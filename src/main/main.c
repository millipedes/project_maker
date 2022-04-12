#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"../file_write_interface/include/file_write_interface.h"
#include"../menu_interface/include/menu_interface.h"

/**
 * access flags:
 *  3) write latex make extensions (remember to make make files data object)
 *  4) write default latex file
 *  5) write plantuml make extensions (remember to make make files data object)
 *  6) write C default file
 *  7) write C make extensions (remember to make make files data object)
 */

void write_flags(FILE * fp);
void print_help_menu(void);

int main(int argc, char ** argv) {
  // If argc <  3 => Not enough information provided by the user
  if(argc < 3 && (argc != 2 && *(*(argv + 1) + 1) != 'h')) {
    print_invalid_flags_help_interface();
  }
  write_files(argc, argv);
  return 0;
}
