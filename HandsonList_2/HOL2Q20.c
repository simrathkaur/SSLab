/*
 * ============================================================================
 Name : 20.c
 Author : Simrath Kaur
 Description : Write two programs so that both can communicate by FIFO -Use one way communication.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	//for writing
	int fd;
	char buff[80];
	fd = open("myfifo", O_WRONLY);
	printf("Enter the text:");
	scanf("%[^\n]", buff);
	write(fd, buff, sizeof(buff));

	/* for reading
	 * fd = open("myfifo", O_RDONLY);
	read(fd, buff, sizeof(buff));
	printf("The text from FIFO file: %s\n", buff);
	*/
	}


