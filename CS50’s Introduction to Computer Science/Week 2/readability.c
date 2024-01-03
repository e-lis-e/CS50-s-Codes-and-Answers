#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int L = count_letters(text), W = count_words(text), S = count_sentences(text);

    float letters = (float) L / (float) W * 100;

    float sentences = (float) S / (float) W * 100;

    int index = round(0.0588 * letters - 0.296 * sentences - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text)
{
    int numle = 0;
    int value = strlen(text);
    for (int i = 0; i < value; i++)
    {
        if (isalpha(text[i]))
        {
            numle++;
        }
    }
    return numle;
}

int count_words(string text)
{
    int numwo = 1;
    int value = strlen(text);
    for (int i = 0; i < value; i++)
    {
        if (isspace(text[i]))
        {
            numwo++;
        }
    }
    return numwo;
}

int count_sentences(string text)
{
    int numsen = 0;
    int value = strlen(text);
    for (int i = 0; i < value; i++)
    {
        if ('!' == text[i] || '.' == text[i] || '?' == text[i])
        {
            numsen++;
        }
    }
    return numsen;
}