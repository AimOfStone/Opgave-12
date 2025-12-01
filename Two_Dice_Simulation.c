/*=============================================================================
*                             Two dice simulations
*            https://c-programming.aydos.de/week12/review-problems.html
gcc .\opgave-12\two_Dice_Simulation.c -o .\opgave-12\two_Dice_Simulation.exe
.\opgave-12\two_Dice_Simulation.exe
*==============================================================================*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*=============================================================================
*                              Helper functions
*=============================================================================*/

/*-----------------------------------------------------------------------------
* dice_throw: randomly generate 2 values (1-6).
*
*   @param values               the maximum value (int) on the dice we simulate
*   @return sum of values       returns a single throw throw simulation      
-----------------------------------------------------------------------------*/

int dice_throw(int values)
{
    int first = rand() % (values) +1;
    int second = rand() % (values) +1;

    int combined_value = first + second;
    return combined_value;
}

/*-----------------------------------------------------------------------------
* Simulate multiple dice_throw.
*
*   @param repetition           int for amount of simulations
*   @param values               the value we simulate the dice with
*   @param counts[]             the array where we store the values
-----------------------------------------------------------------------------*/
void simulate(int repetition, int values, int counts[])
{
    for(int i = 0; i < repetition ; i++) //repeat X times
    {
        unsigned int dice_Throw_Value = dice_throw(values);
        counts[dice_Throw_Value]++; //add +1 to the simulated value
    }
}


/*=============================================================================
*                                Main function
*=============================================================================*/

int main(void)
{
    srand(time(NULL));

    unsigned int counts[13] = {0}; // //array where I store my output value from each sim. Doesn't need 0 or 1 so just using 2-12
    simulate(50000, 6, counts);

    for (int sum = 2; sum <= 12; sum++)
    {
        printf("%2d: %d\n", sum, counts[sum]);
    }

    return 0;
}

/*
Write a program that simulates the distribution of the sum of two dice.
Throw the dice 50.000 times and store the occurrences of the possible sums (2-12) in an array.

The program must output the occurrences for every sum as follows:
*/