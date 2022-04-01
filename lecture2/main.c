#include <stdio.h>

int main()
{
    // example of variable types (strict types)
    int myInteger = 20;
    char myCharacter = 'x';

    // print variables (with format specifiers)
    // output: The variable values are: 20 x 
    printf("The variable's values are: %d %c\n", 
    myInteger, myCharacter);

    return 0;
}