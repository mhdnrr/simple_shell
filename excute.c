#include "shell.h"

/**
 * execute_cmd - Executes the given command using a child process.
 * @cmd: The command to execute.
 */

void execute_cmd(char *cmd)
{
	char *arguments[MAX_ARGUMENTS];
	int i = 0;

	char *token = strtok(cmd, " ");
	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
		arguments[i++] = token;
		token = strtok(NULL, " ");
	}
	arguments[i] = NULL;

	pid_t pid = fork();
	if (pid == -1)
	{
		print("Fork failed\n");
		return;
	}
	else if (pid == 0)
	{
		execvp(arguments[0], arguments);
		print("Command not found\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
