#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // open memory card
    FILE *inptr = fopen("card.raw", "r");
    // checking if the file is null
    if (inptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "FileNameError: Can not open the filename...\nTry usage: ./recover filename.raw");
        return 1;
    }

    // Allocate memory for 512 byte chunks
    unsigned char buffer[512];

    // How many jpgs found
    int counter = 0;

    // Current filename and img
    char name[10];
    FILE *img;

    // Read until end of card
    while (fread(&buffer, 512, 1, inptr))
    {
        // find a new jpg file in a sequence
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && buffer[3] >> 4 == 0xe)
        {
            // Found jpg increment counter
            counter++;

            // Close prev file (if any)
            if (counter > 1)
            {
                fclose(img);
            }

            // Open new file and write first buffer
            sprintf(name, "%03d.jpg", counter - 1);
            img = fopen(name, "a");
        }

        // If currently writing to file, write buffer
        if (counter > 0)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }

    // close any remaining files
    fclose(img);
    fclose(inptr);
    return 0;
}