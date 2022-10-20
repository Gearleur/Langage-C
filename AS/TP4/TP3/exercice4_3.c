#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LONG 255

void viderBuffer()
{
    int c = 0;
    while (c != '\n')
        c = getchar();
}

int countchar(char* s, char c,int *res)
{
    int i;
    int k = 0;
    for ( i = 0; s[i] != '\0'; ++i )
    {
        if (s[i] == c)
        {
            k++;
        }
    }
    *res=i;
    return k;
}

char* supChar( char *s, char c)
{
   int l,i,j,tot,nb;
   char *s2;
   nb = countchar( s, c, &tot);
   l = tot-nb+1;
   s2 = (char*)malloc(l*sizeof(char));
   j = 0;
   for (i = 0; s[i] !='\0'; ++i)
   {
    if (s[i] != c)
    {
        s2[j] = s[i];
        j++;
    }
   }
   s2[j] = '\0';
   return s2;
}

void main()
{
    char s1[LONG];
    char *s2;
    char c;
    scanf("%[^\n]s", s1);
    viderBuffer();
    c = getchar();;
    s2 = supChar(s1, c);
    printf("%s", s2);  
}