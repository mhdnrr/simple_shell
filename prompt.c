#include"shell.h"

/**
 * start_shell - Starts the shell and prompts the user for input.
 */

void start_shell(void)
{
	char *cmd = NULL;
	size_t size = 0;

	print("shell$ ");
	read_cmd(&cmd, &size);
	execute_cmd(cmd);

	free(cmd);
}
