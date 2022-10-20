#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    int e;
    char mot[100];
    i = 0;
    e = 0;
    printf("entrer le mot\n");
    fgets(mot, sizeof mot, stdin);
    while( mot[i] != '\0')
    {
        if ( mot[i] == ' ')
        {
            e = e + 1;
        }
        i++;
    }
    printf("%d", i - e - 1);
}