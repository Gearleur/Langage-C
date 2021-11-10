#include <stdio.h>
#include <math.h>

void main()
{
    int M;
    int m;
    int a;
    printf("entier :\n");
    scanf("%d", &a);
    M = a;
    m = a;
    
    while (a != 0)
    {
        if ( M < a)
        {
            M = a;
        }
        else
            if (m > a)
            {
            m = a;
            }
        printf ("entier :\n");
        scanf ("%d", &a);
    }
    printf("le max est: %d et le plus petit est: %d", M,m);
}