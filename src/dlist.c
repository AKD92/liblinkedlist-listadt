

/************************************************************************************
    Implementation of Doubly Linked List
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/






#include <stdlib.h>
#include <string.h>
#include "dlist.h"








int dlist_init(DList *list, void (*destroy)(void *data)) {
    
    if (list == NULL)
        return -1;
    
    memset((void *) list, 0, sizeof(DList));
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    
    return 0;
}




void dlist_destroy(DList *list) {
    
    void *data;
    int rem_result;
    
    if (list == NULL)
        return;
    
    while (dlist_size(list) > 0) {
        rem_result = dlist_remove(list, dlist_tail(list), &data);
        if (rem_result == 0 && list->destroy != NULL) {
            list->destroy((void *) data);
        }
    }
    return;
}




int dlist_ins_next(DList *list, DListElem *elem, const void *data) {

    DListElem *new_elem;
    
    if (list == NULL)
        return -1;
    if (elem == NULL && dlist_size(list) > 0)
        return -1;

    new_elem = (DListElem *) malloc(sizeof(DListElem));
    if (new_elem == 0)
        return -1;

    new_elem->data = (void*) data;

    if (dlist_size(list) == 0) {

        list->head = new_elem;
        new_elem->next = NULL;
        new_elem->prev = NULL;
        list->tail = new_elem;

    } else {

        new_elem->next = elem->next;
        new_elem->prev = elem;

        if (elem->next == NULL)
            list->tail = new_elem;
        else
            elem->next->prev = new_elem;

        elem->next = new_elem;
    }

    list->size++;
    return 0;
}




int dlist_ins_prev(DList *list, DListElem *elem, const void *data) {

    DListElem *new_elem;
    
    if (list == NULL)
        return -1;
    if (elem == NULL && dlist_size(list) > 0)
        return -1;

    new_elem = (DListElem *) malloc(sizeof(DListElem));
    if (new_elem == 0)
        return -1;

    new_elem->data = (void*) data;

    if (dlist_size(list) == 0) {

        list->head = new_elem;
        list->tail = new_elem;
        new_elem->next = NULL;
        new_elem->prev = NULL;

    } else {

        new_elem->next = elem;
        new_elem->prev = elem->prev;

        if (elem->prev == NULL)
            list->head = new_elem;
        else
            elem->prev->next = new_elem;

        elem->prev = new_elem;
    }

    list->size++;
    return 0;
}




int dlist_remove(DList *list, DListElem *elem, void **data) {

    if (list == NULL)
        return -1;
    if (elem == NULL || dlist_size(list) == 0)
        return -1;

    *data = elem->data;

    if (dlist_is_head(elem) == 1) {

        list->head = elem->next;

        if (list->head == NULL)
            list->tail = NULL;
        else
            elem->next->prev = NULL;
    } else {

        elem->prev->next = elem->next;

        if (elem->next == NULL)
            list->tail = elem->prev;
        else
            elem->next->prev = elem->prev;
    }

    free((void *) elem);
    list->size--;

    return 0;
}




int dlist_search
(
    DList *list,
    void *data,
    DListElem **elem,
    int (*comparator) (const void *data1, const void *data2)
) {
    int cmpres, res;
    register DListElem *n;
    
    res = 0;
    n = dlist_head(list);
    
    if (data == NULL)
        return -1;
    
    while (n != NULL) {
        cmpres = comparator(data, n->data);
        if (cmpres == 0) {
            *elem = n;
            res = 1;
            break;
        }
    }
    return res;
}

