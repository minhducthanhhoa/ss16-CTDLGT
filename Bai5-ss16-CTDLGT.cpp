#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findMaxValue(struct Node* root) {
    if (root == NULL) {
        return INT_MIN; 
    }

    int leftMax = findMaxValue(root->left);
    int rightMax = findMaxValue(root->right);

    int max = root->data;
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }

    return max;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int maxValue = findMaxValue(root);
    printf("Gia tri lon nhat trong cay nhi phan la: %d\n", maxValue);

    return 0;
}

