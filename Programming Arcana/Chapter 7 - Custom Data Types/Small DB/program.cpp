#include "splashkit.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

//==========
// SMALL DB
//==========

//the number of elements in the row array
#define DB_SIZE 3

//the Column Value union. Stores either an integer, a double or 8(7+1) characters.
typedef union {
        int int_val;
        double double_val;
        char txt_val[8];
    } column_value;









int main()
{
    return 0;
}