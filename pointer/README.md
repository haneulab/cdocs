# Welcome to Pointers in C 🧑🏻‍💻👨🏻‍💻👩🏻‍💻

.

<aside>
💡  In this module, I will go over the concept of **pointer** which is just a technical term for referring to the address for a program variable

</aside>

> Please note that this is my interpretation, thus others may have different interpretation strategies.
> 

## Pointer Conceptual Interpretation

One of our classmates Ryan on Discord mentioned that the point of **pointers** is to point to a point in memory. I think this is superb intuitive statement that explains what the pointer is.

To add my deeper interpretation, I’d like to say that what they mean by a point in memory is basically **address** in memory, which is the string that has information about the variable that we are referring to is stored in memory. 

When we declare a normal variable (Not a pointer variable) in C, it is a data that needs to take up some finite memory in our machine. Where they are stored in memory (so that we can always refer to that variable later in the program) needs some sort of address so that the program can easily find that variable when it is called.

Take a look at the following program in C

```c
#include <stdio.h>

int main ()
{
	// declaration of an integer variable named num and assigned value of integer 0
	int num = 0;
	
	/*
	* some program lines here
	*/

	// time to change the variable value to 1;
	num = 1; 
}
```

In the above program, we first declare the integer variable and assign 0 as its value, then later in the program when a certain things happen, we now want to change the value (increment) to 1. 

In this process, we as programmers/human can easily tell how we did and what the program now does. But did you ever think about how your computer process the entire situation above? Note that computers are not human like us. They just do what we tell them to do. 

In order for such a finite state machine to do what we tell them to do, there must be a rule that the program should follow in order to successfully finish its job as told. 

Unlike our behavior of ‘num = 1’ to change the original ‘num’ value, the computer needs to first store ‘num’ once it is declared, then whenever we tell the program to change the value, it has to refer and access to that storage to mutate the value. 

This is my understanding what the computer will do

- When we declare the variable, say **int num = 0;**
    - The computer will assign that specific data into our memory and also create a memory address so that when later **num** is called, the program can refer back to it at that address.
- When we change the value of **num** after its declaration, **say num = 1;**
    - The computer will first access the address, then go to that address which stores the original value of **num = 0,** then change it to 1.

Here, notice how the byte that **num** takes will never change because the initially declared variable type can’t mutate. The amount of boxes in memory storage taken by the integer variable **num** won’t change, also the address of **num** did not change. The only thing that changed along with the value of **num** is just what’s inside of these integer byte (4 bytes) boxes that consists of 0s and 1s (binary code).  

As far as talking about how WE as programmers can access that address or use it in our program is to use **pointer variable.** Note that pointer variable is a variable and that it takes space in our memory. But it is different from normal variable that we are familiar of. 

I will continue to use **num** for the following program

```c
#include <stdio.h>

int main ()
{
	int num = 0;

	// declare a pointer varialbe using * next to the type and & next to the variable that you want to point to
	int *ptnum = &num;
	printf("To access the address of 'num' : %p\n", ptnum); // To access the address of 'num' : b40eeff...
	
	return 0;
}
```

Now, **ptnum** is a pointer variable to **num** because, we explicitly declared it as a pointer variable using * and &. 

- * is used next to the type of variable declaration to say that it will be pointer variable
- & is used when assigning the variable to a pointer variable to tell the program to assign the address of variable and not the value of it.
- %p is a format specifier of pointer variable just like %d for integer, %f for float, and so on.

Now consider two ways of changing **num** value where one will be done using the variable itself and the other using its pointer variable by dereferencing. 

```c
#include <stdio.h>

int main ()
{
	int num = 0;

	printf("num : %d\n", num); // num : 0
	
	// change the num value using num
	num ++; // num = num + 1 = 0 + 1 = 1
	
	printf("num : %d\n", num); // num : 1
	
	// change the num value using pointer variable
	int *ptnum = &num; // ptnum = address of num 
	
	// dereferencing to change the value of num
	// num is currently 1
	*ptnum = num + 1 //  num + 1 = 1 + 1 = 2
	
	printf("num : %d\n", num); // num : 2

	return 0;
}

```

