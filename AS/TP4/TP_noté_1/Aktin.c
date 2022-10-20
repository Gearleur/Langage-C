#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int* Aktin(int n, int* count1, int* count2, int* count3, int* count4)
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
                (*count1)++;
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
                (*count2)++;
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
                    (*count3)++;
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
                (*count4)++;
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
    //printf("Entrer un nombre\n");
    //scanf("%d", &n);
    for(int i =100 ; i < 10000000; i=i*10)
    {
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        tab = Aktin(i, &c1, &c2, &c3, &c4);
        printf("%d, %d, %d, %d\n", c1,c2,c3,c4);
        free(tab);
    }
}