#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
int main() {
int i, fd;
struct {
int train_num;
int ticket_count;
} db[3];
for (i=0; i<3; i++) {
db[i].train_num = i+1;
db[i].ticket_count = 0;
}
// Writing all 3 records to record.txt file
fd = open("record.txt", O_RDWR);
write(fd, db, sizeof(db));
}
