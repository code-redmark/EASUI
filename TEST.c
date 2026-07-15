#include "EASUI/EASUI.h"
#include "EASUI/DEPENDENCIES/COMMON/STRINGS.h"



int main()
{

        EASUI_LABEL LABEL_1;

        SET_NEW_EASUI_LABEL(&LABEL_1, 0, 0, 10, 2, 12, 1024);

        STRING_APPEND(LABEL_1.TEXT, "HELLO WORLD");


        LABEL_1.TEST_FUNCTION(&LABEL_1);


        return 0;

}
