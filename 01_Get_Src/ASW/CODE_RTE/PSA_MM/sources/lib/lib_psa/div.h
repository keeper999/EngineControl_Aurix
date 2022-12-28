/******************************************************************************
*
* FILE:
*   DIV.h         1999/03/30
*
* RELATED FILES:
*
* DESCRIPTION:
* - This file contains several macro definitions and function declarations
*   for the multiplication with 64bit values and automatic saturation
* - C-macros are characterized by a leading "C__".
*   Ansi-C-functions are characterized by a leading "F__".
* - The macro/function-name represents the implemented operation(s):
*	(C__|F__) + output_type + OPERATION + input_type {+ input_type} [+ _SAT]
*
*   C__I64DIVI64I32():          signed division 64bit/32bit=>64bit
*   F__I64DIVI64I32():          signed division 64bit/32bit=>64bit
*   C__I64DIVI64U32():          mixed division 64bit/32bit=>64bit
*   F__I64DIVI64U32():          mixed division 64bit/32bit=>64bit
*   C__I64DIVU64I32():          mixed division 64bit/32bit=>64bit
*   F__I64DIVU64I32():          mixed division 64bit/32bit=>64bit
*   C__U64DIVU64U32():          unsigned division 64bit/32bit=>64bit
*   F__U64DIVU64U32():          unsigned division 64bit/32bit=>64bit
*   C__U64DIVI64I32():          signed division 64bit/32bit=>64bit
*   F__U64DIVI64I32():          signed division 64bit/32bit=>64bit
*   C__U64DIVI64U32():          mixed division 64bit/32bit=>64bit
*   F__U64DIVI64U32():          mixed division 64bit/32bit=>64bit
*   C__U64DIVU64I32():          mixed division 64bit/32bit=>64bit
*   F__U64DIVU64I32():          mixed division 64bit/32bit=>64bit
*   C__I64DIVU64U32():          unsigned division 64bit/32bit=>64bit
*   F__I64DIVU64U32():          unsigned division 64bit/32bit=>64bit
*
*   C__I64DIVI32I32():          signed division 32bit/32bit=>64bit
*   C__I64DIVU32I32():          mixed division 32bit/32bit=>64bit
*
*   C__I32DIVI64I32():          signed division 64bit/32bit=>32bit
*   F__I32DIVI64I32():          signed division 64bit/32bit=>32bit
*   C__I32DIVI64U32():          mixed division 64bit/32bit=>32bit
*   F__I32DIVI64U32():          mixed division 64bit/32bit=>32bit
*   C__I32DIVU64I32():          mixed division 64bit/32bit=>32bit
*   F__I32DIVU64I32():          mixed division 64bit/32bit=>32bit
*   C__U32DIVU64U32():          unsigned division 64bit/32bit=>32bit
*   F__U32DIVU64U32():          unsigned division 64bit/32bit=>32bit
*   C__I32DIVU64U32():          unsigned division 64bit/32bit=>32bit
*   F__I32DIVU64U32():          unsigned division 64bit/32bit=>32bit
*   C__U32DIVI64I32():          signed division 64bit/32bit=>32bit
*   F__U32DIVI64I32():          signed division 64bit/32bit=>32bit
*   C__U32DIVI64U32():          mixed division 64bit/32bit=>32bit
*   F__U32DIVI64U32():          mixed division 64bit/32bit=>32bit
*   C__U32DIVU64I32():          mixed division 64bit/32bit=>32bit
*   F__U32DIVU64I32():          mixed division 64bit/32bit=>32bit
*   C__I16DIVI64I32():          signed division 64bit/32bit=>16bit
*   C__I16DIVI64U32():          mixed division 64bit/32bit=>16bit
*   C__I16DIVU64I32():          mixed division 64bit/32bit=>16bit
*   C__I16DIVU64U32():          unsigned division 64bit/32bit=>16bit
*   C__U16DIVI64I32():          signed division 64bit/32bit=>16bit
*   C__U16DIVI64U32():          mixed division 64bit/32bit=>16bit
*   C__U16DIVU64I32():          mixed division 64bit/32bit=>16bit
*   C__U16DIVU64U32():          unsigned division 64bit/32bit=>16bit
*   C__I8DIVI64I32():           signed division 64bit/32bit=>8bit
*   C__I8DIVI64U32():           mixed division 64bit/32bit=>8bit
*   C__I8DIVU64I32():           mixed division 64bit/32bit=>8bit
*   C__I8DIVU64U32():           unsigned division 64bit/32bit=>8bit
*   C__U8DIVI64I32():           signed division 64bit/32bit=>8bit
*   C__U8DIVI64U32():           mixed division 64bit/32bit=>8bit
*   C__U8DIVU64I32():           mixed division 64bit/32bit=>8bit
*   C__U8DIVU64U32():           usigned division 64bit/32bit=>8bit
*
*   C__I32DIVI64C32_SAT():      saturated mixed division 64bit/32bit=>32bit
*   C__I32DIVU64C32_SAT():      saturated unsigned division 64bit/32bit=>32bit
*   C__U32DIVI64C32_SAT():      saturated mixed division 64bit/32bit=>32bit
*   C__U32DIVU64C32_SAT():      saturated unsigned division 64bit/32bit=>32bit
*   C__I16DIVI64C32_SAT():      saturated mixed division 64bit/32bit=>16bit
*   C__I16DIVU64C32_SAT():      saturated unsigned division 64bit/32bit=>16bit
*   C__U16DIVI64C32_SAT():      saturated mixed division 64bit/32bit=>16bit
*   C__U16DIVU64C32_SAT():      saturated unsigned division 64bit/32bit=>16bit
*   C__I8DIVI64C32_SAT():       saturated mixed division 64bit/32bit=>8bit
*   C__I8DIVU64C32_SAT():       saturated unsigned division 64bit/32bit=>8bit
*   C__U8DIVI64C32_SAT():       saturated mixed division 64bit/32bit=>8bit
*   C__U8DIVU64C32_SAT():       saturated unsigned division 64bit/32bit=>8bit
*
*   C__I16DIVI32C16_SAT():      saturated mixed division 32bit/16bit=>16bit
*   C__I16DIVU32C16_SAT():      saturated unsigned division 32bit/16bit=>16bit
*   C__U16DIVI32C16_SAT():      saturated mixed division 32bit/16bit=>16bit
*   C__U16DIVU32C16_SAT():      saturated unsiged division 32bit/16bit=>16bit
*   C__I8DIVI32C16_SAT():       saturated mixed division 32bit/16bit=>8bit
*   C__I8DIVU32C16_SAT():       saturated unsigned division 32bit/16bit=>8bit
*   C__U8DIVI32C16_SAT():       saturated mixed division 32bit/16bit=>8bit
*   C__U8DIVU32C16_SAT():       saturated unsiged division 32bit/16bit=>8bit
*   C__I8DIVI16C8_SAT():        saturated mixed division 16bit/bit=>8bit
*   C__I8DIVU16C8_SAT():        saturated unsigned division 16bit/bit=>8bit
*   C__U8DIVI16C8_SAT():        saturated mixed division 16bit/bit=>8bit
*   C__U8DIVU16C8_SAT():        saturated unsigned division 16bit/bit=>8bit
*
*  AUTHOR(S):
*    O. Grajetzky
*
*  Copyright (c) 1999 dSPACE GmbH, GERMANY
*
*  $Workfile: div.h $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:50GMT+01:00 $ $Author: FrankL $
******************************************************************************/

