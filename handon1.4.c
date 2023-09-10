#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
        int fd1= open("temp", O_CREAT|O_EXCL);
        printf("the file descripter value of temp file:%d", fd1);
        return 0;
}

