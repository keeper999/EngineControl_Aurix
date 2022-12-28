/******************************************************************************
*
* FILE:
*   sat.h
*
* RELATED FILES:
*
* DESCRIPTION:
*   This file contains macro definitions for the operation Saturation.
*
*   The following applies to all macros:
*   ------------------------------------
*
*   The macro name represents the implemented operation:
*     C__<output_type><operation><input_type>[_SAT{b|l|u}]
*
*     input_type : U8, U16, U32, U64, I8, I16, I32, I64
*     output_type: U8, U16, U32,      I8, I16, I32
*     operation  : SAT
*
*
*   The result:
*    All macros have a return value.
*
*
*   The parameters are classified with three keywords.
*
*    Parameter  Description                    Properties
*    --------------------------------------------------------------------------
*    v          input                          rVars,  NoConsts, NoComplexExpr  
*    v_h        upper part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
*    v_l        lower part of a 64-bit input   rVars,  NoConsts, NoComplexExpr  
*    upsatval   const upper input limit        rVars,  Consts,   NoComplexExpr    
*    losatval   const lower input limit        rVars,  Consts,   NoComplexExpr    
*
*
*  AUTHOR(S):
*    D. Andoleit
*
*  Copyright (c) 1999 dSPACE GmbH, GERMANY
*
*  $Workfile: sat.h $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:51GMT+01:00 $ $Author: FrankL $
******************************************************************************/

#ifndef __sat_h__
#define __sat_h__


/******************************************************************************
*
* MACROS:
*   Int32  C__I32SATI64_SAT(v_h, v_l, upsatval, losatval)
*   Int32  C__I32SATU64_SAT(v_h, v_l, upsatval, losatval)
*   UInt32 C__U32SATI64_SAT(v_h, v_l, upsatval, losatval)
*   UInt32 C__U32SATU64_SAT(v_h, v_l, upsatval, losatval)
*
*   Int16  C__I16SATI64_SAT(v_h, v_l, upsatval, losatval)
*   Int16  C__I16SATU64_SAT(v_h, v_l, upsatval, losatval)
*   UInt16 C__U16SATI64_SAT(v_h, v_l, upsatval, losatval)
*   UInt16 C__U16SATU64_SAT(v_h, v_l, upsatval, losatval)
*
*   Int8   C__I8SATI64_SAT(v_h, v_l, upsatval, losatval)
*   Int8   C__I8SATU64_SAT(v_h, v_l, upsatval, losatval)
*   UInt8  C__U8SATI64_SAT(v_h, v_l, upsatval, losatval)
*   UInt8  C__U8SATU64_SAT(v_h, v_l, upsatval, losatval)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*   clearly arranged code of this macro:
*           if(v > upsatval) r = upsatval;
*           else if(v < losatval) r = losatval;
*           else r = v ;
*
******************************************************************************/
#define C__I32SATI64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > (Int32)(upsatval >> 31))||((v_h == (Int32)(upsatval >> 31))&&\
      (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( ( (v_h < (Int32)(losatval >> 31))||((v_h == (Int32)(losatval >> 31))&&\
      (v_l < (UInt32)losatval)) ) ? losatval : (Int32)v_l) )
#define C__I32SATI64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > (Int32)(upsatval >> 31))||((v_h == (Int32)(upsatval >> 31))&&\
      (v_l > (UInt32)upsatval)) ) ? upsatval : (Int32)v_l )
#define C__I32SATI64_SATl(v_h, v_l, losatval)\
    ( ( (v_h < (Int32)(losatval >> 31))||((v_h == (Int32)(losatval >> 31))&&\
      (v_l < (UInt32)losatval)) ) ? losatval : (Int32)v_l )
#define C__I16SATI64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > (Int32)(upsatval >> 15))||((v_h == (Int32)(upsatval >> 15))&&\
      (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( ( (v_h < (Int32)(losatval >> 15))||((v_h == (Int32)(losatval >> 15))&&\
      (v_l < (UInt32)losatval)) ) ? losatval : (Int16)v_l) )
#define C__I16SATI64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > (Int32)(upsatval >> 15))||((v_h == (Int32)(upsatval >> 15))&&\
      (v_l > (UInt32)upsatval)) ) ? upsatval : (Int16)v_l )
