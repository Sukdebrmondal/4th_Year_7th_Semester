// Write a C program to implement Dijkstra's algorithm using an adjacency matrix

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF INT_MAX

// Function to find the vertex with the minimum distance
int minDistance(int dist[], bool visited[], int size) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < size; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the shortest distances
void printSolution(int dist[], int size) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Dijkstra’s Algorithm using an adjacency matrix
void dijkstra(int** graph, int src, int size) {
    int dist[size];
    bool visited[size];

    for (int i = 0; i < size; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, visited, size);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, size);
}

int main() {
    int size;
    printf("Enter the number of graph nodes:\n");
    scanf("%d", &size);

    // Dynamic memory allocation
    int** graph = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
        graph[i] = (int*)malloc(size * sizeof(int));

    printf("Enter the adjacency matrix (use 'i' for INF / no edge):\n");
    char input[10];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%s", input);
            if (input[0] == 'i' || input[0] == 'I')
                graph[i][j] = INF;
            else
                graph[i][j] = atoi(input);
        }
    }

    int source;
    printf("Enter the source node (0 to %d):\n", size - 1);
    scanf("%d", &source);

    if (source >= size || source < 0) {
        printf("Invalid source node!\n");
        return 1;
    }

    dijkstra(graph, source, size);

    // Free memory
    for (int i = 0; i < size; i++)
        free(graph[i]);
    free(graph);

    return 0;
}



/*

Enter the number of graph nodes:
9
Enter the adjacency matrix (use 'i' for INF / no edge):
i 4 i i i i i 8 i
4 i 8 i i i i 11 i
i 8 i 7 i 4 i i 2
i i 7 i 9 14 i i i
i i i 9 i 10 i i i
i i 4 14 10 i 2 i i
i i i i i 2 i 1 6
8 11 i i i i 1 i 7
i i 2 i i i 6 7 i
Enter the source node (0 to 8):
0
Vertex  Distance from Source
0       0
1       4
2       12
3       19
4       21
5       11
6       9
7       8
8       14




Enter the number of graph nodes:
5
Enter the adjacency matrix (use 'i' for INF / no edge):
i 2 i 6 i
2 i 3 8 5
i 3 i i 7
6 8 i i 9
i 5 7 9 i
Enter the source node (0 to 4):
0
Vertex  Distance from Source
0       0
1       2
2       5
3       6
4       7

*/