#include "splashkit.h"

// This program demonstrates assignments to a variable.

int main()
{
    int my_data = 10, days_in_month, days_remaining;
    printf("my_data is %d\n", my_data);

    my_data = my_data + 1;                     //add 1 to my_data and store in my_data
    printf("my_data is %d\n", my_data);

    my_data += 1;                              //add 1 to my_data and store in my_data
    printf("my_data is %d\n", my_data);
    
    my_data ++;                                //add 1 to my_data and store in my_data
    printf("my_data is %d\n", my_data);

    -- my_data;                                //subtract 1 from my_data and store in my_data
    printf("my_data is %d\n", my_data);

    my_data *= 2;                              //double my_data and store in my_data
    printf("my_data is %d\n", my_data);

    days_in_month = 365 / 12;                   //assign days_in_month a calculated value
    printf("On average there are %d days in a month.\n", days_in_month);

    days_remaining = 365 - days_in_month * 12;  //assign days_remaining a calculated value
    printf("The remaining %d days are distributed to a few months.\n", days_remaining);

    return 0;
}