#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char name[256];
    int rlno;
    int yr;
    char prgm[256];
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

bool searchrlno(int val) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->rlno == val) 
            return true;
        temp = temp->next;
    }
    return false;
}


void insert(char n[], int rno, int y, char pro[]) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head; 

    strcpy(new_node->name,n);
    new_node->rlno = rno;
    new_node->yr = y;
    strcpy(new_node->prgm,pro);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        new_node->prev = NULL;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
    new_node->prev = last;
}

void printListf() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf(" Name: %s, Roll No.: %d, Year: %d, Program: %s ->\n", temp->name, temp->rlno, temp->yr, temp->prgm);
        temp = temp->next;
    }
    printf("\n");
}

void printListb() {
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf(" Name: %s, Roll No.: %d, Year: %d, Program: %s ->\n", temp->name, temp->rlno, temp->yr, temp->prgm);
        temp = temp->prev;
    }
    printf("\n");
}

void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
       temp = node;
       node = node->next;
       free(temp);
    }
}

int main() {
    while(true) {
        int n;
        printf("Please choose one of the function: \n");
        printf("--> Press 1 for inserting a node \n");
        printf("--> Press 2 for finding a node(roll number) \n");
        printf("--> Press 3 for printing the linkedlist in forward direction. \n");
        printf("--> Press 4 for printing the linkedlist in backward direction. \n");
        printf("--> Press 5 for exiting \n");
        printf("Your input: ");
        scanf(" %d", &n);
        if (n == 1) {
            int rl, ya;
            char nm[256], ap[256];
            printf("Enter student name: ");
            scanf("%s", nm);
            printf("Enter roll number: ");
            scanf(" %d", &rl);
            printf("Enter year of admission: ");
            scanf(" %d", &ya);
            printf("Enter academic program: ");
            scanf("%s", ap);
            insert(nm, rl, ya, ap);

        }
        else if(n == 2) {
            int rl;
            printf("Enter student roll number: ");
            scanf("%d", &rl);
            if (searchrlno(rl) == true) {
                printf("Present\n");
            }
            else {
                printf("Not present\n");
            }
        }
        else if(n == 3) {
            printListf();
        }
        else if(n == 4) {
            printListb();
        }
        else if(n == 5) {
            freeList(head);
            break;
        }
    
    
    
    }
    return 0;
}
