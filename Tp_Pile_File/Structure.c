/*les structurespermettent permet de stocker plusieur données
struct point 
{ declaration de la structure
    float x,y,z;
};

ou pour eviter d'appeller a chauqe fois struct:

typedef struct point
{ declaration de la structure
    float x,y,z;
}Point3D;

*/

#include <stdio.h>
#include <string.h>

typedef struct Player
{
    signed char username[256];
    int hp;
    int mp;
} Player;

void creat_Player(Player *p)
{
    strcpy(p->username,"Jules");
    p->hp = 1;
    (*p).mp = 1;
}

int main(void)
{
    Player p1 = {"", 0, 0};

    creat_Player(&p1);

    printf("Nom du joueur : %s\n", p1.username);
    printf("Pv : %d | PM : %d\n", p1.hp, p1.mp);

    return 0;
}