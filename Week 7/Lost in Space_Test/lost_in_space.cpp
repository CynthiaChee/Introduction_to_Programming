#include "lost_in_space.h"
#include "splashkit.h"
#include "player.h"
#include "power_up.h"

#define MAX_XY 1500
#define MIN_XY -1500

//Creates a new game
game_data new_game()
{
    game_data result;
    result.player = new_player();
    return result;
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
        if (game.player.power>=1)           //Once power reaches 100%, value resets and gives coins, score,
        {                                   //fills fuel_pct and health to max
            game.player.power-=1;
            game.player.fuel_pct=1;
            game.player.health=1;
            game.player.coins+=5;
            game.player.score+=100;
            play_sound_effect("bonus_up");
        }
        break;
        case COIN:                          //Add coin +1 with every coin collected
        game.player.coins+=1;
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

}

void update_game(game_data &game)
{
    if (rnd()<0.05 and game.power_ups.size()<10)
    {
        add_power_up(game);
    }
    update_player(game.player);
    for (int i=0; i<game.power_ups.size(); i++)
    {
        check_power_up_position(game);
        update_power_up(game.power_ups[i]);
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
//Player is shown as a blue pixel while power-ups appear as red pixels
void draw_mini_map(const game_data &game)
{
    for (int i = 0; i < game.power_ups.size(); i++)
    {
        draw_pixel(rgba_color(255, 0, 0, 255), power_mini_map_coordinate(game.power_ups[i]), option_to_screen());
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
}

//Draw the game
void draw_game(const game_data &game)
{
    clear_screen(COLOR_BLACK);
    for (int i=0; i<game.power_ups.size();i++)
    {
        draw_power_up(game.power_ups[i]);
    }

    draw_player(game.player);
    draw_hud(game);
    refresh_screen(60);
}
