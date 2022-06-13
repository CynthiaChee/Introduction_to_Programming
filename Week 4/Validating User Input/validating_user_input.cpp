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

double read_double(string prompt)
{
    string line;
    double result;
    line = read_string(prompt);

    while ( not is_double(line))
    {
        write_line("Please enter a real number.");
        line = read_string(prompt);
    }
    result = convert_to_double(line);

    return result;
}

double read_double_range(string prompt, double min, double max)
{
    double result; 
    
    result = read_double(prompt); 

    while (result < min or result > max)
    {
        write_line("Please enter a real number between " + to_string(min) + " and " + to_string(max));
        result = read_double(prompt);
    }

    return result;
}

bool read_boolean(string prompt)
{
    string line;
    bool result;
    line = read_string(prompt);

    while(not (trim(to_lowercase(line)) == "yes") && not (trim(to_lowercase(line)) == "y") && not (trim(to_lowercase(line)) == "no") && not (trim(to_lowercase(line)) == "n"))
    {
        write_line("Try again");
        line = read_string(prompt);
    }
    
    if (trim(to_lowercase(line)) == "yes" || trim(to_lowercase(line)) == "y")
        {
            result = true;
        }
        
    if (trim(to_lowercase(line)) == "no" || trim(to_lowercase(line)) == "n")
        {
            result = false;
        } 

    return result;
}