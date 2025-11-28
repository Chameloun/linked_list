#include "linked_list.h"
#include <assert.h>

int main() {

    node *head = NULL;

    linked_list_add(&head, 10);
    linked_list_add(&head, 5);
    linked_list_add(&head, -1);
    linked_list_add(&head, 55);

    linked_list_print(&head);

    linked_list_remove(&head);

    linked_list_print(&head);

    assert(linked_list_search(head, 5)->data == 5);
    assert(linked_list_search(head, 60) == NULL);

    linked_list_destroy(&head);

    return 0;

}