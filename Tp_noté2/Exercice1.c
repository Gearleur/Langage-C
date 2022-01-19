#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* version 1 */

char* Saisie1()
{
    char *tmp, *def;
    tmp = (char*)malloc(100*sizeof(char)); //tmp[1000]
    int i = 0;
    do
    {
        tmp[i] = getchar();
        i++;
    } while ( tmp[i-1] != '\n');
    tmp[i-1] = '\0';
    def = (char*)malloc(i*sizeof(char));
    i = 0;
    strcpy(def,tmp); // while((def[i] = tmp[i++]) != '\0');sinon \0=0 donc false
    free(tmp);          // pas besoin de \0;
    return def;
}

char* Saisie2()
{
    char* anc, *nv, car;
    int i, j, nb;
    nb = 1;
    anc = NULL;
    do
    {
        car = getchar();
        nv = (char*)malloc(nb*sizeof(char));
        
        for(i = 0; i < nb-2; i++)
            nv[i] = anc[i];
        nv[i] = car;
        if(anc != NULL)
            free(anc);
        nb++;
        anc = nv;
    }while(car != '\n');
    nv[i] = '\0';
    return nv;
}

// hypothèse il n'y a pas de chaine composé uniquement du caractère a supprimer
// 

void supprimer(char** tab, char elt)
{
    int i;
    for(i = 0; tab[i] != NULL; i++) 
    {
        tab[i] = suppresion(tab[i], elt);
        //ou suppression(&tab[i], elt);


    }
}

char** surpprimens(char** tab, char car)
{
    int i, j, nbc, occ;
    char** res;
    occ = 0;
    j = 0;
    for(i = 0; tab[i] != NULL; i++)
    {
        if (tab[i][0] == car)
            occ++;
    }
    nbc = i - occ + 1;
    res = (char**) malloc(nbc * sizeof(char*));
    for (i = 0; tab[i] != NULL; i++)
    {
        if( tab[i][0] != car)
            res[j++] = tab[i];
        else
            free(tab[i]);
    }
    res[j] = NULL;
    free(tab);
    return res;
}

int main()
{
    char *tab;
    printf("Saisie chaine : \n");
    tab = Saisie1();
    printf("chaine : %s\n", tab);
}