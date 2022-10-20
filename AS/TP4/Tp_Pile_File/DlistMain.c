#include <stdio.h>
#include "..\modules\dlist.h"

int main(void)
{
    Dlist mylist = new_dlist();

    if(is_empty_dlist(mylist))
        printf("Elle est vide\n");
    else
        printf("Elle contient quelque chose\n");
    
    printf("Taille de la Dlist : %d\n", dlist_length(mylist));

    return 0;
}

