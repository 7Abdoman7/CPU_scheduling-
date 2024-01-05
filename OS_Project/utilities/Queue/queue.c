#include "queue.h"

queues_t Queues;

const queue_Sizes_t queue_Sizes = {
    .size[QUEUE_1_INDEX] = QUEUE_1_MAX_SIZE,
    .size[QUEUE_2_INDEX] = QUEUE_2_MAX_SIZE,
    .size[QUEUE_3_INDEX] = QUEUE_3_MAX_SIZE,
};

/**
 * @brief Initialize the queues
 * 
 * @return Std_return_t 
 */
Std_return_t queues_Init() {
    Std_return_t ret = OK;

    if (NULL == (&queue_Sizes)) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ queues_Init\n");
        }
    }
    else {
        uint32 counter = ZERO;

        for (counter = ZERO; counter < QUEUES_NUMBER; counter++) {
            /* Initialize the queues max sizes */
            Queues.queue[counter].MAX_SIZE = queue_Sizes.size[counter];

            /* Allocate the size into the memory */
            Queues.queue[counter].arr = (process_t*)malloc(queue_Sizes.size[counter] * sizeof(process_t));

            /* Check if the memeory is allocated */
            if (NULL == Queues.queue[counter].arr) {
                ret = NOT_OK;
                if (QUEUE_DEBUG_EN) {
                    printf("\nError >> Queue can't be allocated @ queues_Init\n");
                }
                break;
            }
            else {}

            /* Set first to NULL */
            Queues.queue[counter].first_Ptr = NULL;

            /* Set last to NULL */
            Queues.queue[counter].last_Ptr = NULL;

            /* Set size to ZERO */
            Queues.queue[counter].size = ZERO;

            /* Set state to EMPTY */
            Queues.queue[counter].state = EMPTY;
        }
    }

    return ret;
};

/**
 * @brief Check queue if empty 
 * 
 * @param queue 
 * @return boolean 
 */
boolean isEmpty(queue_t *queue) {
    if (EMPTY == queue->state) {
        return TRUE;
    }
    else {
        return FALSE;
    }
};

/**
 * @brief Check queue if full
 * 
 * @param queue 
 * @return boolean 
 */
boolean isFull(queue_t *queue) {
    if (FULL == queue->state) {
        return TRUE;
    }
    else {
        return FALSE;
    }
};

/**
 * @brief Check queue if not_full
 * 
 * @param queue 
 * @return boolean 
 */
boolean isNotFull(queue_t *queue) {
    if (NOT_FULL == queue->state) {
        return TRUE;
    }
    else {
        return FALSE;
    }
};

/**
 * @brief Get max size of a queue
 * 
 * @param queue 
 * @param max_Size 
 * @return Std_return_t 
 */
Std_return_t queue_Get_Max_Size(queue_t *queue, uint32 *max_Size) {
    Std_return_t ret = OK;

    if (NULL == max_Size) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> variable is null @ queue_Get_Max_Size\n");
        }
    }
    else if (NULL == queue) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ queue_Get_Max_Size\n");
        }
    }
    else {
        *max_Size = queue->MAX_SIZE;
    }

    return ret;
};

/**
 * @brief Get the size of the elements in the queue
 * 
 * @param queue 
 * @param size 
 * @return Std_return_t 
 */
Std_return_t queue_Get_Size(queue_t *queue, uint32 *size) {
    Std_return_t ret = OK;

    if (NULL == size) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> variable is null @ queue_Get_Size\n");
        }
    }
    else if (NULL == queue) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ queue_Get_Size\n");
        }
    }
    else {
        *size = queue->size;
    }

    return ret;
};

/**
 * @brief Get the state of the queue
 * 
 * @param queue 
 * @param state 
 * @return Std_return_t 
 */
Std_return_t queue_Get_State(queue_t *queue, queue_State *state) {
    Std_return_t ret = OK;

    if (NULL == state) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> variable is null @ queue_Get_State\n");
        }
    }
    else if (NULL == queue) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ queue_Get_State\n");
        }
    }
    else {
        *state = queue->state;
    }

    return ret;
};

/**
 * @brief Return the value of the first element in the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */
Std_return_t queue_Read_first(queue_t *queue, process_t *data) {
    Std_return_t ret = OK;

    if (NULL == data) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> variable is null @ queue_Read_first\n");
        }
    }
    else if (NULL == queue) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ queue_Read_first\n");
        }
    }
    else {
        *data = *queue->first_Ptr;
    }

    return ret;
};

