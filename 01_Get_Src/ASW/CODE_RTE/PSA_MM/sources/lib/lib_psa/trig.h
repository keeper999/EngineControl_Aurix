/******************************************************************************
*
* FILE:
*   trig.h
*
* RELATED FILES:
*
* DESCRIPTION:
*   The file contains prototype definitions of trigonometric functions.
*
*   The function name represents the implemented operation:
*     F__<output_type><operation><input_type>
*
*     output_type, input_type: U8, U16, U32, U64, I8, I16, I32, I64
*     operation              : SIN, COS, TAN, ASIN, ACOS, ATAN, ATAN2
*
*
*   The parameters are classified with three keywords.
*
*    Parameter  Description                    Properties
*    --------------------------------------------------------------------------
*    v, x       input for a
*                fixed type operation          rVars,  NoConsts, ComplexExpr
*    v_h        upper part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
*    v_l        lower part of a 64-bit input   rVars,  NoConsts, NoComplexExpr
*    ysh        const shift factor
*                of output rescaling           NoVars, Consts,   NoComplexExpr
*    yD         denomitator
*                of output rescaling           NoVars, Consts,   NoComplexExpr
*    yN         nominator
*                of output rescaling           NoVars, Consts,   NoComplexExpr
*
*
*  AUTHOR(S):
*    D. Andoleit
*
*  Copyright (c) 2002 dSPACE GmbH, GERMANY
*
*  $Workfile: trig.h $ $Revision: 1.5 $ $Date: 2007/04/04 14:08:22GMT+01:00 $ $Author: DagmarA $
******************************************************************************/

#ifndef __trig_h__
#define __trig_h__


/* table contains a quarter of cosine values */
extern const UInt16 cosLUT[129];

/******************************************************************************
*
*   Int16 F__I16SINI16(Int16 x)
*
*   Int32 F__I32SINI32_LE7(Int32 v)
*   Int32 F__I32SINI32_LE8(Int32 v)
*   Int32 F__I32SINI32_LE9(Int32 v)
*   Int32 F__I32SINI32_LE10(Int32 v)
*   Int32 F__I32SINI32_LE11(Int32 v)
*
*   Int32 F__I32SINI64_LE7(Int32 v_h, UInt32 v_l)
*   Int32 F__I32SINI64_LE8(Int32 v_h, UInt32 v_l)
*   Int32 F__I32SINI64_LE9(Int32 v_h, UInt32 v_l)
*   Int32 F__I32SINI64_LE10(Int32 v_h, UInt32 v_l)
*   Int32 F__I32SINI64_LE11(Int32 v_h, UInt32 v_l)
*
* NOTE:
*   With 16 bit input type and 16 bit output type the calculation of sine uses
*   a table. In 32 bit series approach with various number of summands.
*
******************************************************************************/
Int16 F__I16SINI16(Int16 x);

Int32 F__I32SINI32_LE7(Int32 v);
Int32 F__I32SINI32_LE8(Int32 v);
Int32 F__I32SINI32_LE9(Int32 v);
Int32 F__I32SINI32_LE10(Int32 v);
Int32 F__I32SINI32_LE11(Int32 v);

#define F__I32SINI64_LE7(v_h, v_l)\
    F__I32SINI32_LE7((Int32) (v_l))

#define F__I32SINI64_LE8(v_h, v_l)\
    F__I32SINI32_LE8((Int32) (v_l))

#define F__I32SINI64_LE9(v_h, v_l)\
    F__I32SINI32_LE9((Int32) (v_l))

#define F__I32SINI64_LE10(v_h, v_l)\
    F__I32SINI32_LE10((Int32) (v_l))

#define F__I32SINI64_LE11(v_h, v_l)\
    F__I32SINI32_LE11((Int32) (v_l))

/******************************************************************************
*
*   Int16 F__I16COSI16(v)
*
*   Int32 F__I32COSI32_LE7(v)
*   Int32 F__I32COSI32_LE8(v)
*   Int32 F__I32COSI32_LE9(v)
*   Int32 F__I32COSI32_LE10(v)
*   Int32 F__I32COSI32_LE11(v)
*
*   Int32 F__I32COSI64_LE7(Int32 v_h, UInt32 v_l)
*   Int32 F__I32COSI64_LE8(Int32 v_h, UInt32 v_l)
*   Int32 F__I32COSI64_LE9(Int32 v_h, UInt32 v_l)
*   Int32 F__I32COSI64_LE10(Int32 v_h, UInt32 v_l)
*   Int32 F__I32COSI64_LE11(Int32 v_h, UInt32 v_l)
*
* NOTE:
*   cosine calculation uses sine calculation.
*
******************************************************************************/
#define F__I16COSI16(v)\
    F__I16SINI16((Int16)((v) + 0x4000))

