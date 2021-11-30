#ifndef __Pile__H__
#define __Pile__H__

    /* Typedef bolléen */
    typedef enum Bool
    {
        false, //0
        true //1
    }Bool;

    /* Definition d'une Pile */
    typedef struct StackElement 
    {
        int value;
        struct StackElement *next;
    }StackElement, *Stack;

    /* Prototypes des fonctions */
    Stack new_stack(void);
    Bool is_empty_stack(Stack st);
    void print_stack(Stack st);
    Stack push_stack(Stack st, int x);
    Stack pop_stack(Stack st);
    int top_stack(Stack st);
    int stack_length(Stack st);
    Stack clear_stack(Stack st);


#endif