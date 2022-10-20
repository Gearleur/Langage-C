#include <stdio.h>
#include <math.h>


int main()
{
    int n;
    scanf("%d", &n);
    int i = 2;
    float t = 1;
    while ( i < n)
    {
        t = t + (1/(pow(i,4)));
        i++;
    }
    printf("%f", pow((t*90),1.0/4.0));
}