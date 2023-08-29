#include<unistd.h>
#include<stdio.h>

int main() {
    const char *file_path = "sample.txt";  // Replace with the path to your file
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    char line[256];  // Assuming a maximum line length of 255 characters

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
