#include "splashkit.h"
//Program: Seven Times Table
//Display the seven times table from 1 * 7 to 10 * 7

//printf is equivalent to write() while printfn is equivalent to write_line

int main()
{
    printf("Seven Times Table\n");
    printf("-------------------\n");
    printf("1 x 7 = %d\n", 1 * 7);
    printf("2 x 7 = %d\n", 2 * 7);
    printf("3 x 7 = %d\n", 3 * 7);
    printf("4 x 7 = %d\n", 4 * 7);
    printf("5 x 7 = %d\n", 5 * 7);
    printf("6 x 7 = %d\n", 6 * 7);
    printf("7 x 7 = %d\n", 7 * 7);
    printf("8 x 7 = %d\n", 8 * 7);
    printf("9 x 7 = %d\n", 9 * 7);
    printf("10 x 7 = %d\n", 10 * 7);
    printf("-------------------\n");


// \n inserts a new line. if \n is omited for example in 1 x 7, we get 1 x 7 and 2 x 7 stuck together like "1 x 7 = 72 x 7 = 14"
    return 0;
}