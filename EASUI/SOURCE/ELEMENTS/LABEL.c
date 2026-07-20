#include "../../EASUI.h"




void TEST_FUNCTION(const EASUI_LABEL* LABEL);




int SET_NEW_EASUI_LABEL(EASUI_LABEL* LABEL, void* OPTIONAL__FRAMED_HOLDER, const EASUIvec2 POSITION, const EASUIvec2 SIZE, const unsigned int FONT_SIZE, const unsigned long MAX_STRING_SIZE)
{

        // [SET GIVEN VALUES AND FUNCTIONS]
        {

                LABEL->TYPE = EASUI_LABEL_NUMBER;
                LABEL->POSITION = POSITION;
                LABEL->SIZE = SIZE;
                LABEL->FONT_SIZE = FONT_SIZE;
                LABEL->MAX_STRING_SIZE = MAX_STRING_SIZE;
                LABEL->TEST_FUNCTION = TEST_FUNCTION;

        }


        if (LABEL == NULL)
        {

                LOG_EASUI_ERROR("FAILED TO ADD NEW EASUI LABEL : LABEL IS NULL");


                return EASUI_ERROR;

        }


        if (OPTIONAL__FRAMED_HOLDER != NULL)
        {

                ADD__ELEMENT__TO__FRAMED_ELEMENT(OPTIONAL__FRAMED_HOLDER, LABEL);

        }


        // [ALLOCATE MEMORY FOR THE TEXT]
        {

                LABEL->TEXT = malloc(MAX_STRING_SIZE);


                if (LABEL->TEXT == NULL)
                {

                        return EASUI_ERROR;

                }


                LABEL->TEXT[0] = '\0';

        }


        return EASUI_OK;

}


void TEST_FUNCTION(const EASUI_LABEL* LABEL)
{

        printf("%s\n", LABEL->TEXT);

}
