#include <stdio.h>

void bsort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ssort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int low = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[low] > arr[j]){
                low = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[low];
        arr[low] = temp;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    char chr;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter elements: ");
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter B/b for bubble sort or S/s for selection sort: ");
    scanf(" %c", &chr);
    if (chr == 'S' || chr == 's') {
        ssort(arr, n);
    }
    else if (chr == 'B' || chr == 'b') {
        bsort(arr, n);
    }
    return 0;

    

}