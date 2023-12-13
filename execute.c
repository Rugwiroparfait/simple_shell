// execute.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_single_command(char **command);

/**
 * execute_command - Execute a command in a child process
 * @command: The command and its arguments
 */
void execute_command(char **command) {
    if (handle_builtin(command)) {
        return;  // The command is a built-in, no need to fork
    }

    pid_t pid;
    int status;

    char *command_path = find_command(command[0]);
    if (command_path == NULL) {
        fprintf(stderr, "simple_shell: %s: command not found\n", command[0]);
        return;
    }

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execv(command_path, command) == -1) {
            perror("simple_shell");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        /* Forking error */
        perror("simple_shell");
    } else {
        /* Parent process */
        waitpid(pid, &status, WUNTRACED);
    }

    free(command_path);
     int i = 0;
    while (command[i] != NULL) {
        // Execute each command separately
        char *single_command = command[i];
        char **single_tokens = parse_command(single_command);
        if (single_tokens[0] != NULL) {
            if (!handle_builtin(single_tokens)) {
                pid_t pid = fork();
                if (pid == -1) {
                    perror("fork");
                } else if (pid == 0) {
                    // Child process
                    execute_single_command(single_tokens);
                    exit(EXIT_FAILURE);
                } else {
                    // Parent process
                    wait(NULL);
                }
            }
        }
        free(single_tokens);
        i++;
    }
}

