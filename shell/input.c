/* input.c */

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_input - Read a line of input from the user
 *
 * Return: The input string
 */
char *read_input(void) {
    char *input = NULL;
    size_t bufsize = 0;

    printf("Enter command: ");
    getline(&input, &bufsize, stdin);

    return input;
}

