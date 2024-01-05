#ifndef _PROCESS_H_
#define _PROCESS_H_

/*SECTION - Includes*/
#include "process_cfg.h"

/*SECTION - Function declaretions*/
/**
 * @brief Initialize the processes
 * 
 * @return Std_return_t 
 */
Std_return_t processes_Init();

/**
 * @brief Decrease the time of a process
 * 
 * @param process 
 * @param time 
 * @return Std_return_t 
 */
Std_return_t process_Decrease_time(process_t *process, const uint32 time);

/**
 * @brief Print the Ids of processes
 * 
 * @param processes_Out 
 * @return Std_return_t 
 */
Std_return_t processes_Print(processes_t *Processes);  

#endif
