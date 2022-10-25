#include <stdio.h>
#include <string.h>
#define LONG 255

int palin(char* s1)
{
    int i;
    for (i = 0; i <= strlen(s1); i++)
    {
        if ( s1[i] != s1[strlen(s1)-1-i])
        {
            return 0;
        }
    return 1;
    }
}

void main()
{
    char s1[LONG];
    scanf("%[^\n]s", s1);
    if (palin(s1))
    {
        printf("palin\n");
        printf("%s", s1);
    }
    else
    {
        printf("pas palin\n");
        printf("%s", s1);
    }
}