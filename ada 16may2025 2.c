#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjacencyMatrix[MAX][MAX], inDegree[MAX];
int vertices;

void topologicalSort() {
    for (int i = 0; i < vertices; i++)
        inDegree[i] = 0;

    for (int j = 0; j < vertices; j++)
        for (int i = 0; i < vertices; i++)
            inDegree[i] += adjacencyMatrix[j][i];

    printf("Topological Order:\n");

    for (int i = 0; i < vertices; i++) {
        int j;
        for (j = 0; j < vertices; j++) {
            if (inDegree[j] == 0) {
                printf("%d ", j);
                inDegree[j] = -1;
                break;
            }
        }

        for (int k = 0; k < vertices; k++) {
            if (adjacencyMatrix[j][k] == 1)
                inDegree[k]--;
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &adjacencyMatrix[i][j]);

    topologicalSort();

    return 0;
}
