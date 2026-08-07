#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count digits
int countDigits(long long n)
{
    if (n == 0)
        return 1;

    int count = 0;

    while (n != 0)
    {
        count++;
        n = n / 10;
    }

    return count;
}

// Karatsuba Function
long long karatsuba(long long x, long long y)
{
    // Base Case
    if (x < 10 || y < 10)
        return x * y;

    // Find maximum number of digits
    int n1 = countDigits(x);
    int n2 = countDigits(y);

    int n = (n1 > n2) ? n1 : n2;

    // Make n even
    if (n % 2 != 0)
        n++;

    int m = n / 2;

    long long power = pow(10, m);

    // Split numbers
    long long a = x / power;
    long long b = x % power;

    long long c = y / power;
    long long d = y % power;

    // Recursive multiplication
    long long z0 = karatsuba(b, d);

    long long z1 = karatsuba(a + b, c + d);

    long long z2 = karatsuba(a, c);

    // Final result
    return z2 * pow(10, 2 * m)
           + (z1 - z2 - z0) * power
           + z0;
}

int main()
{
    long long x, y;

    printf("Enter two numbers1: ");
    scanf("%lld", &x);
     if (!isInteger(x))
    {
        printf("Invalid input! Please enter an integer only.\n");
        return 0;
    }
    printf("Enter two numbers2: ");
    scanf("%lld", &y);

    printf("Answer = %lld", karatsuba(x, y));

    return 0;
}