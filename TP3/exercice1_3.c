#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LONG 255

char* copie(char *s1)
{
    int i;
    char *s2;
    s2 = (char*)malloc(strlen(s1)*sizeof(char));
    for ( i = 0; s1[i]!='\0'; ++i)
    {
        s2[i] = s1[i];
    }
    s2[i] = '\0';
    return s2;
}

void main()
{
    char s1[LONG];
    //char* str1 = (char*)malloc(100*sizeof(char));
    char *s2;
    scanf("%s", s1);
    s2 = copie(s1);
    printf("%s", s2);
    free(s2);
}
