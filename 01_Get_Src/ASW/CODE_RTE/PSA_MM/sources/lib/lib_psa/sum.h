/******************************************************************************
*
* FILE:
*   AUXDEF.h         1999/03/30
*
* RELATED FILES:
*
* DESCRIPTION:
* - This file contains several macro definitions for the addition and 
*   subtraction with 64bit values
* - C-macros are characterized by a leading "C__".
*   Ansi-C-functions are characterized by a leading "F__".
* - The macro/function-name represents the implemented operation(s):
*	(C__|F__) + output_type + OPERATION + input_type {+ input_type} [+ _SAT] 
*
*   C__I64ADDI32I32():          Addition of 32bit numbers with a 64bit result
*   C__I64ADDI32U32():          Addition of 32bit numbers with a 64bit result
*   C__I64ADDU32I32():          Addition of 32bit numbers with a 64bit result
*   C__I64ADDU32U32():          Addition of 32bit numbers with a 64bit result
*   C__U64ADDI32I32():          Addition of 32bit numbers with a 64bit result
*   C__U64ADDI32U32():          Addition of 32bit numbers with a 64bit result
*   C__U64ADDU32I32():          Addition of 32bit numbers with a 64bit result
*   C__U64ADDU32U32():          Addition of 32bit numbers with a 64bit result
*
*   C__I64SUBI32I32():          Subtraction of 32bit numbers with a 64bit result
*   C__I64SUBI32U32():          Subtraction of 32bit numbers with a 64bit result
*   C__I64SUBU32I32():          Subtraction of 32bit numbers with a 64bit result
*   C__I64SUBU32U32():          Subtraction of 32bit numbers with a 64bit result
*   C__U64SUBI32I32():          Subtraction of 32bit numbers with a 64bit result
*   C__U64SUBI32U32():          Subtraction of 32bit numbers with a 64bit result
*   C__U64SUBU32I32():          Subtraction of 32bit numbers with a 64bit result
*   C__U64SUBU32U32():          Subtraction of 32bit numbers with a 64bit result
*
*   C__I64ADDI64I32():          Addition 64bit + 32bit with a 64bit result
*   C__I64ADDI64U32():          Addition 64bit + 32bit with a 64bit result
*   C__I64ADDU64I32():          Addition 64bit + 32bit with a 64bit result
*   C__I64ADDU64U32():          Addition 64bit + 32bit with a 64bit result
*   C__U64ADDI64I32():          Addition 64bit + 32bit with a 64bit result
*   C__U64ADDI64U32():          Addition 64bit + 32bit with a 64bit result
*   C__U64ADDU64I32():          Addition 64bit + 32bit with a 64bit result
*   C__U64ADDU64U32():          Addition 64bit + 32bit with a 64bit result
*
*   C__I64SUBI64I32():          Subtraction 64bit - 32bit with a 64bit result
*   C__I64SUBI64U32():          Subtraction 64bit - 32bit with a 64bit result
*   C__I64SUBU64I32():          Subtraction 64bit - 32bit with a 64bit result
*   C__I64SUBU64U32():          Subtraction 64bit - 32bit with a 64bit result
*   C__U64SUBI64I32():          Subtraction 64bit - 32bit with a 64bit result
*   C__U64SUBI64U32():          Subtraction 64bit - 32bit with a 64bit result
*   C__U64SUBU64I32():          Subtraction 64bit - 32bit with a 64bit result
*   C__U64SUBU64U32():          Subtraction 64bit - 32bit with a 64bit result
*
*   C__I64SUBI32I64():          Subtraction 32bit - 64bit with a 64bit result
*   C__I64SUBI32U64():          Subtraction 32bit - 64bit with a 64bit result
*   C__I64SUBU32I64():          Subtraction 32bit - 64bit with a 64bit result
*   C__I64SUBU32U64():          Subtraction 32bit - 64bit with a 64bit result
*   C__U64SUBI32I64():          Subtraction 32bit - 64bit with a 64bit result
*   C__U64SUBI32U64():          Subtraction 32bit - 64bit with a 64bit result
*   C__U64SUBU32I64():          Subtraction 32bit - 64bit with a 64bit result
*   C__U64SUBU32U64():          Subtraction 32bit - 64bit with a 64bit result
*
*   C__I64ADDI64I64():          Addition of 64bit numbers 
*   C__I64ADDI64U64():          Addition of 64bit numbers 
*   C__I64ADDU64I64():          Addition of 64bit numbers 
*   C__I64ADDU64U64():          Addition of 64bit numbers 
*   C__U64ADDI64I64():          Addition of 64bit numbers 
*   C__U64ADDI64U64():          Addition of 64bit numbers 
*   C__U64ADDU64I64():          Addition of 64bit numbers 
*   C__U64ADDU64U64():          Addition of 64bit numbers 
*
*   C__I64SUBI64I64():          Subtraction of 64bit mumbers
*   C__I64SUBI64U64():          Subtraction of 64bit mumbers
*   C__I64SUBU64I64():          Subtraction of 64bit mumbers
*   C__I64SUBU64U64():          Subtraction of 64bit mumbers
*   C__U64SUBI64I64():          Subtraction of 64bit mumbers
*   C__U64SUBI64U64():          Subtraction of 64bit mumbers
*   C__U64SUBU64I64():          Subtraction of 64bit mumbers
*   C__U64SUBU64U64():          Subtraction of 64bit mumbers
*
*   C__I64ADDI64I64_SAT():      Addition of 64bit numbers with saturation 
*   C__I64ADDI64I32_SAT():      Addition of 64bit numbers with saturation 
*
*   C__U64ADDU64U64_SAT():      Addition of 64bit numbers 
*   C__U64ADDU64U32_SAT():      Addition of 64bit numbers 
*
*
*
* HISTORY:
*   1997/11/17 - Initial Revision
*                (O. Grajetzky)
*  AUTHOR(S):
*    O. Grajetzky
*
*  Copyright (c) 1999 dSPACE GmbH, GERMANY
*
*  $Workfile: sum.h $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:52GMT+01:00 $ $Author: FrankL $
******************************************************************************/

