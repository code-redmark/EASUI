#include "STRINGS.h"



/**
 * - BRIEF  : TURNS A SINGLE LETTERED STRING INTO A CHAR
 *
 * - NOTE   : IT WORKS BUT ONLY TAKING THE FIRST LETTER OF THE STRING, SO HAVING MULTIPLE CHAR STRINGS IS STILL ACCEPTED
 *
 * - USAGE  : printf("%c", STRING_TO_CHAR('A'));
*/
char STRING_TO_CHAR(const char* STRING)
{

        return STRING[0];

}


/**
 * - BRIEF  : TURNS A STRING INTO A CHAR
 *
 * - USAGE  : STRING_TO_CHAR(STRING, 'A');
*/
void CHAR_TO_STRING(char* STRING, const char CHAR)
{

        STRING[0] = CHAR;
        STRING[1] = '\0';

}


/**
 * - BRIEF   : TURNS A STRING INTO A LIST, DIVDED BY SPACES
 *
 * - NOTE 1  : RECOMMEND USING STRING_LIST_SETUP()
 *
 * - NOTE 2  : BEFORE USING, THE char** STRING LIST SHOULD BE ALREADY ALLOCATED
 *
 * - NOTE 2  : THE STRING IS AUTOMATICALLY TRIMMED
 *
 * - USAGE   : STRING_TO_WORD_LIST(&STRING_LIST, "I LOVE C");
*/
void STRING_TO_WORD_LIST(char*** WORD_LIST, char* STRING)
{

        unsigned long WORD_LIST_INDEX = 0;


        STRING_TRIM(STRING);


        STRING_CLEAR((*WORD_LIST)[WORD_LIST_INDEX]);


        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                char CHAR = STRING[INDEX];


                if (CHAR != ' ')
                {

                        STRING_APPEND_CHAR((*WORD_LIST)[WORD_LIST_INDEX], CHAR);

                }

                else
                {

                        WORD_LIST_INDEX ++;


                        STRING_CLEAR((*WORD_LIST)[WORD_LIST_INDEX]);

                }

        }

}


/**
 * - BRIEF  : TURNS A STRING LIST INTO A STRING
 *
 * - RESULT : EACH ITEM OF THE STRING LIST WOULD BE PIECED TOGETHER, WITH A SPACED GAP
 *
 * - NOTE   : REQUIRES USING STRING_LIST_SETUP(), AS THE LIST IS NULL TERMINATED
 *
 * - USAGE  : WORD_LIST_TO_STRING(STRING_LIST, STRING);
*/
void WORD_LIST_TO_STRING(char** WORD_LIST, char* STRING)
{

        STRING_CLEAR(STRING);


        for (unsigned long INDEX = 0; WORD_LIST[INDEX] != NULL; INDEX ++)
        {

                STRING_APPEND(STRING, WORD_LIST[INDEX]);
                STRING_APPEND_CHAR(STRING, ' ');

        }


        STRING_TRIM(STRING);
}


/**
 * - BRIEF  : TAKES A STRING THATS EXACTLY AN int FORMAT, AND EDITS INT TO IT
 *
 * - NOTE 1 : IF THE STRING IS AN INVALID int FORMAT, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - NOTE 2 : ANY int OVERFLOW WILL NOT BE HANDLED
 *
 * - USAGE  : STRING_TO_INT("-12345", &INT);
*/
int STRING_TO_INT(const char* INT_STRING, int* INT)
{

        short SIGN = 1;
        long INDEX = 1;



        *INT = 0;



        if (!STRING_IS_INT(INT_STRING))
        {

                return STR_FAILURE;

        }


        if (INT_STRING[0] == '-')
        {

                INDEX = 1;

                SIGN = -1;

        }


        for (INDEX = INDEX; INT_STRING[INDEX] != '\0'; INDEX ++)
        {

                *INT = (*INT) * 10 + INT_STRING[INDEX] - '0';

        }



        *INT *= SIGN;



        return STR_SUCCESS;

}


