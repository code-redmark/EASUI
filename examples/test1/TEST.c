#include "../../EASUI/EASUI.h"




int main()
{

        EASUI_WINDOW WINDOW_1, WINDOW_2;



        EASUI_INIT(3);


        // [RUN PART]
        {

                SET_NEW_EASUI_WINDOW(&WINDOW_1, "WINDOW 1", 16, 1080, 720);
                SET_NEW_EASUI_WINDOW(&WINDOW_2, "WINDOW ", 16, 800, 600);


                WINDOW_1.START(&WINDOW_1);
                WINDOW_2.START(&WINDOW_2);

        }


        EASUI_WAIT_AND_END();



        return 0;

}
