/* Synthèse de cours : 
    Gestion dynamique de la mémoire de

Passe par deux fonctions:
    -allocation : malloc
    -désallocation : free

=> Création du contenant APRES avoir obtenu la taille du contenant
=> Si la taille du contenu varie alors redimentionnement du contenant

Equation générale : taille du contenant = taille du contenu A TOUT MOMENT

1 Allocation memoire : 

    Pointeur = (type*)malloc(nbcases * sizeof(type))

Malloc renvoie une adresse en sortie
    adresse du bloc alloué
A stocker dans 1 pointeur

Exemple / principe : 
                                                         ____
int * P ; --> compilateur --> adresse d'une case (#B03) |#A01|
                                                                                _ _ _ _ _ _ _ _ _ _ 
P = (int*)malloc(10 * sizeof(int)); ---> adresse #A01 d'un tableau de 10 cases |_|_|_|_|_|_|_|_|_|_|

Acces aux element
version indicée
    tab[i] et i++  <-------|
                           |
Version pointeur           |
    p = tab ; (&tab[0])    |
    *p et p++              |
                           |
*(tab+i) <-----------------|
    ou *(p+i)

Desallocation
    remettre à disposition la mémoire alloué

=> free ( adresse bloc mémoire)
----->free ( pointeur )

Attention si p = (int*)malloc(10 * sizeof(int))
    Alors liberation des 10 cases avec free(p)


fonction realloc : 1 nouv = malloc(nouvelletaille)
                   2 copie(ancien block vers nouveau block)
                   3 free(ancien tableau)
*/

//Serie 3 : réécriture des fct de traitement des chaines

//1 fonction copie

char * copied(char * s)
{
    int nbcases;
    int i;
    char *p;
    nbcases = strlen(s) + 1;
    p = (char*)malloc(nbcases* sizeof(char));
    for ( i = 0; s[i] != '\0'; i++)
    {
        p[i] = s[i];
    }
    p[i] = '\0';
    return p;
}

//version pointeur 

char * copied2(char * s)
{
    char * p;
    char * sv;
    sv = p = (char*)malloc((strlen(s)+1) * sizeof(char));
    while (*s !='\0')
    {
        *p = *s;
        p++;
        s++;
    }
    *p = '\0';
    return sv;
    /* ou 
    while ((*p++ = *s++)!='\0');
    */
}

char * concat1d(char * ps1, char * ps2)
{
    int nbcases;
    char * p, *sv;
    nbcases = strlen(ps1) + strlen(ps2) + 1;
    sv = p = (char*)malloc(nbcases* sizeof(char));
    while( *ps1 !='\0')
        *p++ = *ps1++;
    while( *ps2 !='\0')
        *p++ = *ps2++;
    *p = '\0';
    return sv;
}

char * concat2d(char * ps1, char * ps2)
{
    char * s3;
    s3 = concat1d(ps1, ps2);
    return s3;
}

void inverse(char ** s)
{
    char * p1, *p2, *sv;
    sv = (char*)malloc((strlen(*s) + 1) * sizeof(char));
    for( p1 = *s, p2 = sv + strlen(*s)-1; *p1 !='\0'; p1++, p2--)
    {
        *p2 = *p1;
    }
    *(sv + strlen(*s)) = '\0';
    free(*s);
    *s = sv;
}

char * saisied()
{
    char * tmp, *res, *p1, *p2;
    char c;
    tmp = (char*)malloc(1000*sizeof(char));
    p1 =tmp;
    do
    {
        c = getchar();
        *p1++ = c;
    }
    while( c != '\n');
    *--p1 = '\0';
    res = (char*)malloc((strlen(tmp) + 1)*sizeof(char));
    p1 = tmp;
    p2 = res;
    while( (*p2++ = *p1++) !='\0');
}

int main()
{
    char s1[100] = "salut";
    char * s2, *s3;
    s2 = copied(s1);
    printf("%s",s2);
    s3 = concat1d(s1, s2);
    printf("%s", s3);
}



