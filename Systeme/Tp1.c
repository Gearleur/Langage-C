#include <stdio.h>
#include <stdlib.h>

int exo2()
{
 double pi = 3.14;
 printf("La valeur de pi est %lf\n");
 exit(0);
}


int exo3()
{
double valeur; // déclaration d’un réel double précision
double *pv; // déclaration d'un pointeur sur réel double préc.
valeur = 37.2;
pv = &valeur;
printf("valeur = %f\n", valeur);
printf("*pv = %f\n", *pv);
printf("&valeur = %p\n", &valeur);
printf("pv = %p\n", pv);
exit(0);
}

int exo4()
{
double valeur = 65.21;
double *pv;
int val = 7, *ptr; // ptr est un pointeur sur entier
pv = &valeur;
ptr = &val;
printf("taille valeur : %d octets\n", sizeof(valeur));
printf("taille pv : %d octets\n", sizeof(pv));
printf("taille val : %d octets\n", sizeof(val));
printf("taille ptr : %d octets\n", sizeof(ptr));
exit(0);
}

// exo 5
int exo5()
{
    int nb;
    float prix;
    printf("prix baguette\n");
    scanf("%f", &prix);
    printf("nombre baguette\n");
    scanf("%d", &nb);
    printf("coutent %f\n", nb*prix);
    return nb*prix;
}
//exo6
void Incremente(int *val) // val : paramètre formel
{
 *val = *val + 1;
}
int main()
{
 int x = 148;
 Incremente(&x); // x : paramètre réel

 printf("x vaut %d\n", x); // x devrait valoir 149
 exit(0);
}

// exo 7
int schtroumpf(int *t1, int ta1, int* t2, int ta2)
{
    int res = 0;
    for( int i = 0; i < ta1; i++ )
        for(int j = 0; j < ta2; j++ )
            res = res + t1[i] + t2[j];
    return res;
}


// reponse //

/*exo 2
wall dit pas que pi pas déclarer soit erreur
pas prevenue*/

/* exo 3
valeur 37.2
&valeur 0x9aa56f79
pv 0x9aa56f79
*pv 37.2

*pv = 38.2
pv contient l'adresse de valeur
*/

/* exo4
valeur 8
pv 8
val 4
ptr 8

sous linux int en 4 octets double 8 octets
sous windows aussi
adresse en 8 octets
*/

/* exo6
il faut passer par adresse sinon local donc pb */