#define C__I16SATI64_SATl(v_h, v_l, losatval)\
    ( ( (v_h < (Int32)(losatval >> 15))||((v_h == (Int32)(losatval >> 15))&&\
      (v_l < (UInt32)losatval)) ) ? losatval : (Int16)v_l )
#define C__I8SATI64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > (Int32)(upsatval >> 7))||((v_h == (Int32)(upsatval >> 7))&&\
      (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( ( (v_h < (Int32)(losatval >> 7))||((v_h == (Int32)(losatval >> 7))&&\
      (v_l < (UInt32)losatval)) ) ? losatval : (Int8)v_l) )
#define C__I8SATI64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > (Int32)(upsatval >> 7))||((v_h == (Int32)(upsatval >> 7))&&\
      (v_l > (UInt32)upsatval)) ) ? upsatval : (Int8)v_l )
#define C__I8SATI64_SATl(v_h, v_l, losatval)\
    ( ( (v_h < (Int32)(losatval >> 7))||((v_h == (Int32)(losatval >> 7))&&\
      (v_l < (UInt32)losatval)) ) ? losatval : (Int8)v_l )
/* END C__IyySATI64_SAT() */

#define C__I32SATU64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > 0) || ((upsatval > 0) && (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( ((losatval > 0) && (v_l < (UInt32)losatval)) ? losatval : (Int32)v_l) )
#define C__I32SATU64_SATu(v_h, v_l, upsatval)\
    ((v_h > 0) || ((upsatval > 0) && (v_l > (UInt32)upsatval) ) ? upsatval : (Int32)v_l )
#define C__I32SATU64_SATl(v_h, v_l, losatval)\
    ( ((losatval > 0) && (v_l < (UInt32)losatval)) ? losatval : (Int32)v_l )
#define C__I16SATU64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > 0) || ((upsatval > 0) && (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( (v_l < (UInt32)losatval) ? losatval : (Int16)v_l) )
#define C__I16SATU64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > 0) || ((upsatval > 0) && (v_l > (UInt32)upsatval)) ) ? upsatval : (Int16)v_l )
#define C__I16SATU64_SATl(v_h, v_l, losatval)\
    ( ((losatval > 0) && (v_l < (UInt32)losatval)) ? losatval : (Int16)v_l )
#define C__I8SATU64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > 0) || ((upsatval > 0) && (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( (v_l < (UInt32)losatval) ? losatval : (Int8)v_l) )
#define C__I8SATU64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > 0) || ((upsatval > 0) && (v_l > (UInt32)upsatval)) ) ? upsatval : (Int8)v_l )
#define C__I8SATU64_SATl(v_h, v_l, losatval)\
    ( ((losatval > 0) && (v_l < (UInt32)losatval)) ? losatval : (Int8)v_l )
/* END C__IyySATU64_SAT() */

#define C__U32SATI64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > 0) || ((v_h == 0) && (v_l > upsatval)) ) ? upsatval :\
    ( ( (v_h < 0) || (v_l < losatval) ) ? losatval : v_l))
#define C__U32SATI64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > 0) || ((v_h == 0) && (v_l > upsatval)) ) ? upsatval : v_l )
#define C__U32SATI64_SATl(v_h, v_l, losatval)\
    ( ( (v_h < 0) || (v_l < losatval) ) ? losatval : v_l )
#define C__U16SATI64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > 0) || ((v_h == 0) && (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( ( (v_h < 0) || (v_l < (UInt32)losatval) ) ? losatval : (UInt16)v_l))
#define C__U16SATI64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > 0) || ((v_h == 0) && (v_l > (UInt32)upsatval)) ) ? upsatval : (UInt16)v_l )
#define C__U16SATI64_SATl(v_h, v_l, losatval)\
    ( ( (v_h < 0) || (v_l < (UInt32)losatval) ) ? losatval : (UInt16)v_l )
#define C__U8SATI64_SATb(v_h, v_l, upsatval, losatval)\
    ( ( (v_h > 0) || ((v_h == 0) && (v_l > (UInt32)upsatval)) ) ? upsatval :\
    ( ( (v_h < 0) || (v_l < (UInt32)losatval) ) ? losatval : (UInt8)v_l))
