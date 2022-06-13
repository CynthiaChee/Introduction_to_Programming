#include "splashkit.h"

using namespace std;

string read_string (string prompt)
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

int read_integer (string prompt)
{
    string line;
    int result;

    line = read_string(prompt);

    while ( not is_integer(line))
    {
        write_line("Please enter a whole number.");
        line = read_string(prompt);
    }
    result = convert_to_integer(line);

    return result;
}

int read_integer (string prompt, int min, int max)
{
    int result; 
    
    result = read_integer(prompt); 

    while (result < min or result > max)
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_integer(prompt);
    }

    return result;
}