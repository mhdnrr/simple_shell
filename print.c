#include "shell.h"

/*
 * Description: standard library functions like printf()
 *
 */

void print(const char *pnt)
{
	write(STDOUT_FILENO, pnt, strlen(pnt));
}
