/*
 * ============================================================================
 Name : 31.c
 Author : Simrath Kaur
 Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main() {
    key_t key = ftok("/tmp/semaphore_key", 1); // Generate a unique key

    // Create a binary semaphore and initialize its value to 1
    int binarySemaphore = semget(key, 1, IPC_CREAT | 0666);
    if (binarySemaphore == -1) {
        perror("semget");
        exit(1);
    }

    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } sem_union;

    sem_union.val = 1; // Initial value for the binary semaphore
    if (semctl(binarySemaphore, 0, SETVAL, sem_union) == -1) {
        perror("semctl");
        exit(1);
    }

    printf("Binary semaphore created with ID: %d\n", binarySemaphore);

    // Create multiple counting semaphores (e.g., 3 semaphores)
    int numSemaphores = 3;
    int countingSemaphore;
    
    for (int i = 0; i < numSemaphores; i++) {
        countingSemaphore = semget(key + i + 1, 1, IPC_CREAT | 0666);
        if (countingSemaphore == -1) {
            perror("semget");
            exit(1);
        }

        sem_union.val = 3; // Initial value for each counting semaphore
        if (semctl(countingSemaphore, 0, SETVAL, sem_union) == -1) {
            perror("semctl");
            exit(1);
        }

        printf("Counting semaphore %d created with ID: %d\n", i, countingSemaphore);
    }

    return 0;
}
