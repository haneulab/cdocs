**filename** : **iterative_statements.md**

**author** : **Dave Nguyen** [hxnguyen@ucdavis.edu](hxnguyen@ucdavis.edu)

**brief** : explain different types of loops and its functions.

**date** : **06/05/2022**

# Loops
Loops are essentiall to basic coding skills that all coders/hackers/programmers/"whateever names we have" need. The 2 main loops are `while` and `for` loop. The 3rd loop is a little specific in it functionality, thus more examples are provided for better details about each loop. The goal is to help coders understand their differences and their functionality.  
In general, loops are ways that coder use to repeat certain actions based on the condition the loop are given

### while(condition)
Allow you to repeat actions while **condition** is true. If the condition is met we enter the while loop. Once you get to the end of the while loop you go back to the top of the loop. This keeps repeating until the condition becomes false.
**example** if we want to print numbers from 1 to 10 in order, we can use `while()` loop:
```c
// declaring variable
int i = 1;
// while(), condition: i < 11
while (i < 11)
{
    // we prints the variable i
    printf("i = %d\n", i);
    i++; // incrementing (increasing) i
}
```
The output would be:
```
1
2
3
4
5
6
7
8
9
10
```
### for(init; condition; update)
The difference between for loop and while loop is just *fancy* by *Iggy Azalea* (get it..... cause for loop is fancy and ... while loop is not) Anyway, if you like convenience store, you would love the for loop. Since while loop can only take in 1 `condition` and user have to manually update the condition in order to avoid **infinite loop** (key concept in programming), for loop allow users to update the condition within the loop itself, using the argument `update`. `Init` and `update` are optional. Any variables declared in init last only for the duration of the for loop
**example** we want to print different characters `abcde` 
```c
int main() 
{
    // declaring varible
    char s[] = "abcde";
    for (int i = 0; i < 5; ++i) // for (init, condition, update)
    /*
        int i = 0; i < 5; ++i
        1st condition: The init expression is run before the loop starts and is always run
        2nd condition: the condition checks the loop's condition during its iteration
        3rd condition: the condition that is done after each iteration
    */
    {
        printf("%c\n", s[i]); // print the character in string s
    }
```

### do{} while()
A do while loop is like a while loop except that the code inside of it is **always run at least once**.
**example** we want to print number 10:
```c
int i = 10;
do
{
    printf("i = %d\n", i);
    ++i;
} while(i < 10)
```
The output would be:
```
10
```
### break;
Causes the loop to immediately stop running. Usally appear inside of a loop (can't run outside of a loop). 
**example**
```c
//declaring variables
int num, posSum = 0;
while(1) // nonzero means true, zero means false
{
    printf(“Enter a number: ”)
    scanf(“%d”, &num); // getting the numbers <3
    
    //if num is less than 0
    if(num < 0) 
    { 
        break;
    }
    else // num is not less than 0
    { 
        posSum += num;
    }
}
printf(“The sum of numbers is %d”, posSum);  

```

the output would be
```
$ a.out
2
The sum of numbers is 2
$ a.out
-2

```
### continue;
A continue statement can appear inside of loops. It brings you to immediately go back to the top of the loop. If you are in a for loop it **will cause** the update code to be run.
**example** the following code:
```c
// declare numbers
int num, i;
for(i = 0; i < 10; ++i){
    if(i %2 == 0) // if the remainder of i and 2 is equal to 0
    {
        continue; // we escape this iteration (i = 0) and run the printf statement.
    }
    printf(“i = %d\n”, i);
}
```
the output would be:
```
$ a.out
i = 0
i = 2
i = 4
i = 6
i = 8
```