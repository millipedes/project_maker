#ifndef FIL_H
#define FIL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../constants_macros/include/constants.h"
#include"../../constants_macros/include/universal_funcs.h"

typedef struct FILE_MAKE_T {
  FILE * fp;  // The Makefile itself
  char * src; // The source text of the Makefile
} file_make;

file_make * init_file_make(char * file_dest);
void add_to_make_src(file_make * fm, char * addition);
void write_file_make(file_make * fm);
void free_file_maker(file_make * fm);

#endif
