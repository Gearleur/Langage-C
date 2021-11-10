#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    printf("Entrez a, b, c\n");
    scanf("%f %f %f", &a, &b, &c);
    if (b*b-4*a*c >= 0)
    {
        printf("La solution est: %f\n", -b/2*a);
    }
    else if (b*b-4*a*c == 0)
    {
        printf("La solution est: %f\n", -b/2*a);
    }
    else
    {
        printf("il n'y a pas de solutions réelles");
    }  
}