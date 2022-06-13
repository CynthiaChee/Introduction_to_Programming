
/**
 * As said in the lecture, do not direct copy the demo code for compilation, 
 * there are plenty of fill in the blanks in this .cpp
 */

#include "splashkit.h"

#include <vector>

using std::vector;
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
//programp1_demo_pA: int total_length(string array[], int size) //static array
int total_length(const vector <string> &array) //change to vector, const, pass by reference 
{
     //you code(s) and your own comment here

    //for (...???...; i < array.size(); ...???...)

    //you code(s) here

}

/**
 * Calculates whether or not the array contains a certain value. //weekly videos
 */
bool contains(???...???) //???...??? you code(s) here //change array to vector, const, pass by reference 
{
     //you code(s) and your own comment here
}

/**
 * Calculates the longest name in the array.
 * Reference to weekly video for the static array, string shortest_name(string array[], int size)
 */
string longest_name(???...???) //???...??? you code(s) here //change array to vector, const, pass by reference 
{
     //you code(s) and your own comment here
}

/**
 * A function to return the index of a given name within the list. 
 *  return the index of a given name in the array. This should return -1 if the name is not present.
 */
////programp1_demo_pA: int index_of(string array[], string value, int size)
int index_of(const vector <string> &array,string value)
{
     //you code(s) and your own comment here
}

/* Allows the user to change one of the names if the name was in the list (in the array) 
    *ask them to enter the name to change, 
    *and then the new name. 
    *If the name to change was in the list, replace the value at that index with the new name.
*/
//programp1_demo_pA: void change_name(string array[], string value , int size)
void change_name(vector <string> &array, string value) //why no const to the const here?
{
     //you code(s) and your own comment here
}

/**
 * Prints out all names, total length of names, the *longest* name and
 * the index of your name.
 */
void print_summary(???...???) //???...??? you code(s) here //change array to vector, const, pass by reference 
{
      //you code(s) and your own comment here
}

int main()
{
    //Declare other varibles
    vector <string> names;
    string name;
    int i = 0;
    
    //I choose not to define a constant for the size
    //So I ask user to input number of names to store in the array
    int size = read_integer("How many names will be entered? ");
    //Loop to read in the names
    while (i < size)
    {
        names.push_back(read_string("Enter a name: "));
        i++;
    }
    
    //Call print summary to output the details
    print_summary(names);
    //Allow the user to change one of the names - 
    change_name(names, name);
    //Call print summary again to output the new details
    print_summary(names);

    write_line("Goodbye");

    return 0;
}