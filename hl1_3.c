#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd1= creat("temp", 0744);
	printf("the file descripter value of temp file:%d", fd1);
	return 0;
}