#define C__U8SATI64_SATu(v_h, v_l, upsatval)\
    ( ( (v_h > 0) || ((v_h == 0) && (v_l > (UInt32)upsatval)) ) ? upsatval : (UInt8)v_l )
#define C__U8SATI64_SATl(v_h, v_l, losatval)\
    ( ( (v_h < 0) || (v_l < (UInt32)losatval) ) ? losatval : (UInt8)v_l )
/* END C__UyySATI64_SAT() */

#define C__U32SATU64_SATb(v_h, v_l, upsatval, losatval)\
    ( ((v_h > 0) || (v_l > upsatval)) ? upsatval :\
    ( ((v_h == 0) && (v_l < losatval)) ? losatval : v_l ) )
#define C__U32SATU64_SATu(v_h, v_l, upsatval)\
    ( ((v_h > 0) || (v_l > upsatval)) ? upsatval : v_l )
#define C__U32SATU64_SATl(v_h, v_l, losatval)\
    ( ((v_h == 0) && (v_l < losatval)) ? losatval : v_l )
#define C__U16SATU64_SATb(v_h, v_l, upsatval, losatval)\
    ( ((v_h > 0) || (v_l > (UInt32)upsatval)) ? upsatval :\
    ( ((v_h == 0) && (v_l < (UInt32)losatval)) ? losatval : (UInt16)v_l ) )
#define C__U16SATU64_SATu(v_h, v_l, upsatval)\
    ( ((v_h > 0) || (v_l > (UInt32)upsatval)) ? upsatval : (UInt16)v_l )
#define C__U16SATU64_SATl(v_h, v_l, losatval)\
    ( ((v_h == 0) && (v_l < (UInt32)losatval)) ? losatval : (UInt16)v_l )
#define C__U8SATU64_SATb(v_h, v_l, upsatval, losatval)\
    ( ((v_h > 0) || (v_l > (UInt32)upsatval)) ? upsatval :\
    ( ((v_h == 0) && (v_l < (UInt32)losatval)) ? losatval : (UInt8)v_l ) )
#define C__U8SATU64_SATu(v_h, v_l, upsatval)\
    ( ((v_h > 0) || (v_l > (UInt32)upsatval)) ? upsatval : (UInt8)v_l )
#define C__U8SATU64_SATl(v_h, v_l, losatval)\
    ( ((v_h == 0) && (v_l < (UInt32)losatval)) ? losatval : (UInt8)v_l )
/* END C__UyySATU64_SAT() */

/******************************************************************************
*
* MACRO(s):
*   Int32  C__I32SATI32_SAT(v, upsatval, losatval)
*   UInt32 C__U32SATU32_SAT(v, upsatval, losatval)
*   Int16  C__I16SATI16_SAT(v, upsatval, losatval)
*   UInt16 C__U16SATU16_SAT(v, upsatval, losatval)
*   Int8   C__I8SATI8_SAT(v, upsatval, losatval)
*   UInt   C__U8SATU8_SAT(v, upsatval, losatval)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*   clearly arranged code of this macro:
*           if(v > upsatval) return upsatval;
*           else if(v < losatval) return losatval;
*           else return v ;
*
******************************************************************************/
#define C__I32SATI32_SATb(v, upsatval, losatval)\
    C__xzzSATxzz_SATb(v, upsatval, losatval)
#define C__I32SATI32_SATu(v, upsatval)\
    C__xzzSATxzz_SATu(v, upsatval)
#define C__I32SATI32_SATl(v, losatval)\
    C__xzzSATxzz_SATl(v, losatval)

#define C__U32SATU32_SATb(v, upsatval, losatval)\
    C__xzzSATxzz_SATb(v, upsatval, losatval)
#define C__U32SATU32_SATu(v, upsatval)\
    C__xzzSATxzz_SATu(v, upsatval)
#define C__U32SATU32_SATl(v, losatval)\
    C__xzzSATxzz_SATl(v, losatval)

#define C__I16SATI16_SATb(v, upsatval, losatval)\
    C__xzzSATxzz_SATb(v, upsatval, losatval)
