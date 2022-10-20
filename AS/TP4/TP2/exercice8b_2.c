#include <stdio.h>
#include <string.h>
#define LONG 255

char* invers2( char* s1)
{
    int i;
    char c;
    for ( i = 0; i < (strlen(s1)/2); i++)
    {
        c = s1[i];
        s1[i] = s1[strlen(s1)-1-i];
        s1[strlen(s1)-1-i] = c;
    }
    s1[strlen(s1)] = '\0';
}

void main()
{
    char s1[LONG];
    scanf("%[^\n]s", s1);
    invers2(s1);
    printf("%s", s1);
}