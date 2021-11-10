#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LONG 255


int* CountChar(char *s)
{
    int i;
    int* ta;
    ta = (int*)malloc(26 * sizeof(int));
    for (int i=0;i<26;i++) ta[i]=0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ta[s[i]-'A']++;
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ta[s[i]-'a']++;
        }
    }
    return ta;
}

int* CountChar2(char *s)
{
    int i;
    int* ta;
    ta = (int*)malloc(26 * sizeof(int));
    for (int i=0;i<26;i++) ta[i]=0;
    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ta[s[i]-'a']++;
        }
    }
    return ta;
}

void main()
{
    char s1[LONG];
    int *tab;
    int i;
    scanf("%[^\n]s", s1);
    tab = CountChar2(s1);
    for(i =0 ; i < 26; i++)
        if (tab[i] !=0)
            printf("le nombre de %c apparait %d\n",i+97,tab[i]);
}