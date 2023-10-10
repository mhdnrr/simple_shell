#include "shell.h"

/*
 * print: custom printf function
 *
 */

void print(const char *pnt)
{
	write (STDOUT_FILENO, pnt,strlen(pnt));
}
