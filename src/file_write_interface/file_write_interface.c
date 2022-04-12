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

  for(int i = 1; i < argc; i += 2) {
    switch(argv[i][0]) {
      case 'h':
        print_help_interface();
        break;
      case 't':
      case 'l':
        fpd_pair = path_to_fpd_pair(argv[i + 1]);
        // printf("0) `%s`\n1) `%s`\n", fpd_pair[0], fpd_pair[1]);
        if(fpd_pair[0][0] != '\0') { 

        } else {

        }
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
