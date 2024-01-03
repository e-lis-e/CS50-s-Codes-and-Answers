#include <cs50.h>
#include <stdio.h>

int checksum(long long number);
int multiplyandsum(int last_digit);
int get_length(long long number);

int main(void)
{
    // Prompt for input
    long long number = get_long_long("Number: ");

    int length = get_length(number);

    int result = checksum(number);

    if (result % 10 == 0)
    { // if the correct size and starting number is met, print AMEX
        if ((length == 15 && (number >= 34e13 && number < 35e13)) || (number >= 37e13 && number < 38e13))
        {
            printf("AMEX\n");
        } // if the correct size and starting number is met, print MASTERCARD
        else if ((length == 16 && (number >= 51e14 && number < 56e14)))
        {
            printf("MASTERCARD\n");
        } // if the correct size and starting number is met, print VISA
        else if (((length == 13) && (number >= 4e12 && number < 5e12)) || ((length == 16) && (number >= 4e15 && number < 5e15)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
// calculate checksum
int checksum(long long number)
{
    int sum = 0;
    bool alternatedigit = false;

    while (number > 0)
    {
        if (alternatedigit)
        {
            int last_digit = number % 10;
            int product = multiplyandsum(last_digit);
            sum = sum + product;
        }
        else
        {
            int last_digit = number % 10;
            sum = sum + last_digit;
        }

        alternatedigit = !alternatedigit;
        number = number / 10;
    }

    return sum;
}
// do the multiplying and sum of the needed digits
int multiplyandsum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;

    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;
    }

    return sum;
}
// get the number length
int get_length(long long number)
{
    int length = 0;

    while (number > 0)
    {
        number /= 10;
        length++;
    }

    return length;
}