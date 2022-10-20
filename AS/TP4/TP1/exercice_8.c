#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int i = 1;
    int j = 1;
    int valeur;
    printf("entrez l'entier\n");
    scanf("%d", &n);
    while (i <= n)
    {
        j = 1;
        while ( j <= n)
        {
            valeur = i*j;
            printf("\t%d", valeur);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("fin\n");
}