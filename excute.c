#include "shell.h"

/*
 * execute_cmd - Executes the given command using a child process.
 * @cmd: The command to execute.
 */

void execute_cmd(const char *cmd)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		print("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execlp(cmd, cmd, NULL);
		print("Error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
