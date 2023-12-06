#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024

int main(void)
{
    char input[MAX_INPUT_SIZE];
    char *args[MAX_INPUT_SIZE];
    int status = 0;

    while (1)
    {
        printf("($) ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove the trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Tokenize the input into arguments
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Null-terminate the array

        // Execute the built-in command or external command
        status = execute_builtin(args);

        if (status == -1)
        {
            // Placeholder for external command execution
            printf("Executing external command: %s\n", args[0]);
        }
    }

    return 0;
}

