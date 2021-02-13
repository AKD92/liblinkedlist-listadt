

/************************************************************************************
    Implementation of Queue Data Structure (Base is Linked List)
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/







#include <stdlib.h>
#include "queue.h"







int queue_enqueue(Queue *queue, const void *data) {
    
    return list_ins_next((List *) queue, list_tail(queue), data);
}




int queue_dequeue(Queue *queue, void **data) {
    
    return list_rem_next((List *) queue, NULL, data);
}



