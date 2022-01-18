#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int** arr = (int**)malloc(6 * sizeof(int*));
    int master[6] = {7,4,6,3,7,2};
    arr[0] = (int*)malloc(master[0] * sizeof(int));
    arr[1] = (int*)malloc(master[1] * sizeof(int));
    arr[2] = (int*)malloc(master[2] * sizeof(int));
    arr[3] = (int*)malloc(master[3] * sizeof(int));
    arr[4] = (int*)malloc(master[4] * sizeof(int));
    arr[5] = (int*)malloc(master[5] * sizeof(int));
    while(true) {
        int n;
        printf("Please choose one of the function: \n");
        printf("--> Press 1 for viewing the matrix \n");
        printf("--> Press 2 for changing the number of columns \n");
        printf("--> Press 3 for exiting \n");
        printf("Your input: ");
        scanf(" %d", &n);
        printf("\n");
        if (n == 1) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < master[i]; j++) {
                    arr[i][j] = (rand() % 10)+1;
                }
            }
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < master[i]; j++) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        else if(n == 2) {
            int row, column;
            printf("Enter the row you want to access: ");
            scanf(" %d", &row);
            printf("Enter the final column length: ");
            scanf(" %d", &column);
            master[row-1] = column;
            arr[row-1] = (int*)realloc(arr[row-1], master[row] * sizeof(int));
            printf("\n");
        }

        else if(n == 3) {
            for (int i = 0; i < 6; i++) {
                free(arr[i]);
            }
            free(arr);
            break;
        }
    }    
    return 0;
}