#include <stdio.h>
#include <stdlib.h>

/* On recupere N note et on les place dans un tableau*/

int* recupere_note(int N)
{
    int i;
    int *POINT = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        printf("Entrez la note %d: ", i + 1);
        scanf("%d", &POINT[i]);
    }
    return POINT;
}

/* On recupere un fichier txt avec des notes et on les mets dans un tableau*/


/* trouver la note maximale du tableau*/

int maxn(int *tab, int N)
{
    int i;
    int max = tab[0];
    for (i = 0; i < N; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
    return max;
}

int* max2(int *tab, int N )
{
    int i;
    int *max;
    max = (int*)calloc(2, sizeof(int));
    max[0] = tab[0];
    max[1] = 0;
    for(i = 0; i < N; i++)
    {
        if (tab[i] > max[0])
        {
            max[0] = tab[i];
            max[1] = i;
        }
    }
    return max;
}

/* trouver la note minimum du tableau*/

int min(int *tab, int N)
{
    int i;
    int min = tab[0];
    for (i = 0; i < N; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
    }
    return min;
}

/* trouver la moyenne du tableau*/

float moyenne(int *tab, int N)
{
    int i;
    float moyenne = 0;
    for (i = 0; i < N; i++)
    {
        moyenne += tab[i];
    }
    moyenne = moyenne / N;
    return moyenne;
}

/*fonction renvoie nombre de zero et la position des zeros dans le tableau*/
int* zero(int *tab, int N)
{
    int i;
    int *zero;
    int tp=0;
    zero = (int*)calloc(1, sizeof(int));
    zero[0] = 0;
    for (i = 0; i < N; i++)
    {
        if (tab[i] == 0)
        {
            tp++;
            zero[0]++;
            zero = (int*)realloc(zero, tp * sizeof(int));
            zero[tp] = i;
        }
    }
    return zero;
}

/*Etablir un tableau NOTEs à 7 dimension à partir de Tableau POINT*/
/*NOTES[0] contient les notes de 0 à 9, NOTES[4] contient les notes de 40 à 49*/
int* notes(int *tab, int N)
{
    int i;
    int *NOTES = (int*)malloc(7 * sizeof(int));
    for (i = 0; i < N; i++)
    {
        if (tab[i] >= 0 && tab[i] <= 9)
        {
            NOTES[0] += 1;
        }
        else if (tab[i] >= 10 && tab[i] <= 19)
        {
            NOTES[1] += 1;
        }
        else if (tab[i] >= 20 && tab[i] <= 29)
        {
            NOTES[2] += 1;
        }
        else if (tab[i] >= 30 && tab[i] <= 39)
        {
            NOTES[3] += 1;
        }
        else if (tab[i] >= 40 && tab[i] <= 49)
        {
            NOTES[4] += 1;
        }
        else if (tab[i] >= 50 && tab[i] <= 59)
        {
            NOTES[5] += 1;
        }
        else if (tab[i] >= 60 && tab[i] <= 69)
        {
            NOTES[6] += 1;
        }
    }
    return NOTES;
}

/*Etablir un graphique en nuage de points representant le tableau NOTES*/
/* On utilise le symbole 'o'pour representer les point dans le graphique*/
/*afficher le domaines des notes en dessous du graphique*/
   
void graph_nuage(int *note)
{
    int* cp = (int*)calloc(7, sizeof(int));
    int *max;
    int tp[2];
    int l;
    for(int i = 0; i < 7; i++)
        cp[i] = note[i];
    int* zeros = zero(note, 7);
    int nbr = max2(cp, 7)[0];
    printf("%d", nbr);
    tp[0]=0;
    for(int i=0;i<nbr;i++)
    {
        l = 1;
        max = max2(cp, 7);
        while(max[0] < tp[0]-l)
        {
            printf("\n%d >", tp[0]-l);
            l++;
        }
        if (tp[0] == max[0])
        {
            for(int i = tp[1]; i < max[1]-1; i++)
                printf("             ");
            printf("     o     ");
        }
        else
        {
            printf("\n%d >", max[0]);
            for(int j = 0; j < (max[1]); j++)
            {
                printf("          ");
            }
            printf("     o");
        }
        cp[max[1]] = -1;
        tp[0] = max[0];
        tp[1] = max[1];
    }
    printf("\n   ");
    int k = 0;
    for (int i = 0; i < zeros[0]; i++)
    {
        for(int j = k; j < zeros[i+1]; j ++)
            printf("+---------");
        printf("+----o----");
        k = zeros[i+1]+1;
    }
    for(int i = zeros[zeros[0]]+1; i< 7; i++)
        printf("+---------");
    printf("+\n");
    printf("   0        10        20        30        40        50        59     60\n");
}

void main() 
{
    int note[7] = {1, 1, 2, 2, 3, 3, 3};
    graph_nuage(note);
}