#define C__I16SATI16_SATu(v, upsatval)\
    C__xzzSATxzz_SATu(v, upsatval)
#define C__I16SATI16_SATl(v, losatval)\
    C__xzzSATxzz_SATl(v, losatval)

#define C__U16SATU16_SATb(v, upsatval, losatval)\
    C__xzzSATxzz_SATb(v, upsatval, losatval)
#define C__U16SATU16_SATu(v, upsatval)\
    C__xzzSATxzz_SATu(v, upsatval)
#define C__U16SATU16_SATl(v, losatval)\
    C__xzzSATxzz_SATl(v, losatval)

#define C__I8SATI8_SATb(v, upsatval, losatval)\
    C__xzzSATxzz_SATb(v, upsatval, losatval)
#define C__I8SATI8_SATu(v, upsatval)\
    C__xzzSATxzz_SATu(v, upsatval)
#define C__I8SATI8_SATl(v, losatval)\
    C__xzzSATxzz_SATl(v, losatval)

#define C__U8SATU8_SATb(v, upsatval, losatval)\
    C__xzzSATxzz_SATb(v, upsatval, losatval)
#define C__U8SATU8_SATu(v, upsatval)\
    C__xzzSATxzz_SATu(v, upsatval)
#define C__U8SATU8_SATl(v, losatval)\
    C__xzzSATxzz_SATl(v, losatval)


#define C__xzzSATxzz_SATb(v, upsatval, losatval)\
    ( (v > upsatval) ? upsatval : ( (v < losatval) ? losatval : v ) )
#define C__xzzSATxzz_SATu(v, upsatval)\
    ( (v > upsatval) ? upsatval : v )
#define C__xzzSATxzz_SATl(v, losatval)\
    ( (v < losatval) ? losatval : v )

/******************************************************************************
*
* MACRO(s):
*   Int32  C__I32SATU32_SAT(v, upsatval, losatval)
*   UInt32 C__U32SATI32_SAT(v, upsatval, losatval)
*   Int16  C__I16SATU16_SAT(v, upsatval, losatval)
*   UInt16 C__U16SATI16_SAT(v, upsatval, losatval)
*   Int32  C__I32SATU32_SAT(v, upsatval, losatval)
*   UInt32 C__U32SATI32_SAT(v, upsatval, losatval)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*   clearly arranged code of this macro:
*           if(v > upsatval) return upsatval;
*           else if(v < losatval) return losatval;
*           else return v ;
*
******************************************************************************/
#define C__I32SATU32_SATb(v, upsatval, losatval)\
    ( ( (upsatval < 0) || (v > (UInt32)upsatval) ) ? upsatval :\
    ( ( ((losatval > 0) && (v < (UInt32)losatval)) ) ? losatval : (Int32)v ) )
#define C__I32SATU32_SATu(v, upsatval)\
    ( ( (upsatval < 0) || (v > (UInt32)upsatval) ) ? upsatval : (Int32)v )
#define C__I32SATU32_SATl(v, losatval)\
    ( ( ((losatval > 0) && (v < (UInt32)losatval)) ) ? losatval : (Int32)v )

#define C__U32SATI32_SATb(v, upsatval, losatval)\
    ( ( (v > 0) && ((UInt32)v > upsatval) ) ? upsatval :\
    ( ( (v < 0) || ((UInt32)v < losatval) ) ? losatval : (UInt32)v ) )
#define C__U32SATI32_SATu(v, upsatval)\
    ( ( (v > 0) && ((UInt32)v > upsatval) ) ? upsatval : (UInt32)v )
#define C__U32SATI32_SATl(v, losatval)\
    ( ( (v < 0) || ((UInt32)v < losatval) ) ? losatval : (UInt32)v )

#define C__I16SATU16_SATb(v, upsatval, losatval)\
    ( ( (upsatval < 0) || (v > (UInt16)upsatval) ) ? upsatval :\
    ( ( ((losatval > 0) && (v < (UInt16)losatval)) ) ? losatval : (Int16)v ) )
#define C__I16SATU16_SATu(v, upsatval)\
    ( ( (upsatval < 0) || (v > (UInt16)upsatval) ) ? upsatval : (Int16)v )
