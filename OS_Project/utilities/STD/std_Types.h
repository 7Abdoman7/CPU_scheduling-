#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/*SECTION - Includes*/
#include <stdlib.h>
#include <stdio.h>

/*SECTION - Defines*/
#define TRUE                (1)
#define FALSE               (0)
#define ZERO                (0)

/*SECTION - Data types*/
typedef unsigned char       boolean;
typedef unsigned char       uint8;
typedef signed char         sint8;
typedef unsigned short      uint16;
typedef signed short        sint16;
typedef unsigned int        uint32;
typedef signed int          sint32;

/*SECTION - Enums*/
typedef enum {
    OK,
    NOT_OK
}Std_return_t;

#endif