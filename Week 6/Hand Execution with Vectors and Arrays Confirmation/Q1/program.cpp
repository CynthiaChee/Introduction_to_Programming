#include "splashkit.h"
#include <vector>
using namespace std;
using std::vector;

int main()
{
    write_line("Hello.");
    double data[5];

    data[0] = 8;
    data[1] = -7;
    data[2] = 8;
    data[3] = 2;
    data[4] = 8;

    int result = 0;

    for(int i = 0; i < 5; i++)
    {
        if(data[i] == 8)
        {
            result++;
        }
    }
    
    write("Result is: ");
    write_line(result);

    return 0;
}