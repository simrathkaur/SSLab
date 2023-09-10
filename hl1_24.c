/*
============================================================================
Name : Handson List 1- ques 24
Author : Simrath Kaur
Description : Write a program to create an orphan process.
============================================================================
*/  
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
int main()
{
      
    int pid = fork();
  
    if (pid > 0)
        printf("in parent process");
  
    else if (pid == 0)
    {
        sleep(30);
        printf("in child process");
    }
  
    return 0;
}