#define F__I32COSI32_LE7(v)\
    F__I32SINI32_LE7((v) + 0x40000000)

#define F__I32COSI32_LE8(v)\
    F__I32SINI32_LE8((v) + 0x40000000)

#define F__I32COSI32_LE9(v)\
    F__I32SINI32_LE9((v) + 0x40000000)

#define F__I32COSI32_LE10(v)\
    F__I32SINI32_LE10((v) + 0x40000000)

#define F__I32COSI32_LE11(v)\
    F__I32SINI32_LE11((v) + 0x40000000)

#define F__I32COSI64_LE7(v_h, v_l)\
    F__I32COSI32_LE7((Int32) (v_l))

#define F__I32COSI64_LE8(v_h, v_l)\
    F__I32COSI32_LE8((Int32) (v_l))

#define F__I32COSI64_LE9(v_h, v_l)\
    F__I32COSI32_LE9((Int32) (v_l))

#define F__I32COSI64_LE10(v_h, v_l)\
    F__I32COSI32_LE10((Int32) (v_l))

#define F__I32COSI64_LE11(v_h, v_l)\
    F__I32COSI32_LE11((Int32) (v_l))

/******************************************************************************
*
*   functions that calculate n terms of sine series
*   Int32 F__I32SINI32_6TERMS(Int32 v)
*   Int32 F__I32SINI32_5TERMS(Int32 v)
*   Int32 F__I32SINI32_4TERMS(Int32 v)
*
*   functions that calculate n terms of cosine series
*   Int32 F__I32COSI32_6TERMS(Int32 v)
*   Int32 F__I32COSI32_5TERMS(Int32 v)
*   Int32 F__I32COSI32_4TERMS(Int32 v)
*
* NOTE:
*   These functions are auxiliary functions for calculation of sine and cosine
*   using series approach.
*
******************************************************************************/
Int32 F__I32SINI32_6TERMS(Int32 v);
Int32 F__I32SINI32_5TERMS(Int32 v);
Int32 F__I32SINI32_4TERMS(Int32 v);

Int32 F__I32COSI32_6TERMS(Int32 v);
Int32 F__I32COSI32_5TERMS(Int32 v);
Int32 F__I32COSI32_4TERMS(Int32 v);

/******************************************************************************
*
*   Int16 F__I16TANI16(Int16 v, Int8 ysh)
*   Int16 F__I16TANI16_ARB(Int16 v, Int16 yN, Int16 yD)
*
*   Int32 F__I32TANI32_LE7(Int32 v, Int8 ysh)
*   Int32 F__I32TANI32_LE7_ARB(Int32 v, Int32 yN, Int32 yD)
*   Int32 F__I32TANI32_LE8(Int32 v, Int8 ysh)
*   Int32 F__I32TANI32_LE8_ARB(Int32 v, Int32 yN, Int32 yD)
*   Int32 F__I32TANI32_LE9(Int32 v, Int8 ysh)
*   Int32 F__I32TANI32_LE9_ARB(Int32 v, Int32 yN, Int32 yD)
*   Int32 F__I32TANI32_LE10(Int32 v, Int8 ysh)
*   Int32 F__I32TANI32_LE10_ARB(Int32 v, Int32 yN, Int32 yD)
*   Int32 F__I32TANI32_LE11(Int32 v, Int8 ysh)
*   Int32 F__I32TANI32_LE11_ARB(Int32 v, Int32 yN, Int32 yD)
*
*   Int32 F__I32TANI64_LE7(Int32 v_h, UInt32 v_l, Int8 ysh)
*   Int32 F__I32TANI64_LE7_ARB(Int32 v_h, UInt32 v_l, Int32 yN, Int32 yD)
*   Int32 F__I32TANI64_LE8(Int32 v_h, UInt32 v_l, Int8 ysh)
*   Int32 F__I32TANI64_LE8_ARB(Int32 v_h, UInt32 v_l, Int32 yN, Int32 yD)
*   Int32 F__I32TANI64_LE9(Int32 v_h, UInt32 v_l, Int8 ysh)
*   Int32 F__I32TANI64_LE9_ARB(Int32 v_h, UInt32 v_l, Int32 yN, Int32 yD)
*   Int32 F__I32TANI64_LE10(Int32 v_h, UInt32 v_l, Int8 ysh)
*   Int32 F__I32TANI64_LE10_ARB(Int32 v_h, UInt32 v_l, Int32 yN, Int32 yD)
*   Int32 F__I32TANI64_LE11(Int32 v_h, UInt32 v_l, Int8 ysh)
*   Int32 F__I32TANI64_LE11_ARB(Int32 v_h, UInt32 v_l, Int32 yN, Int32 yD)
*
* NOTE:
*   calculation of tangent uses 'sin/cos'
*
******************************************************************************/
Int16 F__I16TANI16(Int16 v, Int8 ysh);
Int16 F__I16TANI16_ARB(Int16 v, Int16 yN, Int16 yD);

