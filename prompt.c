#include"shell.h"

/**
 * start_shell - Starts the shell and prompts the user for input.
 */

void start_shell(void)
{
	char **args;
	size_t argc;
	char *cmd = NULL;
	size_t size = 0;

	print("#cisfun$ ");
	read_cmd(&cmd, &size);


	args = parse_cmd(cmd, &argc);

	execute_cmd((const char **)args);

	free(cmd);
	free(args);
}
