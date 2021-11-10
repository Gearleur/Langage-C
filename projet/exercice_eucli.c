#include <stdio.h>
#include <math.h>

int pgcd(int a, int b)
{
    int r;
    do
    {
        r = a%b;
        a = b;
        b = r;
    }
    while ( r > 0);
    return b;
}

int eucli(int a, int b)
{
    int r;
    int q;
    int u;
    int v;
    while (r > 0 )
    {

    }
}

void main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d",pgcd(a, b));

}