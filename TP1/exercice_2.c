#include <math.h>
#include <stdio.h>

int main()
{
    int t;
    printf("Entrer la température\n");
    scanf(" %d", &t);
    if (0<=t && t<=20)
        printf(" froid\n");
    if (21 <= t && t <= 50)
        printf(" chaud\n");
    if (t >= 51)
        printf("Très chaud\n");
}