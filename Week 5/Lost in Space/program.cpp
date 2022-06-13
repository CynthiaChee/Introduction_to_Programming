#include "splashkit.h"
#include "player.h"
#include "power_up.h"

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

    player_data player;
    player = new_player();

    power_up_data power;
    power = new_power_up(150, 450);

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(player);

        // Perform movement and update the camera
        update_player(player);

        // Redraw everything
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
        draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 400, 675, option_to_screen());
        draw_power_up(power);
        // as well as the player who can move
        draw_player(player);

        refresh_screen(60);
    }

    return 0;
}