/**
 * - BRIEF  : TAKES A STRING THATS EXACTLY A long FORMAT, AND EDITS LONG TO IT
 *
 * - NOTE 1 : IF THE STRING IS AN INVALID long FORMAT, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - NOTE 2 : ANY long OVERFLOW WILL NOT BE HANDLED
 *
 * - USAGE  : STRING_TO_LONG("-12345", &LONG);
*/
int STRING_TO_LONG(const char* INT_STRING, long* LONG)
{

        short SIGN = 0;
        long INDEX = 1;



        *LONG = 0;



        if (!STRING_IS_INT(INT_STRING))
        {

                return STR_FAILURE;

        }


        if (INT_STRING[0] == '-')
        {

                INDEX = 1;

                SIGN = -1;

        }


        for (INDEX = INDEX; INT_STRING[INDEX] != '\0'; INDEX++)
        {

                *LONG = (*LONG) * 10 + INT_STRING[INDEX] - '0';

        }



        *LONG *= SIGN;



        return STR_SUCCESS;

}


/**
 * - BRIEF  : TAKES A STRING THATS EXACTLY AN unsigned int FORMAT, AND EDITS INT TO IT
 *
 * - NOTE 1 : IF THE STRING IS AN INVALID unsigned int FORMAT, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - NOTE 2 : ANY unsigned int OVERFLOW WILL NOT BE HANDLED
 *
 * - USAGE  : STRING_TO_UNSIGNED_INT("12345", &UNSIGNED_INT);
*/
int STRING_TO_UNSIGNED_INT(const char* STRING, unsigned int* UNSIGNED_INT)
{

        *UNSIGNED_INT = 0;



        if (!STRING_IS_INT(STRING))
        {

                return STR_FAILURE;

        }


        if (STRING[0] == '-')
        {

                return STR_FAILURE;

        }


        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

               *UNSIGNED_INT = ((*UNSIGNED_INT) * 10) + (STRING[INDEX] - '0');

        }


        return STR_SUCCESS;

}


/**
 * - BRIEF  : TAKES A STRING THATS EXACTLY AN unsigned long FORMAT, AND EDITS UNSIGNED_LONG TO IT
 *
 * - NOTE 1 : IF THE STRING IS AN INVALID unsigned long FORMAT, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - NOTE 2 : ANY unsigned long OVERFLOW WILL NOT BE HANDLED
 *
 * - USAGE  : STRING_TO_UNSIGNED_LONG("12345", &UNSIGNED_LONG);
*/
int STRING_TO_UNSIGNED_LONG(const char* STRING, unsigned long* UNSIGNED_LONG)
{

        *UNSIGNED_LONG = 0;



        if (!STRING_IS_INT(STRING))
        {

                return STR_FAILURE;

        }


        if (STRING[0] == '-')
        {

                return STR_FAILURE;

        }


        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

               *UNSIGNED_LONG = ((*UNSIGNED_LONG) * 10) + (STRING[INDEX] - '0');

        }


        return STR_SUCCESS;

}


/**
 * - BRIEF  : TAKES AN ANY INT TYPE FORMAT, AND EDITS STRING TO IT
 *
 * - NOTE   : ANY INT OVERFLOW WILL NOT BE HANDLED
 *
 * - USAGE  : INT_TO_STRING(INT_STRING, -12345);
*/
void INT_TO_STRING(char* STRING, long INT)
{

        STRING_CLEAR(STRING);



        if (INT == 0)
        {

                STRING_APPEND_CHAR(STRING, '0');

                return;

        }


        while (INT > 0)
        {

                const short NUMBER = INT % 10;

                INT = (INT - NUMBER) / 10;


                STRING_APPEND_CHAR(STRING, NUMBER + '0');

        }


        if (INT < 0)
        {

                INT = -INT;


                STRING_APPEND_CHAR(STRING, '-');

        }


        STRING_FLIP(STRING);

}


