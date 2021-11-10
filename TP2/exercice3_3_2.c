#include <stdio.h>
#include <math.h>

int main()
{
    int tab[5][5];
    int i, j;
    for(i = 0; i <= 5; i++)
    {
        for( j = 0; j <= 5; j++)
        {
            scanf("%c", tab[i][j]);
        }
    printf("%d", tab);
    }
    return 0;
}