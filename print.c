#include "shell.h"

void print(const char *pnt)
{
	write(STDOUT_FILENO, pnt, strlen(pnt));
}
