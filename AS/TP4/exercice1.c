#include <stdio.h>
#include <stdlib.h>

int** TrinanglaPascal(int n)
{
    int** TrPascal;
    TrPascal = (int**)malloc(n* sizeof(int*));
    *TrPascal = (int*)malloc(2* sizeof(int));
    *(*(TrPascal+0)+0) = 1;
    *(*(TrPascal+0)+1) = 0;
    for (int i = 1; i <= n-1; i++)
    {
        *(TrPascal+i)= (int*)malloc((i+2)* sizeof(int));
        *(*(TrPascal+i)+0) = 1;
        for(int j = 1; j <= i ; j++ )
        {
           *(*(TrPascal+i)+j) = *(*(TrPascal+i-1)+j-1) + *(*(TrPascal+i-1)+j); 
        }
        *(*(TrPascal+i)+i+1) = 0;
    }
    return TrPascal;
}

int** TrinanglaPascal2(int n)
{
    int** TrPascal;
    TrPascal = (int**)malloc(n* sizeof(int*));
    *TrPascal = (int*)malloc(2* sizeof(int));
    *(*(TrPascal+0)+0) = 1;
    for (int i = 1; i <= n-1; i++)
    {
        *(TrPascal+i)= (int*)malloc((i+1)* sizeof(int));
        *(*(TrPascal+i)+0) = 1;
        for(int j = 1; j <= i-1 ; j++ )
        {
           *(*(TrPascal+i)+j) = *(*(TrPascal+i-1)+j-1) + *(*(TrPascal+i-1)+j); 
        }
        *(*(TrPascal+i)+i) = 1;
    }
    return TrPascal;
}

void main()
{
    int n;
    int** tab;
    scanf("%d", &n);
    tab = TrinanglaPascal2(n);
    for (int i = 0; i <= n-1; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%d\t", *(*(tab+i)+j));
        }
        printf("\n");
    }
    free (tab);
}