#ifndef __div_h__
#define __div_h__


/******************************************************************************
*
* MACRO:
*   C__I64DIVI64I32(n_h, n_l, d, r_h, r_l)
*   C__U64DIVI64I32(n_h, n_l, d, r_h, r_l)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 64bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   Int32    n_h    upper 32Bit of the nominator
*   UInt32   n_l    lower 32Bit of the nominator
*   Int32      d    denominator
*  yInt32    r_h    upper 32bit of the result
*  UInt32    r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFFFFFFFFFF respectively
*    0xFFFFFFFFFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__I64DIVI64I32(n_h, n_l, d, r_h, r_l)\
{\
	UInt64s tmp;\
	tmp.lo = n_l;\
	tmp.hi = (UInt32)n_h;\
	tmp = F__I64sDIVI64sI32(&tmp, d);\
	r_h = (Int32)tmp.hi;\
	r_l = tmp.lo;\
}

#define C__U64DIVI64I32(n_h, n_l, d, r_h, r_l)\
    C__I64DIVI64I32(n_h, n_l, d, r_h, r_l)
/* END C__I64DIVI64I32()
       C__U64DIVI64I32() */


/******************************************************************************
*
* FUNCTION:
*   F__I64DIVI64I32(n_h, n_l, d, r_h, r_l)
*   F__U64DIVI64I32(n_h, n_l, d, r_h, r_l)
*
******************************************************************************/
void F__I64DIVI64I32(Int32 n_h, UInt32 n_l, Int32 d, Int32 *r_h, UInt32 *r_l);

