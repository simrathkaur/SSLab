#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
FILE *file = fopen("sample.txt", "r");
int fd = fileno(file);
int mode = fcntl(fd, F_GETFL);
//printf("%d",mode);
switch(mode){
    case 32768 : printf("r"); break;
    case 32769 : printf("w"); break;
    case 33793 : printf("a"); break;
    case 32770 : printf("r+ || w+"); break;
    case 32794 : printf("a+"); break;
}
return 0;
}
