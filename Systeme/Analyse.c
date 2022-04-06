#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

float* Recup150valeur(char* chemin)
{
    int d;
    float* Tab = (float*) calloc(150,sizeof(float));

    //si erreur
    if((d = open(chemin, O_RDONLY)) == -1)
    {
        perror("erreur");
        return NULL;
    }
    
    read(d, Tab, 150*sizeof(float));        

    close(d);

    return Tab;
}

float* CaclMinMaxAvg(float *tab)
{
    float* TabF = (float*)calloc(9,sizeof(float));
    for(int j = 0; j<=2; j++)
    {
        float s = 0;
        float min = tab[50*j];
        float max = tab[50*j];
        for(int i = 0; i <=49; i++)
        {
            if(tab[50*j+i] < min)
                min = tab[50*j+i];
            if(tab[50*j+i] > max)
                max = tab[50*j+i];
            s += tab[50*j+i];
        }
        TabF[3*j] = s/50;
        TabF[1+3*j] = max;
        TabF[2+3*j] = min;  
    }
    return TabF;
}

void affiche(float* TabF, char* esp[])
{
    for(int i = 0; i<=8; i++)
    {
        if(i%3 == 0)
            printf("%s\n",esp[i/3]);
        printf("\t %f\n", TabF[i]);
    }
}

int main()
{
    float* tab = Recup150valeur("Systeme/iris.dat");
    float* TabF = CaclMinMaxAvg(tab);
    char* esp[3][9] = {"espace1", "espece2", "espece3"};
    affiche(TabF, esp);
}