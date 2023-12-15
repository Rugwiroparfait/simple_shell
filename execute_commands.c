#include "shell.h"
/**
 *execute_command - it executes the commands.
 * @command: pointer to char.
 *
 * Return: 0.
 */
int execute_command(char *command)
{
	char *args[] = {command, NULL};
	pid_t pid;
	int status = 0;

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
