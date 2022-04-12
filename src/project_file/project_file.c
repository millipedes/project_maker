/**
 * @file This file contains the functions relating to the
 * @brief 
 * @author Matthew C. Lindeman
 * @date 
 * @bug None known
 * @todo Nothing
 */
#include"include/project_file.h"

ud_file * init_ud_file(char * ext, char * interface, char * name, char * pd) {
  ud_file * udf = calloc(1, sizeof(struct UD_FILE_T));
  deep_copy_string(udf->ext, ext);
  deep_copy_string(udf->interface, interface);
  deep_copy_string(udf->name, name);
  deep_copy_string(udf->pd, pd);
  return udf;
}


/**
 * This function deep copies a string with exact behavior I require for this
 * purpose (there may exist a library function with this exact functionality IDK
 * personaly, but I doubt it).
 * @param  dest - the destination string that is *uninitialized*.
 * @param   src - the source string.
 * @return  N/a
 */
void deep_copy_string(char * dest, char * src) {
  size_t len = strnlen(src, MX_STR);
  dest = calloc(len - 1, sizeof(char));
  for(int i = 0; i < len; i++) {
    *(dest + i) = *(src + i);
  }
}

/**
 * This function frees a user defined type.
 * @param  udf - the user defined file type.
 * @return N/a
 */
void free_ud_files(ud_file * udf) {
  if(udf->ext) {
    free(udf->ext);
  }
  if(udf->interface) {
    free(udf->interface);
  }
  if(udf->name) {
    free(udf->name);
  }
  if(udf->pd) {
    free(udf->pd);
  }
  if(udf) {
    free(udf);
  }
}
