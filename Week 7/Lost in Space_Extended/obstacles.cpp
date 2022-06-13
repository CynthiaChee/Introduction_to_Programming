#include "splashkit.h"
#include "obstacles.h"

#define SCREEN_BORDER 100
#define MAX_XY 1500
#define MIN_XY -1500

//Converts obstacle into bitmap
bitmap obstacle_bitmap(obstacle_kind obs_kind)
{
    switch (obs_kind)
    {
    case BOX:
        return bitmap_named("box");
    case POISON:
        return bitmap_named("potion");
    case BULLET:
        return bitmap_named("bullet");
    case PLUTO:
        return bitmap_named("pluto");
    case VENUS:
        return bitmap_named("venus");     
    }
}

//Creates the obstacles
obstacle_data new_obstacle(double x, double y)
{
    obstacle_data result;
    obstacle_kind kind;
    bitmap default_bitmap;

    kind=static_cast<obstacle_kind>(rnd(5));
    result.obs_kind=kind;

    default_bitmap=obstacle_bitmap(kind);
    result.obstacle_sprite=create_sprite(default_bitmap);

    sprite_set_x(result.obstacle_sprite, x);
    sprite_set_y(result.obstacle_sprite, y);

    sprite_set_dx(result.obstacle_sprite, rnd() * 4 / 2);
    sprite_set_dy(result.obstacle_sprite, rnd() * 4 / 2);

    return result;
}

//Accepts a obstacle_data value and calls draw_sprite on obstacle_sprite
void draw_obstacle(const obstacle_data &obstacle_to_draw)
{
    draw_sprite(obstacle_to_draw.obstacle_sprite);
}

//Accepts a obstacle_data value and call update_sprite on obstacle_sprite
//Moves the obstacle based on the velocity
void update_obstacle(obstacle_data &obstacle_to_update)
{
    // Apply movement based on rotation and velocity in the sprite
    update_sprite(obstacle_to_update.obstacle_sprite);

}