#define F__U64DIVI64I32(n_h, n_l, d, r_h, r_l)\
    F__I64DIVI64I32(n_h, n_l, d, r_h, r_l)


/******************************************************************************
*
* MACRO:
*   C__I64DIVI64U32(n_h, n_l, d, r_h, r_l)
*   C__U64DIVI64U32(n_h, n_l, d, r_h, r_l)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 64bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   Int32    n_h    upper 32Bit of the nominator
*  UInt32    n_l    lower 32Bit of the nominator
*  UInt32      d    denominator
*  yInt32    r_h    upper 32bit of the result
*  UInt32    r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFFFFFFFFFF respectively
*    0xFFFFFFFFFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__I64DIVI64U32(n_h, n_l, d, r_h, r_l)\
{\
	UInt64s tmp;\
	tmp.lo = n_l;\
	tmp.hi = (UInt32)n_h;\
	tmp = F__I64sDIVI64sU32(&tmp, d);\
	r_h = (Int32)tmp.hi;\
	r_l = tmp.lo;\
}

#define C__U64DIVI64U32(n_h, n_l, d, r_h, r_l)\
    C__I64DIVI64U32(n_h, n_l, d, r_h, r_l)
/* END C__I64DIVI64U32()
       C__U64DIVI64U32() */

/******************************************************************************
*
* FUNCTION:
*   F__I64DIVI64U32(n_h, n_l, d, r_h, r_l)
*   F__U64DIVI64U32(n_h, n_l, d, r_h, r_l)
*
******************************************************************************/
void F__I64DIVI64U32(Int32 n_h, UInt32 n_l, UInt32 d, Int32 *r_h, UInt32 *r_l);

#define F__U64DIVI64U32(n_h, n_l, d, r_h, r_l)\
    F__I64DIVI64U32(n_h, n_l, d, r_h, r_l)


/******************************************************************************
*
* MACRO:
*   C__I64DIVU64I32(n_h, n_l, d, r_h, r_l)
*   C__U64DIVU64I32(n_h, n_l, d, r_h, r_l)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 64bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*  UInt32    n_h    upper 32Bit of the nominator
*  UInt32    n_l    lower 32Bit of the nominator
*   Int32      d    denominator
*  yInt32    r_h    upper 32bit of the result
*  UInt32    r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFFFFFFFFFF respectively
*    0xFFFFFFFFFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__I64DIVU64I32(n_h, n_l, d, r_h, r_l)\
{\
	UInt64s tmp;\
	tmp.lo = n_l;\
	tmp.hi = n_h;\
	tmp = F__I64sDIVU64sI32(&tmp, d);\
	r_h = (Int32)tmp.hi;\
	r_l = tmp.lo;\
}

#define C__U64DIVU64I32(n_h, n_l, d, r_h, r_l)\
    C__I64DIVU64I32(n_h, n_l, d, r_h, r_l)
/* END C__I64DIVU64I32()
       C__U64DIVU64I32() */

/******************************************************************************
*
* FUNCTION:
*   F__I64DIVU64I32(n_h, n_l, d, r_h, r_l)
*   F__U64DIVU64I32(n_h, n_l, d, r_h, r_l)
******************************************************************************/
void F__I64DIVU64I32(UInt32 n_h, UInt32 n_l, Int32 d, Int32 *r_h, UInt32 *r_l);

#define F__U64DIVU64I32(n_h, n_l, d, r_h, r_l)\
    F__I64DIVU64I32(n_h, n_l, d, r_h, r_l)


