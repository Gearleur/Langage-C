#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
                                                                                                       
int* Eratos(int n, int* count)
{
    *count = 0;
    int * ta;
    ta = (int*)calloc(n, sizeof(int));
    ta[2] = 1;
    ta[0] = 0;
    ta[1] = 0;
    for (int i = 4; i < n; i+=2) ta[i]=0;
    for (int i = 3; i < n; i+=2) ta[i]=1;
    for (int i = 3; i <= sqrt(n); i+=2)
    {
        (*count)++;
        if (ta[i]==1)
        {
            int j = (i * i);
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
    int c = 0;
    int *tab;
    int i;
    printf("Entrer un nombre\n");
    scanf("%d", &n);
    tab = Eratos(n, &c);
    /*for(i =0 ; i < n; i++)
        if (tab[i]==1)
            printf("%d\n",i);*/
    printf("%d", c);
    free(tab);
    return 0;
}