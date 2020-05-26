// importing all the libriaries including math.h
#include <stdio.h>
#include <cs50.h>
#include <math.h>

// main function declaration
int main(void)
{
    // declaration of variable to use in devision and modulus process
    int pennies = 1;
    int nickels = 5;
    int dimes = 10;
    int quarters = 25;

    // float change;
    int change_owed;
    do
    {
        float change = get_float("What amount owed: ");
        change_owed = round(change * 100);
    }
    while (change_owed <= 0);
    // Refactoring all the code is bad belowe
    // while (change_owed >= 100)
    //  {
    //      change_owed = change_owed - 100;
    //  }

    // while (change != 0)
    // {
    int quarters_owed = change_owed / quarters;
    int dimes_owed = (change_owed % quarters) / dimes;
    int nickels_owed = ((change_owed % quarters) % dimes) / nickels;
    int pennies_owed = ((change_owed % quarters) % dimes) % nickels / pennies;
    // }
    // Final result
    int coins = quarters_owed + dimes_owed + nickels_owed + pennies_owed;
    printf("The amount of coins to give: %i\n", coins);
}