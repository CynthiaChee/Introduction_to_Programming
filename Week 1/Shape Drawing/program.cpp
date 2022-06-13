#include "splashkit.h"

//Program: shape_drawing
//Draws a number of shapes to the screen using SwinGame

int main()
{
    open_window("Shape Drawing", 800, 600);
        
    clear_screen();

    fill_rectangle(COLOR_WHITE, 10, 10, 780, 580);

    refresh_screen();
    delay(500);

    fill_circle(COLOR_RED, 50, 50, 25);
    fill_circle(COLOR_GREEN, 80, 50, 25);
    fill_circle(COLOR_BLUE, 110, 50,25);

    refresh_screen();
    delay(500);

    fill_triangle(COLOR_YELLOW, 100, 100, 150, 175, 210,115);
    refresh_screen();
    delay(2000);


    return 0;
}