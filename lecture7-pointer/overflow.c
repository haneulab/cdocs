#include <stdio.h>

// conventional sizes
// char 1 byte
// short 2 bytes
// int 4 bytes
// long 8 bytes

// the more byte a type is, the more range of values that type can support


int main ()
{
    int x = 1000000000;
    int y = 5;

    // overflow calculation
    printf("overflow : %d\n", x * y);
    

    return 0;
}