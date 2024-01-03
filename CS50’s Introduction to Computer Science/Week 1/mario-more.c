#include <cs50.h>
#include <stdio.h>
int get_height(void);
void print_pyramid(int height);

int main(void)
{
    // prompt height of bricks
    int height = get_height();

    print_pyramid(height);
}

int get_height(void)
{
    int height;
    do // repeat itself until it says a number from 1 to 8 inclusive
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        // print spaces
        for (int s = height - i - 1; s > 0; s--)
        {
            printf(" ");
        }
        // print left hashes
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        // print gap (equals two dots)
        printf("  ");
        // print right hashes
        for (int r = 0; r <= i; r++)
        {
            printf("#");
        }
        printf("\n");
    }
}