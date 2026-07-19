#include "../../EASUI.h"
#include <SDL3/SDL_events.h>




int EASUI__GET_EVENTS()
{

        SDL_Event SDL_EVENT;


        while (SDL_WaitEvent(&SDL_EVENT) != 0)
        {

                if (SDL_EVENT.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
                {

                        return EASUI_CLOSE_WINDOW_EVENT;

                }

        }


        return EASUI_NO_WINDOW_EVENT;

}
