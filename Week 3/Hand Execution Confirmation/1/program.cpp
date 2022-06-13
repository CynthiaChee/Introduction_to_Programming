#include "splashkit.h"

int main()
{
    int a, b, c;

    a = 3;
    b = 6;
    c = a + b;
    b = 10;

    write("c is ");
    write_line(c);
    write("b is ");
    write_line(b);

    return 0;
}