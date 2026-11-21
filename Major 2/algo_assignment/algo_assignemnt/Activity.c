// Write a C program to implement the Activity Selection Problem using the Greedy Algorithm.



#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store each activity
typedef struct {
    char name[20];
    int start;
    int finish;
} Activity;

// Compare activities according to finish time
int compare(const void *a, const void *b) {
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;

    return (x->finish > y->finish) -
           (x->finish < y->finish);
}

// Greedy Activity Selection
void greedyActivitySelector(Activity A[], int n) {
    int last_finish = -1;
    int j = 0;

    printf("\nSelected Activities: ");

    for (int i = 0; i < n; i++) {
        if (A[i].start >= last_finish) {
            printf("%s ", A[i].name);

            last_finish = A[i].finish;
            j++;
        }
    }

    printf("\nTotal Activities Selected: %d\n", j);
}

int main() {
    Activity A[MAX];
    int n;

    printf("Enter the number of activities (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of activities!\n");
        return 1;
    }

    // Input activity details
    printf("\nEnter activity name, start time and finish time: \n");
    for (int i = 0; i < n; i++) {
        scanf("%19s %d %d",
              A[i].name, &A[i].start, &A[i].finish);

        if (A[i].start > A[i].finish) {
            printf("Invalid activity time!\n");
            return 1;
        }
    }

    // Sort activities by increasing finish time
    qsort(A, n, sizeof(Activity), compare);

    printf("\nActivities sorted by finish time:\n");
    printf("Activity\tStart\tFinish\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t%d\n",
               A[i].name, A[i].start, A[i].finish);
    }

    // Apply the Greedy Algorithm
    greedyActivitySelector(A, n);

    return 0;
}


// Enter the number of activities (1-100): 6

// Enter activity name, start time and finish time:
// a1 1 2  
// a2 3 4
// a3 0 6
// a4 5 7
// a5 8 9
// a6 5 9

// Activities sorted by finish time:
// Activity        Start   Finish
// a1              1       2
// a2              3       4
// a3              0       6
// a4              5       7
// a6              5       9
// a5              8       9

// Selected Activities: a1 a2 a4 a5
// Total Activities Selected: 4
