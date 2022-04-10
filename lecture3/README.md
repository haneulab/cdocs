## Lecture 3

Today, we went over the `if` statement & `char` specificities. For the source code & comments
related to these codes can be found in each `.c` files in this directory.

### Character Type Specifics

We know now that in `C language`, we can delcare an integer variable in the program as something like
`int myInteger;`. Now, to delcare a `character` variable, we must consider the following things. In other words,
we should think about the use of this variable in our program.

✋ Q1. By character variable, do we mean **a single character**?

✋ Q2. By character variable, do we mean **multiple characters**? (If so, how many characters?)

```c
int main ()
{
    // single character for variable assignment
    char singleChar = "x";

    // multiple characters for variable assignment
    // specify the characters length + 1
    // for example, I want to assign to this variable anything less than equal to 30 characters.
    char multipleChars[31] = "xyz123#Q"
    // even though the assigned value's length is strictly less than 30, it is fine because it meets our pre defined rule set. [31] (less than equal to 30)


    // we will play with these variables in the next section for if&else statements

    return 0;
}
```

Now, using the concept above, we will use a user input function `scanf()` to let user assign value to these variables.

```c
int main ()
{
    int userInteger;
    char userSingleChar;
    char userMultipleChars[17];

    // get user integer
    printf("Hey, type your integer : ");
    scanf("%d", &userInteger);

    // get user single character
    printf("Hey, now type your single character : ");
    scanf("%c", &userSingleChar);

    // get user multiple characters
    printf("Hey, can you finally type your multiple characters without space? : ");
    scanf("%s", userMultipleChars);


    // print these values back to user to confirm
    printf("Hey user! Well Done.\n");
    printf("Your integer is %d.\nYour single character is %c.\nFinally, your multiple characters are %s.\n", userInteger, userSingleChar, userMultipleChars);

    return 0;
}
```

> **Note `char[]`**
> Using multiple characters, we must be careful because if we type "Hello World" instead of "HelloWorld", the value won't be assigned as we expect. Using `char[]`, we should strict our selves to only using multiple characters **WITHOUT** any space character in it."

---

### Conditional Statement

Conditional statement are quite straight forward given that we know one or more programming languages before `C`.

Now, to remind ourselves how the `if else` statement in general structures work, please look at the following.

In python, suppose we have such a conditional statement

```python
if 1 == 0:
    printf("WTH?")
else:
    printf("1 is not same as 0")
```

Then, the statement in `if`, that is `1 == 0`, is simply there to be evaluated. It is not there to assign `0` to `1`. Since we know that `1 == 0` is `False` meaning `not True`, we also know that whatever is there for `else:` statement will be executed.

Similarly, in `C programming language`, we are inputing an evaluatable statement inside the `if` and `esle if` statement.

```c
.
.
.
// good example
int userInteger;
printf("Hey, what is your favorite integer ? : ");
scanf("%d", &userInteger);

if (userInteger == 20)
{
    // do these if userInput is greater than 20
}
```

The statement next to `if`, that is `userInput > 20` is an evaluable statement, and **NOT** assignment of 20 to the variable `userInput`.

To assign a value to a variable we use `=`, while we use `==` to evaluate whether the left and right variables are equal.

This, for `if & else` statements, we should put evaluatable statements such as `x == 5` not assign value to the left variable `x = 5`.

---

##### Fun Example

I came up with a fun example to practice these concepts we learned so far, if you want, you can come up with your own or try mine!

We are going write a program that asks user for their first/last name and age. Then, we will implement `if&else` statement to print out different sentences depending on the user's assigned age.

In order for you to try out this program, simply go to [Running](#Running) below for instruction.

Here goes the code for the program.

```c
#include <stdio.h>

int main ()
{
    int userAge;
    char userFirstName[21], userLastName[21];

    // Welcome the user!
    printf("Welcome User!\n");

    // ask your first and last name
    printf("user, what is your first name? : ");
    scanf("%s", userFirstName);
    printf("and your last name? : ");
    scanf("%s", userLastName);

    // ask your age and now call the user by their name.
    printf("%s, how old are you ? ", userFirstName);
    scanf("%d", &userAge);

    // confirm user data
    printf("%s %s, you are %d years old!\n", userFirstName, userLastName, userAge);

    // implement if & else statement with thier age
    if (userAge == 21)
    {
        printf("You turned 21 recently, Let's go to vegas!\n");
    }
    else if (userAge > 21) {
        printf("You are well over 21! Let's go grab a bottle of soju.\n");
    }
    else
    {
        printf("Since you cannot drink alcohol yet, let's go drink a strawberry milk or orange juice.\n");
    }

    return 0;
}
```

---

##### Running

- ✏️ Copy the `c` code above and paste it into a file
- ✏️ Compile the executable
- ✏️ Run the executable

**Create a file & paste it to the file**

The convention with the `.c` filename and its executable is the following

- `filename` : `some.c`, `some_file.c`, `some_new_file.c`
- `executable filename` : `some`, `some_file`, `some_new_file`

The following is a way to complite `.c` file using gcc (GND Complier Collection).

```bash
touch ./fun.c
# or
touch fun.c
```

**Compile it to executable**

```bash
gcc ./fun.c -o ./fun
# or
gcc fun.c -o fun
```

**Run the program**

```bash
./fun
```
