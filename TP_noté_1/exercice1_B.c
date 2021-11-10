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

void Premier_inf(int n)
{
    int j;
    char c;
    j = 0;
    viderBuffer();
    for (int i = 2; i < n; i++)
    {
        if (premier(i))
        {
            j++;
            printf("%d\n", i);
            if (j == 25)
            {
                j = 0;
                printf("enter");
                scanf("%c", &c);
            }
        }
    }
}

void main()
{
    int n;
    printf("Entrer un nombre: \n");
    scanf("%d", &n);
    Premier_inf2(n);
}