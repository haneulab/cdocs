/**
 * @file exampleFile.c : <filename>.<fileExtension>
 * @author Haneul Choi (hanchoi@ucdavis.edu) : <yourname> (<youremail> or <yourdomain>)
 * @brief This is an example C file to show contributors how to start a new file that they want to add. : <brief description>
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#define MAX_MESSAGE_LEN 50

/**
 * @brief printMessage function prints the message passed as an argument. If the message points to NULL, return 0. Otherwise, prints and returns 1.
 *
 * @param char* message
 * @return int 0 || 1 : 0 failed to print, 1 succeeded to print
 */
int printMessage(char *message)
{
    if (!message)
    {
        return 0;
    }

    printf("message: %s", message);
    return 1;
}
/**
 * @brief main program of exampleFile.c
 *
 * @return int : returns program ending state # echo $?
 */
int main()
{
    char message[MAX_MESSAGE_LEN];

    printf("Enter Your Message To Display : ");
    fgets(message, sizeof(message), stdin);
    printMessage(message);

    return 1;
}