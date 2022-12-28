/**
 * @file     mul.h
 * @brief    This file contains macro definitions and function declarations for multiplication with 64-bit values.
 * @since    2000-01-24
 * @author   Dagmar Andoleit, Klaus Goebel
 *
 * Note:
 *   C macro names begin with "C__" and C function names begin with "F__".
 *   The macro/function name represents the implemented operation:
 *	   Syntax: (C__|F__) + <result type> + <OPERATION> + <input type 1> + <input type 2>
 *
 *   The result:
 *    The macro's parameter list contains the parameters r_h and r_l.
 *    These variables contain the calculation result and the macro has no return
 *    value. Those macros must not be used inside expressions!
 *
 *
 *   The parameters are classified with three keywords.
 *
 *    Parameter  Description                    Properties
 *    --------------------------------------------------------------------------
 *    f1         first input                    rVars,  NoConsts, ComplexExpr
 *    f2         second input                   rVars,  NoConsts, ComplexExpr
 *    f1_h       upper part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
 *    f1_l       lower part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
 *    r_h        upper part of a 64-bit output  wVars,  NoConsts, NoComplexExpr
 *    r_l        lower part of a 64-bit output  wVars,  NoConsts, NoComplexExpr
 * 
 * Contents:
 *   F__I64MULI64I32()
 *   F__U64MULI64I32()
 *   F__I64MULI64U32()
 *   F__U64MULI64U32()
 *   F__I64MULU64I32()
 *   F__U64MULU64I32()
 *   F__I64MULU64U32()
 *   F__U64MULU64U32()
 *   C__I64MULI64I32()
 *   C__U64MULI64I32()
 *   C__I64MULI64U32()
 *   C__U64MULI64U32()
 *   C__I64MULU64I32()
 *   C__U64MULU64I32()
 *   C__I64MULU64U32()
 *   C__U64MULU64U32()
 *
 *   F__I64MULI32I32()
 *   F__U64MULI32I32()
 *   F__I64MULI32U32()
 *   F__U64MULI32U32()
 *   F__I64MULU32I32()
 *   F__U64MULU32I32()
 *   F__I64MULU32U32()
 *   F__U64MULU32U32()
 *   C__I64MULI32I32()
 *   C__U64MULI32I32()
 *   C__I64MULI32U32()
 *   C__U64MULI32U32()
 *   C__I64MULU32I32()
 *   C__U64MULU32I32()
 *   C__I64MULU32U32()
 *   C__U64MULU32U32() 
 *
 * Copyright (c) 2006 by dSPACE GmbH, Paderborn, Germany
 * All Rights Reserved
 */

/*
 * $RCSfile: mul.h $
 * $Revision: 1.4 $
 * $Date: 2006/10/31 14:45:16GMT+01:00 $
 */

#ifndef __mul_h__
#define __mul_h__

/* By default, Dynamique multiplication are done on 64bits */
#if  defined(PSA_F__I64MULI32I32_64BITS_SC) || defined(PSA_F__I64MULI32U32_64BITS_SC) || defined(PSA_F__U64MULI32I32_64BITS_SC) || defined(PSA_F__U64MULU32U32_64BITS_SC)
typedef unsigned long long       PSA_UInt64;
typedef signed long long         PSA_SInt64;
#endif



/******************************************************************************
*
* signed multiplication 64 x 32 with 64 bit result
*
******************************************************************************/

/******************************************************************************
*
* FUNCTION:
*   void F__I64MULI64I32(Int32 f1_h, UInt32 f1_l, Int32 f2, Int32 *r_h, UInt32 *r_l)
*   void F__U64MULI64I32(Int32 f1_h, UInt32 f1_l, Int32 f2, UInt32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__I64MULI64I32(f1_h, f1_l, f2, r_h, r_l)
*   C__U64MULI64I32(f1_h, f1_l, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   Int32    f1_h    1. factor (high-part)
*   UInt32   f1_l    1. factor (low-part)
*   Int32    f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input values are used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   The macro C__I64MULI64I32 contains the same algorithm as the function F__I64MULI64I32(..)
*   The macro C__U64MULI64I32 contains the same algorithm as the function F__U64MULI64I32(..)
*
******************************************************************************/
void F__I64MULI64I32(Int32 f1_h, UInt32 f1_l, Int32 f2, Int32 *r_h, UInt32 *r_l);

