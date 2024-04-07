from cs50 import get_int


def luhn_algorithm(card):
    # Convert card number to string for easier manipulation
    card_str = str(card)

    # Initialize variables for the sum and the flag to alternate multiplication by 2
    total_sum = 0
    multiply_by_2 = False

    # Iterate through the card digits from right to left
    for digit in reversed(card_str):
        digit = int(digit)

        if multiply_by_2:
            # Multiply every other digit by 2 and add the digits of the product
            digit *= 2
            digit = digit // 10 + digit % 10

        # Add the current digit to the total sum
        total_sum += digit

        # Toggle the flag for the next iteration
        multiply_by_2 = not multiply_by_2

    # Check if the total sum's last digit is 0
    return total_sum % 10 == 0


# Get the credit card number from the user
card = get_int("Number: ")

# Check the length and apply Luhn's algorithm
if len(str(card)) in [13, 15, 16] and luhn_algorithm(card):
    if len(str(card)) == 15 and (str(card).startswith("34") or str(card).startswith("37")):
        print("AMEX")
    elif len(str(card)) == 16 and str(card).startswith(("51", "52", "53", "54", "55")):
        print("MASTERCARD")
    elif (len(str(card)) == 13 or len(str(card)) == 16) and str(card).startswith("4"):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
