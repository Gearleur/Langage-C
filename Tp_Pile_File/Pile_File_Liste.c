#include <stdio.h>
#include <stdlib.h>
#include "..\modules\list.h"

int main(void)
{

/*----------------------------------------------------------------*/

    List mylist = new_list();
    print_list(mylist);

    mylist = push_front_list(mylist, 6);
    mylist = push_front_list(mylist, 4);
    mylist = push_front_list(mylist, 9);
    mylist = push_back_list(mylist, 3);
    mylist = push_back_list(mylist, 11);
    mylist = push_back_list(mylist, 10);
    mylist = push_back_list(mylist, 7);
    print_list(mylist);

    mylist = pop_front_list(mylist);
    print_list(mylist);

    mylist = add_normal_list(mylist, 1, 5);
    print_list(mylist);

    mylist = push_back_list(mylist, 1);
    mylist = push_front_list(mylist, 2);
    print_list(mylist);

    mylist = add_normal_list(mylist, 2, 14);
    print_list(mylist);

    mylist = pop_normal_list(mylist, 3);
    print_list(mylist);


    int i = recherche_list(mylist, 14);
    printf("%d\n", i);

    mylist = trie_list(mylist);
    print_list(mylist);
    
    mylist = clear_list(mylist);
    print_list(mylist);

/*----------------------------------------------------------------*/

    return 0;
}

