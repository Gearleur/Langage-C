#include <stdio.h>
#include <math.h>

double f(double x)
{
return (x-1/(2+pow(x,2)));
}

int main()
{
    int n;
    double a, b, c;
    int i = 1;
    printf("intervalle\n");
    scanf("%lf %lf", &a, &b);
    printf("precision\n");
    scanf("%d", &n);
    c = (a+b)/2;
    do
    {
        c = (a+b)/2;
        if (f(a)*f(c) <= 0)
        {
            b=c;
        }
        else if (f(b)*f(c) <= 0)
        {
            a=c;
        }
        else 
        {
            printf ("pas de solution\n");
        }
        i++;
    }
    while ( fabs(c)> pow(10,-3));
    printf ("x est proche de %lf\n", c);
}