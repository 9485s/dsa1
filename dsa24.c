#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    // if head contains key
    if (head != NULL && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;

    // search key
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            break;   // delete only first occurrence
        }
        curr = curr->next;
    }

    return head;
}

// print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, key;
    struct Node *head = NULL, *temp = NULL, *last = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = createNode(x);

        if (head == NULL)
            head = temp;
        else
            last->next = temp;

        last = temp;
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}