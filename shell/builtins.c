// builtins.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_builtin - Handles built-in commands
 * @command: An array of command and arguments
 * 
 * Return: 1 if the command is a built-in, 0 otherwise
 */
int handle_builtin(char **command) {
    if (command == NULL || command[0] == NULL) {
        return 0;
    }

    if (_strcmp(command[0], "exit") == 0) {
        handle_exit(command);
        return 1;
    } else if (_strcmp(command[0], "setenv") == 0) {
        handle_setenv(command);
        return 1;
    } else if (_strcmp(command[0], "unsetenv") == 0) {
        handle_unsetenv(command);
        return 1;
    } else if (_strcmp(command[0], "cd") == 0) {
        handle_cd(command);
        return 1;
    }

    // Add more built-ins as needed

    return 0;
}

/**
 * handle_cd - Handles the cd built-in command
 * @command: An array containing "cd" and an optional directory argument
 */
void handle_cd(char **command) {
    char *new_dir;

    if (command[1] == NULL || _strcmp(command[1], "~") == 0) {
        new_dir = getenv("HOME");
    } else if (_strcmp(command[1], "-") == 0) {
        new_dir = getenv("OLDPWD");
    } else {
        new_dir = command[1];
    }

    if (new_dir == NULL) {
        fprintf(stderr, "cd: No home directory.\n");
        return;
    }

    if (chdir(new_dir) == -1) {
        perror("cd");
    } else {
        char *current_dir = getcwd(NULL, 0);
        if (current_dir != NULL) {
            setenv("PWD", current_dir, 1);
            free(current_dir);
        }
    }
}
/**
 * handle_exit - Handles the exit built-in command
 * @command: An array containing "exit" and an optional status argument
 */
void handle_exit(char **command) {
    int status = 0;

    if (command[1] != NULL) {
        status = _atoi(command[1]);
    }

    exit(status);
}

/**
 * handle_setenv - Handles the setenv built-in command
 * @command: An array containing "setenv", variable, and value
 */
void handle_setenv(char **command) {
    if (command[1] == NULL || command[2] == NULL || command[3] != NULL) {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return;
    }

    if (setenv(command[1], command[2], 1) == -1) {
        perror("setenv");
    }
}

/**
 * handle_unsetenv - Handles the unsetenv built-in command
 * @command: An array containing "unsetenv" and variable
 */
void handle_unsetenv(char **command) {
    if (command[1] == NULL || command[2] != NULL) {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return;
    }

    if (unsetenv(command[1]) == -1) {
        perror("unsetenv");
    }
}