Int32 F__I32TANI32_LE7(Int32 v, Int8 ysh);
Int32 F__I32TANI32_LE7_ARB(Int32 v, Int32 yN, Int32 yD);
Int32 F__I32TANI32_LE8(Int32 v, Int8 ysh);
Int32 F__I32TANI32_LE8_ARB(Int32 v, Int32 yN, Int32 yD);
Int32 F__I32TANI32_LE9(Int32 v, Int8 ysh);
Int32 F__I32TANI32_LE9_ARB(Int32 v, Int32 yN, Int32 yD);
Int32 F__I32TANI32_LE10(Int32 v, Int8 ysh);
Int32 F__I32TANI32_LE10_ARB(Int32 v, Int32 yN, Int32 yD);
Int32 F__I32TANI32_LE11(Int32 v, Int8 ysh);
Int32 F__I32TANI32_LE11_ARB(Int32 v, Int32 yN, Int32 yD);

#define F__I32TANI64_LE7(v_h, v_l, ysh)\
    F__I32TANI32_LE7((Int32)(v_l), (ysh))

#define F__I32TANI64_LE7_ARB(v_h, v_l, yN, yD)\
    F__I32TANI32_LE7_ARB((Int32)(v_l), (yN), (yD))

#define F__I32TANI64_LE8(v_h, v_l, ysh)\
    F__I32TANI32_LE8((Int32)(v_l), (ysh))

#define F__I32TANI64_LE8_ARB(v_h, v_l, yN, yD)\
    F__I32TANI32_LE8_ARB((Int32)(v_l), (yN), (yD))

#define F__I32TANI64_LE9(v_h, v_l, ysh)\
    F__I32TANI32_LE9((Int32)(v_l), (ysh))

#define F__I32TANI64_LE9_ARB(v_h, v_l, yN, yD)\
    F__I32TANI32_LE9_ARB((Int32)(v_l), (yN), (yD))

#define F__I32TANI64_LE10(v_h, v_l, ysh)\
    F__I32TANI32_LE10((Int32)(v_l), (ysh))

#define F__I32TANI64_LE10_ARB(v_h, v_l, yN, yD)\
    F__I32TANI32_LE10_ARB((Int32)(v_l), (yN), (yD))

#define F__I32TANI64_LE11(v_h, v_l, ysh)\
    F__I32TANI32_LE11((Int32)(v_l), (ysh))

#define F__I32TANI64_LE11_ARB(v_h, v_l, yN, yD)\
    F__I32TANI32_LE11_ARB((Int32)(v_l), (yN), (yD))

/******************************************************************************
*
*   Int16 F__I16ASINI16(Int16 x_In)
*
* NOTE:
*   the calculation of asin uses a 2D table
*
******************************************************************************/
Int16 F__I16ASINI16(Int16 x_In);

/******************************************************************************
*
*   UInt16 F__U16ACOSI16(Int16 v)
*
* NOTE:
*   acos is implemented using asin.
*
******************************************************************************/
#define F__U16ACOSI16(v)\
    (UInt16)(25736 - /* CTO */ (UInt16)F__I16ASINI16(v))

/******************************************************************************
*
*   Int16 F__I16ATANI16(Int16 x_In, Int32 c)
*
*   Int16 F__I16ATAN2I16(Int16 v, Int32 c, Int16 y)
*
* NOTE:
*   atan can be calculated using the asin.
*
******************************************************************************/
Int16 F__I16ATANI16(Int16 x_In, Int32 c);

Int16 F__I16ATAN2I16(Int16 v, Int32 c, Int16 y);

#endif /* #ifndef __trig_h__ */
