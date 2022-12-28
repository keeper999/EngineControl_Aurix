/******************************************************************************
*
* FILE:
*   fit.h
*
* DESCRIPTION:
*   This file contains macro definitions for fitting an input value into an
*   output type.
*
*   The following applies to all macros:
*   ------------------------------------
*
*   The macro name represents the implemented operation:
*    C__<output_type>FIT<input_type>_SAT[{l|u}]
*
*    output_type            : U8, U16, U32,      I8, I16, I32,    
*     input_type            : U8, U16, U32, U64, I8, I16, I32, I64
*
*
*   The parameters are classified with three keywords.
*
*    Parameter  Description                    Properties
*    --------------------------------------------------------------------------
*    v          input                          rVars,  NoConsts, NoComplexExpr  
*    v_h        upper part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
*    v_l        lower part of a 64-bit input   rVars,  NoConsts, NoComplexExpr  
*    csatval    saturation limit (positive),
*               the negative value is ~csatval rVars,  Consts,   NoComplexExpr
*
*
*  AUTHOR(S):
*    O. Grajetzky, K. Goebel
*
*  Copyright (c) 2004 dSPACE GmbH, GERMANY
*
*  $Workfile: fit.h $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:51GMT+01:00 $ $Author: FrankL $
******************************************************************************/


#ifndef __fit_h__
#define __fit_h__


/******************************************************************************
*
* GENERAL:
*   Macros to fit a type into a type with a smaller width
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I32FITI64_SAT(v_h, v_l, csatval)
*   C__I32FITI64_SATu(v_h, v_l, csatval)
*   C__I32FITI64_SATl(v_h, v_l, csatval)
*
*   C__I16FITI64_SAT(v_h, v_l, csatval)
*   C__I16FITI64_SATu(v_h, v_l, csatval)
*   C__I16FITI64_SATl(v_h, v_l, csatval)
*
*   C__I8FITI64_SAT(v_h, v_l, csatval)
*   C__I8FITI64_SATu(v_h, v_l, csatval)
*   C__I8FITI64_SATl(v_h, v_l, csatval)
*
*   C__I32FITU64_SAT(v_h, v_l, csatval)
*   C__I32FITU64_SATu(v_h, v_l, csatval)
*
*   C__I16FITU64_SAT(v_h, v_l, csatval)
*   C__I16FITU64_SATu(v_h, v_l, csatval)
*
*   C__I8FITU64_SAT(v_h, v_l, csatval)
*   C__I8FITU64_SATu(v_h, v_l, csatval)
*
*   C__U32FITI64_SAT(v_h, v_l, csatval)
*   C__U32FITI64_SATu(v_h, v_l, csatval)
*   C__U32FITI64_SATl(v_h, v_l, csatval)
*
*   C__U16FITI64_SAT(v_h, v_l, csatval)
*   C__U16FITI64_SATu(v_h, v_l, csatval)
*   C__U16FITI64_SATl(v_h, v_l, csatval)
*
*   C__U8FITI64_SAT(v_h, v_l, csatval)
*   C__U8FITI64_SATu(v_h, v_l, csatval)
*   C__U8FITI64_SATl(v_h, v_l, csatval)
*
*   C__U32FITU64_SAT(v_h, v_l, csatval)
*   C__U32FITU64_SATu(v_h, v_l, csatval)
*
*   C__U16FITU64_SAT(v_h, v_l, csatval)
*   C__U16FITU64_SATu(v_h, v_l, csatval)
*
*   C__U8FITU64_SAT(v_h, v_l, csatval)
*   C__U8FITU64_SATu(v_h, v_l, csatval)
*
*
*   C__I16FITI32_SAT(v, csatval)
*   C__I16FITI32_SATu(v, csatval)
*   C__I16FITI32_SATl(v, csatval)
*
*   C__I8FITI32_SAT(v, csatval)
*   C__I8FITI32_SATu(v, csatval)
*   C__I8FITI32_SATl(v, csatval)
*
*   C__I16FITU32_SAT(v, csatval)
*   C__I16FITU32_SATu(v, csatval)
*
*   C__I8FITU32_SAT(v, csatval)
*   C__I8FITU32_SATu(v, csatval)
*
*   C__U16FITI32_SAT(v, csatval)
*   C__U16FITI32_SATu(v, csatval)
*   C__U16FITI32_SATl(v, csatval)
*
*   C__U8FITI32_SAT(v, csatval)
*   C__U8FITI32_SATu(v, csatval)
*   C__U8FITI32_SATl(v, csatval)
*
*   C__U16FITU32_SAT(v, csatval)
*   C__U16FITU32_SATu(v, csatval)
*
*   C__U8FITU32_SAT(v, csatval)
*   C__U8FITU32_SATu(v, csatval)
*
*
*   C__I8FITI16_SAT(v, csatval)
*   C__I8FITI16_SATu(v, csatval)
*   C__I8FITI16_SATl(v, csatval)
*
*   C__I8FITU16_SAT(v, csatval)
*   C__I8FITU16_SATu(v, csatval)
*
*   C__U8FITI16_SAT(v, csatval)
*   C__U8FITI16_SATu(v, csatval)
*   C__U8FITI16_SATl(v, csatval)
*
*   C__U8FITU16_SAT(v, csatval)
*   C__U8FITU16_SATu(v, csatval)
*
*
* NOTE:     
*   The input values are used more than once inside the macro body.
*   Thus, for performance reasons, the input values should be no expressions.
*
******************************************************************************/

