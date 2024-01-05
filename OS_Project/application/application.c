#include "application.h"
#include <time.h>

FILE *stepsFile = NULL;
FILE *processFile = NULL;

/**
 * @brief Get a random value betwen 0 and 1
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

    uint32 random_number = (rand() % 100 + 1) % 2; 

    return random_number;
}

/**
 * @brief Queue #1 job
 * 
 * @param process_Out 
 * @param process_Counter 
 * @param process_Out_Counter 
 */
static void Queue_1_Job(processes_t *process_Out, uint32 *process_Counter, uint32 *process_Out_Counter) {
    uint32 queue_1_Counter = ZERO;
    process_t temp_Process;

    if (APP_STEPS_EN) {
        printf(">>>>CPU at queue (1)\n");
    }
    else {}
    fprintf(stepsFile, ">>>>CPU at queue (1)\n");

    /* 50% of the CPU */
    for (queue_1_Counter = ZERO; queue_1_Counter < QUEUE_1_USAGE; queue_1_Counter++) {
        if (isEmpty(QUEUE(1))) {
            if (PROCESS_NUMBER != *process_Counter) {
                enQueue(QUEUE(1), PROCESS(*process_Counter));
                if (APP_STEPS_EN) {
                    printf(">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", PROCESS(*process_Counter).Id, PROCESS(*process_Counter).time);
                }
                else {}
                fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", PROCESS(*process_Counter).Id, PROCESS(*process_Counter).time);
                (*process_Counter)++;
            }
            else {break;}
        }
        else if (isFull(QUEUE(1))) {
            deQueue(QUEUE(1), &temp_Process);
            if (APP_STEPS_EN) {
                printf(">>Process(Id = %d, Current time = %d) has been removed from queue (1)\n", temp_Process.Id, temp_Process.time);
            }
            else {}
            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been removed from queue (1)\n", temp_Process.Id, temp_Process.time);
            if (APP_STEPS_EN) {
                printf(">>Process (Id = %d, Current time = %d), Its time decreased by %d\n", temp_Process.Id, temp_Process.time, QUEUE_1_Q);
            }
            else {}
            fprintf(stepsFile, ">>Process (Id = %d, Current time = %d), Its time decreased by %d\n", temp_Process.Id, temp_Process.time, QUEUE_1_Q);
            process_Decrease_time(&temp_Process, QUEUE_1_Q);
            if (ZERO != temp_Process.time) {
                if (isFull(QUEUE(2))) {
                    enQueue(QUEUE(1), temp_Process);
                    if (APP_STEPS_EN) {
                        printf(">>Process(Id = %d, Current time = %d) has added to queue (1)\n", temp_Process.Id, temp_Process.time);
                    }
                    else {}
                    fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has added to queue (1)\n", temp_Process.Id, temp_Process.time);
                }
                else {
                    enQueue(QUEUE(2), temp_Process);
                    if (APP_STEPS_EN) {
                        printf(">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                    }
                    else {}
                    fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                }
            }
            else {
                process_Out->process[*process_Out_Counter].Id = temp_Process.Id;
                process_Out->process[*process_Out_Counter].time = processes.process[temp_Process.Id - 1].time;
                if (APP_STEPS_EN) {
                    printf(">>Process(Id = %d, Initial time = %d) has finished\n", process_Out->process[*process_Out_Counter].Id, process_Out->process[*process_Out_Counter].time);
                }
                else {}
                fprintf(stepsFile, ">>Process(Id = %d, Initial time = %d) has finished\n", process_Out->process[*process_Out_Counter].Id, process_Out->process[*process_Out_Counter].time);
                (*process_Out_Counter)++;
            }
        }
        else if (isNotFull(QUEUE(1))) {
            if (PROCESS_NUMBER != *process_Counter) {
                enQueue(QUEUE(1), PROCESS(*process_Counter));
                if (APP_STEPS_EN) {
                    printf(">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", PROCESS(*process_Counter).Id, PROCESS(*process_Counter).time);
                }
                else {}
                fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", PROCESS(*process_Counter).Id, PROCESS(*process_Counter).time);
                (*process_Counter)++;
            }
            deQueue(QUEUE(1), &temp_Process);
            if (APP_STEPS_EN) {
                printf(">>Process(Id = %d, Current time = %d) has been removed from queue (1)\n", temp_Process.Id, temp_Process.time);
            }
            else {}
            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been removed from queue (1)\n", temp_Process.Id, temp_Process.time);
            if (APP_STEPS_EN) {
                printf(">>Process (Id = %d, Current time = %d), Its time decreased by %d\n", temp_Process.Id, temp_Process.time, QUEUE_1_Q);
            }
            else {}
            fprintf(stepsFile, ">>Process (Id = %d, Current time = %d), Its time decreased by %d\n", temp_Process.Id, temp_Process.time, QUEUE_1_Q);
            process_Decrease_time(&temp_Process, QUEUE_1_Q);
            if (ZERO != temp_Process.time) {
                if (isFull(QUEUE(2))) {
                    enQueue(QUEUE(1), temp_Process);
                    if (APP_STEPS_EN) {
                        printf(">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", temp_Process.Id, temp_Process.time);
                    }
                    else {}
                    fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", temp_Process.Id, temp_Process.time);
                }
                else {
                    enQueue(QUEUE(2), temp_Process);
                    if (APP_STEPS_EN) {
                        printf(">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                    }
                    else {}
                    fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                }
            }
            else {
                process_Out->process[*process_Out_Counter] = temp_Process;
                process_Out->process[*process_Out_Counter].time = processes.process[temp_Process.Id - 1].time;
                if (APP_STEPS_EN) {
                    printf(">>Process(Id = %d, Initial time = %d) has finished\n", process_Out->process[*process_Out_Counter].Id, process_Out->process[*process_Out_Counter].time);
                }
                else {}
                fprintf(stepsFile, ">>Process(Id = %d, Initial time = %d) has finished\n", process_Out->process[*process_Out_Counter].Id, process_Out->process[*process_Out_Counter].time);
                (*process_Out_Counter)++; 
            }
        }     
    }

    if (APP_STEPS_EN) {
        printf(">>>>CPU left queue (1)\n");
    }
    else {}
    fprintf(stepsFile, ">>>>CPU left queue (1)\n");
}

/**
 * @brief Queue #2 job
 * 
 * @param process_Out 
 * @param process_Counter 
 * @param process_Out_Counter 
 */
static void Queue_2_Job(processes_t *process_Out, uint32 *process_Counter, uint32 *process_Out_Counter) {
    process_t temp_Process;
    uint8 random_Value = ZERO;
    uint32 queue_2_Counter = ZERO;

    if (APP_STEPS_EN) {
        printf(">>>>CPU at queue (2)\n");
    }
    else {}
    fprintf(stepsFile, ">>>>CPU at queue (2)\n");

    /* 30% of the CPU */
    for (queue_2_Counter = ZERO; queue_2_Counter < QUEUE_2_USAGE; queue_2_Counter++) {
        if (isEmpty(QUEUE(2))) {
            break;
        }
        else {
            deQueue(QUEUE(2), &temp_Process);
            if (APP_STEPS_EN) {
                printf(">>Process(Id = %d, Current time = %d) has been removed from queue (2)\n", temp_Process.Id, temp_Process.time);
            }
            else {}
            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been removed from queue (2)\n", temp_Process.Id, temp_Process.time);
            if (APP_STEPS_EN) {
                printf(">>Process (Id = %d, Current time = %d), Its time decreased by %d\n", temp_Process.Id, temp_Process.time, QUEUE_2_Q);
            }
            else {}
            fprintf(stepsFile, ">>Process (Id = %d, Current time = %d), Its time decreased by %d\n", temp_Process.Id, temp_Process.time, QUEUE_2_Q);
            process_Decrease_time(&temp_Process, QUEUE_2_Q);
            if (ZERO != temp_Process.time) {
                random_Value = get_Random();
                if (FALSE == random_Value) {
                    if (isFull(QUEUE(1))) {
                        if (isFull(QUEUE(3))) {
                            enQueue(QUEUE(2), temp_Process);
                            if (APP_STEPS_EN) {
                                printf(">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                            }
                            else {}
                            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                        }
                        else {
                            enQueue(QUEUE(3), temp_Process);
                            if (APP_STEPS_EN) {
                                printf(">>Process(Id = %d, Current time = %d) has been added to queue (3)\n", temp_Process.Id, temp_Process.time);
                            }
                            else {}
                            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (3)\n", temp_Process.Id, temp_Process.time);
                        }
                    }
                    else {
                        enQueue(QUEUE(1), temp_Process);
                        if (APP_STEPS_EN) {
                            printf(">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", temp_Process.Id, temp_Process.time);
                        }
                        else {}
                        fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", temp_Process.Id, temp_Process.time);
                    }
                }
                else if (TRUE == random_Value) {
                    if (isFull(QUEUE(3))) {
                        if (isFull(QUEUE(1))) {                           
                            enQueue(QUEUE(2), temp_Process);
                            if (APP_STEPS_EN) {
                                printf(">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                            }
                            else {}
                            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (2)\n", temp_Process.Id, temp_Process.time);
                        }
                        else {
                            enQueue(QUEUE(1), temp_Process);
                            if (APP_STEPS_EN) {
                                printf(">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", temp_Process.Id, temp_Process.time);
                            }
                            else {}
                            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (1)\n", temp_Process.Id, temp_Process.time);
                        }
                    }
                    else {
                        enQueue(QUEUE(3), temp_Process);
                        if (APP_STEPS_EN) {
                            printf(">>Process(Id = %d, Current time = %d) has been added to queue (3)\n", temp_Process.Id, temp_Process.time);
                        }
                        else {}
                        fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been added to queue (3)\n", temp_Process.Id, temp_Process.time);
                    }
                }
            }
            else {
                process_Out->process[*process_Out_Counter] = temp_Process;
                process_Out->process[*process_Out_Counter].time = processes.process[temp_Process.Id - 1].time;
                if (APP_STEPS_EN) {
                    printf(">>Process(Id = %d, Initial time = %d) has finished\n", process_Out->process[*process_Out_Counter].Id, process_Out->process[*process_Out_Counter].time);
                }
                else {}
                fprintf(stepsFile, ">>Process(Id = %d, Initial time = %d) has finished\n", process_Out->process[*process_Out_Counter].Id, process_Out->process[*process_Out_Counter].time);
                (*process_Out_Counter)++;         
            }
        }
    }   

    if (APP_STEPS_EN) {
        printf(">>>>CPU left queue (2)\n");
    }
    else {}
    fprintf(stepsFile, ">>>>CPU left queue (2)\n");
}

/**
 * @brief Queue #3 job
 * 
 * @param process_Out 
 * @param process_Counter 
 * @param process_Out_Counter 
 */
static void Queue_3_Job(processes_t *process_Out, uint32 *process_Counter, uint32 *process_Out_Counter) {
    process_t temp_Process;
    uint32 queue_3_Counter = ZERO;

    if (APP_STEPS_EN) {
        printf(">>>>CPU at queue (3)\n");
    }
    else {}
    fprintf(stepsFile, ">>>>CPU at queue (3)\n");

    /* 20% of the CPU*/
    for (queue_3_Counter = ZERO; queue_3_Counter < QUEUE_3_USAGE; queue_3_Counter++) {
        if (isEmpty(QUEUE(3))) {  
            break;
        }
        else {
            deQueue(QUEUE(3), &temp_Process);
            if (APP_STEPS_EN) {
                printf(">>Process(Id = %d, Current time = %d) has been removed from queue (3)\n", temp_Process.Id, temp_Process.time);
            }
            else {}
            fprintf(stepsFile, ">>Process(Id = %d, Current time = %d) has been removed from queue (3)\n", temp_Process.Id, temp_Process.time);
            process_Decrease_time(&temp_Process, temp_Process.time);
            process_Out->process[*process_Out_Counter] = temp_Process;
            process_Out->process[*process_Out_Counter].time = processes.process[temp_Process.Id - 1].time;
            if (APP_STEPS_EN) {
                printf(">>Process(Id = %d, Initial time = %d) has finished\n", process_Out->process[*process_Out_Counter].Id, process_Out->process[*process_Out_Counter].time);
            }
            else {}
            (*process_Out_Counter)++;   
        } 
    }

    if (APP_STEPS_EN) {
        printf(">>>>CPU left queue (3)\n");
    }
    else {}
    fprintf(stepsFile, ">>>>CPU left queue (3)\n");
}

/**
 * @brief Assist the app_Start function
 * 
 * @param process_Out 
 * @return Std_return_t 
 */
static Std_return_t app_Start_Aux(processes_t *process_Out) {
    Std_return_t ret = OK;

    stepsFile = fopen(STEPS_FILE_PATH, "w");
    processFile = fopen(PROCESS_FILE_PATH, "w");

    if (NULL == stepsFile || NULL == processFile) {
        ret = NOT_OK;
        if (APP_DEBUG_EN) {
            printf("\nError >> File is NULL @ app_Start_Aux\n");
        }
        return ret;
    }

    if (NULL == process_Out) {
        ret = NOT_OK;
        if (APP_DEBUG_EN) {
            printf("\nError >> Process_Out is NULL @ app_Start_Aux\n");
        }
        return ret;
    }

    ret = queues_Init();
    if (NOT_OK == ret) {
        if (APP_DEBUG_EN) {
            printf("\nError >> Can't init queues @ app_Start_Aux\n");
        }
        return ret;
    }

    ret = processes_Init();
    if (NOT_OK == ret) {
        if (APP_DEBUG_EN) {
            printf("\nError >> Can't init processes @ app_Start_Aux\n");
        }
        return ret;
    }

    return ret;
}

/**
 * @brief Start the application
 * 
 * @param process_Out 
 * @return Std_return_t 
 */
Std_return_t app_Start(processes_t *process_Out) {
    Std_return_t ret = OK;

    ret = app_Start_Aux(process_Out);
    if (NOT_OK == ret) {
        if (APP_DEBUG_EN) {
            printf("\nError >> In app_Start_Aux @ app_Start_Aux\n");
        }
        ret = NOT_OK;
    }

    /* Initialize the counters */
    uint32 process_Counter = ZERO;
    uint32 process_Out_Counter = ZERO;
    uint32 counter = ZERO;

    if (APP_STEPS_EN) {
        printf(">>>>>>The program has started\n");
    }
    else {}   
    fprintf(stepsFile, ">>>>>>The program has started\n");

    while (TRUE) {
        Queue_1_Job(process_Out, &process_Counter, &process_Out_Counter);
        Queue_2_Job(process_Out, &process_Counter, &process_Out_Counter);
        Queue_3_Job(process_Out, &process_Counter, &process_Out_Counter);

        if (isEmpty(QUEUE(1)) && isEmpty(QUEUE(2)) && isEmpty(QUEUE(3)) && (PROCESS_NUMBER == process_Counter) && (PROCESS_NUMBER == process_Out_Counter)) {
            if (APP_STEPS_EN) {
                printf(">>>>>>The program has finished\n");
            }
            else {}   
            fprintf(stepsFile, ">>>>>>The program has finished\n");
            break;
        }
    }

    fprintf(processFile, "The initial processes:\n");
    if (APP_DEBUG_EN) {
        printf("The initial processes:\n");
    }
    else {}
    
    for (counter = ZERO; counter < PROCESS_NUMBER; counter++) {
        fprintf(processFile, "The id =  [%d] The initial time = [%d] ms \n", processes.process[counter].Id, processes.process[counter].time);
        if (APP_DEBUG_EN) {
            printf("The id =  [%d] The initial time = [%d] ms \n", processes.process[counter].Id, processes.process[counter].time);
        }
        else {}
    }

    fprintf(processFile, "\nThe processes by the time they finished:\n");
    if (APP_DEBUG_EN) {
        printf("\nThe processes by the time they finished:\n");
    }
    else {}

    for (counter = ZERO; counter < PROCESS_NUMBER; counter++) {
        fprintf(processFile, "The id =  [%d] The initial time = [%d] ms \n", process_Out->process[counter].Id, process_Out->process[counter].time);
        if (APP_DEBUG_EN) {
            printf("The id =  [%d] The initial time = [%d] ms \n", process_Out->process[counter].Id, process_Out->process[counter].time);
        }
        else {}
    }

    fclose(stepsFile);
    fclose(processFile);


    return ret;
};