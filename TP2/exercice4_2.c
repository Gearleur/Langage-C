#include <stdio.h>
#include <string.h>
#define LONG 255

void copie(char *s1, char *s2)
{
    int i;
    for (i = 0; i<=strlen(s1); i++)
    {
        s2[i] = s1[i];
    }
}

int main()
{
    int* a;
    *a = 3;
    int b;
    /*char s1[LONG];
    char s2[LONG];
    scanf("%s%s", s1,s2);
    copie (s1, s2);
    printf( "la copie est %s\n", s2);*/
    scanf("%d", a);
    scanf("%d", b);
    scanf("%d", a);
    scanf("%d", b);
    printf("%d", a);
    printf("%d", b);
    printf("%p", &a);
    printf("%p", &b);
    return 0;
}