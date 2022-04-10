#include <stdio.h>

int main()
{
    // declare a variable & ask user to input the value of x
    // we will have the type of x pre-defined as integer
    int userValue;
    printf("What is your favorite integer ? (ex: -10, 0, 4, 220, ...) : ");
    // value input function via terminal (in this case by user)
    scanf("%d", &userValue);
    // Now, userValue has been assgined of a value integer
    // if user types something other than integer typed value, userInput will be assigned some integer 327..
    printf("Ok, user! Your favorite integer is : %d\n", userValue);

    // apply conditional statements
    if (userValue == 20)
    {
        printf("Lucky! your favorite integer is exactly 20. Same as mine ✋!\n");
    }
    else if (userValue < 20)
    {
        printf("Your favorite number is less than my favorite number : %d < 20.\n", userValue);
    }
    else
    {
        printf("Your favorite number is greater than my favorite number : %d > 20.\n", userValue);
    }

    return 0;
}