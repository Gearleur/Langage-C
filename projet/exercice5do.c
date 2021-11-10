#include <stdio.h>
#include <math.h>

/* affichage du max de trois entier */

void main()
{
    int a, b, c, t;
    printf("enter les trois entier\n");
    scanf("%d %d %d", &a, &b, &c);
    if ( a <= b )
    {
        t = b;
    }
    else
    {
        t = a;
    }
    if ( t <= c)
    {
        t = c;
    }
    printf("le max est %d\n", t);
}