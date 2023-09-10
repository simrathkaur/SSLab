/*
============================================================================
Name : Handson List 1- ques 27
Author : Simrath Kaur
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *args[] = { "/bin/ls", "-Rl", NULL };

    // Using execv
    execv("/bin/ls", args);
    
    perror("execv");
    return 1;
}
