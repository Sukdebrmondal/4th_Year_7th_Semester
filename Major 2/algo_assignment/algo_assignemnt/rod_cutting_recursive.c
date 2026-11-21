
/* Write a C program to implement the Rod Cutting problem using recursion. The program should take the length of the rod and the prices
for each length as input, and output the maximum revenue that can be obtained by cutting the rod into pieces.*/
#include <stdio.h>
#include <float.h>


float rod_cutting(int n, float p[])
{
    if (n == 0)
    {
        return 0;
    }
    
    float q = FLT_MIN;  // negative infinity

    for (int i = 1; i <= n; i++)
    {
        float tmp = p[i] + rod_cutting(n-i, p); 
        q = tmp > q ? tmp: q; // q = max(q, p[i] + rod_cutting[j-i])
    }

    return q;
    
    
}

int main()
{
    int n;
    float max_profit;

    printf("Please enter the length of the rod: ");
    scanf("%d", &n);
    
    float p[n+1]; //prices for length 1 to n;

    p[0] = 0; //price for length 0 = 0

    for (int i = 1; i <= n; i++)
    {
        printf("Enter of price for length %d: ", i);
        scanf("%f", &p[i]);
    }

    max_profit = rod_cutting(n, p);

    printf("Max revenue: %.2f\n", max_profit);
    

    return 0;
}



// Please enter the length of the rod: 10
// Enter of price for length 1: 35.34
// Enter of price for length 2: 75.43
// Enter of price for length 3: 20.67
// Enter of price for length 4: 18.76
// Enter of price for length 5: 42.45
// Enter of price for length 6: 46.4
// Enter of price for length 7: 23.64
// Enter of price for length 8: 22.
// Enter of price for length 9: 64.23
// Enter of price for length 10: 42.66
// Max revenue: 377.15