#define C__I32FITI64_SAT(v_h, v_l, csatval)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > csatval)) ) ? csatval :\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < ~(UInt32)csatval)) ) ? ~csatval : (Int32)v_l ) )
#define C__I32FITI64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > csatval)) ) ? csatval : (Int32)v_l )
#define C__I32FITI64_SATl(v_h, v_l, csatval)\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < ~(UInt32)csatval)) ) ? ~csatval : (Int32)v_l )

#define C__I16FITI64_SAT(v_h, v_l, csatval)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > csatval)) ) ? csatval :\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < ~(UInt32)csatval)) ) ? ~csatval : (Int16)v_l ) )
#define C__I16FITI64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > csatval)) ) ? csatval : (Int16)v_l )
#define C__I16FITI64_SATl(v_h, v_l, csatval)\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < ~(UInt32)csatval)) ) ? ~csatval : (Int16)v_l )

#define C__I8FITI64_SAT(v_h, v_l, csatval)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > csatval)) ) ? csatval :\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < ~(UInt32)csatval)) ) ? ~csatval : (Int8)v_l ) )
#define C__I8FITI64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > csatval)) ) ? csatval : (Int8)v_l )
#define C__I8FITI64_SATl(v_h, v_l, csatval)\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < ~(UInt32)csatval)) ) ? ~csatval : (Int8)v_l )

#define C__I32FITU64_SAT(v_h, v_l, csatval)\
        C__I32FITU64_SATu(v_h, v_l, csatval)
#define C__I32FITU64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||(v_l > csatval) ) ? csatval : (Int32)v_l )

#define C__I16FITU64_SAT(v_h, v_l, csatval)\
        C__I16FITU64_SATu(v_h, v_l, csatval)
#define C__I16FITU64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||(v_l > csatval) ) ? csatval : (Int16)v_l )

#define C__I8FITU64_SAT(v_h, v_l, csatval)\
        C__I8FITU64_SATu(v_h, v_l, csatval)
#define C__I8FITU64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||(v_l > csatval) ) ? csatval : (Int8)v_l )

#define C__U32FITI64_SAT(v_h, v_l, csatval)\
    ( (v_h > 0) ? csatval : ( (v_h < 0) ? ~csatval : (UInt32)v_l  ) )
#define C__U32FITI64_SATu(v_h, v_l, csatval)\
    ( (v_h > 0) ? csatval : (UInt32)v_l  )
#define C__U32FITI64_SATl(v_h, v_l, csatval)\
    ( (v_h < 0) ? ~csatval : (UInt32)v_l  )

