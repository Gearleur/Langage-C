#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int* Eratos(int n, int* count)
{
    int * ta;
    ta = (int*)malloc(n* sizeof(int));
    ta[0] = 0;
    ta[1] = 0;
    for (int i = 2; i < n; i++) ta[i]=1;
    for (int i = 2; i < n; i++)
    {
        (*count)++;
        if (ta[i]==1)
        {
            int j = i + i;
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

int main()
{
    int n;
    int *tab;
    int i;
    int cE = 0;
    printf("Entrer un nombre\n");
    scanf("%d", &n);
    tab = Eratos(n, &cE);
    /*for(i =0 ; i < n; i++)
        printf("%d: %d\n",i,tab[i]);*/
    printf("%d", cE);
    return 0;
}

