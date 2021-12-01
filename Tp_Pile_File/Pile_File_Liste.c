#include <stdio.h>
#include <stdlib.h>
#include "..\modules\list.h"

int main(void)
{

/*----------------------------------------------------------------*/

    List mylist = new_list();
    print_list(mylist);

    mylist = push_front_list(mylist, 87);
    mylist = push_front_list(mylist, 8);
    mylist = push_front_list(mylist, 12);
    mylist = push_back_list(mylist, 3);
    mylist = push_back_list(mylist, 98);
    mylist = push_back_list(mylist, 22);
    mylist = push_back_list(mylist, 7);
    print_list(mylist);

    mylist = pop_front_list(mylist);
    print_list(mylist);

    mylist = add_normal_list(mylist, 1, 5);
    print_list(mylist);

    mylist = pop_normal_list(mylist, 3);
    print_list(mylist);

    int i = recherche_list(mylist, 300);
    printf("%d\n", i);
    
    mylist = clear_list(mylist);
    print_list(mylist);

/*----------------------------------------------------------------*/

    return 0;
}

