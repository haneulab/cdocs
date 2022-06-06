**filename** : **standard_error.md**

**author** : **Haneul Choi** [hanchoi@ucdavis.edu](hanchoi@ucdavis.edu)

**brief** : exploring the basic understanding & usage of standard error `stderr`

**date** : **06/05/2022**

# Standard Error

Hopefully, you've read `standard_error.md` file before reaidng this. If not, you can do it now!

**NOW**, just like standard output, we want our programs to notify the programmer if there is a certain error-like behavior while running the program.

For example, you are supposed to receive integer greater than 0 but received -1. Something like this causes the program either to crash or behave unexpectedly after then. So we as programmers want to make sure if there is some erorr, we want to know, or let the users know, what the error was about and why it was caused.

This is where `stderr` comes play.

For `stdout` or standard ouputs, the indicator was 1. So it makes sense that we define the indicator for standard error as something other than 1. It turns out that programmers decide to agree that the indicator code for standard eror or `stderr` set to be 2.

So far the indicator list that we can now remember is

- 1: standard output
- 2: standard error

Now take a look at the example program below

```c
/* main.c */
#include <stdio.h>

int main()
{
    int positiveNum;

    // user input comes here
    printf("User, please type positive integer\n");
    scanf("%d\n", &positiveNum);

    if (positiveNum <= 0)
    {
        // if user types non-positive number, we should treat that as error in our program
        fprintf(stderr, "You entered %d, which is a non-positive number.\n", positiveNum);
        return 2;
    }

    // if user types positive number as prompted
    printf("You entered a positive number : %d.\n", positiveNum);
    return 0;
}
```

```bash
# compile main.c
gcc main.c -o ./a.out
```

Now take a look at the following two cases when the program runs but for **case 1** user enters positive number (which the program asks for) and **case 2** where the user enters negative number (which the program should output the standard error)

```terminal
# case 1: user types positive number
./a.out
User, please type positive integer : 10
You entered a positive number : 10 // this line is the standard OUTPUT
```

```terminal
# case 2: user types negative number
./a.out
User, please type positive integer : -5
You entered -5, which is a non-positivie number. // this line is the standard ERROR
```

Now, botht types `stdout & stderr` outputs in the terminal regardless of its type. **Now what if we want to redirect them into separate files or put some distinguishable output strategies depending on the type (stdout, stderr)?** Well, it turns out that that is the most effective way to separate these types.

In the following file `redirection.md`, we will learn how to redirect both `stdout` and `stderr` into different files or possibly trash them in some garbage bin so that we can now store them in designated location in our computer without having to keep printing them in the terminal without any distinguishion between them.
