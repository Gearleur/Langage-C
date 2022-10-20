
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAILLE 255

void main()
{
    int i;
    char str[TAILLE];
    char c;
    for (i=0 ; i<TAILLE-1; i++) {
        c = getchar();
        while (getchar() != '\n') ;
        if (c=='0')
            break;  
        else
            str[i]=c;
        printf("'%s'\n",str);
    }
    str[i+1]='\0';
}