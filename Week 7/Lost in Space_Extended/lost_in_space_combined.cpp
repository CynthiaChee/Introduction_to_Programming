//Sound effects obtained from https://www.zapsplat.com/

//=======================================
// lost_in_space.h
//=======================================

#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "obstacles.h"
#include <vector>

using namespace std;
using std::vector;

struct game_data
{
    player_data player;
    vector<power_up_data> power_ups;
    vector<obstacle_data> obstacles;
};

game_data new_game();

void update_game(game_data &game);

void draw_game(const game_data &game);

void add_power_up(game_data &game);

void check_collisions(game_data &game);

void apply_power_up(game_data &game, int index);

void remove_power_up(game_data &game, int index);

void check_power_up_position (game_data &game);

void apply_obstacle_effect(game_data &game, int index);

void remove_obstacle(game_data &game, int index);

void check_obstacle_position (game_data &game);

point_2d power_mini_map_coordinate(const power_up_data &power_up);

point_2d player_mini_map_coordinate(const player_data &player);

void draw_mini_map(const game_data &game);

void draw_hud(const game_data &gmae);

#endif

//=======================================
// lost_in_space.cpp
//=======================================

#include "lost_in_space.h"
#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "obstacles.h"

#define MAX_XY 1500
#define MIN_XY -1500

//Creates a new game
game_data new_game()
{
    game_data game;
    game.player = new_player();
    return game;
}

//Adds power-ups into the game
void add_power_up(game_data &game)
{
    double x, y;
    x = rnd(MIN_XY);
    y = rnd(MAX_XY);
    power_up_data power_up;
    power_up = new_power_up(x, y);
    game.power_ups.push_back(power_up);
}

//Apply the effects of power-ups to the player
void apply_power_up(game_data &game, int index)
{
    switch(game.power_ups[index].kind)
    {
        case FUEL:
        if (game.player.fuel_pct<1)         //Increases fuel_pct only if fuel_pct <100%
        {
            game.player.fuel_pct +=0.25;
        }
        if (game.player.fuel_pct>=1)        //Max value for fuel_pct is 1
        {
            game.player.fuel_pct=1;
            game.player.score+=1;
        }
        play_sound_effect("got_it");
        break;
        case HEART:
        if (game.player.health<1)           //Increases health only if health <100%
        {
            game.player.health +=0.25;
        }
        if (game.player.health >=1)         //Max value for health is 1
        {
            game.player.health=1;
            game.player.score+=1;
        }
        play_sound_effect("got_it");
        break;
        case STAR:
        if (game.player.bonus<1)            //Increases bonus value
        {    
            game.player.bonus+=0.25;
            game.player.score+=1;
            play_sound_effect("got_it");
        }
        if(game.player.bonus>=1)            //Once bonus reaches 100%, value resets and gives extra score +100
        {
            game.player.bonus-=1;
            game.player.game_time+=250;
            game.player.score+=100;
            play_sound_effect("bonus_up");
        }
        break;
        case POWER:
        if (game.player.power<1)            //Increases power value
        {
            game.player.power+=0.25;
            game.player.score+=1;
            play_sound_effect("got_it");
        }
        if (game.player.power>=1)           //Once power reaches 100%, value resets and gives extra score,
        {                                   //fills fuel_pct and health to max
            game.player.power-=1;
            game.player.fuel_pct=1;
            game.player.health=1;
            game.player.game_time+=250;
            game.player.score+=100;
            play_sound_effect("bonus_up");
        }
        break;
        case COIN:                          //Add coin +1 with every coin collected
        game.player.coins+=1;
        if (game.player.coins >= 3)         //Level up for every 3 coins collected
        {                                   //With every level up, health, fuel, score and time bonuses are given
            game.player.level+=1;
            game.player.coins=0;
            game.player.game_time+=1000;
            game.player.health=1;
            game.player.fuel_pct=1;
            game.player.score+=1000;
            play_sound_effect("level_up");
        }
        play_sound_effect("got_it");
        break;
        case TIME:
        game.player.game_time+=250;
        play_sound_effect("got_it");
        break;
        default:
        game.player.score+=1;
        play_sound_effect("got_it");
        break;
    }
}

