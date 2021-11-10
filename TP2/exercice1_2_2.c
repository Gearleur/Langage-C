#include <stdio.h>
#define LONG 255

char* maj_min(char *s)
{
    int i;
    for (i=0; s[i] != '\0'; i++)
    {
        if (s[i]>='A' && s[i]<= 'Z')
        {
            s[i] = s[i] + 32;
        }
        else if ( s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
    return s;
}

void main()
{
    char s[LONG];
    scanf("%[^\n]s", s);
    maj_min(s);
    printf("%s", s);
}