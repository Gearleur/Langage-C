#include <stdio.h>
#include <string.h>
#include <math.h>
#define LONG 255

int num(char* s1)
{
    int i;
    int n = 0;
    for( i = 0; i < strlen(s1); i++)
    {
        if ( s1[i] >= 48 && s1[i] <= 57)
        {
            n = n + (s1[i]-48)*pow(10,strlen(s1)-1-i);
        }
    }
    return n;
}

void main()
{
    char s1[LONG];
    scanf("%[^\n]s", s1);
    printf("%d", num(s1));
}