#define C__I16SATU16_SATl(v, losatval)\
    ( ( ((losatval > 0) && (v < (UInt16)losatval)) ) ? losatval : (Int16)v )

#define C__U16SATI16_SATb(v, upsatval, losatval)\
    ( ( (v > 0) && ((UInt16)v > upsatval) ) ? upsatval :\
    ( ( (v < 0) || ((UInt16)v < losatval) ) ? losatval : (UInt16)v ) )
#define C__U16SATI16_SATu(v, upsatval)\
    ( ( (v > 0) && ((UInt16)v > upsatval) ) ? upsatval : (UInt16)v )
#define C__U16SATI16_SATl(v, losatval)\
    ( ( (v < 0) || ((UInt16)v < losatval) ) ? losatval : (UInt16)v )

#define C__I8SATU8_SATb(v, upsatval, losatval)\
    ( ( (upsatval < 0) || (v > (UInt8)upsatval) ) ? upsatval :\
    ( ( ((losatval > 0) && (v < (UInt8)losatval)) ) ? losatval : (Int8)v ) )
#define C__I8SATU8_SATu(v, upsatval)\
    ( ( (upsatval < 0) || (v > (UInt8)upsatval) ) ? upsatval : (Int8)v )
#define C__I8SATU8_SATl(v, losatval)\
    ( ( ((losatval > 0) && (v < (UInt8)losatval)) ) ? losatval : (Int8)v )

#define C__U8SATI8_SATb(v, upsatval, losatval)\
    ( ( (v > 0) && ((UInt8)v > upsatval) ) ? upsatval :\
    ( ( (v < 0) || ((UInt8)v < losatval) ) ? losatval : (UInt8)v ) )
#define C__U8SATI8_SATu(v, upsatval)\
    ( ( (v > 0) && ((UInt8)v > upsatval) ) ? upsatval : (UInt8)v )
#define C__U8SATI8_SATl(v, losatval)\
    ( ( (v < 0) || ((UInt8)v < losatval) ) ? losatval : (UInt8)v )

/******************************************************************************
*
* MACRO(s):
*   Int16  C__I16SATI32_SAT(v, upsatval, losatval)
*   Int16  C__I16SATU32_SAT(v, upsatval, losatval)
*   UInt16 C__U16SATI32_SAT(v, upsatval, losatval)
*   UInt16 C__U16SATU32_SAT(v, upsatval, losatval)
*
*   Int8   C__I8SATI32_SAT(v, upsatval, losatval)
*   Int8   C__I8SATU32_SAT(v, upsatval, losatval)
*   UInt8  C__U8SATI32_SAT(v, upsatval, losatval)
*   UInt8  C__U8SATU32_SAT(v, upsatval, losatval)
*
*   Int8   C__I8SATI16_SAT(v, upsatval, losatval)
*   Int8   C__I8SATU16_SAT(v, upsatval, losatval)
*   UInt8  C__U8SATI16_SAT(v, upsatval, losatval)
*   UInt8  C__U8SATU16_SAT(v, upsatval, losatval)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*   clearly arranged code of this macro:
*           if(v > upsatval) return upsatval;
*           else if(v < losatval) return losatval;
*           else return v ;
*
******************************************************************************/
#define C__I16SATI32_SATb(v, upsatval, losatval)\
    ( (v > (Int32)upsatval) ? upsatval : ( (v < (Int32)losatval) ? losatval : (Int16)v ) )
#define C__I16SATI32_SATu(v, upsatval)\
    ( (v > (Int32)upsatval) ? upsatval : (Int16)v )
#define C__I16SATI32_SATl(v, losatval)\
    ( (v < (Int32)losatval) ? losatval : (Int16)v )

#define C__U16SATI32_SATb(v, upsatval, losatval)\
    ( (v > (Int32)upsatval) ? upsatval : ( (v < (Int32)losatval) ? losatval : (UInt16)v ) )
#define C__U16SATI32_SATu(v, upsatval)\
    ( (v > (Int32)upsatval) ? upsatval : (UInt16)v )
#define C__U16SATI32_SATl(v, losatval)\
    ( (v < (Int32)losatval) ? losatval : (UInt16)v )

