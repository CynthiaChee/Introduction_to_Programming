#include "splashkit.h"
#include<vector>

int main()
{
    vector<string> names;
    names.push_back("Adam");
    names.push_back("Bob");
    names.push_back("Cindy");
    names.push_back("Diane");
    names.pop_back();
    write_line(names[1]);
    for(int i=0; i<names.size(); i++)
    {
        write_line(names[i]);
    }

    int arr[5];     
    // add values to the array by their indices 
    // (remember that they start from 0) 
    arr[0] = 12;   
    arr[1] = 24;
    arr[2] = 15;
    arr[3] = 7;
    arr[4] = 30;

    for(int j=0; j<3; j++)
    {
        arr[j] = 2*arr[j];
    }
    
    for(int k=0; k<5; k++)
    {
        write_line(arr[k]);
    }

    return 0;
}