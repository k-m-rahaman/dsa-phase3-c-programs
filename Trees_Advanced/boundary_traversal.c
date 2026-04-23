#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void printLeft(struct Node* root) {
    if (!root) return;
    if (root->left) {
        printf("%d ", root->data);
        printLeft(root->left);
    }
}

void printLeaves(struct Node* root) {
    if (!root) return;
    printLeaves(root->left);
    if (!root->left && !root->right)
        printf("%d ", root->data);
    printLeaves(root->right);
}

void printRight(struct Node* root) {
    if (!root) return;
    if (root->right) {
        printRight(root->right);
        printf("%d ", root->data);
    }
}

void boundary(struct Node* root) {
    if (!root) return;

    printf("%d ", root->data);
    printLeft(root->left);
    printLeaves(root);
    printRight(root->right);
}