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
        /*if (key_typed(L_KEY))
        {
            game.player.level +=1;
            play_sound_effect("level_up");
        }*/

        //Player successful once past level 10
        if(game.player.level >= 11)
        {
            draw_text("CONGRATULATIONS! YOU REACHED LEVEL " + std::to_string(game.player.level), COLOR_WHITE, 350, 300, option_to_screen());
            draw_text("FINAL SCORE: " + std::to_string(game.player.score), COLOR_WHITE, 350, 350, option_to_screen());
            draw_text("GAME OVER", COLOR_WHITE, 350, 400, option_to_screen());
            draw_text("PRESS R TO RESTART", COLOR_WHITE, 350, 450, option_to_screen());
            stop_music();
            close_audio();
            refresh_screen(60);
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