//Removes power-ups by vector index
void remove_power_up(game_data &game, int index)
{
    if (index >= 0 and index < game.power_ups.size())
    {
        int last_idx;
        last_idx = game.power_ups.size() - 1;
        game.power_ups[index] = game.power_ups[last_idx];
        game.power_ups.pop_back();
    }
}

//Removes power-ups that go outside of playing field
void check_power_up_position(game_data &game)
{
    for(int i = 0; i < game.power_ups.size(); i++)
    {
        double power_up_x = sprite_x(game.power_ups[i].power_up_sprite);
        double power_up_y = sprite_y(game.power_ups[i].power_up_sprite);
        
        if (power_up_x > MAX_XY || power_up_y > MAX_XY || power_up_x < MIN_XY || power_up_y < MIN_XY)
        {
            remove_power_up(game, i);
        }
    }
}

//Adds obstacles
void add_obstacle(game_data &game)
{
    double x, y;
    x = rnd(MIN_XY);
    y = rnd(MAX_XY);
    obstacle_data obstacles;
    obstacles = new_obstacle(x, y);
    game.obstacles.push_back(obstacles);
}

//Removes obstacles by index
void remove_obstacle(game_data &game, int index)
{
    if (index >= 0 and index < game.obstacles.size())
    {
        int last_idx;
        last_idx = game.obstacles.size() - 1;
        game.obstacles[index] = game.obstacles[last_idx];
        game.obstacles.pop_back();
    }
}

//Applies effects to the player when collided with an obstacle
void apply_obstacle_effect(game_data &game, int index)
{
    switch(game.obstacles[index].obs_kind)
    {
        case BOX:
            if (game.player.fuel_pct>0)             //Reduces fuel_pct if collided with BOX
            {
                game.player.fuel_pct -= 0.5;
                play_sound_effect("damage");
            }
            break;
        case POISON:
            if (game.player.health>0)               //Reduces health if collided with POISON
            {
                game.player.health -=0.25;
                play_sound_effect("damage");
            }
            break;
        case BULLET:
            if (game.player.health>0 && game.player.fuel_pct>0)     //BULLET reduces both fuel_pct and health
            {
                game.player.health -=0.5;
                game.player.fuel_pct -=0.25;
                play_sound_effect("damage");
            }
            break;
        case PLUTO:
            if (game.player.bonus>0 && game.player.power>0)         //brings BONUS and POWER to 0
            {
                game.player.bonus -=1;
                game.player.power -=1;
                play_sound_effect("damage");
            }
            break;
        case VENUS:                                                 //Reduces time by 500
            game.player.game_time -=500;
            play_sound_effect("damage");
            break;
        }
}

//Checks if obstacle is outside of playing field. If so, obstacle is removed
void check_obstacle_position(game_data &game)
{
    for(int i = 0; i < game.obstacles.size(); i++)
    {
        double obstacle_x = sprite_x(game.obstacles[i].obstacle_sprite);
        double obstacle_y = sprite_y(game.obstacles[i].obstacle_sprite);
        
        if (obstacle_x > MAX_XY || obstacle_y > MAX_XY || obstacle_x < MIN_XY || obstacle_y < MIN_XY)
        {
            remove_obstacle(game, i);
        }
    }
}

//Checks for collisions between player and power-up sprites, then removes the power-up and applies its effects to the player
void check_collisions(game_data &game)
{
    int i;
    //power_up_data power_up;
    for(i =game.power_ups.size()-1; i>=0; i--)
    {
        if(sprite_collision(game.power_ups[i].power_up_sprite, game.player.player_sprite))
        {
            apply_power_up(game, i);
            remove_power_up(game, i);
        }
    }
    for(i =game.obstacles.size()-1; i>=0; i--)
    {
        if(sprite_collision(game.obstacles[i].obstacle_sprite, game.player.player_sprite))
        {
            apply_obstacle_effect(game, i);
            remove_obstacle(game, i);
        }
    }

}