/**
 * - BRIEF  : TAKES AN ANY UNSIGNED INT TYPE FORMAT, AND EDITS STRING TO IT
 *
 * - NOTE   : ANY UNSIGNED INT OVERFLOW WILL NOT BE HANDLED
 *
 * - USAGE  : INT_TO_STRING(UNSIGNED_INT_STRING, 12345);
*/
void UNSIGNED_INT_TO_STRING(char* STRING, unsigned long INT)
{

        STRING_CLEAR(STRING);



        if (INT == 0)
        {

                STRING_APPEND_CHAR(STRING, '0');

                return;

        }


        while (INT > 0)
        {

                const short NUMBER = INT % 10;

                INT = (INT - NUMBER) / 10;


                STRING_APPEND_CHAR(STRING, NUMBER + '0');

        }


        if (INT < 0)
        {

                INT = -INT;


                STRING_APPEND_CHAR(STRING, '-');

        }


        STRING_FLIP(STRING);

}


/**
 * - BRIEF  : RETURNS THE UPPERCASE OF THE GIVEN LETTER
 *
 * - RETURN : IF THE GIVEN CHAR IS IN LOWERCASE, RETURN THE UPPERCASE OF IT, OTHERWISE, RETURN THE ORIGINAL GIVEN CHAR
 *
 * - NOTE   : ONLY WORKS FOR THE 26 LETTERS OF THE ENGLISH ALPHABET AND ASCII FORMAT
 *
 * - USAGE  : char UPPERCASE_CHAR = CHAR_TO_UPPER('a');
*/
char CHAR_TO_UPPER(char CHAR)
{

		#define IS_UPPER (CHAR >= 97 && CHAR <= 122)


        if (IS_UPPER)
        {

                CHAR -= 32;

        }


        return CHAR;

}


/**
 * - BRIEF  : RETURNS THE LOWERCASE OF THE GIVEN LETTER
 *
 * - RETURN : IF THE GIVEN CHAR IS IN UPPERCASE, RETURN THE LOWERCASE OF IT, OTHERWISE, RETURN THE ORIGINAL GIVEN CHAR
 *
 * - NOTE   : ONLY WORKS FOR THE 26 LETTERS OF THE ENGLISH ALPHABET AND ASCII FORMAT
 *
 * - USAGE  : char LOWERCASE_CHAR = CHAR_TO_LOWER('A');
*/
char CHAR_TO_LOWER(char CHAR)
{

		#define IS_LOWER (CHAR >= 65 && CHAR <= 90)


        if (IS_LOWER)
        {

                CHAR += 32;

        }


        return CHAR;

}


/**
 * - BRIEF  : TAKES A STRING, EDITS ALL LOWERCASE LETTERS TO UPPERCASE
 *
 * - NOTE 1 : THROUGH EACH CHAR IN THE STRING, IF THE CHAR IS IN LOWERCASE, EDIT IT TO UPPERCASE
 *
 * - NOTE 2 : ONLY WORKS FOR THE 26 LETTERS OF THE ENGLISH ALPHABET AND ASCII FORMAT
 *
 * - USAGE  : STRING_TO_UPPER(UPPERCASE_STRING);
*/
void STRING_TO_UPPER(char* STRING)
{

        const char* LOWER = "abcdefghijklmnopqrstuvwxyz";


        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING_CONTAINS_CHAR(LOWER, STRING[INDEX]))
                {

                        STRING[INDEX] -= 32;

                }

        }

}


/**
 * - BRIEF  : TAKES A STRING, EDITS ALL UPPERCASE LETTERS TO LOWERCASE
 *
 * - NOTE 1 : THROUGH EACH CHAR IN THE STRING, IF THE CHAR IS IN LOWERCASE, EDIT IT TO UPPERCASE
 *
 * - NOTE 2 : ONLY WORKS FOR THE 26 LETTERS OF THE ENGLISH ALPHABET AND ASCII FORMAT
 *
 * - USAGE  : STRING_TO_LOWER(LOWERCASE_STRING);
*/
void STRING_TO_LOWER(char* STRING)
{

        const char* UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING_CONTAINS_CHAR(UPPER, STRING[INDEX]))
                {

                        STRING[INDEX] += 32;

                }

        }

}


