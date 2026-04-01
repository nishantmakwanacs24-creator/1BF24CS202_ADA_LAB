#include <stdio.h>
#include <limits.h>

#define V 5   // Number of vertices

// Function to find vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra function
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Stores shortest distance from source
    int visited[V];   // Keeps track of visited vertices

    // Initialize all distances as infinite and visited as 0
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;  // Distance of source from itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited); // Pick min distance vertex
        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
               
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Main function
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
