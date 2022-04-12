/**
 * @file file_write_interface.h
 * @brief This file has the function definitions for file_write_interface.c
 * @author Matthew C. Lindeman
 * @date Apr 12 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef FIL_H
#define FIL_H

#include<unistd.h>
#include"../../menu_interface/include/menu_interface.h"

void write_files(int argc, char ** argv);

#endif
