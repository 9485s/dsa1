#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // Base case: if tree is empty
    if (root == NULL) {
        return createNode(val);
    }

    // If value is smaller, go left
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    // If value is greater, go right
    else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder traversal (to check BST)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Main function
int main() {
    struct TreeNode* root = NULL;

    // Insert elements
    root = insertIntoBST(root, 50);
    insertIntoBST(root, 30);
    insertIntoBST(root, 70);
    insertIntoBST(root, 20);
    insertIntoBST(root, 40);
    insertIntoBST(root, 60);
    insertIntoBST(root, 80);

    // Print inorder traversal
    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}