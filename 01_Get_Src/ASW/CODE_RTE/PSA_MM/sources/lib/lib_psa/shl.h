/******************************************************************************
*
* FILE:
*   shl.h
*
* RELATED FILES:
*
* DESCRIPTION:
*   This file contains macro definitions for the operation Shift Left.
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
*     operation              : SHL
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
*    hi          upper part of a combined
*                64-bit input/output           rwVars, NoConsts, NoComplexExpr 
*    lo          lower part of a combined 
*                64-bit input/output           rwVars, NoConsts, NoComplexExpr 
*    maxIn      const upper input limit        rVars,  Consts,   NoComplexExpr    
*    minIn      const lower input limit        rVars,  Consts,   NoComplexExpr    
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
* AUTHOR(S):
*    O. Grajetzky, D. Andoleit
*
* Copyright (c) 2002 dSPACE GmbH, GERMANY
*
* $Workfile: shl.h $ $Revision: 1.3 $ $Date: 2006/04/19 11:34:24GMT+01:00 $ $Author: DagmarA $
******************************************************************************/

#ifndef __shl_h__
#define __shl_h__


/******************************************************************************
*
* GENERAL:
*   Generic rules, no saturation
*   (SH < Wo), (Wo == 64) && (Wx <= 32)
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I64SHLI32C6_LT32(v, csh, csh32, r_h, r_l)
*   C__I64SHLI32C6_EQ32(v, r_h, r_l)
*   C__I64SHLI32C6_GT32(v, csh32, r_h, r_l)
*
*   C__I64SHLI16C6_LT32(v, csh, csh32, r_h, r_l)
*   C__I64SHLI16C6_EQ32(v, r_h, r_l)
*   C__I64SHLI16C6_GT32(v, csh32, r_h, r_l)
*
*   C__I64SHLI8C6_LT32(v, csh, csh32, r_h, r_l)
*   C__I64SHLI8C6_EQ32(v, r_h, r_l)
*   C__I64SHLI8C6_GT32(v, csh32, r_h, r_l)
*
*   C__I64SHLI32U6(v, sh, r_h, r_l)
*
* NOTE:     
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression.
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHLI32C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (Int32)((v) >> csh32);\
    r_l = (UInt32)((v) << csh)

#define C__I64SHLI32C6_EQ32(v, r_h, r_l)\
    r_h = v;\
    r_l = 0 

#define C__I64SHLI32C6_GT32(v, csh32, r_h, r_l)\
    r_h = (Int32)((v) << csh32);\
    r_l = 0

#define C__I64SHLI16C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (Int32)((v) >> csh32);\
    r_l = (UInt32)((Int32)(v) << csh)         

#define C__I64SHLI16C6_EQ32(v, r_h, r_l)\
    r_h = (Int32)(v);\
    r_l = 0 

#define C__I64SHLI16C6_GT32(v, csh32, r_h, r_l)\
    r_h = (Int32)((Int32)(v) << csh32);\
    r_l = 0 

#define C__I64SHLI8C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (Int32)((v) >> csh32);\
    r_l = (UInt32)((Int32)(v) << csh) 

#define C__I64SHLI8C6_EQ32(v, r_h, r_l)\
    r_h = (Int32)(v);\
    r_l = 0 

#define C__I64SHLI8C6_GT32(v, csh32, r_h, r_l)\
    r_h = (Int32)((Int32)(v) << csh32);\
    r_l = 0

#define C__I64SHLI32U6(v, sh, r_h, r_l)\
    if(sh != 0)\
    {\
        if(sh<32)\
        {\
            r_h = (Int32)((v) >> (32-sh));\
            r_l = (UInt32)((v) << sh);\
        }\
        else if(sh==32)\
        {\
            r_h = v;\
            r_l = 0;\
        }\
        else\
        {\
            r_h = (Int32)((v) << (sh-32));\
            r_l = 0;\
        }\
    }


/******************************************************************************
*
* MACROS:
*   C__U64SHLU32C6_LT32(v, csh, csh32, r_h, r_l)
*   C__U64SHLU32C6_EQ32(v, r_h, r_l)
*   C__U64SHLU32C6_GT32(v, csh32, r_h, r_l)
*
*   C__U64SHLU16C6_LT32(v, csh, csh32, r_h, r_l)
*   C__U64SHLU16C6_EQ32(v, r_h, r_l)
*   C__U64SHLU16C6_GT32(v, csh32, r_h, r_l)
*
*   C__U64SHLU8C6_LT32(v, csh, csh32, r_h, r_l)
*   C__U64SHLU8C6_EQ32(v, r_h, r_l)
*   C__U64SHLU8C6_GT32(v, csh32, r_h, r_l)
*
*   C__U64SHLU32U6(v, sh, r_h, r_l)
*
* NOTE:
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression. 
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHLU32C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (UInt32)((v) >> csh32);\
    r_l = (UInt32)((v) << csh)

#define C__U64SHLU32C6_EQ32(v, r_h, r_l)\
    r_h = v;\
    r_l = 0

#define C__U64SHLU32C6_GT32(v, csh32, r_h, r_l)\
    r_h = (UInt32)((v) << csh32);\
    r_l = 0

#define C__U64SHLU16C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (UInt32)((v) >> csh32);\
    r_l = (UInt32)((UInt32)(v) << csh)

#define C__U64SHLU16C6_EQ32(v, r_h, r_l)\
    r_h = (UInt32)(v);\
    r_l = 0

#define C__U64SHLU16C6_GT32(v, csh32, r_h, r_l)\
    r_h = (UInt32)((UInt32)(v) << csh32);\
    r_l = 0

#define C__U64SHLU8C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (UInt32)((v) >> csh32);\
    r_l = (UInt32)((UInt32)(v) << csh)

#define C__U64SHLU8C6_EQ32(v, r_h, r_l)\
    r_h = (UInt32)(v);\
    r_l = 0

#define C__U64SHLU8C6_GT32(v, csh32, r_h, r_l)\
    r_h = (UInt32)((UInt32)(v) << csh32);\
    r_l = 0

#define C__U64SHLU32U6(v, sh, r_h, r_l)\
    if(sh != 0)\
    {\
        if(sh<32)\
        {\
            r_h = (UInt32)((v) >> (32-sh));\
            r_l = (UInt32)((v) << sh);\
        }\
        else if(sh==32)\
        {\
            r_h = v;\
            r_l = 0;\
        }\
        else\
        {\
            r_h = (UInt32)((v) << (sh-32));\
            r_l = 0;\
        }\
    }


/******************************************************************************
*
* MACROS:
*   C__I64SHLU32C6_LT32(v, csh, csh32, r_h, r_l)
*   C__I64SHLU32C6_EQ32(v, r_h, r_l)
*   C__I64SHLU32C6_GT32(v, csh32, r_h, r_l)
*
*   C__I64SHLU16C6_LT32(v, csh, csh32, r_h, r_l)
*   C__I64SHLU16C6_EQ32(v, r_h, r_l)
*   C__I64SHLU16C6_GT32(v, csh32, r_h, r_l)
*
*   C__I64SHLU8C6_LT32(v, csh, csh32, r_h, r_l)
*   C__I64SHLU8C6_EQ32(v, r_h, r_l)
*   C__I64SHLU8C6_GT32(v, csh32, r_h, r_l)
*
*   C__I64SHLU32U6(v, sh, r_h, r_l)
*
* NOTE:
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression. 
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHLU32C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (Int32)((v) >> csh32);\
    r_l = (UInt32)((v) << csh)

#define C__I64SHLU32C6_EQ32(v, r_h, r_l)\
    r_h = (Int32)(v);\
    r_l = 0 

#define C__I64SHLU32C6_GT32(v, csh32, r_h, r_l)\
    r_h = (Int32)((v) << csh32);\
    r_l = 0

#define C__I64SHLU16C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (Int32)((v) >> csh32);\
    r_l = (UInt32)((UInt32)(v) << csh)

#define C__I64SHLU16C6_EQ32(v, r_h, r_l)\
    r_h = (Int32)(v);\
    r_l = 0

#define C__I64SHLU16C6_GT32(v, csh32, r_h, r_l)\
    r_h = (Int32)((UInt32)(v) << csh32);\
    r_l = 0

#define C__I64SHLU8C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (Int32)((v) >> csh32);\
    r_l = (UInt32)((UInt32)(v) << csh) 

#define C__I64SHLU8C6_EQ32(v, r_h, r_l)\
    r_h = (Int32)(v);\
    r_l = 0

#define C__I64SHLU8C6_GT32(v, csh32, r_h, r_l)\
    r_h = (Int32)((UInt32)(v) << csh32);\
    r_l = 0

#define C__I64SHLU32U6(v, sh, r_h, r_l)\
    if(sh != 0)\
    {\
        if(sh<32)\
        {\
            r_h = (Int32)((v) >> (32-sh));\
            r_l = (UInt32)((v) << sh);\
        }\
        else if(sh==32)\
        {\
            r_h = (Int32)(v);\
            r_l = 0;\
        }\
        else\
        {\
            r_h = (Int32)((v) << (sh-32));\
            r_l = 0;\
        }\
    }


/******************************************************************************
*
* MACROS:
*   C__U64SHLI32C6_LT32(v, csh, csh32, r_h, r_l)
*   C__U64SHLI32C6_EQ32(v, r_h, r_l)
*   C__U64SHLI32C6_GT32(v, csh32, r_h, r_l)
*
*   C__U64SHLI16C6_LT32(v, csh, csh32, r_h, r_l)
*   C__U64SHLI16C6_EQ32(v, r_h, r_l)
*   C__U64SHLI16C6_GT32(v, csh32, r_h, r_l)
*
*   C__U64SHLI8C6_LT32(v, csh, csh32, r_h, r_l)
*   C__U64SHLI8C6_EQ32(v, r_h, r_l)
*   C__U64SHLI8C6_GT32(v, csh32, r_h, r_l)
*
*   C__U64SHLI32U6(v, csh32, r_h, r_l)
*
* NOTE:
*   The input value is used more than once inside the macro body.
*   Thus, for performance reasons, the input value should be no expression. 
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHLI32C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (UInt32)(Int32)((v) >> csh32);\
    r_l = (UInt32)((v) << csh)

#define C__U64SHLI32C6_EQ32(v, r_h, r_l)\
    r_h = (UInt32)(v);\
    r_l = 0

#define C__U64SHLI32C6_GT32(v, csh32, r_h, r_l)\
    r_h = (UInt32)((v) << csh32);\
    r_l = 0

#define C__U64SHLI16C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (UInt32)(Int32)((v) >> csh32);\
    r_l = (UInt32)((Int32)(v) << csh)

#define C__U64SHLI16C6_EQ32(v, r_h, r_l)\
    r_h = (UInt32)(v);\
    r_l = 0

#define C__U64SHLI16C6_GT32(v, csh32, r_h, r_l)\
    r_h = (UInt32)((Int32)(v) << csh32);\
    r_l = 0

#define C__U64SHLI8C6_LT32(v, csh, csh32, r_h, r_l)\
    r_h = (UInt32)(Int32)((v) >> csh32);\
    r_l = (UInt32)((Int32)(v) << csh)

#define C__U64SHLI8C6_EQ32(v, r_h, r_l)\
    r_h = (UInt32)(v);\
    r_l = 0

#define C__U64SHLI8C6_GT32(v, csh32, r_h, r_l)\
    r_h = (UInt32)((Int32)(v) << csh32);\
    r_l = 0

#define C__U64SHLI32U6(v, sh, r_h, r_l)\
    if(sh != 0)\
    {\
        if(sh<32)\
        {\
            r_h = (UInt32)(Int32)((v) >> (32-sh));\
            r_l = (UInt32)((v) << sh);\
        }\
        else if(sh==32)\
        {\
            r_h = (UInt32)(v);\
            r_l = 0;\
        }\
        else\
        {\
            r_h = (UInt32)((v) << (sh-32));\
            r_l = 0;\
        }\
    }


/******************************************************************************
*
* GENERAL:
*   Generic rules, no saturation
*   (SH < Wo), (Wo == 64) && (Wx == 64)
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__I64SHLI64C6_LT32(hi, lo, csh, csh32)
*   C__I64SHLI64C6_EQ32(hi, lo)
*   C__I64SHLI64C6_GT32(hi, lo, csh32)
*
*   C__I64SHLI64U6(hi, lo, sh)
*
* NOTE:
*   The input values are modified.
*   Use these macros only with temporary variables.
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHLI64C6_LT32(hi, lo, csh, csh32)\
    hi = (Int32)(/* CTO */ (UInt32)(hi << csh) + (UInt32)(lo >> csh32) );\
    lo = (UInt32)(lo << csh)

