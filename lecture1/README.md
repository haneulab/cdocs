Creating a `c` file, writing a program to it, then compiling it to run in CLI.

```bash
touch ./main.c
```

```c
// main.c
#include<stdio.h>

int main ()
{
    printf("Hello, Aron!\n");
}
```

```bash
gcc ./main.c
./a.out
# or we can combine them
gcc ./main.c && ./a.out
```