/* ecrire un programme qui determine tous les diviseurs d'un nombre entier */

#include <stdio.h>
#include <math.h>

void main()
{
    /* initialisation du diviseur */
    int i = 1;

    /*déclaration de la saisie */
    int a;

    printf("Entier: ");
    scanf("%d", &a);
    do
    {
        if (a%i == 0)
        {
            printf("%d est un diviseur de %d\n",i ,a);
        }
        i++;
    } 
    while ( i <= a/2);
    printf("%d est un diviseur de %d\n",a ,a);
}