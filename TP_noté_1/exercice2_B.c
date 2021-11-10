#include <stdio.h>
#include <math.h>

int premier(long int n)
{
    long int i;
    if (n % 2 == 0 || n == 1)
    {
        return 0;
    }
    for (i = 3; i <= sqrt(n); i +=2 )
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Parfait(long int n)
{
    long int res = 1;
    for(long int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            res = res + i +(n/i);
            if (res > n)
            {
                return 0;
            }
        }
    }
    if (res < n)
    {
        return 0;
    }
    return 1;
}

void Parfait_inf(long int n)
{
    long int i;
    for (i = 6; i < n; i++)
    {
        if (Parfait(i))
        {
            printf("%ld\n", i);
        }
    }
}

void Parfait_inf2(long int n)
{
    int p=1;
    for(long int i= 1; i*(i+1)/2 < n; i=pow(2,p++)-1 )
    {
        if (premier(i))
        {
            printf("%ld\n",i*(i+1)/2);
        }
    }
}

void main()
{
    long int n;
    printf("Entrer un nombre: \n");
    scanf("%ld", &n);
    Parfait_inf(n);
}