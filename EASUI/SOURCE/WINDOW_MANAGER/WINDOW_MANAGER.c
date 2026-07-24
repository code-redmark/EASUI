#include "../EASUI_INTERNAL.h"



EASUI_WINDOW** WINDOW_LIST;
EASUI_WINDOW* ACTIVE_WINDOW;


SDL_GLContext EASUI__SDL_CONTEXT = EASUI_NONE;


unsigned short LAST_WINDOW_INDEX;
unsigned short MAX_WINDOW_COUNT;
unsigned short FRAMETIME_MILLISECONDS = 0;




EASUI_WINDOW* GET_FOCUSED_WINDOW();


int NO_WINDOWS_RUNNING();


void SET_FRAMETIME();




int EASUI__WINDOW_MANAGER__INIT(const unsigned short WINDOW_COUNT)
{

        const char* MESSAGE = "FAILED TO INITIALIZE WINDOW MANAGER";


        if (WINDOW_COUNT == 0)
        {

                LOG_EASUI_CRITICAL_ERROR(MESSAGE, "WINDOW COUNT MUST BE ATLEAST 1");


                return EASUI_ERROR;

        }


        // [SET DATA]
        {

                MAX_WINDOW_COUNT = WINDOW_COUNT;
                LAST_WINDOW_INDEX = 0;


                SET_FRAMETIME();

        }


        // [INITIALIZE WINDOW LIST]
        {

                WINDOW_LIST = MEMORY_ARENA_ALLOC(sizeof(EASUI_WINDOW*) * WINDOW_COUNT);


                if (WINDOW_LIST == NULL)
                {

                        LOG_EASUI_CRITICAL_ERROR(MESSAGE, "FAILED TO ALLOCATE MEMORY FOR WINDOW LIST");


                        return EASUI_ERROR;

                }


                WINDOW_LIST[0] = NULL;

        }


        return EASUI_OK;

}


int EASUI__WINDOW_MANAGER__RUN()
{

        // [WAIT FOR A WINDOW TO BE RUNNING]
        {

                while (WINDOW_LIST[0] == NULL)
                while (NO_WINDOWS_RUNNING());

        }


        while (!NO_WINDOWS_RUNNING())
        {

                int WINDOW_EVENT = EASUI__GET_EVENTS();


                EASUI_WINDOW* CURRENT_WINDOW = GET_FOCUSED_WINDOW();



                if (CURRENT_WINDOW == NULL)
                {

                        continue;

                }


                if (WINDOW_EVENT == EASUI_CLOSE_WINDOW_EVENT)
                {

                        SDL_DestroyWindow(WINDOW_INTERNAL_DATA(CURRENT_WINDOW)->SDL_WINDOW);


                        WINDOW_INTERNAL_DATA(CURRENT_WINDOW)->STATUS = EASUI_WINDOW_CLOSED;


                        continue;

                }


                // [RENDER CURRENT WINDOW]
                {

                        WINDOW_INTERNAL_DATA(CURRENT_WINDOW)->UPDATE_SIZE_AND_CONTEXT_SIZE(CURRENT_WINDOW);


                        EASUI__RENDER_WINDOW(CURRENT_WINDOW);

                }


                SDL_Delay(FRAMETIME_MILLISECONDS);

        }


        SDL_GL_DestroyContext(EASUI__SDL_CONTEXT);


        return EASUI_OK;

}


int NO_WINDOWS_RUNNING()
{

        for (unsigned short INDEX = 0; INDEX <= LAST_WINDOW_INDEX; INDEX ++)
        {

                if (WINDOW_INTERNAL_DATA(WINDOW_LIST[INDEX])->STATUS == EASUI_WINDOW_RUNNNING)
                {

                        return FALSE;

                }

        }


        return TRUE;

}