One of the things that we have to be closely attentive about the pointer is where expressing **ptnum**  and ***ptnum** are not the same thing. 

- **ptnum** is just a pointer variable that stores the address of num.
- ***ptnum** is actually dereferencing expression in order to assign some value to num.

This is why if you want to print out the address of num, you have to use **ptnum** and not ***ptnum** as a printf’s second argument. 

```c
#include <stdio.h>

int main ()
{
	int num = 0;
	int *ptnum = &num;
	
	// correct expression to print address of num
	printf("address of num : %p\n", ptnum);

	// incorrect expression to print address of num
	printf("address of num : %p\n", *ptnum);
}
```

I think that was a pretty solid interpretation of general concept of pointer variable, but we have not dived into other types such as float, character, and arrays. Before we go into that I want to suggest you all to kind of memorize the memory byte take up of each variable type.

 

| Var Type | Bytes |
| --- | --- |
| int | 4 |
| float | 4 |
| long | 8 |
| double | 8 |
| char | 1 |
| array | depends... |

Further going forwards, please note that **array** in C has to be implicitly or explicitly told of its size and type as far as what we are concerned for our class. 

We are telling the size and type of array that we are declaring if

- integer array : int arr[] = {1,2,3} // we are implicitly saying the size (3) by having 3 elements
- integer array : int arr[3] // we are not assigning yet any element in arr, but explicitly saying the size of it
- char array (string) : char str[] = “Hello”; // we are implicitly saying the size (6 with null string end)
- char array (string) : char str[6]; // we are explicitly telling the size of str, but not assigning any characters in it yet.

In C, I believe that **string** is just an array of char (character). Although we’ve adjusted our mind to having a separate string type in Python, we must change that as C does not have the same kind of type. 

A single character is wrapped with ‘A’, while the string (array of char) is wrapped with “ABC”

```c
#include <stdio.h>

int main ()
{
	char singleChar = 'A'; // not an array
	char strChar[] = "A BC DEF"; // an array of char

	int num = 0; // not an array
	int numArr[] = {0, 0, 1}; // an array of int

	return 0;
}
```

## Weirdness about Array and their pointers

It is pretty clear that for a single variable type such as **int, char (single char), float, long, double,**  the pointer variable can be declared and use in the way I did with the integer **num & ptnum** earlier in this document, but **array** is not the same (array of integer, array of chars (string), array of ....), they are so confusing. In fact, this is why I did not even mention it above so that you can question yourself why it is not mentioned above. It is because I wanted to separate the pointer of array individually here. So, let’s get into it.

<aside>
💡 **In a brief sentence, array variable is the pointer variable to itself.**

</aside>

I know, wth does that mean right?

Well, this is one of those things that are just there for us to take it as it is without having to understand how it got there. So let me explain this in a more clear way.

Funny thing is that the pointer of array will only point to the address of the first element of that arr

 

```c
#include <stdio.h>

int main ()
{
	int arr[] = {1,2,3};
	int *p = arr; // address of 1, not {1,2,3} as a whole

	printf("address of arr's first element : %p\n", p);
	// address of arr's first element : 0x7fff4f32fd50
	
	return 0
}
```

This means that if you want the second element you can do the following,

```c
#include <stdio.h>

int main ()
{
	int arr[] = {1,2,3};
	int *p = arr; // address of 1, not {1,2,3} as a whole

	printf("address of arr's first element : %p\n", p);
	// address of arr's first element : 0x7fff4f32fd50

	p++; // p = p + 1
	printf("address of arr's second element : %p\n", p);
	// address of arr's second element : 0x7fff4f32fd54
	
	return 0
}
```

Suppose now that we want to declare an array of size 3, then change a specific element’s value after. To do that, we can do it using two different ways

```c
#include <stdio.h>

int main ()
{
	int arr[] = {1,2,3};
	printf("the array's first element : %d\n", arr[0]); // 1

	// change first element value using index
	arr[0] = 10;
	printf("the array's first element : %d\n", arr[0]); // 10

	// change first element value using pointer;
	int *p = arr; 
	*p = 1;
	printf("the array's first element : %d\n", arr[0]); // 1

	return 0;
}
```

