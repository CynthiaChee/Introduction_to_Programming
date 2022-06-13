/**
 * As said in the lecture, do not direct copy the demo code for compilation, 
 * there are plenty of fill in the blanks in this .cpp
 */

#include "splashkit.h"

using namespace std;

/**
 * Useful read_ family reading inputs in various types
 */
string read_string(string prompt)
{
    //you code(s) and your own comment here
}

int read_integer(string prompt)
{
   //you code(s) and your own comment here
}

double read_double(string prompt)
{
    //you code(s) and your own comment here
}

/**
 * Calculate total length of array (list of names) //weekly videos
 */
int total_length(string array[], int size)
{
    //you code(s) and your own comment here
}

/**
 * Calculates whether or not the array contains a certain value. //weekly videos
 */
bool contains(string array[], int size, string value)
{
    //you code(s) and your own comment here
}

/**
 * Calculates the longest name in the array.
 * Reference to weekly video, string shortest_name(string array[], int size)
 */
string longest_name(string array[], int size)
{
    string max;
    max = array[0];

    for (int i = 0; i < size; i++)
    {
        if (max.length() ?????? array[i].length())  //?????? you code here: How to set up the comparsion?
        {
            max = array[i];
        }
    }

    return max;
}

/**
 * A function to return the index of a given name within the list. 
 *  return the index of a given name in the array. This should return -1 if the name is not present.
 */
int index_of(string array[], string value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (to_lowercase(??? A ???) == to_lowercase(??? B ???)) //A? abd B? you code here: What to be compare?
        {
            return i;
        }
    }
    return -1;
}

/* Allows the user to change one of the names if the name was in the list (in the array) 
    *ask them to enter the name to change, 
    *and then the new name. 
    *If the name to change was in the list, replace the value at that index with the new name.
*/
void change_name(string array[], string value , int size)
{
    //Declare variables
    //you code(s) and your own comment here

    //ask them to enter the name to change
    //you code(s) and your own comment here *What data type?

    //Check the name is in the array 
    //you code(s) and your own comment here  *What data type?

    /*you code(s) and your own comment here 
    //if - Check the name if it is in the array
        //obtain the corresponding index
        //ask to enter the new name
        //update the record with the corresponding index by the new name
    //else 
        //do nothing or give a response
    */
}

/**
 * Prints out all names, 
 * total length of names, 
 * the *longest* name, and
 * the index of the name.
 * //partly in weekly videos
 */
void print_summary(string array[], int size)
{
    //you code(s) and your own comment here
}

int main()
{

    //Use a constant for the size (make it 3 or 4 or 5)
    #define SIZE 5
    //Declare other varibles
    string names[SIZE];
    string name;
    int i = 0;
    
    //Loop to read in the names
    while (i < SIZE)
    {
        names[i] = read_string("Enter a name: ");
        i++;
    }
    
    //Call print summary to output the details
    print_summary(names, i);
    //Allow the user to change one of the names - 
        //ask them to enter the name to change, 
        //and then the new name. 
        //If the name to change was in the list, replace the value at that index with the new name.
        //you code(s) and your own comment here
    change_name(names, name, SIZE);
    //Call print summary again to output the new details
    print_summary(names, i);

    write_line("Goodbye");

    return 0;
}