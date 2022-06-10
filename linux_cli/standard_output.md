**filename** : **standard_output.md**

**author** : **Haneul Choi** [hanchoi@ucdavis.edu](hanchoi@ucdavis.edu)

**brief** : exploring the basic understanding & usage of standard output `stdout`

**date** : **06/05/2022**

# Standard Output

Every program, say in `c`, we write will be compiled into executable files. Suppose that we have a program file `main.c` and its exectuable file `a.out`.

```c
/* wwrite program main.c */
#include <stdio.h>
int main()
{
    printf("A\n");
    printf("AB\n");
    printf("ABC\n");

    return 0;
}
```

```bash
# compile main.c into a.out
gcc main.c -o a.out
```

```bash
# run the executable
./a.out

# program output
A
AB
ABC
```

**HERE**, the program output is the standard output that the program displays into the terminal.

The programming integer code for indiciating standard output is 1. We will not use this code in this file, but we will use that in the `redirection.md` file.

Another way to explicitly use `stdout` flag for standard output using `fprintf` function is the following

```c
/* main.c */
#include <stdio.h>

int main()
{
    char *msg = "Hello World!";

    // standard output (code : 1) type
    fprintf(stdout, "%s\n", msg);

    return 0;
}
```

```bash
gcc main.c -o a.out
./a.out

# the program output
Hello World!
```

That is the basic of standard output, there is also `stderr` which stands for standard output. The indicator for standard error is 2 (standard input indicator is 1).

You can read more about `stderr` in the file `standard_error.md` before reading `redirection.md`.
