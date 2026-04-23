#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

void zigzag(struct Node* root) {
    if (!root) return;

    struct Node* current[MAX];
    struct Node* next[MAX];
    int top1 = -1, top2 = -1;
    int leftToRight = 1;

    current[++top1] = root;

    while (top1 >= 0) {
        struct Node* temp = current[top1--];
        printf("%d ", temp->data);

        if (leftToRight) {
            if (temp->left) next[++top2] = temp->left;
            if (temp->right) next[++top2] = temp->right;
        } else {
            if (temp->right) next[++top2] = temp->right;
            if (temp->left) next[++top2] = temp->left;
        }

        if (top1 < 0) {
            leftToRight = !leftToRight;
            top1 = top2;
            for (int i = 0; i <= top2; i++)
                current[i] = next[i];
            top2 = -1;
        }
    }
}