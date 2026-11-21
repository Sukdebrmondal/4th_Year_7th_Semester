// Write a C program to implement Prim's algorithm for finding the Minimum Spanning Tree (MST) of a connected, undirected graph represented using an adjacency matrix.

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>

int extractMin(int key[], bool inMST[],int node_size) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < node_size; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int node_size,int graph[node_size][node_size]) {
    printf("Edge\tWeight\n");
    for (int i = 1; i < node_size; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int main(){
    int node_size;
    printf("enter the number of graph nodes: \n");
    scanf("%d", &node_size);

    // Input adjacency matrix
    int adj_mat[node_size][node_size];
    printf("enter the adjacency matrix of the graph along with the edge:\n");
    for(int i = 0; i < node_size; i++){
        for(int j = 0; j < node_size; j++){
            scanf("%d", &adj_mat[i][j]);
        }
    }

    int start;
    printf("enter the starting node: \n");
    scanf("%d", &start);
    if(start >= node_size){
        printf("no node exists , exit!!");
        exit(0);
    }

    int key[node_size];
    int parent[node_size];
    bool inMST[node_size];
    for(int i = 0; i < node_size; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    key[start] = 0;
    
    

    for (int count = 0; count < node_size - 1; count++) {
        int u = extractMin(key, inMST,node_size);
        inMST[u] = true;                 // Include u in MST
        // Update key values of adjacent vertices
        for (int v = 0; v < node_size; v++) {
            if (adj_mat[u][v] && !inMST[v] && adj_mat[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj_mat[u][v];
            }
        }
    }

    printMST(parent,node_size,adj_mat);
}


/*

enter the number of graph nodes: 
5
enter the adjacency matrix of the graph along with the edge:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
enter the starting node: 
0
Edge    Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5



enter the number of graph nodes: 
9
enter the adjacency matrix of the graph along with the edge:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
enter the starting node: 
0
Edge    Weight
0 - 1   4
1 - 2   8
2 - 3   7
3 - 4   9
2 - 5   4
5 - 6   2
6 - 7   1
2 - 8   2


*/