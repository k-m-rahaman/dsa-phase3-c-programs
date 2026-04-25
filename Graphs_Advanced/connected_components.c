#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], V;

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < V; i++)
        if (graph[node][i] && !visited[i])
            dfs(i);
}

void findComponents() {
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
            printf("\n");
            count++;
        }
    }

    printf("Total Components: %d\n", count);
}