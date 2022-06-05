/**
 * @file conditional.c
 * @author Casey Anno
 * @brief discussing conditional statements that include:
 *  if, else if, else
 * Ternary/conditional operator
 * Logical operators: &&, ||, !
 * switch statements
 * includes examples of using printf and scanf as well
 * @date 2022-6-05
 * 
 * @copyright Copyright (C) 2022
 * 
 */
#include <stdio.h>


/** 
 * @brief if, else if, else:
 * 
 * In if statements, there will be a condition that will be checked. If it is true, then
 * it will execute what is contained within the if block. If the condition is false,
 * it will not execute. In that case, we want an else statement to execute code for when the
 * initial condition is false. For example:
 */
int main()
{
    int x = 0;
    if (x == 1)
    {
        // if condition is true, which it's not,
        // this part of the code will execute
        printf("x is 1.\n");
    }
    else
    {
        // if initial condition is false,
        // this part of the code will execute instead.
        printf("x is not 1.\n");
    }

// If you want to check multiple specific conditions, you can use an 'else if' statement as well:
    int y = 20;
    if (y == 10)
    {
        printf("y is 10.\n");
    }
    else if (y == 20)
    {
        printf("y is 20.\n");
    }
    else
    {
        printf("y is not 10 or 20.\n");
    }




/** 
 * @brief Ternary/conditional operator:
 * 
 * This is basically a shorter way to write if else statements. it is in the form
 * variable = Expression1 ? Expression2 : Expression3
 * where if Expression1, then Expression2. Else, Expression3. 
 * It simplifies many lines into 1. Example:
*/
    int a = 10, b = 20;
    (a > b) ? printf("%d > %d\n", a, b) : printf("%d > %d\n", b, a);
    // for printf, we use '%d' to print out integers, associating them with the variable we want
    // to specify after the closed double quotes. '%s' is used for strings, '%c' for characters.




/**
 * @brief Logical operators &&, ||, and !: 
 * 
 * && is used for saying 'and'
 * || is used for saying 'or'
 * ! is used for saying 'not' 
 * Example:
*/
    int m = 20, n = 25;
    if (m == 20 && n == 20)
    {
        // This code would not execute because it checks if 
        // both m and n are equal to 20, which they're not
    }
    else if (m == 20 || n == 20)
    {
        // This code would execute because if either m is 20
        // OR n is 20, then it's true.
    }
    else if (!(m == 25) && n == 25)
    {
        // if it wasn't the case that the previous block executed,
        // and m was not 25, this block would execute because it's
        // true that m is not 25 and that n is 25.
    }
    else
    {
        // Again, if nothing above was true, this would be the
        // code that executes.
    }



/**
 * @brief Switch statements:
 * 
 * Switch statements can be used for a lot of different cases in shorter syntax than if 
 * statements. For example, using the 'scanf' command, which reads user input and becomes the
 * value we compare with, we can create a series of switch statements to print certain
 * things based on what they input:
 */
    int x = 0;
    scanf("%d", &x);

    switch (x)
    {
        case 10:
        // the syntax below (commented out) can be used for checking 2 values at once.
        // case 10: case 40:
            // printf("You entered 10 or 40.\n");
            printf("You entered 10.\n");
            break;
        case 20:
            printf("You entered 20.\n");
            break;
        case 30:
            printf("You entered 30.\n");
            break;
        case 50:
            printf("You entered 50.\n");
            break;
        // the default is the code that executes if the user input did not match any of our  
        // previous cases:
        default:
            printf("blah blah blah\n");
            break;
    }
    
    return 0;
}


/**
 * @brief Sources:
 * https://www.geeksforgeeks.org/c-c-if-else-statement-with-examples/ 
 * https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/ 
 */
