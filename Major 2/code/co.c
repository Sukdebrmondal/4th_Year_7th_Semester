
#include <stdio.h>

// Function to count digits
int countDigits(long long n)
{
    if (n == 0)
        return 1;

    int count = 0;

    while (n != 0)
    {
        count++;
        n /= 10;
    }

    return count;
}

// Function to calculate 10^n
long long powerOf10(int n)
{
    long long result = 1;

    for (int i = 0; i < n; i++)
        result *= 10;

    return result;
}

// Karatsuba Multiplication
long long karatsuba(long long x, long long y)
{
    // Base case
    if (x < 10 || y < 10)
        return x * y;

    int n1 = countDigits(x);
    int n2 = countDigits(y);

    int n = (n1 > n2) ? n1 : n2;

    // Make n even
    if (n % 2 != 0)
        n++;

    int m = n / 2;

    long long power = powerOf10(m);

    // Split numbers
    long long a = x / power;
    long long b = x % power;

    long long c = y / power;
    long long d = y % power;

    // Three recursive multiplications
    long long P1 = karatsuba(a, c);
    long long P2 = karatsuba(b, d);
    long long P3 = karatsuba(a + b, c + d);

    // Middle term
    long long Middle = P3 - P1 - P2;

    // Final result
    long long result =
        P1 * powerOf10(2 * m)
        + Middle * power
        + P2;

    return result;
}

int main()
{
    long long x, y;

    printf("Enter first number: ");

    if (scanf("%lld", &x) != 1 || x < 0)
    {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Enter second number: ");

    if (scanf("%lld", &y) != 1 || y < 0)
    {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 1;
    }

    // Calculate digits and split values
    int n1 = countDigits(x);
    int n2 = countDigits(y);
    int n = (n1 > n2) ? n1 : n2;

    if (n % 2 != 0)
        n++;

    int m = n / 2;
    long long power = powerOf10(m);

    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    // Calculate P1, P2, P3
    long long P1 = karatsuba(a, c);
    long long P2 = karatsuba(b, d);
    long long P3 = karatsuba(a + b, c + d);

    long long Middle = P3 - P1 - P2;

    long long finalResult =
        P1 * powerOf10(2 * m)
        + Middle * power
        + P2;

    // Display only the important intermediate results
    printf("\nP1 = %lld\n", P1);
    printf("P2 = %lld\n", P2);
    printf("P3 = %lld\n", P3);
    printf("Middle = P3 - P1 - P2 = %lld\n", Middle);

    printf("\nFinal Result after multiplication using this algorithm\n = %lld\n",
           finalResult);

    return 0;
}