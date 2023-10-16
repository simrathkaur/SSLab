/*
 * ============================================================================
 Name : 26.c
 Author : Simrath Kaur
 Description : Write a program to send messages to the message queue. Check $ipcs -q

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

int main() {
	struct msg {
		long int m_type;
		char message[80];
	} myq;
	key_t key = ftok(".", 'a');
	int mqid = msgget(key, 0);
	printf("Enter message type: ");
	scanf("%ld", &myq.m_type);
	printf("Enter message text:");
	scanf("%[^\n]", myq.message);
	int size = strlen(myq.message);
	// size + 1 to accommodate terminating character
	msgsnd(mqid, &myq, size + 1, 0);
}
