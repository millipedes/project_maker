#include"include/file_write_interface.h"

void write_flags(int argc, char ** argv) {
  int flag = 0;
  int latex_written = 0;
  /**
   * @flag h   - help flag
   * @flag c   - classification flag (like your the orgranization)
   * @flag t/l - latex    file type flag, followed by name/path
   * @flag p   - plantuml file type flag, followed by name/path
   * @flag C   - C        file type flag, followed by name/path
   * @flag g   - git project flag
   * @flag e   - editor, defaults to neovim
   */
  while((flag = getopt(argc, argv, "h:c:t:l:p:C:g:e:")) != -1) {
    switch(flag) {
      case 'h':

        break;
      case 'c':
        break;
      case 't':
        break;
      case 'l':
        break;
      case 'p':
        break;
      case 'C':
        break;
      case 'g':
        break;
      case 'e':
        break;
    }
  }
}
