#define EASUI
#ifdef EASUI


#include "DEPENDENCIES/GLAD/include/glad/glad.h"
#include "DEPENDENCIES/COMMON/STRINGS.h"
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>


#define EASUI_NONE 0
#define EASUI_ERROR 0
#define EASUI_OK 1


typedef struct EASUI_BASE_ELEMENT EASUI_BASE_ELEMENT;
typedef struct EASUI_SCREEN EASUI_SCREEN;
typedef struct EASUI_WINDOW EASUI_WINDOW;




typedef struct EASUI_VEC3
{

        float X;
        float Y;
        float Z;

}
EASUI_VEC3;


typedef struct EASUI_VEC2
{

        float X;
        float Y;

}
EASUI_VEC2;


// ================================================== [FUNCTIONS] =================================================
//

int EASUI__INIT(const unsigned short MAX_WINDOW_COUNT);


int EASUI__RUN();

//
// ================================================================================================================



// ================================================= [BASE ELEMENT] =============================================
//

        struct EASUI_BASE_ELEMENT
        {

                void* INTERNAL_DATA;

        };

//
// =============================================================================================================


// ================================================== [SCREEN] =================================================
//

        struct EASUI_SCREEN
        {

                void* INTERNAL_DATA;
                int (*ADD_ELEMENT)(EASUI_SCREEN* SCREEN, void* ELEMENT);

        };


        int SET_NEW_EASUI_SCREEN(EASUI_SCREEN* SCREEN, const unsigned short MAX_ELEMENT_COUNT);

//
// =============================================================================================================


// ================================================== [WINDOW] =================================================

        struct EASUI_WINDOW
        {

                void* INTERNAL_DATA;
                int (*ADD_ELEMENT)(EASUI_WINDOW* WINDOW, void* ELEMENT);
                int (*START)(EASUI_WINDOW* WINDOW);
                EASUI_VEC3 BG_COLOR;
        };


        int SET_NEW_EASUI_WINDOW(EASUI_WINDOW* WINDOW, const char* TITLE, const unsigned short MAX_ELEMENT_COUNT, const EASUI_VEC2 SIZE, const int RESIZABLE);

// =============================================================================================================



// =================================================== [LABEL] =================================================

        typedef struct EASUI_LABEL EASUI_LABEL;


        struct EASUI_LABEL
        {

                void* INTERNAL_DATA;

        };


        int SET_NEW_EASUI_LABEL(EASUI_LABEL* LABEL, void* OPTIONAL__FRAMED_HOLDER, const EASUI_VEC2 POSITION, const EASUI_VEC2 SIZE, const unsigned int FONT_SIZE, const unsigned long MAX_STRING_SIZE);

// ===============================================================================================================


#endif
