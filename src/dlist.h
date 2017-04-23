

/************************************************************************************
    Program Interface (Function Prototypes) of Doubly Linked List
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/






#ifndef DLIST_H_AKD
#define DLIST_H_AKD






#include <stdlib.h>





/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************      DATA STRUCTURES      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/



struct DListElem_ {

    void *data;
    struct DListElem_ *next;
    struct DListElem_ *prev;
};
typedef struct DListElem_ DListElem;




struct DList_ {

    unsigned int size;

    int (*match) (const void *data1, const void *data2);        /* For use on other derived data structures */
    void (*destroy) (void *data);                               /* Called when a DList object is destroyed */

    DListElem *head;
    DListElem *tail;
};
typedef struct DList_ DList;





/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************     PUBLIC INTERFACE      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/


/*
 *  Initializes a doubly linked list with an optional
 *  destruction function for the data elements
 *  This destruction function will only be called when dlist_destroy
 *  will be executed, if present.
 *
 *  Parameter:
 *      list        :   Pointer to a doubly linked list which is being initialized
 *      destroy     :   Pointer to a destruction function for data elements
 *
 *  Returns:
 *      0 for successful
*/
int dlist_init(DList *list, void (*destroy)(void *data));





/*
 *  Destroyes a previously initialized doubly linked list
 *
 *  Parameter:
 *      list        :   Pointer to a doubly linked list which is being destroyed
 *
 *  Returns:
 *      
*/
void dlist_destroy(DList *list);





/*
 *  Inserts a pointer to any data element into the linked list
 *  after the specified DListElem object
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      elem        :   Pointer to a DListElem object after which the specified data
 *                      pointer will be inserted
 *                      elem cannot be 0 (NULL) if the size of the list is not 0
 *      data        :   Pointer to a data element which will be inserted into the list
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int dlist_ins_next(DList *list, DListElem *elem, const void *data);





/*
 *  Inserts a pointer to any data element into the linked list
 *  before the specified DListElem object
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      elem        :   Pointer to a DListElem object before which the specified data
 *                      pointer will be inserted
 *                      elem cannot be 0 (NULL) if the size of the list is not 0
 *      data        :   Pointer to a data element which will be inserted into the list
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int dlist_ins_prev(DList *list, DListElem *elem, const void *data);





/*
 *  Removes the specified DListElem object from the linked list
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      elem        :   Pointer to a DListElem object which is being removed
 *                      elem cannot be 0 (NULL) if the size of the list is not 0
 *      data        :   Pointer to a pointer which will receive the pointer to
 *                      the data elementof the removed DListElem object
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int dlist_remove(DList *list, DListElem *elem, void **data);





/*
 *  Returns the number of data elements the linked list is currently holding
 *
 *  Parameter:
 *      list        :   Pointer to a doubly linked list
 *
 *  Returns:
 *      an unsigned interger carrying the number of elements on the list
*/
#define dlist_size(list) ((list)->size)





/*
 *  Returns a pointer to a DListElem object which is the head
 *  of the specified linked list
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *
 *  Returns:
 *      list->head, a pointer to the DListElem object which is the head
*/
#define dlist_head(list) ((list)->head)





/*
 *  Returns a pointer to a DListElem object which is the tail (last)
 *  of the specified linked list
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *
 *  Returns:
 *      list->tail, a pointer to the DListElem object which is the tail
*/
#define dlist_tail(list) ((list)->tail)





/*
 *  Checks if the specified DListElem object is the head of the
 *  specified linked list object or not
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *      elem        :   Pointer to a DListElem object
 *
 *  Returns:
 *      1 if elem is the head of list
 *      0 if it does not
*/
#define dlist_is_head(elem) ((elem)->prev == NULL? 1 : 0)





/*
 *  Checks if the specified DListElem object is the tail (last)
 *  of the specified linked list object or not
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *      elem        :   Pointer to a DListElem object
 *
 *  Returns:
 *      1 if elem is the tail of list
 *      0 if it does not
*/
#define dlist_is_tail(elem) ((elem)->next == NULL? 1 : 0)





/*
 *  Returns a pointer to the data element of the specified DListElem object
 *
 *  Parameter:
 *      elem        :   Pointer to a DListElem object
 *
 *  Returns:
 *      elem->data, a pointer to the data element
*/
#define dlist_data(elem) ((elem)->data)





/*
 *  Returns a pointer to a DListElem object which is next to
 *  the specific DListElem object
 *
 *  Parameter:
 *      elem        :   Pointer to a DListElem object
 *
 *  Returns:
 *      elem->next, a pointer to the next DListElem object
*/
#define dlist_next(elem) ((elem)->next)





/*
 *  Returns a pointer to a DListElem object which is previous to
 *  the specific DListElem object
 *
 *  Parameter:
 *      elem        :   Pointer to a DListElem object
 *
 *  Returns:
 *      elem->next, a pointer to the previous DListElem object
*/
#define dlist_prev(elem) ((elem)->prev)







#endif


