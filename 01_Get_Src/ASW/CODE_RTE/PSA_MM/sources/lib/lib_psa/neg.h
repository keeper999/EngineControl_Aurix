/******************************************************************************
*
* FILE:
*   NEG.h         1999/03/31
*
* RELATED FILES:
*
* DESCRIPTION:
* - This file contains several macro definitions 
*   for the negation with 64bit values
* - C-macros are characterized by a leading "C__".
*   Ansi-C-functions are characterized by a leading "F__".
* - The macro/function-name represents the implemented operation(s):
*	(C__|F__) + output_type + OPERATION + input_type {+ input_type} [+ _SAT] 
*
*   C__I64NEGI64():             negate value 64bit->64bit 
*   C__I64NEGU64():             negate value 64bit->64bit 
*   C__I64NEGI32():             negate value 32bit->64bit 
*   C__I64NEGU32():             negate value 32bit->64bit 
*
* HISTORY:
*   1997/11/17 - Initial Revision
*                (O. Grajetzky)
*  AUTHOR(S):
*    O. Grajetzky
*
*  Copyright (c) 1999 dSPACE GmbH, GERMANY
*
*  $Workfile: neg.h $ $Revision: 1.3 $ $Date: 2008/01/15 15:28:50GMT+01:00 $ $Author: KarstenF $
******************************************************************************/

#ifndef __neg_h__
#define __neg_h__


/******************************************************************************
*
* MACRO:
*   C__I64NEGI64(v_h, v_l, r_h, r_l)
*   C__I64NEGU64(v_h, v_l, r_h, r_l)
*
* DESCRIPTION:
*   Negates a 64 bit value to a 64bit value
*
* PARAMETERS:
*   type    name    meaning    
*  xInt32   v_h    upper 32bit of the input value
*  UInt32   v_l    lower 32bit of the input value
*   Int32   r_h    upper 32bit of the result
*  UInt32   r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*
* HISTORY:
*
******************************************************************************/
#define C__I64NEGI64(v_h, v_l, r_h, r_l)\
	r_l = -(v_l);	/* complement */\
	r_h = ~v_h;\
	if(r_l == 0) ++r_h;
/* END C__I64NEGI64() */

#define C__I64NEGU64(v_h, v_l, r_h, r_l)\
	r_l = -(v_l);	/* complement */\
	r_h = (Int32)~v_h;\
	if(r_l == 0) ++r_h;
/* END C__I64NEGU64() */

/******************************************************************************
*
* MACRO:
*   C__I64NEGI32(v, r_h, r_l)
*   C__I64NEGU32(v, r_h, r_l)
*
* DESCRIPTION:
*   Negates a 32 bit value to a 64bit value
*
* PARAMETERS:
*   type    name    meaning    
*  xInt32   v       input value
*   Int32   r_h    upper 32bit of the result
*  UInt32   r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*
* HISTORY:
*
******************************************************************************/
#define C__I64NEGI32(v, r_h, r_l)\
    r_l = (UInt32)(-(v));\
    r_h = (v > 0 ? -1 : 0);
/* END C__I64NEGI32() */

#define C__I64NEGU32(v, r_h, r_l)\
    r_l = -(v);\
    r_h = (v > 0 ? -1 : 0);
/* END C__I64NEGU32() */



#endif /* #ifndef __neg_h__ */
