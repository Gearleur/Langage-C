#include <stdio.h>
#include <string.h>
#define LONG 255

char* concat(char* s1, char * s2, char *s3)
{
    int i;
    if ( strlen(s1)+strlen(s2)<=LONG)
    {
        for (i = 0; i<=strlen(s1); i++)
        {
            s3[i] = s1[i];
        }
        for (i = 0; i<=strlen(s2); i++)
        {
            s3[i+strlen(s1)] = s2[i];
        }
        s3[strlen(s1)+strlen(s2)] = '\0';
    }

}

void main()
{
    char s1[LONG];
    char s2[LONG];
    char s3[LONG];
    scanf("%s", s1);
    scanf("%s", s2);
    concat(s1, s2, s3);
    printf("%s", s3);
}