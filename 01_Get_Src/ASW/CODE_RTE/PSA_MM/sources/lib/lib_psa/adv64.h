/******************************************************************************
*
* FILE:
*   ADV64.h         1999/03/31
*
* RELATED FILES:
*
* DESCRIPTION:
* - File contains advanced functions and macros for 64bit arithmetic
*   This file functions and macros in this file are implemented in ANSI-C Code, 
*   but they are target dependent! The functions are using complex data types 
*   containing structs, unions and arrays, so the handling of some pointers 
*   depends on the "Endian" of the target.
* - C-macros are characterized by a leading "C__".
*   Ansi-C-functions are characterized by a leading "F__".
* - The macro/function-name represents the implemented operation(s):
*	(C__|F__) + output_type + OPERATION + input_type {+ input_type} [+ _SAT] 
* - Note: The target's endian must be defined in the "tl_types.h" file.
*
***** TYPEDEFS *****
*   UInt64s             64bit data type containing a two 32bit values (struct)
*   UInt32s             32bit data type containing a two 16bit values (struct)
*
***** BASE FUNCTIONS *****
*   negate();           negate a 64bit value
*
***** MUL *****
*   F__U64sMULU32U32(); multiply two 32bit values with a 64bit result (internal use)    
*   F__I64sMULI32U32(); multiply two 32bit values with a 64bit result (internal use)
*   F__I64sMULU32I32(); multiply two 32bit values with a 64bit result (internal use)
*   F__I64sMULI32I32(); multiply two 32bit values with a 64bit result (internal use)
*
***** DIV *****
*   div3by2();          divide a 3-digit value by a 2-digit value (internal use)
*
*   F__U64sDIVU64sU16();divide a 64bit value by a 16bit value (internal use)
*   F__U32DIVU64sU16(); divide a 64bit value by a 16bit value (internal use)
*
*   F__U64sDIVU64sU32();divide a 64bit value by a 32 bit value (internal use)
*   F__I64sDIVI64sU32();divide a 64bit value by a 32 bit value (internal use)
*   F__I64sDIVU64sI32();divide a 64bit value by a 32 bit value (internal use)
*   F__I64sDIVI64sI32();divide a 64bit value by a 32 bit value (internal use)
*   F__U32DIVU64sU32(); divide a 64bit value by a 32 bit value (internal use)
*   F__I32DIVI64sU32(); divide a 64bit value by a 32 bit value (internal use)
*   F__I32DIVU64sI32(); divide a 64bit value by a 32 bit value (internal use)
*   F__I32DIVI64sI32(); divide a 64bit value by a 32 bit value (internal use)
*
* HISTORY:
*   1998/03/06 - Initial Revision
*                (O. Grajetzky)
*  AUTHOR(S):
*    O. Grajetzky
*
*  Copyright (c) 1999 dSPACE GmbH, GERMANY
*
*  $Workfile: adv64.h $ $Revision: 1.2 $ $Date: 2005/07/05 16:06:55GMT+01:00 $ $Author: SebastianH $
******************************************************************************/

#ifndef __adv64_h__
#define __adv64_h__


/* Definition of basic type */
#ifdef LITTLE_ENDIAN	/* Target with little-endian architecture */

 typedef struct
 {	
	UInt32 lo;
	UInt32 hi;
 } UInt64s;

 typedef union 
 {
	UInt32 lng;
	UInt16 pr[2]; /* element 0: lo; element 1: hi */
 } UInt32s;
 
#else
 #ifdef BIG_ENDIAN	/* Target with big-endian architecture */

  typedef struct
  {	
	UInt32 hi;
	UInt32 lo;
  } UInt64s;

  typedef union 
  {
	UInt32 lng;
	UInt16 pr[2]; /* element 1: hi; element 0: lo */
  } UInt32s;
 #else

  #error "The definition LITTLE_ENDIAN or BIG_ENDIAN is not define! Please check the file tllimits.h and set the endian."

 #endif
#endif


/* negate a UInt64s */
void negate(UInt64s *x);

                                                     
/* Multiply two UInt32s to yield a UInt64s */
UInt64s F__U64sMULU32U32(const UInt32 x, const UInt32 y);

/* Multiply Int32 with UInt32 to yield a UInt64s using Booth's algorithm */
UInt64s F__I64sMULI32U32(const Int32 x, const UInt32 y);

/* Multiply UInt32 with Int32 to yield a UInt64s using Booth's algorithm */
#define F__I64sMULU32I32(x, y) \
    F__I64sMULI32U32(y, x)

/* Multiply two Int32 to yield a Int64s using Booth's algorithm */
UInt64s F__I64sMULI32I32(const Int32 x, const Int32 y);

/* divide three digits by two (used by multiword division) */
UInt16 div3by2(UInt16 u[3], UInt32s v);

/* divide a UInt64s by an UInt16 */
UInt64s F__U64sDIVU64sU16(const UInt64s *u, UInt16 a);

/* divide a UInt64s by an UInt16 */
UInt32 F__U32DIVU64sU16(const UInt64s *u, UInt16 a);

/* divide unsigned UInt64s by UInt32 */
UInt64s F__U64sDIVU64sU32(const UInt64s *U, UInt32 v);

/* mixed division of Int64s by UInt32 */
UInt64s F__I64sDIVI64sU32(const UInt64s *u, UInt32 a);

/* mixed division of UInt64s by Int32 */
UInt64s F__I64sDIVU64sI32(const UInt64s *u, Int32 a);

/* signed division of Int64s by Int32 */
UInt64s F__I64sDIVI64sI32(const UInt64s *u, Int32 a);

/* divide unsigned UInt64s by UInt32 */
UInt32 F__U32DIVU64sU32(const UInt64s *U, UInt32 v);

/* mixed division of Int64s by UInt32 */
Int32 F__I32DIVI64sU32(const UInt64s *u, UInt32 a);

/* mixed division of UInt64s by Int32 */
Int32 F__I32DIVU64sI32(const UInt64s *u, Int32 a);

/* signed division of Int64s by Int32 */
Int32 F__I32DIVI64sI32(const UInt64s *u, Int32 a);



#endif /* #ifndef __adv64_h__ */
