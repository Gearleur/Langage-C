#include <stdio.h>
#include <math.h>

void main()
{
    int i;
    char c;
    int j;
    scanf("%c", &c);
    for (i = 1; i<=10; i++)
    {
        for (j = 1 ; j <= 10; j++)
        {
            printf("%2c", c);
        }
        printf("\n");
    }
}