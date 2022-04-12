/**
 * @file universal_funcs.c
 * @brief This file function definitions for universal_funcs.c
 * @author Matthew C. Lindeman
 * @date Apr 12, 2022
 * @bug None known
 * @todo Nothing
 */
#ifndef UFUN_H
#define UFUN_H

#include<stdlib.h>
#include<string.h>
#include"constants.h"

void deep_copy_string(char * dest, char * src);
void append_string(char * src, char * addition);
char * get_sub_string(char * src, int start, int end_po);
char ** path_to_fpd_pair(char * path);
void free_fpd_pair(char ** fpd_pair);

#endif
