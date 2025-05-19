#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int v, int vertices) {
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && !visited[i])
            dfs(i, vertices);
    }
    stack[++top] = v;
}

void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i])
            dfs(i, vertices);
    }

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    topologicalSort(vertices);

    return 0;
}
