#include "../EASUI.h"
#include <SDL3/SDL_init.h>
#include <stdlib.h>
#include <stdio.h>





void LOG_EASUI_ERROR(const char* MESSAGE)
{

        fprintf(stderr, "\033[1;31m[EASUI ERROR]\033[0m : | %s |\n", MESSAGE);

}


void LOG_EASUI_CRITICAL_ERROR(const char* MESSAGE)
{

        fprintf(stderr, "\033[1;31m[EASUI *CRITICAL* ERROR]\033[0m : | %s |\n", MESSAGE);

}


int EASUI_INIT(const unsigned short MAX_WINDOW_COUNT)
{

        // [SETUP SDL]
        {

                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
                SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


                #ifdef __linux__

                        SDL_SetHint(SDL_HINT_VIDEO_DRIVER, getenv("XDG_SESSION_TYPE"));

                #endif


                if (!SDL_Init(SDL_INIT_VIDEO))
                {

                        LOG_EASUI_CRITICAL_ERROR("FAILED TO INITIALIZE SDL VIDIEO");


                        return EASUI_ERROR;

                }

        }


        INIT_MEMORY_ARENA(1024);


        EASUI__SETUP_WINDOW_LIST(MAX_WINDOW_COUNT);


        EASUI__WINDOW_MANAGER_START();


        return EASUI_OK;

}


int ADD__ELEMENT__TO__FRAMED_ELEMENT(void* FRAMED_ELEMENT, void* ELEMENT)
{

        char FRAMED_TYPE = *(char*)FRAMED_ELEMENT;


        if (FRAMED_TYPE == EASUI_WINDOW_NUMBER)
        {

                #define FRAMED_PTR ((EASUI_WINDOW*)FRAMED_ELEMENT)


                FRAMED_PTR->ADD_ELEMENT(FRAMED_PTR, ELEMENT);

        }
        else
        {

                return EASUI_ERROR;

        }


        return EASUI_OK;

}


int EASUI_WAIT_AND_END()
{

        const int WINDOW_MANAGER_END_STATUS = EASUI__WINDOW_MANAGER_WAIT_AND_END();


        if (WINDOW_MANAGER_END_STATUS == EASUI_ERROR)
        {

                LOG_EASUI_CRITICAL_ERROR("FAILED TO END EASUI : DUE TO THE PREVIOUS ERROR");


                return EASUI_ERROR;

        }


        FREE_MEMORY_ARENA();


        SDL_Quit();


        return EASUI_OK;

}
