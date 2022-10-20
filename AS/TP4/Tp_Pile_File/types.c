#include <stdio.h>

typedef enum Booleen
{
    false,//0
    true//1
} Booleen;

typedef enum Marquevoiture
{
    PEUGEOT = 5,
    RENAULT,//1
    TOYOTA,//2
    MAZDA,//3
} Marque;

typedef union Nombre
{
    int entier;
    float decimals;
};



int main(void)
{
    enum Booleen jeu_lance = false;

    Marque voiture1 = TOYOTA;

    return 0;
}