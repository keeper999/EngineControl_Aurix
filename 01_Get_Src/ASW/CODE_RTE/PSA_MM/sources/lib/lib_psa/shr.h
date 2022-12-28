/******************************************************************************
*
* FILE:
*   shr.h
*
* RELATED FILES:
*
* DESCRIPTION:
*   This file contains macro definitions for the operation Shift Right.
*   Macros whose names contain 'SAT' are with automatic saturation.
*   The saturation limits are defined by the type of the returned variable.
*
*   The following applies to all macros:
*   ------------------------------------
*
*   The macro name represents the implemented operation:
*     C__<output_type><operation><input_type>{C|U}6[{LT|EQ|GT}32][_SAT{b|l|u}]
*
*     output_type, input_type: U8, U16, U32, U64, I8, I16, I32, I64
*     operation              : SHR
*
*
*   The result:
*    If a macro's parameter list contains the parameters r_h and r_l or hi and lo
*    these variables contain the calculation result and the macro has no return
*    value. Those macros must not be used inside expressions!
*    All other macros have a return value.
*
*
*   The parameters are classified with three keywords.
*
*    Parameter  Description                    Properties
*    --------------------------------------------------------------------------
*    v          input for a ...
*                ... fixed type operation      rVars,  NoConsts, ComplexExpr
*                ... saturated operation       rVars,  NoConsts, NoComplexExpr
*    v_h        upper part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
*    v_l        lower part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
*    sh         variable shift factor          rVars,  NoConsts, NoComplexExpr
*    csh        const shift factor             NoVars, Consts,   NoComplexExpr
*    csh32      abs(32 - csh)                  NoVars, Consts,   NoComplexExpr
*    r_h        upper part of a 64-bit output  wVars,  NoConsts, NoComplexExpr
*    r_l        lower part of a 64-bit output  wVars,  NoConsts, NoComplexExpr
*    hi         upper part of a combined
*                64-bit input/output           rwVars, NoConsts, NoComplexExpr
*    lo         lower part of a combined
*                64-bit input/output           rwVars, NoConsts, NoComplexExpr
*    maxIn      = 2^(W_output - 1) * 2^csh - 1
*               const upper input limit        rVars,  Consts,   NoComplexExpr
*    minIn      = ~maxIn
*               const lower input limit        rVars,  Consts,   NoComplexExpr
*    maxIn_h    upper part of the const
*                upper input limit             rVars,  Consts,   NoComplexExpr
*    maxIn_l    lower part of the const
*                upper input limit             rVars,  Consts,   NoComplexExpr
*    minIn_h    upper part of the const
*                lower input limit             rVars,  Consts,   NoComplexExpr
*    minIn_l    lower part of the const
*                lower input limit             rVars,  Consts,   NoComplexExpr
*
*
*  AUTHOR(S):
*    O. Grajetzky, D. Andoleit
*
*  Copyright (c) 2002 dSPACE GmbH, GERMANY
*
*  $Workfile: shr.h $ $Revision: 1.3 $ $Date: 2004/11/26 10:51:11GMT+01:00 $ $Author: KlausG $
******************************************************************************/

#ifndef __shr_h__
#define __shr_h__


