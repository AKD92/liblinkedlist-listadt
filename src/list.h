

/************************************************************************************
    Program Interface (Function Prototypes) of Singly Linked List
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/






#ifndef LIST_H_AKD
#define LIST_H_AKD




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

    int (*match) (const void *data1, const void *data2);        /* For use on other derived data structures */
    void (*destroy) (void *data);                               /* Called when a DList object is destroyed */

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
 *  Initializes a singly linked list with an optional
 *  destruction function for the data elements
 *  This destruction function will only be called when list_destroy
 *  will be executed, if present.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list which is being initialized
 *      destroy     :   Pointer to a destruction function for data elements
 *
 *  Returns:
 *      0 for successful
*/
int list_init(List *list, void (*destroy) (void *data));





/*
 *  Destroyes a previously initialized singly linked list
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list which is being destroyed
 *
 *  Returns:
 *      
*/
void list_destroy(List *list);





/*
 *  Inserts a pointer to any data element into the linked list
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
 *  Removes a data element from the linked list which is next to the specified ListElem
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      elem        :   Pointer to a ListElem object which is the previous ListElem object
 *                      If elem is 0 (NULL), the head (top) of the linked list will be
 *                      removed and the rest of the ListElem objects will be adjusted properly
 *      data        :   Pointer to a pointer which will receive the pointer to the
 *                      data element of the removed ListElem object
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int list_rem_next(List *list, ListElem *elem, void **data);





/*
 *  Check if an element is already into the linked list or not.
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *      data        :   Pointer to a data element which is being searched
 *      cmp         :   Pointer to a comparison function by which the data elements
 *                      will be compared with each other
 *
 *  Returns:
 *      1 if data exists on the linked list, compared with cmp
 *      0 if data does not exist
 *      -1 if data is NULL
*/
int list_linearsearch(List *list, void *data,
                  int (*cmp) (const void *data1, const void *data2));

                  
                  
                  
                  
/*
 *  Returns the number of data elements the linked list is currently holding
 *
 *  Parameter:
 *      list        :   Pointer to a singly linked list
 *
 *  Returns:
 *      an unsigned interger carrying the number of elements on the list
*/
#define list_size(list) ((list)->size)





/*
 *  Returns a pointer to a ListElem object which is next to
 *  the specific ListElem object
 *
 *  Parameter:
 *      elem        :   Pointer to a ListElem object
 *
 *  Returns:
 *      elem->next, a pointer to the next ListElem object
*/
#define list_next(elem) ((elem)->next)





/*
 *  Returns a pointer to a ListElem object which is the head
 *  of the specified linked list
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *
 *  Returns:
 *      list->head, a pointer to the ListElem object which is the head
*/
#define list_head(list) ((list)->head)





/*
 *  Returns a pointer to a ListElem object which is the tail (last)
 *  of the specified linked list
 *
 *  Parameter:
 *      list        :   Pointer to a linked list object
 *
 *  Returns:
 *      list->tail, a pointer to the ListElem object which is the tail
*/
#define list_tail(list) ((list)->tail)





/*
 *  Checks if the specified ListElem object is the head of the
 *  specified linked list object or not
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
 *  specified linked list object or not
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
 *  Returns a pointer to the data element of the specified ListElem object
 *
 *  Parameter:
 *      elem        :   Pointer to a ListElem object
 *
 *  Returns:
 *      elem->data, a pointer to the data element
*/
#define list_data(elem) ((elem)->data)







#endif


