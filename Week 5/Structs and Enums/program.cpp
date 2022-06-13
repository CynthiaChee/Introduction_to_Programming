#include "splashkit.h"
#include <string>

using namespace std;

struct knight_data
{
    string name;
    int age;
    int month;
    double weight;
};

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

int read_integer_range(string prompt)
{
    int result; 
    
    result = read_integer(prompt); 

    while (result < 1 or result > 12)
    {
        write_line("Please enter a valid month number from 1 to 12");
        result = read_integer(prompt);
    }

    return result;
}

double read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}

knight_data read_knight()
{
    knight_data result;
    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");
    result.month = read_integer_range("Enter birth month: ");
    result.weight = read_double("Enter weight: ");
    return result;
}

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_MONTH,
    UPDATE_WEIGHT,
    FINISH_UPDATE
};

knight_update_option read_knight_update_option()
{
    int result;

        write_line("1: Update name");
        write_line("2. Update age");
        write_line("3. Update birth month");
        write_line("4. Update weight");
        write_line("5. Finish update");
        result = read_integer("Select option: ");
        
        return static_cast<knight_update_option>(result - 1);
}

void write_knight(const knight_data &knight)
{
    write_line("Hello, " + knight.name + " aged " + to_string(knight.age) + " born on month " + to_string(knight.month) + " who weighs " + to_string(knight.weight) + " kgs.");
}

void update_knight(knight_data &knight)
{
    knight_update_option option;

    do
    {
        write_line();
        write_line("== Update Knight ==");
        write_knight(knight);
        write_line();
        option = read_knight_update_option();

        switch(option)
        {
            case UPDATE_NAME:
            knight.name = read_string("Enter new name ");
            break;
            case UPDATE_AGE:
            knight.age = read_integer("Enter new age ");
            break;
            case UPDATE_MONTH:
            knight.month = read_integer_range("Enter new birth month ");
            break;
            case UPDATE_WEIGHT:
            knight.weight = read_double("Enter new weight ");
            break;
            case FINISH_UPDATE:
            break;
            default:
            write_line("Please select a valid option");
        }
    } while (option != FINISH_UPDATE);
    
}

int main()
{
    knight_data my_knight;
    my_knight = read_knight();
    write_knight(my_knight);

    update_knight(my_knight);
    write_line("After update... back in main");
    write_knight(my_knight);

    return 0;
}