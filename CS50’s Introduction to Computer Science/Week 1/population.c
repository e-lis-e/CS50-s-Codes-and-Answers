#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    long ss;
    do
    {
        ss = get_long("Start size: ");
    }
    while (ss < 9);


    // TODO: Prompt for end size
    long es;
    do
    {
        es = get_long("End size: ");
    }
    while (es < ss);


    // TODO: Calculate number of years until we reach threshold
    long numyears = 0;
    while (ss < es)
    {
        ss = ss + (ss / 3) - (ss / 4);
        numyears++;

    }




    // TODO: Print number of years
    printf("Years: %li\n", numyears);

}
