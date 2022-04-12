/**
 * @file project_file.h
 * @brief This file contains the function definitions for the user defined file
 * type related functions.
 * @author Matthew C. Lindeman
 * @date Apr 12 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef PRO_H
#define PRO_H

#include<stdlib.h>
#include"../../constants_macros/include/constants.h"
#include"../../constants_macros/include/universal_funcs.h"

typedef struct UD_FILE_T {
  char * ext;        // File Extension
  char * inter;      // File Compiler/Interpretor/Valid Interface
  char * name;       // File Name
  char * pd;         // Parent Directory
  void * file;       // The file
} ud_file;

ud_file * init_ud_file(char * ext, char * inter, char * name, char * pd,
  void (*fun_ptr)(ud_file *));
void free_ud_files(ud_file * udf);

#endif