#define C__I64SHLI64C6_EQ32(hi, lo)\
    hi = (Int32)lo;\
    lo = 0                                               

#define C__I64SHLI64C6_GT32(hi, lo, csh32)\
    hi = (Int32)(lo << csh32);\
    lo = 0

#define C__I64SHLI64U6(hi, lo, sh)\
    if(sh != 0)\
    {\
        if(sh < 32)\
        {\
            hi = (Int32)(/* CTO */ (UInt32)(hi << sh) + (UInt32)(lo >> (32-sh)) );\
            lo = (UInt32)(lo << sh);\
        }\
        else if (sh == 32)\
        {\
            hi = (Int32)lo;\
            lo = 0;\
        }\
        else\
        {\
            hi = (Int32)(lo << (sh-32) );\
            lo = 0;\
        }\
    }


/******************************************************************************
*
* MACROS:
*   C__U64SHLU64C6_LT32(v_h, v_l, csh, csh32)
*   C__U64SHLU64C6_EQ32(v_h, v_l)
*   C__U64SHLU64C6_GT32(v_h, v_l, csh32)
*
*   C__U64SHLU64U6(v_h, v_l, sh)
*   
* NOTE:
*   The input values are modified.
*   Use these macros only with temporary variables.
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHLU64C6_LT32(hi, lo, csh, csh32)\
    hi = (UInt32)(hi << csh) + (UInt32)(lo >> csh32);\
    lo = (UInt32)(lo << csh)

#define C__U64SHLU64C6_EQ32(hi, lo)\
    hi = lo;\
    lo = 0

#define C__U64SHLU64C6_GT32(hi, lo, csh32)\
    hi = (UInt32)(lo << csh32);\
    lo = 0

#define C__U64SHLU64U6(hi, lo, sh)\
    if(sh != 0)\
    {\
        if(sh < 32)\
        {\
            hi = (UInt32)(hi << sh) + (UInt32)(lo >> (32-sh));\
            lo = (UInt32)(lo << sh);\
        }\
        else if (sh == 32)\
        {\
            hi = lo;\
            lo = 0;\
        }\
        else\
        {\
            hi = (UInt32)(lo << (sh-32));\
            lo = 0;\
        }\
    }


/******************************************************************************
*
* MACROS:
*   C__I64SHLU64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)
*   C__I64SHLU64C6_EQ32(v_l, r_h, r_l)
*   C__I64SHLU64C6_GT32(v_l, csh32, r_h, r_l)
*
*   C__I64SHLU64U6(v_h, v_l, sh, r_h, r_l)
*   
* NOTE:
*   These macros do not have a return value.
*
******************************************************************************/

