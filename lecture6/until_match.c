#include <stdio.h>

int main()
{
    char target1, target2;
    printf("Enter first character: ");
    scanf("%c", &target1);
    printf("Enter secoond character: ");
    scanf(" %c", &target2);

    char buf[21];
    do
    {
        printf("Enter string: ");
        scanf("%s", buf)q;
    } while (buf[4] != target1 && buf[4] != target2);
}