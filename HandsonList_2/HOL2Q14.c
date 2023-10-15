/*
 * ============================================================================
 Name : 14.c
 Author : Simrath Kaur
 Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
 the monitor.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
	int a[2];
	char buff[10];
	if(pipe(a) ==-1){
		perror("pipe");
		exit(1);

	}
	write(a[1],"code",5);

	read(a[0],buff,5);
	printf("%s\n",buff);
}
