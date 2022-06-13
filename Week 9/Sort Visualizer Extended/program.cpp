#include "splashkit.h"
using namespace std;

#define NUM_VALS 100                                 //Number of values to be sorted

void draw_values(const int values[], int size)      //Create a visual representation of the values in the form of bars
{
    int x = 0;
    int y;
    int rect_height;
    int rect_width = screen_width() / size;

    for (int i = 0; i < size; i++)
    {

        rect_height = values[i];
        y = screen_height() - rect_height;

        fill_rectangle(COLOR_PINK, x, y, rect_width, rect_height);
        draw_rectangle(COLOR_WHITE, x, y, rect_width, rect_height);
        
        x += rect_width;

    }
}

void swap(int &value1, int &value2)                 //Swaps the values during sorting
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void draw_sort(int values[], int size)              //Draws the sorting process
{
    clear_screen(COLOR_WHITE);
    draw_values(values, size);
    refresh_screen(60);
}

void bubble_sort(int values[], int size)            //Implements bubble sorting
{
    for(int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                swap(values[i], values[i + 1]);
                draw_sort(values, size);
            }
        }
    }
}

void insertion_sort(int values[], int size)
{
    int i, key, j;            //key is the first element of the unsorted portion which we will compare with the sorted portion
    for(i = 1; i < size; i++) //i is the index of elements for comparison
    {
        key = values[i];     //temp is used to hold a value while shifts take place
        j = i - 1;          //j is the pointer for element for comparison with key

        while (j>=0 && values[j] > key)
        {
            values[j+1] = values[j];
            j = j-1;
            draw_sort(values, size);
        }
        values[j+1] = key;  //value of next element in unsorted portion is stored in key
    }
}

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
    int k = a;                  //Index pointer for the combined array "values"

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
    draw_sort(values, k);
}

void merge_sort(int values[], int front, int back)      //Divides the array into halves until we get subarrays of size 1
{
    if (front < back)
    { 
        int mid = front + (back - front)/2;
        merge_sort(values, front, mid);
        merge_sort(values, mid + 1, back);
        merge(values, front, mid, back);                //After splitting process is completed, merge is called to do the sorting and merging back into a full-size sorted array
    }
}

int partition(int values[], int front, int back)
{
    int pivot = values[back];                           //last element of the array is chosen as the pivot
    int i = (front - 1);                                //i is the last element smaller than the pivot, so pivot will be placed at i+1

    for(int j = front; j <= back-1; j++)
    {
        if (values[j] < pivot)                          //moves values smaller than the pivot to its left
        {
            i++;
            swap(values[i], values[j]);
        }
    }
    swap(values[i+1], values[back]);                    //places pivot at the correct position
    draw_sort(values, i);
    return (i+1);
}

void quick_sort(int values[], int front, int back)
{
    if (front < back)
    {
        int part_idx = partition(values, front, back);  //takes the pivot index as partition index

        quick_sort(values, front, part_idx - 1);        //performs quick sort on each of the partitions
        quick_sort(values, part_idx + 1, back);
    }
}

void random_fill_array(int values[], int size)          //Create an array filled with randomized values
{
    for (int i = 0; i < size; i++) 
    {
        values[i] = rnd(screen_height()) + 1;
    }
}

void handle_input(int values[], int size)
{
    if (key_typed(R_KEY))
    {
        random_fill_array(values, size);
    }
    else if (key_typed(B_KEY))
    {
        bubble_sort(values, size);
    }
    else if (key_typed(M_KEY))
    {
        merge_sort(values, 0, size);
    }
    else if (key_typed(I_KEY))
    {
        insertion_sort(values, size);
    }
    else if (key_typed(Q_KEY))
    {
        quick_sort(values, 0, size);
    }
}

int main()
{
    int values[NUM_VALS];

    open_window("Sort Visualiser", 800, 600);
    
    random_fill_array(values, NUM_VALS);
    while ( not quit_requested() )
    {
        process_events();
        handle_input(values, NUM_VALS);
        draw_sort(values, NUM_VALS);
    }

    return 0;
}