#define C__I64SHLU64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)\
    r_h = (Int32)( (UInt32)(v_h << csh) + (UInt32)(v_l >> csh32) );\
    r_l = (UInt32)(r_l << csh)

#define C__I64SHLU64C6_EQ32(v_l, r_h, r_l)\
    r_h = (Int32)v_l;\
    r_l = 0

#define C__I64SHLU64C6_GT32(v_l, csh32, r_h, r_l)\
    r_h = (Int32)(v_l << csh32);\
    r_l = 0

#define C__I64SHLU64U6(v_h, v_l, sh, r_h, r_l)\
    if(sh != 0)\
    {\
        if(sh < 32)\
        {\
            r_h = (Int32)( (UInt32)(v_h << sh) + (UInt32)(v_l >> (32-sh)) );\
            r_l = (UInt32)(r_l << sh);\
        }\
        else if (sh == 32)\
        {\
            r_h = (Int32)v_l;\
            r_l = 0;\
        }\
        else\
        {\
            r_h = (Int32)(v_l << (sh-32));\
            r_l = 0;\
        }\
    }


/******************************************************************************
*
* MACROS:
*   C__U64SHLI64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)
*   C__U64SHLI64C6_EQ32(v_l, r_h, r_l)
*   C__U64SHLI64C6_GT32(v_l, csh32, r_h, r_l)
*
*   C__U64SHLI64U6(v_h, v_l, sh, r_h, r_l)
*   
* NOTE:
*   These macros do not have a return value.
*
******************************************************************************/

