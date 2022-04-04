#include <stdio.h>

int main()
{
    int userAge;
    char userFirstName[21], userLastName[21];

    // Welcome the user!
    printf("Welcome User!\n");

    // ask your first and last name
    printf("user, what is your first name? : ");
    scanf("%s", userFirstName);
    printf("and your last name? : ");
    scanf("%s", userLastName);

    // ask your age and now call the user by their name.
    printf("%s, how old are you ? ", userFirstName);
    scanf("%d", &userAge);

    // confirm user data
    printf("%s %s, you are %d years old!\n", userFirstName, userLastName, userAge);

    // implement if & else statement with thier age
    if (userAge == 21)
    {
        printf("You turned 21 recently, Let's go to vegas!\n");
    }
    else if (userAge > 21)
    {
        printf("You are well over 21! Let's go grab a bottle of soju.\n");
    }
    else
    {
        printf("Since you cannot drink alcohol yet, let's go drink a strawberry milk or orange juice.\n");
    }

    return 0;
}