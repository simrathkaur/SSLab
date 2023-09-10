#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *args[] = { "ls", "-Rl", NULL };

    // Using execvp
    execvp("ls", args);

    perror("execvp");
    return 1;
}
