from cs50 import get_int

height = get_int("Height: ")

while height not in range(1, 9):
    height = get_int("Height: ")

# generate the half pyramids with loops and prints


def print_pyramid(height):
    for i in range(height):
        # print spaces
        for j in range(height - i - 1):
            print(" ", end="")

        # print left hashes
        for k in range(i + 1):
            print("#", end="")

        # print gap (equals two dots)
        print("  ", end="")

        # print right hashes
        for l in range(i + 1):
            print("#", end="")

        print()


print_pyramid(height)
