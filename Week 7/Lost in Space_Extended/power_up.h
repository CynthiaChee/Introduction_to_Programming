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