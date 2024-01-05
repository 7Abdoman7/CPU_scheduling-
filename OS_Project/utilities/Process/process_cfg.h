#ifndef _PROCESS_CFG_H_
#define _PROCESS_CFG_H_

/*SECTION - Includes*/
#include "../STD/std_Types.h"

/*SECTION - Defines*/
#define PROCESS_DEBUG_EN        FALSE // For debugging 

#define PROCESS_NUMBER          (100)
#define PROCESS_TIME_MAX        (100)

#define PROCESS(counter)    (processes.process[counter]) // Easier way to get a process

/*SECTION - Structure*/
/* Structure of a process */
typedef struct {
    uint32 Id;
    uint32 time;
}process_t;

/* Structure of a processes */
typedef struct {
    process_t process[PROCESS_NUMBER];
}processes_t;

/*SECTION - Externs*/
extern processes_t processes; // Used later in the code

#endif