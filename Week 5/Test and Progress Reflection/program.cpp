#include "splashkit.h"
#include <string>

#define COEFF 0.62  //defining constant (coefficient)

//Converts kilometres to miles
double calc_km_to_miles(double km)
{
    double result;
    result = km * COEFF;
    return result;
}

//Outputs converted value to terminal
void output_km_to_miles(double km)
{
    write_line(calc_km_to_miles(km));
}

//Converts miles to kilometres
double calc_miles_to_km(double miles)
{
    double result;
    result = miles / COEFF;
    return result;
}

//Outputs converted value to terminal
void output_miles_to_km(double miles)
{
    write_line(calc_miles_to_km(miles));
}

//Read user input
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

//Read user input and converts to double
double read_double(string prompt)
{
    string line;
    double result;
    line = read_string(prompt);
    result =  convert_to_double(line);
    return result;
}

int main()
{
    string line;
    int option;
    double km;
    double miles;

    //Post-test loop
    do
    {
        write_line("1. Convert kilometres to miles");
        write_line("2. Convert miles to kilometres");
        write_line("3. Quit Program");

        write("Choose option: ");
        line = read_line();
        option = convert_to_integer(line);

        switch(option)  //Branching statement - allows user to choose options
        {
            case 1:
                km = read_double("Enter value in kilometres: ");
                write("The converted value in miles is: ");
                output_km_to_miles(km);
                
                break;
            case 2:
                miles = read_double("Enter value in miles: ");
                write("The converted value in kilometres is: ");
                output_miles_to_km(miles);
                break;
            case 3:
                write_line("See you soon!");
                break;
            default:
                write_line("Please choose an option from the menu");
        }
    } while (option != 3);   //Program continues to run as long as user does not choose to quit program
    
    return 0;
}