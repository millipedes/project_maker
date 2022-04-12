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
      " project.\nPlease see the flags below for valid options:\n");
  print_help_interface();
  exit(1);
}

/**
 * This function will print the help interface.
 */
void print_help_interface(void) {
  printf("Usage:\n");
  printf("-h       The Help Flag\n");
}
