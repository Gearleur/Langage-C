#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*Déclarer une structure Restaurant contenant les champs suivants : nom_restaurant,
adresse_restaurant, position_restaurant et sa spécialité*/

typedef struct
{
    char nom_restaurant[100];
    char adresse_restaurant[100];
    char position_restaurant[100];
    char specialite[100];
}Restaurant;

/*fonction qui copie restaurants*/
void copie_restaurant(Restaurant r1[], Restaurant r2[])
{
    for(int i = 0 ; i < 100 ; i++)
    {
        r2[i]= r1[i];
    }
}

/* trier restaurants en fonction de la distance x et y dans un rayon r*/
void trier_restaurant(double x, double y, Restaurant results[])
{
    Restaurant temp;
    for(int j=1;j<=100;j++)
    { 
        for(int i=0;i<100-1;i++)
        {
            char *pos = results[i].position_restaurant;
            char *po = strtok(pos, "=");
            char *pos1 = strtok(NULL, ",");
            char *po2 = strtok(NULL, "=");
            char *pos2 = strtok(NULL, ")");
            double x_restaurant = atof(pos1);
            double y_restaurant = atof(pos2);
            double distance = sqrt(pow(x_restaurant - x, 2) + pow(y_restaurant - y, 2));
            char *pos3 = results[i+1].position_restaurant;
            char *po3 = strtok(pos3, "=");
            char *pos4 = strtok(NULL, ",");
            char *po4 = strtok(NULL, "=");
            char *pos5 = strtok(NULL, ")");
            double x_restaurant2 = atof(pos4);
            double y_restaurant2 = atof(pos5);
            double distance2 = sqrt(pow(x_restaurant2 - x, 2) + pow(y_restaurant2 - y, 2));
            if (distance > distance2)
            {
                temp = results[i];
                results[i] = results[i+1];
                results[i+1] = temp;
            }
        }
    }
}

/*A travers la fonction int lire_restaurant (char* chemin, Restaurant restaurants []),
récupérer dans le tableau restaurants toutes les informations concernant chaque
restaurant inséré dans le fichier nommé chemin. Les infromations sont séparés par ";". La fonction lire_restaurant re-
tournera en fin de lecture le nombre de restaurants lu à partir du fichier.*/


int lire_restaurant(char* chemin, Restaurant restaurants[])
{
    FILE* fichier = NULL;
    fichier = fopen(chemin, "r");
    if (fichier != NULL)
    {
        int i = 0;
        while (fscanf(fichier, "%[^;];%[^;];%[^;];%[^\n]", restaurants[i].nom_restaurant, restaurants[i].adresse_restaurant, restaurants[i].position_restaurant, restaurants[i].specialite) != EOF)
        {
            i++;
        }
        fclose(fichier);
        return i-1;
    }
    else
    {
        printf("Erreur d'ouverture du fichier");
        return 0;
    }
}
    

/*implémenter la fonction inserer_restaurant(Restaurant restaurant) permettant d’insérer
un restaurant à la fin du fichier (restau.txt) */
void inserer_restaurant(Restaurant restaurant)
{
    FILE *f;
    f = fopen("restau.txt", "a");
    if (f == NULL)
    {
        printf("Erreur d'ouverture du fichier");
    }
    fprintf(f, "%[^;];%[^;];%[^;];%[^\n]", restaurant.nom_restaurant, restaurant.adresse_restaurant, restaurant.position_restaurant, restaurant.specialite);
    fclose(f);
}