#ifndef __sum_h__
#define __sum_h__


/******************************************************************************
*
* MACRO:
*   void C__I64ADDI32I32(s1, s2, r_h, r_l)
*   void C__U64ADDI32I32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32     s1    1. 32bit number 
*   Int32     s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*  
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDI32I32(s1, s2, r_h, r_l)\
    r_h = (s1 < 0) ? -1 : 0;\
    if(s2 < 0) r_h -= 1;\
    r_l = s1 + s2;\
    if(r_l < (UInt32)s1) r_h++;\
/*END C__I64ADDI32I32() */

#define C__U64ADDI32I32(s1, s2, r_h, r_l)\
    C__I64ADDI32I32(s1, s2, r_h, r_l)
/*END C__U64ADDI32I32() */


/******************************************************************************
*
* MACRO:
*   void C__I64ADDI64I32_SAT(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add a 64bit value and a 32bit values with a 64bit result and saturation.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32     s1    1. 32bit number 
*   Int32     s2    2. 32bit number 
*   Int32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDI64I32_SAT(s1_h, s1_l, s2, r_h, r_l)\
{\
    Int32 s2_h;\
    s2_h  = (Int32)s2 < 0 ? -1 : 0;\
\
    C__I64ADDI64I64_SAT(s1_h,s1_l,s2_h,s2,r_h,r_l);\
\
}/*END C__I64ADDI64I32_SAT() */\


/******************************************************************************
*
* MACRO:
*   void C__I64ADDI32U32(s1, s2, r_h, r_l)
*   void C__U64ADDI32U32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32     s1    1. 32bit number 
*   UInt32    s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDI32U32(s1, s2, r_h, r_l)\
    r_h = (s1 < 0) ? -1 : 0;\
    r_l = s1 + s2;\
    if(r_l < (UInt32)s1) r_h++;\
/*END C__I64ADDI32U32() */

#define C__U64ADDI32U32(s1, s2, r_h, r_l)\
    C__I64ADDI32U32(s1, s2, r_h, r_l)
/*END C__U64ADDI32U32() */


/******************************************************************************
*
* MACRO:
*   void C__I64ADDU32I32(s1, s2, r_h, r_l)
*   void C__U64ADDU32I32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   UInt32    s1    1. 32bit number 
*   Int32     s2    2. 32bit number 
*   Int32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDU32I32(s1, s2, r_h, r_l)\
    r_h = (s2 < 0) ? -1 : 0;\
    r_l = s1 + s2;\
    if(r_l < s1) r_h++;\
/*END C__I64ADDU32I32() */

#define C__U64ADDU32I32(s1, s2, r_h, r_l)\
    C__I64ADDU32I32(s1, s2, r_h, r_l)
/*END C__U64ADDU32I32() */
               
