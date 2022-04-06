#include <stdio.h>

int main()
{
    int myNum = 10;

    // postfix expression & evaluation
    printf("%d\n", myNum);   // 10
    printf("%d\n", myNum++); // 10
    printf("%d\n", myNum);   // 11

    printf("%d\n", myNum);   // 11
    printf("%d\n", myNum--); // 11
    printf("%d\n", myNum);   // 10

    /**
     * postfix operation evaluates the new value after that block of code
     */

    return 0;
}