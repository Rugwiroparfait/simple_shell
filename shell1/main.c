

#include "shell.h"
#include <stdio.h>

int main(void) {
    char *command;

    display_prompt();
    command = _getline();
    execute_command(parse_command(command));

    return 0;
}

