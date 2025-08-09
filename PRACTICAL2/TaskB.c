#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 9999

void update_near(int near[], int cost[][MAX], int included[], int new_vertex, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (!included[i]) {
            if (near[i] == -1 || cost[i][new_vertex] < cost[i][near[i]]) {
                near[i] = new_vertex;
            }
        }
    }
}

int main() {
    int cost[MAX][MAX], near[MAX], included[MAX] = {0};
    int n, i, j, u = -1, v = -1, min, total_cost = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Find initial minimum edge
    min = INF;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    included[u] = included[v] = 1;
    total_cost += cost[u][v];
    printf("Edge: %d - %d  Cost: %d\n", u + 1, v + 1, cost[u][v]);
    edges++;

    for (i = 0; i < n; i++) {
        if (!included[i]) {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        } else {
            near[i] = -1;
        }
    }

    // Repeat until n-1 edges
    while (edges < n - 1) {
        min = INF;
        int k = -1;
        for (i = 0; i < n; i++) {
            if (!included[i] && cost[i][near[i]] < min) {
                min = cost[i][near[i]];
                k = i;
            }
        }

        if (k == -1) break; // No more edges

        included[k] = 1;
        total_cost += cost[k][near[k]];
        printf("Edge: %d - %d  Cost: %d\n", k + 1, near[k] + 1, cost[k][near[k]]);
        edges++;

        update_near(near, cost, included, k, n);
    }

    printf("Total cost of MST = %d\n", total_cost);

    return 0;
}
