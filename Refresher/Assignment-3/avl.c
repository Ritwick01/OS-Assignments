#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};

struct Node *makeNode(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getheight(struct Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getmax(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int balancefact(struct Node *N) {
    if (N == NULL) {
        return 0;
    }
    return (getheight(N->left) - getheight(N->right));
}

struct Node *minimum(struct Node *node) {
    struct Node *element = node;
    while (element != NULL) {
        element = element->left;
    }
    return element;
}

struct Node *leftRotate(struct Node *nodeleft) {
    struct Node *noderight = nodeleft->right;
    struct Node *temp = noderight->left;
    noderight->left = nodeleft;
    nodeleft->right = temp;
    nodeleft->height = 1 + getmax(getheight(nodeleft->left), getheight(nodeleft->right));
    noderight->height = 1 + getmax(getheight(noderight->left), getheight(noderight->right));
    return noderight;
}

struct Node *rightRotate(struct Node *noderight) {
    struct Node *nodeleft = noderight->left;
    struct Node *temp = nodeleft->right;
    nodeleft->right = noderight;
    noderight->left = temp;
    noderight->height = 1 + getmax(getheight(noderight->left), getheight(noderight->right));
    nodeleft->height = 1 + getmax(getheight(nodeleft->left), getheight(nodeleft->right));
    return nodeleft;
}

struct Node *insert(struct Node *node, int val) {
    if (node == NULL) {
        return makeNode(val);
    }
    if (val < node->key) {
        node->left = insert(node->left, val);
    }
    else if (val > node->key){
        node->right = insert(node->right, val);
    }
    else {
        return node;
    }

    node->height = 1 + getmax(getheight(node->left),getheight(node->right));
    int balance = balancefact(node);
    
    if (balance > 1) {
        if (val < node->left->key) {
            return rightRotate(node);
        }
        else if (val > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balance < -1) {
        if (val > node->right->key) {
            return leftRotate(node);
        }
        else if (val < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;

    
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
        if ((node->left == NULL) || (node->right == NULL)) {
            struct Node *temp = NULL;
            if (node->left == temp) {
                temp = node->right; 
            } 
            else {
                temp = node->left;
            }
            if (temp == NULL){
                temp = node;
                node = NULL;
            }
            else {
                *node = *temp;
                free(temp);
            }
        }
        else {
            struct Node *temp = minimum(node->right);
            node->key = temp->key;
            node->right = delete(node->right, temp->key);
        }
    }

    if (node == NULL) {
        return node;
    }

    node->height = 1 + getmax(getheight(node->left),getheight(node->right));
    int balance = balancefact(node);
    
    if (balance > 1) {
        if (0 <= balancefact(node->left)) {
            return rightRotate(node);
        }
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balance < -1) {
        if (0 >= balancefact(node->right)) {
            return leftRotate(node);
        }
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
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
        printf("--> Press 3 for printing the tree \n");
        printf("--> Press 4 for exiting \n");
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
                root = insert(root,m);
            }
        }
        else if(n == 2) {
            int t;
            printf("Enter value of the node: ");
            scanf(" %d", &t);
            root = delete(root, t);
        }
        else if(n == 3) {
            printi(root);
            printf("\n");
            printpre(root);
            printf("\n");
            printpos(root);
            printf("\n");
        }
        else if(n == 4) {
            freeall(root);
            break;
        }
    
    }
    return 0;
}