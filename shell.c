#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * print_prompt - Display the prompt.
 */
void print_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * execute_command - Execute the specified command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		print_prompt();

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break; /* End of file (Ctrl+D) */
		}

		buffer[strcspn(buffer, "\n")] = '\0'; /* Remove the newline character */

		if (strcmp(buffer, "exit") == 0)
			break; /* User entered "exit" */

		execute_command(buffer);
	}

	printf("\n");

	return (0);
}

