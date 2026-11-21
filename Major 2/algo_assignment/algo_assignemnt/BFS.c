
// Write a C program to implement the Breadth-First Search (BFS) algorithm using an array.

#include<stdio.h>
#include<stdlib.h>

// Structure to represent a graph node
struct node{
    int node;
    struct node * add;
};

// Structure for queue implementation
struct queue{
    int size;
    int rear;
    int front;
    int * adj_list;
};

// Function to check if the queue is empty
int isEmpty(struct queue * q){
    if(q->rear == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the queue is full
int isFull(struct queue * q){
    if(q->rear == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to display the queue elements
void show_queue(struct queue * q){
    int a = (q->front == -1)?0:q->front+1;
    int b = (q->rear == -1)?0:q->rear;
    if(isEmpty(q)){
        printf("queue: ");
    }
    else{
        printf("queue: ");
        for(int i = a; i <= b; i++){
            printf("%d ", q->adj_list[i]);
        }
    }
    printf("\n");
}

// Function to add an element to the queue
void enqueue(struct queue * q, int val){
    if(isFull(q)){
        printf("queue is full\n");
    }
    else{
        q->rear++;
        q->adj_list[q->rear] = val;
    }
}

// Function to remove an element from the queue
int dequeue(struct queue * q){
    int a = -1;
    if(isEmpty(q)){
        printf("queue is empty");
    }
    else{
        q->front++;
        a = q->adj_list[q->front];
    }
    return a;
}

int main(){
    int len;
    printf("enter the number of graph nodes: \n");
    scanf("%d", &len);

    struct queue q;
    q.rear = q.front = -1;
    q.size = 20;
    q.adj_list = (int*) malloc(q.size * sizeof(int));

    int visited[100];
    for(int i = 0; i < 100; i++){
        visited[i] = 0;
    }

    struct node adj_list[len];

    // Creating adjacency list
    for(int i = 0;i<len;i++){
        printf("enter the node: \n");
        scanf("%d",&adj_list[i].node);
        int n;
        printf("number of edges connected to node no %d:\n",adj_list[i].node);
        scanf("%d",&n);
        struct node *link = NULL;
        for(int j = 0;j<n;j++){
            printf("enter connected node:\n");
            struct node *a = (struct node *)malloc(sizeof(struct node));
            scanf("%d",&a->node);
            a->add = NULL;
            if(j == 0){
                adj_list[i].add = a;
                link = a;
            }
            else {
                link->add = a;
                link = a;
            }
        }
    }

    // Printing adjacency list
    for(int i = 0;i<len;i++){
        struct node * link;
        link = adj_list[i].add;
        printf("%d -> ",adj_list[i].node);
        do{
            printf("%d ", link->node);
            link = link->add;
        }while(link != NULL);
        printf("\n");
    }

    int start;
    printf("enter the starting node: \n");
    scanf("%d", &start);
    printf("node is %d \n", start);
    visited[start] = 1;
    enqueue(&q, start);
    
    // BFS traversal
    while(!isEmpty(&q)){
        int node = dequeue(&q);
        
            struct node * link = NULL;
            for(int i = 0;i<len;i++){
                if(adj_list[i].node == node){
                    link = adj_list[i].add;
                    break;
                }
            }
            while(link != NULL){
                if(visited[link->node] == 0){
                    visited[link->node] = 1;
                    enqueue(&q, link->node);
                    printf("node is %d \n", link->node);
                }
                link = link->add;
            }
        
    }
    printf("breadth first search is completed!!");
    
    return 0;
}



/*
enter the number of graph nodes: 
5
enter the node:
1
number of edges connected to node no 1:
2
enter connected node:
2
enter connected node:
4
enter the node:
2
number of edges connected to node no 2:
3
enter connected node:
1
enter connected node:
4
enter connected node:
3
enter the node:
4
number of edges connected to node no 4:
4
enter connected node:
1
enter connected node:
2
enter connected node:
3
enter connected node:
5
enter the node:
3
number of edges connected to node no 3:
3
enter connected node:
2
enter connected node:
4
enter connected node:
5
enter the node:
5
number of edges connected to node no 5:
2
enter connected node:
4
enter connected node:
3
1 -> 2 4
2 -> 1 4 3
4 -> 1 2 3 5
3 -> 2 4 5
5 -> 4 3
enter the starting node:
1
node is 1
node is 2
node is 4
node is 3
node is 5
breadth first search is completed!!




enter the number of graph nodes: 
7
enter the node:
0
number of edges connected to node no 0:
3
enter connected node:
0
enter connected node:
2
enter connected node:
3
enter the node:
1
number of edges connected to node no 1:
2
enter connected node:
0
enter connected node:
3
enter the node:
2
number of edges connected to node no 2:
2
enter connected node:
0
enter connected node:
3
enter the node:
3
number of edges connected to node no 3:
4
enter connected node:
1
enter connected node:
0
enter connected node:
2
enter connected node:
4
enter the node:
4
number of edges connected to node no 4:
4
enter connected node:
2
enter connected node:
3
enter connected node:
5
enter connected node:
6
enter the node:
5
number of edges connected to node no 5:
1
enter connected node:
4
enter the node:
6
number of edges connected to node no 6:
1
enter connected node:
4
0 -> 0 2 3
1 -> 0 3
2 -> 0 3
3 -> 1 0 2 4
4 -> 2 3 5 6
5 -> 4
6 -> 4
enter the starting node:
0
node is 0
node is 2
node is 3
node is 1
node is 4
node is 5
node is 6
breadth first search is completed!!
*/