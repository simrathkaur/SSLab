/*
============================================================================
Name : Handson List 1- ques 1
Author : Simrath Kaur
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
============================================================================
*/
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