void F__U64MULI64I32(Int32 f1_h, UInt32 f1_l, Int32 f2, UInt32 *r_h, UInt32 *r_l);


#define C__I64MULI64I32(f1_h, f1_l, f2, r_h, r_l)\
{\
  UInt16 f1_hH,f1_hL,f1_lH,f1_lL,f2H,f2L;\
  UInt32 f1_lHf2H,f1_lLf2H,f1_lLf2L,temp;\
\
  f1_hH = (UInt16)((UInt32)f1_h >> 16);\
  f1_hL = (UInt16)f1_h;\
  f1_lH = (UInt16)((UInt32)f1_l >> 16);\
  f1_lL = (UInt16)f1_l;\
  f2H   = (UInt16)((UInt32)f2 >> 16);\
  f2L   = (UInt16)f2;\
\
  f1_lHf2H = (UInt32)f1_lH * (UInt32)f2H;\
  f1_lLf2H = (UInt32)f1_lL * (UInt32)f2H;\
  f1_lLf2L = (UInt32)f1_lL * (UInt32)f2L;\
\
  temp = f1_lLf2H + ((UInt32)f1_lH*(UInt32)f2L);\
  if(temp < f1_lLf2H) f1_lHf2H += 0x10000;\
  f1_lLf2H = temp + (f1_lLf2L >> 16);\
  if(f1_lLf2H < temp) f1_lHf2H += 0x10000;\
\
  r_h = (Int32)( (((UInt32)f1_hL*(UInt32)f2H) << 16) + f1_lHf2H +\
        (((UInt32)f1_hH*(UInt32)f2L) << 16) + ((UInt32)f1_hL*(UInt32)f2L) +\
        (f1_lLf2H >> 16) );\
  if(f2 < 0) r_h -= f1_l;\
  r_l = (UInt32)( (f1_lLf2H << 16) + (f1_lLf2L & 0x0000FFFF) );\
}/*END C__I64MULI64I32()*/

#define C__U64MULI64I32(f1_h, f1_l, f2, r_h, r_l)\
{\
  UInt16 f1_hH,f1_hL,f1_lH,f1_lL,f2H,f2L;\
  UInt32 f1_lHf2H,f1_lLf2H,f1_lLf2L,temp;\
\
  f1_hH = (UInt16)((UInt32)f1_h >> 16);\
  f1_hL = (UInt16)f1_h;\
  f1_lH = (UInt16)((UInt32)f1_l >> 16);\
  f1_lL = (UInt16)f1_l;\
  f2H   = (UInt16)((UInt32)f2 >> 16);\
  f2L   = (UInt16)f2;\
\
  f1_lHf2H = (UInt32)f1_lH * (UInt32)f2H;\
  f1_lLf2H = (UInt32)f1_lL * (UInt32)f2H;\
  f1_lLf2L = (UInt32)f1_lL * (UInt32)f2L;\
\
  temp = f1_lLf2H + ((UInt32)f1_lH*(UInt32)f2L);\
  if(temp < f1_lLf2H) f1_lHf2H += 0x10000;\
  f1_lLf2H = temp + (f1_lLf2L >> 16);\
  if(f1_lLf2H < temp) f1_lHf2H += 0x10000;\
\
  r_h = (UInt32)( (((UInt32)f1_hL*(UInt32)f2H) << 16) + f1_lHf2H +\
        (((UInt32)f1_hH*(UInt32)f2L) << 16) + ((UInt32)f1_hL*(UInt32)f2L) +\
        (f1_lLf2H >> 16) );\
  if(f2 < 0) r_h -= f1_l;\
  r_l = (UInt32)( (f1_lLf2H << 16) + (f1_lLf2L & 0x0000FFFF) );\
}/*END C__U64MULI64I32()*/


