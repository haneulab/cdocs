filename : redirection.md

author : Catherine Chen ccrchen@ucdavis.edu

brief : exploring input/output redirection on the linux command line

date : 06/05/2022


# Redirection

Redirection in Linux is used to use input and change where outputs are stored when running executables on the terminal. 

## Redirecting standard output

To redirect and put standard output into a file, you use the `>` character after the executable after compiling the file.

In this code we want to redirect the standard output of the `printf` statement into a file called `output.txt`.
```c
// redirection.c
int main() 
{
    int a = 30;
    printf("a is %d\n", a);
}
```

In terminal, you would run the function with the follwing code:
```
$ gcc redirection.c
$ ./a.out > ouput.txt  // redirecting output with >
$ cat output.txt // cat prints out contents of output.txt
a is 30
```
Each time you run this file and redirect the standard output into the file `output.txt`, you overwrite the file. To prevent overwriting and instead append to the file, you can use two `>>` instead. 

Compiling `redirection.c` again, this is the code you would run and see on the terminal:
```
$ gcc redirection.c
$ ./a.out > ouput.txt  // redirecting output with >
$ cat output.txt 
a is 30
$
$ gcc redirection.c // running the file a second time
$ ./a.out >> output.txt // appending output to file
$ cat output.txt
a is 30
a is 30
```
Now you can see that the output file has two lines for the two times you ran the file executable ./a.out and appended the output with the >> the second time you ran the program. 

**In short:**
`./a.out > output.txt` overwrites output.txt
`./a.out >> output.txt` appends to output.txt

## Redirecting standard input

You can also use standard input to feed data from a file, like a text file, into your program by using standard input. Standard input uses the `<` after the executable like when redirecting standard output, and feeds the data into each `scanf` for each character.
```c
// redirection.c
int main() 
{
    int a;
    printf("enter first value -> ");
    scanf(" %d", &a);
    printf("a: %d\n", a);
    printf("enter second value -> ");
    scanf(" %d", &a);
    printf("a: %d\n", a);
}
```
On the terminal, this is what would run and see for input redirection:
```
$ cat input.txt
13
20
$ gcc redirection.c
$ ./a.out < input.txt
enter first value -> a: 13
enter second value -> a: 20
```


The following command line code uses input redirection and then uses output redirection to store the standard output in a different file. Here, the first step is input redirection for the input to be read into the executable. Then the standard output is stored in the `output.txt` file instead of being printed to the terminal. the standard output is not printed to the terminal. Instead it is redirected to be stored in 
```
$ cat input.txt
13
20
$ gcc redirection.c
$ ./a.out < input.txt > output.txt
$ cat output.txt
enter first value -> a: 13
enter second value -> a: 20
```


## Redirectng standard error

Standard error is used to print the output of a standard error message to the terminal. It uses the syntax `fprintf(stderr, "error message");`. It prints to standard error instead of standard output. This is more for error messages to figure out issues in your code. To redirect it to a error file to only see error messages in the file, you can redirect standard error similar to how you would redirect standard output. Instead of using the `>` character, you would use the character `2>`. Using double carats, `2>>`, would append the error messages in `error.txt.`

```c
// redirection.c
int main () 
{
    int a;
    printf("enter first value -> ");
    scanf(" %d", &a);
    printf("a: %d\n", a);
    printf("enter second value -> ");
    scanf(" %d", &a);
    printf("a: %d\n", a);
    fprintf(stderr, "this will print to standard error"); // adding stderr line 
}
```
The output would be:
```
$ cat input.txt
13
20
$ gcc redirection.c
$ ./a.out < input.txt 2> error.txt
enter first value -> a: 13
enter second value -> a: 20
$ cat error.txt
this will print to standard error
```
Standard error is different than standard output. 
```c
// redirection.c
int main()
{
    printf("this prints to standard output\n");
    fprintf(stderr, "this prints to standard error\n");
}
```
By redirecting the standard output to a different file, the standard error would still print. Redirecting standard error to a different file would cause the standard output to still print.
```
$ gcc redirection.c
$ ./a.out > outputs.txt     // redirection of standard output
this is printed to standard error
$ 
$ gcc redirection.c
$ ./a.out 2> error.txt      //redirection of standard error
this is printed to standard output.
```

## Redirecting BOTH standard output and standard error

To redirect both standard output and standard error, you use the character `&>` to overwrite the file to output or `&>>` to append to the file to output.

```c
// redirection.c
int main()
{
    printf("this prints to standard output\n");
    fprintf(stderr, "this prints to standard error\n");
}
```
In this example, both standard error and standard output will be redirected to the file `output.txt`.
```
$ gcc redirection.c
$ ./a.out &> output.txt  
$ cat output.txt
this is printed to standard error.
printing to standard output
```

## /dev/null

`/dev/null` is essentially like a trash can where outputs can be discarded.

```c
// redirection.c
int main()
{
    printf("this prints to standard output\n");
    fprintf(stderr, "this prints to standard error\n");
}
```
In this example, both standard error and standard output will be redirected to `/dev/null`.
```
$ gcc redirection.c
$ ./a.out &> /dev/null 
$ 
```

## Pipelines

A pipeline is a series of commands that sends the previous command's results to the next command following the `|` character. 

```c
// redirection.c
int main() 
{
    int a;
    printf("enter first value -> ");
    scanf(" %d", &a);
    printf("a: %d\n", a);
    printf("enter second value -> ");
    scanf(" %d", &a);
    printf("a: %d\n", a);
}
```
This following example first redirects the inputs from `input.txt` to use in the program, and then from those outputs, `grep` finds the lines that contain the word "second".
```
$ gcc redirection.c
$ ./a.out < input.txt | grep "second"
$ enter second value: a: 20
```