/**
 * - BRIEF  : ADDS A STRING TO THE END OF A STRING
 *
 * - USAGE  : STRING_APPEND(STRING, "I APPENDED THIS");
*/
void STRING_APPEND(char* STRING, const char* APPEND)
{

        unsigned long STRING_INDEX;
	unsigned long APPEND_INDEX;



	for (STRING_INDEX = STRING_LENGTH(STRING), APPEND_INDEX = 0; APPEND[APPEND_INDEX] != '\0'; STRING_INDEX ++, APPEND_INDEX ++)
	{

                STRING[STRING_INDEX] = APPEND[APPEND_INDEX];

	}


	STRING[STRING_INDEX] = '\0';

}


/**
 * - BRIEF  : ADDS A CHAR TO THE END OF A STRING
 *
 * - USAGE  : STRING_APPEND_CHAR(STRING, 'A');
*/
void STRING_APPEND_CHAR(char* STRING, const char CHAR)
{

        unsigned long LENGTH = STRING_LENGTH(STRING);


        STRING[LENGTH] = CHAR;
        STRING[LENGTH + 1] = '\0';

}


/**
 * - BRIEF  : INSERTS A STRING TO THE START OF A STRING
 *
 * - USAGE  : STRING_PREPEND(STRING, "I PREPENDED THIS");
*/
void STRING_PREPEND(char* STRING, const char* PREPEND)
{

        unsigned long BASE_LENGTH = STRING_LENGTH(STRING);
        unsigned long PREPEND_LENGTH = STRING_LENGTH(PREPEND);



        for (unsigned long INDEX = BASE_LENGTH + PREPEND_LENGTH; INDEX >= PREPEND_LENGTH; INDEX --)
        {

                STRING[INDEX] = STRING[INDEX - PREPEND_LENGTH];

        }


        for (unsigned long INDEX = 0; PREPEND[INDEX] != '\0'; INDEX ++)
        {

                STRING[INDEX] = PREPEND[INDEX];

        }

}


/**
 * - BRIEF  : INSERTS A CHAR TO THE START OF A STRING
 *
 * - USAGE  : STRING_PREPEND_CHAR(STRING, 'A');
*/
void STRING_PREPEND_CHAR(char* STRING, const char PREPEND)
{

        const unsigned long LENGTH = STRING_LENGTH(STRING);



        for (unsigned long INDEX = LENGTH; INDEX > 0; INDEX --)
        {

                STRING[INDEX] = STRING[INDEX - 1];

        }



        STRING[LENGTH + 1] = '\0';



        STRING[0] = PREPEND;

}


/**
 * - BRIEF  : INSERTS A STRING AT THE GIVEN INDEX INTO A STRING
 *
 * - NOTE   : IF THE GIVEN INDEX IS > TO THE LENGTH OF THE STRING, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : STRING_INSERT(STRING, "I INSERTED THIS", 5);
*/
int STRING_INSERT(char* STRING, const char* INSERT_STRING, const unsigned long INSERT_INDEX)
{

        const unsigned long BASE_LENGTH = STRING_LENGTH(STRING);
        const unsigned long INSERT_LENGTH = STRING_LENGTH(INSERT_STRING);



        if (INSERT_INDEX >= BASE_LENGTH)
        {

                return STR_FAILURE;

        }



        for (unsigned long INDEX = BASE_LENGTH + INSERT_LENGTH; INDEX > INSERT_INDEX; INDEX --)
        {

                STRING[INDEX] = STRING[INDEX - INSERT_LENGTH];

        }


        for (unsigned long INDEX = 0; INSERT_STRING[INDEX] != '\0'; INDEX ++)
        {

                STRING[INDEX + INSERT_INDEX] = INSERT_STRING[INDEX];

        }



        return STR_SUCCESS;

}


