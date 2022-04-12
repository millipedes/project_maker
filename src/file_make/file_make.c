/**
 * @file file_make.c
 * @brief This function contains the functions that relate to the make file to
 * be written.
 * @author Matthew C. Lindeman
 * @date 
 * @bug None known
 * @todo Nothing
 */
#include"include/file_make.h"

/**
 * This function initializes a Makefile
 * @param file_dest - the destination of the Makefile
 * @return       fm - the Makefile
 */
file_make * init_file_make(char * file_dest) {
  file_make * fm = calloc(1, sizeof(struct FILE_MAKE_T));
  fm->src = NULL;
  fm->fp = fopen(file_dest, "w");
  return fm;
}

/**
 * This function adds addition to the src for the Makefile
 * @param       fm - the Makefile to be added onto
 * @param addition - the addition to be made
 * @return     N/a
 */
void add_to_make_src(file_make * fm, char * addition) {
  append_string(fm->src, addition);
}

/**
 * This functions writes the Makefile. Should be used after src is written
 * @param   fm - the Makefile to be writen
 * @return N/a
 */
void write_file_make(file_make * fm) {
  fprintf(fm->fp, "%s", fm->src);
}

/**
 * This function frees a Makefile
 * @param   fm - the Makefile to be freed
 * @return N/a
 */
void free_file_make(file_make * fm) {
  if(fm->fp) {
    fclose(fm->fp);
  }
  if(fm->src) {
    free(fm->src);
  }
  if(fm) {
    free(fm);
  }
} 
