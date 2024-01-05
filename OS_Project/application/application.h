#ifndef _APPLICATION_H_
#define _APPLICATION_H_

/*SECTION - Includes*/
#include "../utilities/Process/process.h"
#include "../utilities/Queue/queue.h"

/*SECTION - Defines*/
#define APP_DEBUG_EN            FALSE // For debugging
#define APP_STEPS_EN            FALSE // For showing steps

#define STEPS_FILE_PATH         "files/steps.txt"
#define PROCESS_FILE_PATH       "files/process.txt"

/*NOTE - Define the time of the CPU for each queue */
#define QUEUE_1_USAGE         (5)
#define QUEUE_2_USAGE         (3)
#define QUEUE_3_USAGE         (2)

/*SECTION - Function declaretions*/
/**
 * @brief Start the application
 * 
 * @param process_Out 
 * @return Std_return_t 
 */
Std_return_t app_Start(processes_t *process_Out);

/*SECTION - Externs*/
extern FILE *stepsFile;
extern FILE *processFile;

#endif
