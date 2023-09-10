#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
    int policy;
    struct sched_param param;

    // Get the current scheduling policy and parameters
    int pid = getpid();
    if ((policy = sched_getscheduler(pid)) == -1) {
        perror("sched_getscheduler");
        return 1;
    }
    printf("Current scheduling policy: ");
    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    struct sched_param new_param;
    new_param.sched_priority = 99;

    if (sched_setscheduler(pid, SCHED_FIFO, &new_param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }
    printf("\nSetting scheduling policy to SCHED_FIFO...\n");

    // Get the new scheduling policy and parameters
    if ((policy = sched_getscheduler(pid)) == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("New scheduling policy: ");
    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
    return 0;
}
