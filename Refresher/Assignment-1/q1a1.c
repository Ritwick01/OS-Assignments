#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    FILE *file1, *file2;
    char chr[50];
    if (fopen(argv[1], "rb") == NULL) {
        printf("Error in source file.");
        return 0;
    }
    else {
        file1 = fopen(argv[1], "rb");
    }
    if (fopen(argv[2], "rb") == NULL) {
        printf("Error in source file.");
        return 0;
    }
    else {
        file2 = fopen(argv[2], "wb");
    }
    
    while (!fread(&chr, sizeof(char), 1, file1)) {
        fwrite(&chr, sizeof(char), 1, file2);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}