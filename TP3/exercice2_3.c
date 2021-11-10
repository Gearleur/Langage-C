#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LONG 255

char* concat2(char* s1, char* s2)
{
    int i;
    int j;
    char *s3;
    s3 = (char*)malloc(sizeof(char));
        for (i = 0; s1[i] != '\0'; i++)
        {
            s3 = (char*)realloc(s3,i+2);
            s3[i] = s1[i];
            s3[i+1] = '\0';
            printf("%s\n", s3);
        }
        j = strlen(s3);
        for (i =j; s2[i-j] != '\0'; i++)
        {
            s3 = (char*)realloc(s3,i+2);
            s3[i] = s2[i-j];
            s3[i+1] = '\0';
            printf("%s\n", s3);
        }
    s3[i] = '\0';
    return s3;
}

char main()
{
    char s1[LONG];
    char s2[LONG];
    char *s3;
    scanf("%s", s1);
    scanf("%s", s2);
    s3 = concat2(s1,s2);
    printf("%s\n", s3);
    printf("%d", strlen(s3));
    free(s3);
}
