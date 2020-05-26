// importing all the libriaries
#include <cs50.h>
#include <stdio.h>

// Declaring a main function where we have all the code
int main(void)
{
    // Declating a variables that will be used further
    int height;

    // Warn the user that the integer must be in range from 1 to 8
    printf("Enter a value more than 0 and less than 8.\n");

    // Prompting from a user an input in range of 1 or 8
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // Iterating over this varibale and printing a new line
    for (int line = 0; line < height; line++)
    {
        for (int dots = height - line; dots > 1; dots--)
        {
            printf(" ");
        }
        // iterating over hashes and printing a hash symbol
        for (int hashes = 0; hashes <= line; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
