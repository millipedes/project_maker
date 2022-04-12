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
 * @param   ext - the file extension.
 * @param inter - the interface through which the file is used. I.e. the
 * compiler/interpreter etc.
 * @param   name - the name of the file.
 * @param     pd - the parent directory of the file.
 * @param   file - the structure respresentative of the file
 * @return   udf - the new user defined file.
 */
ud_file * init_ud_file(char * ext, char * inter, char * name, char * pd,
  void (*fun_ptr)(ud_file *)) {
  ud_file * udf = calloc(1, sizeof(struct UD_FILE_T));
  deep_copy_string(udf->ext, ext);
  deep_copy_string(udf->inter, inter);
  deep_copy_string(udf->name, name);
  deep_copy_string(udf->pd, pd);
  /**
   * This allows for genericity, for example if we wanted a file_make, we would
   * pass in the file_make's make_clone to make this ud_file a make_file.
   */
  (*fun_ptr)(udf);
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
  if(udf->inter) {
    free(udf->inter);
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