/******************************************************************************
*
* GENERAL:
*   Generic rules, no saturation
*   (1 <= csh < Wx), (Wo == 64) && (Wx <= 32)
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I64SHRI32C6(v, csh, r_h, r_l)
*   C__I64SHRI16C6(v, csh, r_h, r_l)
*   C__I64SHRI8C6(v, csh, r_h, r_l)
*
*   C__I64SHRI32U6(v, sh, r_h, r_l)
*
* NOTE:     
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression.
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHRI32C6(v, csh, r_h, r_l)\
    r_l = (UInt32)(Int32)((v) >> csh);\
    r_h = ((v) < 0) ? -1 : 0

#define C__I64SHRI16C6(v, csh, r_h, r_l)\
    r_l = (UInt32)(Int32)((v) >> csh);\
    r_h = ((v) < 0) ? -1 : 0

#define C__I64SHRI8C6(v, csh, r_h, r_l)\
    r_l = (UInt32)(Int32)((v) >> csh);\
    r_h = ((v) < 0) ? -1 : 0

#define C__I64SHRI32U6(v, sh, r_h, r_l)\
  if(sh != 0)\
  {\
      r_l = (UInt32)(Int32)((v) >> sh);\
      r_h = (v < 0) ? -1 : 0;\
  }

/******************************************************************************
*
* MACROS:
*   C__U64SHRU32C6(v, csh, r_h, r_l)
*   C__U64SHRU16C6(v, csh, r_h, r_l)
*   C__U64SHRU8C6(v, csh, r_h, r_l)
*
*   C__U64SHRU32U6(v, sh, r_h, r_l)
*
* NOTE:     
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHRU32C6(v, csh, r_h, r_l)\
    r_l = (UInt32)((v) >> csh);\
    r_h = 0

#define C__U64SHRU16C6(v, csh, r_h, r_l)\
    r_l = (UInt32)((v) >> csh);\
    r_h = 0

#define C__U64SHRU8C6(v, csh, r_h, r_l)\
    r_l = (UInt32)((v) >> csh);\
    r_h = 0

#define C__U64SHRU32U6(v, sh, r_h, r_l)\
  if(sh != 0)\
  {\
      r_l = (UInt32)((v) >> sh);\
      r_h = 0;\
  }

/******************************************************************************
*
* MACROS:
*   C__I64SHRU32C6(v, csh, r_h, r_l)
*   C__I64SHRU16C6(v, csh, r_h, r_l)
*   C__I64SHRU8C6(v, csh, r_h, r_l)
*
*   C__I64SHRU32U6(v, sh, r_h, r_l)
*
* NOTE:     
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHRU32C6(v, csh, r_h, r_l)\
    r_l = (UInt32)((v) >> csh);\
    r_h = 0

#define C__I64SHRU16C6(v, csh, r_h, r_l)\
    r_l = (UInt32)((v) >> csh);\
    r_h = 0

#define C__I64SHRU8C6(v, csh, r_h, r_l)\
    r_l = (UInt32)((v) >> csh);\
    r_h = 0

#define C__I64SHRU32U6(v, sh, r_h, r_l)\
  if(sh != 0)\
  {\
      r_l = (UInt32)((v) >> sh);\
      r_h = 0;\
  }

/******************************************************************************
*
* MACROS:
*   C__U64SHRI32C6(v, csh, r_h, r_l)
*   C__U64SHRI16C6(v, csh, r_h, r_l)
*   C__U64SHRI8C6(v, csh, r_h, r_l)
*
*   C__U64SHRI32U6(v, sh, r_h, r_l)
*
* NOTE:     
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression.
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHRI32C6(v, csh, r_h, r_l)\
    r_l = (UInt32)(Int32)((v) >> csh);\
    r_h = ((v) < 0) ? UINT32MAX : 0

#define C__U64SHRI16C6(v, csh, r_h, r_l)\
    r_l = (UInt32)(Int32)((v) >> csh);\
    r_h = ((v) < 0) ? UINT32MAX : 0

#define C__U64SHRI8C6(v, csh, r_h, r_l)\
    r_l = (UInt32)(Int32)(v) >> csh;\
    r_h = ((v) < 0) ? UINT32MAX : 0

#define C__U64SHRI32U6(v, sh, r_h, r_l)\
  if(sh != 0)\
  {\
      r_l = (UInt32)((v) >> sh);\
      r_h = ((v) < 0) ? UINT32MAX : 0;\
  }

/******************************************************************************
*
* GENERAL:
*   Generic rules, no saturation
*   (1 <= csh < Wx), (Wo <= 32) && (Wx == 64)
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I32SHRI64C6_LT32(v_h, v_l, csh, csh32)
*   C__I32SHRI64C6_EQ32(v_h, v_l)
*   C__I32SHRI64C6_GT32(v_h, v_l, csh32)
*
*   C__I16SHRI64C6_LT32(v_h, v_l, csh, csh32)
*   C__I16SHRI64C6_EQ32(v_h, v_l)
*   C__I16SHRI64C6_GT32(v_h, v_l, csh32)
*
*   C__I8SHRI64C6_LT32(v_h, v_l, csh, csh32)
*   C__I8SHRI64C6_EQ32(v_h, v_l)
*   C__I8SHRI64C6_GT32(v_h, v_l, csh32)
*
*   C__I32SHRI64U6(v_h, v_l, sh)
*
* NOTE:     
*   -
*
******************************************************************************/

#define C__I32SHRI64C6_LT32(v_h, v_l, csh, csh32)\
    (Int32)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__I32SHRI64C6_EQ32(v_h, v_l)\
    v_h

#define C__I32SHRI64C6_GT32(v_h, v_l, csh32)\
    (Int32)(v_h >> csh32)

