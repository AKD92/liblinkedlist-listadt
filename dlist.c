
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

void dlist_init(DList *list, void (*destroy)(void *data)) {

	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;

	return;
}

void dlist_destroy(DList *list) {

	void *data;
	int removeOpResult;

	while (dlist_size(list) > 0) {
		
		removeOpResult = dlist_remove(list, dlist_tail(list), &data);

		if (removeOpResult == 0 && list->destroy != NULL) {
			list->destroy(data);
		}
	}

	memset(list, 0, sizeof(DList));

	return;

}

int dlist_ins_next(DList *list, DListElem *elem, const void *data) {

	DListElem *new_elem;

	if (elem == NULL && dlist_size(list) != 0)
		return -1;

	new_elem = (DListElem*) malloc(sizeof(DListElem));
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

	if (elem == NULL && dlist_size(list) != 0)
		return -1;

	if ((new_elem = (DListElem*) malloc(sizeof(DListElem))) == NULL)
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

	free(elem);

	list->size--;

	return 0;

}
