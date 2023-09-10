/*
============================================================================
Name : Handson List 1- ques 4
Author : Simrath Kaur
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
============================================================================
*/  #include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
        int fd1= open("temp", O_CREAT|O_EXCL);
        printf("the file descripter value of temp file:%d", fd1);
        return 0;
}

