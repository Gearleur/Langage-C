#include <stdio.h>
#include <math.h>


int fact(int n)
{
    int i = 1;
    int t = 1;
    scanf("%d", &n);
    while ( i < n)
    {
        t = t*i;
        i++;
    }
    return t;
}

int puis(float x, int n)
{
    int i = 1;
    while ( i < n )
    {
        x = x*x;
        i++;
    }
    return x;
}

int parmi(int p, int n)
{
    if (p<n)
    {
        return ((fact(n))/(fact(n-p)*fact(p)));
    }
    else
    {
        return ((fact(p))/(fact(p-n)*fact(n)));
    }
}

int main()
{
    int x = fact(3);
    int y = puis(5,3);
    int z = parmi(3, 4);
    printf("%d %d %d\n", x, y, z);
}