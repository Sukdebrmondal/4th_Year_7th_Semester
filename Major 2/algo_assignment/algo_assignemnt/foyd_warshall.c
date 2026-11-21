
// Write a C program to implement the Floyd-Warshall algorithm using an adjacency matrix.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


#define INF 99999  // A large value to represent infinity

// Floyd-Warshall algorithm
void floydWarshall(int** graph, int size) {
    int** dist = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        dist[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Main algorithm
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the matrix in formatted style (no labels)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    int size;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &size);

    int** graph = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
        graph[i] = (int*)malloc(size * sizeof(int));

    printf("Enter the adjacency matrix (use 'i' for INF):\n");
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

    printf("\nShortest distance matrix:\n");
    floydWarshall(graph, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}


/*

Enter the number of vertices in the graph: 9
Enter the adjacency matrix (use 'i' for INF):
i 4 i i i i i 8 i
4 i 8 i i i i 11 i
i 8 i 7 i 4 i i 2
i i 7 i 9 14 i i i
i i i 9 i 10 i i i
i i 4 14 10 i 2 i i
i i i i i 2 i 1 6
8 11 i i i i 1 i 7
i i 2 i i i 6 7 i

Shortest distance matrix:
   8   4  12  19  21  11   9   8  14
   4   8   8  15  22  12  12  11  10
  12   8   4   7  14   4   6   7   2
  19  15   7  14   9  11  13  14   9
  21  22  14   9  18  10  12  13  16
  11  12   4  11  10   4   2   3   6
   9  12   6  13  12   2   2   1   6
   8  11   7  14  13   3   1   2   7
  14  10   2   9  16   6   6   7   4






Enter the number of vertices in the graph: 5
Enter the adjacency matrix (use 'i' for INF):
i 2 i 6 i
2 i 3 8 5
i 3 i i 7
6 8 i i 9
i 5 7 9 i

Shortest distance matrix:
   4   2   5   6   7
   2   4   3   8   5
   5   3   6  11   7
   6   8  11  12   9
   7   5   7   9  10
*/