// utility.c
// This file will have the implementation of the commands.

#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to change the current working directory
void change_directory(char *path) {
    // Check if the path argument is NULL, which implies no specific directory was provided
    if (path == NULL) {
        // Create a buffer to store the current working directory path
        char cwd[1024];

        // Use getcwd to get the current working directory.
        // getcwd fills the array 'cwd' with the absolute pathname of the current working directory.
        // If the function succeeds, the cwd array contains this pathname and NULL is not returned.
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // If successful, print the current working directory to the user
            printf("%s\n", cwd);
        } else {
            // If getcwd fails, use perror to print an error message.
            // perror produces a message on standard error describing the last error encountered during a call to a system or library function.
            perror("getcwd() error");
        }
    } else {
        // If a path is provided, try changing the directory to the specified path using chdir
        // chdir changes the current working directory of the calling process to the directory specified in path.

        // If chdir returns a non-zero value, it indicates an error occurred (like if the directory does not exist).
        if (chdir(path) != 0) {
            // In case of an error, use perror to print the error message.
            perror("myshell");
        }
    }
}
