#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include <vector>

using namespace std;
using std::vector;

struct game_data
{
    player_data player;
    vector<power_up_data> power_ups;
};

game_data new_game();

void update_game(game_data &game);

void draw_game(const game_data &game);

void add_power_up(game_data &game);

void check_collisions(game_data &game);

void apply_power_up(game_data &game, int index);

void remove_power_up(game_data &game, int index);

void check_power_up_position (game_data &game);

point_2d power_mini_map_coordinate(const power_up_data &power_up);

point_2d player_mini_map_coordinate(const player_data &player);

void draw_mini_map(const game_data &game);

void draw_hud(const game_data &gmae);

#endif