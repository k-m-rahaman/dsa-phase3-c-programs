#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(struct Node* root) {
    if (!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(lh + rh + 1, max(ld, rd));
}