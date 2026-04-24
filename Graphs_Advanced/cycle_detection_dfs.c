#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], recStack[MAX];
int V;

int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int hasCycle() {
    for (int i = 0; i < V; i++)
        if (!visited[i] && dfs(i))
            return 1;
    return 0;
}