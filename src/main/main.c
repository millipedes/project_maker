#include"include/main.h"

int main(int argc, char ** argv) {
  /**
   * If argc <  3 => Not enough information provided by the user
   * ^ only true if not the help flag i.e. the and
   * Note print_invalid_flags_help_interface exit with code 1
   */
  if(argc < 3 && (argc != 2 && *(*(argv + 1) + 1) != 'h')) {
    print_invalid_flags_help_interface();
  }
  // write the files from the file_write_interface
  write_files(argc, argv);
  return 0;
}
