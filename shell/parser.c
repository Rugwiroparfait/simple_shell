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
    char **tokens = malloc(sizeof(char *));
    int i = 0;

    char *token = _strtok(input, ";");
    while (token != NULL) {
        tokens[i++] = token;
        token = _strtok(NULL, ";");
    }
    tokens[i] = NULL;

    return tokens;
}

