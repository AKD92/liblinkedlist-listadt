

/************************************************************************************
    Implementation of Singly Linked List
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/






#include <stdlib.h>
#include <string.h>
#include "list.h"








int list_init(List *list, void (*destroy) (void *data)) {
    
    if (list == NULL)
        return -1;
        
    /*  Initialize the specified list */
    memset((void *) list, 0, sizeof(List));
    
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    
    return 0;
}





void list_destroy(List *list) {

    void *data;
    int rem_result;
    
    
    /*  Check for invalid arguments */
    if (list == NULL)
        return;
    
    
    /*  Remove elements from the head of the List
        until no element is left, and 'destroy' each removed
        element if the 'destroy' function is provided to dispose
        user-specified elements.
    */
    while(list_size(list) > 0) {
        rem_result = list_rem_next(list, NULL, &data);
        
        /*  ret-val = 0 means, an object was removed successfully */
        if (rem_result == 0 && list->destroy != NULL) {
            list->destroy((void *) data);
        }
    }
    
    return;
}




int list_ins_next(List *list, ListElem *elem, const void *data) {

    ListElem *new_elem;
    
    
    /*  Check for invalid arguments */
    if (list == NULL)
        return -1;
    
    
    /*  Create new node element to hold the element */
    new_elem = (ListElem*) malloc(sizeof(ListElem));
    if (new_elem == 0)
        return -1;
    
    
    /*  Associate the user-specified element with this node element */
    new_elem->data = (void*) data;
    
    
    /*  We insert this new node into the head of the List */
    if (elem == NULL) {
        if (list_size(list) == 0)
            list->tail = new_elem;
        
        new_elem->next = list->head;
        list->head = new_elem;
        
    }
    
    /*  Insert this new node after the node specified as elem */
    else {
        if (list_is_tail(list, elem) == 1)
            list->tail = new_elem;

        new_elem->next = elem->next;
        elem->next = new_elem;

    }
    
    list_size(list) += 1;
    return 0;
}




int list_rem_next(List *list, ListElem *elem, void **data) {

    ListElem *old_elem;
    
    
    /*  Check for invalid arguments */
    if (list == NULL || data == NULL)
        return -1;
    if (list_size(list) == 0)
        return -1;
    
    
    /*  Remove the first node (head) of the List */
    if (elem == NULL) {
        old_elem = list_head(list);
        *data = old_elem->data;
        list->head = old_elem->next;
        if (list_is_tail(list, old_elem) == 1)
            list->tail = NULL;
    }
    
    /*  Remove the node which is the next node of the specified elem */
    else {
        if (list_next(elem) == NULL)
            return -1;

        old_elem = list_next(elem);
        *data = list_data(old_elem);
        elem->next = old_elem->next;
        if (list_is_tail(list, old_elem) == 1)
            list->tail = elem;

    }
    
    list_size(list) -= 1;
    free((void *) old_elem);
    return 0;
}




int list_search
(
    List *list,
    void *data,
    int (*fpCompare) (const void *data1, const void *data2)
) {

    int cmpres;
    int res;
    register ListElem *n;

    res = 0;
    n = list_head(list);

    if (data == NULL)
        return -1;
    
    while (n != NULL) {

        cmpres = fpCompare(data, n->data);
        if (cmpres == 0) {
            res = 1;
            break;
        }
        n = list_next(n);
    }
    return res;
}
