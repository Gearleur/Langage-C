#include <stdio.h>
#include <stdlib.h>
#include "ecureuil.h"

int calcul(int annee, double capInit)
{
    double res = capInit;
    for (int i = 0; i < annee; i++)
    {
        res += TAUX/100*capInit;
    }

    return res;
}