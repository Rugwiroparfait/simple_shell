// main.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *input = NULL;
    size_t len = 0;
    FILE *stream = stdin;

    while (1)
    {
        display_prompt();

        if (getline(&input, &len, stream) == -1)
        {
            if (isatty(STDIN_FILENO))
                putchar('\n');
            break;
        }

        handle_commands(input);

        if (isatty(STDIN_FILENO))
            free(input);
        else
            break;
    }

    return EXIT_SUCCESS;
}

