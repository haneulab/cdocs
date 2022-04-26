#include <stdio.h>

int len(char *str);

int main()
{
    char str1[] = "Hello";
    char str2[] = "apple";
    char str3[] = "Hi";

    printf("%s & %s have the same length : %d\n", str1, str2, len(str1));
    printf("%s & %s do not have the same length : %d %d\n", str1, str3, len(str1), len(str3));

    return 0;
}