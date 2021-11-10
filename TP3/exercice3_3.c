#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* scan()
{
    int i=0;
    char *s1;
    char c;
    s1 = (char*)malloc(sizeof(char));
    do
    {
        scanf("%c", &c);
        s1 = (char*)realloc(s1,i+1);
        s1[i] = c;
        i++;
    }
    while ( c !='\n');
    s1[i-1] = '\0';
    return s1;
}

void print(char *s)
{
    int i;
    for (i = 0; s[i] != '\0';i++)
    {
        printf("%c ", s[i]);
    }
}

int main()
{
    char *s2;
    s2 = scan();
    printf("%s\n", s2);
    printf("%ld\n", strlen(s2));
    print(s2);
}