/******************************************************************************
*
* FILE:
*   COPY.h         1999/04/13
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
*   C__I64COPYI64():             copy value 64bit->64bit 
*   C__U64COPYU64():             copy value 64bit->64bit 
*   C__I64COPYI32():             copy value 32bit->64bit 
*   C__I64COPYU32():             copy value 32bit->64bit 
*   C__U64COPYU32():             copy value 32bit->64bit 
*
* HISTORY:
*   1999/04/13 - Initial Revision
*                (O. Grajetzky)
*  AUTHOR(S):
*    O. Grajetzky
*
*  Copyright (c) 1999 dSPACE GmbH, GERMANY
*
*  $Workfile: copy.h $ $Revision: 1.2 $ $Date: 2006/03/14 10:26:14GMT+01:00 $ $Author: DagmarA $
******************************************************************************/

#ifndef __copy_h__
#define __copy_h__


/******************************************************************************
*
* MACRO:
*   C__I64COPYI64(v_h, v_l, r_h, r_l)
*   C__U64COPYU64(v_h, v_l, r_h, r_l)
*   C__I64COPYU64(v_h, v_l, r_h, r_l)
*   C__U64COPYI64(v_h, v_l, r_h, r_l)
*
* DESCRIPTION:
*   Copies a 64 bit value to a 64bit value
*
* PARAMETERS:
*   type    name    meaning    
*  xInt32   v_h    upper 32bit of the input value
*  UInt32   v_l    lower 32bit of the input value
*  yInt32   r_h    upper 32bit of the result
*  UInt32   r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*
* HISTORY:
*
******************************************************************************/
#define C__I64COPYI64(v_h, v_l, r_h, r_l)\
    r_h = (v_h);\
    r_l = (v_l);
/* END C__I64COPYI64() */

#define C__U64COPYU64(v_h, v_l, r_h, r_l)\
    r_h = (v_h);\
    r_l = (v_l);
/* END C__U64COPYU64() */

#define C__I64COPYU64(v_h, v_l, r_h, r_l)\
    r_h = (Int32)(v_h);\
    r_l = (v_l);
/* END C__I64COPYU64() */

#define C__U64COPYI64(v_h, v_l, r_h, r_l)\
    r_h = (UInt32)(v_h);\
    r_l = (v_l);
/* END C__U64COPYI64() */


/******************************************************************************
*
* MACRO:
*   C__I64COPYI32(v, r_h, r_l)
*   C__I64COPYU32(v, r_h, r_l)
*   C__U64COPYU32(v, r_h, r_l)
*   C__U64COPYI32(v, r_h, r_l)
*
* DESCRIPTION:
*   Copies a 32 bit value to a 64bit value
*
* PARAMETERS:
*   type    name    meaning    
*  xInt32   v       input value
*  yInt32   r_h    upper 32bit of the result
*  UInt32   r_l    lower 32bit of the result
*
* RETURNS:
*
* NOTE:
*
* HISTORY:
*
******************************************************************************/
#define C__I64COPYI32(v, r_h, r_l)\
    r_h = (v) >> 31;\
    r_l = (UInt32)(v);
/* END C__I64COPYI32() */

#define C__I64COPYU32(v, r_h, r_l)\
    r_h = 0;\
    r_l = (v);
/* END C__I64COPYI32() */

#define C__U64COPYU32(v, r_h, r_l)\
    r_h = 0;\
    r_l = (v);
/* END C__I64COPYI32() */

#define C__U64COPYI32(v, r_h, r_l)\
    r_h = 0;\
    r_l = (UInt32)(v);
/* END C__U64COPYI32() */



#endif /* #ifndef __copy_h__ */
