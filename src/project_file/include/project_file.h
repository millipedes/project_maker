#ifndef PRO_H
#define PRO_H

#include<stdlib.h>
#include"../../constants_macros/include/constants.h"

typedef struct UD_FILE_T {
  char * ext;       // File Extension
  char * interface; // File Compiler/Interpretor/Valid Interface
  char * name;      // File Name
  char * pd;        // Parent Directory
} ud_file;

ud_file * init_ud_file(char * ext, char * interface, char * name, char * pd);
void deep_copy_string(char * dest, char * src);
void free_ud_files(ud_file udf);

#endif
