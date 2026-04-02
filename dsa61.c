#include <stdio.h>

int main() {
    int n, m, i, u, v;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix with 0
    int adj[n][n];
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Input edges
    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        // For undirected graph, also mark reverse edge
        adj[v][u] = 1;
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}