## Lecture 2

Overall lecture went over first **How to use VIM (text editor)** in cli. Then, we moved on to learn about variable types and format specifying into `printf` function. 

### VIM Text Editor Usage

VIM is one of the text editor tools where we write codes. VIM is different from other text editors such as VSCode, PyCharm, and so on because VIM opens the file inside the terminal instead of some external desktop application or browser.

I personally do not use VIM in my daily workflow, but it is a good idea to know how to use basic VIM features such as `create & write` and `edit` files in VIM. 

### C Language Introduction

In `C Programming Language`, we should specify the type of a variable when delcaring them. Refer to `./main.c` file for detail. 

```c
// soms example declarations
int main () {
    // declare integer (int)
    int someInt = 10;
    int anotherInt = 20;
    // declare character (char)
    char someCharacter = 'X';
    char anotherCharacter = 'Y';
}
```

Now, if you remember python built-in funtion `print`, you know that we can use `formatted string` to output a string with dynamically with variables' values in the string.

```python
my_favorite_num = 7
my_favroite_char = 'a'
print(f"My favorite number is {my_favorite_num}.\n My favorite character is {my_favorite_char}.");
```

But in C, we have a function called `printf`. The difference between this and the python `print` function is that in C we must use what we call **format specifer** to variables used in `printf` function. This means that unlike python code above, we must specify some kind of formatter to refer to that variable. Each variable type has different formatter.

```c
// bad example C
int main () {
    int myFavoriteNum = 7;
    char myFavoriteChar = 'X';
    
    printf("My favorite number is {myFavoriteNum}.\nMy favorite character is {myFavoriteCharacter}.\n");
}

// good example C
int main () {
    int myFavoriteNum = 7;
    char myFavoriteChar = 'X';
    
    printf("My favorite number is %d.\nMy favorite character is %c.\n", myFavoriteNum, myFavoriteChar);
}
```

Here, `%d` points to the first variable `myFavoriteNum` and it must be type of `int`. On the other hand the second format specifier `%c` will point to the seocnd variable `myFavoriteChar` and it must be a type of `char`. Each built-in types will have their own format specifier.

I will list some of the most usede format specifiers. *The lecture today only went over two tyes of format specifiers (`int : %d`, `char : %c`)*

#### (EXTRA) Format Specifiers In C Programming

|Variable Type|Format Specifier|
|---|---|
|`int`|`%d`|
|`char`|`%c`|
|`float`|`%f`|

> **NOTE** Sometimes, you may want to include `%` as a string rather than a format specifier prefix. For example I want to assign a string 'I will win the game at 50%` to a variable, then you just have to use two percent signs.

```c
// bad
printf("I will win the game at 50% of chance\n");
// good
printf("I will win the game at 50%% of chance\n");
```

#### (EXTRA) Compling the executables

In lecture, we notice that compiling `main.c` file using `gcc main.c` always output `a.out` file.

Sometimes, this can be annoying especially when you would have multiple files and have to compile them & regonize their corresponding executables. 

First, `.out` extension is not required as an executable file. This means that there are some ways we can compile `main.c` into something like `a` instead of `a.out`. In my own practices, I try to correspond the executable filename to the original c filename. 

For example, if we have `main.c`, I want to compile this file into executable filed named `main` instead of `a.out`. To do this, we use our CLI command with flag (optional) statement. 

```bash
# original version
gcc main.c # outputs an executable with filename = a.out 
# optional version with flag
gcc main.c -o main # outputs an executable with filename = main 
```