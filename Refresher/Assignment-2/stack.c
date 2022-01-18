#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void push(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void pop() {
    if(head == NULL) {
        printf("Stack is Empty\n");
    }
    else {
        struct Node *temp = head;
        printf("Poped element = %d\n", temp->data);
        head = head->next;
        free(temp);
    }
}

void peek() {
    if(head == NULL) {
        printf("Stack is Empty\n");
    }
    else {
        printf("Element at top = %d\n", head->data);
    }
}

void print() {
    struct Node *temp = head;
    while(temp != NULL) {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("\n");
}

int main() {
    while(true) {
        int n;
        printf("Please choose one of the function: \n");
        printf("--> Press 1 for pushing a node \n");
        printf("--> Press 2 for popping the node \n");
        printf("--> Press 3 for peeking at the stack \n");
        printf("--> Press 4 for printing the stack \n");
        printf("--> Press 5 for exiting \n");
        printf ("Your input: ");
        scanf(" %d", &n);
        if (n == 1) {
            int m;
            printf("Enter value to be pushed: ");
            scanf("%d", &m);
            push(m);
        }
        else if(n == 2) {
            pop();
        }
        else if(n == 3) {
            peek();
        }
        else if(n == 4) {
            print();
        }
        else if(n == 5) {
            break;
        }
    }
}