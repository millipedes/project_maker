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
  int latex_written = 0;
  /**
   * I don't think this block is deoxygen standard, but it is here to help keep
   * track of the flags.
   *
   * @flag h   - help flag
   */
  for(int i = 1; i < argc; i++) {
    switch(argv[i][0]) {
      case 'h':
        print_invalid_flags_help_interface();
        break;
      case 't':
      case 'l':
        if(latex_written == 0) {
          latex_written = 1;
        }
        break;
      case 'p':
        break;
      case 'C':
        break;
      case 'g':
        break;
      default:
        fprintf(stderr, "Unknown flag `%c`", argv[i][0]);
    }
  }
}
