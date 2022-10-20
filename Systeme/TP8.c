/*
Le but du tp est de trouver une approximation de pi
a l'aide de la méthode de Monte-Carlo
 
le but est de générer un pipeline en deux processus fils:
F1 qui sera en out pour envoyer N couples de nombres aléatoires
F2 qui sera en in pour recevoir les couples de nombres aléatoires et
    Déterminera s'ils sont dans le cercle de rayon 1
    (x**2 + y**2 <=1).
    De plus il fera une approximation de pi = 4*M/N
 
Notre main contiendra:
    un tableau de deux cases (pour la création du pipeline)
    une variable pid_t pour la création des fils (fork())
    il attendra que les fils finisse pour se finir
 
Un point important est la vérification d ela bonne exécution des differentes
fonctions utilisées (pipe, fork)
 
Enfin la chose élégante à ne pas oublier est la fermeture des différents
côtés de notre pipeline par les fils.


*/


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void F1(int n, int* tube)
{
    //initialisation des variables
    double x, y;

    //boucle de génération des couple de nombres aléatoires
    for(int i = 0; i < n; i++)
    {
        //génération de x
        x = (double)rand() / (double)RAND_MAX;

        // ecrit dans le tube (out) x
        write(tube[1], &x, sizeof(x));
        //génération de y
        y = (double)rand() / (double)RAND_MAX;
        // ecrit dans le tube (out) y
        write(tube[1], &y, sizeof(y));
    }

    //fin du processus fils et envoie signal SIGCHLD au père
    exit(0);
}

void F2(int n, int* tube)
{
    //initialisation de nos variable;
    double x, y;
    int M = 0;

    //on boucle sur nos n valeurs, et on regarde si les point sont dans le cercle
    //si oui, on incrémente M
    for(int i = 0; i < n; i++)
    {
        //Récupère la valeur dans le tube
        read(tube[0], &x, sizeof(x));
        read(tube[0], &y, sizeof(y));

        //si le point est dans le cercle, on incrémente M (relation de pythagore)
        if(x*x + y*y <= 1)
            M++;
    }

    //fermeture des cotés de notre pipeline qui n'est plus utilisé (in)
    close(tube[0]);

    //affichage de l'ensemble des variables M et pi
    printf("\n");
    printf("M = %d\n", M);
    printf("pi = %f\n", 4.*M/n);

    //fin du processus fils et envoie signal SIGCHLD au père
    exit(0);
}


int main()
{
    //création de nos variables
    //n le nombre de points à générer
    // tube représente notre pipeline
    // pid pour recevoir les fork et les tester
    int n = 100000;
    int * tube = (int *) malloc(2 * sizeof(int));
    pid_t pid;

    //je ne sais pas si c'est une primitive?
    // création du pipeline + test de la reussite
    if (pipe(tube) == -1)
    {
        perror("pipe à échoué");
        exit(1);
    }

    // création du fils qui executera F1 les valeurs random
    pid = fork();
    //test du fork
    if (pid == -1)
    {
        perror("fork à échoué");
        exit(2);
    }
    // fils
    else if (pid == 0)
    {
        //fermeture du coté in car F1 n'en a pas l'utilité
        close(tube[0]);
        //création de la fonction F1
        F1(n, tube);
        //fermeture des cotés de notre pipeline qui n'est plus utilisé (out)
        close(tube[1]);
    }

    // création du fils qui executera F2 les valeurs random
    pid = fork();
    //test du fork
    if (pid == -1) {
        perror("fork à échoué");
        exit(2);
    }
    else if (pid == 0)
    {
        //fermeture du coté out car F2 n'en a pas l'utilité
        close(tube[1]);
        //création de la fonction F2
        F2(n, tube);
    }

    //attente de la fin des deux fils + verification du wait
    if (wait(NULL) == -1)
    {
        perror("wait à échoué");
        exit(3);
    }
}