/**
 * - BRIEF  : INSERTS A CHAR AT THE GIVEN INDEX INTO A STRING
 *
 * - NOTE   : IF THE GIVEN INDEX IS > TO THE LENGTH OF THE STRING, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : STRING_INSERT_CHAR(STRING, 'A', 5);
*/
int STRING_INSERT_CHAR(char* STRING, const char INSERT_CHAR, const unsigned long INSERT_INDEX)
{

        const unsigned long BASE_LENGTH = STRING_LENGTH(STRING);



        if (INSERT_INDEX >= BASE_LENGTH)
        {

                return STR_FAILURE;

        }


        for (unsigned long INDEX = BASE_LENGTH; INDEX > INSERT_INDEX; INDEX --)
        {

                STRING[INDEX] = STRING[INDEX - 1];

        }



        STRING[INSERT_INDEX] = INSERT_CHAR;


        STRING[BASE_LENGTH + 1] = '\0';



        return STR_SUCCESS;

}


/**
 * - BRIEF  : FLIPS A STRING INTO REVERSE ORDER
 *
 * - USAGE  : STRING_FLIP(STRING);
*/
void STRING_FLIP(char* STRING)
{

        const unsigned long LENGTH = STRING_LENGTH(STRING);


        for (unsigned long INDEX = 0; INDEX < LENGTH / 2; INDEX++)
        {

                unsigned long FLIP_INDEX = LENGTH - 1 - INDEX;
                char TEMP = STRING[INDEX];


                STRING[INDEX] = STRING[FLIP_INDEX];
                STRING[FLIP_INDEX] = TEMP;

        }

}


/**
 * - BRIEF  : DIRECTLY SUB-STRINGS THE GIVEN STRING
 *
 * - NOTE   : IF STARTING_INDEX + TO_TAKE > THE STRING LENGTH, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : SUB_STRING_SELF(STRING, 6, 5);
*/
int SUB_STRING_SELF(char* STRING, const unsigned long STARTING_INDEX, const unsigned long TO_TAKE)
{

        const unsigned long FULL_LENGTH = STRING_LENGTH(STRING);
        unsigned long SUB_INDEX;
        unsigned long STRING_INDEX;



        if (STARTING_INDEX + TO_TAKE > FULL_LENGTH)
        {

                return STR_FAILURE;

        }


        for (SUB_INDEX = STARTING_INDEX, STRING_INDEX = 0; STRING_INDEX < TO_TAKE; SUB_INDEX ++, STRING_INDEX ++)
        {

                STRING[STRING_INDEX] = STRING[SUB_INDEX];

        }



        STRING[STRING_INDEX] = '\0';



        return STR_SUCCESS;

}


/**
 * - BRIEF  : SUB-STRINGS THE BASE_STRING INTO SUB_STRING
 *
 * - NOTE   : IF STARTING_INDEX + TO_TAKE > THE STRING LENGTH, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : SUB_STRING("HELLO WORLD", SUB_STRING, 6, 5);
*/
int SUB_STRING(const char* BASE_STRING, char* SUB_STRING, const unsigned long STARTING_INDEX, const unsigned long TO_TAKE)
{

        const unsigned long FULL_LENGTH = STRING_LENGTH(BASE_STRING);
        unsigned long STRING_INDEX;



        if (STARTING_INDEX + TO_TAKE > FULL_LENGTH)
        {

                return STR_FAILURE;

        }


        for (STRING_INDEX = 0; STRING_INDEX < TO_TAKE; STRING_INDEX ++)
        {

                SUB_STRING[STRING_INDEX] = BASE_STRING[STARTING_INDEX + STRING_INDEX];

        }



        SUB_STRING[STRING_INDEX] = '\0';



        return STR_SUCCESS;

}


/**
 * - BRIEF  : COPIES THE GIVEN STRING TO THE DESTINATION STRING
 *
 * - USAGE  : STRING_COPY(STRING, "HELLO WORLD");
*/
void STRING_COPY(char* DESTINATION, const char* STRING)
{

        unsigned long INDEX;



        for (INDEX = 0; STRING[INDEX] != '\0'; INDEX++)
        {

                DESTINATION[INDEX] = STRING[INDEX];

        }


        DESTINATION[INDEX] = '\0';

}


