#include "splashkit.h"

void merge(int values[], int a, int b, int c)  //Merges subarrays to form a sorted array
{
    int n1 = b - a + 1;     //Splits the array by index
    int n2 = c - b;

    int sub1[n1], sub2[n2];

    //Copies the values of subarrays to be sorted
    for(int i = 0; i < n1; i++)
    {
        sub1[i] = values[a + i];
    }
    for(int j = 0; j < n2; j++)
    {
        sub2[j] = values[b + 1 + j];
    }

    //These are pointers for the arrays and subarrays
    int i = 0;                  //Index pointer for sub1
    int j = 0;                  //Index pointer for sub2
    int k = a;                  //Index pointer for the original array "values"

    //Sorts the values
    //If value of sub1 at index[i] <= value of sub2 at index[j],
    //place this value in "values" array at the index of k (starting from position a)
    //else, place value of sub2 if it is smaller than value of sub1
    while(i < n1 and j < n2)
    {
        if (sub1[i] <= sub2[j])
        {
            values[k] = sub1[i], i++;
        }
        else
        {
            values[k] = sub2[j], j++;
        }
        k++;
    }

    //Place remaining elements of sub1 or sub2 in the array (if subarray size is not equal this can lead to extra values)
    while(i < n1)
    {
        values[k] = sub1[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        values[k] = sub2[j];
        j++;
        k++;
    }
}

void merge_sort(int values[], int front, int back)
{
    if (front < back)
    { 
        int mid = front + (back - front)/2;
    
        merge_sort(values, front, mid);
        merge_sort(values, mid + 1, back);
        merge(values, front, mid, back);
    }
}

void print_array(int values[], int size)
{
    for(int i = 0; i < size; i++)
    {
        write_line(values[i]);
    }
}

void random_fill_array(int values[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        values[i] = rnd(5);
    }
}

int main()
{
    int values[] = {4, 23, 54, 67, 16, 89};
    int size = sizeof(values) / sizeof(values[0]);
    print_array(values, size);
    merge_sort(values, 0, size);
    print_array(values, size);

    return 0;
}