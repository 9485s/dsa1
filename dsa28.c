#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCLL(int n) {
    if (n == 0)
        return NULL;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    int x;
    scanf("%d", &x);

    // First node
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = x;
    head->next = head;   // circular link
    temp = head;

    // Remaining nodes
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;

        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// Function to traverse circular linked list
void traverseCLL(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);   // stop when back to head
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCLL(n);

    traverseCLL(head);

    return 0;
}