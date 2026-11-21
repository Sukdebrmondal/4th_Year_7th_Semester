// Write a C program to implement the Huffman Coding algorithm using Greedy Algorithm( priority queue (min-heap)).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

// Min-Heap
struct MinHeap {
    int size;
    struct Node *arr[MAX];
};

// Create a new node
struct Node* newNode(char ch, int freq) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->ch = ch;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Swap two nodes
void swap(struct Node **a, struct Node **b) {
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down
void minHeapify(struct MinHeap *Q, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < Q->size &&
        Q->arr[left]->freq < Q->arr[smallest]->freq)
        smallest = left;

    if (right < Q->size &&
        Q->arr[right]->freq < Q->arr[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(&Q->arr[i], &Q->arr[smallest]);
        minHeapify(Q, smallest);
    }
}

// Insert a node into Min-Heap
void INSERT(struct MinHeap *Q, struct Node *node) {
    if (Q->size >= MAX) {
        printf("Heap is full!\n");
        return;
    }

    int i = Q->size++;
    Q->arr[i] = node;

    // Heapify up
    while (i > 0 &&
           Q->arr[(i - 1) / 2]->freq > Q->arr[i]->freq) {
        swap(&Q->arr[i], &Q->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract the node with minimum frequency
struct Node* EXTRACT_MIN(struct MinHeap *Q) {
    if (Q->size <= 0)
        return NULL;

    struct Node *minNode = Q->arr[0];
    Q->arr[0] = Q->arr[--Q->size];

    if (Q->size > 0)
        minHeapify(Q, 0);

    return minNode;
}

// HUFFMAN(C) - Greedy Algorithm
struct Node* HUFFMAN(char ch[], int freq[], int n) {
    struct MinHeap Q;
    Q.size = 0;

    // Q = C
    for (int i = 0; i < n; i++) {
        INSERT(&Q, newNode(ch[i], freq[i]));
    }

    // Repeat n - 1 times
    for (int i = 1; i <= n - 1; i++) {
        struct Node *z = newNode('-', 0);

        struct Node *x = EXTRACT_MIN(&Q);
        struct Node *y = EXTRACT_MIN(&Q);

        z->left = x;
        z->right = y;
        z->freq = x->freq + y->freq;

        INSERT(&Q, z);
    }

    return EXTRACT_MIN(&Q);
}

// Generate Huffman Codes
void printCodes(struct Node *root, int code[], int top) {
    if (root == NULL)
        return;

    // Left edge = 0
    if (root->left != NULL) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    // Right edge = 1
    if (root->right != NULL) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    // Leaf node represents a character
    if (root->left == NULL && root->right == NULL) {
        printf("%c : ", root->ch);

        if (top == 0)
            printf("0");

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

// Free the Huffman Tree
void freeTree(struct Node *root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    char ch[MAX];
    int freq[MAX];
    int code[MAX];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Number of characters must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter characters and their frequencies:\n");

    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &ch[i], &freq[i]);

        if (freq[i] < 0) {
            printf("Frequency cannot be negative.\n");
            return 1;
        }
    }

    struct Node *root = HUFFMAN(ch, freq, n);

    printf("\nHuffman Codes:\n");
    printCodes(root, code, 0);

    freeTree(root);

    return 0;
}

/*
Enter number of characters: 4
Enter characters and their frequencies:
A 7     
B 3
C 9
D 8

Huffman Codes:
B : 00
A : 01
D : 10
C : 11
*/
