//Sound effects obtained from https://www.zapsplat.com/
//Link to screencast: https://2006242.kaf.kaltura.com/media/t/1_s4scry4q#
//Alternative link: https://drive.google.com/file/d/1ROTSJzEn80njxiwRC6qiRJFAvoOXS1Bo/view?usp=sharing

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
    }

    return 0;
}