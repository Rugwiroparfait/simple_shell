// strtoken.c

#include "shell.h"
#include <stddef.h>
#include <string.h>

/**
 * _strtok - Custom implementation of strtok
 * @str: The string to tokenize
 * @delim: The delimiter characters
 * 
 * Return: The next token or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim) {
    static char *last_token = NULL;
    char *token;
    size_t i;

    if (str != NULL) {
        last_token = str;
    } else if (last_token == NULL) {
        return NULL;
    }

    token = last_token;

    for (i = 0; last_token[i] != '\0'; i++) {
        if (strchr(delim, last_token[i]) != NULL) {
            last_token[i] = '\0';
            last_token = last_token + i + 1;
            return token;
        }
    }

    last_token = NULL;

    return token;
}

