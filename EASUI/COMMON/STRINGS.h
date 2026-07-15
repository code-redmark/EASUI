#ifndef STRINGS
#define STRINGS



#include <stdarg.h>
#include <stdio.h>



#define TRUE 1
#define FALSE 0
#define EMPTY ""
#define STR_FAILURE 0
#define STR_SUCCESS 1
#define STR_WARNING 2




// [CONVERSION]
//


char STRING_TO_CHAR(const char* STRING);


void CHAR_TO_STRING(char* STRING, const char CHAR);


void STRING_TO_WORD_LIST(char*** WORD_LIST, char* STRING);


void WORD_LIST_TO_STRING(char** WORD_LIST, char* STRING);


int STRING_TO_INT(const char* INT_STRING, int* INT);


int STRING_TO_LONG(const char* INT_STRING, long* LONG);


int STRING_TO_UNSIGNED_INT(const char* STRING, unsigned int* UNSIGNED_INT);


int STRING_TO_UNSIGNED_LONG(const char* STRING, unsigned long* UNSIGNED_LONG);


void INT_TO_STRING(char* STRING, long INT);


void UNSIGNED_INT_TO_STRING(char* STRING, unsigned long);


char CHAR_TO_UPPER(char CHAR);


char CHAR_TO_LOWER(char CHAR);


void STRING_TO_UPPER(char* STRING);


void STRING_TO_LOWER(char* STRING);


//
// [/CONVERISON]




// [MODIFICATION]
//


void STRING_APPEND(char* STRING, const char* APPEND);


void STRING_APPEND_CHAR(char* STRING, const char CHAR);


void STRING_PREPEND(char* STRING, const char* PREPEND);


void STRING_PREPEND_CHAR(char* STRING, const char PREPEND);


int STRING_INSERT(char* STRING, const char* INSERT_STRING, const unsigned long INSERT_INDEX);


int STRING_INSERT_CHAR(char* STRING, const char INSERT_CHAR, const unsigned long INSERT_INDEX);


void STRING_FLIP(char* STRING);


int SUB_STRING_SELF(char* STRING, const unsigned long STARTING_INDEX, const unsigned long TO_TAKE);


int SUB_STRING(const char* BASE_STRING, char* SUB_STRING, const unsigned long STARTING_INDEX, const unsigned long TO_TAKE);


void STRING_COPY(char* DESTINATION, const char* STRING);


void STRING_SET(char* STRING, const char* SET);


void STRING_REPLACE_CHAR(char* STRING, const char FIND_CHAR, const char REPLACE_CHAR);


int STRING_REPLACE_SEQUENCE(char* BASE, const char* REPLACE, unsigned long INDEX);


void STRING_REMOVE_FIRST(char* STRING);


void STRING_REMOVE_LAST(char* STRING);


int STRING_REMOVE_INDEX(char* STRING, unsigned long INDEX);


void STRING_REMOVE_CHAR(char* STRING, const char CHAR);


void STRING_TRIM(char* STRING);


void STRING_CLEAR(char* STRING);


int STRING_FORMAT(char* STRING, const char* FORMAT, ...);


//
// [/MODIFICATION]




// [CONDITIONS]
//


int STRING_EQUALS(const char* STRING, const char* COMPARER);


int STRING_IS_EMPTY(const char* STRING);


int STRING_CONTAINS_CHAR(const char* STRING, const char CHAR);


int STRING_STARTS_WITH(const char* STRING, const char* STARTING);


int STRING_ENDS_WITH(const char* STRING, const char* ENDING);


int STRING_IS_INT(const char* STRING);


//
// [/CONDITIONS]




// [PROPERTIES]
//


unsigned long STRING_LENGTH(const char *STRING);


unsigned long STRING_SIZE(const char* STRING);


//
// [/PROPERTIES]




#endif
