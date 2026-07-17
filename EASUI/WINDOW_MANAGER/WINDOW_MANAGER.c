#include "../EASUI.h"



EASUI_WINDOW** WINDOW_LIST;
EASUI_WINDOW* ACTIVE_WINDOW;



unsigned long MAX_WINDOW_COUNT;

int GET_LAST_WINDOW_INDEX();



int EASUI__SETUP_WINDOW_LIST(const unsigned short WINDOW_COUNT)
{

        MAX_WINDOW_COUNT = WINDOW_COUNT;


        WINDOW_LIST = MEMORY_ARENA_ALLOC(sizeof(EASUI_WINDOW*) * (WINDOW_COUNT + 1));


        if (WINDOW_LIST == NULL)
        {

                LOG_EASUI_ERROR("FAILED TO SETUP WINDOW LIST : FAILED TO ALLOCATE MEMORY FOR WINDOW LIST");


                return EASUI_ERROR;

        }


        WINDOW_LIST[0] = NULL;


        return EASUI_OK;

}


int EASUI__ADD_WINDOW_TO_WINDOW_LIST(EASUI_WINDOW* WINDOW)
{

        if (WINDOW == NULL)
        {

                LOG_EASUI_ERROR("FAILED TO ADD WINDOW TO WINDOW LIST : ADDED WINDOW IS NULL");


                return EASUI_ERROR;

        }


        const int LAST_INDEX = GET_LAST_WINDOW_INDEX();


        if (LAST_INDEX + 1 == MAX_WINDOW_COUNT)
        {

                LOG_EASUI_ERROR("FAILED TO ADD WINDOW TO WINDOW LIST : NUMBER OF WINDOWS HAS EXCEEDED THE MAXIMUM");


                return EASUI_ERROR;

        }


        WINDOW_LIST[LAST_INDEX + 1] = WINDOW;
        WINDOW_LIST[LAST_INDEX + 2] = NULL;


        ACTIVE_WINDOW = WINDOW;


        return EASUI_OK;

}


int GET_LAST_WINDOW_INDEX()
{

        int INDEX = 0;


        for (; WINDOW_LIST[INDEX] != NULL; INDEX ++);


        return INDEX;

}