#define C__I16SATU32_SATb(v, upsatval, losatval)\
    ( ((upsatval < 0) || (v > (UInt32)upsatval)) ? upsatval :\
    ( ((losatval > 0) && (v < (UInt32)losatval)) ? losatval : (Int16)v ) )
#define C__I16SATU32_SATu(v, upsatval)\
    (  ((upsatval < 0) || (v > (UInt32)upsatval)) ? upsatval : (Int16)v )
#define C__I16SATU32_SATl(v, losatval)\
    ( ((losatval > 0) && (v < (UInt32)losatval)) ? losatval : (Int16)v )

#define C__U16SATU32_SATb(v, upsatval, losatval)\
    ( (v > (UInt32)upsatval) ? upsatval : ( (v < (UInt32)losatval) ? losatval : (UInt16)v ) )
#define C__U16SATU32_SATu(v, upsatval)\
    ( (v > (UInt32)upsatval) ? upsatval : (UInt16)v )
#define C__U16SATU32_SATl(v, losatval)\
    ( (v < (UInt32)losatval) ? losatval : (UInt16)v )


#define C__I8SATI32_SATb(v, upsatval, losatval)\
    ( (v > (Int32)upsatval) ? upsatval : ( (v < (Int32)losatval) ? losatval : (Int8)v ) )
#define C__I8SATI32_SATu(v, upsatval)\
    ( (v > (Int32)upsatval) ? upsatval : (Int8)v )
#define C__I8SATI32_SATl(v, losatval)\
    ( (v < (Int32)losatval) ? losatval : (Int8)v )

#define C__I8SATU32_SATb(v, upsatval, losatval)\
    ( ((upsatval < 0) || (v > (UInt32)upsatval)) ? upsatval :\
    ( ((losatval > 0) && (v < (UInt32)losatval)) ? losatval : (Int8)v ) )
#define C__I8SATU32_SATu(v, upsatval)\
    ( ((upsatval < 0) || (v > (UInt32)upsatval)) ? upsatval : (Int8)v )
#define C__I8SATU32_SATl(v, losatval)\
    ( ((losatval > 0) && (v < (UInt32)losatval)) ? losatval : (Int8)v )

#define C__U8SATI32_SATb(v, upsatval, losatval)\
    ( (v > (Int32)upsatval) ? upsatval : ( (v < (Int32)losatval) ? losatval : (UInt8)v ) )
#define C__U8SATI32_SATu(v, upsatval)\
    ( (v > (Int32)upsatval) ? upsatval : (UInt8)v )
#define C__U8SATI32_SATl(v, losatval)\
    ( (v < (Int32)losatval) ? losatval : (UInt8)v )

#define C__U8SATU32_SATb(v, upsatval, losatval)\
    ( (v > (UInt32)upsatval) ? upsatval : ( (v < (UInt32)losatval) ? losatval : (UInt8)v ) )
#define C__U8SATU32_SATu(v, upsatval)\
    ( (v > (UInt32)upsatval) ? upsatval : (UInt8)v )
#define C__U8SATU32_SATl(v, losatval)\
    ( (v < (UInt32)losatval) ? losatval : (UInt8)v )


#define C__I8SATI16_SATb(v, upsatval, losatval)\
    ( (v > (Int16)upsatval) ? upsatval : ( (v < (Int16)losatval) ? losatval : (Int8)v ) )
#define C__I8SATI16_SATu(v, upsatval)\
    ( (v > (Int16)upsatval) ? upsatval : (Int8)v )
#define C__I8SATI16_SATl(v, losatval)\
    ( (v < (Int16)losatval) ? losatval : (Int8)v )

#define C__I8SATU16_SATb(v, upsatval, losatval)\
    ( ((upsatval < 0) || (v > (UInt16)upsatval)) ? upsatval :\
    ( ((losatval > 0) && (v < (UInt16)losatval)) ? losatval : (Int8)v ) )
#define C__I8SATU16_SATu(v, upsatval)\
    ( ((upsatval < 0) || (v > (UInt16)upsatval)) ? upsatval : (Int8)v )
#define C__I8SATU16_SATl(v, losatval)\
    ( ((losatval > 0) && (v < (UInt16)losatval)) ? losatval : (Int8)v )

