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

void add_power_up(game_data &game, double x, double y);

#endif