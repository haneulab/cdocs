**filename** : **iterative_statements.md**

**author** : **Dave Nguyen** [hxnguyen@ucdavis.edu](hxnguyen@ucdavis.edu)

**brief** : explain different types of loops and its functions.

**date** : **06/05/2022**

# Loops
Loops are essential tool that all coders/hackers/programmers/"whateever names we have" need. As like Python, the 2 main loops in C are `while` and `for` loop. Additionally, the `do while` loop is a little specific in it functionality, thus more examples are provided for better details. The goal is to help coders understand their functionalities and their differences.  
In general, loops are ways coder use to **repeat** certain actions based on **the condition** the loop are given

### while(condition)
Allow you to repeat actions while the **condition** is true. If the condition is met(*true*), we enter the while loop. Once you get to the end of the while loop, you go back to the top of the loop. This keeps repeating until the condition becomes *false*.
**Example** if we want to print numbers from 1 to 10 in order:
```c
#include <stdio.h>

int main()
{
    // declaring variable i 
    int i = 1;

    // while(condition: i < 11)
    while (i < 11)
    {
        // we prints the variable i
        printf("i = %d\n", i);
        i++; // incrementing (increasing) i and repeat the print statement
    }
    return 0;
}
```
The output would be:
```
$ gcc -g -Wall -Werror while_loop.c -o while_loop
$ ./while_loop
1
2
3
4
5
6
7
8
9
10
```

### for(init; condition; update)
The difference between for loop and while loop is just *fancy* by *Iggy Azalea* (get it..... cause `for` loop is fancy and ... `while` loop is not) Anyway, if you like convenience store, you would love the for loop. Since while loop can only take in 1 `condition` and user have to manually update the condition in order to avoid **infinite loop** (future discussion), for loop allow users to update the condition within the loop itself, using arguments `init` and `update`. The syntax is 
```c
for (init, condition, update)
{
    //code!
}
``` 
`init` is a variable that the for loop use to iterate. Typically, this would be a number. But on a higher level, variable "that loop use to iterate" can take many forms. `update` is a condition that affect the `init` after each iteration. We want `update` in our for loop so the loop doesn't become an infinite loop (future discussion). `Init` and `update` are optional. Any variables declared in `init` last only for the duration of the for loop. 
**Example** we want to print different characters `abcde` 
```c
#include <stdio.h>
//for_loop.c
int main() 
{
    // declaring varible
    char s[] = "abcde";

    for (int i = 0; i < 5; ++i) // for (init, condition, update)
    /*
        int i = 0; i < 5; ++i
        1st condition: The init expression is run before the loop starts and is always run
        2nd condition: the condition checks the loop's condition during its iteration
        3rd condition: the condition that is done after each iteration
    */
    {
        printf("%c\n", s[i]); // print the character in string s
    }
```
the output would be:
```
$ gcc -g -Wall -Werror for_loop.c -o for_loop
$ ./for_loop
a
b
c
d
e
```

### do{} while(condition) loop
A do while loop is like a while loop except that the code inside of the do loop is **always run at least once**. A way to visualize the order of operation:
```c
do
{
    //this code runs first
}while(1) // while condition is true, it goes back to the do loop code
``` 
**example** we want to print number 10:
```c
#include <stdio.h>
// do_loop.c
int main ()
{
    //declare variable
    int i = 10;

    //here comes the magic
    do
    {
        printf("i = %d\n", i);
        ++i;
    } while(i < 10)
    // what is the output?
}
```
The output would be:
```
$ gcc -g -Wall -Werror do_loop.c -o do
$ ./do
10
```
The result is 10 is because the `printf("i = %d\n", i);` in the do loop runs first. The condition in the while loop is considered, and since it is not true, the loop breaks. *which leads us to our next topic: break;*

##### Side Note*
`Condition` in a loop can be *True* or *False*. *True* can be expressed any nonzero numbers, such as 1. *False* can be expressed as 0. Code often use this for better logical thinking, or just plain lazy sometime. *(Nothing is wrong with being lazy)*  

### break;
Causes the loop to immediately stop running. Usually appear inside of a loop (can't run outside of a loop). 
**example** We want the user to guess a number. 
```c
#include <stdio.h>

int main()
{
    //declaring variables
    int num = 0;
    while(1) // nonzero means true, zero means false
    {
        printf("Enter a number: ")
        scanf("%d", &num); // getting the numbers <3
        
        //if num is less than 0
        if(num == 10) 
        { 
            printf("you enter number: %d. This is what I want (<3).\n", num);
            break;
        }
        else // num is not less than 0
        {
            printf("This is not what I want. Try Again.... please!\n");
        }
    }
    return 0;
}
```
If we run this program, the output would be
```
$ gcc -g -Wall -Werror break.c 
$ ./a
Enter a number: 5
This is not what I want. Try Again.... please!
Enter a number: 6
This is not what I want. Try Again.... please!
Enter a number: 7
This is not what I want. Try Again.... please!
Enter a number: 1
This is not what I want. Try Again.... please!
Enter a number: 2
This is not what I want. Try Again.... please!
Enter a number: 3
This is not what I want. Try Again.... please!
Enter a number: 10
you enter number: 10. This is what I want (<3).
```

### continue;
Cause the loop to run the next iteration when encounter. This is the key difference between `break` and `continue`. 
**example** the following code:
```c
#include <stdio.h>

int main()
{
    // declare i. We use i for the for loop
    // This wil make sure that i still exist after the for loop
    int i;

    for(i = 0; i < 10; ++i)
    {
        if(i % 2 == 0) // if the remainder of i and 2 is equal to 0
        {
            continue; // continue is called, next iteration continues.
        printf("i = %d\n", i);
        // can you guess what is the output?
    }
}
```
the output after compilation would be:
```
$ gcc continue_statement.c -o continue_statement
$ ./continue_statement
i = 1
i = 3
i = 5
i = 7
i = 9
```
The continue statement make sure that even numbers between 0 and 10 are skipped. Therefore, the output prints the odd numbers only. 

***Online Resources*** 
*Some online resources that might be helful*
- [C for loop](https://www.programiz.com/c-programming/c-for-loop)
- [for loop](https://www.w3schools.com/c/c_for_loop.php)
- [C - loop](https://www.tutorialspoint.com/cprogramming/c_loops.htm)
- [Loops in C: For, While, Do While looping Statements](https://www.guru99.com/c-loop-statement.html)
