#include "splashkit.h"
#include "power_up.h"

#define SCREEN_BORDER 100
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
    default:
        return bitmap_named("heart");     
    }
}

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    power_up_kind kind;
    bitmap default_bitmap;

    kind=static_cast<power_up_kind>(rnd(5));
    result.kind=kind;

    default_bitmap=power_up_bitmap(kind);
    result.power_up_sprite=create_sprite(default_bitmap);

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

}
