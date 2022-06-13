#include "splashkit.h"

#define MAX_RADIUS 200
#define MIN_RADIUS 10

int main()
{
    double x;
    double y;
    double radius;
    color circle_color = COLOR_GREEN;

    open_window("Shape Shifter by Cynthia Chee", 800, 600);
    
    x = screen_width() / 2;
    y = screen_height() / 2;
    radius = 50;

    while(not quit_requested())
    {
        process_events();

        //Randomise circle colour
        if (key_typed(C_KEY)) 
        {
            circle_color = random_color();
        }

        //Moves circle to the right or left by 3 pixels
        if (key_down(RIGHT_KEY))
        {
            x = x + 3;
        }

        if (key_down(LEFT_KEY))
        {
            x = x - 3;
        }

        //Prevents circle from going offscreen
        if (x + radius > screen_width())
        {
            x = screen_width() - radius;
        }

        if (x - radius < 0)
        {
            x = radius;
        }

        //Moves circle up and down by 3 pixels
        if (key_down(UP_KEY))
        {
            y = y - 3;
        }

        if (key_down(DOWN_KEY))
        {
            y = y + 3;
        }

        //Prevents circle from going offscreen
        if (y + radius > screen_height())
        {
            y = screen_height() - radius;
        }

        if (y - radius < 0)
        {
            y = radius;
        }

        //Increases or decreases the circle radius by 5 pixels
        if (key_down(EQUALS_KEY))
        {
            radius = radius + 5;
        }

        if (key_down(MINUS_KEY))
        {
            radius = radius - 5;
        }

        //Keeps maximum radius at 200 and minimum radius at 10
        if (radius > MAX_RADIUS)
        {
            radius = MAX_RADIUS;
        }

        if (radius < MIN_RADIUS)
        {
            radius = MIN_RADIUS;
        }

        //Resets the circle to the center of the screen when R is pressed
        if (key_down(R_KEY))
        {
            x = screen_width() / 2;
            y = screen_height() / 2;
        }

        clear_screen(COLOR_WHITE);
        fill_circle(circle_color, x, y, radius);

        refresh_screen(60);

    }
    return 0;
}