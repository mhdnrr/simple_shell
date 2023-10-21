#include "shell.h"

/**
 * parse_cmd - Parse command into tokens.
 * @cmd: The command to parse.
 * @argc: Pointer to store the number of tokens.
 *
 * Return: An array of tokens (strings).
 */

char **parse_cmd(const char *cmd, size_t *argc)
{
	size_t buffer_size = 64;
	char **tokens = (char **)malloc(buffer_size * sizeof(char *));
	char *token;
	char *saveptr;
	size_t count = 0;

	if (!tokens)
	{
		print("Error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok_r((char *)cmd, " \t\n", &saveptr);
	while (token != NULL)
	{
		tokens[count] = token;
		count++;

		if (count >= buffer_size)
		{
			buffer_size += 64;
			tokens = (char **)realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				print("Error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok_r(NULL, " \t\n", &saveptr);
	}

	tokens[count] = NULL;
	*argc = count;
	return (tokens);
}
