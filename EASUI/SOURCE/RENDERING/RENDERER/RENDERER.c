#include "../../EASUI.h"
#include "../BACKEND//PRIMITIVES/PRIMITIVES.h"


void EASUI__RENDER_ELEMENT(void* ELEMENT)
{
    char TYPE = *(char*)ELEMENT;

    switch (TYPE)
    {
        case EASUI_FRAME_NUMBER: // frame is prob just going to be a way to group stuff
            //RenderRectangle(POSITION, SIZE);
            break;
        case EASUI_SCREEN_NUMBER:
            //RenderContainer or smth
            break;
        case EASUI_TEXTBOX_NUMBER:
            //RenderRectangle(POSITION, SIZE);
            //RenderTextfield(POSITION, (EASUI_TEXTBOX*)ELEMENT->TEXT, EASUI_FONT FONT);
            break;
    }
}

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


                        glClearColor(WINDOW->BG_COLOR.x, WINDOW->BG_COLOR.y, WINDOW->BG_COLOR.z, 1.0f);
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                        EASUI_SCREEN* current = WINDOW->ACTIVE_SCREEN != &WINDOW->DEFAULT_SCREEN ? WINDOW->ACTIVE_SCREEN : &WINDOW->DEFAULT_SCREEN;

                        for (int i = 0; i < current->LAST_ELEMENT_INDEX; i++)
                        {
                            char type = *(char*)current->ELEMENT_LIST[i];
                            
                        }

                        SDL_GL_SwapWindow(WINDOW->SDL_WINDOW);

                }

        }


        return EASUI_OK;

}




