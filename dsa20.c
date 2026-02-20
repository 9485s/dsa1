#include <stdio.h>
#include <stdlib.h>

// Simple hash structure
typedef struct Node {
    int sum;
    int freq;
    struct Node* next;
} Node;

#define SIZE 10007

Node* hashTable[SIZE];

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

// Insert or update frequency
void insert(int sum) {
    int index = hash(sum);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->sum == sum) {
            temp->freq++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->freq = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Get frequency
int getFreq(int sum) {
    int index = hash(sum);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->sum == sum)
            return temp->freq;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, count = 0;

    insert(0);  // Important

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        count += getFreq(sum);

        insert(sum);
    }

    printf("%d\n", count);

    return 0;
}