/******************************************************************************
*
* MACRO:
*   C__U64DIVU64U32(n_h, n_l, d, r_h, r_l)
*   C__I64DIVU64U32(n_h, n_l, d, r_h, r_l)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 64bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*  UInt32    n_h    upper 32Bit of the nominator
*  UInt32    n_l    lower 32Bit of the nominator
*  UInt32      d    denominator
*  yInt32    r_h    upper 32bit of the result
*  UInt32    r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFFFFFFFFFF respectively
*    0xFFFFFFFFFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__U64DIVU64U32(n_h, n_l, d, r_h, r_l)\
{\
	UInt64s tmp;\
	tmp.lo = n_l;\
	tmp.hi = n_h;\
	tmp = F__U64sDIVU64sU32(&tmp, d);\
	r_h = tmp.hi;\
	r_l = tmp.lo;\
}

#define C__I64DIVU64U32(n_h, n_l, d, r_h, r_l)\
    C__U64DIVU64U32(n_h, n_l, d, r_h, r_l)
/* END C__I64DIVU64U32()
       C__U64DIVU64U32() */


/******************************************************************************
*
* FUNCTION:
*   F__U64DIVU64U32(n_h, n_l, d, r_h, r_l)
*   F__I64DIVU64U32(n_h, n_l, d, r_h, r_l)
*
******************************************************************************/
void F__U64DIVU64U32(UInt32 n_h, UInt32 n_l, UInt32 d, UInt32 *r_h, UInt32 *r_l);

#define F__I64DIVU64U32(n_h, n_l, d, r_h, r_l)\
    F__U64DIVU64U32(n_h, n_l, d, r_h, r_l)


/******************************************************************************
*
* MACRO:
*   C__I64DIVI32I32(n, d, r_h, r_l)
*
* DESCRIPTION:
*   Divides the 32bit Value n by the 32bit Value d with a 64bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   Int32      n    nominator
*   Int32      d    denominator
*   Int32    r_h    upper 32bit of the result
*  UInt32    r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFFFFFFFFFF respectively
*    0xFFFFFFFFFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__I64DIVI32I32(n, d, r_h, r_l)\
{\
	UInt64s tmp;\
	C__I64COPYI32(n, tmp.hi, tmp.lo);\
	tmp = F__I64sDIVI64sI32(&tmp, d);\
	r_h = (Int32)tmp.hi;\
	r_l = tmp.lo;\
}/* END C__I64DIVI32I32() */

/******************************************************************************
*
* MACRO:
*   C__I64DIVU32I32(n, d, r_h, r_l)
*
* DESCRIPTION:
*   Divides the 32bit Value n by the 32bit Value d with a 64bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   UInt32     n    nominator
*   Int32      d    denominator
*   Int32    r_h    upper 32bit of the result
*  UInt32    r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFFFFFFFFFF respectively
*    0xFFFFFFFFFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__I64DIVU32I32(n, d, r_h, r_l)\
{\
	UInt64s tmp;\
	C__U64COPYU32(n, tmp.hi, tmp.lo);\
	tmp = F__I64sDIVU64sI32(&tmp, d);\
	r_h = (Int32)tmp.hi;\
	r_l = tmp.lo;\
}/* END C__I64DIVU32I32() */

/******************************************************************************
*
* MACRO:
*   C__I32DIVI64I32(n_h, n_l, d, r)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 32bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   Int32    n_h    upper 32Bit of the nominator
*   UInt32   n_l    lower 32Bit of the nominator
*   Int32      d    denominator
*   Int32      r    result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFF respectively 0xFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__I32DIVI64I32(n_h, n_l, d, r)\
{\
	UInt64s tmp;\
	tmp.lo = n_l;\
	tmp.hi = (UInt32)n_h;\
	r = F__I32DIVI64sI32(&tmp, d);\
}/* END C__I32DIVI64I32() */

/******************************************************************************
*
* FUNCTION:
*   F__I32DIVI64I32(n_h, n_l, d)
*
******************************************************************************/
Int32 F__I32DIVI64I32(Int32 n_h, UInt32 n_l, Int32 d);

/******************************************************************************
*
* MACRO:
*   C__I32DIVI64U32(n_h, n_l, d, r)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 32bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   Int32    n_h    upper 32Bit of the nominator
*   UInt32   n_l    lower 32Bit of the nominator
*   UInt32     d    denominator
*   Int32      r    result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFF respectively 0xFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__I32DIVI64U32(n_h, n_l, d, r)\
{\
	UInt64s tmp;\
	tmp.lo = n_l;\
	tmp.hi = (UInt32)n_h;\
	r = F__I32DIVI64sU32(&tmp, d);\
}/* END C__I32DIVI64U32() */

