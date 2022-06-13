#include "splashkit.h"

//Program: Morse Calling
// Outputs the morse cose for the signal "Calling Anyone" (cq)

void short_signal()
{
    printf(".");
}

void long_signal()
{
    printf("-");
}

void signal_c()
{
    printf(" ");
    long_signal();
    short_signal();
    long_signal();
    short_signal();
}

void signal_q()
{
    printf(" ");
    long_signal();
    long_signal();
    short_signal();
    long_signal();
}
int main()
{
    signal_c();
    signal_q();
    printf("\n");

    return 0;
}