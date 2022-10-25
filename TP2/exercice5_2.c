#include <stdio.h>
#include <string.h>
#define LONG 255

int compar( char* s1, char* s2)
{
    int i;
    if (strlen(s1) != strlen(s2))
    {
        return 0;
    }
    for (i = 0; i <= strlen(s1); ++i)
    {
        if ( s1[i] != s2[i])
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    char s1[LONG];
    char s2[LONG];
    fgets(s1, sizeof s1, stdin);
    fgets(s2, sizeof s2, stdin);
    if (compar(s1, s2))
    {
        printf("pareil\n");
        printf("%s%s", s1,s2);
    }
    else
    {
        printf("differente\n");
        printf("%s%s", s1,s2);
    }
}