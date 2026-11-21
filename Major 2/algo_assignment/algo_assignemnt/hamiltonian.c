// Write a C program to implement the Hamiltonian Path Problem using Backtracking.

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

// Check whether the vertex has not been visited
int isValid(int next)
{
    return visited[next] == 0;
}

// Backtracking function
int solve(int path[], int depth)
{
    // All vertices have been visited
    if (depth == n)
        return 1;

    // Get the last vertex in the current path
    int last = path[depth - 1];

    // Try all possible next vertices
    for (int next = 0; next < n; next++)
    {
        if (graph[last][next] && isValid(next))
        {
            path[depth] = next;  // Place vertex
            visited[next] = 1;

            if (solve(path, depth + 1))
                return 1;

            visited[next] = 0;   // Undo (Backtrack)
        }
    }

    return 0;  // Dead end
}

int main()
{
    int m, u, v;
    int path[MAX];
    int found = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (0-based vertices):\n");

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    // Try every vertex as a starting point
    for (int start = 0; start < n; start++)
    {
        for (int i = 0; i < n; i++)
            visited[i] = 0;

        path[0] = start;
        visited[start] = 1;

        if (solve(path, 1))
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("\nHamiltonian Path found:\n");

        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
    }
    else
    {
        printf("\nNo Hamiltonian Path exists.");
    }

    return 0;
}


/*
case 1:
Enter number of vertices and edges: 4 4
Enter edges (0-based vertices):
0 1
1 2
2 3
3 0

Hamiltonian Path found:
0 1 2 3

case 2:
Enter number of vertices and edges: 4 3 
Enter edges (0-based vertices):
0 1
0 2
0 3

No Hamiltonian Path exists.
*/