#include "splashkit.h"
#include <string>
using std::string;

#define COEFF 3.28  //coefficient

double calcm_to_ft(double met)
{
    double result;
    result = met * COEFF;
    return result;
}

void output_m_to_ft(double met)
{
    write_line(calcm_to_ft(met));
}

double calcft_to_m(double ft)
{
    double result;
    result = ft / COEFF;
    return result;
}

void output_ft_to_m(double ft)
{
    write_line(calcft_to_m(ft));
}

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

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
    double met;
    double ft;

    do
    {
        write_line("1. Convert metres to feet");
        write_line("2. Convert feet to metres");
        write_line("3. Quit Program");

        write("Choose option: ");
        line = read_line();
        option = convert_to_integer(line);

        switch(option)
        {
            case 1:
                met = read_double("Enter value in metres: ");
                write("The converted value in ft is: ");
                output_m_to_ft(met);
                
                break;
            case 2:
                ft = read_double("Enter value in feet: ");
                write("The converted value in metres is: ");
                output_ft_to_m(ft);
                break;
            case 3:
                write_line("See you soon!");
                break;
            default:
                write_line("Please choose an option from the menu");
        }
    } while (option != 3);
    
    return 0;
}