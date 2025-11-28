#include "linked_list.h"

bool linked_list_add(node **me, DATA_TYPE data) {

    node *new_me = (node *)malloc(sizeof(node));

    if (new_me == NULL)
        return false;

    new_me->data = data;
    new_me->next = *me;

    *me = new_me;

    return true;

}

void linked_list_print(node **me) {

    if (me == NULL)
        return;

    node *current = *me;
    
    while(current != NULL) {

        printf("%d", current->data);

        if (current->next != NULL)
            printf(" -> ");

        current = current->next;

    }

    printf("\r\n");

}

bool linked_list_remove(node **me) {

    if (*me == NULL)
        return false;

    node *temp = *me;

    *me = temp->next;

    free(temp);

    return true;

}

node *linked_list_search(node *me, DATA_TYPE data) {

    if (me == NULL)
        return NULL;

    node *current = me;

    while (current != NULL) {

        if (current->data == data)
            return current;

        current = current->next;

    }

    return NULL;

}

bool linked_list_destroy(node **me) {

    if (*me == NULL)
        return false;

    node *current = *me;

    while (current != NULL) {

        node *next_node = current->next;
        free(current);
        current = next_node;

    }

    *me = NULL;

    return true;

}