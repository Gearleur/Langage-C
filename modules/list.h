#ifndef __LIST__H
#define __LIST__H

/* def type booleen */
typedef enum Bool
{
    false,
    true
}Bool;

/* Definition d'une liste */
typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *List;

/* Prototypes */
List new_list(void);
Bool is_empty_list(List li);
int list_length(List li);
void print_list(List li);
List push_back_list(List li, int x);
List push_front_list(List li, int x);
List add_normal_list(List li, int p, int x);
List pop_back_list(List li);
List pop_front_list(List li);
List pop_normal_list(List li, int p);
List clear_list(List li);
int recherche_list(List li, int x);

#endif