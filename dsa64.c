#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// BFS function
void BFS(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};

    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main() {
    int n, m;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // remove this line for directed graph
    }

    int s;
    printf("Enter source vertex: ");
    scanf("%d", &s);

    BFS(n, adj, s);

    return 0;
}