#define C__U64SHLI64C6_LT32(v_h, v_l, csh, csh32, r_h, r_l)\
    r_h = (UInt32)(v_h << csh) + (UInt32)(v_l >> csh32);\
    r_l = (UInt32)(r_l << csh)

#define C__U64SHLI64C6_EQ32(v_l, r_h, r_l)\
    r_h = v_l;\
    r_l = 0

#define C__U64SHLI64C6_GT32(v_l, csh32, r_h, r_l)\
    r_h = (UInt32)(v_l << csh32);\
    r_l = 0

#define C__U64SHLI64U6(v_h, v_l, sh, r_h, r_l)\
    if(sh != 0)\
    {\
        if(sh < 32)\
        {\
            r_h = (UInt32)(v_h << sh) + (UInt32)(v_l >> (32-sh));\
            r_l = (UInt32)(r_l << sh);\
        }\
        else if (sh == 32)\
        {\
            r_h = v_l;\
            r_l = 0;\
        }\
        else\
        {\
            r_h = (UInt32)(v_l << (sh-32));\
            r_l = 0;\
        }\
    }


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
*   C__I32SHLI32C6_SATb(v, csh, maxIn, minIn)
*   C__I32SHLI32C6_SATu(v, csh, maxIn)
*   C__I32SHLI32C6_SATl(v, csh, minIn)
*
*   C__I32SHLI16C6_SATb(v, csh, maxIn, minIn)
*   C__I32SHLI16C6_SATu(v, csh, maxIn)
*   C__I32SHLI16C6_SATl(v, csh, minIn)
*
*   C__I32SHLI8C6_SATb(v, csh, maxIn, minIn)
*   C__I32SHLI8C6_SATu(v, csh, maxIn)
*   C__I32SHLI8C6_SATl(v, csh, minIn)
*
*
*   C__I16SHLI32C6_SATb(v, csh, maxIn, minIn)
*   C__I16SHLI32C6_SATu(v, csh, maxIn)
*   C__I16SHLI32C6_SATl(v, csh, minIn)
*
*   C__I16SHLI16C6_SATb(v, csh, maxIn, minIn)
*   C__I16SHLI16C6_SATu(v, csh, maxIn)
*   C__I16SHLI16C6_SATl(v, csh, minIn)
*
*   C__I16SHLI8C6_SATb(v, csh, maxIn, minIn)
*   C__I16SHLI8C6_SATu(v, csh, maxIn)
*   C__I16SHLI8C6_SATl(v, csh, minIn)
*
*
*   C__I8SHLI32C6_SATb(v, csh, maxIn, minIn)
*   C__I8SHLI32C6_SATu(v, csh, maxIn)
*   C__I8SHLI32C6_SATl(v, csh, minIn)
*
*   C__I8SHLI16C6_SATb(v, csh, maxIn, minIn)
*   C__I8SHLI16C6_SATu(v, csh, maxIn)
*   C__I8SHLI16C6_SATl(v, csh, minIn)
*
*   C__I8SHLI8C6_SATb(v, csh, maxIn, minIn)
*   C__I8SHLI8C6_SATu(v, csh, maxIn)
*   C__I8SHLI8C6_SATl(v, csh, minIn)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1  ;  minIn = ~maxIn
*               2^csh
*
******************************************************************************/

