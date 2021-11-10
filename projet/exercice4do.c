#include <stdio.h>
#include <math.h>

/* parité d'un entier */

void main()
{
    int a;
    printf("entrer l'entier a tester\n");
    scanf("%d", &a);
    if ( (a%2) == 0)
    {
        printf("l'entier est pair\n");
/* ou if ( a%2) printf ("impaire"); */
    }
    else
    {
        printf("l'entier est impaire\n");
    }
}