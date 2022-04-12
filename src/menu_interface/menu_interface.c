#include"include/menu_interface.h"


void print_invalid_flags_helpe_interface(void) {
  printf("This program requires at least one file type to generate a project.\n"
      "Please see the flags below for valid options:\n");
  print_help_interface();
}


void print_help_interface(void) {
  printf("Usage:\n");
  printf("-h       The Help Flag");
  printf("-c       The Cassification Flag (Organization)");
  printf("-g       The git make Option Flag");
  printf("-e       The Default Editor (Default is Neovim)");
  printf("-t OR -l The Latex    File Type Flag");
  printf("-p       The plantuml File Type Flag");
  printf("-C       The C        File Type Flag");
}
