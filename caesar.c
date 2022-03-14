#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//argc = integer that stores how many words as a prompt
//argv = argument vector; an array of all the words the human type
//Computer will store everything the human writes in an array called argv
//& will tell us how many words there are in argc
int main(int argc, string argv[])
{
    //If not 2 arrays, will not work
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //DON'T PUT A RETURN HERE!!! IT WILL END THE CODE

    string key = argv[1];

    //Make sure that anything in the 2nd array is a # and not an alphabet
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        //CHECK EACH LETTER OF THE ARRAY.
        //./caesar 50xabd --> 0 = ./caesar, 1 = 50xabd; [i] = 5, 0, x, a, b, d
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Prompt user for a plaintext
    string plaintext = get_string("plaintext: ");

    //Convert the string to an int, which we will use to make the cyphertext off of
    int k = atoi(argv[1]);

    //Do this first... for the entire string to be recalled throughout the loop
    printf("ciphertext: ");

    //Go through each letter of the plaintext
    //c = (p + k) % 26
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if isupper(plaintext[j])
        {
            //Do not need to reprint "ciphertext after printf
            printf("%c", ((plaintext[j] + k - 65) % 26) + 65);
        }

        else if islower(plaintext[j])
        {
            printf("%c", ((plaintext[j] + k - 97) % 26) + 97);
        }

        else
        {
            printf("%c", plaintext[j]);
        }
    }
    //"\n" creates a new vertical space.
    printf("\n");
//Having ciphertext = ((plaintext[j] + k - 65) % 26) + 65;
//and printf("ciphertext: %c\n", ciphertext); does not work... only prints last #
}