#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

Dlist new_dlist(void)
{
    return NULL;
}

/*-------------------------------------------------*/

Bool is_empty_dlist(Dlist li)
{
    if(li == NULL) 
        return true;
    return false;
}

/*-------------------------------------------------*/

int dlist_length(Dlist li)
{
    if(is_empty_dlist(li))
        return 0;
    return li->length;
}

/*-------------------------------------------------*/