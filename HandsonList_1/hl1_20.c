/*
============================================================================
Name : Handson List 1- ques 20
Author : Simrath Kaur
Description : Find out the priority of your running program. Modify the priority with nice command.
============================================================================
*/  
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>



int main(int argc, char* argv[]){

	struct sched_param s;
	int pid = getpid();//atoi(argv[1]);
	printf("PID: %d\n",pid);

	sched_getparam(pid,&s);
	printf("Current Priority: %d\n",s.sched_priority);

	int ret=nice(5);
	if(ret){

	sched_getparam(pid,&s);
	printf("Updated Priority: %d\n",s.sched_priority);
	}
	else perror("nice");
}
