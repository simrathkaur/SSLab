#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
   char* envp[] = { NULL };

    // Using execle
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    perror("execle");
    return 1;
}