#define C__U8SATI16_SATb(v, upsatval, losatval)\
    ( (v > (Int16)upsatval) ? upsatval : ( (v < (Int16)losatval) ? losatval : (UInt8)v ) )
#define C__U8SATI16_SATu(v, upsatval)\
    ( (v > (Int16)upsatval) ? upsatval : (UInt8)v )
#define C__U8SATI16_SATl(v, losatval)\
    ( (v < (Int16)losatval) ? losatval : (UInt8)v )

#define C__U8SATU16_SATb(v, upsatval, losatval)\
    ( (v > (UInt16)upsatval) ? upsatval : ( (v < (UInt16)losatval) ? losatval : (UInt8)v ) )
#define C__U8SATU16_SATu(v, upsatval)\
    ( (v > (UInt16)upsatval) ? upsatval : (UInt8)v )
#define C__U8SATU16_SATl(v, losatval)\
    ( (v < (UInt16)losatval) ? losatval : (UInt8)v )

/******************************************************************************
*
* MACRO(s):
*   Int32  C__I32SATI16_SAT(v, upsatval, losatval)
*   Int32  C__I32SATU16_SAT(v, upsatval, losatval)
*   UInt32 C__U32SATI16_SAT(v, upsatval, losatval)
*   UInt32 C__U32SATU16_SAT(v, upsatval, losatval)
*
*   Int32  C__I32SATI8_SAT(v, upsatval, losatval)
*   Int32  C__I32SATU8_SAT(v, upsatval, losatval)
*   UInt32 C__U32SATI8_SAT(v, upsatval, losatval)
*   UInt32 C__U32SATU8_SAT(v, upsatval, losatval)
*
*   Int16  C__I16SATI8_SAT(v, upsatval, losatval)
*   Int16  C__I16SATU8_SAT(v, upsatval, losatval)
*   UInt16 C__U16SATI8_SAT(v, upsatval, losatval)
*   UInt16 C__U16SATU8_SAT(v, upsatval, losatval)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*   clearly arranged code of this macro:
*           if(v > upsatval) return upsatval;
*           else if(v < losatval) return losatval;
*           else return v ;
*
******************************************************************************/
#define C__I32SATI16_SATb(v, upsatval, losatval)\
    ( ((Int32)v > upsatval) ? upsatval : ( ((Int32)v < losatval) ? losatval : (Int32)v ) )
#define C__I32SATI16_SATu(v, upsatval)\
    ( ((Int32)v > upsatval) ? upsatval : (Int32)v )
#define C__I32SATI16_SATl(v, losatval)\
    ( ((Int32)v < losatval) ? losatval : (Int32)v )

#define C__U32SATI16_SATb(v, upsatval, losatval)\
    ( ((v > 0) && ((UInt32)v > upsatval)) ? upsatval :\
    ( ((v < 0) || ((UInt32)v < losatval)) ? losatval : (UInt32)v ) )
#define C__U32SATI16_SATu(v, upsatval)\
    ( ((v > 0) && ((UInt32)v > upsatval)) ? upsatval : (UInt32)v )
#define C__U32SATI16_SATl(v, losatval)\
    ( ((v < 0) || ((UInt32)v < losatval)) ? losatval : (UInt32)v )

#define C__I32SATU16_SATb(v, upsatval, losatval)\
    ( ((Int32)v > upsatval) ? upsatval : ( ((Int32)v < losatval) ? losatval : (Int32)v ) )
#define C__I32SATU16_SATu(v, upsatval)\
    ( ((Int32)v > upsatval) ? upsatval : (Int32)v )
#define C__I32SATU16_SATl(v, losatval)\
    ( ((Int32)v < losatval) ? losatval : (Int32)v )

#define C__U32SATU16_SATb(v, upsatval, losatval)\
    ( (v > (UInt32)upsatval) ? upsatval : ( (v < (UInt32)losatval) ? losatval : (UInt32)v ) )
#define C__U32SATU16_SATu(v, upsatval)\
    ( (v > (UInt32)upsatval) ? upsatval : (UInt32)v )
