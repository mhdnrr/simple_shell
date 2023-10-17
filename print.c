#include "shell.h"

/*
 * Function: print
 * @print:
 * Prints the given string to the standard output
 *
 * prt: The string to be printed
 */

void print(const char *prt)
{
	write(STDOUT_FILENO, prt, strlen(prt));
}
