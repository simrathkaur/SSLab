#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Using execl
    execl("/bin/ls", "ls", "-Rl", NULL);
    perror("execl");
    return 1;
}
