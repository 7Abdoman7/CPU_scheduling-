#include "process.h"
#include <time.h>

processes_t processes; 

/**
 * @brief Get a random value between 1 and max time of the process
 * 
 * @return uint32 
 */
static uint32 get_Random() {
    static int seed_initialized = FALSE;

    if (FALSE == seed_initialized) {
        srand(time(NULL));
        seed_initialized = TRUE;
    }
    else {}

    uint32 random_number = rand() % PROCESS_TIME_MAX + 1; 

    return random_number;
}

/**
 * @brief Initialize the processes
 * 
 * @return Std_return_t 
 */
Std_return_t processes_Init() {
    Std_return_t ret = OK;

    /* Check if the number of processes is positive */
    if (ZERO > PROCESS_NUMBER) {
        ret = NOT_OK;
        if (PROCESS_DEBUG_EN) {
            printf("\nError >> No processes to init @ processes_Init\n");
        }
    }
    else {
        uint32 counter = ZERO;
        uint32 random_Value = ZERO;

        for (counter = ZERO; counter < PROCESS_NUMBER; counter++) {
            random_Value = get_Random();
            /* Ids from 1 to the number of processes */
            processes.process[counter].Id = (counter + 1);
            /* Set a random value to the time */
            processes.process[counter].time = random_Value;
        }
    }

    return ret;
};

/**
 * @brief Decrease the time of a process
 * 
 * @param process 
 * @param time 
 * @return Std_return_t 
 */
Std_return_t process_Decrease_time(process_t *process, const uint32 time) {
    Std_return_t ret = OK;

    if (NULL == process) {
        ret = NOT_OK;
        if (PROCESS_DEBUG_EN) {
            printf("\nError >> Process is null @ process_Decrease_time\n");
        }
    }
    else {
        /* Check if the time is bigger than the process time */
        if (time > process->time) {
            process->time = ZERO;
        }
        else {
            process->time = process->time - time;
        }
    }

    return ret;
};

/**
 * @brief Print the Ids of processes
 * 
 * @param processes_Out 
 * @return Std_return_t 
 */
Std_return_t processes_Print(processes_t *Processes) {
    Std_return_t ret = OK;
    uint32 counter = ZERO;

    if (NULL == Processes) {
        ret = NOT_OK;
        if (PROCESS_DEBUG_EN) {
            printf("\nError >> Processes is null @ processes_Print_Id\n");
        }
    }
    else {
        for (counter = ZERO; counter < PROCESS_NUMBER; counter++) {
            printf("The id =  [%d] The initial time = [%d] ms \n", Processes->process[counter].Id, Processes->process[counter].time);
        }
    }

    return ret;
}
