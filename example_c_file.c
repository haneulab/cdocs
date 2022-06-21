/**
 * @file example_c_file.c
 * @author your name (you@domain.com) // email is optional but please put your name
 * @brief this file shows the example template for writing a file with .c extension
 * @date 2022-06-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

/**
 * @brief foo function take integer 'num' and string 'name'
 * if name is NULL, return immediately, otherwise print both num and name
 *
 * @param num : int
 * @param name : char *
 */
void foo(int num, char *name)
{
    if (!name)
        return;

    printf("num : %d\n", num);
    printf("name : %s\n", name);
}

int main()
{
    foo(10, "Bill Gates");

    return 0;
}