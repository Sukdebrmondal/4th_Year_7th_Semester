// Write a C program to implement the Longest Common Subsequence (LCS) algorithm using dynamic programming.

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 100
#define max(a, b) ((a) > (b) ? (a) : (b))

void longestSub(char string1[], char string2[], int lenString1, int lenString2) {
    int table[lenString1 + 1][lenString2 + 1];
    
    for(int i = 0; i < lenString1 + 1; i++) {
        for(int j = 0; j < lenString2 + 1; j++) {
            if(i == 0 || j == 0) {
                table[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < lenString1; i++) {
        for(int j = 0; j < lenString2; j++) {
            if(string1[i] == string2[j]) {
                table[i + 1][j + 1] = table[i][j] + 1;
            } else {
                table[i + 1][j + 1] = max(table[i][j + 1], table[i + 1][j]);;
            }
        }
    }

    printf("lenght1: %d\n", lenString1);
    printf("lenght2: %d\n", lenString2);

    for(int i = 0; i < lenString1 + 1; i++) {
        for(int j = 0; j < lenString2 + 1; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("The longest subsequence has length: %d\n", table[lenString1][lenString2]);
}

int main() {
    char string1[MAX], string2[MAX];

    printf("Enter the first string:");
    scanf("%s", string1);
    int lenString1 = strlen(string1);

    printf("Enter the second string:");
    scanf("%s", string2);
    int lenString2 = strlen(string2);

    printf("In Main: \n");
    printf("lenght1: %d\n", lenString1);
    printf("lenght2: %d\n", lenString2);

    if(string1 != "" && string2 != ""){
        lenString1 < lenString2 ? longestSub(string1, string2, lenString1, lenString2) : longestSub(string2, string1, lenString2, lenString1);
    }

    return 0;
}


/*
Enter the first string:intension
Enter the second string:execution
In Main: 
lenght1: 9
lenght2: 9
lenght1: 9
lenght2: 9
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1 1
0 0 0 1 1 1 1 1 1 1
0 1 1 1 1 1 1 2 2 2
0 1 1 1 1 1 1 2 3 3
0 1 2 2 2 2 2 2 3 4
The longest subsequence has length: 4
*/
