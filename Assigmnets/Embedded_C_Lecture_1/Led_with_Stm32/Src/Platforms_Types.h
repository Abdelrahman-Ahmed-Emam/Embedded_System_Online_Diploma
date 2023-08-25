/*
 * Platforms_Types.h
 *
 *  Created on: Aug 22, 2023
 *      Author: HP
 */

#ifndef PLATFORMS_TYPES_H_
#define PLATFORMS_TYPES_H_
//Types
typedef unsigned char		boolean;
typedef signed char			sint8;
typedef unsigned char		uint8;
typedef signed short		sint16;
typedef unsigned short		uint16;
typedef signed long			sint32;
typedef unsigned long		uint32;
typedef signed long long	sint64;
typedef unsigned long long	uint64;
typedef float				float32;
typedef double 				float64;
//Volatiles
typedef volatile sint8		vint8_t;
typedef volatile uint8		vuint8_t;
typedef volatile sint16		vint16_t;
typedef volatile uint16		vuint16_t;
typedef volatile sint32		vint32_t;
typedef volatile uint32		vuint32_t;
typedef volatile sint64		vint64_t;
typedef volatile uint64		vuint64_t;
typedef volatile float32	vfloat32_t;
typedef volatile float64	vfloat64_t;


#endif /* PLATFORMS_TYPES_H_ */
