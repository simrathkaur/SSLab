/*
============================================================================
Name : Handson List 1- ques 15
Author : Simrath Kaur
Description : Write a program to display the environmental variable of the user (use environ).
============================================================================
*/  
#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main() {
    char** env = environ;

    while (*env != NULL) {
        printf("%s\n",*env);
        env++;
    }

    return 0;
}
