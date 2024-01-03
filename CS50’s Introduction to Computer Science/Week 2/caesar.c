#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // error basics
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: /caesar key\n");
            return 1;
        }
    }
    // receive input and plaintext
    int n = atoi(argv[1]);

    string ptext = get_string("plaintext:  ");

    // print the needed ciphertext
    printf("Ciphertext: ");

    for (int j = 0; j < strlen(ptext); j++)
    {
        if (isupper(ptext[j]))
        {
            printf("%c", (ptext[j] - 65 + n) % 26 + 65);
        }

        else if (islower(ptext[j]))
        {
            printf("%c", (ptext[j] - 97 + n) % 26 + 97);
        }
        else
        {
            printf("%c", ptext[j]);
        }
    }
    printf("\n");
    return 0;
}