/******************************************************************************
*
* MACRO:
*   void C__I64ADDU32U32(s1, s2, r_h, r_l)
*   void C__U64ADDU32U32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   UInt32    s1    1. 32bit number 
*   UInt32    s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDU32U32(s1, s2, r_h, r_l)\
    r_l = s1 + s2;\
    if(r_l < s1) r_h = 1;\
    else r_h = 0;\
/*END C__I64ADDU32U32() */

#define C__U64ADDU32U32(s1, s2, r_h, r_l)\
    C__I64ADDU32U32(s1, s2, r_h, r_l)
/*END C__U64ADDU32U32() */



/******************************************************************************
*
* MACRO:
*   void C__I64SUBI32I32(s1, s2, r_h, r_l)
*   void C__U64SUBI32I32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Sub two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32     s1    1. 32bit number 
*   Int32     s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBI32I32(s1, s2, r_h, r_l)\
    r_h = (s1 < 0) ? -1 : 0;\
    if(s2 < 0) r_h += 1;\
    r_l = s1 - s2;\
    if(r_l > s1) r_h--;
/*END C__I64SUBI32I32() */

#define C__U64SUBI32I32(s1, s2, r_h, r_l)\
    C__I64SUBI32I32(s1, s2, r_h, r_l)
/*END C__U64SUBI32I32() */


/******************************************************************************
*
* MACRO:
*   void C__I64SUBI32U32(s1, s2, r_h, r_l)
*   void C__U64SUBI32U32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32     s1    1. 32bit number 
*   UInt32    s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBI32U32(s1, s2, r_h, r_l)\
    r_h = (s1 < 0) ? -1 : 0;\
    r_l = s1 - s2;\
    if(r_l > s1) r_h--;
/*END C__I64SUBI32U32() */        

#define C__U64SUBI32U32(s1, s2, r_h, r_l)\
    C__I64SUBI32U32(s1, s2, r_h, r_l)
/*END C__U64SUBI32U32() */        


/******************************************************************************
*
* MACRO:
*   void C__I64SUBU32I32(s1, s2, r_h, r_l)
*   void C__U64SUBU32I32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Sub two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning            				                
*   UInt32    s1    1. 32bit number 
*   Int32     s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBU32I32(s1, s2, r_h, r_l)\
    r_h = (s2 < 0) ? 1 : 0;\
    r_l = s1 - s2;\
    if(r_l > s1) r_h--;
/*END C__I64SUBU32I32() */        

#define C__U64SUBU32I32(s1, s2, r_h, r_l)\
    C__I64SUBU32I32(s1, s2, r_h, r_l)
/*END C__U64SUBU32I32() */        


/******************************************************************************
*
* MACRO:
*   void C__I64SUBU32U32(s1, s2, r_h, r_l)
*   void C__U64SUBU32U32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Sub two 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   UInt32    s1    1. 32bit number 
*   UInt32    s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBU32U32(s1, s2, r_h, r_l)\
    r_l = s1 - s2;\
    if(r_l > s1) r_h = -1;\
    else r_h = 0;
/*END C__I64SUBU32U32() */        

#define C__U64SUBU32U32(s1, s2, r_h, r_l)\
    C__I64SUBU32U32(s1, s2, r_h, r_l)
/*END C__U64SUBU32U32() */        


/******************************************************************************
*
* MACRO:
*   void C__I64ADDI64I32(s1_h, s1_l, s2, r_h, r_l)
*   void C__U64ADDI64I32(s1_h, s1_l, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add a 64bit value and a 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_1    1. 64bit number (low-part)
*   Int32     s2    2. 32bit number 
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDI64I32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    if(s2 < 0) r_h -= 1;\
    r_l = temp + s2;\
    if(r_l < temp) r_h++;\
\
}/*END C__I64ADDI64I32() */

#define C__U64ADDI64I32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64ADDI64I32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64ADDI64I32() */


/******************************************************************************
*
* MACRO:
*   void C__I64ADDI64U32(s1_h, s1_l, s2, r_h, r_l)
*   void C__U64ADDI64U32(s1_h, s1_l, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add a 64bit value and a 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_1    1. 64bit number (low-part)
*  UInt32     s2    2. 32bit number 
*  yInt32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDI64U32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    r_l = temp + s2;\
    if(r_l < temp) r_h++;\
}/*END C__I64ADDI64U32() */

#define C__U64ADDI64U32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64ADDI64U32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64ADDI64U32() */