/**
 * - BRIEF  : SETS A STRING TO THE GIVEN STRING SET
 *
 * - NOTE   : THIS IS IDENTICAL TO STRING_COPY, THIS IS ONLY FOR CLEARER STATMENT MEANING IN SOME CASES
 *
 * - USAGE  : STRING_SET(STRING, "HELLO WORLD");
*/
void STRING_SET(char* STRING, const char* SET)
{

        unsigned long INDEX;



        for (INDEX = 0; STRING[INDEX] != '\0'; INDEX++)
        {

                STRING[INDEX] = SET[INDEX];

        }


        STRING[INDEX] = '\0';

}


/**
 * - BRIEF  : FINDS AND REPLACES THE GIVEN FIND_CHAR TO REPLACE_CHAR
 *
 * - USAGE  : STRING_REPLACE_CHAR(STRING, A, B);
*/
void STRING_REPLACE_CHAR(char* STRING, const char FIND_CHAR, const char REPLACE_CHAR)
{

        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX++)
        {

                if (STRING[INDEX] == FIND_CHAR)
                {

                        STRING[INDEX] = REPLACE_CHAR;

                }

        }

}


/**
 * - BRIEF  : REPLACE A STRING SEQUENCE IN THE BASE STRING, STARTING FROM THE GIVEN INDEX
 *
 * - NOTE   : IF INDEX + REPLACE LENGTH > BASE_LENGTH, FUNCTION RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : STRING_REPLACE_AT_INDEX(STRING, "WORLD", 7);
*/
int STRING_REPLACE_SEQUENCE(char* BASE, const char* REPLACE, unsigned long INDEX)
{

        unsigned long BASE_LENGTH = STRING_LENGTH(BASE);
        unsigned long REPLACE_LENGTH = STRING_LENGTH(REPLACE);
        unsigned long BASE_INDEX;
        unsigned long REPLACE_INDEX;



        if (INDEX + REPLACE_LENGTH > BASE_LENGTH)
        {

                return STR_FAILURE;

        }



        for (BASE_INDEX = INDEX, REPLACE_INDEX = 0; BASE[BASE_INDEX] != '\0'; BASE_INDEX ++, REPLACE_INDEX ++)
        {

                BASE[BASE_INDEX] = REPLACE[REPLACE_INDEX];

        }



        return STR_SUCCESS;

}


/**
 * - BRIEF  : REMOVES THE FIRST CHAR IN A STRING, AND SHIFTS BACK BY 1
 *
 * - USAGE  : STRING_REMOVE_FIRST(STRING);
*/
void STRING_REMOVE_FIRST(char* STRING)
{

        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                STRING[INDEX] = STRING[INDEX + 1];

        }

}


/**
 * - BRIEF  : REMOVES THE LAST CHAR IN A STRING
 *
 * - USAGE  : STRING_REMOVE_LAST(STRING);
*/
void STRING_REMOVE_LAST(char* STRING)
{

        const unsigned long LENGTH = STRING_LENGTH(STRING);


        if (LENGTH == 0)
        {

                return;

        }


        STRING[LENGTH - 1] = '\0';

}


/**
 * - BRIEF  : REMOVES THE GIVEN INDEX OF A STRING
 *
 * _ NOTE   : IF INDEX > LENGTH, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : STRING_REMOVE_INDEX(STRING, 5);
*/
int STRING_REMOVE_INDEX(char* STRING, unsigned long INDEX)
{

        if (INDEX >= STRING_LENGTH(STRING))
        {

                return STR_FAILURE;

        }


        for (INDEX = INDEX; STRING[INDEX] != '\0'; INDEX ++)
        {

                STRING[INDEX] = STRING[INDEX + 1];

        }


        return STR_SUCCESS;

}


/**
 * - BRIEF  : REMOVES ALL OCCURENCES OF THE GIVEN CHAR IN A STRING
 *
 * - USAGE  : STRING_REMOVE_CHAR(STRING, 'A');
*/
void STRING_REMOVE_CHAR(char* STRING, const char CHAR)
{

        for (unsigned long INDEX = 0; STRING[INDEX] != '\0';)
        {

                if (STRING[INDEX] == CHAR)
                {

                        STRING_REMOVE_INDEX(STRING, INDEX);

                }

                else
                {

                        INDEX ++;

                }

        }

}