Now, let’s try to involve what we call as **string (array of chars)**

Note that a character in a string takes 1 byte because it is ‘char’ a single character. This means that the total byte that the string (array of char) takes is the number of characters (including empty-spaced character) + 1. 

For example, if I have a str = “ABC” its size is 3 but takes 4 bytes. We can verify that using the following code. Try it yourself with your own string.

```c
#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "ABC";
	printf("the lengh of str array : %d\n", strlen(str)); // 3
	printf("the size in 'byte' of str array: %lu\n", sizeof(str)); // 4

	return 0;
}
```

Recall that string is also an array but with char type of its elements. This means that just like integer array we can access each element by index and change the value or using pointer (two ways, remember?)

```c
#include <stdio.h>

int main ()
{
	char str[] = "ABC Hi"; 
	printf("first character in str : %c\n", str[0]); // A
	
	// change A to Z using index
	str[0] = 'Z'; // single quote since it is a single char
	printf("first character in str : %c\n", str[0]); // Z

	// change Z back to A using pointer
	char *ptstr = str; // points the address of the first element of str == which now is the address of  Z
	printf("address of first element of str : %p\n", ptstr); // some address...
	// dereferencing to change value
	*ptstr = 'A';
	printf("first character in str : %c\n", str[0]); // A

	return 0;
}
```

## How to use pointer as an argument of a function

In programming, the scope of variable is very important, there are things that we can or cannot do because of the variable scope (where the variable was declared initially) 

suppose we have a function that just prints whatever the integer and character argument was passed to it.

```c
void printArgs(int intArg, char charArg)
{
	printf("int : %d, char : %c\n", intArg, charArg);
}

int main ()
{
	// notice how the argments are not variable rather just expression
	printArgs(100, 'A'); // int : 100, char : A

	// notice how the arguments are variable in this main function scope
	int i = 100;
	char chr = 'A';
	printArgs(i, chr); // int : 100, char : A

	return 0;
}
```

The above case did not need a pointer at all because the void function won’t change the original value. 

But if we do have a case where we want to keep the original variable but change its value when passed into a function, we have to use pointer because that will be the only way for the variable’s value to be changed since the function inside a function has its own scope. If the concept of what **block scope** and **local scope** means is difficult, I suggest that you search youtube about it and maybe try some program using Python first (since it is easier to grab the concept) 

Anyway, now I’d like to change the varialbe **int num** that will be declared in main function but change the value using **void changeInt (int *pVar, int newValue)** function

```c
void changeInt(int *pVar, int newValue)
{
	// this function returns nothing, only change the value of the variable that 'pVar' is pointing to
	// argument is pointer already, so to change the value, we just need to dereference
	*pVar = newValue;
}

int main ()
{
	/*
	** Warning, to change value of a variable, argument must be variable, not an expression
	** This means that we have to first declare it in the scope of main function
	*/
	int num = 0;
	
	// I want to change the value to 10;
	// first argument is pointer so we need to add the pointer assignment symbol & if it is not an array
	changeInt(&num, 10);
	print("num : %d\n", num); // 10;

	return 0;
}
```

In order to change an array element in such a function, it is much more complicated. 

Suppose that I have a string (array of char) “Hello”, and also suppose that I want all the ‘l’ character replaced with the capital ‘L’, then take a look at the following program

```c
#include <stdio.h>
#include <string.h>

void capitalizeL(char *strToLoop)
{
	for (unsigned i = 0; i < strlen(strToLoop); i ++)
	{
		if (strToLoop[i] == 108 /* 'l' ascii code is 108 */)
		{
			strToLoop[i] = 'L';
		}
	}
}

int main ()
{
	char str[] = "Hello";
	printf("str : %s\n", str); // Hello
	
	// change l's to L's
	capitalizeL(str);
	
	printf("str : %s\n", str); // HeLLo

	return 0;
}
```

There are more confusing things to learn about pointers, but I won’t even do that, If you guys come across a specific question about pointer, please let me know, and within my knowledge and understanding, I will respond to you!