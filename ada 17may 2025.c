#include <stdio.h>
#include <limits.h>

#define V 5
typedef struct {
    int vertex;
    int distance;
} Node;

void initializePriorityQueue(Node Q[], int dist[], int parent[]) {
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
}

int extractMin(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], parent[V], visited[V] = {0};
    initializePriorityQueue((Node[]){{0, 0}}, dist, parent);

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = extractMin(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Vertex \t Distance \t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d \t\t ", i, dist[i]);
        int pathNode = i;
        while (pathNode != -1) {
            printf("%d <- ", pathNode);
            pathNode = parent[pathNode];
        }
        printf("source\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
