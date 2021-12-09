#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char* tab;
    tab = malloc( 2* sizeof(char));
    tab[0] = "a";
    tab[1] = "b";
    for( int i=0; i<2; i++ )
        printf("%s", tab[i]);
    /*for ( int i=2; i<4; i++ )
        printf("%d", tab[i])*/
    free(tab);
}