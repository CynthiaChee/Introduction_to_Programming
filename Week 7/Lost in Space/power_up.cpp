#include "splashkit.h"
#include "power_up.h"


#define SCREEN_BORDER 100

// Range of power_up sprites
#define MAX_XY 1500
#define MIN_XY -1500

//Converts power up into bitmap
bitmap power_up_bitmap(power_up_kind kind)
{
    switch (kind)
    {
    case FUEL:
        return bitmap_named("fuel");
    case STAR:
        return bitmap_named("star");
    case COIN:
        return bitmap_named("coin");
    case POWER:
        return bitmap_named("power");
    case HEART:
        return bitmap_named("heart");     
    case TIME:
        return bitmap_named("time");
    }
}

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    power_up_bitmap(static_cast<power_up_kind>(rnd(6)));
    result.power_up_sprite = create_sprite(power_up_bitmap(FUEL));
    result.power_up_sprite = create_sprite(power_up_bitmap(STAR));
    result.power_up_sprite = create_sprite(power_up_bitmap(COIN));
    result.power_up_sprite = create_sprite(power_up_bitmap(POWER));
    result.power_up_sprite = create_sprite(power_up_bitmap(HEART));
    result.power_up_sprite = create_sprite(power_up_bitmap(TIME));
    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);
    sprite_set_dx(result.power_up_sprite, rnd() * 4 / 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 / 2);

    return result;
}

//Accepts a power_up_data value and calls draw_sprite on power_up_sprite
void draw_power_up(const power_up_data &power_up_to_draw)
{
    draw_sprite(power_up_to_draw.power_up_sprite);
}

//Accepts a power_up_data value and call update_sprite on power_up_sprite
//Moves the power_up based on the velocity
void update_power_up(power_up_data &power_up_to_update)
{
    // Apply movement based on rotation and velocity in the sprite
    update_sprite(power_up_to_update.power_up_sprite);

    // Test edge of screen boundaries to adjust the camera
    double left_edge = camera_x() + SCREEN_BORDER;
    double right_edge = left_edge + screen_width() - 2 * SCREEN_BORDER;
    double top_edge = camera_y() + SCREEN_BORDER;
    double bottom_edge = top_edge + screen_height() - 2 * SCREEN_BORDER;

    // Get the center of the power up
    point_2d sprite_center = center_point(power_up_to_update.power_up_sprite);


    // Test top/bottom of screen
    if (sprite_center.y < top_edge)
    {
        move_camera_by(0, sprite_center.y - top_edge);
    }
    else if (sprite_center.y > bottom_edge)
    {
        move_camera_by(0, sprite_center.y - bottom_edge);
    }

    // Test left/right of screen
    if (sprite_center.x < left_edge)
    {
        move_camera_by(sprite_center.x - left_edge, 0);
    }
    else if (sprite_center.x > right_edge)
    {
        move_camera_by(sprite_center.x - right_edge, 0);
    }
}

