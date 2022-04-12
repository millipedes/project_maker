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
 * This function takes the command line input and generates a 
 * @param argc - the number of arguments passed to the binary
 * @param argv - the list of arguments
 * @return N/a
 */
void write_files(int argc, char ** argv) {
  char ** fpd_pair = NULL;
  file_make * fm = init_file_make(MAKEFILE_PATH);

  for(int i = 1; i < argc; i += 2) {
    switch(argv[i][0]) {
      case 'h':
        print_help_interface();
        break;
      case 't':
        fpd_pair = path_to_fpd_pair(argv[i + 1]);
        write_latex_extension(fm, fpd_pair);
        translate_default_file(argv[i + 1], LATEX_DEFAULT_FILE);
        free_fpd_pair(fpd_pair);
        break;
      case 'p':
        break;
      case 'C':
        translate_default_file(argv[i + 1], C_DEFAULT_FILE);
        write_C_extension(fm);
        break;
      case 'g':
        break;
      default:
        fprintf(stderr, "Unknown flag `%c`", argv[i][0]);
        print_invalid_flags_help_interface();
    }
  }
  free_file_make(fm);
}

/**
 * This function writes a latex subsection of a makefile
 * @param       fm - the Makefile
 * @param fpd_pair - the file parent directory pair
 * @return     N/a
 */
void write_latex_extension(file_make * fm, char ** fpd_pair) {
  /**
   * Make the latex project
   */
  fprintf(fm->fp, "t-m:\n");
  fprintf(fm->fp, "\tpdf-latex %s%s.tex\n", fpd_pair[0], fpd_pair[1]);
  fprintf(fm->fp, "\trm *.log *.aux\n");
  fprintf(fm->fp, "\tclear\n");
  /**
   * Open the latex project
   */
  fprintf(fm->fp, "t-o:\n");
  fprintf(fm->fp, "\tevince %s%s.pdf\n", fpd_pair[0], fpd_pair[1]);
  /**
   * Edit the tex file
   */
  fprintf(fm->fp, "t-e:\n");
  fprintf(fm->fp, "\tnvim %s%s.tex\n", fpd_pair[0], fpd_pair[1]);
}

/**
 * This function writes a C subsection of a makefile
 * @param       fm - the Makefile
 * @param fpd_pair - the file parent directory pair
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
}

/**
 * This function writes the default file to the file passed to the program by
 * the user
 * @param project_path - the path to the project file (to include the file name)
 * @param default_path - the path the default file (to include file name)
 * @return N/a
 */
void translate_default_file(char * project_path, char * default_path) {
  FILE * default_file = fopen(default_path, "r+");
  FILE * project_file = fopen(project_path, "w");
  char buf[MX_STR];
  while(fgets(buf, MX_STR, default_file)) {
    fprintf(project_file, "%s", buf);
  }
  fclose(default_file);
  fclose(project_file);
}
