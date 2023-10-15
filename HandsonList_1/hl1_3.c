/*
============================================================================
Name : Handson List 1- ques 3
Author : Simrath Kaur
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
============================================================================
*/#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd1= creat("temp", 0744);
	printf("the file descripter value of temp file:%d", fd1);
	return 0;
}
