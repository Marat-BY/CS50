// including standard libriaries
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // declaring variable height for user's unput
    int height;
    // warn the user of value's range
    printf("Enter a value in range of 0 and 8.\n");


    // prompt from user a valid value until done
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

        for (int spaces = 0; spaces <= height; spaces++)
        {
            printf(" ");
        }
        for (int second = 0; second <= line; second++)
        {
            printf("#");
        }
        printf("\n");
    }

}