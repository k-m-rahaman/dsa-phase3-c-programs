#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], indegree[MAX], V;

void topoSort() {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }
}