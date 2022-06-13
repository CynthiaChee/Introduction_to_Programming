#include "splashkit.h"

int main()
{
    /*int result = 0;
    vector<int> data;

    data.push_back(4);
    data.push_back(-7);
    data.push_back(-13);
    data.push_back(1);
    data.push_back(3);

    for (int i = 0; i<data.size(); i++)
    {
        write_line(data[i]);
    }

    for (int j = 0; j<data.size(); j++)
    {
        if(data[j]>2)
        {
            result = result + data[j] + j;
        }
            return result;
        write_line(result);
    }*/

    vector<int> int_array;

    int_array.push_back(120);
    int_array.push_back(240);
    int_array[0] = 120;
    int_array.pop_back();
    int_array.push_back(180);
    int_array.push_back(70);
    int_array.push_back(40);
    int_array.pop_back();
    for (int count = 2; count<int_array.size(); count++)
    {
        write_line(count);
        int_array[count] = 350;
    }
    for (int i = 0; i<int_array.size(); i++)
    {
        write_line(int_array[i]);
    }

}
