# Lecture 4

Today, we went over a few different topics. For each topic related codes, please go to the corresponding `.c` file.

**Note** some of you may have confusion understanding what `void` means before the function name or inside the function argument, for this, I created a directory in here `./functions/`, please go there and read `README.md`. 

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