/******************************************************************************
*
* mixed multiplication 64 x 32 with 64 bit result
*
******************************************************************************/

/******************************************************************************
*
* FUNCTION:
*   void F__I64MULI64U32(Int32 f1_h, UInt32 f1_l, UInt32 f2, Int32 *r_h, UInt32 *r_l)
*   void F__U64MULI64U32(Int32 f1_h, UInt32 f1_l, UInt32 f2, UInt32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__I64MULI64U32(f1_h, f1_l, f2, r_h, r_l)
*   C__U64MULI64U32(f1_h, f1_l, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   Int32    f1_h    1. factor (high-part)
*   UInt32   f1_l    1. factor (low-part)
*   UInt32   f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input values are used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   The macro C__I64MULI64U32 contains the same algorithm as the function F__I64MULI64U32(..)
*   The macro C__U64MULI64U32 contains the same algorithm as the function F__U64MULI64U32(..)
*
******************************************************************************/
void F__I64MULI64U32(Int32 f1_h, UInt32 f1_l, UInt32 f2, Int32 *r_h, UInt32 *r_l);

void F__U64MULI64U32(Int32 f1_h, UInt32 f1_l, UInt32 f2, UInt32 *r_h, UInt32 *r_l);


#define C__I64MULI64U32(f1_h, f1_l, f2, r_h, r_l)\
{\
  UInt16 f1_hH,f1_hL,f1_lH,f1_lL,f2H,f2L;\
  UInt32 f1_lHf2H,f1_lLf2H,f1_lLf2L,temp;\
\
  f1_hH = (UInt16)((UInt32)f1_h >> 16);\
  f1_hL = (UInt16)f1_h;\
  f1_lH = (UInt16)((UInt32)f1_l >> 16);\
  f1_lL = (UInt16)f1_l;\
  f2H   = (UInt16)((UInt32)f2 >> 16);\
  f2L   = (UInt16)f2;\
\
  f1_lHf2H = (UInt32)f1_lH * (UInt32)f2H;\
  f1_lLf2H = (UInt32)f1_lL * (UInt32)f2H;\
  f1_lLf2L = (UInt32)f1_lL * (UInt32)f2L;\
\
  temp = f1_lLf2H + ((UInt32)f1_lH*(UInt32)f2L);\
  if(temp < f1_lLf2H) f1_lHf2H += 0x10000;\
  f1_lLf2H = temp + (f1_lLf2L >> 16);\
  if(f1_lLf2H < temp) f1_lHf2H += 0x10000;\
\
  r_l = (UInt32)( (f1_lLf2H << 16) + (f1_lLf2L & 0x0000FFFF) );\
  r_h = (Int32)( (((UInt32)f1_hL*(UInt32)f2H) << 16) + f1_lHf2H +\
         (((UInt32)f1_hH*(UInt32)f2L) << 16) + ((UInt32)f1_hL*(UInt32)f2L) +\
         (f1_lLf2H >> 16) );\
}/*END C__I64MULI64U32()*/

