// Determines if a credit card number is valid, and whether it is a Visa, Mastercard, or American Express number.
// Uses helper functions from CS50 library

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize variables
    // Note: references to "even-indexed digits" are based on  the last digit being index 1 (odd), second-last digit index 2 (even), etc.
    int sum_even_digits = 0;
    int sum_odd_digits = 0;
    long card_number;
    int length = 0;
    int first_digit = 0;
    int second_digit = 0;

    do
    {
        // Prompt user for card number
        card_number = get_long("Number: ");
    }
    // Continue prompting until input is greater than 0
    while (card_number <= 0);

    // Loop through digits of card number while there is at least a single digit
    while (card_number > 0)
    {
        // Check if digit is the first digit
        if (card_number >= 0 && card_number <= 9)
        {
            first_digit = card_number;
        }

        // Check if digit is the second digit
        if (card_number >= 10 && card_number <= 99)
        {
            second_digit = card_number % 10;
        }

        // Check if even-indexed digit (from the back)
        if (length % 2 != 0)
        {
            // Check if twice the current digit is a two-digit number
            if (card_number % 10 * 2 >= 10)
            {
                // Split the two-digit number and add individual digits to sum of even-indexed digits
                sum_even_digits += card_number % 10 * 2 % 10 + 1;
            }

            // If twice the current digit is a one-digit number, add twice the digit to sum of even-indexed digits
            else
            {
                sum_even_digits += card_number % 10 * 2;
            }
        }

        // If odd-numbered digit (from the back), add to sum of odd-indexed digits
        else
        {
            sum_odd_digits += card_number % 10;
        }

        // Increment length of number
        length++;

        // Truncate the last digit of the card number and continue the loop
        card_number /= 10;
    }

    // Add the sum of even-indexed digits to the sum of odd-indexed digits
    sum_odd_digits += sum_even_digits;

    // Check if final sum is divisible by 10
    if (sum_odd_digits % 10 != 0)
    {
        // If it is not, the card is invalid; stop program
        printf("INVALID\n");
        return 0;
    }

    // Check if card is an American Express
    else if (length == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
    {
        printf("AMEX\n");
    }

    // Check if card is a MasterCard
    else if (length == 16 && first_digit == 5 && second_digit >= 0 && second_digit <= 5)
    {
        printf("MASTERCARD\n");
    }

    // Check if card is a Visa
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
