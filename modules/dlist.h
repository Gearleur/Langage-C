#ifndef __DLIST__H
#define __DLIST__H

    /* Définition d'un Booléen */
    typedef enum 
    {
        false,
        true
    }Bool;

    /* défintion d'un maillon de la Dlist */
    typedef struct DelisNode
    {
        int value;
        struct DelisNode *back;
        struct DelisNode *next;
    }DlistNode;

    /* Définition d'une Dliste */
    typedef struct Dlist
    {
        int length;
        struct DelisNode *begin;
        struct DelisNode *end;
    }*Dlist;

    /* prototype */
    Dlist new_dlist(void);
    Bool is_empty_dlist(Dlist li);
    int dlist_length(Dlist li);


#endif