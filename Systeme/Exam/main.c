#include <stdio.h>
#include <stdlib.h>
#include "ecureuil.h"

/*prototypage des focntion */

double calcul(int, double);
void affichage(double, int, double);

int main(int argn, char* argv[])
{
    double si, sf; int an;

    /*verification du nombre d'arguments passés au programme */
    if (argn != 3)
    {
        fprintf(stderr,"nombre d'argument invalid\n");
        exit(2);
    }

    si = atof(argv[1]);
    an = atoi(argv[2]);

    /*calcul du capital */
    sf = calcul(an, si);

    /*affichage du capital final*/
    affichage(si, an, sf);

    exit(0);
}