#include "splashkit.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

void random_fill_array(int arr[], int size)          //Create an array filled with randomized values
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rnd(size*5);
    }
}

void print_array(int arr[], int size)               //Put this here just for testing to see if the array is really sorted
{                                                   //correctly by the algorithm
    for (int i=0; i<25; i++)
    {
        write_line(arr[i]);
    }
}

void swap(int &value1, int &value2)                 //Swaps the values during sorting
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void bubble_sort(int arr[], int size)               //Implements bubble sorting
{         
    for(int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);           //Performs swapping if out of order
            }
        }
    }
}

void insertion_sort(int arr[], int size)
{
    int i, key, j;            //key is the first element of the unsorted portion which we will compare with the sorted portion
    for(i = 1; i < size; i++) //i is the index of elements for comparison
    {
        key = arr[i];     //key is used to hold a value while shifts take place
        j = i - 1;          //j is the pointer for element for comparison with key

        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;  //value of next element in unsorted portion is stored in key
    }
}

void merge(int arr[], int a, int b, int c)  //Merges subarrays to form a sorted array
{
    int n1 = b - a + 1;                     //Splits the array by index
    int n2 = c - b;
    int sub1[n1], sub2[n2];

    //Copies the values of subarrays to be sorted
    for(int i = 0; i < n1; i++)
    {
        sub1[i] = arr[a + i];
    }
    for(int j = 0; j < n2; j++)
    {
        sub2[j] = arr[b + 1 + j];
    }

    //These are pointers for the arrays and subarrays
    int i = 0;                  //Index pointer for sub1
    int j = 0;                  //Index pointer for sub2
    int k = a;                  //Index pointer for the combined array

    //Sorts the values
    //If value of sub1 at index[i] <= value of sub2 at index[j],
    //place this value in the array at the index of k (starting from position a)
    //else, place value of sub2 if it is smaller than value of sub1
    while(i < n1 and j < n2)
    {
        if (sub1[i] <= sub2[j])
        {
            arr[k] = sub1[i], i++;
        }
        else
        {
            arr[k] = sub2[j], j++;
        }
        k++;
    }

    //Place remaining elements of sub1 or sub2 in the array (if subarray size is not equal this can lead to extra values)
    while(i < n1)
    {
        arr[k] = sub1[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = sub2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int front, int back)      //Divides the array into halves until we get subarrays of size 1
{
    if (front < back)
    {
        int mid = front + (back - front)/2;
        merge_sort(arr, front, mid);
        merge_sort(arr, mid + 1, back);
        merge(arr, front, mid, back);                //After splitting process is completed, merge is called to do the sorting and merging back into a full-size sorted array
    }
}

int partition(int arr[], int front, int back)     //low = starting index of array, high = ending index of array
{
    int pivot = arr[back];                      //Last element of array is chosen as pivot
    int i = (front - 1);                          //i the last element less than pivot (so i+1 indicates correct placement for the pivot)

    for(int j = front; j <= back-1; j++)          //j used as pointer for elements to compare with pivot
    {
        if (arr[j] < pivot)                     //if current element at j is smaller than pivot
        {
            i++;                               
            swap(arr[i], arr[j]);               //swap values of pivot index and the value smaller than the pivot
        }
    }
    swap(arr[i+1], arr[back]);                  //places pivot into correct position
    return (i+1);                               //returns pivot index
}

void quick_sort(int arr[], int front, int back)
{
    if (front < back)
    {
        int part_idx = partition(arr, front, back); //pivot index from partition() is used as partition index to form two sub-arrays

        quick_sort(arr, front, part_idx - 1);
        quick_sort(arr, part_idx + 1, back);
    }
}

//Added timers for each of the sorting algorithms
void bubble_sort_timed(int arr[], int values)
{
    auto bub_start = high_resolution_clock::now();
    bubble_sort(arr, values);
    auto bub_stop = high_resolution_clock::now();
    auto bub_duration = duration_cast<microseconds>(bub_stop - bub_start);
    write_line("Time taken by Bubble Sort to sort " + to_string(values) + " values is: " + to_string(bub_duration.count()) + " microseconds.");
}

void insertion_sort_timed(int arr[], int values)
{
    auto ins_start = high_resolution_clock::now();
    insertion_sort(arr, values);
    auto ins_stop = high_resolution_clock::now();
    auto ins_duration = duration_cast<microseconds>(ins_stop - ins_start);
    write_line("Time taken by Insertion Sort to sort " + to_string(values) + " values is: " + to_string(ins_duration.count()) + " microseconds.");
}

void merge_sort_timed(int arr[], int front, int values)
{
    auto mrg_start = high_resolution_clock::now();
    merge_sort(arr, 0, values);
    auto mrg_stop = high_resolution_clock::now();
    auto mrg_duration = duration_cast<microseconds>(mrg_stop - mrg_start);
    write_line("Time taken by Merge Sort to sort " + to_string(values) + " values is: " + to_string(mrg_duration.count()) + " microseconds.");
}

void quick_sort_timed(int arr[], int front, int values)
{
    auto qck_start = high_resolution_clock::now();
    quick_sort(arr, 0, values);
    auto qck_stop = high_resolution_clock::now();
    auto qck_duration = duration_cast<microseconds>(qck_stop - qck_start);
    write_line("Time taken by Quick Sort to sort " + to_string(values) + " values is: " + to_string(qck_duration.count()) + " microseconds.");
}

int main()
{
    string line;
    int option;
    string name;
    name = read_string("Hello, what is your name? ");

    do
    {
        write_line("Hello " + name + ", glad you're here!");
        int values = read_integer("Enter number of values to sort: ");
        int arr[values];
        random_fill_array(arr, values);
        write_line("1. Bubble Sort");
        write_line("2. Insertion Sort");
        write_line("3. Merge Sort");
        write_line("4. Quick Sort");
        write_line("5. All of them");
        write_line("6. Exit");
        write("Choose sorting option: ");
        line = read_line();
        option = convert_to_integer(line);
        switch(option)
        {
            case 1:
                bubble_sort_timed(arr, values);
                break;
            case 2:
                insertion_sort_timed(arr, values);
                break;
            case 3:
                merge_sort_timed(arr, 0, values);
                break;
            case 4:
                quick_sort_timed(arr, 0, values);
                break;
            case 5:
                random_fill_array(arr, values);
                bubble_sort_timed(arr, values);
                random_fill_array(arr, values);
                insertion_sort_timed(arr, values);
                random_fill_array(arr, values);
                merge_sort_timed(arr, 0, values);
                random_fill_array(arr, values);
                quick_sort_timed(arr, 0, values);
                break;
            case 6:
                write_line("Thank you for using this program, see you soon!");
                break;
            default:
                write_line("Please choose an option from the menu");
        }

    } while(option != 6);

    return 0;
}

