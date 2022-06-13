#include "splashkit.h"

int main()
{
    write_line("Hello.");
    double data[5];

    data[0] = 0;
    data[1] = -3;
    data[2] = 3;
    data[3] = -10;
    data[4] = 7;

    for(int i = 0; i < 5; i++)
    {
        if(data[i] < 0)
        {
            data[i] = data[i] * - 1;
        }
    }
    
    write_line("Data result is: ");

    for(int i = 0; i < 5; i++)
    {
        write_line(data[i]);
    }

    return 0;
}