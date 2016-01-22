
#include <stdlib.h>
#include "list.h"


void list_init(List *list, void (*destroy) (void *data)) {

	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;

	return;

}

void list_destroy(List *list) {

	int ret_val;
	void *data;

	while(list_size(list) > 0) {

		ret_val = list_rem_next(list, NULL, &data);

		if (ret_val == 0 && list->destroy != NULL)
			list->destroy(data);

	}

}

int list_ins_next(List *list, ListElem *elem, const void *data) {

	ListElem *new_elem;

	new_elem = (ListElem*) malloc(sizeof(ListElem));
	if (new_elem == 0)
		return -1;

	new_elem->data = (void*) data;

	if (elem == NULL) {

		if (list_size(list) == 0)
			list->tail = new_elem;

		new_elem->next = list->head;
		list->head = new_elem;

	} else {

		if (list_is_tail(list, elem) == 1)
			list->tail = new_elem;

		new_elem->next = elem->next;
		elem->next = new_elem;

	}

	list->size++;

	return 0;

}

int list_rem_next(List *list, ListElem *elem, void **data) {

	ListElem *old_elem;

	if (list_size(list) == 0)
		return -1;

	if (elem == NULL) {

		old_elem = list_head(list);
		*data = old_elem->data;

		list->head = old_elem->next;

		if (list_is_tail(list, old_elem) == 1)
			list->tail = NULL;

	} else {

		if (list_next(elem) == NULL)
			return -1;

		old_elem = list_next(elem);
		*data = list_data(old_elem);

		elem->next = old_elem->next;

		if (list_is_tail(list, old_elem) == 1)
			list->tail = elem;

	}

	list->size--;

	free(old_elem);

	return 0;

}

void list_copy(List *dest, List *src) {

	ListElem *elem_src;
	ListElem *elem_dest;

	elem_src = list_head(src);

	while (elem_src != NULL) {

		elem_dest = list_tail(dest);
		list_ins_next(dest, elem_dest, list_data(elem_src));
		elem_src = list_next(elem_src);
	}
	return;
}

int list_contains(List *list, void *data,
                  int (*cmp) (const void *data1, const void *data2)) {

	int cmpres;
	int res;

	ListElem *n;
	res = 0;

	n = list_head(list);

	if (data == NULL) return 0;

	while (n != NULL) {

		cmpres = cmp(data, n->data);
		if (cmpres == 0) {
			res = 1;
			break;
		}
		n = list_next(n);
	}

	return res;

}
