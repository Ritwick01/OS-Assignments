#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char string1[256]; 
    char stringrev[256];
    int length = 0;
    printf("Input a string: ");
    scanf("%s", string1);
    while (string1[length] != '\0') {
        length++;
    }
    int end = length - 1;
    for(int i = 0; i < length; i++) {
        stringrev[i] = string1[end];
        end--;
    }
    printf("%s", stringrev);

    return 0;
}