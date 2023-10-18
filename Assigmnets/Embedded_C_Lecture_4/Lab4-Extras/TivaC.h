#ifndef _TIVA_C_H_
#define _TIVA_C_H_

#include "Platforms_Type.h"

#define SYSCTL 0X400FE000
#define GPIOF 0X40025000
#define RCGC2_R 0X108 // for the SYSCTL_RCGC2_R
#define _DATA_R 0X3FC // for GPIOF
#define _DIR_R 0X400  // for GPIOF
#define _DEN_R 0X51C  // for GPIOF

#define SYSCTL_RCGC2_R ((vuint16_t *)(SYSCTL + RCGC2_R))
#define GPIOF_DATA_R ((vint16_t *)(GPIOF + _DATA_R))
#define GPIOF_DIR_R ((vint16_t *)(GPIOF + _DIR_R))
#define GPIOF_DEN_R ((vint16_t *)(GPIOF + _DEN_R))

typedef union
{
    vuint32_t All_Pins;
    struct
    {
        vuint32_t pin0 : 1;
        vuint32_t pin1 : 1;
        vuint32_t pin2 : 1;
        vuint32_t pin3 : 1;
        vuint32_t pin4 : 1;
        vuint32_t pin5 : 1;
        vuint32_t pin6 : 1;
        vuint32_t pin7 : 1;
        vuint32_t pin8 : 1;
        vuint32_t pin9 : 1;
        vuint32_t pin10 : 1;
        vuint32_t pin11 : 1;
        vuint32_t pin12 : 1;
        vuint32_t pin13 : 1;
        vuint32_t pin14 : 1;
        vuint32_t pin15 : 1;
        vuint32_t pin16 : 1;
        vuint32_t pin17 : 1;
        vuint32_t pin18 : 1;
        vuint32_t pin19 : 1;
        vuint32_t pin20 : 1;
        vuint32_t pin21 : 1;
        vuint32_t pin22 : 1;
        vuint32_t pin23 : 1;
        vuint32_t pin24 : 1;
        vuint32_t pin25 : 1;
        vuint32_t pin26 : 1;
        vuint32_t pin27 : 1;
        vuint32_t pin28 : 1;
        vuint32_t pin29 : 1;
        vuint32_t pin30 : 1;
        vuint32_t pin31 : 1;

    } pins;
} Registers;

#endif