#define C__I32SHLI32C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : ( (v < minIn) ? (Int32)INT32MIN : (Int32)(v << csh) ) ) 

#define C__I32SHLI32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : (Int32)(v << csh) ) 

#define C__I32SHLI32C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int32)INT32MIN : (Int32)(v << csh) )  


#define C__I32SHLI16C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : ( (v < minIn) ? (Int32)INT32MIN : (Int32)((Int32)v << csh) ) ) 

#define C__I32SHLI16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : (Int32)((Int32)v << csh) ) 

#define C__I32SHLI16C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int32)INT32MIN : (Int32)((Int32)v << csh) )  


#define C__I32SHLI8C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : ( (v < minIn) ? (Int32)INT32MIN : (Int32)((Int32)v << csh) ) ) 

#define C__I32SHLI8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : (Int32)((Int32)v << csh) ) 

#define C__I32SHLI8C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int32)INT32MIN : (Int32)((Int32)v << csh) )  


#define C__I16SHLI32C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : ( (v < minIn) ? (Int16)INT16MIN : (Int16)(v << csh) ) ) 

#define C__I16SHLI32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : (Int16)(v << csh) ) 

#define C__I16SHLI32C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int16)INT16MIN : (Int16)(v << csh) )  


#define C__I16SHLI16C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : ( (v < minIn) ? (Int16)INT16MIN : (Int16)(v << csh) ) ) 

#define C__I16SHLI16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : (Int16)(v << csh) ) 

#define C__I16SHLI16C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int16)INT16MIN : (Int16)(v << csh) )  


#define C__I16SHLI8C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : ( (v < minIn) ? (Int16)INT16MIN : (Int16)((Int16)v << csh) ) ) 

#define C__I16SHLI8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : (Int16)((Int16)v << csh) ) 

#define C__I16SHLI8C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int16)INT16MIN : (Int16)((Int16)v << csh) )  


#define C__I8SHLI32C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : ( (v < minIn) ? (Int8)INT8MIN : (Int8)(v << csh) ) ) 

#define C__I8SHLI32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : (Int8)(v << csh) ) 

#define C__I8SHLI32C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int8)INT8MIN : (Int8)(v << csh) )  


#define C__I8SHLI16C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : ( (v < minIn) ? (Int8)INT8MIN : (Int8)(v << csh) ) ) 

#define C__I8SHLI16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : (Int8)(v << csh) ) 

#define C__I8SHLI16C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int8)INT8MIN : (Int8)(v << csh) )  


#define C__I8SHLI8C6_SATb(v, csh, maxIn, minIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : ( (v < minIn) ? (Int8)INT8MIN : (Int8)(v << csh) ) ) 

#define C__I8SHLI8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : (Int8)(v << csh) ) 

