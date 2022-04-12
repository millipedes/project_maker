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
#include"constants.h"

void deep_copy_string(char * dest, char * src);
void append_string(char * src, char * addition);
char * get_sub_string(char * src, int start, int end_po);
char ** path_to_pd_and_fn(char * path);

#endif
