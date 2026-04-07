#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    
    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        // If not visited → DFS
        if(!visited[neighbor]) {
            if(dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        // If already in recursion stack → cycle
        else if(recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = 0; // backtrack
    return false;
}

void detectCycle(int V, int edges[][2], int E) {

    // Step 1: Create adjacency list
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for(int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
    }

    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;  // directed edge u → v
    }

    // Step 2: visited & recursion stack
    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));

    // Step 3: DFS for each node
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES\n");
                return;
            }
        }
    }

    printf("NO\n");
}