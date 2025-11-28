#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define DATA_TYPE int

typedef struct node {

    DATA_TYPE data;
    struct node *next;

} node;

bool linked_list_add(node **me, DATA_TYPE data);

void linked_list_print(node **me);

bool linked_list_remove(node **me);

node *linked_list_search(node *me, DATA_TYPE data);

#endif