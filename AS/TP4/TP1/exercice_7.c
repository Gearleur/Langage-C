#include <stdio.h>
#include <math.h>

int main()
{
    float i, t;
    int a;
    printf("entrer la somme initiale, le taux d'interet et le nombre d'annee\n");
    scanf("%f %f %d", &i, &t, &a);
    printf("%f\n",i*pow((1+t/100),a));
}