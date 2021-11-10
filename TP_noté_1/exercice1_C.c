#include <stdio.h>
#include <math.h>

void viderBuffer()
{
    int c = 0;
    while (c != '\n')
        c = getchar();
}

int premier(unsigned int n)
{
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
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void N_Premier(int n)
{
    char c;
    int j=0;
    int i=2;
    viderBuffer();
    while (j< n)
    {
        if (premier(i))
        {   
            j++;
            printf("%d\n", i);
            if (j%25 == 0)
            {
                printf("entrer");
                scanf("%c", &c);
            }
        }
    i++;
    }
}


void main()
{
    int n, i;
    int* tab;
    printf("Entrer un nombre: \n");
    scanf("%d", &n);
    tab = N_Premier2(n);
    for(i =0 ; i < n; i++)
        printf("%d\n",tab[i]);
}