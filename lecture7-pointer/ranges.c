#include <limits.h>
#include <stdio.h>

int main ()
{
    // min and max value of a type
    // the use of macro variables
    printf("%d %d\n", SHRT_MIN, SHRT_MAX); // -32768 32767
    printf("%d %d\n", INT_MIN, INT_MAX); // -2147483648
    printf("%ld %ld\n", LONG_MIN, LONG_MAX); // -9223372036854775808 9223372036854775807

    return 0;
}