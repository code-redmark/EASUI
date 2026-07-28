#include "../../EASUI/EASUI.h"




int main()
{

        EASUI__INIT(5);


        EASUI_WINDOW WINDOW_1, WINDOW_2, WINDOW_3;
        EASUI_LABEL LABEL_1, LABEL_2, LABEL_3;


        SET_NEW_EASUI_WINDOW(&WINDOW_1, "Window 1", 8, (EASUIvec2){800, 800}, TRUE);
        SET_NEW_EASUI_WINDOW(&WINDOW_2, "Window 2", 8, (EASUIvec2){800, 600}, TRUE);
        SET_NEW_EASUI_WINDOW(&WINDOW_3, "Window 3", 8, (EASUIvec2){600, 800}, TRUE);

        WINDOW_1.BG_COLOR = (EASUIColor){ 1.0f, 0.0f, 0.0f, 1.0 };
        WINDOW_2.BG_COLOR = (EASUIColor){ 0.0f, 1.0f, 0.0f, 1.0 };
        WINDOW_3.BG_COLOR = (EASUIColor){ 0.0f, 0.0f, 1.0f, 1.0 };

        
        SET_NEW_EASUI_LABEL(&LABEL_1, &WINDOW_2, 
            (EASUIvec2) { 0.f, 400 }, 
            (EASUIvec2) {200.f, 100.f},
            9, 1024
        );
        LABEL_1.TEXT_COLOR = (EASUIColor){ 245, 84, 66, 1.0 };

        SET_NEW_EASUI_LABEL(&LABEL_2, &WINDOW_2, 
            (EASUIvec2) { 600.f, 400.f }, 
            (EASUIvec2) { 200.f, 100.f },
            9, 1024
        );
        LABEL_2.TEXT_COLOR = (EASUIColor){ 66, 129, 245, 1.0 };

        SET_NEW_EASUI_LABEL(&LABEL_3, &WINDOW_2, 
            (EASUIvec2) { 300.f, 400.f }, 
            (EASUIvec2) { 200.f, 100.f }, 
            9, 1024
        );
        LABEL_3.TEXT_COLOR = (EASUIColor){ 18, 171, 15, 1.0 };


        WINDOW_1.START(&WINDOW_1);
        WINDOW_2.START(&WINDOW_2);
        WINDOW_3.START(&WINDOW_3);

        EASUI__RUN();


        printf("bye bro\n");


        return 0;

}
