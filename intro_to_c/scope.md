**filename** : **scope.md**

**author** : **Haneul Choi** [hanchoi@ucdavis.edu](hanchoi@ucdavis.edu)

**brief** : exploring the concept of scopes in a programming language (using C language)

**date** : **06/03/2022**

# Scopes

When writing programming languages, we often get stuck in manipulating variables inside functions, loops, and so on. Most programming languages, if not all, have what is known as **Scope**.

Often, we will see two types of **scopes**

- **Global Scope**

- **Local Scope**

Every variable that we create whether outside of a function or inside the function has its defined scope. Take a look at the following code.

```c
#include <stdio.h>

int globalNum = 100;

void bar()
{
    globalNum = globalNum + 1;
}

int main()
{
    int a = 10;
    int b = 20;

    printf(globalNum); // 100
    bar();
    printf(globalNum); // 101

    return 0;
}
```

The variable `globalNum` declared at the top level of the file (meaning that it is declared outside of any function in the file) have the global scope throughout the program. This means that the variable `globalNum` can be accessed & manipulated anywhere in the program. The state of `globalNum` depends on the last execution where it was declared, assigned, or manipulated. In this program above, the `globalNum` was last manipulated when the function `bar()` was called inside the `main()` function and when the `bar()` function is called then `globalNum` increaments by 1. So initially printed 100 but now it will have the value of 101.

**NOW**, what tricks a lot of us is the **local scopeed variables**. Anything that is declared inside functions are local to itself. Take a look at the following code below.

```c
#include <stdio.h>

int globalNum = 100;

void foo(int a)
{
    printf("a : %d\n", a);
    a = a + 1;
    printf("a : %d\n", a);
}

int main()
{
    int x = 10;
    foo(x);

    /** output
     * a : 10
     * a : 11
     */

    printf("x : %d\n", x); // x : 10

    return 0;
}
```

Our `globalNum` is still a global scoped variable. However in the function `foo()`, the `int a` argument is a scoped variable locally available within `foo()` function. Thus, reassignments like `a = a + 1` or `a = 1` work inside the foo function but then gets thrown away when the execution cylce of the `foo()` ends. That is why the state of the variable `int x` declared in `main()` is not changed. When we look at `foo(x)` in the main, all we are doing is just passing the value of `x` which is `10` to `foo` and then `foo` will take that value and use it wihtin itself, but never has a connection back out of its scope (where `main()`) is executed.

We call such event **Pass By Value**. We are passing the value of `x` to the function `foo` in `foo(x)` because `foo` requires integer arugmnet when being called.

The reason why the `globalNum` was able to change even though the operation happened inside of a function `bar` is because `bar` can access the global variable `globalNum`. On the other hand, when we are passing an argument `a` into the function `foo` simply means that `foo` needs a `int` value passed into the `a` variable that it can use throughout the `foo` execution time and thrown away as soon as `foo` execution time is done.

**Briefly**, we can think of any variables declared in a function such as `arguments` or variables declared in the funtion as local scoped variables. Which means that it is only accessible and alive within the function's execution context. When this function execution ends, that is when all the variables delcared within the function is also distoried.

**Moreover**, when we pass a variable into a functionc all, that simply means we are passing whatever the value that this variable is storing and not the whole variable scope. For example, if a variable `int x` is declared inside the `main` function, and call an outer scoped function `foo` where we pass `x` into `foo` such that `foo(x)` is executed, this is equivalent of saying `foo(value of x)` in plain english. So even if the `foo` has some operations to change what is passed, it won't affect the variable `x` that lives in the `main` function's scope after `foo(x)`'s execution time passed.

## Test Your Scope Knowledge

Please take a look at the following programs and try to convince yourselves about what will be the output.

### Program 1

```c
#include <stdio.h>

void foo(int a, int b)
{
    a = 0;
    b = 0;
}

int main()
{
    int x = 10;
    int y = 10;
    printf("%d\n", x);
    printf("%d\n", y);

    foo(x, y)
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}
```

The output of the **program 1** will be

```bash
10
10
10 # not 0
10 # not 0
```

### Program 2

```c
#include <stdio.h>

void foo(int a)
{
    a = a + 1;
    printf("%d\n", a);
}

int main()
{
    int num = 0;
    printf("num : %d\n", num);
    foo(num);
    printf("num : %d\n", num);

    return 0;
}
```

The output of the **program 2** will be

```bash
num : 0
1
num : 0 # not num : 1
```
