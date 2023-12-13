#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 1024

/* Function prototypes */
void display_prompt(void);
void read_command(char *buffer);
void execute_command(char *command);

#endif /* SHELL_H */

