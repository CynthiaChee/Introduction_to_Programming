#include "splashkit.h"
#include "validating_user_input.h"

using namespace std;

int main()
{
    string name;
    int age;
    double height, range_test;
    bool test;
    bool again;

    do
    {
        name = read_string("Enter your name: ");
        write_line("For read integer test errors for real numbers and text");
        write_line(" - eg '3.1415' and 'Fred'");
        age = read_integer("Enter your age: ");
        write_line("For read double test errors for text - eg 'Fred'");
        height = read_double("Enter your height: ");
        write_line("Read double range test errors with number outside of range 0.0 - 1.0") ;
        range_test = read_double_range("Enter test value: ", 0.0, 1.0);
        write_line("Read boolean test errors with text other than yes and no");
        test = read_boolean("Yes or No: ");

        write_line("Got values: ");
        write("String: ");
        write_line(name);
        write("Integer: ");
        write_line(age);
        write("Double: ");
        write_line(height);
        write("Test value: ");
        write_line(to_string(range_test));
        write("Boolean: ");
        write_line(test);

        again = read_boolean("Try this again: ");

    } while (again == true);
    
    return 0;
}
