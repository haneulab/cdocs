#include <stdio.h>

int main()
{
    // // buffer problem
    // char target1, target2;
    // printf("Enter first character: ");
    // scanf("%c", &target1);

    // printf("Enter second character: ");
    // scanf("%c", &target2);
    // printf("t1 : %c, t2 : %c\n", target1, target2);

    // fix buffer problem
    char target1, target2;
    printf("Enter first character: ");
    scanf("%c", &target1);

    printf("Enter second character: ");
    scanf(" %c", &target2);

    printf("t1 : %c, t2 : %c\n", target1, target2);

    // null byte innclusive : 21 characters (20 characters from user)
    char buf[21];
    do
    {
        printf("Enter string: ");
        scanf("%s", buf);
    } while (buf[4] != target1 && buf[4] != target2);

    return 0;
}