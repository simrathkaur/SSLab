/*
============================================================================
Name : Handson List 1- ques 22
Author : Simrath Kaur
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
============================================================================
*/  
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
        int op=open("hl1.txt",O_RDWR|O_CREAT);
        fork();
        char buff[]="hey";
        write(op,&buff,sizeof(buff));
        return 0;
}