/**
 * - BRIEF  : TRIMS THE GIVEN STRING
 *
 * - NOTE 1 : IT WILL TRIM ALL SPACES AND NEWLINES AT THE START AND END OF A STRING
 *
 * _ NOTE 2 : IT WILL TRIM THE SPACES IN THE INNER PART OF THE STRING AND LEAVE 1 SPACE OR NEWLINE ONLY
 *
 * - USAGE  : STRING_TRIM(STRING);
*/
void STRING_TRIM(char* STRING)
{

        if (STRING_IS_EMPTY(STRING))
        {

                return;

        }


        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING[INDEX] == ' ' || STRING[INDEX] == '\n')
                {

                        while (STRING[INDEX + 1] == ' ' || STRING[INDEX + 1] == '\n')
                        {

                                STRING_REMOVE_INDEX(STRING, INDEX + 1);

                        }


                        if (INDEX == 0 || STRING[INDEX + 1] == '\0')
                        {

                                STRING_REMOVE_INDEX(STRING, INDEX);

                        }

                }

        }

}


/**
 * - BRIEF  : CLEARS THE GIVEN STRING
 *
 * - NOTE   : IT SET INDEX 0 OF THE STRING TO '\0'
 *
 * - USAGE  : STRING_CLEAR(STRING);
*/
void STRING_CLEAR(char* STRING)
{

        STRING[0] = '\0';

}


/**
 * - BRIEF  : FORMATS A STRING BY PIECING THE GIVEN STRINGS WITH THE FORMAT, FORMATTED INTO STRING
 *
 * - NOTE 1 : USE %V TO SET MARKERS IN THE FORMAT, IT INDICATES WHERE THE GIVEN STRING VARIABLES WOULD BE
 *
 * - NOTE 2 : USE CAREFULLY, va_args IS A PRIMITIVE LIBRARY, MAKE SURE TO GIVE THE CORRECT NUMBER OF MARKERS AND STRING VARIABLES
 *
 * - NOTE 3 : IF THE GIVEN STRING VARIABLES ARE NULL OR HAS TYPE MISMATCH, IT RETURNS STR_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : STRING_FORMAT(STRING, "%V, %V", "HELLO", "WORLD");
*/
int STRING_FORMAT(char* STRING, const char* FORMAT, ...)
{

        va_list VARIABLES;



        va_start(VARIABLES, FORMAT);



        STRING_CLEAR(STRING);



        for (unsigned long INDEX = 0; FORMAT[INDEX] != '\0'; INDEX ++)
        {

                if (FORMAT[INDEX] == '%' && FORMAT[INDEX + 1] == 'V')
                {

                        char* VARIABLE = va_arg(VARIABLES, char*);



                        if (VARIABLE == NULL)
                        {

                                va_end(VARIABLES);


                                return STR_FAILURE;

                        }



                        STRING_APPEND(STRING, VARIABLE);



                        INDEX ++;

                }
                else
                {

                        STRING_APPEND_CHAR(STRING, FORMAT[INDEX]);

                }

        }



        va_end(VARIABLES);



        return STR_SUCCESS;

}


/**
 * - BRIEF  : COMPARES IF THE GIVEN TWO STRINGS ARE EQUAL/IDENTICAL
 *
 * - USAGE  : int EQUALS = STRING_EQUALS("HELLO", "HELLO");
*/
int STRING_EQUALS(const char* STRING, const char* COMPARER)
{

        unsigned long INDEX = 0;



        while (STRING[INDEX] != '\0' && STRING[INDEX] == COMPARER[INDEX])
        {

                INDEX ++;

        }


        return STRING[INDEX] == COMPARER[INDEX];

}


