#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Structure for Disjoint Set (Union-Find)
int parent[MAX];

// Find function with path compression
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    parent[u_root] = v_root;
}

// Comparator function for sorting edges by weight
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

int main() {
    int n, e;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Input edges
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Sort edges by weight
    qsort(edges, e, sizeof(edges[0]), compare);

    int count = 0;   // Number of edges in MST
    int cost = 0;    // Total cost

    printf("\nEdges in MST:\n");

    // Kruskal's Algorithm
    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            cost += edges[i].weight;
            unionSet(set_u, set_v);
            count++;
        }
    }

    printf("\nMinimum Cost of Spanning Tree = %d\n", cost);

    return 0;
}

