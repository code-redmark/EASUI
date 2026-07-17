#include "STRING_LISTS.h"




/**
 * - BRIEF  : SETUPS A NULL-TEMINATED STRING
 *
 * - NOTE 1 : IT USES malloc() TO GIVE BUFFER FOR THE STRING LIST, TO FREE, FREE_STRING_LIST() IS RECOMMENDED
 *
 * - NOTE 2 : IF all malloc()s FAILS, FUNCTION RETURNS STRLIST_FAILURE, OTHERWISE, STR_SUCCESS
 *
 * - USAGE  : STRING_LIST_SETUP(&STRING_LIST, 10, 64);
*/
int STRING_LIST_SETUP(char*** STRING_LIST, const unsigned long LIST_SIZE, const unsigned long STRING_SIZE)
{

        *STRING_LIST = malloc((LIST_SIZE + 1) * sizeof(char*));



        if (*STRING_LIST == NULL)
        {

                return STRLIST_FAILURE;

        }


        for (unsigned long INDEX = 0; INDEX < LIST_SIZE; INDEX ++)
        {

                (*STRING_LIST)[INDEX] = malloc(STRING_SIZE);


                if ((*STRING_LIST)[INDEX] == NULL)
                {

                        for (unsigned long COUNTER = 0; COUNTER < INDEX; COUNTER ++)
                        {

                                free((*STRING_LIST)[COUNTER]);

                        }


                        free(*STRING_LIST);


                        *STRING_LIST = NULL;


                        return STRLIST_FAILURE;

                }


                STRING_CLEAR((*STRING_LIST)[INDEX]);

        }



        (*STRING_LIST)[LIST_SIZE] = NULL;



        return STR_SUCCESS;

}


/**
 * - BRIEF  : FREES THE GIVEN STRING LIST
 *
 * - NOTE   : FOR EACH STRING IN THE STRING LIST, IF ANY ONE IS NULL, FUNCTION RETURNS STRLIST_FAILURE, OTHERWISE, STRLIST_SUCCESS
 *
 * - USAGE  : FREE_STRING_LIST(&STRING_LIST);
*/
int FREE_STRING_LIST(char*** STRING_LIST)
{

        const unsigned long LIST_SIZE = STRING_LIST_SIZE(STRING_LIST);



        for (unsigned long INDEX = 0; INDEX < LIST_SIZE; INDEX ++)
        {

                char* STRING = (*STRING_LIST)[INDEX];


                if (STRING == NULL)
                {

                        return STRLIST_FAILURE;

                }


                free(STRING);

        }


        free(*STRING_LIST);



        return STRLIST_SUCCESS;

}


/**
 * - BRIEF  : APPENDS A STRING TO THE GIVEN STRING LIST
 *
 * - NOTE   : IF THERE ARE NO SPACES LEFT TO APPEND, FUNCTION RETURNS STRLIST_FAILURE, OTHERWISE, STRLIST_SUCCESS
 *
 * - USAGE  : STRING_LIST_APPEND(&STRING_LIST, "HELLO WORLD");
*/
int STRING_LIST_APPEND(char*** STRING_LIST, const char* APPEND_STRING)
{

        unsigned long LIST_SIZE = STRING_LIST_SIZE(STRING_LIST);
        unsigned long INDEX = LIST_SIZE - 1;



        while (STRING_EQUALS((*STRING_LIST)[INDEX], EMPTY) && INDEX > 0)
        {

                INDEX --;

        }


        if (INDEX == LIST_SIZE - 1)
        {

                return STRLIST_FAILURE;

        }


        if (INDEX == 0 && STRING_EQUALS((*STRING_LIST)[0], EMPTY))
        {

                STRING_COPY((*STRING_LIST)[0], APPEND_STRING);


                return STRLIST_SUCCESS;

        }



        STRING_COPY((*STRING_LIST)[INDEX + 1], APPEND_STRING);



        return STRLIST_SUCCESS;

}


/**
 * - BRIEF  : APPENDS A STRING TO THE GIVEN STRING LIST
 *
 * - NOTE   : MAKE SURE THAT THE LIST IS NULL-TERMINATED, USING STRING_LIST_SETUP() IS RECOMMENDED
 *
 * - USAGE  : int LIST_SIZE = STRING_LIST_SIZE(&STRING_LIST);
*/
unsigned long STRING_LIST_SIZE(char*** STRING_LIST)
{

        unsigned long INDEX = 0;


        while ((*STRING_LIST)[INDEX] != NULL)
        {

                INDEX ++;

        }


        return INDEX;

}
