#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int* Aktin(int n)
{
    int * array;
    array = (int*)malloc(n* sizeof(int));
    for (int i = 0; i < n; i++) array[i]= 0;
    for (int x = 1; x < sqrt(n); x++) 
    {
        for (int y = 1; y < sqrt(n); y++) 
        {
            int k = 4 * x * x + y * y;
            if ((k < n) && ((k % 12 == 1) || (k % 12 == 5))) 
            {
                if (array[k] == 1)
                {
                    array[k] = 0;
                }
                else
                {
                    array[k] = 1;
                }
            }
            k = 3 * x * x + y * y;
            if ((k < n) && (k % 12 == 7)) 
            {
                if (array[k] == 1)
                {
                    array[k] = 0;
                }
                else
                {
                    array[k] = 1;
                }
            }
            if (x > y) 
            {
                k = 3 * x * x - y * y;
                if ((k < n) && (k % 12 == 11)) 
                {
                    if (array[k] == 1)
                    {
                        array[k] = 0;
                    }
                    else
                    {
                        array[k] = 1;
                    }
                }
            }
        }
    }
    array[2] = 1;
    array[3] = 1;
    for (int j = 5; j <= sqrt(n); j++) 
    {
        if (array[j] == 1) 
        {
            int j2 = j * j;
            for (int k = j2; k < n; k += j2) 
            {
                array[k] = 0;
        }
        }
    }
    return array;
}


void main()
{
    int n;
    int *tab;
    int i;
    printf("Entrer un nombre\n");
    scanf("%d", &n);
    tab = Aktin(n);
    for(i =2 ; i < n; i++)
    {
        if (tab[i]==1)
            printf("%d\n",i);
    }
}