/******************************************************************************
*
* MACRO:
*   void C__I64ADDU64I32(s1_h, s1_l, s2, r_h, r_l)
*   void C__U64ADDU64I32(s1_h, s1_l, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add a 64bit value and a 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*  UInt32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_1    1. 64bit number (low-part)
*   Int32     s2    2. 32bit number 
*  yInt32    r_h    64bit result    (high-part)                     
*  UInt32    r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDU64I32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    if(s2 < 0) r_h -= 1;\
    r_l = temp + s2;\
    if(r_l < temp) r_h++;\
}/*END C__I64ADDU64I32() */

#define C__U64ADDU64I32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64ADDU64I32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64ADDU64I32() */


/******************************************************************************
*
* MACRO:
*   void C__I64ADDU64U32(s1_h, s1_l, s2, r_h, r_l)
*   void C__U64ADDU64U32(s1_h, s1_l, s2, r_h, r_l)
*
* DESCRIPTION:
*   Add a 64bit value and a 32bit values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*  UInt32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_1    1. 64bit number (low-part)
*  UInt32     s2    2. 32bit number 
*  yInt32    r_h    64bit result    (high-part)                     
*  UInt32    r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDU64U32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    r_l = temp + s2;\
    if(r_l < temp) r_h++;\
}/*END C__I64ADDU64U32() */

#define C__U64ADDU64U32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64ADDU64U32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64ADDU64U32() */


 
/******************************************************************************
*
* MACRO:
*   void C__I64SUBI64I32(s1, s2, r_h, r_l)
*   void C__U64SUBI64I32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Sub a 32bit value from a 64bit value with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_l    1. 64bit number (low-part)
*   Int32     s2    2. 32bit number 
*  yInt32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBI64I32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    if(s2 < 0) r_h += 1;\
    r_l = temp - s2;\
    if(r_l > temp) r_h--;\
}/*END C__I64SUBI64I32() */

#define C__U64SUBI64I32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64SUBI64I32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64SUBI64I32() */


/******************************************************************************
*
* MACRO:
*   void C__I64SUBI64U32(s1, s2, r_h, r_l)
*   void C__U64SUBI64U32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Sub a 32bit value from a 64bit value with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_l    1. 64bit number (low-part)
*  UInt32     s2    2. 32bit number 
*  yInt32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBI64U32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    r_l = temp - s2;\
    if(r_l > temp) r_h--;\
}/*END C__I64SUBI64U32() */        

#define C__U64SUBI64U32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64SUBI64U32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64SUBI64U32() */        


/******************************************************************************
*
* MACRO:
*   void C__I64SUBU64I32(s1, s2, r_h, r_l)
*   void C__U64SUBU64I32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Sub a 32bit value from a 64bit value with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*  UInt32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_l    1. 64bit number (low-part)
*   Int32     s2    2. 32bit number 
*  yInt32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBU64I32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    if(s2 < 0) r_h += 1;\
    r_l = temp - s2;\
    if(r_l > temp) r_h--;\
}/*END C__I64SUBU64I32() */        

#define C__U64SUBU64I32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64SUBU64I32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64SUBU64I32() */        


/******************************************************************************
*
* MACRO:
*   void C__I64SUBU64U32(s1, s2, r_h, r_l)
*   void C__U64SUBU64U32(s1, s2, r_h, r_l)
*
* DESCRIPTION:
*   Sub a 32bit value from a 64bit value with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*  UInt32   s1_h    1. 64bit number (high-part)
*  UInt32   s1_l    1. 64bit number (low-part)
*  UInt32     s2    2. 32bit number 
*  yInt32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64SUBU64U32(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_h = s1_h;\
    r_l = temp - s2;\
    if(r_l > temp) r_h--;\
}/*END C__I64SUBU64U32() */        

#define C__U64SUBU64U32(s1_h, s1_l, s2, r_h, r_l)\
    C__I64SUBU64U32(s1_h, s1_l, s2, r_h, r_l)
/*END C__U64SUBU64U32() */        


/******************************************************************************
*
* MACRO:
*   void C__I64SUBI32I64(s1, s2_h, s2_l, r_h, r_l)
*   void C__I64SUBI32U64(s1, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBI32I64(s1, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBI32U64(s1, s2_h, s2_l, r_h, r_l)
*
* DESCRIPTION:
*   Sub a 64bit value from a 32bit value with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32     s1    1. 32bit number 
*   Int32   s2_h    2. 64bit number (high-part)
*  xInt32   s2_l    2. 64bit number (low-part)
*  yInt32    r_h    64bit result    (high-part)                     
*  UInt32    r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY: 
* 2001-05-03 remark: if s1 is negative the pseudo high byte must set to -1.
*
******************************************************************************/
#define C__I64SUBI32I64(s1, s2_h, s2_l, r_h, r_l)\
    r_h = (s1 < 0) ? (-1 - s2_h) : (-s2_h);\
    r_l = s1 - s2_l;\
    if(r_l > s1) r_h--;\
