#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2, pid3, status;

    if ((pid1 = fork()) == 0) {
        printf("Child 1 (PID: %d) is running.\n", getpid());
        exit(0);
    }
    if ((pid2 = fork()) == 0) {
        printf("Child 2 (PID: %d) is running.\n", getpid());
        exit(0);
    }

    if ((pid3 = fork()) == 0) {
        printf("Child 3 (PID: %d) is running.\n", getpid());
        exit(0);
    }

    // Parent process waits for pid1
    int waited_pid = waitpid(pid1, &status, 0);
    if(waited_pid==-1) printf("error");

    if (WIFEXITED(status)||(WIFSIGNALED(status))){
		    printf("child-1 done");
		    } 

    return 0;
}
