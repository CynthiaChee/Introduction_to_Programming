#include "splashkit.h"
#include <stdbool.h>
#include <stdio.h>

//==================
// DEFINE CONSTANTS
//==================

#define WHEEL_SIZE 10
#define WHEEL_GAP 10
#define SEAT_GAP 5
#define MAX_ACCELERATION 10
#define RACE_DURATION 30
#define X_SCALE_FACTOR 0.15

//===========
// FUNCTIONS
//===========

//Calculate the distance travelled given acceleration and time
// distance = ut + ((at^2) / 2)
// s = distance, u = starting speed, t = time, a = acceleration

float distance_travelled(float initial_speed, float acceleration, float time)
{
    return (initial_speed * time) + ((acceleration * time * time) / 2);
}

//Calculate the x position of a bike accelerating at the given acceleration for the duration of the race

float bike_x_for_accel(float acceleration)
{
    float distance;
    distance = distance_travelled(0, acceleration, RACE_DURATION);
    return distance * X_SCALE_FACTOR;
}

//Come up with a random acceleration value for a bike between 0 and MAX_ACCELERATION

float random_accel()
{
    return rnd() * MAX_ACCELERATION;
}


//============ 
// PROCEDURES
//============

//Draw the bike to the screen in the given colour
void draw_bike(color bike_color, float x, float y)
{
    float left_wheel_x, right_wheel_x, wheel_y;
    float seat_x, seat_y;

    left_wheel_x = x + WHEEL_SIZE;
    right_wheel_x = left_wheel_x + WHEEL_SIZE * 2 + WHEEL_GAP;

    wheel_y = y + WHEEL_SIZE + SEAT_GAP;

    seat_x = (right_wheel_x - left_wheel_x) / 2.0f + left_wheel_x;
    seat_y = y + SEAT_GAP;

    draw_circle(bike_color, left_wheel_x, wheel_y, WHEEL_SIZE);
    draw_circle(bike_color, right_wheel_x, wheel_y, WHEEL_SIZE);
    draw_triangle(bike_color, left_wheel_x, wheel_y, right_wheel_x, wheel_y, seat_x, seat_y);
    draw_line(bike_color, right_wheel_x, wheel_y, right_wheel_x, y);
}

//====================
// MAIN - ENTRY POINT
//====================

//Run the bike race...

int main()
{
    open_audio();
    open_window("Bicycle Race...", 800, 600);
    clear_screen(COLOR_WHITE);

    draw_bike(COLOR_RED, bike_x_for_accel(random_accel()), 10);
    draw_bike(COLOR_GREEN, bike_x_for_accel(random_accel()), 60);
    draw_bike(COLOR_BLUE, bike_x_for_accel(random_accel()), 110);
    draw_bike(rgb_color(127, 127, 0), bike_x_for_accel(random_accel()), 160);
    draw_bike(rgb_color(127, 127, 127), bike_x_for_accel(random_accel()), 210);
    draw_bike(rgb_color(0, 0, 0), bike_x_for_accel(random_accel()), 260);
    draw_bike(random_color(), bike_x_for_accel(random_accel()), 310);
    
    refresh_screen();
    delay(7500);
    close_audio();

    return 0;
}