#define C__I8SHLI8C6_SATl(v, csh, minIn)\
    ( (v < minIn) ? (Int8)INT8MIN : (Int8)(v << csh) )  


/******************************************************************************
*
* MACROS:
*   C__U32SHLU32C6_SATu(v, csh, maxIn)
*   
*   C__U32SHLU16C6_SATu(v, csh, maxIn)
*
*   C__U32SHLU8C6_SATu(v, csh, maxIn)
*   
*   
*   C__U16SHLU32C6_SATu(v, csh, maxIn)
*   
*   C__U16SHLU16C6_SATu(v, csh, maxIn)
*   
*   C__U16SHLU8C6_SATu(v, csh, maxIn)
*
*   
*   C__U8SHLU32C6_SATu(v, csh, maxIn)
*   
*   C__U8SHLU16C6_SATu(v, csh, maxIn)
*   
*   C__U8SHLU8C6_SATu(v, csh, maxIn)
*   
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1
*               2^csh
*
******************************************************************************/

#define C__U32SHLU32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : (UInt32)(v << csh) )

#define C__U32SHLU16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : (UInt32)((UInt32)v << csh) ) 

#define C__U32SHLU8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : (UInt32)((UInt32)v << csh) ) 

#define C__U16SHLU32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : (UInt16)(v << csh) ) 

#define C__U16SHLU16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : (UInt16)(v << csh) ) 

#define C__U16SHLU8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : (UInt16)((UInt16)v << csh) ) 

#define C__U8SHLU32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : (UInt8)(v << csh) ) 

#define C__U8SHLU16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : (UInt8)(v << csh) ) 

#define C__U8SHLU8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : (UInt8)(v << csh) ) 


/******************************************************************************
*
* MACROS:
*   C__I32SHLU32C6_SATu(v, csh, maxIn)
*   
*   C__I32SHLU16C6_SATu(v, csh, maxIn)
*
*   C__I32SHLU8C6_SATu(v, csh, maxIn)
*   
*   
*   C__I16SHLU32C6_SATu(v, csh, maxIn)
*   
*   C__I16SHLU16C6_SATu(v, csh, maxIn)
*   
*   C__I16SHLU8C6_SATu(v, csh, maxIn)
*
*   
*   C__I8SHLU32C6_SATu(v, csh, maxIn)
*   
*   C__I8SHLU16C6_SATu(v, csh, maxIn)
*   
*   C__I8SHLU8C6_SATu(v, csh, maxIn)
*   
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1
*               2^csh
*
******************************************************************************/

#define C__I32SHLU32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : (Int32)(v << csh) ) 

#define C__I32SHLU16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : (Int32)((UInt32)v << csh) ) 

#define C__I32SHLU8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int32)INT32MAX : (Int32)((UInt32)v << csh) ) 

#define C__I16SHLU32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : (Int16)(v << csh) ) 

#define C__I16SHLU16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : (Int16)(v << csh) ) 

#define C__I16SHLU8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int16)INT16MAX : (Int16)((UInt16)v << csh) ) 

#define C__I8SHLU32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : (Int8)(v << csh) ) 

#define C__I8SHLU16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : (Int8)(v << csh) ) 

#define C__I8SHLU8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (Int8)INT8MAX : (Int8)(v << csh) ) 


/******************************************************************************
*
* MACROS:
*   C__U32SHLI32C6_SATb(v, csh, maxIn)
*   C__U32SHLI32C6_SATu(v, csh, maxIn)
*   C__U32SHLI32C6_SATl(v, csh)
*
*   C__U32SHLI16C6_SATb(v, csh, maxIn)
*   C__U32SHLI16C6_SATu(v, csh, maxIn)
*   C__U32SHLI16C6_SATl(v, csh)
*
*   C__U32SHLI8C6_SATb(v, csh, maxIn)
*   C__U32SHLI8C6_SATu(v, csh, maxIn)
*   C__U32SHLI8C6_SATl(v, csh)
*
*
*   C__U16SHLI32C6_SATb(v, csh, maxIn)
*   C__U16SHLI32C6_SATu(v, csh, maxIn)
*   C__U16SHLI32C6_SATl(v, csh)
*
*   C__U16SHLI16C6_SATb(v, csh, maxIn)
*   C__U16SHLI16C6_SATu(v, csh, maxIn)
*   C__U16SHLI16C6_SATl(v, csh)
*
*   C__U16SHLI8C6_SATb(v, csh, maxIn)
*   C__U16SHLI8C6_SATu(v, csh, maxIn)
*   C__U16SHLI8C6_SATl(v, csh)
*
*
*   C__U8SHLI32C6_SATb(v, csh, maxIn)
*   C__U8SHLI32C6_SATu(v, csh, maxIn)
*   C__U8SHLI32C6_SATl(v, csh)
*
*   C__U8SHLI16C6_SATb(v, csh, maxIn)
*   C__U8SHLI16C6_SATu(v, csh, maxIn)
*   C__U8SHLI16C6_SATl(v, csh)
*
*   C__U8SHLI8C6_SATb(v, csh, maxIn)
*   C__U8SHLI8C6_SATu(v, csh, maxIn)
*   C__U8SHLI8C6_SATl(v, csh)
*
* NOTE:
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1
*               2^csh
*
******************************************************************************/

