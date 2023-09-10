#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *args[] = { "/bin/ls", "-Rl", NULL };

    // Using execv
    execv("/bin/ls", args);
    
    perror("execv");
    return 1;
}
