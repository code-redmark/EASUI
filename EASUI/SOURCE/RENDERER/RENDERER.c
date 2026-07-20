#include "../../EASUI.h"




int EASUI__RENDER_WINDOW(EASUI_WINDOW* WINDOW)
{

        if (WINDOW == NULL)
        {

                LOG_EASUI_ERROR("FAILED TO RENDER WINDOW : WINDOW IS NULL");


                return EASUI_ERROR;

        }


        // [RENDER]
        {

                // !----------------! TEMPORARY !----------------!
                {

                        SDL_GL_MakeCurrent(WINDOW->SDL_WINDOW, EASUI__SDL_CONTEXT);


                        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


                        SDL_GL_SwapWindow(WINDOW->SDL_WINDOW);

                }

        }


        return EASUI_OK;

}
