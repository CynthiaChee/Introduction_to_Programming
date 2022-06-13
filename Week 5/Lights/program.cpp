#include "splashkit.h"

#define SPEED 5

enum light_size
{
    SMALL_LIGHT,
    MEDIUM_LIGHT,
    LARGE_LIGHT
};

struct light_data
{
    double      x;
    double      y;
    bool        is_on;
    light_size  size;
};

void load_resources()
{
    load_bitmap("large-on", "large-on-light.png");
    load_bitmap("large-off", "large-off-light.png");
    load_bitmap("medium-on", "medium-on-light.png");
    load_bitmap("medium-off", "medium-off-light.png");
    load_bitmap("small-on", "small-on-light.png");
    load_bitmap("small-off", "small-off-light.png");
}

light_data new_light(double x, double y, bool is_on)
{
    light_data result;

    result.x = x;
    result.y = y;
    result.is_on = is_on;
    result.size = SMALL_LIGHT;

    return result;
}

bitmap light_bitmap(const light_data& light)
{
    string bitmap_name;

    switch ( light.size )
    {
        case MEDIUM_LIGHT:
            bitmap_name = "medium";
            break;
        case LARGE_LIGHT:
            bitmap_name = "large";
            break;
        case SMALL_LIGHT:
        default:
            bitmap_name = "small";
    }

    if ( light.is_on )
    {
        bitmap_name += "-on";
    }
    else
    {
        bitmap_name += "-off";
    }

    return bitmap_named(bitmap_name);
}

void draw_light(const light_data &light)
{
    draw_bitmap(light_bitmap(light), light.x, light.y);
}

void handle_input(light_data &light)
{
    if ( key_down(RIGHT_KEY) )  light.x = light.x + SPEED;
    if ( key_down(LEFT_KEY) )   light.x = light.x - SPEED;
    if ( key_down(DOWN_KEY) )   light.y = light.y + SPEED;
    if ( key_down(UP_KEY) )     light.y = light.y - SPEED;

    if ( key_typed(NUM_1_KEY) ) light.size = SMALL_LIGHT;
    if ( key_typed(NUM_2_KEY) ) light.size = MEDIUM_LIGHT;
    if ( key_typed(NUM_3_KEY) ) light.size = LARGE_LIGHT;

    if ( key_typed(SPACE_KEY) ) light.is_on = ! light.is_on;
}

int main()
{
    light_data my_light;

    my_light = new_light(50, 50, true);

    open_window("Lights", 800, 600);

    load_resources();

    do
    {
        process_events();

        handle_input(my_light);

        if ( my_light.is_on ) clear_screen(COLOR_WHITE);
        else clear_screen(COLOR_BLACK);

        draw_light(my_light);
        refresh_screen(60);
    } while ( ! quit_requested() );

    return 0;
}