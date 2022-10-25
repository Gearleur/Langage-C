#include <stdio.h>
#include <math.h>

int premier(long int n, int *count)
{
    long int i;
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

int Parfait(long int n)
{
    long int res = 1;
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


int Parfait2(long int n, int* count)
{
    unsigned long int res;
    res = sqrt(n*2);
    if (premier(res, count) && ((res*(res+1))/2)==n )
    {
        return 1;
    }
    return 0;
}

void ParfaitEucl(int n, int * count)
{
    long long int res = 0;
    long long int to = 0;
    int c=1;
    int i = 3;
    printf("6\n");
    while (c <= n-1)
    {
        (*count)++;
        res = pow(2,i)-1;
        if (premier(i, count) == 1 && premier(res, count) == 1)
        {
            to = pow(2,i-1)*res;
            printf("%d\n", to);
            c+=1;
        }
        i+=2;
    }
}

int* Eratos(int n, int* count)
{
    *count = 0;
    int * ta;
    ta = (int*)calloc(n, sizeof(int));
    ta[2] = 1;
    ta[0] = 0;
    ta[1] = 0;
    for (int i = 4; i < n; i+=2) ta[i]=0;
    for (int i = 3; i < n; i+=2) ta[i]=1;
    for (int i = 3; i <= sqrt(n); i+=2)
    {
        (*count)++;
        if (ta[i]==1)
        {
            int j = (i * i);
            while (j < n)
            {
                (*count)++;
                ta[j] = 0;
                j += i;
            }
        }
    }
    return ta;
}

void ParfaitEucl2(int n, int * count)
{
    long long int res = 0;
    long long int to = 0;
    int c=1;
    int * tab;
    tab = Eratos(n, &c);
    int i = 3;
    printf("6\n");
    while (c <= n-1)
    {
        for(int j = 0; j < n; j++)
        (*count)++;
        res = pow(2,i)-1;
        if (premier(i, count) == 1 && premier(res, count) == 1)
        {
            to = pow(2,i-1)*res;
            printf("%d\n", to);
            c+=1;
        }
        i+=2;
    }
}

int ParfaitPasOpti(long int n)
{
    long int res = 1;
    if (n == 1)
        return 0;
    for(long int i = 2; i < n; ++i)
    {
        if(n%i == 0)
        {
            res = res + i;
        }
    }
    if (res < n || res > n)
    {
        return 0;
    }
    return 1;
}

void main()
{
    long int n;
    int j = 0;
    int count = 0;
    printf("Entrer un nombre: \n");
    scanf("%ld", &n);
    /*while (j<n)
    {
        if(Parfait2(j, &count))
        {
            printf("%d\n", j);
            j++;
        }
    }*/
    ParfaitEucl(n, &count);
    printf("%d\n", count);
}