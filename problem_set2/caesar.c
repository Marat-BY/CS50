// importing libriaries and modules
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

// main function declaration but with int argument character and string argument vector
int main(int argc, string argv[])
{
    // validation of correct input if not print the input form
    if (argc == 2 && isdigit(*argv[1]))
    {
        // prompt from user a caesar k-value for cipher
        int k = atoi(argv[1]);

        // prompt the text from user that's need to be encrypted
        string text = get_string("text: ");

        // output of encrypted text
        printf("ciphertext: ");

        // iteration process letter by letter in the plain text
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // if it is lowercase 97 = a to 112 = z and if it upper +13 characters along
            // Figuring out whether uppercase or lowercase and Iteration through each letter
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                // print out lowercase with key
                printf("%c", (((text[i] - 'a') + k) % 26) + 'a');
            }
            // if it it between uppercase A and C
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                // print out uppercase with key
                printf("%c", (((text[i] - 'A') + k) % 26) + 'A');
            }
            else
            {
                // just print the character for example it might be !,?... and etc.
                printf("%c", text[i]);
            }
        }

        printf("\n");
        return 0;
    }
    else
    {
        // if user entered command incorrectly output the form of how to prompt
        printf("Usage: ./caesar k\n");
        return 1;
    }
}