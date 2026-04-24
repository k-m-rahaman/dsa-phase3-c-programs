#include <stdio.h>

#define MAX 100

int graph[MAX][MAX], indegree[MAX], V;

int hasCycle() {
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int i = 0; i < V; i++) {
            if (graph[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    return count != V;
}