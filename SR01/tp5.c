#include <stdio.h>
#include <string.h>

 /* inverse les majuscules et les minuscules de s1 et retourne le resultat dans s2 exemple: s1="TiCtAc"  s2="tIcTaC" */
 void mystrupdown(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            s2[i] = s1[i] - 32;
        }
        else if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s2[i] = s1[i] + 32;
        }
        else
        {
            s2[i] = s1[i];
        }
    }
    s2[i] = '\0';
}

/* inverse la chaîne s1 et retoune le résultat dans s2:   exemple  s1="tac" s2="cat" */
void mystrinv(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] != '\0'; i++)
    {
        s2[i] = s1[strlen(s1) - i - 1];
    }
    s2[i] = '\0';
}

 /* retourne le nombre d'occurrences de c dans  la chaîne s */
 int mystrchrn(char *s, char c)
{
    int i, count = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }
    return count;
}

/* copie les n derniers caractères de s1 dans s2 et retourne s2 */
char *mystrncpy(char *s1, char *s2, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        s2[i] = s1[strlen(s1) - n + i];
    }
    s2[i] = '\0';
    return s2;
}

 /* concatène au plus les n derniers caractères de s1 à la chaîne s2 */
 void mystrncat(char *s1, char *s2, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        s2[strlen(s2)] = s1[strlen(s1) - n + i];
    }
    s2[strlen(s2)] = '\0';
}

/* Ecrire un programmes de test  teststring.c  qui permet de tester l'ensemble des fonctions de la bibliothèque.*/
