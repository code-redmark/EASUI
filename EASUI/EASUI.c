#include "EASUI.h"



int EASUI_INIT()
{

        INIT_MEMORY_AREMA(1024);


        if (!SDL_Init(SDL_INIT_VIDEO))
        {

                return EASUI_ERROR;

        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


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


void EASUI_END()
{

        FREE_MEMORY_ARENA();

}
