# Lecture 6

Today, we've talked about debugging in `C` Programs. 

In programming, we use the work `debug` as a verb to `catch a bug` in your code. 
For examle, the program code may be written correctly but it might not do (behave) what we expect. This is always a good practice (if not must) to debug your code until it has nearly performed 99.9% the same as we expected. 

As an example, the below is a case where debugging can catch and thus you can fix those bugs

```c
#include <stdio.h>

int main ()
{
    // I want the user type the character for each varaible below
    char target1, target2;

    printf("user, please enter the first character: ");
    scanf("%c", &target1);
    printf("user, please enter the first character: ");
    scanf("%c", &target2);

    // do something with user inputs

    return 0;
}
```

In the program above, one of the variables `target2` will have some unexpected bug issue caused by what's known as `buffering`. It is hard to catch it if especially if we do not a lot of `C` programming concepts like so. In this case, if we have a tool to debug our code, more specifically line by line, that will help us to detect the assignment of the user input to `target2` thus we can find a way to fix before we make our program more complicated. 

In debugging `C`, we will use `gdb` tool to set breakpoints and more. The document below shows how to debug your program via `gdb`

---

### Introduction to GDB (gdb)

The following content is to show basic commands and debugging utilities.

For this example, I will refer our debugging program as `main.c`

```bash
# first compile the file to debug
gcc -g main.c -o main
```

Then instantiate the `gdb` with the `main` executable

```bash
# point the debugging executable file (in our case it is ./main since we compiled main.c to)
gdb ./main
```

To create a break point, we can run the following

```bash
gdb ./main

# set break point
# we are setting line 4 as our first break point
(gdb) break 4 
```

Then, to run with our new break point(s), we can do the following

```bash
gdb ./main

(gdb) break 4

# run the debugger 
(gdb) run
```

While running the debugger if you want to see the specific variable printed to the terminal at that exact point of the program, we can run the following. (We can assume we have an integer variable `a` in our `main.c`)

```bash
gdb ./main

(gdb) break 4

(gdb) run

# I want to see my variable (int a)
(gdb) p a
```

To move on to the next line debugging, we can simply type the following

```bash
(gdb) n
# or
(gdb) next
# if you want to debug a specific fucntion 
# that you declared in the program
# you can run the following instead
(gdb) s
# or
(gdb) step
```