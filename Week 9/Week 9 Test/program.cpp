#include "splashkit.h"

enum segment
{
    OFF,
    ON
};

enum light
{
    WHITE = 1,
    BLUE,
    YELLOW,
    GREEN,
    RED,
};

int main()
{
    light color;
    segment indicator;

    int temp_prev = 37;
    int temp_curr = 39;
    indicator = OFF;

    if ((temp_curr > temp_prev and temp_curr >39) or !indicator)
    {
        color = GREEN;
        write(color);
        color = RED;
        write(color);
        color = YELLOW;
        write(color);
        color = BLUE;
        write(color);
    }
    else
    {
        color = WHITE;
        write(color);
        color = WHITE;
        write(color);       
        color = RED;
        write(color); 
        color = RED;
        write(color);        
    }

    return 0;
}