int EASUI__ADD_WINDOW_TO_WINDOW_LIST(EASUI_WINDOW* WINDOW)
{

        const char* MESSAGE = "FAILED TO ADD WINDOW TO WINDOW LIST";


        if (WINDOW == NULL)
        {

                LOG_EASUI_ERROR(MESSAGE, "ADDED WINDOW IS NULL");


                return EASUI_ERROR;

        }


        // [ADD WINDOW TO WINDOW LIST]
        {

                const int OFFSET = (WINDOW_LIST[0] == NULL);


                if (LAST_WINDOW_INDEX + 1 - OFFSET >= MAX_WINDOW_COUNT)
                {

                        LOG_EASUI_ERROR(MESSAGE, "NUMBER OF WINDOWS HAS EXCEEDED THE MAXIMUM");


                        return EASUI_ERROR;

                }


                WINDOW_LIST[LAST_WINDOW_INDEX + 1 - OFFSET] = WINDOW;


                if (!OFFSET)
                {

                        LAST_WINDOW_INDEX ++;

                }


                ACTIVE_WINDOW = WINDOW;

        }


        return EASUI_OK;

}


EASUI_WINDOW* GET_FOCUSED_WINDOW()
{

        const SDL_Window* FOCUSED_SDL_WINDOW = SDL_GetKeyboardFocus();



        if (FOCUSED_SDL_WINDOW == NULL)
        {

                return NULL;

        }


        for (unsigned short INDEX = 0; INDEX <= LAST_WINDOW_INDEX; INDEX ++)
        {

                if (WINDOW_INTERNAL_DATA(WINDOW_LIST[INDEX])->SDL_WINDOW == FOCUSED_SDL_WINDOW)
                {

                        return WINDOW_LIST[INDEX];

                }

        }


        LOG_EASUI_ERROR("FAILED TO GET FOCUSED WINDOW", "COULDNT MATCH FOCUSED SDL WINDOW WITHIN WINDOW LIST");


        return NULL;

}


EASUI_WINDOW* GET__WINDOW__FROM__SDL_WINDOW(const SDL_Window* SDL_WINDOW)
{

        const char* MESSAGE = "FAILED GET WINDOW FROM SDL WINDOW";


        if (SDL_WINDOW == NULL)
        {

                LOG_EASUI_ERROR(MESSAGE, "SDL WINDOW IS NULL");


                return NULL;

        }


        for (unsigned short INDEX = 0; INDEX <= LAST_WINDOW_INDEX; INDEX ++)
        {

                if (WINDOW_INTERNAL_DATA(WINDOW_LIST[INDEX])->SDL_WINDOW == SDL_WINDOW)
                {

                        return WINDOW_LIST[INDEX];

                }

        }


        LOG_EASUI_ERROR(MESSAGE, "NO WINDOW HAS THE SDL WINDOW");


        return NULL;

}


void SET_FRAMETIME()
{

        const char* MESSAGE = "FAILED TO SET MONITORS FRAMETIME";


        const SDL_DisplayMode* DISPLAY_MODE;


        float REFRESH_RATE = EASUI__DEFAULT__REFRESH_RATE;



        // [GET DISPLAY MODE]
        {

                SDL_DisplayID DISPLAY_ID = SDL_GetPrimaryDisplay();


                if (DISPLAY_ID == 0)
                {

                        LOG_EASUI_ERROR(MESSAGE, "DISPLAY ID IS 0");


                        goto SET_FRAMETIME;

                }


                DISPLAY_MODE = SDL_GetDesktopDisplayMode(DISPLAY_ID);


                if (!DISPLAY_MODE)
                {

                        LOG_EASUI_ERROR(MESSAGE, "DISPLAY MODE IS NULL");


                        goto SET_FRAMETIME;

                }


                REFRESH_RATE = DISPLAY_MODE->refresh_rate;

        }


        SET_FRAMETIME:
        {

                FRAMETIME_MILLISECONDS = 1000 / REFRESH_RATE;

        }

}
