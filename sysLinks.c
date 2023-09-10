#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
        int h=link("original.txt", "syshardlink");
        if(h<0) {
                perror("Failed"); return 1;
        }
        int s=symlink("original.txt","syssoftlink");
        if(s<0){ perror("Failed"); return 1;}

        int f=mknod("sysFifoFile",S_IFIFO,0);
        if(f<0) perror("Failed");
        return 0;
        }

