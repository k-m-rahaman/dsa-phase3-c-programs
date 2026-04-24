#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], stack[MAX];
int top = -1, V;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++)
        if (graph[node][i] && !visited[i])
            dfs(i);

    stack[++top] = node;
}

void topoSort() {
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i);

    while (top != -1)
        printf("%d ", stack[top--]);
}