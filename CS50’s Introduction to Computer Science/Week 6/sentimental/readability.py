from cs50 import get_string


def count_letters(text):
    numle = 0
    for char in text:
        if char.isalpha():
            numle += 1
    return numle


def count_words(text):
    numwo = 1
    for char in text:
        if char.isspace():
            numwo += 1
    return numwo


def count_sentences(text):
    numsen = 0
    for char in text:
        if char in ['!', '.', '?']:
            numsen += 1
    return numsen


text = get_string("Text: ")

l = count_letters(text)

w = count_words(text)

s = count_sentences(text)

letters = l/w * 100

sentences = s/w * 100

index = round(0.0588 * letters - 0.296 * sentences - 15.8)

if index > 16:
    print("Grade 16+")
elif 1 <= index <= 16:
    print(f"Grade {index}")
else:
    print("Before Grade 1")