void update_game(game_data &game)
{
    int obstacle_limit;             //Maximum number of obstacles at a time
    int power_up_limit;             //Maximum number of power-ups at a time
    if (game.player.level<3)                            //If player level <3, no more than 3 obstacles and 10 power-ups
    {
        obstacle_limit = 3;
        power_up_limit = 10;
    }
    if (game.player.level>=3 && game.player.level<5)    //Between levels 3-5, up to 5 obstacles & 8 power-ups
    {
        obstacle_limit = 5;
        power_up_limit = 8;
    }
    if (game.player.level >=5 && game.player.level<10)  //Between levels 5-8, up to 8 obstacles & 8 power-ups
    {
        obstacle_limit = 8;
        power_up_limit = 8;
    }
    if (game.player.level >=10)                         //Beyond level 10, up to 10 obstacles and 5 power-ups
    {
        obstacle_limit = 10;
        power_up_limit = 5;
    }
    if (rnd()<0.05 and game.power_ups.size()<power_up_limit)
    {
        add_power_up(game);
    }
    if (rnd()<0.05 and game.obstacles.size()<obstacle_limit)
    {
        add_obstacle(game);
    }
    update_player(game.player);
    for (int i=0; i<game.power_ups.size(); i++)
    {
        check_power_up_position(game);
        update_power_up(game.power_ups[i]);
    }
    for (int i=0; i<game.obstacles.size(); i++)
    {
        check_obstacle_position(game);
        update_obstacle(game.obstacles[i]);
    }
    check_collisions(game);
}

//Returns coordinates for power-ups
point_2d power_mini_map_coordinate(const power_up_data &power_up)
{
    double power_up_x, power_up_y, mini_map_x, mini_map_y;

    power_up_x = sprite_x(power_up.power_up_sprite);
    power_up_y = sprite_y(power_up.power_up_sprite);

    mini_map_x = (power_up_x - MIN_XY)/ 3000 *100 + 15;
    mini_map_y = (power_up_y - MIN_XY)/ 3000 *100 + 675;

    return point_at(mini_map_x, mini_map_y);

}

//Returns coordinates for obstacles
point_2d obstacle_mini_map_coordinate(const obstacle_data &obstacle)
{
    double obstacle_x, obstacle_y, mini_map_x, mini_map_y;

    obstacle_x = sprite_x(obstacle.obstacle_sprite);
    obstacle_y = sprite_y(obstacle.obstacle_sprite);

    mini_map_x = (obstacle_x - MIN_XY)/ 3000 *100 + 15;
    mini_map_y = (obstacle_y - MIN_XY)/ 3000 *100 + 675;

    return point_at(mini_map_x, mini_map_y);

}

//Returns coordinates for player
point_2d player_mini_map_coordinate(const player_data &player)
{
    double player_x, player_y, mini_map_x, mini_map_y;

    player_x = sprite_x(player.player_sprite);
    player_y = sprite_y(player.player_sprite);
    
    mini_map_x = (player_x - MIN_XY)/ 3000 *100 + 25;
    mini_map_y = (player_y - MIN_XY)/ 3000 *100 + 675;

    return point_at(mini_map_x, mini_map_y);
}

//Draw the mini-map using coordinates for power-ups and player
//Player appears blue, power-ups appear green and obstacles appear red in mini-map
void draw_mini_map(const game_data &game)
{
    for (int i = 0; i < game.power_ups.size(); i++)
    {
        draw_pixel(rgba_color(0, 255, 0, 255), power_mini_map_coordinate(game.power_ups[i]), option_to_screen());
    }

    for (int i = 0; i < game.obstacles.size(); i++)
    {
        draw_pixel(rgba_color(255, 0, 0, 255), obstacle_mini_map_coordinate(game.obstacles[i]), option_to_screen());
    }

    draw_pixel(rgba_color(0, 0, 255, 255), player_mini_map_coordinate(game.player), option_to_screen());
}

