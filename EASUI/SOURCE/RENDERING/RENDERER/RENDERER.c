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
                printf("\nRendering label: \n POS: %f, %f\nSIZE: %f, %f\n", LABEL->POSITION.x, LABEL->POSITION.y, LABEL->SIZE.x, LABEL->SIZE.y);
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

    printf("[EASUI__RENDER_ELEMENT] Rendered element of type %d OK\n", TYPE);
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

                        WINDOW->UPDATE_SIZE_AND_CONTEXT_SIZE(WINDOW);
                        UPDATE_PROJECTION_DATA(WINDOW);

                        glViewport(0, 0, (int)WINDOW->SIZE.x, (int)WINDOW->SIZE.y);

                        glClearColor(WINDOW->BG_COLOR.x, WINDOW->BG_COLOR.y, WINDOW->BG_COLOR.z, 1.0f);
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                        printf("[EASUI__RENDER_WINDOW] window size: %fx%f\n", WINDOW->SIZE.x, WINDOW->SIZE.y);

                        RenderRectangle((EASUIvec2) { 200.f, 80.f }, 0.f, (EASUIvec2) { 100.f, 100.f }, (EASUIvec3) { 1.f, 0.f, 1.f });

                        //EASUI_SCREEN* current = WINDOW->ACTIVE_SCREEN != &WINDOW->DEFAULT_SCREEN ? WINDOW->ACTIVE_SCREEN : &WINDOW->DEFAULT_SCREEN;

                        //for (int i = 0; i < current->LAST_ELEMENT_INDEX + 1; i++)
                        //{
                        //    if (current->ELEMENT_LIST[i] != NULL) EASUI__RENDER_ELEMENT(current->ELEMENT_LIST[i]);
                        //}

                        SDL_GL_SwapWindow(WINDOW->SDL_WINDOW);

                        GLenum err = glad_glGetError();
                        if (err != GL_NO_ERROR) printf("[EASUI__RENDER_WINDOW] GL error after render: %d\n", err);
                        else printf("[EASUI__RENDER_WINDOW] Window rendered OK\n");

                }

        }


        return EASUI_OK;

}




