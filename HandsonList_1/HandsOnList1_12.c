/*
============================================================================
Name : Handson List 1- ques 12
Author : Simrath Kaur
Description : Write a program to find out the opening mode of a file. Use fcntl.
============================================================================
*/  
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
int fd = open("sample1.txt",O_RDONLY);
int mode = fcntl(fd, F_GETFL);
switch(mode){
    case 32768 : printf("r"); break;
    case 32769 : printf("w"); break;
    case 33793 : printf("a"); break;
    case 32770 : printf("r+ || w+"); break;
    case 32794 : printf("a+"); break;
}
return 0;
}
