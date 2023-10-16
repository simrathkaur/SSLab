/*
 * ============================================================================
 Name : 27.c
 Author : Simrath Kaur
 Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>
#include <unistd.h>
int main() {
	struct msg {
	long int m_type;
	char message[80];
	} myq;
	key_t key = ftok(".", 'a');
	int mqid = msgget(key, 0);
	printf("Enter message type: ");
	scanf("%ld", &myq.m_type);
	//IPC_NOWAIT 
	int ret = msgrcv(mqid, &myq, sizeof(myq.message), myq.m_type,IPC_NOWAIT|MSG_NOERROR);
	if (ret == -1)
	exit(-1);
	printf("Message type: %ld\n Message: %s\n", myq.m_type, myq.message);

	//0 flag
	ret = msgrcv(mqid, &myq, sizeof(myq.message), myq.m_type,0);
        if (ret == -1)
        exit(-1);
        printf("Message type: %ld\n Message: %s\n", myq.m_type, myq.message);

}

