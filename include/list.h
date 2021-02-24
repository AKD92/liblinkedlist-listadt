

/************************************************************************************
    Program Interface (Function Prototypes) of Singly Linked List
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/






#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED




#include <stdlib.h>





/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************      DATA STRUCTURES      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/



struct ListElem_ {

    void *data;
    struct ListElem_ *next;

};
typedef struct ListElem_ ListElem;




struct List_ {

    unsigned int size;
    void (*destroy) (void *data);                     /* Called when a List object is destroyed */

    ListElem *head;
    ListElem *tail;

};
typedef struct List_ List;





/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************     PUBLIC INTERFACE      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/



/*
 *  Returns the number of data elements the linked list is currently holding.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *
 *  Returns:
 *      (unsigned int)  Number of elements the specified list is holding.
*/
#define list_size(list) ((list)->size)





/*
 *  Returns a pointer to a ListElem object which is next to
 *  the specific ListElem object.
 *
 *  Parameter:
 *      elem        :   Pointer to a ListElem object
 *
 *  Returns:
 *      (ListElem *)    Pointer to the next ListElem object
*/
#define list_next(elem) ((elem)->next)





/*
 *  Returns a pointer to a ListElem object which is the head
 *  of the specified linked list.
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *
 *  Returns:
 *      (ListElem *)    Pointer to the ListElem object which is the head
*/
#define list_head(list) ((list)->head)





/*
 *  Returns a pointer to a ListElem object which is the tail (last)
 *  of the specified linked list.
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *
 *  Returns:
 *      (ListElem *)    Pointer to the ListElem object which is the tail
*/
#define list_tail(list) ((list)->tail)





/*
 *  Checks if the specified ListElem object is the head of the
 *  specified linked list object or not.
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *      elem        :   Pointer to a ListElem object
 *
 *  Returns:
 *      1 if elem is the head of list
 *      0 if it does not
*/
#define list_is_head(list, elem) ((elem) == (list)->head ? 1 : 0)





/*
 *  Checks if the specified ListElem object is the tail of the
 *  specified linked list object or not.
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *      elem        :   Pointer to a ListElem object
 *
 *  Returns:
 *      1 if elem is the tail of list
 *      0 if it does not
*/
#define list_is_tail(list, elem) ((elem) == (list)->tail ? 1 : 0)





/*
 *  Returns a pointer to the data element of the specified ListElem object.
 *
 *  Parameter:
 *      elem        :   Pointer to a ListElem object
 *
 *  Returns:
 *      (void *)        Pointer to the data element
*/
#define list_data(elem) ((elem)->data)





/*
 *  Initializes a singly linked list with an optional destruction
 *  function for the data elements.
 *  This destruction function will only be called when list_destroy
 *  will be executed.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list which is being initialized
 *      destroy     :   Pointer to a destruction function for data elements
 *                      (can be NULL)
 *
 *  Returns:
 *      0 for successful
*/
int list_init(List *list, void (*destroy) (void *data));





/*
 *  Destroyes a previously initialized singly linked list.
 *  If the list is NULL, this function does nothing.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list which is being destroyed
 *
 *  Returns:
 *      (void)
*/
void list_destroy(List *list);





/*
 *  Inserts a data element into the linked list.
 *  The data element will be inserted right after the ListElem
 *  element provided.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      elem        :   Pointer to a ListElem object after which the specified data
 *                      pointer will be inserted
 *                      If elem is 0 (NULL), the data pointer will be inserted
 *                      on the head (top) of the linked list and the element which
 *                      was the head of the linked list will be the 2nd element
 *      data        :   Pointer to a data element which will be inserted into the list
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int list_ins_next(List *list, ListElem *elem, const void *data);





/*
 *  Removes a data element from the linked list which is next to
 *  the specified ListElem.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      elem        :   Pointer to a ListElem object which is the previous ListElem object
 *                      If elem is 0 (NULL), the head (top) of the linked list will be
 *                      removed and the rest of the ListElem objects will be adjusted properly
 *      data        :   Pointer to a pointer which will receive the pointer to the
 *                      data element of the removed ListElem object
 *                      (can not be NULL)
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int list_rem_next(List *list, ListElem *elem, void **data);





/*
 *  Check if an element exists into the linked list or not.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      data        :   Pointer to a data element which is being searched
 *      fpCompare   :   Pointer to a comparison function by which the data elements
 *                      will be compared with each other
 *
 *  Returns:
 *      1 if data exists on the linked list, compared with cmp
 *      0 if data does not exist
 *      -1 if data is NULL
*/
int list_search
(
    List *list,
    void *data,
    int (*fpCompare) (const void *data1, const void *data2)
);





#endif


