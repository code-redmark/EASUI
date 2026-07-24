#include "../EASUI_INTERNAL.h"




void TEST_FUNCTION(const EASUI_LABEL* LABEL);




int SET_NEW_EASUI_LABEL(EASUI_LABEL* LABEL, void* OPTIONAL__FRAMED_HOLDER, const EASUI_VEC2 POSITION, const EASUI_VEC2 SIZE, const unsigned int FONT_SIZE, const unsigned long MAX_STRING_SIZE)
{

        const char* MESSAGE = "FAILED TO ADD NEW EASUI LABEL";



        // [CHECK FOR NULL POINTERS]
        {

                if (LABEL == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "LABEL IS NULL");


                        return EASUI_ERROR;

                }

        }


        // [ALLOCATE MEMORY FOR INTERNAL DATA]
        {

                LABEL->INTERNAL_DATA = MEMORY_ARENA_ALLOC(sizeof(EASUI_LABEL__INTERNAL_DATA));


                if (LABEL->INTERNAL_DATA == NULL)
                {

                        LOG_EASUI_ERROR(MESSAGE, "FAILED TO ALLOCATE MEMORY FOR INTERNAL DATA");


                        return EASUI_ERROR;

                }

        }


        // [SET GIVEN VALUES AND FUNCTIONS]
        {

                LABEL_INTERNAL_DATA(LABEL)->TYPE = EASUI_LABEL_NUMBER;
                LABEL_INTERNAL_DATA(LABEL)->POSITION = POSITION;
                LABEL_INTERNAL_DATA(LABEL)->SIZE = SIZE;
                LABEL_INTERNAL_DATA(LABEL)->FONT_SIZE = FONT_SIZE;
                LABEL_INTERNAL_DATA(LABEL)->MAX_STRING_SIZE = MAX_STRING_SIZE;

        }


        if (OPTIONAL__FRAMED_HOLDER != NULL)
        {

                const int ADD_TO_HOLDER_STATUS = ADD__ELEMENT__TO__FRAMED_ELEMENT(OPTIONAL__FRAMED_HOLDER, LABEL);


                if (ADD_TO_HOLDER_STATUS == EASUI_ERROR)
                {

                        LOG_EASUI_ERROR(MESSAGE, "FAILED TO ADD LABEL TO OPTIONAL HOLDER");


                        return EASUI_ERROR;

                }

        }


        // [ALLOCATE MEMORY FOR THE TEXT]
        {

                LABEL_INTERNAL_DATA(LABEL)->TEXT = malloc(MAX_STRING_SIZE);


                if (LABEL_INTERNAL_DATA(LABEL)->TEXT == NULL)
                {

                        return EASUI_ERROR;

                }


                LABEL_INTERNAL_DATA(LABEL)->TEXT[0] = '\0';

        }


        return EASUI_OK;

}
