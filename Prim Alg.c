#include <stdio.h>

int cost[10][10], n, f[10][2], sum;

void prims(int cost[10][10], int n);

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;  // 999 represents infinity
        }
    }

    prims(cost, n);

    printf("Edges of the minimal spanning tree:\n");
    for (i = 1; i < n; i++)
        printf("%d -> %d\n", f[i][0], f[i][1]);

    printf("Sum of minimal spanning tree: %d\n", sum);

    return 0;
}

void prims(int cost[10][10], int n) {
    int i, j, u, v, min, source;
    int p[10], d[10], s[10];

    min = 999;
    source = 0;

    // Initialize arrays
    for (i = 0; i < n; i++) {
        d[i] = cost[source][i];
        p[i] = source;
        s[i] = 0;
    }

    s[source] = 1;  // Include source in MST
    sum = 0;

    for (i = 1; i < n; i++) {
        min = 999;

        // Find the vertex v not in MST with minimum d[v]
        for (j = 0; j < n; j++) {
            if (!s[j] && d[j] < min) {
                min = d[j];
                v = j;
            }
        }

        u = p[v];
        f[i][0] = u;
        f[i][1] = v;
        sum += cost[u][v];
        s[v] = 1;

        // Update the distances
        for (j = 0; j < n; j++) {
            if (!s[j] && cost[v][j] < d[j]) {
                d[j] = cost[v][j];
                p[j] = v;
            }
        }
    }
}
