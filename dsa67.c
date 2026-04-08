#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int node, int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }

    // push to stack after visiting all neighbors
    stack[++top] = node;
}

void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int V = 6;

    // initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Example DAG
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V);

    return 0;
}