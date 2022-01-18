#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
  
int main() {   
    int n;
    printf("Enter 1 for swapping variables or 2 for swapping arrays: ");
    scanf("%d", &n);
    printf("\n");
    if (n == 1) {
        int n1, n2;
        printf("Enter n1 = ");
        scanf("%d", &n1);
        printf("\n");
        printf("Enter n2 = ");
        scanf("%d", &n2);
        printf("\n");
        swap(&n1, &n2);
        printf("After Swapping: \nn1 = %d \nn2 = %d", n1, n2);
    }
    if (n == 2) {
        int l;
        printf("Enter length of the arrays = ");
        scanf("%d", &l);
        printf("\n");
        int n1[l], n2[l];
        printf("Enter elements of first array (spaced):");
        for(int i = 0; i < l; i++) {
            scanf("%d", &n1[i]);
        }
        printf("\n");
        printf("Enter elements of second array (spaced):");
        for(int i = 0; i < l; i++) {
            scanf("%d", &n2[i]);
        }
        printf("\nFirst array before swapping: ");
        for(int i = 0; i < l; i ++) {
            printf(" %d",n1[i]);
        }
        printf("\nSecond array before swapping: ");
        for(int i = 0; i < l; i ++) {
            printf(" %d",n2[i]);
        }
        for(int i = 0; i < l; i++) {
            swap(&n1[i], &n2[i]);
        }
        printf("\nFirst array after swapping: ");
        for(int i = 0; i < l; i ++) {
            printf(" %d",n1[i]);
        }
        printf("\nSecond array after swapping: ");
        for(int i = 0; i < l; i ++) {
            printf(" %d",n2[i]);
        }
    }
    
    return 0;

}