#define C__I16SHRI64C6_LT32(v_h, v_l, csh, csh32)\
    (Int16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__I16SHRI64C6_EQ32(v_h, v_l)\
    (Int16)v_h

#define C__I16SHRI64C6_GT32(v_h, v_l, csh32)\
    (Int16)(v_h >> csh32)

#define C__I8SHRI64C6_LT32(v_h, v_l, csh, csh32)\
    (Int8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__I8SHRI64C6_EQ32(v_h, v_l)\
    (Int8)v_h

#define C__I8SHRI64C6_GT32(v_h, v_l, csh32)\
    (Int8)(v_h >> csh32)

#define C__I32SHRI64U6(v_h, v_l, sh)\
    ( (Int32)( sh < 32 ? ((UInt32)(v_l >> sh) | (UInt32)((UInt32)v_h << (32-sh))) : ( (sh==32) ?\
    v_h : (UInt32)(v_h >> (sh-32)) ) ) )
       
/******************************************************************************
*
* MACROS:
*   C__U32SHRU64C6_LT32(v_h, v_l, csh, csh32)
*   C__U32SHRU64C6_EQ32(v_h, v_l)
*   C__U32SHRU64C6_GT32(v_h, v_l, csh32)
*
*   C__U16SHRU64C6_LT32(v_h, v_l, csh, csh32)
*   C__U16SHRU64C6_EQ32(v_h, v_l)
*   C__U16SHRU64C6_GT32(v_h, v_l, csh32)
*
*   C__U8SHRU64C6_LT32(v_h, v_l, csh, csh32)
*   C__U8SHRU64C6_EQ32(v_h, v_l)
*   C__U8SHRU64C6_GT32(v_h, v_l, csh32)
*
*   C__U32SHRU64U6(v_h, v_l, sh)
*
* NOTE:     
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__U32SHRU64C6_LT32(v_h, v_l, csh, csh32)\
    ( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__U32SHRU64C6_EQ32(v_h, v_l)\
    v_h

#define C__U32SHRU64C6_GT32(v_h, v_l, csh32)\
    (UInt32)(v_h >> csh32)

#define C__U16SHRU64C6_LT32(v_h, v_l, csh, csh32)\
    (UInt16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__U16SHRU64C6_EQ32(v_h, v_l)\
    (UInt16)v_h

#define C__U16SHRU64C6_GT32(v_h, v_l, csh32)\
    (UInt16)(v_h >> csh32)

#define C__U8SHRU64C6_LT32(v_h, v_l, csh, csh32)\
    (UInt8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__U8SHRU64C6_EQ32(v_h, v_l)\
    (UInt8)v_h

#define C__U8SHRU64C6_GT32(v_h, v_l, csh32)\
    (UInt8)(v_h >> csh32)

#define C__U32SHRU64U6(v_h, v_l, sh)\
    (UInt32)( sh < 32 ? ((UInt32)(v_l >> sh) | (UInt32)(v_h << (32-sh))) : ( (sh==32) ?\
    v_h : (v_h >> (sh-32)) ) )

/******************************************************************************
*
* MACROS:
*   C__I32SHRU64C6_LT32(v_h, v_l, csh, csh32)
*   C__I32SHRU64C6_EQ32(v_h, v_l)
*   C__I32SHRU64C6_GT32(v_h, v_l, csh32)
*
*   C__I16SHRU64C6_LT32(v_h, v_l, csh, csh32)
*   C__I16SHRU64C6_EQ32(v_h, v_l)
*   C__I16SHRU64C6_GT32(v_h, v_l, csh32)
*
*   C__I8SHRU64C6_LT32(v_h, v_l, csh, csh32)
*   C__I8SHRU64C6_EQ32(v_h, v_l)
*   C__I8SHRU64C6_GT32(v_h, v_l, csh32)
*
*   C__I32SHRU64U6(v_h, v_l, sh)
*
* NOTE:     
*   -
*
******************************************************************************/

#define C__I32SHRU64C6_LT32(v_h, v_l, csh, csh32)\
    (Int32)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )
    
#define C__I32SHRU64C6_EQ32(v_h, v_l)\
    (Int32)v_h

#define C__I32SHRU64C6_GT32(v_h, v_l, csh32)\
    (Int32)(v_h >> csh32)

#define C__I16SHRU64C6_LT32(v_h, v_l, csh, csh32)\
    (Int16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__I16SHRU64C6_EQ32(v_h, v_l)\
    (Int16)v_h

#define C__I16SHRU64C6_GT32(v_h, v_l, csh32)\
    (Int16)(v_h >> csh32)

#define C__I8SHRU64C6_LT32(v_h, v_l, csh, csh32)\
    (Int8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__I8SHRU64C6_EQ32(v_h, v_l)\
    (Int8)v_h

#define C__I8SHRU64C6_GT32(v_h, v_l, csh32)\
    (Int8)(v_h >> csh32)

#define C__I32SHRU64U6(v_h, v_l, sh)\
    (Int32)( sh < 32 ? ((UInt32)(v_l >> sh) | (UInt32)(v_h << (32-sh))) : ( (sh==32) ?\
    v_h : (UInt32)(v_h >> (sh-32)) ) )

/******************************************************************************
*
* MACROS:
*   C__U32SHRI64C6_LT32(v_h, v_l, csh, csh32)
*   C__U32SHRI64C6_EQ32(v_h, v_l)
*   C__U32SHRI64C6_GT32(v_h, v_l, csh32)
*
*   C__U16SHRI64C6_LT32(v_h, v_l, csh, csh32)
*   C__U16SHRI64C6_EQ32(v_h, v_l)
*   C__U16SHRI64C6_GT32(v_h, v_l, csh32)
*
*   C__U8SHRI64C6_LT32(v_h, v_l, csh, csh32)
*   C__U8SHRI64C6_EQ32(v_h, v_l)
*   C__U8SHRI64C6_GT32(v_h, v_l, csh32)
*
*   C__U32SHRI64U6(v_h, v_l, sh)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__U32SHRI64C6_LT32(v_h, v_l, csh, csh32)\
    ( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__U32SHRI64C6_EQ32(v_h, v_l)\
    (UInt32)v_h

#define C__U32SHRI64C6_GT32(v_h, v_l, csh32)\
    (UInt32)(Int32)(v_h >> csh32)

#define C__U16SHRI64C6_LT32(v_h, v_l, csh, csh32)\
    (UInt16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__U16SHRI64C6_EQ32(v_h, v_l)\
    (UInt16)v_h

#define C__U16SHRI64C6_GT32(v_h, v_l, csh32)\
    (UInt16)(Int16)(v_h >> csh32)

#define C__U8SHRI64C6_LT32(v_h, v_l, csh, csh32)\
    (UInt8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) )

#define C__U8SHRI64C6_EQ32(v_h, v_l)\
    (UInt8)v_h

#define C__U8SHRI64C6_GT32(v_h, v_l, csh32)\
    (UInt8)(Int8)(v_h >> csh32)

#define C__U32SHRI64U6(v_h, v_l, sh)\
    (UInt32)( sh < 32 ? ((UInt32)(v_l >> sh) | (UInt32)((UInt32)v_h << (32-sh))) : ( (sh==32) ?\
    v_h : (UInt32)(v_h >> (sh-32)) ) )
       
/******************************************************************************
*
* GENERAL:
*   Generic rules, no saturation
*   (1 <= csh < Wx), (Wo == 64) && (Wx == 64)
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I64SHRI64C6_LT32(hi, lo, csh, csh32)
*   C__I64SHRI64C6_EQ32(hi, lo)
*   C__I64SHRI64C6_GT32(hi, lo, csh32)
*
*   C__I64SHRI64U6(hi, lo, sh)
*
* NOTE:     
*   The input values are modified.
*   Use these macros only with temporary variables.
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHRI64C6_LT32(hi, lo, csh, csh32)\
    lo = (UInt32)(lo >> csh) | (UInt32)(hi << csh32);\
    hi = (Int32)(hi >> csh)

#define C__I64SHRI64C6_EQ32(hi, lo)\
    lo = (UInt32)hi;\
    hi = (hi < 0) ? -1 : 0

#define C__I64SHRI64C6_GT32(hi, lo, csh32)\
    lo = (UInt32)(Int32)(hi >> csh32);\
    hi = (hi < 0) ? -1 : 0

#define C__I64SHRI64U6(hi, lo, sh)\
  if(sh != 0)\
  {\
    if(sh < 32)\
    {\
      lo = (UInt32)( (UInt32)(lo >> sh) | (UInt32)((UInt32)hi << (32-sh)) );\
      hi = (Int32)(hi >> sh);\
    }\
    else if (sh == 32)\
    {\
        lo = (UInt32)hi;\
        hi = (Int32)(hi >> sh);\
    }\
    else\
    {\
        lo = (UInt32)(hi >> (sh-32));\
        hi = (Int32)(hi >> sh);\
    }\
  }  

/******************************************************************************
*
* MACROS:
*   C__U64SHRU64C6_LT32(hi, lo, csh, csh32)
*   C__U64SHRU64C6_EQ32(hi, lo)
*   C__U64SHRU64C6_GT32(hi, lo, csh32)
*
*   C__U64SHRU64U6(hi, lo, sh)
*
* NOTE:     
*   The input values are modified.
*   Use these macros only with temporary variables.
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHRU64C6_LT32(hi, lo, csh, csh32)\
    lo = (UInt32)(lo >> csh) | (UInt32)(hi << csh32);\
    hi = (UInt32)(hi >> csh)                                               

#define C__U64SHRU64C6_EQ32(hi, lo)\
    lo = hi ;\
    hi = 0                                               

#define C__U64SHRU64C6_GT32(hi, lo, csh32)\
    lo = (UInt32)(hi >> csh32);\
    hi = 0

#define C__U64SHRU64U6(hi, lo, sh)\
    if(sh != 0)\
    {\
        if(sh < 32)\
        {\
            lo = (UInt32)(lo >> sh) | (UInt32)(hi << (32-sh));\
            hi = (UInt32)(hi >> sh);\
        }\
        else if (sh == 32)\
        {\
            lo = hi;\
            hi = 0;\
        }\
        else\
        {\
            lo = (UInt32)(hi >> (sh-32));\
            hi = 0;\
        }\
    }

/******************************************************************************
*
* MACROS:
*   C__I64SHRU64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)
*   C__I64SHRU64C6_EQ32(v_h, r_h, r_l)
*   C__I64SHRU64C6_GT32(v_h, csh32, r_h, r_l)
*
* NOTE:     
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHRU64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)\
    r_l = (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32);\
    r_h = (Int32)(v_h >> csh) 

#define C__I64SHRU64C6_EQ32(v_h, r_h, r_l)\
    r_l = v_h;\
    r_h = 0 

#define C__I64SHRU64C6_GT32(v_h, csh32, r_h, r_l)\
    r_l = (UInt32)(v_h >> csh32);\
    r_h = 0

/******************************************************************************
*
* MACROS:
*   C__U64SHRI64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)
*   C__U64SHRI64C6_EQ32(v_h, r_h, r_l)
*   C__U64SHRI64C6_GT32(v_h, csh32, r_h, r_l)
*
* NOTE:     
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHRI64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)\
    r_l = (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32);\
    r_h = (UInt32)(Int32)(v_h >> csh) 

#define C__U64SHRI64C6_EQ32(v_h, r_h, r_l)\
    r_l = (UInt32)v_h ;\
    r_h = (v_h < 0) ? UINT32MAX : 0

#define C__U64SHRI64C6_GT32(v_h, csh32, r_h, r_l)\
    r_l = (UInt32)(Int32)(v_h >> csh32);\
    r_h = (v_h < 0) ? UINT32MAX : 0


/******************************************************************************
*
* GENERAL:
*   Generic rules, with saturation
*   (Wo <= 32) && (Wx <= 32)
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I16SHRI32C6_LT16_SATb(v, csh, maxIn, minIn)          : csh <  |Wx - Wo|
*   C__I16SHRI32C6_LT16_SATu(v, csh, maxIn)                 : csh <  |Wx - Wo|
*   C__I16SHRI32C6_LT16_SATl(v, csh, minIn)                 : csh <  |Wx - Wo|
*
*   C__I8SHRI32C6_LT24_SATb(v, csh, maxIn, minIn)           : csh <  |Wx - Wo|
*   C__I8SHRI32C6_LT24_SATu(v, csh, maxIn)                  : csh <  |Wx - Wo|
*   C__I8SHRI32C6_LT24_SATl(v, csh, minIn)                  : csh <  |Wx - Wo|
*
*   C__I8SHRI16C6_LT8_SATb(v, csh, maxIn, minIn)            : csh <  |Wx - Wo|
*   C__I8SHRI16C6_LT8_SATu(v, csh, maxIn)                   : csh <  |Wx - Wo|
*   C__I8SHRI16C6_LT8_SATl(v, csh, minIn)                   : csh <  |Wx - Wo|
*
* NOTE:     
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__I16SHRI32C6_LT16_SATb(v, csh, maxIn, minIn)\
  ( (v > maxIn) ? INT16MAX : ( (v < minIn) ? INT16MIN : (Int16)(v >> csh) ) )

#define C__I16SHRI32C6_LT16_SATu(v, csh, maxIn)\
  ( (v > maxIn) ? INT16MAX : (Int16)(v >> csh) )

#define C__I16SHRI32C6_LT16_SATl(v, csh, minIn)\
  ( (v < minIn) ? INT16MIN : (Int16)(v >> csh) )


#define C__I8SHRI32C6_LT24_SATb(v, csh, maxIn, minIn)\
  ( (v > maxIn) ? INT8MAX : ( (v < minIn) ? INT8MIN : (Int8)(v >> csh) ) )

#define C__I8SHRI32C6_LT24_SATu(v, csh, maxIn)\
  ( (v > maxIn) ? INT8MAX : (Int8)(v >> csh) )

#define C__I8SHRI32C6_LT24_SATl(v, csh, minIn)\
  ( (v < minIn) ? INT8MIN : (Int8)(v >> csh) )


#define C__I8SHRI16C6_LT8_SATb(v, csh, maxIn, minIn)\
  ( (v > maxIn) ? INT8MAX : ( (v < minIn) ? INT8MIN : (Int8)(v >> csh) ) )

#define C__I8SHRI16C6_LT8_SATu(v, csh, maxIn)\
  ( (v > maxIn) ? INT8MAX : (Int8)(v >> csh) )

#define C__I8SHRI16C6_LT8_SATl(v, csh, minIn)\
  ( (v < minIn) ? INT8MIN : (Int8)(v >> csh) )

/******************************************************************************
*
* MACROS:
*   C__U16SHRU32C6_LT16_SATu(v, csh, maxIn)                 : csh <  |Wx - Wo|
*   C__U8SHRU32C6_LT24_SATu(v, csh, maxIn)                  : csh <  |Wx - Wo|
*   C__U8SHRU16C6_LT8_SATu(v, csh, maxIn)                   : csh <  |Wx - Wo|
*
* NOTE:     
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__U16SHRU32C6_LT16_SATu(v, csh, maxIn)\
   ( (v > maxIn) ? UINT16MAX : (UInt16)(v >> csh) )

#define C__U8SHRU32C6_LT24_SATu(v, csh, maxIn)\
   ( (v > maxIn) ? UINT8MAX : (UInt8)(v >> csh) )

#define C__U8SHRU16C6_LT8_SATu(v, csh, maxIn)\
   ( (v > maxIn) ? UINT8MAX : (UInt8)(v >> csh) )

/******************************************************************************
*
* MACROS:
*   C__I16SHRU32C6_EQ16_SATu(v, maxIn)                      : csh == |Wx - Wo|
*   C__I16SHRU32C6_LT16_SATu(v, csh, maxIn)                 : csh <  |Wx - Wo|
*
*   C__I8SHRU32C6_EQ24_SATu(v, maxIn)                       : csh == |Wx - Wo|  
*   C__I8SHRU32C6_LT24_SATu(v, csh, maxIn)                  : csh <  |Wx - Wo|
*
*   C__I8SHRU16C6_EQ8_SATu(v, maxIn)                        : csh == |Wx - Wo|  
*   C__I8SHRU16C6_LT8_SATu(v, csh, maxIn)                   : csh <  |Wx - Wo|
*
* NOTE:     
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__I16SHRU32C6_EQ16_SATu(v, maxIn)\
   ( (v > maxIn) ? INT16MAX : (Int16)(v >> 16) )

#define C__I16SHRU32C6_LT16_SATu(v, csh, maxIn)\
   ( (v > maxIn) ? INT16MAX : (Int16)(v >> csh) )


#define C__I8SHRU32C6_EQ24_SATu(v, maxIn)\
   ( (v > maxIn) ? INT8MAX : (Int8)(v >> 24) )

#define C__I8SHRU32C6_LT24_SATu(v, csh, maxIn)\
   ( (v > maxIn) ? INT8MAX : (Int8)(v >> csh) )


#define C__I8SHRU16C6_EQ8_SATu(v, maxIn)\
   ( (v > maxIn) ? INT8MAX : (Int8)(v >> 8) )

#define C__I8SHRU16C6_LT8_SATu(v, csh, maxIn)\
   ( (v > maxIn) ? INT8MAX : (Int8)(v >> csh) )

/******************************************************************************
*
* MACROS:
*   C__U16SHRI32C6_GT16_SATl(v, csh)                        : csh >  |Wx - Wo|
*   C__U16SHRI32C6_EQ16_SATl(v)                             : csh == |Wx - Wo|
*
*   C__U16SHRI32C6_EQ15_SATl(v)                             : csh <  |Wx - Wo|
*   C__U16SHRI32C6_LT15_SATb(v, csh, maxIn)                 : csh <  |Wx - Wo|
*   C__U16SHRI32C6_LT15_SATu(v, csh, maxIn)                 : csh <  |Wx - Wo|
*   C__U16SHRI32C6_LT15_SATl(v, csh)                        : csh <  |Wx - Wo|
*
*   C__U8SHRI32C6_GT24_SATl(v, csh)                         : csh >  |Wx - Wo|
*   C__U8SHRI32C6_EQ24_SATl(v)                              : csh == |Wx - Wo|
*
*   C__U8SHRI32C6_EQ23_SATl(v)                              : csh <  |Wx - Wo|
*   C__U8SHRI32C6_LT23_SATb(v, csh, maxIn)                  : csh <  |Wx - Wo|
*   C__U8SHRI32C6_LT23_SATu(v, csh, maxIn)                  : csh <  |Wx - Wo|
*   C__U8SHRI32C6_LT23_SATl(v, csh)                         : csh <  |Wx - Wo|
*
*   C__U8SHRI16C6_GT8_SATl(v, csh)                          : csh >  |Wx - Wo|
*   C__U8SHRI16C6_EQ8_SATl(v)                               : csh == |Wx - Wo|
*
*   C__U8SHRI16C6_EQ7_SATl(v)                               : csh <  |Wx - Wo|
*   C__U8SHRI16C6_LT7_SATb(v, csh, maxIn)                   : csh <  |Wx - Wo|
*   C__U8SHRI16C6_LT7_SATu(v, csh, maxIn)                   : csh <  |Wx - Wo|
*   C__U8SHRI16C6_LT7_SATl(v, csh)                          : csh <  |Wx - Wo|
*
* NOTE:     
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__U16SHRI32C6_GT16_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt16)(Int16)(v >> csh) )                    

#define C__U16SHRI32C6_EQ16_SATl(v)\
    ( (v < 0) ? 0 : (UInt16)(Int16)(v >> 16) )                    


#define C__U16SHRI32C6_EQ15_SATl(v)\
    ( (v < 0) ? 0 : (UInt16)(Int16)(v >> 15) )                    

#define C__U16SHRI32C6_LT15_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? UINT16MAX : ( (v < 0) ? 0 : (UInt16)(Int16)(v >> csh) ) )

#define C__U16SHRI32C6_LT15_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? UINT16MAX : (UInt16)(Int16)(v >> csh) )

#define C__U16SHRI32C6_LT15_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt16)(Int16)(v >> csh) )                    


#define C__U8SHRI32C6_GT24_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> csh) )                    

#define C__U8SHRI32C6_EQ24_SATl(v)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> 24) )                    


#define C__U8SHRI32C6_EQ23_SATl(v)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> 23) )                    

#define C__U8SHRI32C6_LT23_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? UINT8MAX : ( (v < 0) ? 0 : (UInt8)(Int8)(v >> csh) ) )

#define C__U8SHRI32C6_LT23_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? UINT8MAX : (UInt8)(Int8)(v >> csh) )

#define C__U8SHRI32C6_LT23_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> csh) )                    


#define C__U8SHRI16C6_GT8_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> csh) )                    

#define C__U8SHRI16C6_EQ8_SATl(v)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> 8) )                    


#define C__U8SHRI16C6_EQ7_SATl(v)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> 7) )                    

#define C__U8SHRI16C6_LT7_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? UINT8MAX : ( (v < 0) ? 0 : (UInt8)(Int8)(v >> csh) ) )

#define C__U8SHRI16C6_LT7_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? UINT8MAX : (UInt8)(Int8)(v >> csh) )

#define C__U8SHRI16C6_LT7_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> csh) )                    

/******************************************************************************
*
* MACROS:
*   C__U32SHRI32C6_SATl(v, csh)                             : csh >  |Wx - Wo|
*                                                           
*   C__U32SHRI16C6_SATl(v, csh)                             : csh >  |Wx - Wo|
*
*   C__U32SHRI8C6_SATl(v, csh)                              : csh >  |Wx - Wo|
*
*   C__U16SHRI16C6_SATl(v, csh)                             : csh >  |Wx - Wo|
*
*   C__U16SHRI8C6_SATl(v, csh)                              : csh >  |Wx - Wo|
*
*   C__U8SHRI8C6_SATl(v, csh)                               : csh >  |Wx - Wo|
*
* NOTE:     
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__U32SHRI32C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt32)(Int32)(v >> csh) )                    

#define C__U32SHRI16C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt32)(Int32)(v >> csh) )                    

#define C__U32SHRI8C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt32)(Int32)(v >> csh) )                    

#define C__U16SHRI16C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt16)(Int16)(v >> csh) )                    

#define C__U16SHRI8C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt16)(Int16)(v >> csh) )                    

#define C__U8SHRI8C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(Int8)(v >> csh) )                    

/******************************************************************************
*
* GENERAL:
*   Generic rules, with saturation
*   (Wo <= 32) && (Wx == 64)
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I32SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l) : csh <  |Wx - Wo|
*   C__I32SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)                   : csh <  |Wx - Wo|
*   C__I32SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32, minIn_h, minIn_l)                   : csh <  |Wx - Wo|
*
*   C__I16SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l) : csh <  |Wx - Wo|
*   C__I16SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l, minIn_h, minIn_l)             : csh <  |Wx - Wo|
*   C__I16SHRI64C6_LT48_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)      : csh <  |Wx - Wo|
*
*   C__I16SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)                   : csh <  |Wx - Wo|
*   C__I16SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)                               : csh <  |Wx - Wo|
*   C__I16SHRI64C6_LT48_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)                        : csh <  |Wx - Wo|
*
*   C__I16SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32, minIn_h, minIn_l)                   : csh <  |Wx - Wo|
*   C__I16SHRI64C6_EQ32_SATl(v_h, v_l, minIn_h, minIn_l)                               : csh <  |Wx - Wo|
*   C__I16SHRI64C6_LT48_SATl(v_h, v_l, csh32, minIn_h, minIn_l)                        : csh <  |Wx - Wo|
*
*   C__I8SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)  : csh <  |Wx - Wo|
*   C__I8SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l, minIn_h, minIn_l)              : csh <  |Wx - Wo|
*   C__I8SHRI64C6_LT56_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)       : csh <  |Wx - Wo|
*
*   C__I8SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)                    : csh <  |Wx - Wo|
*   C__I8SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)                                : csh <  |Wx - Wo|
*   C__I8SHRI64C6_LT56_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)                         : csh <  |Wx - Wo|
*
*   C__I8SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32, minIn_h, minIn_l)                    : csh <  |Wx - Wo|
*   C__I8SHRI64C6_EQ32_SATl(v_h, v_l, minIn_h, minIn_l)                                : csh <  |Wx - Wo|
*   C__I8SHRI64C6_LT56_SATl(v_h, v_l, csh32, minIn_h, minIn_l)                         : csh <  |Wx - Wo|
*
* NOTE:     
*   -
*
******************************************************************************/

#define C__I32SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT32MAX :\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT32MIN :\
    ( (Int32)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) ) )

#define C__I32SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT32MAX :\
    ( (Int32)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__I32SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32, minIn_h, minIn_l)\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT32MIN :\
    ( (Int32)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )


#define C__I16SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT16MIN :\
    ( (Int16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) ) )

