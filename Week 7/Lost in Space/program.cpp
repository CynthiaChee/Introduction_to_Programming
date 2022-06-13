#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"

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
    //player_data player;
    game_data game;
    game = new_game();
    //power_up_data power;
    //power = new_power_up(150, 450);

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);

        // Perform movement and update the camera
        update_game(game);

        draw_game(game);

        // Redraw everything


        refresh_screen(60);
    }

    return 0;
}