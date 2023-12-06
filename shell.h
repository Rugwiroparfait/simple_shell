// shell.h

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */

/* _atoi.c */
int is_digit(char c);
int _atoi_recursive(char *str, int sign);
int _atoi(char *str);


/* builtin.c */
int execute_builtin(char **args);

/* builtin1.c */
/* Add prototypes for functions in builtin1.c */

/* environ.c */
/* Add prototypes for functions in environ.c */

/* errors.c */
/* Add prototypes for functions in errors.c */

/* error1.c */
/* Add prototypes for functions in error1.c */

/* exits.c */
/* Add prototypes for functions in exits.c */

/* getLine.c */
/* Add prototypes for functions in getLine.c */

/* getenv.c */
/* Add prototypes for functions in getenv.c */

/* getinfo.c */
/* Add prototypes for functions in getinfo.c */

/* history.c */
/* Add prototypes for functions in history.c */

/* lists.c */
/* Add prototypes for functions in lists.c */

/* main.c */
/* Add prototypes for functions in main.c */

/* memory.c */
/* Add prototypes for functions in memory.c */

/* parser.c */
/* Add prototypes for functions in parser.c */

/* realloc.c */
/* Add prototypes for functions in realloc.c */

/* shell_loop.c */
/* Add prototypes for functions in shell_loop.c */

/* string.c */
/* Add prototypes for functions in string.c */

/* string1.c */
/* Add prototypes for functions in string1.c */

/* tokenizer.c */
/* Add prototypes for functions in tokenizer.c */

/* vars.c */
/* Add prototypes for functions in vars.c */

#endif /* SHELL_H */