/******************************************************************************
*
* FUNCTION:
*   F__I32DIVI64U32(n_h, n_l, d)
*
******************************************************************************/
Int32 F__I32DIVI64U32(Int32 n_h, UInt32 n_l, UInt32 d);

/******************************************************************************
*
* MACRO:
*   C__I32DIVU64I32(n_h, n_l, d, r)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 32bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   UInt32   n_h    upper 32Bit of the nominator
*   UInt32   n_l    lower 32Bit of the nominator
*   Int32      d    denominator
*   Int32      r    result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFF respectively 0xFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*  - n must fit into Int64, if the result should fit into Int32. Therefore the
*    macro C__I32DIVI64I32() is used.
*
******************************************************************************/
#define C__I32DIVU64I32(n_h, n_l, d, r)\
    C__I32DIVI64I32(n_h, n_l, d, r)
/* END C__I32DIVU64I32() */

/******************************************************************************
*
* FUNCTION:
*   F__I32DIVU64I32(n_h, n_l, d, r)
*
******************************************************************************/
Int32 F__I32DIVU64I32(UInt32 n_h, UInt32 n_l, Int32 d);

/******************************************************************************
*
* MACRO:
*   C__U32DIVU64U32(n_h, n_l, d, r)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a 32bit result.
*
*
* PARAMETERS:
*   type    name    meaning
*   UInt32   n_h    upper 32Bit of the nominator
*   UInt32   n_l    lower 32Bit of the nominator
*   UInt32     d    denominator
*   UInt32     r    result
*
* RETURNS:
*
* NOTE:
*  - "division by zero" detection (gives 0x7FFFFFFF respectively 0xFFFFFFFF)
*  - the algorithm supports only calculations with unsigned values. Therefore
*    the sign of the result is determined separately.
*
******************************************************************************/
#define C__U32DIVU64U32(n_h, n_l, d, r)\
{\
	UInt64s tmp;\
	tmp.lo = n_l;\
	tmp.hi = n_h;\
	r = F__U32DIVU64sU32(&tmp, d);\
}/* END C__U32DIVU64U32() */

/******************************************************************************
*
* FUNCTION:
*   F__U32DIVU64U32(n_h, n_l, d)
*
******************************************************************************/
UInt32 F__U32DIVU64U32(UInt32 n_h, UInt32 n_l, UInt32 d);


/******************************************************************************
*
* MACROs:
*   C__I32DIVU64U32(n_h, n_l, d, r)
*   C__U32DIVI64U32(n_h, n_l, d, r)
*   C__I16DIVI64U32(n_h, n_l, d, r)
*   C__I16DIVU64U32(n_h, n_l, d, r)
*   C__U16DIVI64U32(n_h, n_l, d, r)
*   C__U16DIVU64U32(n_h, n_l, d, r)
*   C__I8DIVI64U32(n_h, n_l, d, r)
*   C__I8DIVU64U32(n_h, n_l, d, r)
*   C__U8DIVI64U32(n_h, n_l, d, r)
*   C__U8DIVU64U32(n_h, n_l, d, r)
*
* DESCRIPTION:
*   Divides the 64bit Value n by the 32bit Value d with a yybit result.
*
* PARAMETERS:
*   type    name    meaning
*   xInt32   n_h    upper 32Bit of the nominator
*   UInt32   n_l    lower 32Bit of the nominator
*   UInt32     d    denominator (0 ... 2^31-1)
*   yIntyy     r    result
*
* RETURNS:
*
* NOTE:
*
******************************************************************************/
#define C__I32DIVU64U32(n_h, n_l, d, r)     C__U32DIVU64U32(n_h, n_l, d, r)
#define C__U32DIVI64I32(n_h, n_l, d, r)     C__I32DIVI64I32(n_h, n_l, d, r)
#define C__U32DIVI64U32(n_h, n_l, d, r)     C__I32DIVI64U32(n_h, n_l, d, r)
#define C__U32DIVU64I32(n_h, n_l, d, r)     C__I32DIVU64I32(n_h, n_l, d, r)