#define C__I16SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l, minIn_h, minIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT16MIN :\
    (Int16)v_h ) )

#define C__I16SHRI64C6_LT48_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT16MIN :\
    (Int16)(v_h >> csh32) ) )


#define C__I16SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    ( (Int16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__I16SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    (Int16)v_h )

#define C__I16SHRI64C6_LT48_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    (Int16)(v_h >> csh32) )


#define C__I16SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32, minIn_h, minIn_l)\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT16MIN :\
    ( (Int16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__I16SHRI64C6_EQ32_SATl(v_h, v_l, minIn_h, minIn_l)\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT16MIN :\
    (Int16)v_h )

#define C__I16SHRI64C6_LT48_SATl(v_h, v_l, csh32, minIn_h, minIn_l)\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT16MIN :\
    (Int16)(v_h >> csh32) ) 


#define C__I8SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT8MIN :\
    ( (Int8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) ) )

#define C__I8SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l, minIn_h, minIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT8MIN :\
    (Int8)v_h ) )

#define C__I8SHRI64C6_LT56_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l, minIn_h, minIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT8MIN :\
    (Int8)(v_h >> csh32) ) ) 


#define C__I8SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    ( (Int8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__I8SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    (Int8)v_h )

#define C__I8SHRI64C6_LT56_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    (Int8)(v_h >> csh32) )


