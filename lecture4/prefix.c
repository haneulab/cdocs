#include <stdio.h>

int main()
{
    int myNum = 10;

    // prefix expression & evaluation
    printf("%d\n", myNum);   // 10
    printf("%d\n", ++myNum); // 11
    printf("%d\n", myNum);   // 11

    printf("%d\n", myNum);   // 11
    printf("%d\n", --myNum); // 10
    printf("%d\n", myNum);   // 10

    /**
     * prefix operation evaluates the new value before that block of code
     */

    return 0;
}