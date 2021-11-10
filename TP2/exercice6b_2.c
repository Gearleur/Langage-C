#include <stdio.h>
#include <string.h>
#define LONG 255

char* concat2(char* s1, char* s2)
{
    int i;
    if (strlen(s1)+strlen(s2)<=LONG)
    {
        for (i = 0; i<=strlen(s2); i++)
        {
            s1[i+strlen(s2)] = s2[i];
        }
    }
}

void main()
{
    char s1[LONG];
    char s2[LONG];
    scanf("%s", s1);
    scanf("%s", s2);
    concat2(s1, s2);
    printf("%s", s1);
}