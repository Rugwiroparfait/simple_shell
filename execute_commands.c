#include "shell.h"
/**
 *execute_command - it executes the commands.
 * @command: pointer to char.
 *
 * Return: 0.
 */
int execute_command(char *command)
{
	int i = 0;
	char *args[1024];
	pid_t pid;
	char *token;
	int status = 0;

	token = strtok(command, " \n");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("error");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}
