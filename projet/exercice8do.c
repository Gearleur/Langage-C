/* création de la division */

#include <stdio.h>
#include <math.h>

int division(int a, int b)
{
    int max;
    int q=0;
    if (a <= b )
    {
        max = b;
        b = a;
        a = max;
    }
    while ( a >= b)
    {
        q++;
        a -= b;
    }
    printf("le quotien est %d et le reste est %d", q, a);
}

void main()
{
    int a;
    int b;
    printf( "entrer l'entier a et b: ");
    scanf("%d%d", &a, &b);
    division(a, b);
}