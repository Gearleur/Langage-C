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
//if premier? paire ? 6/8.
    if (n == 1)
        return 0;
    for(long int i = 2; i <= sqrt(n); ++i)
    {
        if(n%i == 0)
        {
            if (i==n/i)
            {
                res = res + i;
            }
            else
            {
            res = res + i +(n/i);
            }
            if (res > n)        /* fréquence ? */
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


int Parfait2(long int n)
{
    unsigned long int res;
    res = sqrt(n*2);
    if (premier(res) && ((res*(res+1))/2)==n )
    {
        return 1;
    }
    return 0;
}

void main()
{
    long int n;
    printf("Entrer un nombre: \n");
    scanf("%ld", &n);
    if (Parfait(n))
    {
        printf("Est parfait");
    }
    else
    {
        printf("N'est pas parfait");
    }
}