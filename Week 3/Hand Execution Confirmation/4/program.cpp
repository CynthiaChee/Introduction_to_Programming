#include "splashkit.h"

int main()
{
    int a, b, c, d, e;

    a = 2;
    b = 8;
    c = 10;
    d = a;
    e = 30;

    b = a;
    a = a + b;
    c = e - c;
    d = a;
    e = e - 1;

    write("a is ");
    write_line(a);
    write("b is ");
    write_line(b);
    write("c is ");
    write_line(c);
    write("d is ");
    write_line(d);
    write("e is ");
    write_line(e);

    return 0;
}