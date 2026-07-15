#ifndef STRING_LISTS
#define STRING_LISTS


#include "STRINGS.h"
#include <stdio.h>
#include <stdlib.h>


#define STRLIST_SUCCESS 1
#define STRLIST_FAILURE 0



int STRING_LIST_SETUP(char*** STRING_LIST, const unsigned long LIST_SIZE, const unsigned long STRING_SIZE);


int FREE_STRING_LIST(char*** STRING_LIST);


int STRING_LIST_APPEND(char*** STRING_LIST, const char* APPEND_STRING);


unsigned long STRING_LIST_SIZE(char*** STRING_LIST);





#endif