#define C__U32SHLI32C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : ( (v < 0) ? 0 : (UInt32)(v << csh) ) ) 

#define C__U32SHLI32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : (UInt32)(v << csh) ) 

#define C__U32SHLI32C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt32)(v << csh) )  


#define C__U32SHLI16C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : ( (v < 0) ? 0 : (UInt32)((Int32)v << csh) ) ) 

#define C__U32SHLI16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : (UInt32)((Int32)v << csh) )

#define C__U32SHLI16C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt32)((Int32)v << csh) )  


#define C__U32SHLI8C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : ( (v < 0) ? 0 : (UInt32)((Int32)v << csh) ) ) 

#define C__U32SHLI8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt32)UINT32MAX : (UInt32)((Int32)v << csh) ) 

#define C__U32SHLI8C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt32)((Int32)v << csh) )  


#define C__U16SHLI32C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : ( (v < 0) ? 0 : (UInt16)(v << csh) ) )

#define C__U16SHLI32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : (UInt16)(v << csh) ) 

#define C__U16SHLI32C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt16)(v << csh) )  


#define C__U16SHLI16C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : ( (v < 0) ? 0 : (UInt16)(v << csh) ) )

#define C__U16SHLI16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : (UInt16)(v << csh) ) 

#define C__U16SHLI16C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt16)(v << csh) )  


#define C__U16SHLI8C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : ( (v < 0) ? 0 : (UInt16)((Int16)v << csh) ) ) 

#define C__U16SHLI8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt16)UINT16MAX : (UInt16)((Int16)v << csh) ) 

#define C__U16SHLI8C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt16)((Int16)v << csh) )  


#define C__U8SHLI32C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : ( (v < 0) ? 0 : (UInt8)(v << csh) ) ) 

#define C__U8SHLI32C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : (UInt8)(v << csh) ) 

#define C__U8SHLI32C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(v << csh) )  


#define C__U8SHLI16C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : ( (v < 0) ? 0 : (UInt8)(v << csh) ) ) 

#define C__U8SHLI16C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : (UInt8)(v << csh) ) 

#define C__U8SHLI16C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(v << csh) )  


#define C__U8SHLI8C6_SATb(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : ( (v < 0) ? 0 : (UInt8)(v << csh) ) )

#define C__U8SHLI8C6_SATu(v, csh, maxIn)\
    ( (v > maxIn) ? (UInt8)UINT8MAX : (UInt8)(v << csh) ) 

#define C__U8SHLI8C6_SATl(v, csh)\
    ( (v < 0) ? 0 : (UInt8)(v << csh) )  


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
*   C__I32SHLI64C6_SATb(v_h, v_l, csh, maxIn_l, minIn_l)
*   C__I32SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)
*   C__I32SHLI64C6_SATl(v_h, v_l, csh, minIn_l)
*
*   C__I16SHLI64C6_SATb(v_h, v_l, csh, maxIn_l, minIn_l)
*   C__I16SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)
*   C__I16SHLI64C6_SATl(v_h, v_l, csh, minIn_l)
*   
*   C__I8SHLI64C6_SATb(v_h, v_l, csh, maxIn_l, minIn_l)
*   C__I8SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)
*   C__I8SHLI64C6_SATl(v_h, v_l, csh, minIn_l)
*   
* NOTE:
*   The input parameters are not put in parantheses inside the macro body.
*   Thus, the input values must not be expressions. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1  ;  minIn = ~maxIn
*               2^csh
*
******************************************************************************/

#define C__I32SHLI64C6_SATb(v_h, v_l, csh, maxIn_l, minIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int32)INT32MAX :\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < minIn_l)) ) ? (Int32)INT32MIN :\
    (Int32)(v_l << csh) ) )

#define C__I32SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int32)INT32MAX :\
    (Int32)(v_l << csh) )

#define C__I32SHLI64C6_SATl(v_h, v_l, csh, minIn_l)\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < minIn_l)) ) ? (Int32)INT32MIN :\
    (Int32)(v_l << csh) )


