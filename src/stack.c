

/************************************************************************************
    Implementation of Stack Data Structure (Base is Linked List)
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/







#include <stdlib.h>
#include "stack.h"







int stack_push(Stack *st, const void *data) {
    
    return list_ins_next((List *) st, NULL, data);
}




int stack_pop(Stack *st, void **data) {
    
    return list_rem_next((List *) st, NULL, data);
}



