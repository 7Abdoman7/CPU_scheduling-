#ifndef _QUEUE_CFG_H_
#define _QUEUE_CFG_H_

/*SECTION - Includes*/
#include "../STD/std_Types.h"
#include "../Process/process_cfg.h"

/*SECTION - Defines*/
#define QUEUE_DEBUG_EN          FALSE // For debugging 

#define QUEUES_NUMBER           (3) // Number of queues for the application 

/* Idicies of the queues */
#define QUEUE_1_INDEX           (0)
#define QUEUE_2_INDEX           (1)
#define QUEUE_3_INDEX           (2)

/* Initialize the max_size of the queues */
#define QUEUE_1_MAX_SIZE        (10)
#define QUEUE_2_MAX_SIZE        (20)
#define QUEUE_3_MAX_SIZE        (30)

/* Define the Q of the queues */
#define QUEUE_1_Q               (8)
#define QUEUE_2_Q               (16)

#define QUEUE(counter)    (&(Queues.queue[counter - 1])) // Easier way to get the queue

/*SECTION - Structures*/
/* Structure of the queue state*/
typedef enum {
    EMPTY,
    FULL,
    NOT_FULL
}queue_State;

/* Structure of the queue */
typedef struct {
    uint32 MAX_SIZE;
    uint32 size;
    process_t *arr;
    process_t *first_Ptr;
    process_t *last_Ptr;
    queue_State state;
}queue_t;

/* Structure of the queues used */
typedef struct {
    queue_t queue[QUEUES_NUMBER];
}queues_t;

/* Array of sizes */
typedef struct
{
    uint32 size[QUEUES_NUMBER];
}queue_Sizes_t;

/*SECTION - Externs*/
extern queues_t Queues;
extern const queue_Sizes_t queue_Sizes;

#endif
