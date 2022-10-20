#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    printf("Entrer l'entier\n");
    fflush(stdin);
    scanf("%d", &a);
    printf("%d", a*(a+1)/2);
}