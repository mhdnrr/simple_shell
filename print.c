#include "shell.h"

/*
 * Prints the given string to standard output
 * @print:
 *
 * pnt: The string to be printed
 */

void print(const char *prt)
{
	write(STDOUT_FILENO, prt, strlen(prt));
}
