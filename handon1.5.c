/*
============================================================================
Name : Handson List 1- ques 5
Author : Simrath Kaur
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
============================================================================
*/  #include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	
		int f1=creat("temp1",0744);
		int f2=creat("temp2",0744);
		int f3=creat("temp3",0744);
		int f4=creat("temp4",0744);
		int f5=creat("temp5",0744);
	for(;;);
}

