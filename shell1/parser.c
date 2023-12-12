// parser.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * parse_command - Parse the input command into an array of tokens
 * @input: The input command
 * 
 * Return: An array of tokens (commands and arguments)
 */
char **parse_command(char *input) {
    char **tokens = NULL;
    char *token;

    if (!input)
        return NULL;

    tokens = malloc(sizeof(char *));
    if (!tokens) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = _strtok(input, ";");
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;

        tokens = realloc(tokens, (i + 1) * sizeof(char *));
        if (!tokens) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        token = _strtok(NULL, ";");
    }

    tokens[i] = NULL;

    return tokens;
}

