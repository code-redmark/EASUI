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

                        

                        glClearColor(WINDOW->BG_COLOR.x, WINDOW->BG_COLOR.y, WINDOW->BG_COLOR.z, 1.0f);
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                        mat4 transform;
                        glm_mat4_identity(transform);

                        glm_scale(transform, (vec3) { 200.f, 80.f, 1.f });
                        glm_translate(transform, (vec3) { 0.f, 0.f, 0.f });
                        //glm_rotate(transform, ROTATION, (vec3) { 0.f, 0.f, 1.f });
                        

                        vec4 color = { 1.f, 1.f, 1.f, 1.f };

                        glad_glUseProgram(RECTANGLE_DATA.PROGRAM);

                        glad_glBindVertexArray(RECTANGLE_DATA.VAO);

                        GLint modelLocation = glad_glGetUniformLocation(RECTANGLE_DATA.PROGRAM, MODEL_MAT_UNIFORM_NAME);
                        glad_glUniformMatrix4fv(modelLocation, 1, GL_FALSE, (float*)transform);

                        GLint colorLocation = glad_glGetUniformLocation(RECTANGLE_DATA.PROGRAM, FRAGMENT_COLOR_UNIFORM_NAME);
                        glad_glUniform4fv(colorLocation, 1, (float*)color);

                        glad_glDrawElements(GL_TRIANGLES, RECTANGLE_DATA.INDEX_COUNT, GL_UNSIGNED_INT, (void*)0);
                        
                        
                        //EASUI_SCREEN* current = WINDOW->ACTIVE_SCREEN != &WINDOW->DEFAULT_SCREEN ? WINDOW->ACTIVE_SCREEN : &WINDOW->DEFAULT_SCREEN;

                        //for (int i = 0; i < current->LAST_ELEMENT_INDEX + 1; i++)
                        //{
                        //    if (current->ELEMENT_LIST[i] != NULL) EASUI__RENDER_ELEMENT(current->ELEMENT_LIST[i]);
                        //}

                        SDL_GL_SwapWindow(WINDOW->SDL_WINDOW);

                }

        }


        return EASUI_OK;

}




