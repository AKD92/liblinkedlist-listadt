

/************************************************************************************
	Program Interface (Function Prototypes) of Doubly Linked List
	Author:             Ashis Kumar Das
	Email:              akd.bracu@gmail.com
*************************************************************************************/






#ifndef DLIST_H_AKD
#define DLIST_H_AKD






#include <stdlib.h>









/*******************************************************************************
*																			   *
* ----------------- DEFINE STRUCTURES FOR DOUBLY LINKED LIST ----------------- *
*																			   *
*******************************************************************************/





struct DListElem_ {

	void *data;
	struct DListElem_ *next;
	struct DListElem_ *prev;
};

typedef struct DListElem_ DListElem;


struct DList_ {

	unsigned int size;

	int (*match) (const void *data1, const void *data2);		/* For use on other derived data structures */
	void (*destroy) (void *data);								/* Called when a DList object is destroyed */

	DListElem *head;
	DListElem *tail;
};

typedef struct DList_ DList;








/*******************************************************************************
*																			   *
* -------------------------------PUBLIC INTERFACE----------------------------- *
*																			   *
*******************************************************************************/





void dlist_init(DList *list, void (*destroy)(void *data));

void dlist_destroy(DList *list);

int dlist_ins_next(DList *list, DListElem *elem, const void *data);

int dlist_ins_prev(DList *list, DListElem *elem, const void *data);

int dlist_remove(DList *list, DListElem *elem, void **data);





#define dlist_size(list) ((list)->size)

#define dlist_head(list) ((list)->head)

#define dlist_tail(list) ((list)->tail)

#define dlist_is_head(elem) ((elem)->prev == NULL? 1 : 0)

#define dlist_is_tail(elem) ((elem)->next == NULL? 1 : 0)

#define dlist_data(elem) ((elem)->data)

#define dlist_next(elem) ((elem)->next)

#define dlist_prev(elem) ((elem)->prev)

#endif
