#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Include for chdir
#include <limits.h>  // Include for PATH_MAX

extern char **environ;

#define PATH_MAX 4096

/**
 * exit_shell - Handles the "exit" command
 */
static void exit_shell(void)
{
    printf("Exiting shell...\n");
    exit(EXIT_SUCCESS);
}

/**
 * env_shell - Handles the "env" command
 */
static void env_shell(void)
{
    printf("Environment variables:\n");
    for (int i = 0; environ[i] != NULL; i++)
        printf("%s\n", environ[i]);
}

/**
 * cd_shell - Handles the "cd" command
 * @args: The arguments of the command
 *
 * Return: 0 on success, -1 on failure
 */
static int cd_shell(char **args)
{
    if (!args || !args[1])
    {
        fprintf(stderr, "cd: missing argument\n");
        return -1;
    }

    if (chdir(args[1]) != 0)
    {
        perror("cd");
        return -1;
    }

    return 0;
}

/**
 * echo_shell - Handles the "echo" command
 * @args: The arguments of the command
 *
 * Return: 0 on success, -1 on failure
 */
static int echo_shell(char **args)
{
    if (!args)
        return -1;

    for (int i = 1; args[i] != NULL; i++)
        printf("%s ", args[i]);

    printf("\n");
    return 0;
}

/**
 * pwd_shell - Handles the "pwd" command
 */
static void pwd_shell(void)
{
    char path[PATH_MAX];
    if (getcwd(path, PATH_MAX) != NULL)
        printf("%s\n", path);
    else
        perror("pwd");
}

/**
 * history_shell - Handles the "history" command
 */
static void history_shell(void)
{
    // Placeholder for demonstration
    printf("Command history:\n");
    printf("1. ls\n");
    printf("2. gcc -Wall -o my_program my_program.c\n");
}

/**
 * alias_shell - Handles the "alias" command
 * @args: The arguments of the command
 *
 * Return: 0 on success, -1 on failure
 */
static int alias_shell(char **args)
{
    // Placeholder for demonstration
    (void)args;
    printf("Aliases:\n");
    printf("myls='ls -la'\n");
    return 0;
}

/**
 * unset_shell - Handles the "unset" command
 * @args: The arguments of the command
 *
 * Return: 0 on success, -1 on failure
 */
static int unset_shell(char **args)
{
    // Placeholder for demonstration
    (void)args;
    printf("Unsetting variables...\n");
    return 0;
}

/**
 * set_shell - Handles the "set" command
 */
static void set_shell(void)
{
    // Placeholder for demonstration
    printf("Setting variables...\n");
}

/**
 * execute_builtin - Executes a built-in shell command
 * @args: The arguments of the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_builtin(char **args)
{
    if (!args || !args[0])
        return -1;

    // "exit" command
    if (strcmp(args[0], "exit") == 0)
    {
        exit_shell();
        return 0;
    }

    // "env" command
    if (strcmp(args[0], "env") == 0)
    {
        env_shell();
        return 0;
    }

    // "cd" command
    if (strcmp(args[0], "cd") == 0)
    {
        return cd_shell(args);
    }

    // "echo" command
    if (strcmp(args[0], "echo") == 0)
    {
        return echo_shell(args);
    }

    // "pwd" command
    if (strcmp(args[0], "pwd") == 0)
    {
        pwd_shell();
        return 0;
    }

    // "history" command
    if (strcmp(args[0], "history") == 0)
    {
        history_shell();
        return 0;
    }

    // "alias" command
    if (strcmp(args[0], "alias") == 0)
    {
        return alias_shell(args);
    }

    // "unset" command
    if (strcmp(args[0], "unset") == 0)
    {
        return unset_shell(args);
    }

    // "set" command
    if (strcmp(args[0], "set") == 0)
    {
        set_shell();
        return 0;
    }

    // Add more built-in commands as needed

    return -1; // Indicate that the command is not a built-in command
}

