/******************************************************************************
*
* FILE:
*   cmp.h
*
* RELATED FILES:
*
* DESCRIPTION:
*   This file contains macro definitions for 64bit relational operators.
*   Both operands must have the same signedness.
*
*   The following applies to all macros:
*   ------------------------------------
*
*   The macro name represents the implemented operation:
*     C__<operation><input_width>
*
*     input_width: 64
*     operation  : EQ, NE, GT, LT, GE, LE
*
*
*   The result:
*     The result of the comparison is always 0 or 1. 
*     All macros have no return value.
*
*
*   The parameters are classified with three keywords.
*
*    Parameter  Description                    Properties
*    --------------------------------------------------------------------------
*    v*_h       upper part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
*    v*_l       lower part of a 64-bit input   rVars,  NoConsts, NoComplexExpr  
*
*
* AUTHOR(S):
*    D. Andoleit
*
* Copyright (c) 2002 dSPACE GmbH, GERMANY
*
* $Workfile: cmp.h $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:49GMT+01:00 $ $Author: FrankL $
******************************************************************************/

#ifndef __cmp_h__
#define __cmp_h__

#define TLTRUE  1
#define TLFALSE 0

/******************************************************************************
*
* GENERAL:
*   Generic rules, all operations, Wx == 64
*
******************************************************************************/

/******************************************************************************
*
* MACROS:
*   C__EQ64(v1_h, v1_l, v2_h, v2_l)
*   C__NE64(v1_h, v1_l, v2_h, v2_l)
*   C__GT64(v1_h, v1_l, v2_h, v2_l)
*   C__LT64(v1_h, v1_l, v2_h, v2_l)
*   C__GE64(v1_h, v1_l, v2_h, v2_l)
*   C__LE64(v1_h, v1_l, v2_h, v2_l)
*
* NOTE:     
*   The input parameter is not put in parantheses inside the macro body.
*   Thus, the input value must not be an expression. 
*
******************************************************************************/

#define C__EQ64(v1_h, v1_l, v2_h, v2_l)\
        ( ((v1_h == v2_h) && (v1_l == v2_l)) ? TLTRUE : TLFALSE )
/* END C__EQ64() */

#define C__NE64(v1_h, v1_l, v2_h, v2_l)\
        ( ((v1_h == v2_h) && (v1_l == v2_l)) ? TLFALSE : TLTRUE )
/* END C__NE64() */

#define C__GT64(v1_h, v1_l, v2_h, v2_l)\
        ( (v1_h > v2_h) ? TLTRUE : ((v1_h < v2_h) ? TLFALSE : ((v1_l > v2_l) ? TLTRUE : TLFALSE)) )
/* END C__GT64() */

#define C__LT64(v1_h, v1_l, v2_h, v2_l)\
        ( (v1_h < v2_h) ? TLTRUE : ((v1_h > v2_h) ? TLFALSE : ((v1_l < v2_l) ? TLTRUE : TLFALSE)) )
/* END C__LT64() */

#define C__GE64(v1_h, v1_l, v2_h, v2_l)\
        ( (v1_h < v2_h) ? TLFALSE : ((v1_h > v2_h) ? TLTRUE : ((v1_l < v2_l) ? TLFALSE : TLTRUE)) )
/* END C__GE64() */

#define C__LE64(v1_h, v1_l, v2_h, v2_l)\
        ( (v1_h > v2_h) ? TLFALSE : ((v1_h < v2_h) ? TLTRUE : ((v1_l > v2_l) ? TLFALSE : TLTRUE)) )
/* END C__LE64() */



#endif /* #ifndef __cmp_h__ */
