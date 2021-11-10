#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 
 * 
calcule (a * b) % c en tenant compte du fait que a * b pourrait overflow 
 */
long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0;
    long long y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b = b / 2;
    }
    return x % mod;
}
/* 
 * exponentielle modulo
 */
long long modulo(long long base, long long exposant, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exposant > 0)
    {
        if (exposant % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exposant = exposant / 2;
    }
    return x % mod;
}
 
/*
 * Test de primalité de Miller-Rabin, l'itération pour la précision
 */
int Miller(long long p,int iteration)
{
    long long d;
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p%2 == 0)
    {
        return 0;
    }
    d = p - 1;
    while (d%2 == 0)
    {
        d = d / 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        long long a = rand() % (p - 1) + 1;
        long long temp = d;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp = temp * 2;
        }
        if (mod != p - 1 && temp % 2 == 0) /* pour le premier test temp % 2 */
        {
            return 0;
        }
    }
    return 1;
}
//Main
int main()
{
    int iteration = 5;
    long long num;
    printf("Entrer un entier pur tester sa primalitE: ");
    scanf("%lld", &num);
    if ( Miller( num, iteration))
        printf("\n%lld est premier\n", num);
    else
        printf("\n%lld n'est pas premier\n", num);
    return 0;
}