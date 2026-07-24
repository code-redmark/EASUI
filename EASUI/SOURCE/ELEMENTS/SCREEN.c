#include "../EASUI_INTERNAL.h"
#include <stdlib.h>




int SCREEN_ADD_ELEMENT(EASUI_SCREEN* SCREEN, void* ELEMENT);




int SET_NEW_EASUI_SCREEN(EASUI_SCREEN* SCREEN, const unsigned short MAX_ELEMENT_COUNT)
{

        const char* MESSAGE = "FAILED TO SET NEW SCREEN";



        // [NULL POINTER CHECKS]
        {

                if (SCREEN == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "SCREEN IS NULL");


                        return EASUI_ERROR;

                }

        }


        // [ALLOCATE MEMORY FOR INTERNAL DATA]
        {

                SCREEN->INTERNAL_DATA = MEMORY_ARENA_ALLOC(sizeof(EASUI_SCREEN__INTERNAL_DATA));


                if (SCREEN->INTERNAL_DATA == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "FAILED TO ALLOCATE MEMORY FOR INTERNAL DATA");


                        return EASUI_ERROR;

                }

        }


        // [SET BASE VALUES]
        {

                SCREEN_INTERNAL_DATA(SCREEN)->TYPE = EASUI_SCREEN_NUMBER;
                SCREEN_INTERNAL_DATA(SCREEN)->MAX_ELEMENT_COUNT = MAX_ELEMENT_COUNT;
                SCREEN_INTERNAL_DATA(SCREEN)->LAST_ELEMENT_INDEX = 0;
                SCREEN->ADD_ELEMENT = SCREEN_ADD_ELEMENT;

        }


        // [ALLOCATE MEMORY FOR ELEMENT LIST]
        {

                if (MAX_ELEMENT_COUNT == 0)
                {

                        LOG_EASUI_ERROR(MESSAGE, "MAX ELEMENT COUNT IS 0");


                        return EASUI_ERROR;

                }


                SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST = MEMORY_ARENA_ALLOC(sizeof(void*) * MAX_ELEMENT_COUNT);


                if (SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "FAILED TO ALLOCATE MEMORY FOR ELEMENT LIST");


                        return EASUI_ERROR;

                }


                SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST[0] = NULL;

        }


        return EASUI_OK;

}


int SCREEN_ADD_ELEMENT(EASUI_SCREEN* SCREEN, void* ELEMENT)
{

        const char* MESSAGE = "FAILED TO ADD ELEMENT TO SCREEN";


        // [NULL POINTER CHECKS]
        {

                if (SCREEN == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "SCREEN IS NULL");


                        return EASUI_ERROR;

                }


                if (SCREEN->INTERNAL_DATA == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "SCREEN INTERNAL DATA IS NULL");


                        return EASUI_ERROR;

                }


                if (ELEMENT == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "ELEMENT IS NULL");


                        return EASUI_ERROR;

                }

        }


        const int OFFSET = (SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST[0] == NULL);


        if (SCREEN_INTERNAL_DATA(SCREEN)->LAST_ELEMENT_INDEX + 1 - OFFSET >= SCREEN_INTERNAL_DATA(SCREEN)->MAX_ELEMENT_COUNT)
        {

                LOG_EASUI_ERROR(MESSAGE, "ELEMENT COUNT EXCEEDED THE MAXIMUM");


                return EASUI_ERROR;

        }


        SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST[SCREEN_INTERNAL_DATA(SCREEN)->LAST_ELEMENT_INDEX + 1 - OFFSET] = ELEMENT;


        return EASUI_OK;

}
