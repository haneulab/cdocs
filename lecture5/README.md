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
