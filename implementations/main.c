#include <stdio.h>
#include <string.h>

int strCompare(char *str1, char *str2)
{
    if (!(str1 && str2))
        return -1; // return -1 if not comparable

    if (!(strlen(str1) == strlen(str2)))
        return 1; // return 1 if comparable but not matching the length

    int i = 0;

    while (i < strlen(str1))
    {
        if (str1[i] != str2[i])
            return 1; // return 1 if not matched at current index

        i++;
    }

    return 0; // return 0 if every element matched
}

int len(char *str)
{
    if (!str)
        return 0;

    int length = 0;

    while (*str != '\0')
    {
        length++;
        str++;
    }

    str -= length;

    return length;
}