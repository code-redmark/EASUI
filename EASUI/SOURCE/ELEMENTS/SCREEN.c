#include "../EASUI_INTERNAL.h"




int SCREEN_ADD_ELEMENT(EASUI_SCREEN* SCREEN, void* ELEMENT);




int SET_NEW_EASUI_SCREEN(EASUI_SCREEN* SCREEN, const unsigned short MAX_ELEMENT_COUNT)
{

        // [NULL POINTER CHECKS]
        {

                if (SCREEN == NULL)
                {

                        LOG_EASUI_ERROR("FAILED TO SET NEW SCREEN : SCREEN POINTER IS NULL");


                        return EASUI_ERROR;

                }

        }


        // [ALLOCATE MEMORY FOR INTERNAL DATA]
        {

                SCREEN->INTERNAL_DATA = MEMORY_ARENA_ALLOC(sizeof(EASUI_SCREEN__INTERNAL_DATA));


                if (SCREEN->INTERNAL_DATA == NULL)
                {

                        LOG_EASUI_ERROR("FAILED TO SET NEW SCREEN : FAILED TO ALLOCATE MEMORY FOR INTERNAL DATA");


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

                SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST = MEMORY_ARENA_ALLOC(sizeof(void*) * MAX_ELEMENT_COUNT);


                if (SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST == NULL)
                {

                        LOG_EASUI_ERROR("FAILED TO SET NEW SCREEN : FAILED TO ALLOCATE MEMORY FOR ELEMENT LIST");


                        return EASUI_ERROR;

                }


                SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST[0] = NULL;

        }


        return EASUI_OK;

}


int SCREEN_ADD_ELEMENT(EASUI_SCREEN* SCREEN, void* ELEMENT)
{

        const int OFFSET = (SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST[0] == NULL);


        if (SCREEN_INTERNAL_DATA(SCREEN)->LAST_ELEMENT_INDEX + 1 - OFFSET >= SCREEN_INTERNAL_DATA(SCREEN)->MAX_ELEMENT_COUNT)
        {

                LOG_EASUI_ERROR("FAILED TO ADD ELEMENT TO SCREEN : ELEMENT COUNT EXCEEDED THE MAXIMUM");


                return EASUI_ERROR;

        }


        SCREEN_INTERNAL_DATA(SCREEN)->ELEMENT_LIST[SCREEN_INTERNAL_DATA(SCREEN)->LAST_ELEMENT_INDEX + 1 - OFFSET] = ELEMENT;


        return EASUI_OK;

}
