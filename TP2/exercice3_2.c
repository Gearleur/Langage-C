#include <stdio.h>
#include <math.h>

/* Fonction qui saisi un tableau d'entiers */
/* Paramètre d'entrée : int iTab[]: tableau d'entier initialiser */
/*                      int iNb: Nombre d'éléments du tableau */
/* Paramètres de sortie : rien */


void saisir(int iTab[], int iNb)
{ /* declaration d'un compteur d'elements du tableau */
    int iElement;

    /* pour tous les elments du tableau */
    for( iElement = 0; iElement < iNb; iElement++)
    {   /* affichage d'un message de saisi pour l'utilisatuer */
        printf("iTab[%d]=", iElement);
        /* saisi de l'utilisateur */
        sacnf("%d", &iTab[iElement]);
    }
}

/* Fonction qui affiche un tableau d'entiers */
/* parametre d'entrée : int iTab[] : tableau d'entiers à afficher */
/*                      int iNb : Nombre d'éléménts du tableau */
/* Parametres de sortie : rien */
void afficher( int iTab[],int iNb)
{   /*declaration d'un compteur d'éléménts du tableau */
    int iElement;

    /* pour tous les éléments du tableau */
    for (iElement = 0; iElement < iNb; iElement++)
    {   /*Affichage de l'élément */
        printf("%d", iTab[iElement]);

    }
}

/* Fonction qui trie un tableau d'entiers */
/* Parametres d'entrée : int iTab[]: tableau d'entiers à afficher */
/*                       int iNb : Nombre d'éléments du tableau */
/* Paramètres de sortie : rien */
void trier (int iTab[],int iNb)
{   /* Déclaration de deux compteurs :
    /* iComppteur1 compte les éléments du tableau du 0ème au iNbème -1 */
    /* iCompteur comppte les éléments du tableau de iCompteur+1 à iNb */
    int iCompteur1, iCompteur2;

    /* Déclaration de la valeur d'un élément du tableau */
    int iVal;

    

}