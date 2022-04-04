#include <stdio.h>
#include <string.h>

int main()
{
    // receiving character & characters as a userInput

    // any value user will assign to this variable must be something like 'a', '1', 'X', '@', ...
    char userInputSingleChar;
    printf("Hey, user! Please enter your favorite single character : ");
    scanf("%c", &userInputSingleChar);

    // any value user will assign to this variable must be something like anything above or 'ab2', 'adb2@9B', '123'
    // it cannot recieve a combinations of words with spaces like 'hello world'
    char userInputMultipleChar[31];
    printf("Hey, user! now you should enter a set of characters (without space) whose length is less than or equal to 30 characters :");
    scanf("%s", userInputMultipleChar);

    // print two variables
    printf("Single Chracter : %c.\nMultiple Characters : %s.\n", userInputSingleChar, userInputMultipleChar);

    return 0;
}