#define C__I8SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32, minIn_h, minIn_l)\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT8MIN :\
    ( (Int8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__I8SHRI64C6_EQ32_SATl(v_h, v_l, minIn_h, minIn_l)\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT8MIN :\
    (Int8)v_h )

#define C__I8SHRI64C6_LT56_SATl(v_h, v_l, csh32, minIn_h, minIn_l)\
    ( ( (v_h < minIn_h)||((v_h == minIn_h)&&(v_l < minIn_l)) ) ? INT8MIN :\
    (Int8)(v_h >> csh32) )

/******************************************************************************
*
* MACROS:
*   C__U32SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*                                                                    
*   C__U16SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*   C__U16SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)             : csh <  |Wx - Wo|
*   C__U16SHRU64C6_LT48_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)      : csh <  |Wx - Wo|
*   
*   C__U8SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)  : csh <  |Wx - Wo|
*   C__U8SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)              : csh <  |Wx - Wo|
*   C__U8SHRU64C6_LT56_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)       : csh <  |Wx - Wo|
*
* NOTE:     
*   -
*
******************************************************************************/

#define C__U32SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT32MAX :\
    ( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) )


#define C__U16SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    ( (UInt16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__U16SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    (UInt16)v_h )

#define C__U16SHRU64C6_LT48_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    (UInt16)(v_h >> csh32) )


