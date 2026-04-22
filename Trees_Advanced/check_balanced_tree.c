#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int height(struct Node* root) {
    if (!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
        return -1;

    return 1 + (lh > rh ? lh : rh);
}

int isBalanced(struct Node* root) {
    return height(root) != -1;
}