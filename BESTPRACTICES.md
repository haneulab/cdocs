# Best Practices Guidelines of C Programming

When we organize files or write codes, there are some set of rules that general population follow in order to keep the consistency and readability across this population.

Considering the best practices of `C programming language` and its aspects such as `how to write c codes` and `how to manage c files`, please read the following texts to implement these practices to your projects.

As I learn more and more about the best practices, I wil upload them here.

**It is also very important** (especially knowing that you will work in team-oriented environments in near future) that we are consistent with how we do things. Be consistent (indentation, bracket position, setting meaningful variable names, etc.)

---
### Using `{}` Curly Brackets

It seems like most `C` programmers tend to use `{}` 
bracket expressions in a **newline**.

For example,

```c
void sayHello () {
    int x = 0;

    printf("Hello!\n");

    if (x == 0) {
        printf("X is 0\n");
    } else {
        printf("X is not 0\n");
    }

}
```

The code above works fine. But, many others seem like they use the style below

```c
void sayHello () 
{
    int x = 0;

    printf("Hello!\n");

    if (x == 0) 
    {
        printf("X is 0\n");
    } 
    else 
    {
        printf("X is not 0\n");
    }
}
```

But, it is important, whateer style you are using in that team or for yourself, to be consistent with that style throughout the program & project.

---
### Using `int main()` Global Function

By now, we know everytime we create a `c` file and write codes, we declare `main()` function in which we write our program. As explained in `./README.md`, the function returning type for `int main()` is an integer, but we also know that we must end the program after the execution of the code inside `main()`. 

*It is best practice to return an integer*

Since we know that the program will ende after the last line of `int main()`, we can simply return `return 0`

```c
// int main() {} best practice
#include <stdio.h>

int main() 
{
    /*
    Your program goes ihere
    */

    // return 0 indicating that the program ends
    // reflective of the returned type as delcared in front of the functio name 'main'
    return 0;
}
```

If the function does not return anything, we use `void` in the front of the function name.

```c
#include <stdio.h>

void printHello()
{
    printf("Hello World!\n");
}

int main()
{
    // call printHello function
    printHello();
    // and return 0 for ending the program
    return 0;
}
```