#define C__U64MULI64U32(f1_h, f1_l, f2, r_h, r_l)\
{\
  UInt16 f1_hH,f1_hL,f1_lH,f1_lL,f2H,f2L;\
  UInt32 f1_lHf2H,f1_lLf2H,f1_lLf2L,temp;\
\
  f1_hH = (UInt16)((UInt32)f1_h >> 16);\
  f1_hL = (UInt16)f1_h;\
  f1_lH = (UInt16)((UInt32)f1_l >> 16);\
  f1_lL = (UInt16)f1_l;\
  f2H   = (UInt16)((UInt32)f2 >> 16);\
  f2L   = (UInt16)f2;\
\
  f1_lHf2H = (UInt32)f1_lH * (UInt32)f2H;\
  f1_lLf2H = (UInt32)f1_lL * (UInt32)f2H;\
  f1_lLf2L = (UInt32)f1_lL * (UInt32)f2L;\
\
  temp = f1_lLf2H + ((UInt32)f1_lH*(UInt32)f2L);\
  if(temp < f1_lLf2H) f1_lHf2H += 0x10000;\
  f1_lLf2H = temp + (f1_lLf2L >> 16);\
  if(f1_lLf2H < temp) f1_lHf2H += 0x10000;\
\
  r_l = (UInt32)( (f1_lLf2H << 16) + (f1_lLf2L & 0x0000FFFF) );\
  r_h = (UInt32)( (((UInt32)f1_hL*(UInt32)f2H) << 16) + f1_lHf2H +\
         (((UInt32)f1_hH*(UInt32)f2L) << 16) + ((UInt32)f1_hL*(UInt32)f2L) +\
         (f1_lLf2H >> 16) );\
}/*END C__U64MULI64U32()*/


/******************************************************************************
*
* FUNCTION:
*   void F__I64MULU64I32(UInt32 f1_h, UInt32 f1_l, Int32 f2, Int32 *r_h, UInt32 *r_l)
*   void F__U64MULU64I32(UInt32 f1_h, UInt32 f1_l, Int32 f2, UInt32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__I64MULU64I32(f1_h, f1_l, f2, r_h, r_l)
*   C__U64MULU64I32(f1_h, f1_l, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   UInt32   f1_h    1. factor (high-part)
*   UInt32   f1_l    1. factor (low-part)
*   Int32    f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input values are used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   The macro C__I64MULU64I32 contains the same algorithm as the function F__I64MULU64I32(..)
*   The macro C__U64MULU64I32 contains the same algorithm as the function F__U64MULU64I32(..)
*
******************************************************************************/
#define F__I64MULU64I32(f1_h, f1_l, f2, r_h, r_l)\
    F__I64MULI64I32((Int32)f1_h, f1_l, f2, r_h, r_l)
/*END F__I64MULU64I32()*/

#define F__U64MULU64I32(f1_h, f1_l, f2, r_h, r_l)\
    F__U64MULI64I32((Int32)f1_h, f1_l, f2, r_h, r_l)
/*END F__U64MULU64I32()*/


#define C__I64MULU64I32(f1_h, f1_l, f2, r_h, r_l)\
    C__I64MULI64I32((Int32)f1_h, f1_l, f2, r_h, r_l)
/*END C__I64MULU64I32()*/

#define C__U64MULU64I32(f1_h, f1_l, f2, r_h, r_l)\
    C__U64MULI64I32((Int32)f1_h, f1_l, f2, r_h, r_l)
/*END C__U64MULU64I32()*/


/******************************************************************************
*
* unsigned multiplication 64 x 32 with 64 bit result
*
******************************************************************************/

/******************************************************************************
*
* FUNCTION:
*   void F__U64MULU64U32(UInt32 f1_h, UInt32 f1_l UInt32 f2, UInt32 *r_h, UInt32 *r_l)
*   void F__I64MULU64U32(UInt32 f1_h, UInt32 f1_l UInt32 f2, Int32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__U64MULU64U32(f1_h, f1_l, f2, r_h, r_l)
*   C__I64MULU64U32(f1_h, f1_l, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   UInt32   f1_h    1. factor (high-part)
*   UInt32   f1_l    1. factor (low-part)
*   UInt32   f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   This macro contains the same algorithm as the function F__U64MULU64U32(..)
*
******************************************************************************/
void F__U64MULU64U32(UInt32 f1_h, UInt32 f1_l, UInt32 f2, UInt32 *r_h, UInt32 *r_l);

