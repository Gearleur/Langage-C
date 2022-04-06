#include <stdio.h>
#include <stdlib.h>

int main()
{
    int annee = 3;
    double capInit = 1000;
     for (int i = 0; i < annee; i++)
    {
        capInit += 0.75/100*capInit;
    }

    printf("%f", capInit);
    printf("Capital final fourni par %.2lf euros placés sur %d annees : %.2lf", capInit, annee, capInit);

    return capInit;
}