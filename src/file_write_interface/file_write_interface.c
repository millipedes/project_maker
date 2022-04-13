/**
 * @file file_write_interface.c
 * @brief This file is responsible for writing all of the files in the project
 * @author Matthew C. Lindeman
 * @date Apr 12 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/file_write_interface.h"

/**
 * This function takes the command line input and generates a project
 * @param argc - the number of arguments passed to the binary
 * @param argv - the list of arguments
 * @return N/a
 */
void write_files(int argc, char ** argv) {
  int t_flag = 0;
  int p_flag = 0;
  int g_flag = 0;
  int C_flag = 0;
  file_make * fm = init_file_make(MAKEFILE_PATH);
  for(int i = 1; i < argc; i += 2) {
    switch(argv[i][0]) {
      case 'h':
        print_help_interface();
        break;
      case 't':
        t_flag = i;
        break;
      case 'p':
        p_flag = i;
        break;
      case 'C':
        C_flag = i;
        break;
      case 'g':
        g_flag = i;
        break;
      default:
        fprintf(stderr, "Unknown flag `%c`", argv[i][0]);
        print_invalid_flags_help_interface();
    }
  }
  if(C_flag != 0) {
    write_C_extension(fm);
    translate_default_file(argv[C_flag + 1], C_DEFAULT_FILE);
  }
  if(t_flag != 0) {
    write_latex_extension(fm, argv[t_flag + 1]);
    translate_default_file(argv[t_flag + 1], LATEX_DEFAULT_FILE);
  }
  if(p_flag != 0) {
    write_plantuml_extension(fm, argv[p_flag + 1]);
  }
  if(g_flag != 0) {
    write_git_extension(fm);
  }
  free_file_make(fm);
}

/**
 * This function writes a latex subsection of a makefile
 * @param        fm - the Makefile
 * @param file_name - the file parent directory pair
 * @return      N/a
 */
void write_latex_extension(file_make * fm, char * file_name) {
  char ** fpd_pair = path_to_fpd_pair(file_name);
  /**
   * Make the latex project
   */
  fprintf(fm->fp, "t-m:\n");
  fprintf(fm->fp, "\tpdf-latex %s\n", file_name);
  fprintf(fm->fp, "\trm *.log *.aux\n");
  fprintf(fm->fp, "\tclear\n");
  /**
   * Open the latex project
   */
  char * tmp = get_sub_string(fpd_pair[1], 0, strnlen(fpd_pair[1], MX_STR) - 4);
  fprintf(fm->fp, "t-o:\n");
  fprintf(fm->fp, "\tevince %s%s.pdf\n", fpd_pair[0], tmp);
  /**
   * Edit the tex file
   */
  fprintf(fm->fp, "t-e:\n");
  fprintf(fm->fp, "\tnvim %s\n", file_name);
  free_fpd_pair(fpd_pair);
  free(tmp);
}

/**
 * This function writes a C subsection of a makefile
 * @param       fm - the Makefile
 * @return     N/a
 */
void write_C_extension(file_make * fm) {
  /**
   * Some variables
   */
  fprintf(fm->fp, "CC=gcc -g -Wall\n");
  fprintf(fm->fp, "CFILES=$(wildcard src/*/*.c)\n");
  fprintf(fm->fp, "HFILES=$(wildcard src/*/include/*.h)\n");
  fprintf(fm->fp, "OBJFILES=$(CFILES:.c=.o)\n");
  fprintf(fm->fp, "OBJPATH=src/objects/\n");
  fprintf(fm->fp, "EXEFILE=bin/main\n");
  /**
   * Make the C project
   */
  fprintf(fm->fp, "c-m: $(OBJFILES)\n");
  fprintf(fm->fp, "\t$(CC) $(OBJFILES) -o $(EXEFILE) -lm\n");
  fprintf(fm->fp, "%%.o: %%.c $(HFILES)%%.h");
  fprintf(fm->fp, "\t$(CC) -c $(CFILES) $< -o $@ -lm\n");
  /**
   * Edit the C project
   */
  fprintf(fm->fp, "c-e:\n");
  fprintf(fm->fp, "\tnvim $(CFILES)\n");
  /**
   * Memory Check C Program
   */
  fprintf(fm->fp, "c-check-mem:\n");
  fprintf(fm->fp, "\tvalgrind --leak-check=full --read-var-info $(EXEFILE)");
  /**
   * Debug C Program
   */
  fprintf(fm->fp, "c-d:\n");
  fprintf(fm->fp, "\tgdb -q $(EXEFILE)\n");
  /**
   * Run C Program
   */
  fprintf(fm->fp, "c-r:\n");
  fprintf(fm->fp, "\t$(EXEFILE)\n");

  /**
   * Clean C Project
   */
  fprintf(fm->fp, "c-clean:\n");
  fprintf(fm->fp, "\trm $(OBJFILES)\n");
}

/**
 * This function writes a git subsection of a Makefile
 * @param       fm - the Makefile
 * @return     N/a
 */
void write_git_extension(file_make * fm) {
  fprintf(fm->fp, "git-update:\n");
  fprintf(fm->fp, "\tgit add Makefile README.md src/\n");
  fprintf(fm->fp, "\tgit commit -m \"update commit\"\n");
  fprintf(fm->fp, "\tgit push origin main\n");
}

/**
 * This function writes a git subsection of a Makefile
 * @param        fm - the Makefile
 * @param file_name - the name of the file
 * @return      N/a
 */
void write_plantuml_extension(file_make * fm, char * file_name) {
  char ** fpd_pair = path_to_fpd_pair(file_name);
  char * tmp = get_sub_string(fpd_pair[1], 0, strnlen(fpd_pair[1], MX_STR) - 4);
  fprintf(fm->fp, "p-e:\n");
  fprintf(fm->fp, "\tnvim %s\n", file_name);
  fprintf(fm->fp, "p-o:\n");
  fprintf(fm->fp, "\tfeh %s%s.png\n", fpd_pair[0], tmp);
  free_fpd_pair(fpd_pair);
  free(tmp);
}

/**
 * This function writes the default file to the file passed to the program by
 * the user
 * @param project_path - the path to the project file (to include the file name)
 * @param default_path - the path the default file (to include file name)
 * @return         N/a
 */
void translate_default_file(char * project_path, char * default_path) {
  char ** fpd_pair = path_to_fpd_pair(project_path);
  struct stat st = {0};
  if(fpd_pair[0][0] != '\0') {
    if(stat(fpd_pair[0], &st) == -1) {
      mkdir(fpd_pair[0], 0755);
    }
  }
  FILE * default_file = fopen(default_path, "r+");
  FILE * project_file = fopen(project_path, "w");
  char buf[MX_STR];
  while(fgets(buf, MX_STR, default_file)) {
    fprintf(project_file, "%s", buf);
  }
  fclose(default_file);
  fclose(project_file);
  free_fpd_pair(fpd_pair);
}