#define F__I64MULU64U32(f1_h, f1_l, f2, r_h, r_l)\
    F__I64MULI64U32((Int32)(f1_h), f1_l, f2, r_h, r_l)
/*END F__I64MULU64U32()*/


#define C__U64MULU64U32(f1_h, f1_l, f2, r_h, r_l)\
{\
  UInt16 f1_hH,f1_hL,f1_lH,f1_lL,f2H,f2L;\
  UInt32 f1_lHf2H,f1_lLf2H,f1_lLf2L,temp;\
\
  f1_hH = (UInt16)((UInt32)f1_h >> 16);\
  f1_hL = (UInt16)f1_h;\
  f1_lH = (UInt16)((UInt32)f1_l >> 16);\
  f1_lL = (UInt16)f1_l;\
  f2H   = (UInt16)((UInt32)f2 >> 16);\
  f2L   = (UInt16)f2;\
\
  f1_lHf2H = (UInt32)f1_lH * (UInt32)f2H;\
  f1_lLf2H = (UInt32)f1_lL * (UInt32)f2H;\
  f1_lLf2L = (UInt32)f1_lL * (UInt32)f2L;\
\
  temp = f1_lLf2H + ((UInt32)f1_lH*(UInt32)f2L);\
  if(temp < f1_lLf2H) f1_lHf2H += 0x10000;\
  f1_lLf2H = temp + (f1_lLf2L >> 16);\
  if(f1_lLf2H < temp) f1_lHf2H += 0x10000;\
\
  r_l = (UInt32)( (f1_lLf2H << 16) + (f1_lLf2L & 0x0000FFFF) );\
  r_h = (UInt32)( (((UInt32)f1_hL*(UInt32)f2H) << 16) + f1_lHf2H +\
         (((UInt32)f1_hH*(UInt32)f2L) << 16) + ((UInt32)f1_hL*(UInt32)f2L) +\
         (f1_lLf2H >> 16) );\
}/*END C__U64MULU64U32()*/

#define C__I64MULU64U32(f1_h, f1_l, f2, r_h, r_l)\
    C__I64MULI64U32((Int32)f1_h, f1_l, f2, r_h, r_l)
/*END C__I64MULU64U32()*/


/******************************************************************************
*
* signed multiplication 32 x 32 with 64 bit result
*
******************************************************************************/

/******************************************************************************
*
* FUNCTION:
*   void F__I64MULI32I32(Int32 f1, Int32 f2, Int32 *r_h, UInt32 *r_l)
*   void F__U64MULI32I32(Int32 f1, Int32 f2, UInt32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__I64MULI32I32(f1, f2, r_h, r_l)
*   C__U64MULI32I32(f1, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   Int32    f1      1. factor
*   Int32    f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   This macro contains the same algorithm as the function F__I64MULI32I32(..)
*
******************************************************************************/
void F__I64MULI32I32(Int32 f1, Int32 f2, Int32 *r_h, UInt32 *r_l);

void F__U64MULI32I32(Int32 f1, Int32 f2, UInt32 *r_h, UInt32 *r_l);


#define C__I64MULI32I32(f1, f2, r_h, r_l)\
{\
  UInt16 f1L, /* low-part of f1 */\
         f2L, /* low-part of f2 */\
         f1H, /* high-part of f1 */\
         f2H; /* high-part of f2 */\
  UInt32 temp,f1Lf2L,f1Hf2L,f1Hf2H;\
\
  f1L = (UInt16)f1;\
  f2L = (UInt16)f2;\
  f1H = (UInt16)((UInt32)f1 >> 16);\
  f2H = (UInt16)((UInt32)f2 >> 16);\
\
  f1Lf2L = (UInt32)f1L * (UInt32)f2L; /* convenient multiplication */\
  f1Hf2L = (UInt32)f1H * (UInt32)f2L;\
  f1Hf2H = (UInt32)f1H * (UInt32)f2H;\
  /* add the pieces */\
  temp   = f1Hf2L + (f1Lf2L>>16);\
  /* mid = temp + f1Lf2H */\
  f1Hf2L = temp + (UInt32)f1L * (UInt32)f2H;\
  if(f1Hf2L < temp) f1Hf2H += 0x10000; /* high-part + carry */\
\
  r_l  = (UInt32)( (f1Hf2L<<16) + (f1Lf2L & 0x0000FFFF) ); /* low of f1Hf2L */\
  r_h  = (Int32)( f1Hf2H + (f1Hf2L>>16) );\
\
  if(f1<0) r_h -= f2; /* Booth-algorithm */\
  if(f2<0) r_h -= f1;\
}/*END C__I64MULI32I32()*/

