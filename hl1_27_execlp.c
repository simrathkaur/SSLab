#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Using execlp
    execlp("ls", "ls", "-Rl", NULL);
    perror("execlp");
    return 1;
}
