#define EASUI_INTERNAL
#ifdef EASUI_INTERNAL



#include "../EASUI.h"



#define EASUI__DEFAULT__REFRESH_RATE 60
#define EASUI__DEFAULT__MEMORY_ARENA_SIZE 1024



// [ENUMS] ===========================================================================================================
//
        enum EASUI_ELEMENT_TYPE_NUMBERS
        {

                EASUI_WINDOW_NUMBER,
                EASUI_SCREEN_NUMBER,
                EASUI_TEXTBOX_NUMBER,
                EASUI_LABEL_NUMBER

        };

        enum EASUI_WINDOW_STATUS_NUMBERS
        {

                EASUI_WINDOW_UNINITIALIZED,
                EASUI_WINDOW_READY,
                EASUI_WINDOW_RUNNNING,
                EASUI_WINDOW_CLOSED,

        };

        enum EASUI_WINDOW_EVENT_NUMBERS
        {

                EASUI_NO_WINDOW_EVENT,
                EASUI_CLOSE_WINDOW_EVENT,

        };

//
// ===================================================================================================================



// [GLOBAL VARIABLES] ================================================================================================
//

        extern SDL_GLContext EASUI__SDL_CONTEXT;
        extern unsigned short FRAMETIME_MILLISECONDS;

//
// ===================================================================================================================



// [LAZY MACROS] =====================================================================================================
//

        #define BASE_ELEMENT_INTERNAL_DATA(BASE_ELEMENT) ((EASUI_BASE_ELEMENT__INTERNAL_DATA*)((BASE_ELEMENT)->INTERNAL_DATA))
        #define WINDOW_INTERNAL_DATA(WINDOW) ((EASUI_WINDOW__INTERNAL_DATA*)(WINDOW->INTERNAL_DATA))
        #define SCREEN_INTERNAL_DATA(SCREEN) ((EASUI_SCREEN__INTERNAL_DATA*)(SCREEN->INTERNAL_DATA))
        #define LABEL_INTERNAL_DATA(LABEL) ((EASUI_LABEL__INTERNAL_DATA*)(LABEL->INTERNAL_DATA))

//
// ===================================================================================================================



// [FUNCTIONS] ========================================================================================================
//
        int EASUI__WINDOW_MANAGER__INIT(const unsigned short MAX_WINDOW_COUNT);


        int EASUI__WINDOW_MANAGER__RUN();


        int EASUI__ADD_WINDOW_TO_WINDOW_LIST(EASUI_WINDOW* WINDOW);


        EASUI_WINDOW* GET_FOCUSED_WINDOW();


        int EASUI__RENDER_WINDOW(EASUI_WINDOW* WINDOW);


        int EASUI__GET_EVENTS();


        int ADD__ELEMENT__TO__FRAMED_ELEMENT(EASUI_BASE_ELEMENT* FRAMED_ELEMENT, void* ELEMENT);


        int MEMORY_ARENA__INIT(const size_t DEFAULT_ALLOCATION_SIZE);


        void* MEMORY_ARENA_ALLOC(size_t SIZE);


        void FREE_MEMORY_ARENA(void);


        void LOG_EASUI_ERROR(const char* MESSAGE);


        void LOG_EASUI_CRITICAL_ERROR(const char* MESSAGE);

//
// ====================================================================================================================



// [INTERNAL DATA] ====================================================================================================
//
        // [BASE_ELEMENT] ===============================================
        //
                typedef struct EASUI_BASE_ELEMENT__INTERNAL_DATA
                {

                        char TYPE;

                }
                EASUI_BASE_ELEMENT__INTERNAL_DATA;

        //
        // ==============================================================


        // [WINDOW] =====================================================
        //
                typedef struct EASUI_WINDOW__INTERNAL_DATA
                {

                        char TYPE;
                        char STATUS;
                        SDL_Window* SDL_WINDOW;
                        EASUI_SCREEN* ACTIVE_SCREEN;
                        EASUI_SCREEN DEFAULT_SCREEN;
                        EASUI_VEC2 SIZE;
                        int RESIZABLE;
                        void(*UPDATE_SIZE_AND_CONTEXT_SIZE)(EASUI_WINDOW* WINDOW);
                        char* TITLE;

                }
                EASUI_WINDOW__INTERNAL_DATA;

        //
        // ==============================================================


        // [SCREEN] =====================================================
        //
                typedef struct EASUI_SCREEN__INTERNAL_DATA
                {

                        char TYPE;
                        void** ELEMENT_LIST;
                        unsigned short LAST_ELEMENT_INDEX;
                        unsigned short MAX_ELEMENT_COUNT;

                }
                EASUI_SCREEN__INTERNAL_DATA;

        //
        // ==============================================================


        // [SCREEN] =====================================================
        //
                typedef struct EASUI_LABEL__INTERNAL_DATA
                {

                        char TYPE;
                        unsigned long MAX_STRING_SIZE;
                        EASUI_VEC2 POSITION, SIZE;
                        unsigned int FONT_SIZE;
                        char* TEXT;

                }
                EASUI_LABEL__INTERNAL_DATA;

        //
        // ==============================================================

//
// ====================================================================================================================



#endif