#define C__U64MULI32I32(f1, f2, r_h, r_l)\
{\
  UInt16 f1L, /* low-part of f1 */\
         f2L, /* low-part of f2 */\
         f1H, /* high-part of f1 */\
         f2H; /* high-part of f2 */\
  UInt32 temp,f1Lf2L,f1Hf2L,f1Hf2H;\
\
  f1L = (UInt16)f1;\
  f2L = (UInt16)f2;\
  f1H = (UInt16)((UInt32)f1 >> 16);\
  f2H = (UInt16)((UInt32)f2 >> 16);\
\
  f1Lf2L = (UInt32)f1L * (UInt32)f2L; /* convenient multiplication */\
  f1Hf2L = (UInt32)f1H * (UInt32)f2L;\
  f1Hf2H = (UInt32)f1H * (UInt32)f2H;\
  /* add the pieces */\
  temp   = f1Hf2L + (f1Lf2L>>16);\
  /* mid = temp + f1Lf2H */\
  f1Hf2L = temp + (UInt32)f1L * (UInt32)f2H;\
  if(f1Hf2L < temp) f1Hf2H += 0x10000; /* high-part + carry */\
\
  r_l  = (UInt32)( (f1Hf2L<<16) + (f1Lf2L & 0x0000FFFF) ); /* low of f1Hf2L */\
  r_h  = (UInt32)( f1Hf2H + (f1Hf2L>>16) );\
\
  if(f1<0) r_h -= f2; /* Booth-algorithm */\
  if(f2<0) r_h -= f1;\
}/*END C__U64MULI32I32()*/


/******************************************************************************
*
* mixed multiplication 32 x 32 with 64 bit result
*
******************************************************************************/

/******************************************************************************
*
* FUNCTION:
*   void F__I64MULI32U32(Int32 f1, UInt32 f2, Int32 *r_h, UInt32 *r_l)
*   void F__U64MULI32U32(Int32 f1, UInt32 f2, UInt32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__I64MULI32U32(f1, f2, r_h, r_l)
*   C__U64MULI32U32(f1, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   Int32    f1      1. factor
*   UInt32   f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   This macro contains the same algorithm as the function F__I64MULI32U32(..)
*
******************************************************************************/
void F__I64MULI32U32(Int32 f1, UInt32 f2, Int32 *r_h, UInt32 *r_l);

void F__U64MULI32U32(Int32 f1, UInt32 f2, UInt32 *r_h, UInt32 *r_l);


