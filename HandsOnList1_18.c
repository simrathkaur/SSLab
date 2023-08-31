#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

#define NUM_RECORDS 3
#define RECORD_SIZE 64

int file_fd;
pthread_mutex_t file_mutex;
pthread_rwlock_t record_locks[NUM_RECORDS];

void init() {
    file_fd = open("employee_record.txt", O_RDWR | O_CREAT, 0666);
    if (file_fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < NUM_RECORDS; i++) {
        pthread_rwlock_init(&record_locks[i], NULL);
    }
    
    pthread_mutex_init(&file_mutex, NULL);
}
void cleanup() {
    close(file_fd);
    for (int i = 0; i < NUM_RECORDS; i++) {
        pthread_rwlock_destroy(&record_locks[i]);
    }
    pthread_mutex_destroy(&file_mutex);
}

void read_record(int record_id, char *buffer) {
    pthread_rwlock_rdlock(&record_locks[record_id]);
    lseek(file_fd, record_id * RECORD_SIZE, SEEK_SET);
    read(file_fd, buffer, RECORD_SIZE);
    pthread_rwlock_unlock(&record_locks[record_id]);
}

void write_record(int record_id, const char *data) {
    pthread_rwlock_wrlock(&record_locks[record_id]);
    lseek(file_fd, record_id * RECORD_SIZE, SEEK_SET);
    write(file_fd, data, RECORD_SIZE);
    pthread_rwlock_unlock(&record_locks[record_id]);
}

int main() {
    init();

    // Example usage
    char buffer[RECORD_SIZE];

    // Read record 1
    read_record(1, buffer);
    printf("Record 1 content: %s\n", buffer);

    // Write to record 1
    const char *newData = "New data for record 1";
    write_record(1, newData);

    cleanup();
    return 0;
}
