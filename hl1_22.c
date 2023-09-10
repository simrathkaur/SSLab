#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
        int op=open("hl1.txt",O_RDWR|O_CREAT);
        fork();
        char buff[]="hey";
        write(op,&buff,sizeof(buff));
        return 0;
}
