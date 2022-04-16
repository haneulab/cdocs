#include <stdio.h>

// function declarations
int foo()
{

    return 0;
}
float bar()
{
    return 1.52;
}
char* str_foo()
{
    // return string
    return "Hello World!";
}
void nada()
{
    printf("nada running, returns nothig\n");
}

// parameter application to function declaration
void whoIsGreater(int a, int b)
{
    a > b ? printf("a : %d > b : %d\n", a, b) : a == b ? printf("a : %d == b : %d\n", a, b) : printf("a : %d < b : %d\n", a, b);
}

int sumInts(int x, int y)
{
    printf("Adding x : %d & y : %d\n", x, y);

    return x + y;
}

int main()
{
    printf("foo returned : %d\n", foo());
    printf("bar returned : %.2f\n", bar());
    printf("str_foo returned : %s\n", str_foo());
    nada();

    whoIsGreater(5, -5);
    printf("sum is : %d\n", sumInts(1,2));
    return 0;
}