#define C__I16SHLI64C6_SATb(v_h, v_l, csh, maxIn_l, minIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int16)INT16MAX :\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < minIn_l)) ) ? (Int16)INT16MIN :\
    (Int16)(v_l << csh) ) )

#define C__I16SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int16)INT16MAX :\
    (Int16)(v_l << csh) )

#define C__I16SHLI64C6_SATl(v_h, v_l, csh, minIn_l)\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < minIn_l)) ) ? (Int16)INT16MIN :\
    (Int16)(v_l << csh) )


#define C__I8SHLI64C6_SATb(v_h, v_l, csh, maxIn_l, minIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int8)INT8MAX :\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < minIn_l)) ) ? (Int8)INT8MIN :\
    (Int8)(v_l << csh) ) )

#define C__I8SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int8)INT8MAX :\
    (Int8)(v_l << csh) )

#define C__I8SHLI64C6_SATl(v_h, v_l, csh, minIn_l)\
    ( ( (v_h < -1)||((v_h == -1)&&(v_l < minIn_l)) ) ? (Int8)INT8MIN :\
    (Int8)(v_l << csh) )


/******************************************************************************
*
* MACROS:
*   C__U32SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)
*
*   C__U16SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)
*
*   C__U8SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)
*
* NOTE:
*   The input parameters are not put in parantheses inside the macro body.
*   Thus, the input values must not be expressions. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1
*               2^csh
*
******************************************************************************/

#define C__U32SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt32)UINT32MAX :\
    (UInt32)(v_l << csh) )

#define C__U16SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt16)UINT16MAX :\
    (UInt16)(v_l << csh) )

#define C__U8SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt8)UINT8MAX :\
    (UInt8)(v_l << csh) )


/******************************************************************************
*
* MACROS:
*   C__I32SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)
*
*   C__I16SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)
*
*   C__I8SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)
*
* NOTE:
*   The input parameters are not put in parantheses inside the macro body.
*   Thus, the input values must not be expressions. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1
*               2^csh
*
******************************************************************************/

#define C__I32SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int32)INT32MAX :\
    (Int32)(v_l << csh) )

#define C__I16SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int16)INT16MAX :\
    (Int16)(v_l << csh) )

#define C__I8SHLU64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (Int8)INT8MAX :\
    (Int8)(v_l << csh) )


/******************************************************************************
*
* MACROS:
*   C__U32SHLI64C6_SATb(v_h, v_l, csh, maxIn_l)
*   C__U32SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)
*   C__U32SHLI64C6_SATl(v_h, v_l, csh)
*
*   C__U16SHLI64C6_SATb(v_h, v_l, csh, maxIn_l)
*   C__U16SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)
*   C__U16SHLI64C6_SATl(v_h, v_l, csh)
*
*   C__U8SHLI64C6_SATb(v_h, v_l, csh, maxIn_l)
*   C__U8SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)
*   C__U8SHLI64C6_SATl(v_h, v_l, csh)
*
* NOTE:
*   The input parameters are not put in parantheses inside the macro body.
*   Thus, the input values must not be expressions. 
*
*           2^(Wresult-1)
*   maxIn = ------------- - 1
*               2^csh
*
******************************************************************************/

#define C__U32SHLI64C6_SATb(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt32)UINT32MAX :\
    ( (v_h < 0) ? 0 : (UInt32)(v_l << csh) ) )

#define C__U32SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt32)UINT32MAX :\
    (UInt32)(v_l << csh) )

#define C__U32SHLI64C6_SATl(v_h, v_l, csh)\
    ( (v_h < 0) ? 0 : (UInt32)(v_l << csh) )


#define C__U16SHLI64C6_SATb(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt16)UINT16MAX :\
    ( (v_h < 0) ? 0 : (UInt16)(v_l << csh) ) )

#define C__U16SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt16)UINT16MAX :\
    (UInt16)(v_l << csh) )

#define C__U16SHLI64C6_SATl(v_h, v_l, csh)\
    ( (v_h < 0) ? 0 : (UInt16)(v_l << csh) )


#define C__U8SHLI64C6_SATb(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt8)UINT8MAX :\
    ( (v_h < 0) ? 0 : (UInt8)(v_l << csh) ) )

#define C__U8SHLI64C6_SATu(v_h, v_l, csh, maxIn_l)\
    ( ( (v_h > 0)||((v_h == 0)&&(v_l > maxIn_l)) ) ? (UInt8)UINT8MAX :\
    (UInt8)(v_l << csh) )

#define C__U8SHLI64C6_SATl(v_h, v_l, csh)\
    ( (v_h < 0) ? 0 : (UInt8)(v_l << csh) )



#endif /* #ifndef __shl_h__ */
