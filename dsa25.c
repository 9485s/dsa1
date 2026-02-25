#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node *next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Dynamic memory allocation
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to count occurrences
int countOccurrences(struct Node *head, int key) {
    int count = 0;

    while(head != NULL) {
        if(head->data == key)
            count++;

        head = head->next;
    }
    return count;
}

int main() {
    int n, key;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    struct Node *head = createList(n);

    // Input key
    scanf("%d", &key);

    // Count occurrences
    int result = countOccurrences(head, key);

    // Output result
    printf("%d", result);

    return 0;
}