#define C__U8SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    ( (UInt8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__U8SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    (UInt8)v_h )

#define C__U8SHRU64C6_LT56_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    (UInt8)(v_h >> csh32) )

/******************************************************************************
*
* MACROS:
*   C__I32SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)             : csh <  |Wx - Wo|
*   C__I32SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*                                                                    
*   C__I16SHRU64C6_EQ48_SATu(v_h, v_l, maxIn_h, maxIn_l)             : csh == |Wx - Wo|
*
*   C__I16SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*   C__I16SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)             : csh <  |Wx - Wo|
*   C__I16SHRU64C6_LT48_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)      : csh <  |Wx - Wo|
*
*   C__I8SHRU64C6_EQ56_SATu(v_h, v_l, maxIn_h, maxIn_l)              : csh == |Wx - Wo|
*
*   C__I8SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)  : csh <  |Wx - Wo|
*   C__I8SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)              : csh <  |Wx - Wo|
*   C__I8SHRU64C6_LT56_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)       : csh <  |Wx - Wo|
*
* NOTE:     
*   -
*
******************************************************************************/

#define C__I32SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT32MAX :\
    (Int32)v_h )

#define C__I32SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT32MAX :\
    ( (Int32)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )


#define C__I16SHRU64C6_EQ48_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    ( (Int16)(v_h >> 16) ) )


