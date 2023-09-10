#include<unistd.h>
#include<stdio.h>

int main() {
    FILE *file = fopen("sample1.txt", "r");

    if (file == NULL) {
        printf("File not found.\n");
        return 0;
    }

    char line[2];

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
