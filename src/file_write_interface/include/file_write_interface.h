/**
 * @file file_write_interface.h
 * @brief This file has the function definitions for file_write_interface.c
 * @author Matthew C. Lindeman
 * @date Apr 12 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef FINTER_H
#define FINTER_H

#include<stdio.h>
#include<unistd.h>
#include"../../constants_macros/include/constants.h"
#include"../../constants_macros/include/universal_funcs.h"
#include"../../file_make/include/file_make.h"
#include"../../menu_interface/include/menu_interface.h"

void write_files(int argc, char ** argv);
void write_latex_extension(file_make * fm, char ** fpd_pair);
void translate_default_latex_file(char * project_path, char * default_path);

#endif
