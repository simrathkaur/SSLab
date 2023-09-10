/*
============================================================================
Name : Handson List 1- ques 8
Author : Simrath Kaur
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
============================================================================
*/  
#include<unistd.h>
#include<stdio.h>

int main() {
    FILE *file = fopen("sample1.txt", "r");

    if (file == NULL) {
        printf("File not found.\n");
        return 0;
    }

    char line[2];

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
