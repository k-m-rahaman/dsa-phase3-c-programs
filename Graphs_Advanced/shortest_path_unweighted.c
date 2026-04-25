#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], V;

void bfs(int src) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0}, dist[MAX];

    queue[rear++] = src;
    visited[src] = 1;
    dist[src] = 0;

    while (front < rear) {
        int node = queue[front++];

        for (int i = 0; i < V; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = 1;
                dist[i] = dist[node] + 1;
                queue[rear++] = i;
            }
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d -> %d\n", i, dist[i]);
}