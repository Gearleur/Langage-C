#include <stdio.h>
#include <math.h>

/* echange de deux entiers */

void main()
{
    int a;
    int b;
    int e;
    printf("demande des deux entier\n");
    scanf("%d %d", &a, &b);
    e = a;
    a = b;
    b = e;
    printf("les valeurs echangées sont %d et %d", a, b);
}