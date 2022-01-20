#include <stdio.h>
#include <stdlib.h>
#include "julie.c"

int main()
{
    int a;
    scanf("%d", &a);
    if (bisext2(a))
        printf("bisextil");
    else printf("pas bisext");
    return 0;
}