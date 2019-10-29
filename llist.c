#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

// Funcs from the previous assignment

struct node * insert_front(struct node * n, int data)
{
    if (n == NULL)
    {
        n = malloc(sizeof(struct node));
        n->data = data;
        n->next = NULL;
        return n;
    }
    else
    {
        struct node * new_n = malloc(sizeof(struct node));
        new_n->data = data;
        new_n->next = n;
        return new_n;
    }
}


struct node * free_list(struct node * n)
{
    struct node * tmp;

    while(n)
    {
        tmp = n->next;
        free(n);
        n = tmp;
    }

    return n;
}

struct node * remove_node(struct node *front, int data)
{
    struct node * prev, * tmp;
    tmp = front;
    prev = NULL;
    while(tmp)
    {
        if (tmp->data == data)
        {
            // if data is at the front, then free first node and move front over
            if (prev == NULL)
            {
                front = tmp->next;
                free(tmp);
                tmp = front;
            }
            else
            {
                prev->next = tmp->next;
                free(tmp);
            }
        }
    }
    return front;
}