/*Implémenter la fonction void cherche_restaurant(double x, double y, double rayon_recherche,
Restaurant results[]) qui prend en paramètre la position actuelle d’un utilisateur et
un rayon de recherche et qui remplit le tableau results par les restaurants présents
dans le rayon de recherche.*/
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[])
{
    Restaurant restaurants[100];
    int nb_restaurant = lire_restaurant("restau.txt", restaurants);
    Restaurant tp[100];
    copie_restaurant(restaurants, tp);
    int i = 0;
    int j = 0;
    for (i = 1; i < nb_restaurant; i++)
    {
        char *pos = restaurants[i].position_restaurant;
        char *po = strtok(pos, "=");
        char *pos1 = strtok(NULL, ",");
        char *po2 = strtok(NULL, "=");
        char *pos2 = strtok(NULL, ")");
        double x_restaurant = atof(pos1);
        double y_restaurant = atof(pos2);
        double distance = sqrt(pow(x_restaurant - x, 2) + pow(y_restaurant - y, 2));
        if (distance <= rayon_recherche)
        {
            results[j] = tp[i];
            j++;
        }
    }
}

/*Implémenter la fonction void afficher_restaurant(Restaurant restaurant) qui affiche les informations d’un restaurant*/

void afficher_restaurants(Restaurant restaurants[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("Nom du restaurant : %s", restaurants[i].nom_restaurant);
        printf("Adresse du restaurant : %s", restaurants[i].adresse_restaurant);
        printf("Position du restaurant : %s", restaurants[i].position_restaurant);
        printf("Spécialité du restaurant : %s", restaurants[i].specialite);
    }
}

/*Implémenter la fonction void cherche_par_specialite(double x, double y, char * spe-
cialite[], Restaurant results[]) qui prend en paramètre la position actuelle d’un util-
isateur et une liste de spécialité et qui remplit le tableau results par les restaurants
satisfaisants au moins une des spécialités passées en paramètre.*/
void cherche_par_specialite(double x, double y, char *specialite, Restaurant results[])
{
    Restaurant restaurants[100];
    int nb_restaurant = lire_restaurant("restau.txt", restaurants);
    Restaurant tp[100];
    copie_restaurant(restaurants, tp);
    int i = 0;
    int j = 0;
    for (i = 1; i < nb_restaurant; i++)
    {
        if (strcmp(restaurants[i].specialite,specialite) == 0)
        {
            results[j] = tp[i];
            j++;
        }
    }
    trier_restaurant(x, y, results);

}

/*Ecrire la fonction main() permettant de proposer un menu à l’utilisateur permettant
de faire appel aux différentes fonctions mentionnées ci-dessus.*/

int main()
{
    Restaurant restaurants[100];
    Restaurant results[100];
    int nb_restaurant = lire_restaurant("restau.txt", restaurants);
    Restaurant tp[100];
    copie_restaurant(restaurants, tp);
    int choix;
    printf("1- Inserer un restaurant\n");
    printf("2- Afficher les restaurants\n");
    printf("3- Afficher les restaurants dans un rayon\n");
    printf("4- Afficher les restaurants par specialite\n");
    printf("5- Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        Restaurant r;
        printf("Nom du restaurant : ");
        scanf("%s", r.nom_restaurant);
        printf("Adresse du restaurant : ");
        scanf("%s", r.adresse_restaurant);
        printf("Position du restaurant : ");
        scanf("%s", r.position_restaurant);
        printf("Spécialité du restaurant : ");
        scanf("%s", r.specialite);
        inserer_restaurant(r);
        break;
    case 2:
        afficher_restaurants(restaurants, nb_restaurant);
        break;
    case 3:
        double x, y;
        double rayon_recherche;
        printf("Entrer x : ");
        scanf("%lf", &x);
        printf("Entrer y : ");
        scanf("%lf", &y);
        printf("Entrer rayon : ");
        scanf("%lf", &r);
        cherche_restaurant(x, y, rayon_recherche, results);
        afficher_restaurants(results, 100);
        break;
    case 4:
        double x2, y2;
        char specialite[100];
        printf("Entrer x : ");
        scanf("%lf", &x2);
        printf("Entrer y : ");
        scanf("%lf", &y2);
        printf("Entrer specialite : ");
        scanf("%s", specialite);
        cherche_par_specialite(x2, y2, specialite, results);
        afficher_restaurants(results, 100);
        break;
    case 5:
        printf("Au revoir");
        break;
    default:
        printf("Erreur");
        break;
    }
    return 0;
}
