#include "../../EASUI.h"
#include "../BACKEND//PRIMITIVES/PRIMITIVES.h"

OBJECT_RENDERING_DATA* RECTANGLE_DATA = NULL;

/*
    Basic shader for rendering all of EASUIs primitives
*/
GLuint* EASUI_PRIMITIVE_SHADER_PROGRAM = NULL;


void EASUI__RENDER_ELEMENT(void* ELEMENT)
{
    char TYPE = *(char*)ELEMENT;
    
    switch (TYPE)
    {
        case EASUI_LABEL_NUMBER:
            {
                EASUI_LABEL* LABEL = (EASUI_LABEL*)ELEMENT;
                RenderRectangle(LABEL->SIZE, 0.f, LABEL->POSITION, (EASUIvec3) { 127.f, 0.f, 255.f });
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

                        
                        int width, height;
                        SDL_GetWindowSize(WINDOW->SDL_WINDOW, &width, &height);

                        glClearColor(WINDOW->BG_COLOR.x, WINDOW->BG_COLOR.y, WINDOW->BG_COLOR.z, 1.0f);
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                        mat4 proj;
                        glm_ortho(0.f, width, 0.f, height, -1.f, 1.f, proj);

                        EASUI_SCREEN* current = WINDOW->ACTIVE_SCREEN != &WINDOW->DEFAULT_SCREEN ? WINDOW->ACTIVE_SCREEN : &WINDOW->DEFAULT_SCREEN;

                        for (int i = 0; i < current->LAST_ELEMENT_INDEX + 1; i++)
                        {
                            if (current->ELEMENT_LIST[i] != NULL) EASUI__RENDER_ELEMENT(current->ELEMENT_LIST[i]);
                        }

                        SDL_GL_SwapWindow(WINDOW->SDL_WINDOW);

                }

        }


        return EASUI_OK;

}