#define C__I16DIVI64I32(n_h, n_l, d, r)     C__I32DIVI64I32(n_h, n_l, d, r)
#define C__I16DIVI64U32(n_h, n_l, d, r)     C__I32DIVI64U32(n_h, n_l, d, r)
#define C__I16DIVU64I32(n_h, n_l, d, r)     C__I32DIVU64I32(n_h, n_l, d, r)
#define C__I16DIVU64U32(n_h, n_l, d, r)     C__I32DIVU64U32(n_h, n_l, d, r)
#define C__U16DIVI64I32(n_h, n_l, d, r)     C__U32DIVI64I32(n_h, n_l, d, r)
#define C__U16DIVI64U32(n_h, n_l, d, r)     C__U32DIVI64U32(n_h, n_l, d, r)
#define C__U16DIVU64I32(n_h, n_l, d, r)     C__U32DIVU64I32(n_h, n_l, d, r)
#define C__U16DIVU64U32(n_h, n_l, d, r)     C__U32DIVU64U32(n_h, n_l, d, r)

#define C__I8DIVI64I32(n_h, n_l, d, r)      C__I32DIVI64I32(n_h, n_l, d, r)
#define C__I8DIVI64U32(n_h, n_l, d, r)      C__I32DIVI64U32(n_h, n_l, d, r)
#define C__I8DIVU64I32(n_h, n_l, d, r)      C__I32DIVU64I32(n_h, n_l, d, r)
#define C__I8DIVU64U32(n_h, n_l, d, r)      C__I32DIVU64U32(n_h, n_l, d, r)
#define C__U8DIVI64I32(n_h, n_l, d, r)      C__U32DIVI64I32(n_h, n_l, d, r)
#define C__U8DIVI64U32(n_h, n_l, d, r)      C__U32DIVI64U32(n_h, n_l, d, r)
#define C__U8DIVU64I32(n_h, n_l, d, r)      C__U32DIVU64I32(n_h, n_l, d, r)
#define C__U8DIVU64U32(n_h, n_l, d, r)      C__U32DIVU64U32(n_h, n_l, d, r)


/******************************************************************************
*
* FUNCTIONs:
*   F__I32DIVU64U32(n_h, n_l, d)
*   F__U32DIVI64I32(n_h, n_l, d)
*   F__U32DIVI64U32(n_h, n_l, d)
*   F__U32DIVU64I32(n_h, n_l, d)
*
******************************************************************************/
#define F__I32DIVU64U32(n_h, n_l, d)\
    (Int32)F__U32DIVU64U32(n_h, n_l, d)
#define F__U32DIVI64I32(n_h, n_l, d)\
    (UInt32)F__I32DIVI64I32(n_h, n_l, d)
#define F__U32DIVI64U32(n_h, n_l, d)\
    (UInt32)F__I32DIVI64U32(n_h, n_l, d)
#define F__U32DIVU64I32(n_h, n_l, d)\
    (UInt32)F__I32DIVU64I32(n_h, n_l, d)


/******************************************************************************
*
* MACRO:
*   C__I32DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__I32DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__U32DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__U32DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__I16DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__I16DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__U16DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__U16DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__I8DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__I8DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__U8DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*   C__U8DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
*
* DESCRIPTION:
*   Macro divides a 64bit value by a 32bit value (with a 32bit result);
*   result = v / d;
*
* PARAMETERS:
*   type    name    meaning
*   xInt32   v_h    input-value highword
*   UInt32   v_l    input-value lowword
*   xInt32    cd    constant denominator
*   xInt32  cmax_h  limit of input value for saturation (highword)
*   UInt32  cmax_l  limit of input value for saturation (lowword)
*   Int32   csatval output value for saturation
*   yIntzz     r    result of division (saturated)
*
* RETURNS:
*
* NOTE:
*   for TyWy = Int32:   cmax = (2^31 * n) - 1      ; cmin = -(cmax+1)
*   for TyWy = UInt32:  cmax = (2^32 * n) - 1      ; cmin = -(cmax+1) = 0
*   for TyWy = Int16:   cmax = (2^15 * n) - 1      ; cmin = -(cmax+1)
*   for TyWy = UInt16:  cmax = (2^16 * n) - 1      ; cmin = -(cmax+1) = 0
*   for TyWy = Int8:    cmax = (2^7 * n) - 1       ; cmin = -(cmax+1)
*   for TyWy = UInt8:   cmax = (2^8 * n) - 1       ; cmin = -(cmax+1) = 0
*
******************************************************************************/
#define C__I32DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I32DIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I32DIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I32DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I32DIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I32DIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U32DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U32DIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U32DIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U32DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U32DIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U32DIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)

