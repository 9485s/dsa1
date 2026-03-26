#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

// ✅ TreeNode structure MUST be defined first
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Result arrays
    int** result = (int**)malloc(MAX * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX * sizeof(int));

    // Queue for level order traversal
    struct TreeNode* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 0;

    while (front < rear) {
        int size = rear - front;

        // Allocate memory for current level
        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            // 🔁 Zigzag logic
            if (level % 2 == 0) {
                // Left to right
                result[level][i] = node->val;
            } else {
                // Right to left
                result[level][size - i - 1] = node->val;
            }

            // Push children into queue
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        level++;
    }

    *returnSize = level;
    return result;
}