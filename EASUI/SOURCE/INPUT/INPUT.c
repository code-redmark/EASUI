#include "../../EASUI.h"
#include <SDL3/SDL_events.h>




int EASUI__POLL_EVENTS()
{

        SDL_Event SDL_EVENT;


        while (SDL_PollEvent(&SDL_EVENT) != 0)
        {

                if (SDL_EVENT.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
                {

                        return EASUI_CLOSE_WINDOW_EVENT;

                }

                if (SDL_EVENT.type == SDL_EVENT_WINDOW_RESIZED)
                {

                        EASUI_WINDOW* FOCUSED_WINDOW = GET_FOCUSED_WINDOW();


                        FOCUSED_WINDOW->UPDATE_CONTEXT_SIZE(FOCUSED_WINDOW);

                }

        }


        return EASUI_NO_WINDOW_EVENT;

}
