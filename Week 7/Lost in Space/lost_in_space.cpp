#include "lost_in_space.h"
#include "splashkit.h"
#include "player.h"

#define MAX_XY 1500
#define MIN_XY -1500

game_data new_game()
{
    game_data game;
    game.player=new_player();
    return game;
}

//add a power up
void add_power_up(game_data &game)
{
    double x, y;
    x=2*rnd()* MAX_XY+MIN_XY;
    y=2*rnd()* MAX_XY+MIN_XY;
    power_up_data power_up;
    power_up=new_power_up(x,y);
    game.power_ups.push_back(power_up);
}

//remove a power up
void remove_power_up (game_data &game, int size)
{
     //////////
}

//apply a power up to player
void apply_power_up(game_data &game, int index)
{
    ////
}

//check collisions
void check_collisions(game_data &game)
{
    ////
}

//update game
void update_game(game_data &game)
{
    ////
}

void draw_game(game_data &game)
{
        clear_screen(COLOR_BLACK);

        fill_rectangle(COLOR_BLUE, 0, 650, 800, 150, option_to_screen());
        fill_rectangle(COLOR_BLACK, 25, 675, 100, 100, option_to_screen());
        draw_bitmap("empty_bar_transparent", 200, 700, option_to_screen());
        draw_bitmap("full", 200, 700, option_part_bmp(0, 0, (bitmap_width("full") * 0.75), bitmap_height("full"), option_to_screen()));
        draw_bitmap("empty_bar_transparent", 200, 740, option_to_screen());
        draw_bitmap("orange_bar_lines", 200, 740, option_part_bmp(0, 0, bitmap_width("orange_bar_lines") * 0, bitmap_height("orange_bar_lines") * 0, option_to_screen()));
        draw_bitmap("heart", 680, 685, option_to_screen());
        draw_bitmap("heart_grey", 680, 685, option_part_bmp(0, 0, bitmap_width("heart"), (bitmap_height("heart") * 0.5), option_to_screen()));
        draw_text("FUEL: ", COLOR_WHITE, 150, 715, option_to_screen());
        draw_text("BONUS: ", COLOR_WHITE, 150, 760, option_to_screen());
        draw_text("HEALTH: ", COLOR_WHITE, 615, 725, option_to_screen());
        draw_text("SCORE: ", COLOR_WHITE, 150, 675, option_to_screen());
        

        // as well as the player who can move
        draw_player(game.player);
}