#define C__I16DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I16DIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I16DIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I16DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I16DIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I16DIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U16DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U16DIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U16DIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U16DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U16DIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U16DIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)

#define C__I8DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I8DIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I8DIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I8DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I8DIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__I8DIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U8DIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U8DIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U8DIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U8DIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U8DIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__U8DIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)


#define C__IyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if( (v_h > cmax_h)||((v_h == cmax_h)&&(v_l > cmax_l)) )\
        r = csatval;\
    else if( (v_h < ~cmax_h)||((v_h == ~cmax_h)&&(v_l < ~(UInt32)cmax_l)) )\
        r = ~csatval;\
    else C__I32DIVI64U32(v_h, v_l, cd, r)
#define C__IyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if( (v_h > cmax_h)||((v_h == cmax_h)&&(v_l > cmax_l)) )\
        r = csatval;\
    else C__I32DIVI64U32(v_h, v_l, cd, r)
#define C__IyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if( (v_h < ~cmax_h)||((v_h == ~cmax_h)&&(v_l < ~(UInt32)cmax_l)) )\
        r = ~csatval;\
    else C__I32DIVI64U32(v_h, v_l, cd, r)
/*END C__IyyDIVI64C32_SAT() */

#define C__IyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if( (v_h > cmax_h)||((v_h == cmax_h)&&(v_l > cmax_l)) )\
        r = csatval;\
    else C__U32DIVU64U32(v_h, v_l, cd, r)
#define C__IyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__IyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__IyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__U32DIVU64U32(v_h, v_l, cd, r)
/*END C__IyyDIVU64C32_SAT() */

#define C__UyyDIVI64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if( (v_h > cmax_h)||((v_h == cmax_h)&&(v_l > cmax_l)) )\
        r = csatval;\
    else if(v_h < 0)\
        r = ~csatval;\
    else C__I32DIVI64U32(v_h, v_l, cd, r)
#define C__UyyDIVI64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if( (v_h > cmax_h)||((v_h == cmax_h)&&(v_l > cmax_l)) )\
        r = csatval;\
    else C__I32DIVI64U32(v_h, v_l, cd, r)
#define C__UyyDIVI64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if(v_h < 0)\
        r = ~csatval;\
    else C__I32DIVI64U32(v_h, v_l, cd, r)
/*END C__UyyDIVI64C32_SAT() */

#define C__UyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    if( (v_h > cmax_h)||((v_h == cmax_h)&&(v_l > cmax_l)) )\
        r = csatval;\
    else C__U32DIVU64U32(v_h, v_l, cd, r)
#define C__UyyDIVU64C32_SATu(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__UyyDIVU64C32_SAT(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)
#define C__UyyDIVU64C32_SATl(v_h, v_l, cd, cmax_h, cmax_l, csatval, r)\
    C__U32DIVU64U32(v_h, v_l, cd, r)
/*END C__UyyDIVU64C32_SAT() */


