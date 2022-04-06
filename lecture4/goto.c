#include <stdio.h>

int main()
{
    int userAge;
    printf("Enter your age : ");
    scanf("%d", &userAge);

    if (userAge >= 21)
    {
        printf("You are able to drink alcohol.\n");
    }
    else if (userAge < 21 && userAge > 0)
    {
        printf("Your cannot yet drink, please wait till you turn 21.\n");
    }
    else
        goto end;

    return 0;

end:
    printf("It seems like you typed invalid age value. Your age must be greater than 0.\n");
    return 0;
}