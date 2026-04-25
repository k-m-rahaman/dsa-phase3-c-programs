#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX], V;

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, index;

    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] <= min)
            min = dist[i], index = i;

    return index;
}

void dijkstra(int src) {
    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 0; i < V; i++)
        printf("%d -> %d\n", i, dist[i]);
}