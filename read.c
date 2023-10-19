#include "shell.h"

/*
 * Reads a command from standard input and stores it in a buffer.
 * @cmd: A pointer to a character pointer that will store the command.
 * @size: A pointer to a size_t variable that will store the size of the buffer.
 */

void read_cmd(char **cmd, size_t *size)
{

	ssize_t n = getline(cmd, size, stdin);

	if (n == -1)
	{
		if (feof(stdin))
		{

			print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{

			print("Error\n");
			exit(EXIT_FAILURE);
		}
	}

	(*cmd)[strlen(*cmd) - 1] = '\0';
}
