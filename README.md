# CPU Scheduling Simulation Project

## Overview

This project simulates CPU scheduling with multiple queues. It allows you to customize the number of queues, their sizes, and the quantum (Q) value from the `queue_cfg.h` file. Additionally, you can configure the number of processes and their maximum execution times in the `process_cfg.h` file.

## How to Run

To execute the simulation, use the provided Makefile. Running the Makefile will generate two output files: one for the arrangement of output processes and another for the steps taken during the simulation.

## Customization

### Queues Configuration (`queue_cfg.h`)

- Adjust the number of queues: Modify the `QUEUES_NUMBER` constant to the desired value.
- Set the size of each queue: Update the `QUEUE_MAX_SIZE` array with the preferred sizes for each queue.
- Configure the quantum (Q): Modify the `Q` constant to set the quantum for the simulation.

### Processes Configuration (`process_cfg.h`)

- Set the number of processes: Adjust the `PROCESS_NUMBER` constant to the desired value.
- Specify the maximum execution time for each process: Update the `PROCESS_TIME_MAX` array with the preferred maximum execution time for each process.

## Output Files

The simulation will produce two output files:

1. **Arrangement of Output Processes (`process.txt`):** This file contains the arrangement of output processes based on the scheduling algorithm.

2. **Steps Taken during Simulation (`steps.txt`):** This file details the steps taken during the simulation, including the processes executed and the state of the queues after each step.

## Author Information

- Author: Abdelrahman Elsayed Ahmed
- Personal Email: abdo.elsayd102@gmail.com
- Contact: 01222448817 (WhatsApp)

Feel free to contact the author for any issues or inquiries related to the project. Your feedback is valuable.

**Note:** Make sure to have a proper C compiler installed on your system to run the simulation successfully.