//Draw the heads-up display (HUD)
void draw_hud (const game_data &game)
{
    //HUD area
    fill_rectangle(COLOR_BLUE, 0, 650, 800, 150, option_to_screen());
    //minimap area
    fill_rectangle(COLOR_BLACK, 15, 675, 100, 100, option_to_screen());
    draw_mini_map(game);
    //fuel bar
    draw_bitmap("empty_bar_transparent", 130, 700, option_to_screen());
    //fuel information
    draw_bitmap("full", 130, 700, option_part_bmp(0, 0, (bitmap_width("full") * game.player.fuel_pct), bitmap_height("full"), option_to_screen()));
    //health bar
    draw_bitmap("empty_bar_transparent", 130, 750, option_to_screen());
    //health information
    draw_bitmap("red_bar", 130, 750, option_part_bmp(0, 0, (bitmap_width("red_bar") * game.player.health), bitmap_height("full"), option_to_screen()));
    //bonus bar
    draw_bitmap("empty_bar_transparent", 475, 700, option_to_screen());
    //bonus information
    draw_bitmap("blue_bar_bubbles", 475, 700, option_part_bmp(0, 0, (bitmap_width("blue_bar_bubbles") * game.player.power), bitmap_height("full"), option_to_screen()));
    //bonus bar
    draw_bitmap("empty_bar_transparent", 475, 750, option_to_screen());
    //bonus information
    draw_bitmap("purple_bar", 475, 750, option_part_bmp(0, 0, (bitmap_width("purple_bar") * game.player.bonus), bitmap_height("full"), option_to_screen()));

    //text
    draw_text("FUEL: ", COLOR_WHITE, 130, 695, option_to_screen());
    draw_text("HEALTH: ", COLOR_WHITE, 130, 745, option_to_screen());
    draw_text("POWER: ", COLOR_WHITE, 500, 695, option_to_screen());
    draw_text("BONUS: ", COLOR_WHITE, 500, 745, option_to_screen());

    //score, coins and location information
    draw_text("SCORE: " + to_string(game.player.score), COLOR_WHITE, 130, 675, option_to_screen());
    draw_text("COINS: " + to_string(game.player.coins), COLOR_WHITE, 325, 675, option_to_screen());
    draw_text("LOCATION: " + point_to_string(center_point(game.player.player_sprite)), COLOR_WHITE, 485, 675, option_to_screen());
    draw_text("TIME REMAINING: " + to_string(game.player.game_time), COLOR_WHITE, 15, 660, option_to_screen());
    draw_text("LEVEL: " + to_string(game.player.level), COLOR_WHITE, 700, 660, option_to_screen());
}

//Draw the game
void draw_game(const game_data &game)
{
    clear_screen(COLOR_BLACK);
    for (int i=0; i<game.power_ups.size();i++)
    {
        draw_power_up(game.power_ups[i]);
    }
    for (int i=0; i<game.obstacles.size();i++)
    {
        draw_obstacle(game.obstacles[i]);
    }
    draw_player(game.player);
    draw_hud(game);
    refresh_screen(60);
}

//=======================================
// player.h
//=======================================

#ifndef LOST_IN_SPACE_PLAYER
#define LOST_IN_SPACE_PLAYER

#include "splashkit.h"
#include <vector>

using namespace std;

#define PLAYER_SPEED 1.5
#define PLAYER_ROTATE_SPEED 3
#define SCREEN_BORDER 100

/**
 * Different options for the kind of ship.
 * Adjusts the image used.
 */
enum ship_kind
{
    AQUARII,
    GLIESE,
    PEGASI
};

/**
 * The player data keeps track of all of the information related to the player.
 * 
 * @field   player_sprite   The player's sprite - used to track position and movement
 * @field   score           The current score for the player
 * @field   kind            Current kind of player ship
 */
struct player_data
{
    sprite      player_sprite;
    int         score;
    ship_kind   kind;
    double      fuel_pct;
    double      health;
    double      bonus;
    double      power;
    int         coins;
    int         game_time;
    int         level;
}; 

/**
 * Creates a new player in the centre of the screen with the default ship.
 * 
 * @returns     The new player data
 */
player_data new_player();

/**
 * Draws the player to the screen. 
 * 
 * @param player_to_draw    The player to draw to the screen
 */
void draw_player(const player_data &player_to_draw);

/**
 * Actions a step update of the player - moving them and adjusting the camera.
 * 
 * @param player_to_update      The player being updated
 */
