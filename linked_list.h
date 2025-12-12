/**
 * @file LINKED_LIST_H
 * @brief Knihovna pro jednoduchou implementaci spojového seznamu.
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @def DATA_TYPE
 * @brief Definuje datový typ pro data ve spojovém seznamu.
*/
#define DATA_TYPE int

/**
 * @brief Struktura reprezentující prvek ve spojovém seznamu.
*/
typedef struct node {

    DATA_TYPE data;
    struct node *next;

} node;

/**
 * @brief Funkce pro přidání prvku do spojového seznamu.
 * Nový prvek se stane začátkem (hlavou).
 * 
 * @param me Ukazatel na ukazatel na začátek spojového seznamu.
 * @param data Data typu DATE_TYPE, která mají uložena.
 * @return true, pokud se povedlo vložit prvek do seznamu, jinak false.
*/
bool linked_list_add(node **me, DATA_TYPE data);

void linked_list_print(node **me);

bool linked_list_remove(node **me);

node *linked_list_search(node *me, DATA_TYPE data);

bool linked_list_destroy(node **me);

bool linked_list_is_empty(const node *me);

size_t linked_list_size(node *me);

#endif