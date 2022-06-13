#include "splashkit.h"

#define MAX_HEIGHT 400
#define MAX_WIDTH 200

//Draws a water tank, at a given x, y location in a set width and height and at a certain percent full

void draw_water_tank(float x, float y, int width, int height, float pct_full)
{
    float ellipse_height;       //height of ellipses for top/bottom
    float body_height, body_y;  //height of the core of the cylinder
    float bottom_ellipse_y, top_ellipse_y; //the y position of the ellipses
    float water_height, water_y; //the top (y) of the water, and its height

    ellipse_height = height * 0.1; //10% of its height
    body_height = height - ellipse_height;
    body_y = y + ellipse_height / 2;
    bottom_ellipse_y = (y + height) - ellipse_height;

    water_height = pct_full * body_height;
    water_y = body_y + (body_height = water_height);
    top_ellipse_y = water_y - ellipse_height / 2;

    //Water...
    //Bottom ellipse
    fill_ellipse(COLOR_BLUE, x, bottom_ellipse_y, width, ellipse_height);
    draw_ellipse(COLOR_BLACK, x, bottom_ellipse_y, width, ellipse_height);
    //Body - center of cylinder
    fill_rectangle(COLOR_BLUE, x, water_y, width, water_height);
    //Top ellipse
    fill_ellipse(COLOR_BLUE, x, top_ellipse_y, width, ellipse_height);
    draw_ellipse(COLOR_BLACK, x, top_ellipse_y, width, ellipse_height);

    //Frame
    draw_ellipse(COLOR_BLACK, x, y, width, ellipse_height);
    draw_line(COLOR_BLACK, x, y + ellipse_height / 2, x, bottom_ellipse_y + ellipse_height / 2);
    draw_line(COLOR_BLACK, x + width, y + ellipse_height / 2, x + width, bottom_ellipse_y + ellipse_height / 2);
}

//Coordinates the drawing of a number of water tanks
int main(int argc, char* argv[])
{
    open_audio();
    open_window("WaterTanks", 800, 600);
    clear_screen(COLOR_WHITE);
    draw_water_tank(10, 50, 100, 200, 0.75);
    draw_water_tank(150, 50, 100, 300, 0.0);
    draw_water_tank(300, 50, 70, 100, 0.25);
    draw_water_tank(450, 50, rnd() * MAX_HEIGHT, rnd() * MAX_WIDTH, 0.25);
    refresh_screen();

    delay(10000);

    close_audio();
    return 0;
}