#define C__I64MULI32U32(f1, f2, r_h, r_l)\
{\
  UInt16 f1L, /* low-part of f1  */\
         f2L, /* low-part of f2  */\
         f1H, /* high-part of f1 */\
         f2H; /* high-part of f2 */\
  UInt32 temp,f1Lf2L,f1Hf2L,f1Hf2H;\
\
  f1L = (UInt16)f1;\
  f2L = (UInt16)f2;\
  f1H = (UInt16) ( (UInt32)f1 >> 16 );\
  f2H = (UInt16) ( f2 >> 16 );\
\
  f1Lf2L = (UInt32)f1L * (UInt32)f2L; /* convenient multiplication */\
  f1Hf2L = (UInt32)f1H * (UInt32)f2L;\
  f1Hf2H = (UInt32)f1H * (UInt32)f2H;\
  /* add the pieces */\
  temp   = f1Hf2L + (f1Lf2L>>16);\
  /* mid = temp + f1Lf2H */\
  f1Hf2L = temp + (UInt32)f1L * (UInt32)f2H;\
  if(f1Hf2L < temp) f1Hf2H += 0x10000; /* high-part + carry */\
\
  r_l  = (UInt32)( (f1Hf2L<<16) + (f1Lf2L & 0x0000FFFF) ); /* low of f1Hf2L */\
  r_h  = (Int32)( f1Hf2H + (f1Hf2L>>16) );\
\
  if(f1<0) r_h -= f2; /* Booth-algorithm */\
}/*END C__I64MULI32U32()*/

#define C__U64MULI32U32(f1, f2, r_h, r_l)\
{\
  UInt16 f1L, /* low-part of f1  */\
         f2L, /* low-part of f2  */\
         f1H, /* high-part of f1 */\
         f2H; /* high-part of f2 */\
  UInt32 temp,f1Lf2L,f1Hf2L,f1Hf2H;\
\
  f1L = (UInt16)f1;\
  f2L = (UInt16)f2;\
  f1H = (UInt16) ( (UInt32)f1 >> 16 );\
  f2H = (UInt16) ( f2 >> 16 );\
\
  f1Lf2L = (UInt32)f1L * (UInt32)f2L; /* convenient multiplication */\
  f1Hf2L = (UInt32)f1H * (UInt32)f2L;\
  f1Hf2H = (UInt32)f1H * (UInt32)f2H;\
  /* add the pieces */\
  temp   = f1Hf2L + (f1Lf2L>>16);\
  /* mid = temp + f1Lf2H */\
  f1Hf2L = temp + (UInt32)f1L * (UInt32)f2H;\
  if(f1Hf2L < temp) f1Hf2H += 0x10000; /* high-part + carry */\
\
  r_l  = (UInt32)( (f1Hf2L<<16) + (f1Lf2L & 0x0000FFFF) ); /* low of f1Hf2L */\
  r_h  = (UInt32)( f1Hf2H + (f1Hf2L>>16) );\
\
  if(f1<0) r_h -= f2; /* Booth-algorithm */\
}/*END C__U64MULI32U32()*/


/******************************************************************************
*
* FUNCTION:
*   void F__I64MULU32I32(Int32 f1, UInt32 f2, Int32 *r_h, UInt32 *r_l)
*   void F__U64MULU32I32(Int32 f1, UInt32 f2, UInt32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__I64MULU32I32(f1, f2, r_h, r_l)
*   C__U64MULU32I32(f1, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   typ      name    meaning
*   UInt32   f1      1. factor
*   Int32    f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   This macro contains the same algorithm as the function F__I64MULI32U32(..)
*
******************************************************************************/
#define F__I64MULU32I32(f1, f2, r_h, r_l)\
    F__I64MULI32U32(f2, f1, r_h, r_l)

#define F__U64MULU32I32(f1, f2, r_h, r_l)\
    F__U64MULI32U32(f2, f1, r_h, r_l)


#define C__I64MULU32I32(f1, f2, r_h, r_l)\
    C__I64MULI32U32(f2, f1, r_h, r_l)

#define C__U64MULU32I32(f1, f2, r_h, r_l)\
    C__U64MULI32U32(f2, f1, r_h, r_l)


/******************************************************************************
*
* unsigned multiplication 32 x 32 with 64 bit result
*
******************************************************************************/