void update_player(player_data &player_to_update);

/**
 * Read user input and update the player based on this interaction.
 * 
 * @param player    The player to update
 */
void handle_input(player_data &player);

#endif 

//=======================================
// player.cpp
//=======================================

#include "player.h"
#include "splashkit.h"

#define MAX_XY 1500
#define MIN_XY -1500
/**
 * The ship bitmap function converts a ship kind into a 
 * bitmap that can be used.
 * 
 * Not exposed by the header.
 * 
 * @param kind  The kind of ship you want the bitmap of
 * @return      The bitmap matching this ship kind
 */
bitmap ship_bitmap(ship_kind kind)
{
    switch (kind)
    {
    case AQUARII:
        return bitmap_named("aquarii");
    case GLIESE:
        return bitmap_named("gliese");
    default:
        return bitmap_named("pegasi");
    }
}

player_data new_player()
{
    player_data result;
    bitmap default_bitmap = ship_bitmap(AQUARII);

    // Create the sprite with 3 layers - we can turn on and off based
    // on the ship kind selected
    result.player_sprite = create_sprite(default_bitmap);

    sprite_add_layer(result.player_sprite, ship_bitmap(GLIESE), "GLIESE");
    sprite_add_layer(result.player_sprite, ship_bitmap(PEGASI), "PEGASI");

    // Default to layer 0 = Aquarii so hide others
    sprite_hide_layer(result.player_sprite, 1);
    sprite_hide_layer(result.player_sprite, 2);

    result.kind = AQUARII;

    // Position in the centre of the initial screen
    sprite_set_x(result.player_sprite, (screen_width() - sprite_width(result.player_sprite)) / 2);
    sprite_set_y(result.player_sprite, (screen_height() - sprite_height(result.player_sprite)) / 2);

    //Initial values
    result.fuel_pct = 0.75;
    result.health = 0.5;
    result.bonus = 0;
    result.score = 0;
    result.power = 0;
    result.coins = 0;
    result.game_time = 3000;
    result.level = 1;
    return result;
}

void draw_player(const player_data &player_to_draw)
{
    draw_sprite(player_to_draw.player_sprite);
}

void update_player(player_data &player_to_update)
{
    // Apply movement based on rotation and velocity in the sprite
    update_sprite(player_to_update.player_sprite);

    // Test edge of screen boundaries to adjust the camera
    double left_edge = camera_x() + SCREEN_BORDER;
    double right_edge = left_edge + screen_width() - 2 * SCREEN_BORDER;
    double top_edge = camera_y() + SCREEN_BORDER;
    double bottom_edge = top_edge + 650 - 2 * SCREEN_BORDER;

    // Get the center of the player
    point_2d sprite_center = center_point(player_to_update.player_sprite);

    // Test if the player is outside the area and move the camera
    // the player will appear to stay still and everything else
    // will appear to move :)

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

    //Fuel reduces with time
    if (player_to_update.fuel_pct > 0)
    {
        player_to_update.fuel_pct -= 0.0002;
    }

    //Time countdown
    if (player_to_update.game_time > 0)
    {
        player_to_update.game_time -= 1;
    }
}
/**
 * Switch the ship kind - will adjust which layer is hidden/shown
 */
void player_switch_to_ship(player_data &player, ship_kind target)
{
    // only do this if there is a change
    if (player.kind != target)
    {
        // show then hide layers
        sprite_show_layer(player.player_sprite, static_cast<int>(target));
        sprite_hide_layer(player.player_sprite, static_cast<int>(player.kind));

        // remember what is currently shown
        player.kind = target;
    }
}

