#include <stdio.h>

int main ()
{
    // printf("AAA\n");
    // int x = 5 / 0;
    // printf("BBB\n");

    // buffered state still till the crash occurs
    //  AAA not outputed due to the fact that it got dumped from the buffer container when the crash happened
    printf("AAA");
    int x = 5 / 0;
    printf("BBB\n");

    return 0;
}