#include <stdio.h>
#include "modules/Pile.h"

int main(void)
{

/*----------------------------------------------------------------*/

    Stack sta = new_stack();

    if (is_empty_stack(sta))
        printf("La pile est vide\n");
    else
        printf("La pile contient des elements\n");
    
    sta = push_stack(sta, 14);
    sta = push_stack(sta,47);

    print_stack(sta);

    sta = clear_stack(sta);

/*----------------------------------------------------------------*/



    return 0;
}

