#include "splashkit.h"

int main()
{
    //Output the messages
    write_line("Output Test Program");
    write_line("1 + 1 = "+ std::to_string(1 + 1)); //leave no space at "+ std::to_string
    write_line("Area of a circle with radius 3 = %.2f" + std::to_string(3.1415 * 3 * 3));

    //Finish
    return 0;
}

//%.2f = % is the symbol of a variable (a special character whose value is to be added)
//f = the result that is printed will be a float
//.2 = results printed up to 2 decimal points (.3 = 3 decimal points, .4 = 4 decimal points, etc)