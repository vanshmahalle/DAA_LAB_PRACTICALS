#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0}
};

int path[V];

void printSolution() {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++)
        printf("%c ", path[i] + 'T'); // 'T' = 84 (prints T,M,S,H,C)
    printf("%c\n", path[0] + 'T'); // return to start
}

int isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

int hamCycleUtil(int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (hamCycleUtil(pos + 1) == 1)
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

void hamCycle() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Start from vertex 0 (T)

    if (hamCycleUtil(1) == 0)
        printf("No Hamiltonian Cycle exists\n");
    else
        printSolution();
}

int main() {
    hamCycle();
    return 0;
}
