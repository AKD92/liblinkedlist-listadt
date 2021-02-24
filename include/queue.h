

/************************************************************************************
    Program Interface of Queue Data Structure (Base is Linked List)
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/







#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED




#include "list.h"





/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************      DATA STRUCTURES      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/



typedef List Queue;







/**********************************************************************************************/
/*********************************                           **********************************/
/*********************************     PUBLIC INTERFACE      **********************************/
/*********************************                           **********************************/
/**********************************************************************************************/



/*
 *  int queue_init(Queue *queue, void (*destroy) (void *data))
 *
 *  Initializes a queue with an optional destruction function for
 *  the data elements.
 *  This destruction function will only be called when queue_destroy
 *  will be executed.
 *
 *  Parameter:
 *      queue       :   Pointer to a queue which is being initialized
 *      destroy     :   Pointer to a destruction function for data elements
 *                      (can be NULL)
 *
 *  Returns:
 *      0 for successful
*/
#define     queue_init          list_init





/*
 *  void queue_destroy(Queue *queue)
 *
 *  Destroyes a previously initialized queue data structure.
 *  If the queue is NULL, this function does nothing.
 *
 *  Parameter:
 *      queue       :   Pointer to a queue which is being destroyed
 *
 *  Returns:
 *      (void)
*/
#define     queue_destroy       list_destroy





/*
 *  Returns the number of data elements the queue is currently holding.
 *
 *  Parameter:
 *      queue       :   Pointer to a queue data structure
 *
 *  Returns:
 *      (unsigned int)  Number of elements the specified queue is holding.
*/
#define     queue_size          list_size





/*
 *  int queue_search
 *  (
 *      Queue *queue,
 *      void *data,
 *      int (*fpCompare) (const void *data1, const void *data2)
 *  )
 *
 *  Check if an element exists into the queue or not.
 *
 *  Parameter:
 *      queue       :   Pointer to a queue
 *      data        :   Pointer to a data element which is being searched
 *      fpCompare   :   Pointer to a comparison function by which the data elements
 *                      will be compared with each other
 *
 *  Returns:
 *      1 if data exists on the queue, compared with cmp
 *      0 if data does not exist
 *      -1 if data is NULL
*/
#define     queue_search        list_search





/*
 *  Inserts a data element into the specified queue.
 *  The data element will be inserted at the back of the queue.
 *
 *  Parameter:
 *      queue       :   Pointer to a queue
 *      data        :   Pointer to a data element which is being inserted
 *                      (can not be NULL)
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int queue_enqueue(Queue *queue, const void *data);





/*
 *  Removes a data element from the specified queue.
 *  The data element will be removed from the front of the queue.
 *
 *  Parameter:
 *      queue       :   Pointer to a queue
 *      data        :   Pointer to a pointer which will receive the
 *                      removed data element
 *
 *  Returns:
 *      0 for successful
 *      -1 if an error occurs
*/
int queue_dequeue(Queue *queue, void **data);





/*
 *  Retrives but does not remove a data element from the queue
 *  which is currently at the front of the specified queue.
 *
 *  Parameter:
 *      queue       :   Pointer to a queue
 *
 *  Returns:
 *      (void *)        Pointer to the data element at the front of the queue
*/
#define     queue_peek(queue)   (list_head(queue) == NULL ? NULL : list_head(queue)->data)



#endif

