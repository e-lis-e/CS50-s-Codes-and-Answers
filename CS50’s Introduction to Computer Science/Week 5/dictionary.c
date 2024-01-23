// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

unsigned int wordC = 0;

const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);

    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hashVal = 0;
    for (int i = 0; i < 3 && word[i] != '\0'; i++)
    {
        hashVal = (hashVal << 2) ^ tolower(word[i]);
    }
    return hashVal % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *newNode = malloc(sizeof(node));

        if (newNode == NULL)
        {
            unload();
            fclose(file); // Close the file before returning false
            return false;
        }

        strcpy(newNode->word, word);
        newNode->next = NULL; // Initialize the next pointer

        unsigned int hashI = hash(newNode->word);

        node *head = table[hashI];
        newNode->next = head; // Update the next pointer for the new node
        table[hashI] = newNode;
        wordC++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordC;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;

            cursor = cursor->next;

            free(temp);
        }
        table[i] = NULL;
    }

    // Check if all memory has been successfully deallocated
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            return false;
        }
    }

    return true;
}