#define C__U32SATU16_SATl(v, losatval)\
    ( (v < (UInt32)losatval) ? losatval : (UInt32)v )


#define C__I32SATI8_SATb(v, upsatval, losatval)\
    ( ((Int32)v > upsatval) ? upsatval : ( ((Int32)v < losatval) ? losatval : (Int32)v ) )
#define C__I32SATI8_SATu(v, upsatval)\
    ( ((Int32)v > upsatval) ? upsatval : (Int32)v )
#define C__I32SATI8_SATl(v, losatval)\
    ( ((Int32)v < losatval) ? losatval : (Int32)v )

#define C__U32SATI8_SATb(v, upsatval, losatval)\
    ( ((v > 0) && ((UInt32)v > upsatval)) ? upsatval :\
    ( ((v < 0) || ((UInt32)v < losatval)) ? losatval : (UInt32)v ) )
#define C__U32SATI8_SATu(v, upsatval)\
    ( ((v > 0) && ((UInt32)v > upsatval)) ? upsatval : (UInt32)v )
#define C__U32SATI8_SATl(v, losatval)\
    ( ((v < 0) || ((UInt32)v < losatval)) ? losatval : (UInt32)v )

#define C__I32SATU8_SATb(v, upsatval, losatval)\
    ( ((Int32)v > upsatval) ? upsatval : ( ((Int32)v < losatval) ? losatval : (Int32)v ) )
#define C__I32SATU8_SATu(v, upsatval)\
    ( ((Int32)v > upsatval) ? upsatval : (Int32)v )
#define C__I32SATU8_SATl(v, losatval)\
    ( ((Int32)v < losatval) ? losatval : (Int32)v )

#define C__U32SATU8_SATb(v, upsatval, losatval)\
    ( (v > (UInt32)upsatval) ? upsatval : ( (v < (UInt32)losatval) ? losatval : (UInt32)v ) )
#define C__U32SATU8_SATu(v, upsatval)\
    ( (v > (UInt32)upsatval) ? upsatval : (UInt32)v )
#define C__U32SATU8_SATl(v, losatval)\
    ( (v < (UInt32)losatval) ? losatval : (UInt32)v )


#define C__I16SATI8_SATb(v, upsatval, losatval)\
    ( ((Int16)v > upsatval) ? upsatval : ( ((Int16)v < losatval) ? losatval : (Int16)v ) )
#define C__I16SATI8_SATu(v, upsatval)\
    ( ((Int16)v > upsatval) ? upsatval : (Int16)v )
#define C__I16SATI8_SATl(v, losatval)\
    ( ((Int16)v < losatval) ? losatval : (Int16)v )

#define C__U16SATI8_SATb(v, upsatval, losatval)\
    ( ((v > 0) && ((UInt16)v > upsatval)) ? upsatval :\
    ( ((v < 0) || ((UInt16)v < losatval)) ? losatval : (UInt16)v ) )
#define C__U16SATI8_SATu(v, upsatval)\
    ( ((v > 0) && ((UInt16)v > upsatval)) ? upsatval : (UInt16)v )
#define C__U16SATI8_SATl(v, losatval)\
    ( ((v < 0) || ((UInt16)v < losatval)) ? losatval : (UInt16)v )

#define C__I16SATU8_SATb(v, upsatval, losatval)\
    ( ((Int16)v > upsatval) ? upsatval : ( ((Int16)v < losatval) ? losatval : (Int16)v ) )
#define C__I16SATU8_SATu(v, upsatval)\
    ( ((Int16)v > upsatval) ? upsatval : (Int16)v )
#define C__I16SATU8_SATl(v, losatval)\
    ( ((Int16)v < losatval) ? losatval : (Int16)v )

#define C__U16SATU8_SATb(v, upsatval, losatval)\
    ( (v > (UInt16)upsatval) ? upsatval : ( (v < (UInt16)losatval) ? losatval : (UInt16)v ) )
#define C__U16SATU8_SATu(v, upsatval)\
    ( (v > (UInt16)upsatval) ? upsatval : (UInt16)v )
#define C__U16SATU8_SATl(v, losatval)\
    ( (v < (UInt16)losatval) ? losatval : (UInt16)v )




#endif /* #ifndef __sat_h__ */

