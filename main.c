#include "shell.h"
/**
 * main - Entry Point.
 *
 * Return: 0.
 */
int main(void)
{
	char *command = NULL;
	size_t n = 0;
	ssize_t read;

	while (1)
	{
		print_prompt("#cisfun$");
		read = getline(&command, &n, stdin);
		if (read == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		execute_command(command);
	}

		free(command);
		return (0);
}



