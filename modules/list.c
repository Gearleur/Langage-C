#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List new_list(void)
{
    return NULL;
}

/*------------------------------------------------------*/

Bool is_empty_list(List li)
{
    if(li == NULL)
        return true;
    
    return false;
}

/*------------------------------------------------------*/

int list_length(List li)
{
    int size = 0;

    if (!is_empty_list(li))
    while(li != NULL)
    {
        ++size;
        li = li->next;
    }

    return size;
}

/*------------------------------------------------------*/

void print_list(List li)
{
    List element = li;

    if(is_empty_list(element))
    {
        printf("Rien a afficher la list est vide\n");
        return;
    }

    while(element != NULL)
    {
        printf("[%d] ", element->value);
        element = element->next;
    }

    printf("\n");
}

/*------------------------------------------------------*/

List push_back_list(List li, int x)
{
    ListElement *element;

    element = malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur allocation");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = NULL;

    if(is_empty_list(li))
        return element;
    
    ListElement *temp;
    temp = li;

    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = element;

    return li; //ou temp
}

/*------------------------------------------------------*/

List push_front_list(List li, int x)
{
    List element;

    element = (List)malloc(sizeof(ListElement));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur allocation");
        exit(EXIT_FAILURE);
    }

    element->value = x;

    if(is_empty_list(li))
        element->next = NULL;
    else
        element->next = li;
    
    return element; 
}

/*------------------------------------------------------*/

List pop_back_list(List li)
{
    if(is_empty_list(li))
        return new_list();
    
    if(li->next == NULL)
    {
        free(li);
        li = NULL;

        return new_list();
    }

    ListElement *temp = li;
    ListElement *before = li;

    while(temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }

    before->next = NULL;
    free(temp);
    temp = NULL;

    return li;
}

/*------------------------------------------------------*/

List pop_front_list(List li)
{
    if(is_empty_list(li))
        return li;

    List element;

    element = (List)malloc(sizeof(ListElement));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur allocation");
        exit(EXIT_FAILURE);
    }

    element = li->next;

    free(li);
    li = NULL;

    return element;
}

/*------------------------------------------------------*/

List clear_list(List li)
{
    if(is_empty_list(li))
        return new_list();
    
    while(li != NULL)
        li = pop_front_list(li);
}

/*------------------------------------------------------*/

List add_normal_list(List li,int p, int x)
{
    if(is_empty_list(li))
        return li;

    if(abs(p) > list_length(li))
    {
        li =push_back_list(li, x);
        return li;
    }
    if(p<0)
    {
        p = list_length(li)+(p+2);
        printf("%d\n", p);
    }

    if(p==1 || p ==0)
    {
        li = push_front_list(li,x);
        return li;
    }

    List element;

    element = (List)malloc(sizeof(ListElement));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur allocation");
        exit(EXIT_FAILURE);
    }

    ListElement *temp = li;
    ListElement *before = li;

    for(int i = 0; i<p-1; i++)
    {
        before = temp;
        temp = temp->next;
    }

    element->value = x;
    element->next = temp;
    before->next = element;

    return li;
}

/*------------------------------------------------------*/

List pop_normal_list(List li, int p)
{
    if(is_empty_list(li))
        return li;
    
    if(abs(p) > list_length(li))
    {
        li =pop_back_list(li);
        return li;
    }
    if(p<0)
    {
        p = list_length(li)+(p+1);
    }

    if(p==1 || p ==0)
    {
        li = pop_front_list(li);
        return li;
    }


    ListElement *temp = li->next;
    ListElement *after= temp->next;
    ListElement *before = li;

    for(int i = 1; i<p-1; i++)
    {
        before = temp;
        temp = temp->next;
        after = temp->next;
    }

    before->next = after;
    free(temp);
    temp = NULL;

    return li;
}

/*------------------------------------------------------*/

int recherche_list(List li, int x)
{
    if(is_empty_list(li))
        return 0;
    
    ListElement *temp = li;
    int i = 1;

    while(temp->value != x)
    {
        if(temp->next == NULL)
        {
            printf("l'element n'existe pas dans la list\n");
            return 0;
        }
        temp = temp->next;
        i++;
    }

    return i;
}

/*------------------------------------------------------*/

List trie_list(List li)
{
    if(is_empty_list(li))
        return li;
    
    ListElement *after = li->next;
    ListElement *before = li;
    int temp = 0;
    
    Bool permut = true;


    while(permut==true) 
    {
        permut = false;
        for(before = li, after = li->next; before->next !=NULL; before = before->next)
        {
            if(before->value > after->value)
            {
                temp = before->value;
                before->value = after->value;
                after->value = temp;
                permut = true;
            }

            after = after->next;
        }
    }

    return li;
}

/*------------------------------------------------------*/
