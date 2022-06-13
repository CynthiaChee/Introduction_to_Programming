#include "splashkit.h"
#include <string>

#define STROUHAL 0.33
#define PI 3.14159

// Calculate resultant STROUHAL air speed by reading in freq and amp
double calculate_air_speed(double freq, double amp)
{
    double result;
    result = freq * amp * 0.01 / STROUHAL; //amp is converted from CM to M
    return result;
}

// Outputs resultant air speed to the terminal
void output_air_speed(double freq, double amp)
{
    write_line(calculate_air_speed(freq,amp));
}

// Calculate volume of a cylinder from reading radius and height
double calculate_cylinder_volume(double radius, double height)
{
    double volume;
    volume = PI * radius * radius * height;   //pi x r^2 x h
    return volume;
}

// Outputs resultant volume of cylinder to the terminal
void output_volume(double radius, double height)
{
    write_line(calculate_cylinder_volume(radius,height));
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

// Read in an double from the user, with a parameter for the message to prompt with. Converts user input to double
double read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_double(line);

}

int main()
{
    // Declare variables
    string name;
    int age;
    string birdname;
    double freq;
    double amp;
    double radius;
    double height;

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
    freq = read_double("What is the frequency of the bird's beating wings: ");
    amp = read_double("What is the amplitude of the bird's beating wings: ");

    // Output to terminal
    write_line("");
    write("The air speed for ");
    write(birdname);
    write(" is ");
    output_air_speed(freq, amp);

    //  Get cylinder details
    radius = read_double("What is the radius of your cylinder: ");
    height = read_double("What is the height of your cylinder: ");

    // Output to terminal
    write_line("");
    write("The volume of the cylinder is ");
    output_volume(radius,height);
    
    write_line("* End of Program.*");
    return 0;
}