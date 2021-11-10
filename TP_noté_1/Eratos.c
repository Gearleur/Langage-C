#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
                                                                                                       
int* Eratos(int n)
{
    int * ta;
    ta = (int*)calloc(n, sizeof(int));
    ta[2] = 1;
    ta[0] = 0;
    ta[1] = 0;
    for (int i = 4; i < n; i+=2) ta[i]=0;
    for (int i = 3; i < n; i+=2) ta[i]=1;
    for (int i = 3; i <= sqrt(n); i+=2)
    {
        if (ta[i]==1)
        {
            int j = (i * i);
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
        if (tab[i]==0)
            printf("%d: %d\n",i,tab[i]);
}