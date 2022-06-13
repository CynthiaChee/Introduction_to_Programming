#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

int main()
{
    string name;
    int age, test;

    name = read_string("Enter your name: ");
    write_line("Welcome " + name);

    age = read_integer("Enter your age: ");
    write_line("Great, you are " + to_string(age));

    test = read_integer("Enter test value: ", 1, 10);
    write_line(to_string(test));

    return 0;
}
