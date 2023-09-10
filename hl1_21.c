#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	printf("in parent process :parent process id: %d\n", getpid());
	int c=fork();
	if(c){
	  printf("in parent process: child process id: %d\n", c);
	}
	else{
		printf("in child process:\n");
		printf("parent process id: %d\n",getppid());
		printf("child process id: %d", getpid());
		}
return 0;
}
