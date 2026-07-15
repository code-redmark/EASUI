#include "../EASUI.h"




int SET_NEW_EASUI_WINDOW(EASUI_WINDOW* WINDOW, const unsigned short MAX_ELEMENT_COUNT, const unsigned int WIDTH, const unsigned int HEIGHT)
{

        WINDOW->TYPE = EASUI_WINDOW_NUMBER;
        WINDOW->MAX_ELEMENT_COUNT = MAX_ELEMENT_COUNT;
        WINDOW->WIDTH = WIDTH;
        WINDOW->HEIGHT = HEIGHT;



        // [ALLOCATE MEMORY FOR ELEMENT LIST]
        {

                WINDOW->ELEMENT_LIST = malloc(sizeof(void*) * MAX_ELEMENT_COUNT + 1);


                if (WINDOW->ELEMENT_LIST == NULL)
                {

                        return EASUI_ERROR;

                }


                WINDOW->ELEMENT_LIST[0] = NULL;

        }


        return EASUI_OK;

}
