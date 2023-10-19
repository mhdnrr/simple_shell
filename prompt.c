#include"shell.h"

/**
 * start_shell - Starts the shell and prompts the user for input.
 */

void start_shell(void)
{
	char cmd[MAX_COMMAND_LENGTH];

	print("shell$ ");
	while (fgets(cmd, sizeof(cmd), stdin) != NULL)
	{
		cmd[strcspn(cmd, "\n")] = '\0';

		execute_cmd(cmd);

		print("shell$ ");
	}

	print("\n");
}
