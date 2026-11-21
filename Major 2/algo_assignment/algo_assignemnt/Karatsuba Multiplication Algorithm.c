// Write a C program to implement the Karatsuba Multiplication Algorithm for multiplying two numbers.

#include <stdio.h>

// Count digits for positive numbers
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

// Calculate 10^n
long long powerOf10(int n)
{
    long long result = 1;
    for (int i = 0; i < n; i++)
        result *= 10;
    return result;
}

// Absolute value
long long absValue(long long n)
{
    if (n < 0)
        return -n;
    else 
        return n;
}

// Karatsuba Multiplication
long long karatsuba(long long x, long long y)
{
    // Base case
    if (x < 10 || y < 10)
        return x * y;

    int n1 = countDigits(x);
    int n2 = countDigits(y);

    int n;
    if (n1 > n2)
        n = n1;
    else
        n = n2;

    if (n % 2 != 0)
        n++;

    int m = n / 2;
    long long power = powerOf10(m);

    // Split
    long long a = x / power;
    long long b = x % power;

    long long c = y / power;
    long long d = y % power;

    // Recursive multiplication
    long long P1 = karatsuba(a, c);
    long long P2 = karatsuba(b, d);
    long long P3 = karatsuba(a + b, c + d);

    long long Middle = P3 - P1 - P2;

    return P1 * powerOf10(2 * m) + Middle * power + P2;
}

int main()
{
    long long x, y;

    printf("Enter first number: ");
    scanf("%lld", &x);

    printf("Enter second number: ");
    scanf("%lld", &y);

    // Save original values
    long long originalX = x;
    long long originalY = y;

    // Determine sign
    int sign = 1;
    if ((x < 0 && y >= 0) || (x >= 0 && y < 0))
        sign = -1;

    // Convert to positive
    x = absValue(x);
    y = absValue(y);

    // Split values for display
    int n1 = countDigits(x);
    int n2 = countDigits(y);
    int n;
    if (n1 > n2)
        n = n1;
    else
        n = n2;

    if (n % 2 != 0)
        n++;

    int m = n / 2;
    long long power = powerOf10(m);

    long long a = x / power;
    long long b = x % power;

    long long c = y / power;
    long long d = y % power;

    // Intermediate values
    long long P1 = karatsuba(a, c);
    long long P2 = karatsuba(b, d);
    long long P3 = karatsuba(a + b, c + d);

    long long Middle = P3 - P1 - P2;

    long long finalResult =
        P1 * powerOf10(2 * m) + Middle * power + P2;

    // Apply sign
    finalResult *= sign;

    printf("\n----- Karatsuba Steps -----\n");
    printf("Original X = %lld\n", originalX);
    printf("Original Y = %lld\n", originalY);

    printf("Using Absolute Values:\n");
    printf("X = %lld, Y = %lld\n", x, y);

    printf("\na = %lld, b = %lld\n", a, b);
    printf("c = %lld, d = %lld\n", c, d);

    printf("\nP1 = %lld\n", P1);
    printf("P2 = %lld\n", P2);
    printf("P3 = %lld\n", P3);
    printf("Middle = %lld\n", Middle);

    printf("\nFinal Result = %lld\n", finalResult);

    return 0;
}


/*
Enter first number: 435
Enter second number: 255

----- Karatsuba Steps -----
Original X = 435
Original Y = 255
Using Absolute Values:
X = 435, Y = 255

a = 4, b = 35
c = 2, d = 55

P1 = 8
P2 = 1925
P3 = 2223
Middle = 290

Final Result = 110925
*/
