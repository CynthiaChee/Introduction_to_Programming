#include "splashkit.h"
#include <vector>
using namespace std;
using std::vector;

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

int total_length(const vector<string> &names)
{
    int result = 0;
    
    for(int i = 0; i < names.size(); i++)
    {
        string name = names[i];
        result += name.length();
    }

    return result;
}

string longest_name(const vector<string> &names)
{
    string max;

    max = names[0];
    for(int i  = 1; i < names.size(); i++)
    {
        if (max.length() < names[i].length())
        {
            max = names[i];
        }
    }

    return max;
}

int index_of(string name, const vector<string> &names)
{
    for(int i = 0; i < names.size(); i++)
    {
        if((to_lowercase(names[i]) == to_lowercase(name)))
        {
            return i;
        }
    }
    return -1;
}

void change_name(vector<string> &names, string to_change)
{
    int index_to_change;
    to_change = read_string("Which name would you like to change?: ");
    index_to_change = index_of(to_lowercase(to_change), names);
    if(index_to_change != -1)
        {
            names[index_to_change] = read_string("Enter a new name: ");
        }
    else
        {
            write_line(to_change + " is not in the name list.");
        }
}

void print_summary(const vector<string> &names)
{
    //Prints all names
    int i;
    write_line("List of names: ");
    for(i = 0; i < names.size(); i++)
    {
        write_line(names[i]);
    }

    //Prints total length of all names
    int total;
    total = total_length(names);
    write("Total length: ");
    write_line(total);

    //Prints longest name
    write_line("The longest name is: " + longest_name(names));

    //Prints index of name
    int index_cinderella;
    index_cinderella = index_of("cinderella", names);
    write("Index of Cinderella is at: ");
    write_line(index_cinderella);

}

int main()
{
    vector<string> names;
    string line;
    int option;
    int entries;
    string to_change;

    //Asks the user how many names to input
    entries = read_integer("How many names do you want to enter?: ");

    //Asks the user to input the names
    while(names.size() < entries)
    {
        names.push_back(read_string("Enter a name: "));
    }

    //Prints summary of name list
    write_line("Summary of name list:");
    print_summary(names);

    do
    {
        write_line("1. Update name");
        write_line("2. Quit");
        write("Choose option: ");
        line = read_line();
        option = convert_to_integer(line);

        switch(option)
        {
            case 1:
                change_name(names, to_change);
                break;
            case 2:
                write_line("See you later!");
        }
    
        write_line("Updated summary of name list:");
        print_summary(names);
    
    } while (option != 2);

    return 0;
}