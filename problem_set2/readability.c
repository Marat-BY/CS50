// connectin all the libriaries that are needed for the program
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// main function declatation
int main(void)
{

    // Coleman-Liau Index Formula (CLI)
    // CLI = 0.0588 * L - 0.296 * S - 15.8
    // L - is average number of letters per 100 words
    // S - is average number of sentences per 100 words


    // variable letters that will store the number of letters in the text
    float letters = 0;

    // variable words that will store the number of words in the text
    float words = 1;

    // variable sentences that will store the number of sentences in the tex
    float sentences = 0;

    // create an empty variable to store future CLI index
    float cli = 0;

    // initialising the array of sentence termination characters
    char sentence_termination[] = {'.', ';', '!', '?'};

    // prompt the text from user
    string text = get_string("Text: ");

    if (text[0] != '\0')
    {
        // Counting all declared variables that are needed for calculation of the CLI index
        for (int i = 0; i < strlen(text); i ++)
        {
            // counting the number of letters by comparing if the beggining starts with ASCII characters

            if (isalnum(text[i]))
                // ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            {
                letters++;
            }
            // counting the number of words by checking if the word ends with termination or space character
            if (i < strlen(text) - 1 && isspace(text[i]) && isalnum(text[i + 1]))
            {
                words++;
            }
            // counting the number of sentences
            if (i > 0 && (text[i] == '!' || text[i] == '?' || text[i] == '.') && isalnum(text[i - 1]))
            {
                sentences++;
            }
        }
    }
    else
    {
        printf("You entered text is empty. End of the program. Exit...\n");
    }

    // Calculating the Coleman-Liau Index for readability:
    cli = lround(0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8);

    // Getting the result to the user. The result is a CLI index based on cli variable ca
    if (cli >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (cli <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", cli);
    }

    //printf("Quantity of Letters: %f\nQuantity of Words: %f\nQuantity of Sentences: %f\n", letters, words, sentences);
}