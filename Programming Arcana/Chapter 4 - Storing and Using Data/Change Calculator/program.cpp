#include "splashkit.h"

// defining constants
#define TWO_DOLLARS 200
#define ONE_DOLLAR 100
#define FIFTY_CENTS 50
#define TWENTY_CENTS 20
#define TEN_CENTS 10
#define FIVE_CENTS 5

// function coins_to_give, parameters: change, coin_value
int coins_to_give(int change, int coin_value)
{
    return change / coin_value;
}

// procedure give_change
// parameters = &change_value (pass by reference), coin_value, coin_desc (coin description
void give_change(int &change_value, int coin_value, const char *coin_desc)
{
    int to_give;
    
    to_give = coins_to_give(change_value, coin_value); // local variable = to_give
    change_value = change_value - to_give * coin_value;

    printf("%d x %s, ", to_give, coin_desc);
}

// gets user input (printf = output message, scanf = takes user input)
int get_change_value()
{
    int cost_of_item;
    int payment;

    printf("Cost of item (in cents): ");
    scanf("%d", &cost_of_item);

    printf("Amount paid (in cents): ");
    scanf("%d", &payment);

    return payment - cost_of_item;
}

//entry point (main)
int main()
{
    int change_value;  //variable
    change_value = get_change_value();

    printf("Change: ");
    give_change(change_value, TWO_DOLLARS, "$2");
    give_change(change_value, ONE_DOLLAR, "$1");
    give_change(change_value, FIFTY_CENTS, "50c");
    give_change(change_value, TWENTY_CENTS, "20c");
    give_change(change_value, TEN_CENTS, "10c");
    give_change(change_value, FIVE_CENTS, "5c");
    printf("\n");

    return 0;
}