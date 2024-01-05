#ifndef _QUEUE_H_
#define _QUEUE_H_

/*SECTION - Includes*/
#include "queue_cfg.h"

/*SECTION - Function declaretions*/
/**
 * @brief Check queue if empty 
 * 
 * @param queue 
 * @return boolean 
 */
boolean isEmpty(queue_t *queue); 

/**
 * @brief Check queue if full
 * 
 * @param queue 
 * @return boolean 
 */
boolean isFull(queue_t *queue);    

/**
 * @brief Check queue if not_full
 * 
 * @param queue 
 * @return boolean 
 */
boolean isNotFull(queue_t *queue);  

/**
 * @brief Get max size of a queue
 * 
 * @param queue 
 * @param max_Size 
 * @return Std_return_t 
 */
Std_return_t queue_Get_Max_Size(queue_t *queue, uint32 *max_Size);

/**
 * @brief Get the size of the elements in the queue
 * 
 * @param queue 
 * @param size 
 * @return Std_return_t 
 */
Std_return_t queue_Get_Size(queue_t *queue, uint32 *size);          

/**
 * @brief Get the state of the queue
 * 
 * @param queue 
 * @param state 
 * @return Std_return_t 
 */
Std_return_t queue_Get_State(queue_t *queue, queue_State *state);  

/**
 * @brief Insert value into the end of the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */
Std_return_t enQueue(queue_t *queue, const process_t data); 

/**
 * @brief Return the value of the first element in the queue and delete it from the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */
Std_return_t deQueue(queue_t *queue, process_t *data);

/**
 * @brief Return the value of the first element in the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */
Std_return_t queue_Read_first(queue_t *queue, process_t *data); //* Return the value of the first element in the queue

/**
 * @brief Return the value of the last element in the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */
Std_return_t queue_Read_last(queue_t *queue, process_t *data); 

/**
 * @brief Initialize the queues
 * 
 * @return Std_return_t 
 */
Std_return_t queues_Init();

/**
 * @brief Print the elements of the queues
 * 
 * @return Std_return_t 
 */
Std_return_t queues_Print();    

#endif