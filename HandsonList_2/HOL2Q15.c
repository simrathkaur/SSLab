/*
 * ============================================================================
 Name : 15.c
 Author : Simrath Kaur
 Description : Write a simple program to send some data from parent to the child process.
 
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	char buff[80];
	int fd[2];
	pipe(fd);
	if (fork()) {
	close(fd[0]); // Close read-end of pipe for parent
	printf("Enter message to the child: ");
	scanf(" %[^\n]", buff); // Read till newline encountered
	write(fd[1], buff, sizeof(buff));
	}
	else {
	close(fd[1]); // Close write-end of pipe for child
	read(fd[0], buff, sizeof(buff));
	printf("Message from parent: %s\n", buff);
	}
	
}
