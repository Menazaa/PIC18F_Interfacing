/* 
 * File:   std_libraries.h
 * Author: Mohamed Menazaa
 *
 * Created on May 12, 2023, 2:08 PM
 */

#ifndef STD_LIBRARIES_H
#define	STD_LIBRARIES_H


/* Section : Includes */

#include "BIT_MATH.h"
#include <stdio.h>
#include <stdlib.h>

/* Section : Macros Declarations */

#define STD_HIGH        0X01
#define STD_LOW         0X00

#define STD_ON          0X01
#define STD_FF          0X00

#define STD_ACTIVE      0X01
#define STD_IDLE        0X00

/* Section : Macros Functions Declarations */

/* Section : Data Types Declarations */
typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef  char           sint8;
typedef  short          sint16;
typedef  long           sint32;
typedef  long long      sint64;


typedef uint8   STD_ReturnType;

typedef  enum{
    E_OK        =   0x00,
    E_NOT_OK    =   0x01
}STD_Return_State;

/* Section : Functions Declarations */


#endif	/* STD_LIBRARIES_H */

