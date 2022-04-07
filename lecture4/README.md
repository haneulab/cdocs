# Lecture 4

Today, we went over a few different topics. For each topic related codes, please go to the corresponding `.c` file.

---

###  Loops and Prefix & Postfix Expressions

Loops in `C` are pretty straightforward if you are coming from python. We often use either `while` or `for` loop to **iterate** over an **iterable object**. 

```c
#include <stdio.h>

int main ()
{
    char iterableCharacters[] = 'abcde';
}
```

> **NOTE** `char myChar[] = 'abc'`, `[]` can be treated as an array like item, meaning we can use any operations for array to this item such as iterating each index of the item and each item in that index.

In the above code, we have a character variable `iterableCharacters` whose value is assigned as `'abcde'`. The length of this character as you can observe is `5`. So we can use both `while` & `for` loops as follows.

```c
#include <stdio.h>

int main ()
{
    char iterableCharacters[] = 'abcde'; 

    // while loop
    int index = 0;
    while(index < 5)
    {
        // will iterate for the index 0,1,2,3,4
        printf("current character : %c\n", iterableCharacters[index]);

        // increase the index to proceed to next index
        index = index + 1;
    } 

    /* for loop (one lined code does not need curly braces.)
     *
     * for(int i = 0; i < 5; i = i + 1)
     * {
     *    printf("current character : %c\n", iterableCharacters[index]);
     * }
     * 
     */
    for (int i = 0; i < 5; i = i + 1)
        printf("current character : %c\n", iterableCharacters[index]);
    
    return 0;
}
```

Now, you might notice how I wrote `index = index + 1` and `i = i + 1` when stating the `while` and `for` loop above. Shorter way to do this by using postfix (you could use prefix, too). 

**Postfix** is used to evaluate the operand to the variable value and the new value is assigned to the variable after that expression.

```c
// postfix demonstration for increament & decreament

int i = 10; // currently i = 10
printf("add 1 to i : %d.\n", i++) // prints 'add 1 to 10.'
printf("Now i is %d.\n", i) // prints 'Now i is 11'.

printf("subtract 1 from i : %d.\n", i--) // prints 'subtract 1 from 11.'
printf("Now i is %d.\n", i) // prints 'Now i is 10'.

```

**Prefix** is somewhat similar but different in that it is evaluated to the variable first before that line begins to be executed.

```c
// prefix demonstration for increament & decreament

int i = 10; // currently i = 10
printf("1 added to i. So it is now : %d.\n", ++i) // prints '1 added to i. So it is now 11.'
printf("i is still %d.\n", i) // prints 'i is 11'.

printf("1 is subtracted from i. So it is now : %d.\n", --i) // prints '1 is subtracted from i. So it is now 10.'
printf("i is still %d.\n", i) // prints 'i is 10'.

```
---

### Switch Expression

`switch(x)` expression is used to avoid multiple `if & else` statement where you are checking the **specific values** for a given variable `x`. 

For example, if you want to tell user if he or she can drink or not with regards to their input age, we should use `if` because we are only able to tell if they can drink or not by the range since we cannot exactly predict the user's age. 

The idea of using `if` in this case is the following.

- If the user age inputed is greater than or equal to 21, let the user know they can drink.
  
- If the user age inputed is less than 21, let the user know he or she cannot yet drink because it is below the legal age for drinking alcohol.

- If the user types any value out of this range such as `negative integer` or `character(s)`, we can let the user know that they typede an invalid value for their age.

As you can observe, we probably go by using `if` statement here, and not `swtich`.

But consider the example where we are dictating a student's GPA for given a letter grade. When the student types their letter grades for the classes they took this quarter, we can calculate all the neccessary components (such as weight) and their letter grade together to output the overall quarter GPA. 

The student got letter grades as `['A', 'B', 'C']` in the three classes that he or she took. Assuming that the weight of each class (the units) are equal, we know that this student will have `3.0 GPA` this quarter. 

If we were to program this, we can use `switch`. 

```c
#include <stdio.h>

int switchGrade(char letterGrade)
{
    int numericGrade = 0;

    switch(letterGrade)
    {
        case 'A':
            numericGrade = 4;
            break;
        case 'B':
            numericGrade = 3;
            break;
        case 'C':
            numericGrade = 2;
            break;
        case 'D':
            numericGrade = 1;
            break;
        default:
            break;
    }

    printf("You got %c = %d in the course\n", letterGrade, numericGrade);

    return numericGrade;
}

int main ()
{
    char courseGradeA = 'A';
    char courseGradeB = 'B';
    char courseGradeC = 'C';

    int numericGradeA = switchGrade(courseGradeA);
    int numericGradeB = switchGrade(courseGradeB);
    int numericGradeC = switchGrade(courseGradeC);

    int sumGradePoints = numericGradeA + numericGradeB + numericGradeC;
    int totalCourses = 3;

    // float should be replace with int (after we learn the concept of 'float')
    // we have not yet learned 'float' in C.
    int thisGPA = sumGradePoints / totalCourses;

    printf("Calculated. Your GPA this quarter is : %d\n", thisGPA)
;}
```

---

### Concept of Goto

Consider the following code in python,

```python
import sys

# define main function (returns None)
def main () -> None:
    userAge : int = 0

    try:
        userAge = int(input("How old are you? : "))
        if userAge < 0:
            raise Exception("Your age must be greater than or equal to 0.")

        printf("Your age is validated!")

    except Exception as e:
        printf("There was error executing 'int()' function on the user input")
        sys.exit(1)

# call the defined main function
main()
```

In the above code, we are letting the user type their age as a numeric value but if user types any numeric value less than 0 for his or her age, it will raise an exception because 'how can someone have negative valued age?'

In the programmer's perspective, this can definitely happen either it was an accident or user had drunk too much and he or she ran this program typing some random invalid value for the age.

Another things about the code in the `try` block is that it is possible that our program will crash because if the user puts a character as input instead of number, converting string into integer does not make any sense. This is also expected problem that users can type into the program. 

In such cases, we want to prevent the program from crashing or at least let user know in place what went wrong about inputing asked values. 

There is a similar but a bit different concept we can use in our validation or predictable action controller statement in `C` programming language. 

It is `goto` and `end`. Take a look at the following code. For the simplicity, we will only tell ourselves that we can predict the user may type their age as a negative number.

```c
#include <stdio.h>

int main ()
{
    int userAge;
    printf("How old are you? : ");
    scanf("%d", &userAge);

    if (userAge < 0)
        goto end;

    printf("User, congrats! you typed a valid value for your age.\n");

    end:
        printf("User, it seems like you typed an invalid value for your age\n");
        printf("Program ending...\n");
}
```

In the code above, if the user types negative number, the program (at the first line from the `if` statement) will directly send the execution (skip to the 'end' block).