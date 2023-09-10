/*
============================================================================
Name : Handson List 1- ques 6
Author : Simrath Kaur
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
============================================================================
*/ 
#include<stdio.h>
#include<unistd.h>
int main(){
	char buff[10];
	read(0,buff,10);
	write(1,buff,10);
	return 0;
}
