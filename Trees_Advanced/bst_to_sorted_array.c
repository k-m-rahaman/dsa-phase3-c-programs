#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void inorder(struct Node* root) {
    if (!root) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}