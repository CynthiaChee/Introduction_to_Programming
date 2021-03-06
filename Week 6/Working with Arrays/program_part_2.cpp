#include "splashkit.h"
#define SIZE 3

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

int total_length(string names[], int size)
{
    int result = 0;
    
    for(int i = 0; i < size; i++)
    {
        string name = names[i];
        result += name.length();
    }

    return result;
}

string longest_name(string names[], int size)
{
    string max;

    max = names[0];
    for(int i  = 1; i < size; i++)
    {
        if (max.length() < names[i].length())
        {
            max = names[i];
        }
    }

    return max;
}

int index_of(string name, string names[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if((to_lowercase(names[i]) == to_lowercase(name)))
        {
            return i;
        }
    }
    return -1;
}

void change_name(string names[], string to_change, int size)
{
    int index_to_change;
    to_change = read_string("Which name would you like to change?: ");
    index_to_change = index_of(to_lowercase(to_change), names, SIZE);
    if(index_to_change != -1)
    {
        names[index_to_change] = read_string("Enter a new name: ");
    }
    else
    {
        write_line(to_change + " is not in the name list.");
    }
}

void print_summary(string names[], int size)
{
    //Prints all names
    int i;
    write_line("List of names: ");
    for(i = 0; i < SIZE; i++)
    {
        write_line(names[i]);
    }

    //Prints total length of all names
    int total;
    total = total_length(names, SIZE);
    write("Total length: ");
    write_line(total);

    //Prints longest name
    write_line("The longest name is: " + longest_name(names, SIZE));

    //Prints index of name
    int index_cinderella;
    index_cinderella = index_of("cinderella", names, SIZE);
    write("Index of Cinderella is at: ");
    write_line(index_cinderella);

}

int main()
{
    string names[SIZE];
    string line;
    int i;
    int size;
    int option;
    string to_change;

    //Requests user input for names
    for(i = 0; i < SIZE; i++)
    {
        names[i] = read_string("Enter a name: ");
    }

    write_line("Summary of name list:");
    print_summary(names, size);

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
                change_name(names, to_change, size);
                break;
            case 2:
                write_line("See you later!");
        }
    
        write_line("Updated summary of name list:");
        print_summary(names, size);
    
    } while (option != 2);
    


    return 0;
}