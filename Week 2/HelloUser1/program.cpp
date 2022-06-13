#include "splashkit.h"
#include <string>

#define STROUHAL 0.33

// Calculate resultant STROUHAL air speed by reading in freq and amp
double calculate_air_speed(int freq, int amp)
{
    double result;
    result = freq * amp * 0.01 / STROUHAL; //amp is converted from CM to M
    return result;
}

// Outputs bird name and resultant air speed to the terminal
void output_air_speed(int freq, int amp)
{
    write_line(calculate_air_speed(freq,amp));
}

// Return a string of the input line from the terminal
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

// Read in an integer from the user, with a parameter for the message to prompt with. Converts user input to integer
int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);

}

int main()
{
    // Declare variables
    string name;
    int age;
    string birdname;
    int freq;
    int amp;

    // Get user details
    name = read_string("What is your name: ");
    age = read_integer("What is your age: ");

    // Output to terminal
    write_line("");
    write("Hello, ");
    write_line(name + "!");
    write("Age: ");
    write_line(age);

    // Get bird details
    birdname = read_string("Which bird do you want to calculate air speed for: ");
    freq = read_integer("What is the frequency of the bird's beating wings: ");
    amp = read_integer("What is the amplitude of the bird's beating wings: ");

    // Output to terminal
    write_line("");
    write("The air speed for ");
    write(birdname);
    write(" is ");
    output_air_speed(freq, amp);

    write_line("* End of Program.*");
    return 0;
}