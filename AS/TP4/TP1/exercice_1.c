#include <math.h>
#include <stdio.h>

int main()
{
    float R;
    float H;
    float vol;
    printf("Entrer R et H\n");
    scanf("%f %f", &R, &H);
    vol= M_PI*pow(R,2)*H;
    printf("Volume = %f\n", vol);
}

