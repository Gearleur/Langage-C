#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int premier(unsigned int n, long long int *count)
{
    unsigned int i;
    if (n == 1 || n == 0) 
    {
        return 0;
    }
    for (i = 3; i < n; i++ )
    {
        (*count)++;
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


int premierSQRT(unsigned int n, long long int *count)
{
    unsigned int i;
    if (n == 1 || n == 0) 
    {
        return 0;
    }
    for (i = 3; i <= sqrt(n); i++ )
    {
        (*count)++;
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int premierPair(unsigned int n, long long int *count)
{
    unsigned int i;
    if (n == 2)
    {
        return 1;
    }
    else if (n % 2 == 0 || n == 1 || n == 0) 
    {
        return 0;
    }
    for (i = 3; i < n; i +=2 )
    {
        
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int* premierOptiFinal(long long int *count)
{
    int * tab;
    tab = (int*)calloc(100, sizeof(int));
    tab[2] = 1;
    int premier;
    for (int i = 3; i < 100; i += 2)
    {
        int s = sqrt(i);
        premier = 1;
        for (int j = 3; j <= s+1; j +=2 )
        {
            *count++;
            if (i % j == 0)
            {
                premier = 0;
                break;
            }
        }
        tab[i] = 1;
    }
    return tab;
}

int premierOptiFinal2(long long int n,long long int *count)
{
    long long int i;
    if (n == 2)
    {
        return 1;
    }
    else if (n % 2 == 0 || n == 1 || n == 0) 
    {
        return 0;
    }
    int s = sqrt(n);
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

int* premierP(int n,long long int *count)
{
    int pos = 0;
    int premier = 1;
    int *tab;
    int taille = n/log(n)*1.2;
    tab = (int*)malloc(taille*sizeof(int));
    tab[pos]=2;
    for (int i = 3; i < n; i += 2)
    {
        int s = sqrt(i)+1;
        for (int j = 0; j <= pos; j++ )
        {
            (*count)++;
            int value = tab[j];
            if (value > s)
            {
                premier = 1;
                break;
            }
            if ((i % value) == 0)
            {
                premier = 0;
                break;
            }
        }
        if (premier == 1)
        {
            pos++;
            tab[pos] = i;
        }
    }
    return tab;
}




int main(void)
{
    unsigned int n;
    long long int c, cS, cP, cO;
    int *t;
    int* t2;
    n = 10000000;
    int taille = n/log(n)*1.2;
    t = (int*)malloc(taille*sizeof(int));
    c = 0;
    cS = 0;
    cP = 0;
    cO = 0;
    long long int cT = 0;
    int np = 1;
    t = premierP(n,&cT);

    for(int i = 3; i <= 1000000; i++)
    {
        if (premierOptiFinal2(rand(), &cO))
        {
            printf("");
        }
    }
    //for(int i = 0; i <= 25; i++)
        //printf("%d\n", t[i]);
    //printf("%d et %d pour %d\n", cO, cT, np);
    printf("%d\n", cO);
    free(t);
    return 0;

}