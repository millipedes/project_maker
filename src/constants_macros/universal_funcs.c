/**
 * @file universal_funcs.c
 * @brief This file contains those functions whose universal nature makes it
 * necessary for their scope to be global (as if they were in a file with other
 * functionality it can lead to a circular dependency).
 * @author Matthew C. Lindeman
 * @date Apr 12, 2022
 * @bug None known
 * @todo Nothing
 */
#include"include/universal_funcs.h"

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
  dest = calloc(len, sizeof(char));
  for(int i = 0; i < (int)len; i++) {
    *(dest + i) = *(src + i);
  }
}

/**
 * This function appends a string onto another string in a specific way.
 * @param      src - the source string to be appended onto
 * @param addition - the addition to make onto the source
 * @return     N/a
 */
void append_string(char * src, char * addition) {
  if(!src) {
    deep_copy_string(src, addition);
  } else {
    size_t add_len = strnlen(addition, MX_STR);
    size_t ori_len = strnlen(src, MX_STR);
    src = realloc(src, (add_len + ori_len) * sizeof(char));
    for(int i = 0; i < (int)add_len; i++) {
      *(src + i + ori_len + 1) = *(addition + i);
    }
  }
}

/**
 * This function gets a sub string from a source given the bounds: [start,
 * end_po) (i.e. the end value should be 1 greater than the total number of
 * bytes).
 * @param    src - the source string to be sub_stringed
 * @param  start - the starting index
 * @param end_po - the ending index plus one
 * @return
 */
char * get_sub_string(char * src, int start, int end_po) {
  char * ss = calloc(end_po - start + 1, sizeof(char));
  for(int i = start; i < (int)end_po; i++) {
    *(ss + i - start) = *(src + i);
  }
  return ss;
}

/**
 * This funciton takes a file path and returns a double character pointer with
 * two members, the first is the directory to the file and the second is the
 * file name.
 * @param path - the path to the file.
 * @return
 */
char ** path_to_fpd_pair(char * path) {
  size_t len = strnlen(path, MX_STR);
  int index_curr_dir = 0;
  for(int i = 0; i < (int)len; i++) {
    if(*(path + i) == '/') {
      index_curr_dir = i;
    }
  }
  char ** attribs = calloc(2, sizeof(char *));
  int file_name_size = len - index_curr_dir;
  // If just a file, the parent directory is just the EOF character
  if(index_curr_dir == 0) {
    attribs[0] = calloc(1, sizeof(char));
    attribs[0][0] = '\0';
    attribs[1] = get_sub_string(path, 0, file_name_size);
  } else {
    attribs[0] = get_sub_string(path, 0, (len - file_name_size + 1));
    attribs[1] = get_sub_string(path, (len - file_name_size + 1), len);
  }
  return attribs;
}

/**
 * This function frees the file parent directory pair
 * @param fpd_pair - the file parent directory pair
 * @return     N/a
 */
void free_fpd_pair(char ** fpd_pair) {
  if(fpd_pair[0]) {
    free(fpd_pair[0]);
  }
  if(fpd_pair[1]) {
    free(fpd_pair[1]);
  }
  if(fpd_pair) {
    free(fpd_pair);
  }
}
