 #include <stdio.h>
#include <stdlib.h>

int V;
#define INF 9999

void printMatrix(int matrix[][V]);

void floydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist);
}

void printMatrix(int matrix[][V]) {
    printf("\nShortest-path matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter the elements into the graph (use %d for no path):\n", INF);

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j) {
                graph[i][j] = 0;
            }
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph);
    return 0;
}

