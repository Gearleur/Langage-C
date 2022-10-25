#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int modulo(long long int base, long long int exposant, long long int mod) 
{
    long long int x = 1;
    long long int y = base;
    while (exposant > 0) 
    {
        if (exposant % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exposant = exposant / 2;
    }
    return x % mod;
}

int Fermat(long long int p, int iterations) 
{
    int i;
    if (p == 1) 
    {
        return 0;
    }

    for (i = 0; i < iterations; i++) 
    {
        long long int a = rand() % (p - 1) + 1;
        if (modulo(a, p - 1, p) != 1) 
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    int iteration = 5;
    long long int num;
    printf("Enter integer to test primality: ");
    scanf("%lld", &num);
    if (Fermat(num, iteration) == 1)
        printf("%lld is prime ", num);
    else
        printf("%lld is not prime ", num);
    return 0;
}