#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *makeNode(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *node, int val) {
    if (node == NULL) {
        return makeNode(val);
    }
    if (val < node->key) {
        node->left = insert(node->left, val);
    }
    else {
        node->right = insert(node->right, val);
    }
    return node;
}

struct Node *search(struct Node *node, int val) {
    if (node == NULL || node->key == val)
       return node;
    
    if (node->key < val)
       return search(node->right, val);
 
    return search(node->left, val);
}
struct Node *minimum(struct Node *node) {
    struct Node *element = node;
    while (element->left != NULL) {
        element = element->left;
    }
    return element;
}

struct Node *delete(struct Node *node, int val) {
    if (node == NULL) {
        return node;
    }

    if (val < node->key) {
        node->left = delete(node->left, val);
    }
    else if (val > node->key) {
        node->right = delete(node->right, val);
    }
    else {
        if (node->left == NULL) {
            struct Node *temp = node->right;
            free(node);
            return temp;
        } 
        else if (node->right == NULL) {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }

        struct Node *temp = minimum(node->right);
        node->key = temp->key;
        node->right = delete(node->right, temp->key);
    }
    return node;
}

void printi(struct Node *node) {
    if(node == NULL) {
        return;
    }
    printi(node->left);
    printf("%d -> ",node->key);
    printi(node->right);
}

void printpre(struct Node *node) {
    if(node == NULL) {
        return;
    }
    printf("%d -> ",node->key);
    printpre(node->left);
    printpre(node->right);
}

void printpos(struct Node *node) {
    if(node == NULL) {
        return;
    }
    printpos(node->left);
    printpos(node->right);
    printf("%d -> ",node->key);
}

void freeall(struct Node *node) {
    if (node == NULL)
        return;
    freeall(node->left);
    freeall(node->right);
    free(node);

}

int main() {
    struct Node *root = NULL;
    while(true) {
        int n;
        int count = 0;
        printf("Please choose one of the function: \n");
        printf("--> Press 1 for inserting a node \n");
        printf("--> Press 2 for deleting a node \n");
        printf("--> Press 3 for searching a node \n");
        printf("--> Press 4 for printing the tree \n");
        printf("--> Press 5 for exiting \n");
        printf ("Your input: ");
        scanf(" %d", &n);
        if (n == 1) {
            int m;
            printf("Enter value of the node: ");
            scanf("%d", &m);
            if (count == 0) {
                root = insert(root, m);
                count++;
            }
            else {
                insert(root,m);
            }
        }
        else if(n == 2) {
            int m;
            printf("Enter value of the node: ");
            scanf(" %d", &m);
            root = delete(root, m);
        }
        else if(n == 3) {
            int m;
            printf("Enter value of the node: ");
            scanf(" %d", &m);
            struct Node *new = search(root, m);
            if (new == NULL) {
                printf("NOT PRESENT");
            }
            else {
                printf("PRESENT");
                printf("\n");
            }
        }
        else if(n == 4) {
            printi(root);
            printf("\n");
            printpre(root);
            printf("\n");
            printpos(root);
            printf("\n");
        }
        else if(n == 5) {
            freeall(root);
            break;
        }
    
    }
    return 0;
}