/*END C__I64SUBI32I64() */

#define C__I64SUBI32U64(s1, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI32I64(s1, s2_h, s2_l, r_h, r_l)
/*END C__I64SUBI32U64() */

#define C__U64SUBI32I64(s1, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI32I64(s1, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBI32I64() */

#define C__U64SUBI32U64(s1, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI32I64(s1, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBI32U64() */


/******************************************************************************
*
* MACRO:
*   void C__I64SUBU32I64(s1, s2_h, s2_l, r_h, r_l)
*   void C__I64SUBU32U64(s1, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBU32I64(s1, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBU32U64(s1, s2_h, s2_l, r_h, r_l)
*
* DESCRIPTION:
*   Sub a 64bit value from a 32bit value with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*  UInt32     s1    1. 32bit number 
*   Int32   s2_h    2. 64bit number (high-part)
*  xInt32   s2_l    2. 64bit number (low-part)
*  yInt32    r_h    64bit result    (high-part)                     
*  UInt32    r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*
*   
* HISTORY: 
*
******************************************************************************/
#define C__I64SUBU32I64(s1, s2_h, s2_l, r_h, r_l)\
    r_h = -s2_h;\
    r_l = s1 - s2_l;\
    if(r_l > s1) r_h--;\
/*END C__I64SUBU32I64() */

#define C__I64SUBU32U64(s1, s2_h, s2_l, r_h, r_l)\
    C__I64SUBU32I64(s1, s2_h, s2_l, r_h, r_l)
/*END C__I64SUBU32U64() */

