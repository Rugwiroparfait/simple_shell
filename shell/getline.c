// getline.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _getline - Custom implementation of getline
 * 
 * Return: Pointer to the read line or NULL on failure or end of file
 */
char *_getline(void) {
    static char buffer[BUFFER_SIZE];
    static size_t buffer_index = 0;
    static ssize_t bytes_read = 0;

    char *line = NULL;
    size_t line_size = 0;

    while (1) {
        if (buffer_index >= (size_t)bytes_read) {
            // Read more data into the buffer
            bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

            if (bytes_read == 0) {
                // End of file
                return (line_size == 0) ? NULL : line;
            } else if (bytes_read < 0) {
                perror("read");
                free(line);
                return NULL;
            }

            buffer_index = 0; // Reset buffer index
        }

        // Process the current character
        char current_char = buffer[buffer_index++];
        if (current_char == '\n' || current_char == '\0') {
            // End of line
            buffer_index--; // Exclude the newline character from the line
            break;
        }

        // Append the character to the line
        line = realloc(line, line_size + 1);
        if (!line) {
            perror("realloc");
            free(line);
            return NULL;
        }

        line[line_size++] = current_char;
    }

    // Null-terminate the line
    line = realloc(line, line_size + 1);
    if (!line) {
        perror("realloc");
        free(line);
        return NULL;
    }
    line[line_size] = '\0';

    return line;
}

