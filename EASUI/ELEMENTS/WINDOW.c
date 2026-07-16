#include "../EASUI.h"
#include <X11/X.h>
#include <stdlib.h>




int GET_LAST_ELEMENT_INDEX(EASUI_WINDOW* WINDOW);


int ADD_ELEMENT(EASUI_WINDOW* WINDOW, void* ELEMENT);


int START(EASUI_WINDOW* WINDOW);


void* WINDOW_MAIN__THREAD(void* arg);




int SET_NEW_EASUI_WINDOW(EASUI_WINDOW* WINDOW, const char* TITLE, const unsigned short MAX_ELEMENT_COUNT, const unsigned int WIDTH, const unsigned int HEIGHT)
{

        // [SET BASE VALUES]
        {

                WINDOW->TYPE = EASUI_WINDOW_NUMBER;
                WINDOW->MAX_ELEMENT_COUNT = MAX_ELEMENT_COUNT;
                WINDOW->WIDTH = WIDTH;
                WINDOW->HEIGHT = HEIGHT;
                WINDOW->ADD_ELEMENT = ADD_ELEMENT;
                WINDOW->START = START;

        }


        // [CHECK FOR NULL POINTERS]
        {

                if (WINDOW == NULL || TITLE == NULL)
                {

                        return EASUI_ERROR;

                }

        }


        // [ALLOCATE MEMORY FOR ELEMENT LIST]
        {

                WINDOW->ELEMENT_LIST = MEMORY_ARENA_ALLOC(sizeof(void*) * MAX_ELEMENT_COUNT + 1);


                if (WINDOW->ELEMENT_LIST == NULL)
                {

                        return EASUI_ERROR;

                }


                WINDOW->ELEMENT_LIST[0] = NULL;

        }


        //  [ALLOCATE MEMORY FOR TITLE]
        {

                const unsigned long SIZE = STRING_SIZE(TITLE);


                WINDOW->TITLE = malloc(SIZE);


                if (WINDOW->TITLE == NULL)
                {

                        return EASUI_ERROR;

                }


                STRING_COPY(WINDOW->TITLE, TITLE);

        }


        return EASUI_OK;

}


int START(EASUI_WINDOW* WINDOW)
{

        // [CREATE WINDOW AND CONTEXT]
        {

                WINDOW->SDL_WINDOW = SDL_CreateWindow(WINDOW->TITLE, WINDOW->WIDTH, WINDOW->HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);


                if (!WINDOW->SDL_WINDOW)
                {

                        SDL_Quit();


                        return EASUI_ERROR;

                }


                WINDOW->SDL_CONTEXT = SDL_GL_CreateContext(WINDOW->SDL_WINDOW);


                if (!WINDOW->SDL_CONTEXT)
                {

                        SDL_DestroyWindow(WINDOW->SDL_WINDOW);


                        SDL_Quit();


                        return EASUI_ERROR;
                }


                SDL_GL_MakeCurrent(WINDOW->SDL_WINDOW, WINDOW->SDL_CONTEXT);


                SDL_GL_SetSwapInterval(1);

        }


        // [CREATE THREAD]
        {

                const int CREATE_PTHREAD_STATUS = pthread_create(&WINDOW->THREAD, NULL, WINDOW_MAIN__THREAD, (void*)WINDOW);


                if (CREATE_PTHREAD_STATUS != 0)
                {

                        return EASUI_ERROR;

                }


                pthread_join(WINDOW->THREAD, NULL);

        }



        return EASUI_OK;

}


void* WINDOW_MAIN__THREAD(void* VOID_WINDOW)
{

        EASUI_WINDOW* WINDOW = (EASUI_WINDOW*)VOID_WINDOW;


        bool IS_RUNNING = TRUE;
        SDL_Event EVENT;


        while (IS_RUNNING)
        {


                while (SDL_PollEvent(&EVENT))
                {

                        if (EVENT.type == SDL_EVENT_QUIT)
                        {

                                IS_RUNNING = false;

                        }

                }


                glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


                SDL_GL_SwapWindow(WINDOW->SDL_WINDOW);
        }


        SDL_GL_DestroyContext(WINDOW->SDL_CONTEXT);
        SDL_DestroyWindow(WINDOW->SDL_WINDOW);
        SDL_Quit();


        return NULL;

}


int ADD_ELEMENT(EASUI_WINDOW* WINDOW, void* ELEMENT)
{

        const int LAST_ELEMENT_INDEX = GET_LAST_ELEMENT_INDEX(WINDOW);


        if (LAST_ELEMENT_INDEX + 2 >= WINDOW->MAX_ELEMENT_COUNT)
        {

                return EASUI_ERROR;

        }


        WINDOW->ELEMENT_LIST[LAST_ELEMENT_INDEX + 1] = ELEMENT;
        WINDOW->ELEMENT_LIST[LAST_ELEMENT_INDEX + 2] = NULL;


        return 0;

}


int GET_LAST_ELEMENT_INDEX(EASUI_WINDOW* WINDOW)
{

        int INDEX = 0;


        for (; WINDOW->ELEMENT_LIST[INDEX] != NULL; INDEX ++);


        return INDEX - 1;

}