/******************************************************************************
*
* MACRO:
*   C__I16DIVI32C16_SAT(v, cd, cmax, csatval, r)
*   C__I16DIVU32C16_SAT(v, cd, cmax, csatval, r)
*   C__U16DIVI32C16_SAT(v, cd, cmax, csatval, r)
*   C__U16DIVU32C16_SAT(v, cd, cmax, csatval, r)
*   C__I8DIVI32C16_SAT(v, cd, cmax, csatval, r)
*   C__I8DIVU32C16_SAT(v, cd, cmax, csatval, r)
*   C__U8DIVI32C16_SAT(v, cd, cmax, csatval, r)
*   C__U8DIVU32C16_SAT(v, cd, cmax, csatval, r)
*   C__I8DIVI16C8_SAT(v, cd, cmax, csatval, r)
*   C__I8DIVU16C8_SAT(v, cd, cmax, csatval, r)
*   C__U8DIVI16C8_SAT(v, cd, cmax, csatval, r)
*   C__U8DIVU16C8_SAT(v, cd, cmax, csatval, r)
*
* DESCRIPTION:
*   Macro divides a xxbit value by a zzbit value (with a yybit result);
*   result = v / d;
*
* PARAMETERS:
*   type    name    meaning
*   xIntxx     v    input-value
*   UIntzz    cd    constant denominator
*   xIntxx  cmax    limit of input value for saturation
*   yIntyy   csatval output value for saturation
*   yIntyy     r    result of division (saturated)
*
* RETURNS:
*
* NOTE:
*   for TyWy = Int16:   cmax = (2^15 * n) - 1      ; cmin = -(cmax+1)
*   for TyWy = UInt16:  cmax = (2^16 * n) - 1      ; cmin = -(cmax+1) = 0
*   for TyWy = Int8:    cmax = (2^7 * n) - 1      ; cmin = -(cmax+1)
*   for TyWy = UInt8:   cmax = (2^8 * n) - 1      ; cmin = -(cmax+1) = 0
*
******************************************************************************/
#define C__I16DIVI32C16_SAT(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__I16DIVI32C16_SATu(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__I16DIVI32C16_SATl(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__I16DIVU32C16_SAT(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__I16DIVU32C16_SATu(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__I16DIVU32C16_SATl(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__U16DIVI32C16_SAT(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__U16DIVI32C16_SATu(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__U16DIVI32C16_SATl(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__U16DIVU32C16_SAT(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__U16DIVU32C16_SATu(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__U16DIVU32C16_SATl(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)

#define C__I8DIVI32C16_SAT(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__I8DIVI32C16_SATu(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__I8DIVI32C16_SATl(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__I8DIVU32C16_SAT(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__I8DIVU32C16_SATu(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__I8DIVU32C16_SATl(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__U8DIVI32C16_SAT(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__U8DIVI32C16_SATu(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__U8DIVI32C16_SATl(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__U8DIVU32C16_SAT(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__U8DIVU32C16_SATu(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__U8DIVU32C16_SATl(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)

#define C__I8DIVI16C8_SAT(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__I8DIVI16C8_SATu(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__I8DIVI16C8_SATl(v, cd, cmax, csatval, r)\
    C__IyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__I8DIVU16C8_SAT(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__I8DIVU16C8_SATu(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__I8DIVU16C8_SATl(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__U8DIVI16C8_SAT(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__U8DIVI16C8_SATu(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__U8DIVI16C8_SATl(v, cd, cmax, csatval, r)\
    C__UyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)
#define C__U8DIVU16C8_SAT(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__U8DIVU16C8_SATu(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)
#define C__U8DIVU16C8_SATl(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)


#define C__IyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)\
    if(v > cmax) r = csatval;\
    else if(v < ~cmax) r = ~csatval;\
    else ((r) = (v) / (cd))
#define C__IyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)\
    if(v > cmax) r = csatval;\
    else ((r) = (v) / (cd))
#define C__IyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)\
    if(v < ~cmax) r = ~csatval;\
    else ((r) = (v) / (cd))
/*END C__IyyDIVIxxCzz_SAT() */

#define C__IyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)\
    if(v > cmax) r = csatval;\
    else ((r) = (v) / (cd))
#define C__IyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)\
    C__IyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__IyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)\
    ((r) = (v) / (cd))
/*END C__IyyDIVUxxCzz_SAT() */

#define C__UyyDIVIxxCzz_SAT(v, cd, cmax, csatval, r)\
    if(v > cmax) r = csatval;\
    else if(v < 0) r = 0;\
    else ((r) = (v) / (cd))
#define C__UyyDIVIxxCzz_SATu(v, cd, cmax, csatval, r)\
    if(v > cmax) r = csatval;\
    else ((r) = (v) / (cd))
#define C__UyyDIVIxxCzz_SATl(v, cd, cmax, csatval, r)\
    if(v < 0) r = 0;\
    else ((r) = (v) / (cd))
/*END C__UyyDIVIxxCzz_SAT() */

#define C__UyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)\
    if(v > cmax) r = csatval;\
    else ((r) = (v) / (cd))
#define C__UyyDIVUxxCzz_SATu(v, cd, cmax, csatval, r)\
    C__UyyDIVUxxCzz_SAT(v, cd, cmax, csatval, r)
#define C__UyyDIVUxxCzz_SATl(v, cd, cmax, csatval, r)\
    ((r) = (v) / (cd))
/*END C__UyyDIVUxxCzz_SAT() */



#endif /* #ifndef __div_h__ */