void handle_input(player_data &player)
{
    // Allow the player to switch ships
    if (key_typed(NUM_1_KEY))
        player_switch_to_ship(player, AQUARII);
    if (key_typed(NUM_2_KEY))
        player_switch_to_ship(player, GLIESE);
    if (key_typed(NUM_3_KEY))
        player_switch_to_ship(player, PEGASI);

    // Handle movement - rotating left/right and moving forward/back
    float dx = sprite_dx(player.player_sprite);
    float rotation = sprite_rotation(player.player_sprite);

    // Allow rotation with left/right keys
    if (key_down(LEFT_KEY))
        sprite_set_rotation(player.player_sprite, rotation - PLAYER_ROTATE_SPEED);
    if (key_down(RIGHT_KEY))
        sprite_set_rotation(player.player_sprite, rotation + PLAYER_ROTATE_SPEED);

    // Increase speed with up/down keys - typed to give step increases
    if (key_typed(DOWN_KEY))
        sprite_set_dx(player.player_sprite, dx - PLAYER_SPEED);
    if (key_typed(UP_KEY))
        sprite_set_dx(player.player_sprite, dx + PLAYER_SPEED);
}

//=======================================
// power_up.h
//=======================================

#ifndef LOST_IN_SPACE_POWER_UP
#define LOST_IN_SPACE_POWER_UP

#include "splashkit.h"
#include <vector>
#include "player.h"

using namespace std;
using std::vector;

//Enum representing the different kinds of power-ups
enum power_up_kind
{
    FUEL,
    STAR,
    COIN,
    POWER,
    HEART,
    TIME
};

//Struct for power-ups
struct power_up_data
{
    sprite power_up_sprite;
    power_up_kind kind;
};

//Creates a new power up
power_up_data new_power_up(double x, double y);

void draw_power_up(const power_up_data &power_up_to_draw);

void update_power_up(power_up_data &power_up_to_update);


#endif

//=======================================
// power_up.cpp
//=======================================

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
    case TIME:
        return bitmap_named("time");
    default:
        return bitmap_named("heart");     
    }
}

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    power_up_kind kind;
    bitmap default_bitmap;

    kind=static_cast<power_up_kind>(rnd(6));
    result.kind=kind;

    default_bitmap=power_up_bitmap(kind);
    result.power_up_sprite=create_sprite(default_bitmap);

    //result.power_up_sprite = create_sprite(power_up_bitmap(TIME));

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

//=======================================
// obstacles.h
//=======================================

#ifndef LOST_IN_SPACE_OBSTACLES
#define LOST_IN_SPACE_OBSTACLES

#include "splashkit.h"
#include <vector>

using namespace std;
using std::vector;

//Enum representing the different kinds of obstacles
enum obstacle_kind
{
    BOX,
    POISON,
    BULLET,
    PLUTO,
    VENUS
};

//Struct for obstacles
struct obstacle_data
{
    sprite obstacle_sprite;
    obstacle_kind obs_kind;
};

//Creates a obstacle
obstacle_data new_obstacle(double x, double y);

void draw_obstacle(const obstacle_data &obstacle_to_draw);

void update_obstacle(obstacle_data &obstacle_to_update);


#endif

//=======================================
// obstacles.cpp
//=======================================

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

//=======================================
// program.cpp
//=======================================

#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"
#include "obstacles.h"

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 800, 800);
    load_resources();
    load_music("game_music", "game_music.ogg");
    open_audio();
    play_music("game_music");
    game_data game;
    game = new_game();

    while ( not quit_requested() )
    {

        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        // Perform movement and update the camera
        update_game(game);
        draw_game(game);

        //Starts a new game if R key is pressed
        if (key_typed(R_KEY))
        {
            game = new_game();
            open_audio();
            play_music("game_music");
        }
        if (key_typed(L_KEY))
        {
            game.player.level +=1;
            play_sound_effect("level_up");
        }

        //If player fuel/health/time runs out, game over
        if(game.player.fuel_pct <=0 || game.player.health <= 0 || game.player.game_time <= 0)
        {
            draw_text("GAME OVER", COLOR_WHITE, 350, 300, option_to_screen());
            draw_text("FINAL SCORE: " + std::to_string(game.player.score), COLOR_WHITE, 350, 350, option_to_screen());
            draw_text("YOU REACHED LEVEL " + std::to_string(game.player.level), COLOR_WHITE, 350, 400, option_to_screen());
            draw_text("PRESS R TO RESTART", COLOR_WHITE, 350, 450, option_to_screen());
            stop_music();
            close_audio();
            refresh_screen(60);
        }    

    }
    return 0;
}