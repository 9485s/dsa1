#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int* graph[MAX];
int graphSize[MAX];
int visited[MAX];

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int)); // simple allocation
        graphSize[i] = 0;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    // Run DFS from node 1
    dfs(1);

    // Check connectivity
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}