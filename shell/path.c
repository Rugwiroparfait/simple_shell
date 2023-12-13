#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Include the necessary header file

/**
 * find_command - Find the full path of the command using PATH
 * @command: The command to find
 * 
 * Return: The full path of the command if found, otherwise NULL
 */
char *find_command(char *command) {
    const char *path = getenv("PATH");
    char *path_copy = strdup(path);

    if (path_copy == NULL) {
        perror("simple_shell");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(path_copy, ":");
    while (token != NULL) {
        char *full_path = malloc(strlen(token) + strlen(command) + 2);
        if (full_path == NULL) {
            perror("simple_shell");
            exit(EXIT_FAILURE);
        }
        sprintf(full_path, "%s/%s", token, command);

        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

