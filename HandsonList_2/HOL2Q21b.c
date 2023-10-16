/*
 * ============================================================================
 Name : 21_b.c
 Author : Simrath Kaur
 Description : Write two programs so that both can communicate by FIFO -Use two way communications.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int fd1,fd2;
        char buff1[80],buff2[80];

	fd1 = open("myfifo2", O_WRONLY);
	fd2 = open("myfifo1", O_RDONLY);
	printf("Enter the text:");
	scanf(" %[^\n]", buff1);
	write(fd1, buff1, sizeof(buff1));
	read(fd2, buff2, sizeof(buff2));
	printf("The text from FIFO file: %s\n", buff2);
	}
