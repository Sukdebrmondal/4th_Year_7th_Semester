// Write a C program to implement the Longest Increasing Subsequence (LIS) algorithm using dynamic programming.

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    char arr[n];
    int dp[n];
    int parent[n];

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);

        dp[i] = 1;
        parent[i] = -1;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] &&
               dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
    }

    int maxLength = dp[0];
    int maxIndex = 0;

    for(int i = 1; i < n; i++)
    {
        if(dp[i] > maxLength)
        {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    char lis[maxLength];
    int k = 0;

    int current = maxIndex;

    while(current != -1)
    {
        lis[k++] = arr[current];
        current = parent[current];
    }

    printf("\nLength of LIS = %d\n", maxLength);

    printf("One LIS is: ");

    for(int i = k - 1; i >= 0; i--)
    {
        printf("%c ", lis[i]);
    }

    printf("\n");

    return 0;
}


/*
Enter number of elements: 12
Enter elements:
vidyamandira

Length of LIS = 4
One LIS is: i m n r
*/