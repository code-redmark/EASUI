#include "../EASUI.h"




int GET_LAST_ELEMENT_INDEX(EASUI_WINDOW* WINDOW);


int ADD_ELEMENT(EASUI_WINDOW* WINDOW, void* ELEMENT);




int SET_NEW_EASUI_WINDOW(EASUI_WINDOW* WINDOW, const unsigned short MAX_ELEMENT_COUNT, const unsigned int WIDTH, const unsigned int HEIGHT)
{

        // [SET BASE VALUES]
        {

                WINDOW->TYPE = EASUI_WINDOW_NUMBER;
                WINDOW->MAX_ELEMENT_COUNT = MAX_ELEMENT_COUNT;
                WINDOW->WIDTH = WIDTH;
                WINDOW->HEIGHT = HEIGHT;
                WINDOW->ADD_ELEMENT = ADD_ELEMENT;

        }


        // [ALLOCATE MEMORY FOR ELEMENT LIST]
        {

                WINDOW->ELEMENT_LIST = MEMORY_ARENA_ALLOC(sizeof(void*) * MAX_ELEMENT_COUNT + 1);


                if (WINDOW->ELEMENT_LIST == NULL)
                {

                        return EASUI_ERROR;

                }


                WINDOW->ELEMENT_LIST[0] = NULL;

        }


        return EASUI_OK;

}


int ADD_ELEMENT(EASUI_WINDOW* WINDOW, void* ELEMENT)
{

        const int LAST_ELEMENT_INDEX = GET_LAST_ELEMENT_INDEX(WINDOW);


        if (LAST_ELEMENT_INDEX + 2 >= WINDOW->MAX_ELEMENT_COUNT)
        {

                return EASUI_ERROR;

        }


        WINDOW->ELEMENT_LIST[LAST_ELEMENT_INDEX + 1] = ELEMENT;
        WINDOW->ELEMENT_LIST[LAST_ELEMENT_INDEX + 2] = NULL;


        return 0;

}


int GET_LAST_ELEMENT_INDEX(EASUI_WINDOW* WINDOW)
{

        int INDEX = 0;


        for (; WINDOW->ELEMENT_LIST[INDEX] != NULL; INDEX ++);


        return INDEX - 1;

}
