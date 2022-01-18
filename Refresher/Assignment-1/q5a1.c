#include <stdio.h>

void bsort( unsigned long arr[],int n) {
    for (unsigned int i = 0; i < n - 1; ++i) {
        for (unsigned int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j+1]){
                unsigned int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (unsigned int i = 0; i < n; ++i) {
        printf("%lu ", arr[i]);
    }
    printf("\n");
}

unsigned long bSearch(unsigned long array[], unsigned long x, unsigned long lo, unsigned long hi) {
    while (lo <= hi) {
        unsigned long mid = lo + (hi - lo) / 2;

        if (array[mid] == x) {
            return mid;
        }
        if (array[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    unsigned long arr[n];
    printf("\nEnter elements: ");
    for(unsigned long i = 0; i < n; ++i) {
        scanf("%lu", &arr[i]);
    }
    unsigned long x;
    printf("Enter element you want to find: ");
    scanf("%lu", &x);
    bsort(arr, n);
    int res = bSearch(arr, x, 0, n-1);
    if (res == -1) {
        printf("Element not found");
    }
    else {
        printf("Element is present at %d", res);
    }


}