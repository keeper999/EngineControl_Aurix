/******************************************************************************/
/*                                                                            */
/* !Layer          : MATH                                                     */
/*                                                                            */
/* !Component      : MATH                                                     */
/*                                                                            */
/* !Module         : MATH                                                     */
/* !Description    : Source of MATH component                                 */
/*                                                                            */
/* !File           : ACTEMS_CeilF.c                                           */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/ACTEMS_Sing$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   03 Oct 2012$*/
/******************************************************************************/

#ifndef _ACTEMS_SINGLE_H_
#define _ACTEMS_SINGLE_H_

#include "Std_Types.h"

#define SINGLE_ZERO_NEG                      0x80000000
#define SINGLE_ZERO_POS                      0x00000000

/* Input _f : float32 */
/* Return   : uint32 */
#define SINGLE_GET_U32(_f)                   (*(uint32 *)(&_f))

/* Input _u : uint32 */
/* Return   : uint8 */
#define SINGLE_GET_EXP(_u)                   ((uint8)(_u >> 23))

/* Input _u : uint32 */
/* Return   : boolean */
#define SINGLE_IS_POS(_u)                    (0 == (_u >> 31))

/* Input _u : uint32 */
/* Return   : boolean */
#define SINGLE_IS_NEG(_u)                    (0 != (_u >> 31))

/* Input _u : uint32 */
/* Return   : boolean */
#define SINGLE_IS_NAN(_u)                    (0 != (_u >> 31))

/* Input _u : uint32 */
/* Return   : uint32 */
#define SINGLE_GET_FRACTION(_u)              (_u & 0x7FFFFF)

/* Input _frac : uint32 */
/* Input _exp : uint8 */
/* Return   : uint32 */
#define SINGLE_SET_POS(_frac, _exp)          (_frac + (_exp << 23))

/* Input _frac : uint32 */
/* Input _exp : uint8 */
/* Return   : uint32 */
#define SINGLE_SET_NEG(_frac, _exp)          (_frac + (_exp << 23) + (1 << 31))

/* Input _u : uint32 */
/* Return   : float32 */
#define SINGLE_SET_U32(_u)                   (*(float32 *)(&(_u)))

#endif /* _ACTEMS_SINGLE_H_ */

