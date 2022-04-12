#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

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

int main(void) {
  
  /**
   * @flag h   - help flag
   * @flag c   - classification flag (like your the orgranization)
   * @flag t/l - latex    file type flag, followed by name/path
   * @flag p   - plantuml file type flag, followed by name/path
   * @flag C   - C        file type flag, followed by name/path
   * @flag g   - git project flag
   * @flag e   - editor, defaults to neovim
   */
  while((inta = getopt(argc, argv, "h:"

  return 0;
}
