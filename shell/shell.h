// shell.h

#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#define MAX_TOKENS 100

/* Function prototypes */
void display_prompt(void);
char *_getline(void);
char **parse_command(char *input);
void execute_command(char **command);
char *find_command(char *command);
int handle_builtin(char **command);
int handle_env(void);
char *_strtok(char *str, const char *delim);
int _strcmp(const char *s1, const char *s2);
int _atoi(const char *s);
void handle_exit(char **command);
void handle_setenv(char **command);
void handle_unsetenv(char **command);
void handle_cd(char **command);
void handle_commands(char *input);

#endif /* SHELL_H */

