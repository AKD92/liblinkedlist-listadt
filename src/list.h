


#ifndef LIST_H_AKD
#define LIST_H_AKD

#include <stdlib.h>

/*******************************************************************************
*																			   *
* ----------------- DEFINE STRUCTURES FOR SINGLY LINKED LIST ----------------- *
*																			   *
*******************************************************************************/

struct ListElem_ {

	void *data;
	struct ListElem_ *next;

};

typedef struct ListElem_ ListElem;

struct List_ {

	unsigned int size;

	void (*destroy) (void *data);

	ListElem *head;
	ListElem *tail;

};

typedef struct List_ List;


/*******************************************************************************
*																			   *
* ----------------------------- PUBLIC INTERFACE ----------------------------- *
*																			   *
*******************************************************************************/

void list_init(List *list, void (*destroy) (void *data));

void list_destroy(List *list);

int list_ins_next(List *list, ListElem *elem, const void *data);

int list_rem_next(List *list, ListElem *elem, void **data);

void list_copy(List *dest, List *src);


/*	Check if *data conatins in the specifed list
	Returns 1 if contains, 0 if does not
*/

int list_contains(List *list, void *data,
                  int (*cmp) (const void *data1, const void *data2));

#define list_size(list) ((list)->size)

#define list_next(elem) ((elem)->next)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, elem) ((elem) == (list)->head ? 1 : 0)

#define list_is_tail(list, elem) ((elem) == (list)->tail ? 1 : 0)

#define list_data(elem) ((elem)->data)


#endif
