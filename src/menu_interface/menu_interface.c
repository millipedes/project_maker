/**
 * @file menu_interface.c
 * @brief This file contains menus
 * @author Matthew C. Lindeman
 * @date Arp 12, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/menu_interface.h"

/**
 * This function will print a message letting the used know that flags are
 * required to run the program then it will print the help screen then exits.
 */
void print_invalid_flags_help_interface(void) {
  fprintf(stderr, "This program requires at least one file type to generate a"
      "project.\nPlease see the flags below for valid options:\n");
  print_help_interface();
  exit(1);
}

/**
 * This function will print the help interface.
 */
void print_help_interface(void) {
  printf("Usage:\n");
  printf("-h       The Help Flag\n");
  printf("-c       The Cassification Flag (Organization)\n");
  printf("-g       The git make Option Flag\n");
  printf("-e       The Default Editor (Default is Neovim)\n");
  printf("-t OR -l The Latex    File Type Flag\n");
  printf("-p       The plantuml File Type Flag\n");
  printf("-C       The C        File Type Flag\n");
  printf("=================================================================\n");
  printf("A note on File Type flags. They can be used in the following");
  printf("manner:\nproject_maker -x ./directory/to/file/file_name\nNote no");
  printf("file type extension\nIf no directory is specified the file will be");
  printf("placed in fileExt_src/file_name");
  printf("=================================================================\n");
}