#define C__U16FITI64_SAT(v_h, v_l, csatval)\
    ( ((v_h > 0)||((v_h == 0)&&(v_l > csatval))) ? csatval : ( (v_h < 0) ?\
    ~csatval : (UInt16)v_l  ) )
#define C__U16FITI64_SATu(v_h, v_l, csatval)\
    ( ((v_h > 0)||((v_h == 0)&&(v_l > csatval))) ? csatval : (UInt16)v_l  )
#define C__U16FITI64_SATl(v_h, v_l, csatval)\
    ( (v_h < 0) ? ~csatval : (UInt16)v_l  )

#define C__U8FITI64_SAT(v_h, v_l, csatval)\
    ( ((v_h > 0)||((v_h == 0)&&(v_l > csatval))) ? csatval : ( (v_h < 0) ?\
    ~csatval : (UInt8)v_l  ) )
#define C__U8FITI64_SATu(v_h, v_l, csatval)\
    ( ((v_h > 0)||((v_h == 0)&&(v_l > csatval))) ? csatval : (UInt8)v_l  )
#define C__U8FITI64_SATl(v_h, v_l, csatval)\
    ( (v_h < 0) ? ~csatval : (UInt8)v_l  )

#define C__U32FITU64_SAT(v_h, v_l, csatval)\
        C__U32FITU64_SATu(v_h, v_l, csatval)
#define C__U32FITU64_SATu(v_h, v_l, csatval)\
    ( (v_h > 0) ? csatval : (UInt32)v_l )

#define C__U16FITU64_SAT(v_h, v_l, csatval)\
        C__U16FITU64_SATu(v_h, v_l, csatval)
#define C__U16FITU64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||(v_l > csatval) ) ? csatval : (UInt16)v_l )

#define C__U8FITU64_SAT(v_h, v_l, csatval)\
        C__U8FITU64_SATu(v_h, v_l, csatval)
#define C__U8FITU64_SATu(v_h, v_l, csatval)\
    ( ( (v_h > 0)||(v_l > csatval) ) ? csatval : (UInt8)v_l )


#define C__I16FITI32_SAT(v, csatval)\
    ( (v > csatval) ? csatval : ( (v < ~csatval) ? ~csatval : (Int16)v ) )
#define C__I16FITI32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (Int16)v )
#define C__I16FITI32_SATl(v, csatval)\
    ( (v < ~csatval) ? ~csatval : (Int16)v  )

#define C__I8FITI32_SAT(v, csatval)\
    ( (v > csatval) ? csatval : ( (v < ~csatval) ? ~csatval : (Int8)v ) )
#define C__I8FITI32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (Int8)v )
#define C__I8FITI32_SATl(v, csatval)\
    ( (v < ~csatval) ? ~csatval : (Int8)v  )

#define C__I16FITU32_SAT(v, csatval)\
        C__I16FITU32_SATu(v, csatval)
#define C__I16FITU32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (Int16)v )

#define C__I8FITU32_SAT(v, csatval)\
        C__I8FITU32_SATu(v, csatval)
#define C__I8FITU32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (Int8)v )

#define C__U16FITI32_SAT(v, csatval)\
    ( (v > csatval) ? csatval : ( (v < 0) ? 0 : (UInt16)v ) )
#define C__U16FITI32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (UInt16)v  )
#define C__U16FITI32_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt16)v )

#define C__U8FITI32_SAT(v, csatval)\
    ( (v > csatval) ? csatval : ( (v < 0) ? 0 : (UInt8)v ) )
#define C__U8FITI32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (UInt8)v  )
#define C__U8FITI32_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt8)v )

#define C__U16FITU32_SAT(v, csatval)\
        C__U16FITU32_SATu(v, csatval)
#define C__U16FITU32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (UInt16)v )

#define C__U8FITU32_SAT(v, csatval)\
        C__U8FITU32_SATu(v, csatval)
#define C__U8FITU32_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (UInt8)v )


#define C__I8FITI16_SAT(v, csatval)\
    ( (v > csatval) ? csatval : ( (v < ~csatval) ? ~csatval : (Int8)v ) )
