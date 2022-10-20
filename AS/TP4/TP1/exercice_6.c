#include <stdio.h>
#include <math.h>

int main()
{
    float note, som = 0;
    int count = 0;
    while ( note != -1.f )
    {
        printf("entrez -1 pour finir\n");
        scanf("%f", &note);
        som = som + note;
        count++;
    }
    printf ("moyenne des notes %f", som/count);
}