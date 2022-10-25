#include <stdio.h>
#include <math.h>

int premier(unsigned long int n, int* count)
{
    unsigned long int i;
    if (n % 2 == 0 || n == 1)
    {
        return 0;
    }
    for (i = 3; i <= sqrt(n); i +=2 )
    {
        (*count)++;
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Parfait(unsigned long int n)
{
    unsigned long int res = 1;
    if (n == 1)
        return 0;
    for(unsigned long int i = 2; i <= sqrt(n); i++)
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


void N_Parfait(unsigned long int n)
{
    int j=0;
    unsigned long int i=6;
    while (j< n)
    {
        if (Parfait(i))
        {   
            j++;
            printf("%ld\n", i);
        }
    i++;
    }
}

void N_Parfait2(unsigned long int n, int* count)
{
    int j=0;
    int p=1;
    for(unsigned long int i= 1; j < n; i=pow(2,p++)-1 )
    {
        if (premier(i, count))
        {
            printf("%ld\n",i*(i+1)/2);
            j++;
        }
        else{
            (*count)++;
        }
    }
}


void main()
{
    unsigned long int n;
    int count = 0;
    printf("Entrer un nombre: \n");
    scanf("%ld", &n);
    N_Parfait2(n, &count);
    printf("%d\n", count);
}