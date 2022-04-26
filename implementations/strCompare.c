#include <stdio.h>
#include <string.h>

int strCompare(char *str1, char *str2);

int main()
{
    char s1[] = "Hello";
    char s2[] = "hello";
    char s3[] = "Hello";

    printf("%d\n", strCompare(s1, s2)); // expect 1 not equal
    printf("%d\n", strCompare(s1, s3)); // expect 0 equal

    return 0;
}