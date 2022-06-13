#include "splashkit.h"
#include<string>

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

void test_user_details()
{
    string name;
    string line;

    name = read_string("What is your name: ");
    write_line("Hello " + name);

    if (name == "Cynthia")
    {
        write_line("Happy Easter!");
    }

    else
    {
        if(name == "Mom")
        write_line("Wait, what are you doing here?");
    }

    if(name == "Dinesh")
    {   
        write_line("Thank you for taking the time to look at this submission");
    }

    else
    {
        if(name == "Aladdin")
        write_line("You have three wishes to make");
    }
    
}

void play_guess_the_number()
{
    string line;
    int guess;
    int target;

    target = rnd(100) + 1;

    write_line("I'm thinking of a number between 1 and 100");

    while (guess != target)
    {
        write("Guess the number: ");
        line = read_line();

        guess = convert_to_integer(line);

        if (guess < target)
        {
            write_line("No, the number is greater than " + std::to_string(guess));
        }
        else if (guess > target)
        {
            write_line("No, the number is smaller than " + std::to_string(guess));
        }
        else
        {
            write_line("Wow you got it! The number was " + std::to_string(target));
        }
    }
}
int main()
{
    string line;
    int option;

    do
    {   
        write_line("1. Test your name");
        write_line("2. Guess the number");
        write_line("3. Quit");

        write("Choose option: ");
        line = read_line();
        option = convert_to_integer(line);

        switch(option)
        {
            case 1:
                test_user_details();
                break;
            case 2:
                play_guess_the_number();
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