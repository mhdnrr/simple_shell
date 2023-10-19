#ifndef SHELL_H
#define SHELL_H
#define MAX_COMMAND_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

void print(const char *pnt);
void start_shell(void);
void read_cmd(char **cmd, size_t *size);
void execute_cmd(const char *cmd);

#endif
