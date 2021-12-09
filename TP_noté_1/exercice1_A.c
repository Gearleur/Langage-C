#include <stdio.h>
#include <math.h>

int premier(unsigned int n, int *count)
{
    *count = 1;
    unsigned int i;
    if (n == 2 || n == 3 )
    {
        return 1;
    }
    else if (n % 2 == 0 || n == 1 || n % 3 == 0) 
    {
        return 0;
    }
    for (i = 5; i <= sqrt(n); i +=2 )
    {
        (*count)++;
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}




void main()
{
    unsigned int n;
    int c;
    printf("Entrer un nombre: \n");
    scanf("%ld", &n);
    if(premier(n, &c))
    {
        printf("le nombre est premier et iteration = %d\n", c);
    }
    else
    {
        printf("Le nombre n'est pas premier et iteration = %d\n", c);
    }
}