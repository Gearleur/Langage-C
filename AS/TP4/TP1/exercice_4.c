#include <stdio.h>
#include <math.h>

int main()
{
    float a,b;
    char c;
    printf("entrer l'operation\n");
    fflush(stdin);
    scanf("%1f %c %1f", &a, &c, &b);
    switch(c)
    {
        case '+':
        {
            printf("=%.2f",a+b);
            break;      
        }
        case '-':
        {
            printf("=%.2f",a-b);
            break;      
        }
        case '*':
        {
            printf("=%.2f",a*b);
            break;      
        }
        case '/':
        {
            if (b != 0)
            {
                printf("=%.2f",a/b);
                break;
            }
            else
            {
                printf("pas divisible par 0\n");
            }     
        }
        default:
        {
            printf("operation inconnue");
        }
    }
}