/******************************************************************************
*
* FUNCTION:
*   void F__U64MULU32U32(UInt32 f1, UInt32 f2, UInt32 *r_h, UInt32 *r_l)
*   void F__I64MULU32U32(UInt32 f1, UInt32 f2, Int32 *r_h, UInt32 *r_l)
*
* MACRO:
*   C__U64MULU32U32(f1, f2, r_h, r_l)
*   C__I64MULU32U32(f1, f2, r_h, r_l)
*
* DESCRIPTION:
*   Multiplies f1 by f2 with 64bit result.
*
* PARAMETERS:
*   type     name    meaning
*   UInt32   f1      1. factor
*   UInt32   f2      2. factor
*   xInt32   r_h     64bit - result (high-part)
*   UInt32   r_l     64bit - result (low-part)
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call.
*   This macro contains the same algorithm as the function F__U64MULU32U32(..)
*
******************************************************************************/
void F__U64MULU32U32(UInt32 f1, UInt32 f2, UInt32 *r_h, UInt32 *r_l);

void F__I64MULU32U32(UInt32 f1, UInt32 f2, Int32 *r_h, UInt32 *r_l);


#define C__U64MULU32U32(f1, f2, r_h, r_l)\
{\
  UInt16 f1L, /* low-part of f1  */\
         f2L, /* low-part of f2  */\
         f1H, /* high-part of f1 */\
         f2H; /* high-part of f2 */\
  UInt32  temp,f1Lf2L,f1Hf2L,f1Hf2H;\
\
  f1L = (UInt16)f1;\
  f2L = (UInt16)f2;\
  f1H = (UInt16) ( f1 >> 16 );\
  f2H = (UInt16) ( f2 >> 16 );\
\
  f1Lf2L = (UInt32)f1L * (UInt32)f2L; /* convenient multiplication */\
  f1Hf2L = (UInt32)f1H * (UInt32)f2L;\
  f1Hf2H = (UInt32)f1H * (UInt32)f2H;\
  /* add the pieces */\
  temp   = f1Hf2L + (f1Lf2L>>16);\
  /* mid = temp + f1Lf2H */\
  f1Hf2L = temp + (UInt32)f1L * (UInt32)f2H;\
  if(f1Hf2L < temp) f1Hf2H += 0x10000; /* high-part + carry */\
\
  r_l  = (UInt32)( (f1Hf2L<<16) + (f1Lf2L & 0x0000FFFF) ); /* low of f1Hf2L */\
  r_h  = (UInt32)(  f1Hf2H      + (f1Hf2L>>16) );\
}/*END C__U64MULU32U32()*/

#define C__I64MULU32U32(f1, f2, r_h, r_l)\
{\
  UInt16 f1L, /* low-part of f1  */\
         f2L, /* low-part of f2  */\
         f1H, /* high-part of f1 */\
         f2H; /* high-part of f2 */\
  UInt32  temp,f1Lf2L,f1Hf2L,f1Hf2H;\
\
  f1L = (UInt16)f1;\
  f2L = (UInt16)f2;\
  f1H = (UInt16) ( f1 >> 16 );\
  f2H = (UInt16) ( f2 >> 16 );\
\
  f1Lf2L = (UInt32)f1L * (UInt32)f2L; /* convenient multiplication */\
  f1Hf2L = (UInt32)f1H * (UInt32)f2L;\
  f1Hf2H = (UInt32)f1H * (UInt32)f2H;\
  /* add the pieces */\
  temp   = f1Hf2L + (f1Lf2L>>16);\
  /* mid = temp + f1Lf2H */\
  f1Hf2L = temp + (UInt32)f1L * (UInt32)f2H;\
  if(f1Hf2L < temp) f1Hf2H += 0x10000; /* high-part + carry */\
\
  r_l  = (UInt32)( (f1Hf2L<<16) + (f1Lf2L & 0x0000FFFF) ); /* low of f1Hf2L */\
  r_h  = (Int32) (  f1Hf2H      + (f1Hf2L>>16) );\
}/*END C__I64MULU32U32()*/


#endif /* #ifndef __mul_h__ */
