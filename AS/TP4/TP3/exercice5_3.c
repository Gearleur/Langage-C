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

char* doublChar( char *s, char c)
{
   int i,j;
   char *s2;
   j = 0;
   for (i = 0; s[i] !='\0'; ++i)
   {
    if (s[i] == c)
    {
        s2[j] = c;
        j++;
    }
    s2[j] = s[i];
    j++;
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
    c = getchar();
    s2 = doublChar(s1, c);
    printf("%s", s2);  
}