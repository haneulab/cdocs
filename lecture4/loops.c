#include <stdio.h>

int main ()
{
    // define any length of characters
    char myChars[] = "abcde";
    int myCharsLength = 5;

    // define initial index
    int index = 0;

    // use while loop over the characters and print each char
    while (index < myCharsLength)
    {
        // print the character at current length (index)
        printf("(while loop) Current Character : %c\n", myChars[index]);

        // proceed by increasing the index + 1
        index = index + 1;
    }

    // use forloop to do the same
    // we will declare the index & increament within the statement below
    // for (int index = initialValue; index < execlusive maximum value; increament statement index = index + 1)
    for (int forIndex = 0; forIndex < myCharsLength; forIndex = forIndex + 1)
    {
        printf("(for loop) Current Character : %c\n", myChars[forIndex]);
    }

    return 0;
}