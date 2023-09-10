/*
============================================================================
Name : Handson List 1- ques 10
Author : Simrath Kaur
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
============================================================================
*/  
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd=open("sample.txt",O_RDWR|O_CREAT);
	if(fd== -1)
	{printf("file not opened"); return 0;}
	char content[10];
	printf("enter the contents: ");
	scanf(" %[^\n]",content);
	write(fd,content,10);
	lseek(fd,10L,SEEK_CUR);
	write(fd,content,10);
	int curr=lseek(fd,0,SEEK_CUR);
	printf("the current offset value: %d \n",curr);
	return 0;
}