/**
 * @brief Return the value of the last element in the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */
Std_return_t queue_Read_last(queue_t *queue, process_t *data) {
    Std_return_t ret = OK;

    if (NULL == data) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> variable is null @ queue_Read_last\n");
        }
    }
    else if (NULL == queue) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ queue_Read_last\n");
        }
    }
    else {
        *data = *queue->last_Ptr;
    }

    return ret;
};

/**
 * @brief Insert value into the end of the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */Std_return_t enQueue(queue_t *queue, const process_t data) {
    Std_return_t ret = OK;

    if (NULL == queue) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ enQueue\n");
        }
    }
    else {
        if (isFull(queue)) {
            ret = NOT_OK;
            if (QUEUE_DEBUG_EN) {
                printf("\nError >> Queue is full @ enQueue\n");
            }
        }
        else if (isEmpty(queue)) {
            /* Insert the data into the first element in the array*/
            queue->arr[queue->size] = data;

            /* Set the pointers into the first element */
            queue->first_Ptr = &(queue->arr[ZERO]);
            queue->last_Ptr = &(queue->arr[ZERO]);

            /* Increase the size of the queue */
            queue->size++;

            if (queue->MAX_SIZE == queue->size) {
                queue->state = FULL;
            }
            else {
                queue->state = NOT_FULL;
            }
        }
        else if (isNotFull(queue)){
            /* Insert the data into the first element in the array*/
            queue->arr[queue->size] = data;

            /* Set the pointers into the first element */
            queue->last_Ptr = &(queue->arr[queue->size]);

            /* Increase the size of the queue */
            queue->size++;

            if (queue->MAX_SIZE == queue->size) {
                queue->state = FULL;
            }
            else {
                queue->state = NOT_FULL;
            }
        }
    }

    return ret;
};

/**
 * @brief Return the value of the first element in the queue and delete it from the queue
 * 
 * @param queue 
 * @param data 
 * @return Std_return_t 
 */
Std_return_t deQueue(queue_t *queue, process_t *data) {
    Std_return_t ret = OK;

    if (NULL == data) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> variable is null @ deQueue\n");
        }
    }
    else if (NULL == queue) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> Queue is null @ deQueue\n");
        }
    }
    else {
        if (isEmpty(queue)) {
            ret = NOT_OK;
            if (QUEUE_DEBUG_EN) {
                printf("\nError >> Queue is empty @ deQueue\n");
            }
        }
        else {
            uint32 counter = ZERO;
            uint32 queue_Size = ZERO;

            /* Get the data in the first of the queue */
            ret = queue_Read_first(queue, data);
            if (NOT_OK == ret) {
                if (QUEUE_DEBUG_EN) {
                    printf("\nError >> Can't read the first element @ deQueue\n");
                }
            }
            else {
                /* Shift the elements in the queue to the front */
                for (counter = ZERO; counter < (queue->size - 1); counter++) {
                    queue->arr[counter] = queue->arr[counter + 1];
                }

                /* Decrement the size of the queue */
                queue->size--;

                /* Update the pointers */
                queue->first_Ptr = &(queue->arr[ZERO]);
                queue->last_Ptr = &(queue->arr[queue->size - 1]);

                /* Update the queue state */
                if (ZERO == queue->size) {
                    queue->state = EMPTY;
                }
                else {
                    queue->state = NOT_FULL;
                }
            }
        }
    }

    return ret;
}

/**
 * @brief Print the elements of the queues
 * 
 * @return Std_return_t 
 */
Std_return_t queues_Print() {
    Std_return_t ret = OK;

    if (NULL == &(queue_Sizes)) {
        ret = NOT_OK;
        if (QUEUE_DEBUG_EN) {
            printf("\nError >> queues_Sizes is null @ queues_Print\n");
        }
    }
    else {
        uint32 queue_Counter = ZERO;
        uint32 counter = ZERO;

        for (queue_Counter = ZERO; queue_Counter < QUEUES_NUMBER; queue_Counter++) {
            printf("Elements of the [%d] queue: ", (queue_Counter + 1));
            for (counter = ZERO; counter < Queues.queue[queue_Counter].size; counter++) {
                printf(" Id: %d time: %d ", Queues.queue[queue_Counter].arr[counter].Id, Queues.queue[queue_Counter].arr[counter].time);
            }
            printf("\n");
        }
    }

    return ret;
};
