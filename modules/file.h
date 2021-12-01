#ifndef __FILE__H
#define __FILE__H


/* def type booleen */
typedef enum 
{
    false,
    true
}Bool;

/* defiintion file */
typedef struct QueueElement
{
    int value; 
    struct QueueElement *next;
}QueueElement, *Queue;

/* parametre file */
static QueueElement *first = NULL;
static QueueElement *last = NULL;
static int nb_elements = 0;

/* Prototypes */
Bool is_empty_queue(void);
int queue_length(void);
int queue_first(void);
int queue_last(void);
void print_queue(void);
void push_queue(int x);
void pop_queue(void);
void clear_queue(void);

#endif