// commands.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Include necessary headers

/**
 * execute_single_command - Executes a single command
 * @command: An array of command and arguments
 */
void execute_single_command(char **command) {
    char *path = find_command(command[0]);
    if (path != NULL) {
        execve(path, command, NULL);
    } else {
        fprintf(stderr, "%s: command not found\n", command[0]);
        exit(EXIT_FAILURE);
    }
}

