// shell.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * handle_commands - Handles commands separated by ';'
 * @input: The command string
 */
void handle_commands(char *input) {
    char **commands = parse_command(input);
    int i = 0;
    while (commands[i] != NULL) {
        char **tokens = parse_command(commands[i]);
        execute_command(tokens);
        free(tokens);
        i++;
    }
    free(commands);
}

