#include <stdio.h>
#include <stdlib.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order construction
struct Queue {
    struct TreeNode** arr;
    int front, rear;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * size);
    q->front = q->rear = 0;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Function to find height
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return (left > right ? left : right) + 1;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    printf("%d\n", maxDepth(root));

    return 0;
}