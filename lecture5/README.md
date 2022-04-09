# Lecture 5

We've talked about more specifics on ascii characters and how in `C` characters are also integers. We also talked about using `float` and `double` types where both are use for floating precision. It is mentioned that `float` uses less memory space because it is less precise than `dobule` and because of this fact, double is better at precision measures although this type takes more space in memory. Also `double` does not fix the fundamental problem that `float` type has (accurate representation of the actual value). It is simply better in some tasks.

We also went over `<ctype.h>` library and some of the useful functions.

Then, we focused on anaylzing the `buffer` causation and fixation when dealing with characters.

---

### ASCII Characters

In order for us to see `ascii` characters table, go to linux command prompt and type the following.

```bash
man ASCII
```

As you may have observed from the table, for each character `char` we can also view its `dec` (decimal code). From the fact that a character in `C` is actualyl integer, we can refer back to this table if you want to see the integer number of a specific character.

Please look at the example below and otice how the `printf` function logs out one same variable into two different types where one as `char` and the other as `int`.

```c
#include <stdio.h>

int main ()
{
    char A = 'A';
    printf("char : %c\ndec : %d\n", A, A);

    char I = 'I';
    printf("char : %c\ndec : %d\n", I, I);

    char K = 'K';
    printf("char : %c\ndec : %d\n", K, K);

    return 0;
}
```

The executable file for this program will print the following.

```bash
char : A
dec : 65
char : I
dec : 73
char : K
dec : 75
```

--- 

### Use of `<ctype.h>`

As our programs get more and more complex, we often find it useful use the functions that other people who have experienced the same problem created for us to use. These are called **Libraries**. When dealing with `char` typed variables, there are many useful functions in `ctype.h` library. 

To import `ctype.h` library into your project, use the `#include` syntax.

```c
// ./main.c

// include useful libraries
#include <stdio.h>
#include <ctype.h>

int main ()
{
    // do something
    return 0;
}
```

Now, we can see what functions there are for us to use. Please pay a closer attention to the `return type` and `argument type` of each function. You will notice that in this specific library, every functions has a `return type : int` and `argument type : int`. We can expect this because we know that in C `char`s are integers.

**`int isupper(int character)`** is a function that checks a given input is an uppercase or not. It will return an integer corresponding the boolean logic for whether the input is uppercase or not.

**`int islower(int character)`** is a function that checks a given input is a lowercase. It is exactly the opposite demonstration of the `isupper` function above.

```c
#include <ctype.h>

int main ()
{
    char capitalA = 'A';
    char lowerB = 'b';

    /*
        running isupper()
    */
    if (isupper(capitalA))
        printf("This will run\n");

    if (isupper(lowerB))
        printf("This wiil NOT run\n");


    /*
        running islower()
    */
    if (islower(capitalA))
        printf("This will NOT run\n");
    
    if (islower(lowerB))
        printf("This will run\n");

    return 0;
}

```

`int isdigit(int character)` is a function that will check if the input is a digit like '5', '0', ... In doing so it will return a non-zero value if it is a digit, otherwise returning 0 (indicating false).

```c
#include <ctype.h>

int main ()
{
    char item1 = '5'; // it is digit
    char item2 = 'V'; // it is not a digit
    char item3 = ' '; // it is not a digit

    printf("item1 : %c : %d\n", item1, item1);
    printf("item2 : %c : %d\n", item2, item2);
    printf("item3 : %c : %d\n", item3, item3);

    return 0;
}
```

There are a lot of functionst that we can learn, please refer to the web documentation [here](https://www.tutorialspoint.com/c_standard_library/ctype_h.htm).

---

### Float & Double

So far, we learned about `int` and `char` but we haven't learned any way to represent a decimal valued items such as something like `5.05`, `0.00`, `0.0000321312312` which we often know as `float`. In `C` we can have two types of decimal represented types `float` & `double`. 

- `float` has a single precision

- `double` has a double precision


When we refer `float` and `double` in `printf` and `scanf` functions we do in using the following symbols in the program.

```c
#include <stdio.h>

int main ()
{
    float itemAPrice;

    printf("Enter the price for item A : ");
    scanf("%f", &itemAPrice);

    float taxRate = 0.08;

    double itemAPriceAfterTax = itemAPrice * taxRate;

    printf("item has a pre-tax price of %.2f\nAfter tax rate of &.2f, item A has price of &.2lf.\n", itemAPrice, taxRate, itemAPriceAfterTax);

    return 0;
}
```

When dealing with `float` and `double`, we also have to understand the difference between `implicit conversation` and `explicit conversion` of types. 

For example, consider we have two `int` variables and attempt to operate division. We know that this calculation can be `float` as in `x.yz` where `x`, `y`, and `z` are 0 or positive integers even thought the variables in the calcuation are `int`;

Thus we explicitly state that output type next to the calcuation statement. We call this `explicit type conversion` in the calculation. Notice that this will not change each of the variable type itself. Is is acted upon the calcuation only.

The following example code shows `explicit conversation`.

```c
int foo = 10;
int bar = 3;

// 10 / 3 => 3.333- 
// should be float after calculation we know this fact explicitly


// explicit implication of float by inputing the type into the calulation.
printf("divide 10 by 3 %.f\n", (float) foo / bar);

```
On the other hand `implicit conversion`, we do not **explicitly** converse the type. Take a look at the following example. 

```c
int foo = 3;
// implicity type conversion (notice there is no float statement in the calcuation)
printF("%f\n", foo / 5);
```

Considering such conversions, sometimes we may make mistake and let the program to **truncate** the type. 

Borrowing the code from right above, if we state `printf("%d\n", foo / 5);`, this will truncate the type of the calcauion and probably give us `0` instead of `0.6`. This happens because we did not set the right type for the actual output that we expect to see. 

It is always useful to think about such concepts when dealing with the mixture of `int` and `float` data types. 