#define C__I16SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    ( (Int16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__I16SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    (Int16)v_h )

#define C__I16SHRU64C6_LT48_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT16MAX :\
    (Int16)(v_h >> csh32) )


#define C__I8SHRU64C6_EQ56_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    ( (Int8)(v_h >> 24) ) )


#define C__I8SHRU64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    ( (Int8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__I8SHRU64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    (Int8)v_h )

#define C__I8SHRU64C6_LT56_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? INT8MAX :\
    (Int8)(v_h >> csh32) )

/******************************************************************************
*
* MACROS:                                                                                 
*   C__U32SHRI64C6_GT32_SATl(v_h, v_l, csh32)                        : csh >  |Wx - Wo|
*   C__U32SHRI64C6_EQ32_SATl(v_h, v_l)                               : csh == |Wx - Wo|
*   C__U32SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*   C__U32SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*   C__U32SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32)                   : csh <  |Wx - Wo|
*
*   C__U32SHRI64C6_EQ31_SATl(v_h, v_l)                               : csh <  |Wx - Wo|
*                                                                                      
*                                                                    
*   C__U16SHRI64C6_GT48_SATl(v_h, v_l, csh32)                        : csh >  |Wx - Wo|
*   C__U16SHRI64C6_EQ48_SATl(v_h, v_l)                               : csh == |Wx - Wo|
*                                                                                      
*   C__U16SHRI64C6_EQ47_SATl(v_h, v_l)                               : csh <  |Wx - Wo|
*   C__U16SHRI64C6_LT47_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l)      : csh <  |Wx - Wo|
*   C__U16SHRI64C6_LT47_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)      : csh <  |Wx - Wo|
*   C__U16SHRI64C6_LT47_SATl(v_h, v_l, csh32)                        : csh <  |Wx - Wo|
*
*   C__U16SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l)             : csh <  |Wx - Wo|
*   C__U16SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)             : csh <  |Wx - Wo|
*   C__U16SHRI64C6_EQ32_SATl(v_h, v_l)                               : csh <  |Wx - Wo|
*   C__U16SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*   C__U16SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l) : csh <  |Wx - Wo|
*   C__U16SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32)                   : csh <  |Wx - Wo|
*
*
*   C__U8SHRI64C6_GT56_SATl(v_h, v_l, csh32)                         : csh >  |Wx - Wo|
*   C__U8SHRI64C6_EQ56_SATl(v_h, v_l)                                : csh == |Wx - Wo|
*
*   C__U8SHRI64C6_EQ55_SATl(v_h, v_l)                                : csh <  |Wx - Wo|
*   C__U8SHRI64C6_LT55_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l)       : csh <  |Wx - Wo|
*   C__U8SHRI64C6_LT55_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)       : csh <  |Wx - Wo|
*   C__U8SHRI64C6_LT55_SATl(v_h, v_l, csh32)                         : csh <  |Wx - Wo|
*                                                                                      
*   C__U8SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l)              : csh <  |Wx - Wo|
*   C__U8SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)              : csh <  |Wx - Wo|
*   C__U8SHRI64C6_EQ32_SATl(v_h, v_l)                                : csh <  |Wx - Wo|
*   C__U8SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)  : csh <  |Wx - Wo|
*   C__U8SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)  : csh <  |Wx - Wo|
*   C__U8SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32)                    : csh <  |Wx - Wo|
*                                                                                         
* NOTE:     
*   -
*
******************************************************************************/

