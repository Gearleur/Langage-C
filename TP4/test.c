#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a = pow(2, 53) + 1;
    double b = pow(2, 53);
    double c = pow(2, 53) + 3;
    double d, e;
    d = 0.1;
    e = 0.2;
    if ( a == b)
    {
        printf("chelou\n");
        printf("%lf\n", a-b);
        printf("%lf\n", c-b);
        printf("%lf", d+e);
    }
    else
    {
        printf("marche pas");
    }
    return 0;
}