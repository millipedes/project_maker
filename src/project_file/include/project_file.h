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
  char * ext;       // File Extension
  char * interface; // File Compiler/Interpretor/Valid Interface
  char * name;      // File Name
  char * pd;        // Parent Directory
} ud_file;

ud_file * init_ud_file(char * ext, char * interface, char * name, char * pd);
void free_ud_files(ud_file udf);

#endif
