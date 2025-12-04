#include "../lib/unity.h"
#include "../linked_list.h"
#include <stdio.h>

node *test_head = NULL;

void setUp(void) {
    
    test_head = NULL;

    printf("SETUP: Hlava inicializovana na NULL.\r\n");

}

void tearDown(void) {
    
    linked_list_destroy(&test_head);

    printf("\r\nTEARDOWN: Pamet uvolnena.\r\n");

}

void test_empty_list_after_init(void) {

    TEST_ASSERT_NULL(test_head);

}

void test_function_is_empty(void) {

    TEST_ASSERT(linked_list_is_empty(test_head));

}

void test_function_add(void) {

    bool success = linked_list_add(&test_head, 5);

    TEST_ASSERT_TRUE_MESSAGE(success, "Vlozeni na zacatek selhalo.");

    TEST_ASSERT_NOT_NULL_MESSAGE(test_head, "Hlava seznamu by nemela byt NULL.");

    TEST_ASSERT_EQUAL_UINT8_MESSAGE(5, test_head->data, "Hodnota se neshoduje s vlozenymi daty.");

    TEST_ASSERT_NULL_MESSAGE(test_head->next, "Nasledujici nod by mel byt NULL.");

}

void test_function_capacity(void) {

    TEST_ASSERT_EQUAL_size_t_MESSAGE(0, linked_list_capacity(test_head), "Kapacita by mela byt 0. Seznam je prazdny.");

    linked_list_add(&test_head, 2);
    linked_list_add(&test_head, 2);
    linked_list_add(&test_head, 2);
    linked_list_add(&test_head, 2);
    linked_list_add(&test_head, 2);

    TEST_ASSERT_EQUAL_size_t_MESSAGE(5, linked_list_capacity(test_head), "Kapacita se lisi.");


}

void test_function_remove(void) {

    linked_list_add(&test_head, 2);

    linked_list_remove(&test_head);

    TEST_ASSERT_NULL_MESSAGE(test_head, "Hlava by mela byt NULL");

    linked_list_add(&test_head, 4);
    linked_list_add(&test_head, 9);

    linked_list_remove(&test_head);

    TEST_ASSERT_NOT_NULL_MESSAGE(test_head, "Hlava by nemela byt NULL");

    TEST_ASSERT_EQUAL_size_t_MESSAGE(1, linked_list_capacity(test_head), "Kapacita se lisi.");

    TEST_ASSERT_EQUAL_UINT8_MESSAGE(4, test_head->data, "Kapacita se lisi.");

}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_empty_list_after_init);
    RUN_TEST(test_function_is_empty);
    RUN_TEST(test_function_add);
    RUN_TEST(test_function_capacity);
    RUN_TEST(test_function_remove);
    return UNITY_END();
}
