#include <stdio.h>
#include <stdlib.h>

/* Node definition */
struct Node {
    int data;
    struct Node* next;
};

/* Create node */
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Print list */
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

/* Rotate Right by k places */
struct Node* rotateRight(struct Node* head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int n = 1;

    /* count nodes and reach last node */
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    /* make circular */
    temp->next = head;

    k = k % n;          // handle large k
    int steps = n - k;

    struct Node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;

    /* break circle */
    newTail->next = NULL;

    return newHead;
}

/* Main function */
int main() {
    int n, x, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}