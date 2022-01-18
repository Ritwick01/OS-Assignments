#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(front == NULL) {
        printf("Queue is Empty\n");
    }
    else {
        struct Node *temp = front;
        printf("Dequeued element is %d\n", temp->data);
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void print() {
    struct Node *temp = front;
    while(temp != NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeq() {
    struct Node *temp = front;
    while (front != NULL) {
        temp = temp->next;
        free(temp);
    }
}

int main() {
    while(true) {
        int n;
        printf("Please choose one of the function: \n");
        printf("--> Press 1 for enqueuing \n");
        printf("--> Press 2 for dequeing \n");
        printf("--> Press 3 for printing the queue \n");
        printf("--> Press 4 for exiting \n");
        printf ("Your input: ");
        scanf(" %d", &n);
        if (n == 1) {
            int m;
            printf("Enter value to be enqueued: ");
            scanf("%d", &m);
            enqueue(m);
        }
        else if(n == 2) {
            dequeue();
        }
        else if(n == 3) {
            print();
        }
        else if(n == 4) {
            freeq();
            break;
        }
    }
}