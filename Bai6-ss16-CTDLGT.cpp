#include <stdio.h>
#include <stdlib.h>

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

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int countNodesGreaterThanX(struct Node* root, int X) {
    if (root == NULL) {
        return 0; 
    }

    int count = 0;
    if (root->data > X) {
        count = 1; 
    }

    return count + countNodesGreaterThanX(root->left, X) + countNodesGreaterThanX(root->right, X);
}

int main() {
    struct Node* root = NULL;
    int n, i, value, X;

    printf("Nhap so luong phan tu trong cay: ");
    scanf("%d", &n);

    printf("Nhap cac gia tri de chen vao cay: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Nhap gia tri X: ");
    scanf("%d", &X);

    int count = countNodesGreaterThanX(root, X);
    printf("So luong nut co gia tri lon hon %d la: %d\n", X, count);

    return 0;
}

