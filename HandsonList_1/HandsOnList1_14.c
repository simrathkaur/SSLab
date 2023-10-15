/*
============================================================================
Name : Handson List 1- ques 14
Author : Simrath Kaur
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
============================================================================
*/  
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("invalid arguments");
        return 1;
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    if (S_ISREG(file_stat.st_mode)) {
        printf("regular file.\n");
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("directory");
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("symbolic link.");
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("FIFO/pipe");
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("socket");
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("special file");
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("character special file");
    } else {
        printf(" unknown type ");
    }

    return 0;
}
