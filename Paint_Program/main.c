#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/**
    Name        : Paint in C
    Author      : Mustapha Alaouy
    Email       : alaouym@gmail.com
    Description : basic drawing program (Paint) using only the console
                  and the DOS colors
*/

int main()
{
    /*
    system is function that let user write terminal order ,
    here we change the terminal color to Creates a black background with light bright green text
    */
    system("color 0a");     //
   /*
   Change the output video settings for the directory structure in DOS to 80 columns by 50 lines.
    If the lines or cols values are invalid, you will receive the error "Invalid parameter - x,"
   */
    system("mode con cols=160 lines=57");
    //welcomemsg();       // loading
    drawframe();        // draws the menu
    while(1)
    {
        paint();
    }
    return 0;
}
