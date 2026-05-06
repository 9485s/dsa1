#include <stdio.h>
#include <stdlib.h>

// Node for linked list
struct Node {
    float data;
    struct Node* next;
};

// Create new node
struct Node* createNode(float value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert in sorted order
void sortedInsert(struct Node** head, float value) {

    struct Node* newNode = createNode(value);

    // Insert at beginning
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Find correct position
    struct Node* current = *head;

    while (current->next != NULL &&
           current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Bucket Sort Function
void bucketSort(float arr[], int n) {

    // Create buckets
    struct Node* buckets[n];

    int i;

    for (i = 0; i < n; i++)
        buckets[i] = NULL;

    // Put array elements into buckets
    for (i = 0; i < n; i++) {

        int index = n * arr[i];

        sortedInsert(&buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;

    for (i = 0; i < n; i++) {

        struct Node* temp = buckets[i];

        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

// Print array
void printArray(float arr[], int n) {

    int i;

    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    printf("\n");
}

int main() {

    float arr[] = {
        0.78, 0.17, 0.39,
        0.26, 0.72, 0.94,
        0.21, 0.12, 0.23, 0.68
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    return 0;
}