#define C__U64SUBU32I64(s1, s2_h, s2_l, r_h, r_l)\
    C__I64SUBU32I64(s1, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBU32I64() */

#define C__U64SUBU32U64(s1, s2_h, s2_l, r_h, r_l)\
    C__I64SUBU32I64(s1, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBU32U64() */



/******************************************************************************
*
* MACRO:
*   void C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__I64ADDI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__I64ADDU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__I64ADDU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64ADDI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64ADDU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64ADDU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*
* DESCRIPTION:
*   Add two 64bit signed values with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   xInt32  s1_h    1. 64bit number (high-part)                            
*   UInt32  s1_l    1. 64bit number (low-part)                                    
*   xInt32  s2_h    2. 64bit number (high-part)                                
*   UInt32  s2_l    2. 64bit number (low-part)                			
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_l = s1_l + s2_l;\
    r_h = s1_h + s2_h;\
    if(r_l < temp) r_h++;               /*add with carry */\
}
/*END C__I64ADDI64I64() */

#define C__I64ADDI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__I64ADDI64U64() */

#define C__I64ADDU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__I64ADDU64I64() */

#define C__I64ADDU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__I64ADDU64U64() */

#define C__U64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64ADDI64I64() */

#define C__U64ADDI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64ADDI64U64() */

#define C__U64ADDU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64ADDU64I64() */

#define C__U64ADDU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64ADDI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64ADDU64U64() */



/******************************************************************************
*
* MACRO:
*   void C__I64ADDI64I64_SAT(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*
* DESCRIPTION:
*   Add two 64bit signed values with a 64bit result and saturation.
*
* PARAMETERS:
*   type    name    meaning                                            
*   Int32   s1_h    1. 64bit number (high-part)                            
*   UInt32  s1_l    1. 64bit number (low-part)                                    
*   Int32   s2_h    2. 64bit number (high-part)                                
*   UInt32  s2_l    2. 64bit number (low-part)                			
*   Int32    r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   
* HISTORY:
*
******************************************************************************/
#define C__I64ADDI64I64_SAT(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
{\
    UInt32 temp    = s1_l;\
    UInt8  carry   = 0;\
\
    r_l = s1_l + s2_l;\
    if(r_l < temp) carry++;\
    temp = (UInt32)(s1_h + s2_h + carry);\
    if ( (s1_h >= 0) && (s2_h >= 0) && ((Int32)temp < 0) )\
    {\
        r_h = 0x7fffffff;\
        r_l = 0xffffffff;\
    } \
    else if ((s1_h < 0) && (s2_h < 0) && ((Int32)temp >= 0)  )\
    {\
         r_h = 0x80000000;\
         r_l = 0x0;\
    }\
    else\
    {\
         r_h = (Int32)temp;\
    }\
}\
/*END C__I64ADDI64I64_SAT() */



/******************************************************************************
*
* MACRO:
*   void C__U64ADDU64U64_SAT(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*
* DESCRIPTION:
*   Add two 64bit signed values with a 64bit saturated result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   UInt32  s1_h    1. 64bit number (high-part)                            
*   UInt32  s1_l    1. 64bit number (low-part)                                    
*   UInt32  s2_h    2. 64bit number (high-part)                                
*   UInt32  s2_l    2. 64bit number (low-part)                			
*   UInt32  r_h     64bit result    (high-part)                     
*   UInt32  r_l     64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   
* HISTORY:
*
******************************************************************************/
#define C__U64ADDU64U64_SAT(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
{\
    UInt32 temp  = s1_l;\
	UInt8  carry = 0;\
\
    r_l = s1_l + s2_l;\
    if(r_l < temp)	carry++;\
\
	temp = s1_h;\
\
	r_h = s1_h + s2_h;\
\
    if(r_h >= temp)             /*add with carry */\
    {\
		temp  = r_h;\
		r_h  += carry;\
		if(r_h < temp)\
		{\
		    r_h = 0xFFFFFFFF;\
		    r_l = 0xFFFFFFFF;\
		}\
	}\
	else\
	{\
		r_h = 0xFFFFFFFF; r_l = 0xFFFFFFFF;\
	}\
}

/******************************************************************************
*
* MACRO:
*   void C__U64ADDU64U32_SAT(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*
* DESCRIPTION:
*   Add a 64bit value with a 32bit value with a 64Bit saturated result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   UInt32  s1_h    1. 64bit number (high-part)                            
*   UInt32  s1_l    1. 64bit number (low-part)                                    
*   UInt32  s2_h    2. 64bit number (high-part)                                
*   UInt32  s2_l    2. 64bit number (low-part)                			
*   UInt32  r_h     64bit result    (high-part)                     
*   UInt32  r_l     64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   
* HISTORY:
*
******************************************************************************/
#define C__U64ADDU64U32_SAT(s1_h, s1_l, s2, r_h, r_l)\
{\
    UInt32 temp  = s1_l;\
	UInt8  carry = 0;\
\
    r_l = s1_l + s2;\
    if(r_l < temp)	carry++;\
\
	temp  = s1_h;\
	r_h   = s1_h + carry;\
\
    if(r_h < temp)\
    {\
		r_h = 0xFFFFFFFF;\
		r_l = 0xFFFFFFFF;\
	}\
}\



/******************************************************************************
*
* MACRO:
*   void C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__I64SUBU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__I64SUBI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__I64SUBU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*   void C__U64SUBU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
*
* DESCRIPTION:
*   Subtracts operand1 - operrand2 with a 64bit result.
*
* PARAMETERS:
*   type    name    meaning                                            
*   xInt32   s1_h   1. 64bit number (high-part)
*   UInt32  s1_l    1. 64bit number (low-part)
*   xInt32   s2_h   2. 64bit number (high-part)
*   UInt32  s2_l    2. 64bit number (low-part)                            
*   yInt32   r_h    64bit result    (high-part)                     
*   UInt32   r_l    64bit result    (low-part)    
*
* RETURNS:
*
* NOTE:
*   The input value(s) is(are) used more than one time inside this macro.
*     For this reason, no expressions should be inserted at the macro call. 
*
*
* HISTORY:
*
******************************************************************************/
#define C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
{\
    UInt32 temp = s1_l;\
    r_l = s1_l - s2_l;            /* sub low-part      */\
    r_h = s1_h - s2_h;            /* sub high-part         */\
    if(r_l > temp) r_h--;        /* sub witch carrry      */\
}
/*END C__I64SUBI64I64() */

#define C__I64SUBU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__I64SUBU64I64() */

#define C__I64SUBI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__I64SUBI64U64() */

#define C__I64SUBU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__I64SUBU64U64() */

#define C__U64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBI64I64() */

#define C__U64SUBI64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBI64U64() */

#define C__U64SUBU64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBU64I64() */

#define C__U64SUBU64U64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)\
    C__I64SUBI64I64(s1_h, s1_l, s2_h, s2_l, r_h, r_l)
/*END C__U64SUBU64U64() */




#endif /* #ifndef __sum_h__ */
