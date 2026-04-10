#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Edge structure
struct Edge {
    int v, w;
    struct Edge* next;
};

// Create new edge
struct Edge* newEdge(int v, int w) {
    struct Edge* temp = (struct Edge*)malloc(sizeof(struct Edge));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

// Min Heap Node
struct HeapNode {
    int node, dist;
};

// Simple priority queue (array-based)
struct HeapNode heap[MAX * MAX];
int size = 0;

// Push into heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    size++;
}

// Extract minimum
struct HeapNode pop() {
    int minIdx = 0;
    for(int i = 1; i < size; i++) {
        if(heap[i].dist < heap[minIdx].dist)
            minIdx = i;
    }
    struct HeapNode minNode = heap[minIdx];

    heap[minIdx] = heap[size - 1];
    size--;

    return minNode;
}

int isEmpty() {
    return size == 0;
}

void dijkstra(int n, struct Edge* adj[], int source) {

    int dist[MAX];
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    push(source, 0);

    while(!isEmpty()) {
        struct HeapNode current = pop();
        int u = current.node;

        struct Edge* temp = adj[u];
        while(temp != NULL) {
            int v = temp->v;
            int w = temp->w;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", source);
    for(int i = 0; i < n; i++) {
        printf("Node %d -> %d\n", i, dist[i]);
    }
}