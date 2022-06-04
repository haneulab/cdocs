**filename** : **null_pointer.md**

**author** : **Haneul Choi** [hanchoi@ucdavis.edu](hanchoi@ucdavis.edu)

**brief** : exploring the basic understanding & usage of NULL pointers.

**date** : **06/03/2022**

# NULL Pointer

We've dicussed what pointer is in `pointers.md` file. We have not yet discussed about the `NULL` type you see in `C Programming`.

The data `NULL` is actually a pointer (variable that points to the address of some variable), except that it points to nothing.

When you instantiate a pointer variable and assign `NULL`, that pointer points to nothing.

## Basic Usage

The following is how `NULL` can be used in a program

```c
...
int *ptr = NULL;
printf("%p\n", ptr); // (nil)

int num = 0;
ptr = &num;
printf("%p\n", ptr); // 0x7ffc8b461f8c
...
```

In the example code above, `ptr` points to `NULL` so it has no storage of address.

Now, after we assign the address of `num` as `&num` to `ptr`, we can print and see the newly assigned address that points to the variable `num`;

## More Usage

Suppose that your example function `printHi` takes a pointer argument `char *name`.

```c
int printHi(char *name)
```

When writing this function, we can first check if the argument `name` is not a null pointer `!NULL` because if the pointer is `NULL` there is no variable that we can deference to get the data value assigned to `name`.

It is a good practice to check the function's pointer argument's **NULL**ness condition before writing the logic for it.

```c
/**
 * if name is NULL, returns 0 indicating fail to execute
 * if name is NOT NULL, print welcome message with the name provided via parameter then return 1 indicating it was successfully printed.
 */
int printHi(char *name)
{
    if(!name)
        return 0

    printf("Hi, %s\n", name);
    return 1;
}
```

## Some Testing About NULL pointer

Now we know that `NULL` is a pointer that points to nothing in the memory. We can analyze some tricky cases where the program might not behave as we expect. Consider the following examples.

```c
#include <stdio.h>
void getString(char **strPtrs)
{
    if (!strPtrs)
        printf("null pointer passed\n");
    else
        printf("normal (not null) pointer passed\n");
}
int main()
{
    getString(NULL);

    char *str = "Hello";
    getString(&str);
    return 0;
}
```

This example program above will print the following.

```bash
null pointer passed
normal (not null) pointer passed
```
