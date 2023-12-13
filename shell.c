/* shell.c */

#include "shell.h"

void run_shell(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		read_command(command);

		/* Execute the command */
		execute_command(command);
	}
}

