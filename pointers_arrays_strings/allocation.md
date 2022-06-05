**filename** : **allocation.md**

**author** : **Haneul Choi** [hanchoi@ucdavis.edu](hanchoi@ucdavis.edu)

**brief** : exploring the basic understanding & usage of memory allocation & memory leaking

**date** : **06/05/2022**

# Memory Allocation & Memory Leakage

In this file, I will go over what we actually mean by **allocating & leaking memory**. Without think about this too much in terms of coding, please take it as some effects that could happen dealing with manipulation of memory spce in the programs we write.

## Memory Allocation

Ok, now what does it actually mean to allocate memory, or more specifically _allocate memory space_?

Well, our computer has a finiate amount of memory space. At this time, it is not important what the unit or the size of the memory that your computer or my computer has capacity for. What is **important** is to understand the basic mathematical visualization of memory usage relative to its fixed capacity.

Initially, we are going to use the example case to understand this.

```tex
<!-- assumption about the situation -->

Let the memory use capacity 'K' in your computer be 10.
You write a program 'x' that uses 4 out of your computer's capacity 'K'
```

From the above example, you can conclude the following

`When running the program 'A', your computer will only have 6 available for usage by other programs running in your computer.`

**NOW**, we know how memory capacity & memory space that each program can be innerconnected where the larger the memory capacity your computer offers, the more and complex programs can be ran concurrently.

## How Memory Allocation Works

We will now go into discussing within the context of the program **x**. Suppose that we wrote a `c` program called `main.c` which we refer as the program **x**.

The program **x** can be programmed by a programmer like you and me telling it what we want it to do, say for example calculating two user inputted integers & print to the terminal.

In doing so, we do need to declare & assign variables & functions. What I mean by declaration & assignment is all of the following

```c
...
int num = 0; // declared & assigned
char a, b, c; // declared
float pi = 3.14; // declared & assigned
...
```

```c
...
int *ptr; // declared
struct HashTable *ht = htCreate(10); // declared & assigned
...
```

```c
...
void foo(int num) // declared
{
    printf("%d\n", num);
}
...
```

When declaring & assigning data objects in the program, what we actually doing is **using memory space** from the memory factory in our computer. _Note_ how I said that each computer has only **finite amount of memory capacity**. This means that if our prgram **x** gets really complicated or huge, it is almost mandatory to use the given memory space more efficiently so that we can make our program run not only faster but also scaleable.

Now all those things that we did above for declaring & assigning in a **static** manner. We are literally delaring the type & name of the variable then assign the value needed for it. When something is **static**, it is **NOT DYNAMIC**.

So what does it mean by **dynamically allocating memory** in our program **x**? Well, unlike the process of **static allocation** where you declare the variable & assign value and memory allocation follows from it, **dynamic allocation** first saves some memory spaces in the factory for us which we can have access to later within the program for us to store variable(s).

In the following example, I will demonstrate both **static allocation** and **dynamic allocation** where I will handle two integer variables and the program will output the sum of two variables.

```c
/* static allocation manner */
// main.c
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    printf("sum is : %d\n", a+b); // sum is 30
    return 0;
}
```

```c
/* dynamic allocation manner */
// main.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // using malloc() function from stdlib.h library
    int *numLeft_pointer = malloc(sizeof (int));
    int *numRight_pointer = malloc(sizeof (int));

    *numLeft_pointer = 10;
    *numRight_pointer = 20;

    printf("sum is : %d\n", *numLeft_pointer + *numright_pointer); // sum is 30

    free(numLeft_pointer);
    free(numRight_pointer);

    return 0;
}
```

You might be wondering the program we want is so simple but dynamic allocation approach has too many lines of codes. You are **absolutely right**. In this specific program my goal was to show how to use it and the differene for using two different allocation ways you can write your program or part of the program.

Also, when using the **dynamic** allocation approach, you see that we use pointers & the code block of `free(that_pointer)` comes as complementary. I will talk about the reason why this is needed below. For now, you can believe that if we do not `free` the pointer that is dynamically allocated in our memory, it wil CAUSE memory leakage. Yep, that sounds pretty bad especially if you imagine the program uses sensitive & secured data objects that we are not suppose to expose outside of the program.

## Dynamic Allocation & Memory Leakage

When using **dynamic allocation** in the part of the program, we must be aware of the following

- **Saving Space For The Computer Memory Life Span** : we probably assumed that when our program ends, all the data is dead. Well, only the **statically allocated** ones are dead. If you have dynamically allocated variables (memories) in the parts of your program, they are still taking space even after the program ended. This means that we must know when we need to know the timeline that the dynamically allocated variables are not needed for the program and kill that space (restore) at latest before the program ends.

- **Keeping Track of Dynamically Allocated Memory Address** : once we dynamically allocate a certain size of memory, we have access to that location in the program. This means that if we lose that memory address, we cannot `free` it causing memory leakage. We must be able to always access to this address, then `free` it at latest before the program ends.

## Learn From Scenario

Take a look at our program below

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *nptr1 = malloc(sizeof (int)); // dynamically allocate memory space @ 47240eff101
    int *nptr2 = malloc(sizeof (int)); // dynamically allocate memory space @ 6660effeff1

    printf("%p\n", nptr1); // 47240eff101
    printf("%p\n", nptr2); // 6660effeff1

    // deferencing pointers to store integer values
    *nptr1 = 10;
    *nptr2 = 20;

    printf("integer %d is saved @ %p\n", *nptr1, nptr1); // integer 10 is saved @ 47240eff101
    printf("integer %d is saved @ %p\n", *nptr2, nptr2); // integer 20 is saved @ 6660effeff1

    /*
    * The code line below is telling nptr1 is now the location of nptr2
    */

    // PROBLEM MAKER LINE NOW
    nptr1 = nptr2;

    printf("%p\n", nptr1); // 6660effeff1
    printf("%p\n", nptr2); // 6660effeff1


    printf("integer %d is saved @ %p\n", *nptr1, nptr1); // integer 20 is saved @ 6660effeff1
    printf("integer %d is saved @ %p\n", *nptr2, nptr2); // integer 20 is saved @ 6660effeff1

    free(nptr1) // freeing 6660effeff1
    free(nptr2) // freeing 6660effeff1 but already freed above (double free error)

    return 0; // the program ends
    /*
    * But we have not freed the original nptr1 47240eff101 (it now causes memory leakage)
    */
}
```

In the scenario above, we have no way to get back the original `nptr1` address `47240eff101` because we reassigned `nptr1` with what `nptr2` is refering to. It was mono-directional assignment so we lost track of `47240eff101` meaning the program has no way to `free` the dynamically allocated space of `47240eff101` so the meory leakage occurs in our computer.

This is why it is very important to keep track of the dynamically allocated memory address when deciding to use dynamic allocation in your program.
