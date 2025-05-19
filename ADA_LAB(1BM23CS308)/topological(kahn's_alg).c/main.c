#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front > rear;
}

void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++) {
        indegree[i] = 0;
        for (int j = 0; j < vertices; j++) {
            if (graph[j][i] == 1)
                indegree[i]++;
        }
    }

    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    printf("Topological Order: ");

    while (!isQueueEmpty()) {
        int vertex = dequeue();
        printf("%d ", vertex);
        count++;

        for (int i = 0; i < vertices; i++) {
            if (graph[vertex][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if (count != vertices) {
        printf("\nGraph contains a cycle. Topological ordering not possible.\n");
    }
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
