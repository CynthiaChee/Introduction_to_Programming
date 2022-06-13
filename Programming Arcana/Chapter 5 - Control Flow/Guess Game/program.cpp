#include "splashkit.h"
#include <string>

using namespace std;

//Guess game

//declare constants
#define MAX_NUMBER 100
#define MAX_GUESSES 7

// Print a line onto the terminal
void print_line(int len)
{
    int i = 0;
    while(i < len)
    {
        printf("-");
        i++;
    }

    printf("\n");
}

// Perform steps for the guess. Reads the value entered by the user, outputs a message and then returns true if got it otherwise false.
bool perform_guess(int num_guess, int target)
{
    int guess;

    printf("Guess %d: "), num_guess;
    scanf("%d", &guess);

    if (target < guess) printf("The number is less than %d\n", guess);
    else if (target > guess) printf("The number is larger than %d\n"), guess;
    else printf("Well done... the number was %d\n", guess);

    return target == guess;
}

//Implements a simple guessing game. The program generates a random number, and the player tries to guess it.
void play_game()    //Function
{
    int my_number, num_guess;   //Variables
    bool got_it;

    my_number = random() % MAX_NUMBER + 1;
    num_guess = 0;  //Keep track of the number of guesses

    printf("I am thinking of a number between 1 and %d\n\n", MAX_NUMBER);

    do
    {
        num_guess++;
        got_it = perform_guess(num_guess, my_number);
    } while (num_guess < MAX_GUESSES && !got_it);

    if (!got_it)
    {
        printf("You ran out of guesses... the number was %d\n", my_number);
    }

}

//Loops the guessing game until the user decides to quit
int main()
{
    char again;
    srandom(time(0));

    do
    {
        play_game();

        printf("\n");
        print_line(50);
        printf("Do you want to play again [y/n]? ");
        scanf(" %c", &again);
    
    } while (again == 'y' || again == 'Y');

    printf("\nBye\n");
    return 0;
}