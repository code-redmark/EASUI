#include "INPUT.h"
#include "STRINGS.h"
#include <stdio.h>



char PRESSED_KEY(int TO_PRINT)
{

        struct termios OLD_T, NEW_T;

        char KEY;

        tcgetattr(STDIN_FILENO, &OLD_T);

        NEW_T = OLD_T;

        NEW_T.c_lflag &= ~(ICANON | ECHO);

        tcsetattr(STDIN_FILENO, TCSANOW, &NEW_T);

        KEY = (char)getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &OLD_T);


        if (TO_PRINT)
        {

                printf("%c", KEY);

        }


        return KEY;

}


void WAIT_FOR_KEY(const char TARGET_KEY)
{

        char TYPED_KEY = '\0';


        while (TYPED_KEY != TARGET_KEY)
        {

                TYPED_KEY = PRESSED_KEY(FALSE);

        }

}


void INPUT_TO_STRING(char* STRING, const char* ALLOWED_KEYS, const unsigned long MAX_LENGTH)
{

        unsigned long LENGTH = 0;



        STRING_CLEAR(STRING);


        fflush(stdout);



        while (TRUE)
        {

                char KEY = PRESSED_KEY(FALSE);



                if (KEY == '\n')
                {

                        fflush(stdout);


                        break;


                }
                else if (KEY == '\b' || KEY == 127)
                {

                        if (LENGTH == 0)
                        {

                                continue;

                        }


                        STRING_REMOVE_LAST(STRING);


                        printf("\b \b");

                        fflush(stdout);


                        LENGTH --;


                }
                else if (STRING_CONTAINS_CHAR(ALLOWED_KEYS, KEY) && (LENGTH < MAX_LENGTH))
                {

                        STRING_APPEND_CHAR(STRING, KEY);


                        printf("%c", KEY);


                        fflush(stdout);


                        LENGTH ++;

                }

        }


        printf("\n");

}