/**
 * - BRIEF  : CHECKS IF A STRING IS EMPTY
 *
 * _ NOTE   : ONLY CHECKS IF STRING[0] IS '\0' (TRULY EMPTY)
 *
 * - USAGE  : int IS_EMPTY = STRING_IS_EMPTY("");
*/
int STRING_IS_EMPTY(const char* STRING)
{

        return (STRING[0] == '\0');

}


/**
 * - BRIEF  : CHECKS IF A STRING CONTAINS A CHAR
 *
 * - USAGE  : int CONTAINS = STRING_CONTAINS("HELLO", 'H');
*/
int STRING_STARTS_WITH(const char* STRING, const char* STARTING)
{

        if (STRING_LENGTH(STRING) < STRING_LENGTH(STARTING))
        {

                return FALSE;

        }


        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING[INDEX] != STARTING[INDEX])
                {

                        return FALSE;

                }

        }


        return TRUE;

}


/**
 * - BRIEF  : CHECKS IF A STRING STARTS WITH A STRING
 *
 * - USAGE  : int STARTS_WITH = STRING_STARTS_WITH("HELLO", "HE");
*/
int STRING_ENDS_WITH(const char* STRING, const char* ENDING)
{

        const unsigned long BASE_LENGTH = STRING_LENGTH(STRING);
        const unsigned long ENDING_LENGTH = STRING_LENGTH(ENDING);
        const unsigned long DISTANCE = BASE_LENGTH - ENDING_LENGTH;



        if (BASE_LENGTH < ENDING_LENGTH)
        {

                return FALSE;

        }


        for (unsigned long INDEX = 0; ENDING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING[INDEX + DISTANCE] != ENDING[INDEX])
                {

                        return FALSE;

                }

        }


        return TRUE;

}


/**
 * - BRIEF  : CHECKS IF A STRING ENDS WITH A STRING
 *
 * - USAGE  : int ENDS_WITH = STRING_ENDS_WITH("HELLO", "LO");
*/
int STRING_CONTAINS_CHAR(const char* STRING, const char CHAR)
{

        for (unsigned long INDEX = 0; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (STRING[INDEX] == CHAR)
                {

                        return TRUE;


                        break;

                }

        }


        return FALSE;

}


/**
 * - BRIEF  : CHECKS IF A STRING IS IN AN VALID INT FORMAT
 *
 * - NOTE   : IF THE STRING STARTS WITH '0' BUT LENGTH IS > 1, IT RETURNS FALSE
 *
 * - USAGE  : int IS_INT = STRING_IS_INT("-12345");
*/
int STRING_IS_INT(const char* STRING)
{

        unsigned long STARTING_INDEX = 0;



        if (STRING_IS_EMPTY(STRING))
        {

                return FALSE;

        }


        if (STRING[0] == '-')
        {

                STARTING_INDEX = 1;

        }


        if (STRING[STARTING_INDEX] == '0' && STRING[STARTING_INDEX + 1] != '\0')
        {

                return FALSE;

        }


        for (unsigned long INDEX = STARTING_INDEX; STRING[INDEX] != '\0'; INDEX ++)
        {

                if (!STRING_CONTAINS_CHAR("0123456789", STRING[INDEX]))
                {

                        return FALSE;

                }

        }



        return TRUE;

}


/**
 * BRIEF  : RETURNS HOW MANY CHARS ARE IN THE GIVEN STRING
 *
 * USAGE  : int LENGTH = STRING_LENGTH("ABCDEF");
*/
unsigned long STRING_LENGTH(const char *STRING)
{

        unsigned long INDEX;


	for (INDEX = 0; STRING[INDEX] != '\0'; INDEX ++);


	return INDEX;

}


/**
 * BRIEF  : RETURNS HOW MANY BYTES USED BY THE STRING
 *
 * NOTE   : A STRING'S SIZE IS LENGTH + 1 (IF ASCII)
 *
 * USAGE  : int SIZE = STRING_SIZE("ABCDEF");
*/
unsigned long STRING_SIZE(const char* STRING)
{

        unsigned long INDEX;


	for (INDEX = 0; STRING[INDEX] != '\0'; INDEX ++);


	return INDEX + 1;

}
