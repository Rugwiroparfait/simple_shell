#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_commands - Handle commands from input
 * @input: The input string containing commands
 */
void handle_commands(char *input) {
    char **commands = parse_command(input);

    for (int i = 0; commands[i] != NULL; i++) {
        char **single_command = parse_command(commands[i]);

        if (handle_builtin(single_command)) {
            continue;
        }

        execute_single_command(single_command);
        free(single_command);
    }

    free(commands);
}

