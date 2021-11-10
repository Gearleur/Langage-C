#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int* Eratos(int n)
{
    int * ta;
    ta = (int*)malloc(n* sizeof(int));
    ta[0] = 0;
    ta[1] = 0;
    for (int i = 2; i < n; i++) ta[i]=1;
    for (int i = 2; i < n; i++)
    {
        if (ta[i]==1)
        {
            int j = i + i;
            while (j < n)
            {
                ta[j] = 0;
                j += i;
            }
        }
    }
    return ta;
}

void main()
{
    int n;
    int *tab;
    int i;
    printf("Entrer un nombre\n");
    scanf("%d", &n);
    tab = Eratos(n);
    for(i =0 ; i < n; i++)
        printf("%d: %d\n",i,tab[i]);
}

