#include "../../EASUI/EASUI.h"




int main()
{

        EASUI__INIT(5);


        EASUI_WINDOW WINDOW_1, WINDOW_2, WINDOW_3;
        EASUI_LABEL LABEL_1, LABEL_2, LABEL_3;


        SET_NEW_EASUI_WINDOW(&WINDOW_1, "Window 1", 8, (EASUIvec2){.x = 800, .y = 800}, TRUE);
        SET_NEW_EASUI_WINDOW(&WINDOW_2, "Window 2", 8, (EASUIvec2){.x = 800, .y = 600}, TRUE);
        SET_NEW_EASUI_WINDOW(&WINDOW_3, "Window 3", 8, (EASUIvec2){.x = 600, .y = 800}, TRUE);

        WINDOW_1.BG_COLOR = (EASUIvec3){ .x = 1.0f, .y = 0.0f, .z = 0.0f };
        WINDOW_2.BG_COLOR = (EASUIvec3){ .x = 0.0f, .y = 1.0f, .z = 0.0f };
        WINDOW_3.BG_COLOR = (EASUIvec3){ .x = 0.0f, .y = 0.0f, .z = 1.0f };

        
        SET_NEW_EASUI_LABEL(&LABEL_1, &WINDOW_2, (EASUIvec2) { 1.f, 400 }, (EASUIvec2) {200.f, 100.f}, 9, 1024);
        SET_NEW_EASUI_LABEL(&LABEL_2, &WINDOW_2, (EASUIvec2) { 600.f, 400.f }, (EASUIvec2) { 200.f, 100.f }, 9, 1024);
        SET_NEW_EASUI_LABEL(&LABEL_3, &WINDOW_2, (EASUIvec2) { 300.f, 400.f }, (EASUIvec2) { 200.f, 100.f }, 9, 1024);


        WINDOW_1.START(&WINDOW_1);
        WINDOW_2.START(&WINDOW_2);
        WINDOW_3.START(&WINDOW_3);

        EASUI__RUN();


        printf("bye bro\n");


        return 0;

}
