#include <stdio.h>

int main ()
{
    int userInt;
    printf("Hello! enter any integer from 1 to 3.\n");
    scanf("%d", &userInt);


    printf("=== If statement ===\n");
    // if statemnt to check the value
    if (userInt == 1)
    {
        printf("Your integer was 1\n");
    }
    else if (userInt == 2)
    {
        printf("Your integer was 2\n");
    }
    else if (userInt == 3)
    {
        printf("Your integer was 3\n");
    }
    else
    {
        printf("Your integer is not either 1,2, or 3.\n");
    }


    printf("=== Switch statement ===\n");
    // using switch statement to do the same as above
    switch (userInt)
    {
        case 1:
            printf("your integer was 1\n");
            break;
        case 2:
            printf("Your integer was 2\n");
            break;
        case 3:
            printf("Your integer was 3\n");
            break;
        default:
            printf("integer you typed is not either 1,2, or 3.\n");
            break;
    }  

    return 0;
    
}