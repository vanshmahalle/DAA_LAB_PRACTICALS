#include <stdio.h>
#define V 5   // Number of vertices

int graph[V][V];  // Adjacency matrix
int color[V];

int isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoringUtil(int m, int v) {
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoringUtil(m, v + 1))
                return 1;

            color[v] = 0; // Backtrack
        }
    }
    return 0;
}

int graphColoring(int m) {
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(m, 0)) {
        printf("Solution does not exist\n");
        return 0;
    }

    printf("Color assigned to vertices:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i + 1, color[i]);

    return 1;
}

int main() {
    int m; // Number of colors (frequencies)
    printf("Enter number of colors (frequencies): ");
    scanf("%d", &m);

    printf("Enter adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(m);
    return 0;
}
