#include <stdio.h>

int main()
{
    // declare a variable & assign integer 20 to that variable
    int myVar = 20;

    // write if (some condition to be evaluated to boolean value) & else statement
    if (myVar == 20)
    {
        // since 20 was indeed assigned to myVar, whatever is inside this bracket will be executed
        printf("The value of myVar is : %d.\n", myVar);
    }
    else
    {
        // since myVar is 20 and not anything else, this will not be executed
        printf("The value of myVar is not 20.\n");
    }

    return 0;
}