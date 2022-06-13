#include "splashkit.h"
#include <vector>
using namespace std;
using std::vector;

void data_push_back(double data[5], int idx, double value)
{
    if(idx >= 5 - 1) return;
    if(idx < 0) idx = 0;

    for(int i = 5 - 1; i > idx; i--)
    {
        write("data[i] is: ");
        write_line(data[i]);
        write("data[i - 1] is: ");
        write_line(data[i - 1]);
        
        data[i] = data[i - 1];
        data[i - 1] = value;
        
        write("index is: ");
        write_line(i);
        write("Value is: ");
        write_line(value);
    }
}

int main()
{
    write_line("Hello.");
    double data[5];
    int idx;
    double value;

    data[0] = 5;
    data[1] = -5;
    data[2] = 1;
    data[3] = 7;
    data[4] = -2;

    idx = 0;
    value = -4;
    write_line("Size of array: ");
    int sizearray = sizeof(data)/sizeof(data[0]);
    write_line(sizearray);
    data_push_back(data, idx, value);

    write_line("Data result is: ");

    for(int i = 0; i < 5; i++)
    {
        write_line(data[i]);
    }

    write("idx is: ");
    write_line(idx);

    write("Value is: ");
    write_line(value);

    return 0;
}