#define C__I8FITI16_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (Int8)v )
#define C__I8FITI16_SATl(v, csatval)\
    ( (v < ~csatval) ? ~csatval : (Int8)v  )

#define C__I8FITU16_SAT(v, csatval)\
        C__I8FITU16_SATu(v, csatval)
#define C__I8FITU16_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (Int8)v )

#define C__U8FITI16_SAT(v, csatval)\
    ( (v > csatval) ? csatval : ( (v < 0) ? 0 : (UInt8)v ) )
#define C__U8FITI16_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (UInt8)v )
#define C__U8FITI16_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt8)v )

#define C__U8FITU16_SAT(v, csatval)\
        C__U8FITU16_SATu(v, csatval)
#define C__U8FITU16_SATu(v, csatval)\
    ( (v > csatval) ? csatval : (UInt8)v )



/******************************************************************************
*
* GENERAL:
*   Macros to fit a type into a type with the same width
*
******************************************************************************/

/******************************************************************************
*
* MACRO(s):
*   C__I32FITU32_SAT(v, csatval)
*   C__I32FITU32_SATu(v, csatval)
*
*   C__U32FITI32_SAT(v, csatval)
*   C__U32FITI32_SATl(v, csatval)
*
*
*   C__I16FITU16_SAT(v, csatval)
*   C__I16FITU16_SATu(v, csatval)
*
*   C__U16FITI16_SAT(v, csatval)
*   C__U16FITI16_SATl(v, csatval)
*
*
*   C__I8FITU8_SAT(v, csatval)
*   C__I8FITU8_SATu(v, csatval)
*
*   C__U8FITI8_SAT(v, csatval)
*   C__U8FITI8_SATl(v, csatval)
*
*
* NOTE:
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression.
*
******************************************************************************/

#define C__I32FITU32_SAT(v, csatval)\
        C__I32FITU32_SATu(v, csatval)
#define C__I32FITU32_SATu(v, csatval)\
    ( ((Int32)v < 0) ? csatval : (Int32)v )

#define C__U32FITI32_SAT(v, csatval)\
        C__U32FITI32_SATl(v, csatval)
#define C__U32FITI32_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt32)v )


#define C__I16FITU16_SAT(v, csatval)\
        C__I16FITU16_SATu(v, csatval)
#define C__I16FITU16_SATu(v, csatval)\
    ( ((Int16)v < 0) ? csatval : (Int16)v )

#define C__U16FITI16_SAT(v, csatval)\
        C__U16FITI16_SATl(v, csatval)
#define C__U16FITI16_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt16)v )


#define C__I8FITU8_SAT(v, csatval)\
        C__I8FITU8_SATu(v, csatval)
#define C__I8FITU8_SATu(v, csatval)\
    ( ((Int8)v < 0) ? csatval : v )

#define C__U8FITI8_SAT(v, csatval)\
        C__U8FITI8_SATl(v, csatval)
#define C__U8FITI8_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt8)v )



/******************************************************************************
*
* GENERAL:
*   Macros to fit a type into a type with a larger width
*
******************************************************************************/

/******************************************************************************
*
* MACRO(s):
*   C__U32FITI16_SAT()
*   C__U32FITI16_SATl()
*
*   C__U32FITI8_SAT()
*   C__U32FITI8_SATl()
*
*   C__U16FITI8_SAT()
*   C__U16FITI8_SATl()
*
*
* NOTE:
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression.
*
******************************************************************************/

#define C__U32FITI16_SAT(v, csatval)\
        C__U32FITI16_SATl(v, csatval)
#define C__U32FITI16_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt32)v )


#define C__U32FITI8_SAT(v, csatval)\
        C__U32FITI8_SATl(v, csatval)
#define C__U32FITI8_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt32)v )


#define C__U16FITI8_SAT(v, csatval)\
        C__U16FITI8_SATl(v, csatval)
#define C__U16FITI8_SATl(v, csatval)\
    ( (v < 0) ? 0 : (UInt16)v )



#endif /* #ifndef __fit_h__ */
