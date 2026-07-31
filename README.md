
# Readability Calculator

A C program that calculates the approximate US grade level needed to comprehend a given text. It evaluates the text using the **Coleman-Liau index**, which relies on the average number of letters and sentences per 100 words.

## 📖 How It Works

The program takes a string of text from the user and counts the number of:
- **Letters:** Any uppercase or lowercase alphabetical character.
- **Words:** Any sequence of characters separated by spaces.
- **Sentences:** Any sequence of characters ending in a period (`.`), exclamation point (`!`), or question mark (`?`).

It then applies the Coleman-Liau index formula:
> `index = 0.0588 * L - 0.296 * S - 15.8`

Where:
* `L` is the average number of letters per 100 words in the text.
* `S` is the average number of sentences per 100 words in the text.

The result is rounded to the nearest integer to determine the grade level.

## ✨ Features
* Custom `string` struct implementation.
* Dynamic memory allocation using `malloc` to safely handle up to 1024 characters of user input.
* Safe standard input reading using `fgets` to prevent buffer overflow.

##🚀 Getting Started

### Prerequisites
You need a C compiler installed on your system, such as `gcc` or `clang`.

### Compilation
To compile the program, run the following command in your terminal. 
*(Note: the `-lm` flag is required in Linux/Unix environments to link the math library for the `round()` function).*

```bash
gcc -o readability readability.c -lm
Usage
Run the compiled executable:

Bash
./readability
Example Run 1:

Plaintext
Enter a text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
Example Run 2:

Plaintext
Enter a text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level.
Grade 11

🛠️ Built With
C - Standard library <stdio.h>, <string.h>, <stdlib.h>, <ctype.h>, <math.h>
