#include "../../EASUI.h"
#include "../BACKEND//PRIMITIVES/PRIMITIVES.h"




void EASUI__RENDER_ELEMENT(void* ELEMENT)
{
    GLenum err = glad_glGetError();
    if (err != GL_NO_ERROR) printf("\nError: %d\n", err);

    char TYPE = *(char*)ELEMENT;
    
    switch (TYPE)
    {
        case EASUI_LABEL_NUMBER:
            {
                EASUI_LABEL* LABEL = (EASUI_LABEL*)ELEMENT;
                RenderRectangle(LABEL->SIZE, 0.f, LABEL->POSITION, LABEL->TEXT_COLOR);
            };
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

        {
                {

                        SDL_GL_MakeCurrent(WINDOW->SDL_WINDOW, EASUI__SDL_CONTEXT);

                        UPDATE_PROJECTION_DATA(WINDOW);

                        glClearColor(WINDOW->BG_COLOR.r, WINDOW->BG_COLOR.g, WINDOW->BG_COLOR.b, WINDOW->BG_COLOR.a);
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                        EASUI_SCREEN* CURRENT = WINDOW->ACTIVE_SCREEN != &WINDOW->DEFAULT_SCREEN ? WINDOW->ACTIVE_SCREEN : &WINDOW->DEFAULT_SCREEN;

                        if (!CURRENT->IS_EMPTY)
                        {
                            for (int i = 0; i <= CURRENT->LAST_ELEMENT_INDEX; i++)
                            {
                                void* ELEMENT = CURRENT->ELEMENT_LIST[i];
                                EASUI__RENDER_ELEMENT(ELEMENT);
                            }
                        }
                }

                SDL_GL_SwapWindow(WINDOW->SDL_WINDOW);

                GLenum err = glad_glGetError();
                if (err != GL_NO_ERROR) printf("[EASUI__RENDER_WINDOW] GL error after render: %d\n", err);
                

        }
        return EASUI_OK;
}




