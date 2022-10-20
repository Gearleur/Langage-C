#include <stdio.h>
#include <math.h>

double rac2(int a, double e)
{
    double x;
    double x1= (1+a)/2;
    do{
        x = x1;
        x1 = (1./2)*(x+(a/x));
    }
    while (fabs((x1-x)/x) > e);
    return x1;
}

double rac3(int a, double e)
{
    double x;
    double x1= 1;
    do{
        x = x1;
        x1 = x+(1./3)*((a/pow(x,2))-x);
    }
    while (fabs((x1-x)/x) > e);
    return x1;
}


double racN(int a, double e, int n)
{
    double x;
    double x1= a/n;
    do{
        x = x1;
        x1 = ((pow(x,n)*(n-1)+a)/(n*pow(x,n-1)));
    }
    while (fabs((x1-x)/x) > e);
    return x1;
}


int main()
{
    int a,n;
    double e;
    double t;
    scanf("%d %lf", &a, &e);
    t = rac2(a,e);
    printf (" racine de %d = %lf\n", a, t);
}