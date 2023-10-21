



void execute_command(const char *command) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        leo_print("Error forking process.\n");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process

        // Parse the command and its arguments
        char *args[128]; // Maximum 128 arguments (adjust as needed)
        int arg_count = 0;

        char *token = strtok((char *)command, " ");
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL; // Null-terminate the arguments array

        // Execute the command
        execvp(args[0], args);

        // If execvp fails, print an error message
        leo_print("Error executing command.\n");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);
    }
}


void leo_print(const char *message) {
    write(STDOUT_FILENO, message, strlen(message));
}


void display_prompt(void) {
    leo_print("leo_shell$$$$$ ");
}


/*
 *
 */

int main(void) {
    char command[120];

    while (true) {
        display_prompt();
        read_command(command, sizeof(command));
        execute_command(command);
    }





    

    return 0;
}

#ifndef SHELL_H
#define SHELL_H
/*
 *The kjxjhcjxh
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
 *thebse aibfbskf
 */
void display_prompt(void);
void leo_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(const char *command);




#endif /* SHELL_H */


void read_command(char *command, size_t size) {
    if (fgets(command, size, stdin) == NULL) {
        if (feof(stdin)) {
            leo_print("\n");
            exit(EXIT_SUCCESS);
        } else {
            leo_print("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    command[strcspn(command, "\n")] = '\0'; // Remove newline
}
