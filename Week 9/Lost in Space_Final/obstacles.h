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