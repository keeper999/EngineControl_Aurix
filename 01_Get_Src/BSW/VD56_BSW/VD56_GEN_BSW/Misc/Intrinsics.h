/**
 * \file Intrinsics.h
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
 *
 *
 * $Revision: 1415 $
 * $Date: 2013-02-19 16:15:13 +0100 (Di, 19 Feb 2013) $
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Cpu_Intrinsics Intrinsics
 * \ingroup IfxLld_Cpu
 *
 */
#ifndef INTRINSICS_H
#define INTRINSICS_H
/******************************************************************************/
/*#include "Ifx_Types.h"*/

#if defined(__DCC__)
#include "IntrinsicsDcc.h"

#elif defined(_GNU_C_TRICORE_)
#include "IntrinsicsGnuc.h"

#elif defined(_TASKING_C_TRICORE_)
#include "IntrinsicsTasking.h"

#else
#error Compiler unsupported
#endif

#define ALIGN_8         (1)     // Align on 8 bit Boundary
#define ALIGN_16        (2)     // Align on 16 bit Boundary
#define ALIGN_32        (4)     // Align on 32 bit Boundary
#define ALIGN_64        (8)     // Align on 64 bit Boundary

#define AlignOn64(Size) ((((Size) + (ALIGN_64 - 1)) & (~(ALIGN_64 - 1))))
#define AlignOn32(Size) ((((Size) + (ALIGN_32 - 1)) & (~(ALIGN_32 - 1))))
#define AlignOn16(Size) ((((Size) + (ALIGN_16 - 1)) & (~(ALIGN_16 - 1))))
#define AlignOn8(Size)  ((((Size) + (ALIGN_8  - 1)) & (~(ALIGN_8 -  1))))

#define COUNTOF(x)      (sizeof(x) / sizeof(x[0]))

//______________________________________________________________________________



/******************************************************************************/
IFX_INLINE void __ldmst_c (volatile unsigned *address, unsigned mask, unsigned value)
{
    *address = (*address & ~(mask)) | (mask & value);
}

IFX_INLINE uint32 __ld32 (void *addr)
{
    return *(uint32 *) addr;
}

IFX_INLINE void __st32 (void *addr, uint32 value)
{
    *(uint32 *) addr = value;
}

#define IFX_VECTOR_CPU0 (0)
#define IFX_VECTOR_CPU1 (1)
#define IFX_VECTOR_CPU2 (2)
/******************************************************************************/
#endif /* INTRINSICS_H */
