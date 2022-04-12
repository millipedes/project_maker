/**
 * @file project_file.c
 * @brief This file contains the functions relating to the user defined file
 * types. For example, a latex file would be an instance of a user defined file.
 * @author Matthew C. Lindeman
 * @date Apr 12 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/project_file.h"

/**
 * This function initializes a user defined file type.
 * @param       ext - the file extension.
 * @param interface - the interface through which the file is used. I.e. the
 * compiler/interpreter etc.
 * @param      name - the name of the file.
 * @param        pd - the parent directory of the file.
 * @return      udf - the new user defined file.
 */
ud_file * init_ud_file(char * ext, char * interface, char * name, char * pd) {
  ud_file * udf = calloc(1, sizeof(struct UD_FILE_T));
  deep_copy_string(udf->ext, ext);
  deep_copy_string(udf->interface, interface);
  deep_copy_string(udf->name, name);
  deep_copy_string(udf->pd, pd);
  return udf;
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
