

/************************************************************************************
    Program Interface for Stack Data Structure (Based on Linked List)
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/







#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED




#include "list.h"





/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************      DATA STRUCTURES      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/



typedef List Stack;







/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************     PUBLIC INTERFACE      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/



/*
 *  int stack_init(Stack *st, void (*destroy) (void *data))
 *
 *  Initializes a stack with an optional destruction function for
 *  the data elements.
 *  This destruction function will only be called when stack_destroy
 *  will be executed.
 *
 *  Parameter:
 *      stack       :   Pointer to a stack which is being initialized
 *      destroy     :   Pointer to a destruction function for data elements
 *                      (can be NULL)
 *
 *  Returns:
 *      0 for successful
*/
#define     stack_init          list_init





/*
 *  void stack_destroy(Stack *st)
 *
 *  Destroyes a previously initialized stack data structure.
 *  If the stack is NULL, this function does nothing.
 *
 *  Parameter:
 *      stack       :   Pointer to a stack which is being destroyed
 *
 *  Returns:
 *      (void)
*/
#define     stack_destroy       list_destroy





/*
 *  Returns the number of data elements the stack is currently holding.
 *
 *  Parameter:
 *      stack       :   Pointer to a stack data structure
 *
 *  Returns:
 *      (unsigned int)  Number of elements the specified stack is holding.
*/
#define     stack_size          list_size





/*
 *  int stack_search
 *  (
 *      Stack *st,
 *      void *data,
 *      int (*fpCompare) (const void *data1, const void *data2)
 *  )
 *
 *  Check if an element exists into the stack or not.
 *
 *  Parameter:
 *      stack       :   Pointer to a stack
 *      data        :   Pointer to a data element which is being searched
 *      fpCompare   :   Pointer to a comparison function by which the data elements
 *                      will be compared with each other
 *
 *  Returns:
 *      1 if data exists on the stack, compared with cmp
 *      0 if data does not exist
 *      -1 if data is NULL
*/
#define     stack_search        list_search





/*
 *  Inserts a data element into the specified stack.
 *  The data element will be inserted at the front of the stack.
 *
 *  Parameter:
 *      stack       :   Pointer to a stack
 *      data        :   Pointer to a data element which is being inserted
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int stack_push(Stack *st, const void *data);





/*
 *  Removes a data element from the specified stack.
 *  The data element will be removed from the front of the stack.
 *
 *  Parameter:
 *      stack       :   Pointer to a stack
 *      data        :   Pointer to a pointer which will receive the
 *                      removed data element
 *                      (can not be NULL)
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int stack_pop(Stack *st, void **data);





/*
 *  Retrives but does not remove a data element from the stack
 *  which is currently at the front of the specified stack.
 *
 *  Parameter:
 *      stack       :   Pointer to a stack
 *
 *  Returns:
 *      (void *)        Pointer to the data element at the front of the stack
*/
#define     stack_peek(st)   (list_head(st) == NULL ? NULL : list_head(st)->data)



#endif

