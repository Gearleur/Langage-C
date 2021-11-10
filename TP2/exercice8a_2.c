#include <stdio.h>
#include <string.h>
#define LONG 255

char* invers(char* s1, char* s2)
{
    int i;
    for ( i = 0; i <= strlen(s1); i++)
    {
        s2[i] = s1[strlen(s1)-1-i];
    }
    s2[strlen(s1)] = '\0';
}

void main()
{
    char s1[LONG];
    char s2[LONG];
    scanf("%[^\n]s", s1);
    invers(s1, s2);
    printf("%s", s2);
}