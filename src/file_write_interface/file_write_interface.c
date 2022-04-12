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
 * @param
 * @return
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
        translate_default_latex_file(argv[i + 1], LATEX_DEFAULT_FILE);
        free_fpd_pair(fpd_pair);
        break;
      case 'p':
        break;
      case 'C':
        break;
      case 'g':
        break;
      default:
        fprintf(stderr, "Unknown flag `%c`", argv[i][0]);
        print_invalid_flags_help_interface();
    }
  }
}

void write_latex_extension(file_make * fm, char ** fpd_pair) {
  fprintf(fm->fp, "t-m:\n");
  fprintf(fm->fp, "\tpdf-latex %s%s\n", fpd_pair[0], fpd_pair[1]);
  fprintf(fm->fp, "\trm *.log *.aux\n");
  fprintf(fm->fp, "\tclear\n");
  fprintf(fm->fp, "t-o:\n");
  fprintf(fm->fp, "\tevince %s%s\n", fpd_pair[0], fpd_pair[1]);
  fprintf(fm->fp, "t-e:\n");
  fprintf(fm->fp, "\tnvim %s%s\n", fpd_pair[0], fpd_pair[1]);
}

void translate_default_latex_file(char * project_path, char * default_path) {
  FILE * default_latex_file = fopen(default_path, "r");
  FILE * project_latex_file = fopen(project_path, "w");
  char buf[MX_STR];
  while(fgets(buf, MX_STR, default_latex_file)) {
    fprintf(project_latex_file, "%s", buf);
  }
}
