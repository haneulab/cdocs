**filename** : **pointers.md**
**author** : **Haneul Choi** [hanchoi@ucdavis.edu](hanchoi@ucdavis.edu)
**brief** : exploring the basic understanding & usage of pointer variables.
**date** : **06/03/2022**

# Pointers

In this file, we will explore the basic understanding of pointers (variable that points to the address of the variable referred in the memory) compared to normal variables. We will also briefly see the basic usage of pointers.

## What is Pointer?

The term **pointer** is equivalent to saying **variable that stores an address of a normal variable of some type**.

To be more comprehensive, suppose that your `c` program has a variable called `num` that is the `int` type.

```c
int num = 0;
```

When we run the program, our computer needs to store such variables in the designated memory location. That location I will refer as **address** of variable **num**. For us as programmers, it is pretty straight forward that the variable `num` stores an integer type value of `0`. However, for the computer to recall or use **num**, it has to store it somewheere (at the address) which the computer can always refer in order to read and update the value of **num**.

That is the case where pointer is used. **Pointer** is simply a variable type, but special, that we can explicitly be aware of the address of such variable in our computer when running the program.

## Basic Usage

```c
...
int num = 0;

printf("num : %d\n", num); // 0
printf("address of num : %p\n, &num); // 0x7ffd8fb82a68

float pi = 3.14;

printf("pi : %.2f\n" pi); // 3.14
printf("address of pi : %p\n, &pi); // 0x7ffd8fb82a6c
...
```

We can directly access the pointer value of a specific variable `x` by attaching `&` to it. The format specifier that we use to refer to such a pointer value is `%p` regardless of its normal variable type.

Notice how we did not declare pointer variables for `num` and `pi`. Now we will go over how to declare the pointer variable and assigning the variable that you want it to store its address.

```c
...
int num = 0;
float pi = 3.14;

int *numPointer = &num;
float *piPointer = &pi;

printf("%p\n", numPointer); // 0x7ffd8fb82a68
printf("%p\n", piPointer); // 0x7ffd8fb82a6c
...
```

To declare a pointer in your program, we must specify the type of the normal variable it wants to refer to following from `*`.

```c
// good
int *somePointer = &someIntegerVariable;

// bad because missing the pointer sign '*'
int somePointer = &someIntegerVariable;
// bad because missing the pointer reference sign '&'
int *somePointer = someIntegerVariable;
```

## Example Code For Pointer Usage

```c
#include <stdio.h>

int main()
{
    int num = 0;
    float decimalNum = 1.5;
    char character = 'C';

    int *numPtr = &num;
    float *decimalNumPtr = &decimalNum;
    char *charPtr = &character;

    // pointer variables store the 'ADDRESS' of the variable in the memory.
    // meaning that if we print these pointer variables, we should see the address printed
    // we CANNOT use the normal variable type format specifier such as %d %f %c in the printf statement
    // we NEED to use the format specifier for the POINTER written as %p

    printf("variable [num] stored at the address%p\n", numPtr);
    printf("variable [decimalNum] stored at the address%p\n", decimalNumPtr);
    printf("variable [character] stored at the address%p\n", charPtr);

    /**
     * @brief output from the 3 printf statements above
     * variable [num] stored at the address0x7ffd8fb82a68
     * variable [decimalNum] stored at the address0x7ffd8fb82a6c
     * variable [character] stored at the address0x7ffd8fb82a67
     */

    return 0;
}
```
