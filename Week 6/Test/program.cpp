#include "splashkit.h"

int main()
{
    string food[5];
    food[0] = "Apples";
    food[1] = "Bread";
    food[2] = "Chocolate";
    food[3] = "Dairy";
    food[4] = "Eggs";

    int i;
    for(i = 4; i >= 0; i--)
    {
        write_line(food[i]);
    }

    return 0;
}