#define C__U32SHRI64C6_GT32_SATl(v_h, v_l, csh32)\
    ( (v_h < 0) ? 0 : (UInt32)(Int32)(v_h >> csh32) )

#define C__U32SHRI64C6_EQ32_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : (UInt32)v_h )

#define C__U32SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT32MAX :\
    ( (v_h < 0) ? 0 : ( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__U32SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT32MAX :\
    ( ( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__U32SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32)\
    ( (v_h < 0) ? 0 : ( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) )

#define C__U32SHRI64C6_EQ31_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : ( (UInt32)(v_l >> 31) | (UInt32)(v_h << 1) ) )


#define C__U16SHRI64C6_GT48_SATl(v_h, v_l, csh32)\
    ( (v_h < 0) ? 0 : (UInt16)(Int16)(v_h >> csh32) )

#define C__U16SHRI64C6_EQ48_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : (UInt16)(Int16)(v_h >> 16) )

#define C__U16SHRI64C6_EQ47_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : (UInt16)(Int16)(v_h >> 15) )

#define C__U16SHRI64C6_LT47_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    ( (v_h < 0) ? 0 : (UInt16)(Int16)(v_h >> csh32) ) )

#define C__U16SHRI64C6_LT47_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    (UInt16)(Int16)(v_h >> csh32) )

#define C__U16SHRI64C6_LT47_SATl(v_h, v_l, csh32)\
    ( (v_h < 0) ? 0 : (UInt16)(Int16)(v_h >> csh32) )

#define C__U16SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    ( (v_h < 0) ? 0 : (UInt16)v_h ) )

#define C__U16SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    (UInt16)v_h )

#define C__U16SHRI64C6_EQ32_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : (UInt16)v_h )

#define C__U16SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    ( (v_h < 0) ? 0 : (UInt16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__U16SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT16MAX :\
    (UInt16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) )

#define C__U16SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32)\
    ( (v_h < 0) ? 0 : (UInt16)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) )


#define C__U8SHRI64C6_GT56_SATl(v_h, v_l, csh32)\
    ( (v_h < 0) ? 0 : (UInt8)(Int8)(v_h >> csh32) )

#define C__U8SHRI64C6_EQ56_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : (UInt8)(Int8)(v_h >> 24) )

#define C__U8SHRI64C6_EQ55_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : (UInt8)(Int8)(v_h >> 23) )

#define C__U8SHRI64C6_LT55_SATb(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    ( (v_h < 0) ? 0 : (UInt8)(Int8)(v_h >> csh32) ) )

#define C__U8SHRI64C6_LT55_SATu(v_h, v_l, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    (UInt8)(Int8)(v_h >> csh32) )

#define C__U8SHRI64C6_LT55_SATl(v_h, v_l, csh32)\
    ( (v_h < 0) ? 0 : (UInt8)(Int8)(v_h >> csh32) )

#define C__U8SHRI64C6_EQ32_SATb(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    ( (v_h < 0) ? 0 : (UInt8)v_h ) )

#define C__U8SHRI64C6_EQ32_SATu(v_h, v_l, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    (UInt8)v_h )

#define C__U8SHRI64C6_EQ32_SATl(v_h, v_l)\
    ( (v_h < 0) ? 0 : (UInt8)v_h )

#define C__U8SHRI64C6_LT32_SATb(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    ( (v_h < 0) ? 0 : (UInt8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) ) )

#define C__U8SHRI64C6_LT32_SATu(v_h, v_l, csh, csh32, maxIn_h, maxIn_l)\
    ( ( (v_h > maxIn_h)||((v_h == maxIn_h)&&(v_l > maxIn_l)) ) ? UINT8MAX :\
    (UInt8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) )

#define C__U8SHRI64C6_LT32_SATl(v_h, v_l, csh, csh32)\
    ( (v_h < 0) ? 0 : (UInt8)( (UInt32)(v_l >> csh) | (UInt32)(v_h << csh32) ) )


#endif /* #ifndef __shr_h__ */
