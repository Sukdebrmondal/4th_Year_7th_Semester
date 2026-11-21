

// Write a C program to implement the Depth-First Search (DFS) algorithm using an array.
#include<stdio.h>
#include<stdlib.h>


// Structure to represent a graph node
struct node {
    int node;
    struct node *add;
};

// Function to find index of a node in the adjacency list
int find_index(int value, int node_size, struct node adj_list[]) {
    for (int i = 0; i < node_size; i++) {
        if (adj_list[i].node == value) {
            return i;
        }
    }
    return -1;
}

// Depth First Search (DFS) function
void dfs(int node_value, int node_size, struct node adj_list[], int visited[]) {
    int index = find_index(node_value, node_size, adj_list);
    if (index == -1 || visited[index] == 1) {
        return;
    }

    visited[index] = 1;
    printf("Visited node: %d\n", node_value);

    struct node *link = adj_list[index].add;
    while (link != NULL) {
        dfs(link->node, node_size, adj_list, visited);
        link = link->add;
    }
}

int main() {
    int node_size;
    printf("Enter the number of graph nodes: \n");
    scanf("%d", &node_size);

    int visited[node_size];
    for(int i = 0; i < node_size; i++) {
        visited[i] = 0;
    }

    struct node adj_list[node_size];

    // Creating adjacency list
    for(int i = 0; i < node_size; i++) {
        printf("Enter the node number: \n");
        scanf("%d", &adj_list[i].node);
        adj_list[i].add = NULL;  // Initialize adjacency list head

        int n;
        printf("Number of edges connected to node %d: \n", adj_list[i].node);
        scanf("%d", &n);

        struct node *link = NULL;
        for(int j = 0; j < n; j++) {
            struct node *a = (struct node *)malloc(sizeof(struct node));
            printf("Enter connected node: \n");
            scanf("%d", &a->node);
            a->add = NULL;
            
            if (j == 0) {
                adj_list[i].add = a;
                link = a;
            } else {
                link->add = a;
                link = a;
            }
        }
    }

    // Printing adjacency list
    printf("\nGraph adjacency list:\n");
    for(int i = 0; i < node_size; i++) {
        struct node *link = adj_list[i].add;
        printf("%d -> ", adj_list[i].node);
        while (link != NULL) {
            printf("%d ", link->node);
            link = link->add;
        }
        printf("\n");
    }

    // Running DFS
    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("Starting DFS from node %d\n", start);
    dfs(start, node_size, adj_list, visited);

    // Freeing allocated memory
    for (int i = 0; i < node_size; i++) {
        struct node *link = adj_list[i].add;
        while (link != NULL) {
            struct node *temp = link;
            link = link->add;
            free(temp);
        }
    }

    return 0;
}

/*

Enter the number of graph nodes:       
5
Enter the node number: 
1
Number of edges connected to node 1: 
2
Enter connected node: 
2
Enter connected node: 
4
Enter the node number: 
2
Number of edges connected to node 2: 
3
Enter connected node: 
1
Enter connected node: 
4
Enter connected node: 
3
Enter the node number: 
4
Number of edges connected to node 4: 
4
Enter connected node: 
1
Enter connected node: 
2
Enter connected node: 
3
Enter connected node: 
5
Enter the node number: 
3
Number of edges connected to node 3: 
3
Enter connected node: 
2
Enter connected node: 
4
Enter connected node: 
5
Enter the node number: 
5
Number of edges connected to node 5: 
2
Enter connected node: 
4
Enter connected node: 
3

Graph adjacency list:
1 -> 2 4
2 -> 1 4 3
4 -> 1 2 3 5
3 -> 2 4 5
5 -> 4 3
Enter the starting node: 1
Starting DFS from node 1
Visited node: 1
Visited node: 2
Visited node: 4
Visited node: 3
Visited node: 5




Enter the number of graph nodes: 

Enter the node number: 
0
Number of edges connected to node 0: 
3
Enter connected node: 
0
Enter connected node: 
2
Enter connected node: 
3
Enter the node number: 
1
Number of edges connected to node 1: 
2
Enter connected node: 
0
Enter connected node: 
3
Enter the node number: 
2
Number of edges connected to node 2: 
2
Enter connected node: 
0
Enter connected node: 
3
Enter the node number: 
3
Number of edges connected to node 3: 
4
Enter connected node: 
1
Enter connected node: 
0
Enter connected node: 
2
Enter connected node: 
4
Enter the node number: 
4
Number of edges connected to node 4: 
4
Enter connected node: 
2
Enter connected node: 
3
Enter connected node: 
5
Enter connected node: 
6
Enter the node number: 
5
Number of edges connected to node 5: 
1
Enter connected node: 
4
Enter the node number: 
6
Number of edges connected to node 6: 
1
Enter connected node: 
4

Graph adjacency list:
0 -> 0 2 3
1 -> 0 3
2 -> 0 3
3 -> 1 0 2 4
4 -> 2 3 5 6
5 -> 4
6 -> 4
Enter the starting node: 0
Starting DFS from node 0
Visited node: 0
Visited node: 2
Visited node: 3
Visited node: 1
Visited node: 4
Visited node: 5
Visited node: 6

*/