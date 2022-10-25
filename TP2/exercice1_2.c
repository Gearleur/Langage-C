#include <stdio.h>


int main()
{
    char c, m;
    printf("demander le caractere\n");
    scanf("%c", &c);
    if ( c >= 65 && c <= 90)
    {
        c = c + 32;
        printf( " convertion en minuscule %c\n", c);
    }
    else if ( c >= 91 && c <= 121)
    {
        c = c - 32;
        printf("convertion en majuscule %c\n", c);
    }
    else
    {
        printf(" %c n'est pas un charactère\n", c);
    }
}

