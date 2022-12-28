/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Mcal_Compiler.h $                                          **
**                                                                            **
**   $CC VERSION : \main\17 $                                                 **
**                                                                            **
**   $DATE       : 2014-02-07 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This header file exports Mcal compiler specific            **
                   functions and macros                                       **
**                                                                            **
**   SPECIFICATION(S) : NA                                                    **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                            **
*******************************************************************************/
#ifndef MCAL_COMPILER_H 
#define MCAL_COMPILER_H  

#define VALEO_PATCH_MCAL_GNU_C_TRICORE
/*The compiler define is normally created using -D option of compiler         */
/*RTA-OS tool needs a real define and cannot interpret compiler option        */
/*So Mcal_Compiler.h file is duplicated in "include" subfolder only for OS cfg*/
#ifdef VALEO_PATCH_MCAL_GNU_C_TRICORE
#ifndef _GNU_C_TRICORE_
#define _GNU_C_TRICORE_ 1U
#endif
#endif /*VALEO_PATCH_MCAL_GNU_C_TRICORE*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#include "Intrinsics.h"
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#include "asm.h"
#include "stdarg.h"
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
**                      Configuration data                                    **
*******************************************************************************/


/*
 Keyword for Interrupt
*/

#ifndef INTERRUPT
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define INTERRUPT __interrupt__
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
#define INTERRUPT __interrupt
#endif
#endif


/*
volatile keyword
*/

#ifndef _VOLATILE_
#define _VOLATILE_     volatile
#endif

/*

Inline keyword

*/


#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)

#ifndef _INLINE_
#define _INLINE_       __inline__
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE   static __inline__
#endif

#endif /* #if (_GNU_C_TRICORE_ == 1U) */

#else

#ifndef _INLINE_
#define _INLINE_       inline
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE   static inline
#endif

#endif

/*
extern keyword
*/

#ifndef _EXTERN_
#define _EXTERN_       extern
#endif

#ifdef _GNU_C_TRICORE_

#if (_GNU_C_TRICORE_ == 1U)

#ifndef _IFXEXTERN_
#define _IFXEXTERN_    extern
#endif

#endif /* #if (_GNU_C_TRICORE_ == 1U) */

#else

#ifndef _IFXEXTERN_
#define _IFXEXTERN_    
#endif

#endif
/*
Inline qualifier, in case of GNU compiler extern is required
for inline function definition , if residing in header file.
Its not required for TASKING compiler.
Its defined to nothing.
*/

#ifndef _INLINEQUALIFIER_
#define _INLINEQUALIFIER_  
#endif




/*
Tasking Intrinsic: move contents of the addressed core SFR into a data register
*/

#define MFCR(Reg) (__mfcr((Reg)))



#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*
Tasking Intrinsic: Insert ISYNC Instruction
*/
#define ISYNC() (__isync())

#define DSYNC() (__dsync())
/* Tasking Intrinsic: Disable Global Interrupt Flag */
#define DISABLE() (__disable())
/* Tasking Intrinsic: Enable Global Interrupt Flag */
#define ENABLE() (__enable())

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
extern _INLINE_ unsigned __crc32( unsigned b, unsigned a ) \
__attribute__ ((always_inline));

extern _INLINE_ unsigned __crc32( unsigned b, unsigned a ) {
  unsigned res;
  /* The operands a and b are interchanged because GNU compiler has
   * used V1.0 D9 2010-11 of Tricore instruction manual. In this manual,
   * crc32 instruction uses crc32 D[c], D[a], D[b] instead of
   * crc32 D[c], D[b], D[a]
   */
  __asm__ volatile("crc32 %0, %2, %1" :"=d"(res) : "d"(b), "d"(a): "memory");
    return res;
}

/*
Hitech Intrinsic: Insert ISYNC Instruction
*/
#define ISYNC() _isync()

#define DSYNC() _dsync()
/* Intrinsic: Disable Global Interrupt Flag */
#define DISABLE() _disable()
/* Intrinsic: Enable Global Interrupt Flag */
#define ENABLE() _enable()

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)

/*
Hitech Intrinsic: Insert ISYNC Instruction
*/
#define ISYNC() __isync()

#define DSYNC() __dsync()
/* Intrinsic: Disable Global Interrupt Flag */
#define DISABLE() _disable()
/* Intrinsic: Enable Global Interrupt Flag */
#define ENABLE() _enable()

#define __dsync _dsync
#define __isync _isync
#define __mtcr _mtcr
#define __mfcr _mfcr
#define __nop _nop
#define __abs _abs

#define __crc32(b,a)            (_crc32((unsigned)(b), \
                                        (unsigned)(a)))
                                        
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/*
Tasking Intrinsic: Disable Global Interrupt Flag and return it
*/

#define DISABLE_AND_SAVE() (__disable_and_save())


/*
Tasking Intrinsic: Restore Global Interrupt Flag
*/

#define RESTORE(x) (__restore(x))


/*
Tasking Intrinsic: CRC32 instruction
*/

#define CRC32(b, a) (__crc32((b),(a)))


/*
Tasking Intrinsic:  Move contents of a data register (Data) 
to the addressed core SFR (Reg)
*/
#define MTCR(Reg, Data)   __mtcr((Reg), (Data));\
                          ISYNC()  


#ifndef STATIC
#define STATIC static
#endif


#if defined (_GNU_C_TRICORE_) || defined (_DIABDATA_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U) || (_DIABDATA_C_TRICORE_ == 1U)
#ifndef __indirect
#define __indirect 
#endif /* (_GNU_C_TRICORE_ == 1U) || (_DIABDATA_C_TRICORE_ == 1U) */
#endif 
#endif

/*******************************************************************************
** Macro Syntax : IMASKLDMST(Address, Value, Offset, Bits)                    **
**                                                                            **
** Parameters (in) :  Address: Address of the Variable to be Modified         **
**                    Value  : Value to be written                            **
**                    Offset : Bit Offset from LSB                            **
**                    Bits   : No of Bits Modified                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Description    : IMASKLDMST is used to write atomic instructions in        **
**                  code.The function writes the number of bits of an integer **
**                  value at a certain address location in memory with a ...  **
**                  bitoffset. The number of bits must be a constant value... **
**                  Note that the Address must be Word Aligned.A direct type  **
**                  cast to "int"is needed to avoid Misra Violation           **
*******************************************************************************/

/*
Use of Atomic Write Intrinsic from Tasking. 
*/

/* 
The default option provided here:
extended imaskldmst, that helps to execute
ldmst irrespective of variable allocation. NEAR / FAR
boundary.

If the user desires to use TASKING LDMST 
the following is the convention.
Caveat: the variable should be placed in 
NEAR section.
A direct type cast to "int"
is needed to avoid Misra Violation

#define IMASKLDMST(address,val,offset,bits)  \
  __imaskldmst((signed_int*)(address),\
                                 (signed_int)(val),     \
                                 (signed_int)(offset),  \
                                 (signed_int)(bits)) 

*/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

#define IMASKLDMST(address,val,offset,bits) \
 __asm("imask e2,%0,%1,#" #bits " \n ldmst [%2]0,e2" : : "d" (val), "d" (offset), "a" (address) : "e2")

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)

#define IMASKLDMST(address,val,offset,bits)  __imaskldmst(address, val, offset, bits)
/*! \brief Atomic load-modify-store. */

#define __imaskldmst(address, value, bitoffset, bits) \
  {long long tmp;\
  __asm__("imask %A0,%1,%2,%3":"=d"((long long)tmp):"d"(value),"d"(bitoffset),"i"(bits): "memory");\
  __asm__("ldmst [%0]0,%A1"::"a"(address),"d"(tmp): "memory");}

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)

/*#define IMASKLDMST(address,val,offset,bits)  _imaskldmst(address, val, offset, bits) */


#define  IMASKLDMST(address,val,offset,bits) \
{unsigned long long tmp;\
  tmp = _imaskew( val, offset, bits);\
  _ldmst( tmp, address, 0);\
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
/*
Example:
A variable TESTVAR should be set to value 10 from  bit number 3 to 6.
Case 1:

  uint32 TESTVAR;  assume the variable is located at 0xd0001000 
  IMASKLDMST(&TESTVAR,10,3,4);
  
  This will produce assembly instructions like
    imask e0,#10,#3,#4
  ldmst TESTVAR,e0

Case 2:
  
  Now if the variable is placed at outside 16K boundary
  uint32 TESTVAR __at(0xd0004000);

  Using IMASKLDMST will result in compile time error.
  So the user should use EXT_IMASKLDMST. The resulting
  assembly will be

  mov16 d15,#10
  movh.a  a15,#@his(TESTVAR)
  mov16 d0,#3
  lea a15,[a15]@los(TESTVAR)
  imask e2,d15,d0,#4 
  ldmst [a15]0,e2

*/


/*******************************************************************************
** Macro Syntax : EXTRACT(value,pos,width)                                    **
**                                                                            **
** Parameters (in) :                                                          **
**                    Value  : Value to be extracted                          **
**                    pos : Bit Offset from LSB                               **
**                    Width   : No of Bits to be read                         **
** Parameters (out):  None                                                    **
** return value    : integer (extracted value)                                **
** Description    : EXTRACT is used to read value from a required position    **
**                  for the desired number of bits.                           **
**                  Reads the values in a single instruction when compared    **
**                  mask and loading the same                                 **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define EXTRACT(value,pos,width)            (__extru((signed_int)(value), \
                                                    (signed_int)(pos), \
                                                    (signed_int)(width)))

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#define EXTRACT(value,pos,width)            (__extru((unsigned)(value), \
                                                    (unsigned)(pos), \
                                                    (unsigned)(width)))

/*! \brief Same as __extr() but return bit-field as unsigned integer */

extern _INLINE_ unsigned __extru(unsigned a, unsigned p, unsigned w) {
  unsigned res;
  __asm__ volatile ("mov %%d14,%2  \n\
                     mov %%d15,%3  \n\
                     extr.u %0,%1,%%e14"
                    : "=d" (res) : "d" (a), "d" (p), "d" (w):"d14","d15");
  return res;
}

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define EXTRACT(value,pos,width)            (_extru((unsigned)(value), \
                                                    (unsigned)(pos), \
                                                    (unsigned)(width)))
													
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
** Macro Syntax : Mcal_CountLeadingZeros(Variable)                            **
**                                                                            **
** Parameters (in) :  Variable: variable whose leading zero needs to          **
**                              counted.                                      **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Description     : Macro to Count Leading Zeros in a  variable. The tasking **
**                   intrinsic __clz is used for this purpose.                **
**                                                                            **
*******************************************************************************/
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define Mcal_CountLeadingZeros(Variable) ( _clz((signed_int)(Variable)))

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#elif defined _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define Mcal_CountLeadingZeros(Variable) ( __clz((signed_int)(Variable)))

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#define Mcal_CountLeadingZeros(Variable) ( __CLZ((signed_int)(Variable)))

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Macro Syntax : Mcal_Swap(RetVal,ResourceStatusPtr)                         **
**                                                                            **
** Parameters (in) : RetVal: This variable is updated with status of          **
**                           ResourceStatusPtr                                **
**                   ResourceStatusPtr: This variable is set                  **
** Parameters (out):  None                                                    **
**                                                                            **
** Description     : This function is a implementation of a binary semaphore  **
**                   using swap instruction                                   **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define  Mcal_Swap(RetVal,ResourceStatusPtr)  __asm ("mov\t %0, #1\n" \
             "\tswap.w\t %0, [%1]0" : "=d"(RetVal) : "a"(ResourceStatusPtr))

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#define Mcal_Swap(RetVal,ResourceStatusPtr) \
  __asm__ volatile("mov %0, %1" : "=d"(RetVal) : "i"(1)); \
  __asm__ volatile("swap.w [%1]0, %0" : "=d"(RetVal) : "a"(ResourceStatusPtr));

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define  Mcal_Swap(RetVal,ResourceStatusPtr) __swap_diab(RetVal, ResourceStatusPtr)

asm volatile unsigned int _INLINE_ __swap_diab(unsigned long RetVal, unsigned int *ResourceStatusPtr)
{
%reg RetVal; reg ResourceStatusPtr 
! "%d2"
  mov RetVal, 1 
  swap.w  RetVal, [ResourceStatusPtr]0  
    mov %d2, RetVal
}
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Macro Syntax : cmpswap_w(unsigned int volatile *address,                   **
**                                unsigned int value, unsigned int condition) **
**                                                                            **
** Parameters (in) : address : ResourceStatusPtr address                      **
**                   value: This variable is updated with status of           **
**                           ResourceStatusPtr                                **
** Parameters (out):  None                                                    **
**                                                                            **
** Description     : This function is a implementation of a binary semaphore  **
**                   using compare and swap instruction                       **
*******************************************************************************/
#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
_IFXEXTERN_ _INLINE_ unsigned int cmpswap_w (unsigned int volatile *address,
           unsigned int value, unsigned int condition)
{
  __extension__ unsigned long long reg64
    = value | (unsigned long long) condition << 32;

  __asm__ __volatile__ ("cmpswap.w [%[addr]]0, %A[reg]"
                        : [reg] "+d" (reg64)
                        : [addr] "a" (address)
                        : "memory");
    return reg64;
}
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
** Macro Syntax : Mcal_CmpAndSwap(ResourceStatusPtr,Value,Compare)            **
**                                                                            **
** Parameters (in) : Value: This variable is updated with status of          **
**                           ResourceStatusPtr                                **
**                   ResourceStatusPtr: This variable is set                  **
** Parameters (out):  None                                                    **
**                                                                            **
** Description     : This function is a implementation of a binary semaphore  **
**                   using compare and swap instruction                       **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define  Mcal_CmpAndSwap(ResourceStatusPtr,Value,Compare) \
     __cmpswapw((ResourceStatusPtr), ((unsigned long)Value), (Compare) )

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_ /* TBD _cmpswapw is NA in  intrinsics file : GNU*/
#if (_GNU_C_TRICORE_ == 1U)
#define  Mcal_CmpAndSwap(ResourceStatusPtr,Value,Compare)  \
        cmpswap_w((ResourceStatusPtr), ((unsigned long)Value), (Compare) )

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
asm volatile unsigned int _INLINE_ Mcal_CmpAndSwap(
   unsigned int *ResourceStatusPtr, unsigned long RetVal, unsigned long CmpVal)
{
%reg RetVal,ResourceStatusPtr,CmpVal;
!"%d2","%d3"
  mov %d2,RetVal
  mov %d3,CmpVal  
  cmpswap.w %e2,[ResourceStatusPtr]0
  mov RetVal,%d2
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/*******************************************************************************
** Macro Syntax : get_res(void)                                               **
**                                                                            **
** Parameters (in) :  None                                                    **
** Parameters (out):  None                                                    **
** return value    : integer (extracted value)                                **
** Description    : gets the trp number                                       **
**                                                                            **
*******************************************************************************/
asm volatile int get_res (void)
{
!"%d2" 
  mov  %d2, %d2
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif /* _DIABDATA_C_TRICORE_ */
/*******************************************************************************
** Macro Syntax : __GETTIN(tin)                                               **
**                                                                            **
** Parameters (in) :  None                                                    **
** Parameters (out):  None                                                    **
** return value    : tin : trap number                                        **
** Description    : GETTIN is used to read the trap value from register       **
**                                                                            **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

#define __GETTIN(tin) \
{ \
  __asm("mov %0,d15" : "=d"(tin)); \
}

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)

#define __GETTIN(tin) \
{ \
  __asm__ ("mov \t%0,%%d15":"=d" (tin)); \
}

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)

#define __GETTIN(tin) \
{ \
  __asm (" mov\t %d2,%d15"); \
  tin = get_res();        \
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
** Macro Syntax : __trap_handler(puiAddress)                                  **
**                                                                            **
** Parameters (in) :  puiAddress : Address of trap handler                    **
** Parameters (out):  None                                                    **
** return value    : None                                                     **
** Description    : __trap_handler is used to call the trap handler           **
**                                                                            **
*******************************************************************************/

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

#define __trap_handler(puiAddress) \
  { __asm ("ji\t %0\n\trfe": :"a" (puiAddress)); }

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)

#define __trap_handler(puiAddress) \
  { __asm ("ji\t %0\n\trfe": :"a" (puiAddress)); }

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)

#define __trap_handler(puiAddress) \
{ __asm ("#$$bp"); \
  __asm (" movh.a\t %a15,"#puiAddress"@ha"); \
  __asm (" lea\t %a15,[%a15]"#puiAddress"@l"); \
  __asm (" ji %a15"); \
  __asm (" rfe"); \
  __asm ("#$$ep"); \
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Macro Syntax : __set_trapnum(trapnum)                                      **
**                                                                            **
** Parameters (in) :  trapnum : trap number                                   **
** Parameters (out):  None                                                    **
** return value    : None                                                     **
** Description    : __set_trapnum is used to set the trap number              **
**                                                                            **
*******************************************************************************/

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

#define __set_trapnum(trapnum) \
    { __asm(" addi\t d4,d15,#"#trapnum""); }

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)

#define __set_trapnum(trapnum) \
    { __asm(" addi\t %d4,%d15,"#trapnum""); }

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)

#define __set_trapnum(trapnum) \
    { __asm(" addi\t %d4,%d15,"#trapnum""); }

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Macro Syntax : MEMCPY64(DESTINATION,SOURCE,WORDS)                          **
**                                                                            **
** Parameters (in) :  DESTINATION        : Destination address                **
**                    SOURCE             : Source address                     **
**                    WORDS              : Word counter                       **
** Parameters (out):  None                                                    **
** Return value    : None                                                     **
** Description    : Copy memory content using 64bit access.                   **
**                  DESTINATION and SOURCE should be 32bit aligned.           **
*******************************************************************************/
#if defined(_TASKING_C_TRICORE_)
#if (_TASKING_C_TRICORE_ == 1U)

#define MEMCPY64(DESTINATION, SOURCE, WORDS)            \
    __asm(  "                           \n"             \
            "   mov.aa a2,%1            \n"             \
            "   ld.d   e4,[a2+]8        \n"             \
            "   st.d   [%0+]8,e4        \n"             \
            "   loop   %2,*-8           \n"             \
            :  : "a"(DESTINATION), "a"(SOURCE), "a"(((WORDS)/2)-1)  : "e4", "a2")
/*                0                 1            2               */

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
#define MEMCPY64(DESTINATION, SOURCE, WORDS)            \
		  {													\
		    uint32 i = 0 ;                                  \
		    for (i=0; i< WORDS; i++)                      \
		    {                                               \
		      *((uint32 *)DESTINATION + i) = *((uint32 *)SOURCE + i) ;                  \
		    }                                               \
		  }
/*                0                 1            2               */
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
#define MEMCPY64(DESTINATION, SOURCE, WORDS)            \
		  {													\
		    uint32 i = 0 ;                                  \
		    for (i=0; i< WORDS; i++)                      \
		    {                                               \
		      *((uint32 *)DESTINATION + i) = *((uint32 *)SOURCE + i) ;                  \
		    }                                               \
		  }
/*                0                 1            2               */


#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
  #error "No compiler defined!"
#endif


/*******************************************************************************
** Macro Syntax : MEMWRITE64(DESTINATION,SOURCE)                              **
**                                                                            **
** Parameters (in) :  DESTINATION        : Destination address                **
**                    SOURCE             : Source address                     **
** Parameters (out):  None                                                    **
** Return value    : None                                                     **
** Description    : Write 64bit value from SOURCE into DESTINATION.           **
**                  DESTINATION and SOURCE should be 32bit aligned.           **
*******************************************************************************/
#if defined(_TASKING_C_TRICORE_)
#if (_TASKING_C_TRICORE_ == 1U)

#define MEMWRITE64(DESTINATION, SOURCE)                 \
    __asm(  "                           \n"             \
            "   mov.aa a2,%1            \n"             \
            "   ld.d   e4,[a2]          \n"             \
            "   st.d   [%0],e4          \n"             \
            :  : "a"(DESTINATION), "a"(SOURCE)  : "e4", "a2")
/*                0                 1             */
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
#define MEMWRITE64(DESTINATION, SOURCE)                 \
    __asm(  "                           \n"             \
            "   mov.aa %%a2,%1          \n"             \
            "   ld.d   %%e4,[%%a2+]0    \n"             \
            "   st.d   [%0+]0,%%e4      \n"             \
            :  : "a"(DESTINATION), "a"(SOURCE)  : "d4", "d5", "a2")
/*                0                 1             */
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)

asm volatile void MEMWRITE64(void *DESTINATION, void *SOURCE)
{
%reg DESTINATION,SOURCE;
!"%d4","%d5"
  ld.d   %e4,[SOURCE+]0  
  st.d   [DESTINATION+]0,%e4
}
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
  #error "No compiler defined!"
#endif


/*******************************************************************************
** Macro Syntax : MEMWRITE64_RB(DESTINATION,SOURCE,READBACK)                  **
**                                                                            **
** Parameters (in) :  DESTINATION        : Destination address                **
**                    SOURCE             : Source address                     **
**                    READBACK           : Read back address                  **
** Parameters (out):  None                                                    **
** Return value    : None                                                     **
** Description    : Write 64bit value from SOURCE into DESTINATION and reads  **
**                  back into READBACK.                                       **
**                  DESTIDNATION and SOURCE should be 32bit aligned.          **
*******************************************************************************/
#if defined(_TASKING_C_TRICORE_)
#if (_TASKING_C_TRICORE_ == 1U)

#define MEMWRITE64_RB(DESTINATION, SOURCE, READBACK)    \
    __asm(  "                           \n"             \
            "   mov.aa a2,%1            \n"             \
            "   ld.d   e4,[a2]          \n"             \
            "   st.d   [%0],e4          \n"             \
            "   ld.d   e4,[%0]          \n"             \
            "   st.d   [%2],e4          \n"             \
            :  : "a"(DESTINATION), "a"(SOURCE), "a"(READBACK)  : "e4", "a2")
/*                0                 1            2               */

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)

#define MEMWRITE64_RB(DESTINATION, SOURCE, READBACK)    \
    __asm(  "                           \n"             \
            "   mov.aa %%a2,%1          \n"             \
            "   ld.d   %%e4,[%%a2+]0    \n"             \
            "   st.d   [%0+]0,%%e4      \n"             \
            "   ld.d   %%e4,[%0+]0      \n"             \
            "   st.d   [%2+]0,%%e4      \n"             \
            :  : "a"(DESTINATION), "a"(SOURCE), "a"(READBACK)  : "d4", "d5", "a2")
/*                0                 1            2               */

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
asm volatile void MEMWRITE64_RB(void *DESTINATION, void *SOURCE, void *READBACK)
{
%reg DESTINATION,SOURCE,READBACK;
!"%d4","%d5"
  ld.d   %e4,[SOURCE+]0  
  st.d   [DESTINATION+]0,%e4
  ld.d   %%e4,[DESTINATION+]0
  st.d   [READBACK+]0,%%e4
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
  #error "No compiler defined!"
#endif


/*******************************************************************************
** Macro Syntax : MEMFILL64(DESTINATION,VALUE,WORDS)                          **
**                                                                            **
** Parameters (in) :  DESTINATION        : Destination address                **
**                    VALUE              : 32bit fill value                   **
**                    WORDS              : word counter                       **
** Parameters (out):  None                                                    **
** return value    : None                                                     **
** Description    : Fill DESTINATION memory with VALUE using 64bit access.    **
**                  DESTIDNATION and SOURCE should be 32bit aligned.          **
*******************************************************************************/
#if defined(_TASKING_C_TRICORE_)
#if (_TASKING_C_TRICORE_ == 1U)

#define MEMFILL64(DESTINATION, VALUE, WORDS)            \
    __asm(  "                           \n"             \
            "   mov.aa a2,%0            \n"             \
            "   mov    d4, %1           \n"             \
            "   mov    d5, %1           \n"             \
            "   st.d   [a2+]8,e4        \n"             \
            "   loop   %2,*-4           \n"             \
            :  : "a"(DESTINATION), "d"(VALUE), "a"(((WORDS)/2)-1)  : "e4", "a2")
/*                0                 1->E4       2              */

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
#define MEMFILL64(DESTINATION, VALUE, WORDS)            \
  {													\
    uint32 i = 0 ;                                  \
    for (i=0; i< WORDS; i++)                      \
    {                                               \
      *((uint32 *)DESTINATION + i) = VALUE ;                  \
    }                                               \
  }
#endif /* #if (_GNU_C_TRICORE_ == 1U) */  
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
#define MEMFILL64(DESTINATION, VALUE, WORDS)            \
  {													\
    uint32 i = 0 ;                                  \
    for (i=0; i< WORDS; i++)                      \
    {                                               \
      *((uint32 *)DESTINATION + i) = VALUE ;                  \
    }                                               \
  }

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
  #error "No compiler defined!"
#endif


/*******************************************************************************
** Macro Syntax : MEMCMP64(RESULT,ADDR,VALUE,WORDS)                           **
**                                                                            **
** Parameters (in) :  ADDR               : Address of memory to compare       **
**                    VALUE              : 32bit compare value                **
**                    WORDS              : word counter (32bit)               **
** Parameters (out):  RESULT             : 0 if not all words are the same    **
**                                         1 if all words are the same        **
** return value    : None                                                     **
** Description    : Reads SOURCE memory using 64bit access and compare with   **
**                  VALUE.                                                    **
**                  SOURCE should be 32bit aligned.                           **
*******************************************************************************/
#if defined(_TASKING_C_TRICORE_)
#if (_TASKING_C_TRICORE_ == 1U)

#define MEMCMP64(RESULT, ADDR, VALUE, WORDS)            \
    __asm(  "                           \n"             \
            "   mov    d15,%2           \n"             \
            "   mov.aa a2,%1            \n"             \
            "   mov    %0,#0            \n"             \
            "   ld.d   e6,[a2+]8        \n"             \
            "   jne    d15,d6,*+8       \n"             \
            "   jne    d15,d7,*+6       \n"             \
            "   loop   %3,*-8           \n"             \
            "   mov    %0,#1            \n"             \
            :  "=d"(RESULT) : "a"(ADDR), "d"(VALUE), "a"(((WORDS)/2)-1) : "e6", "d15", "a2" )
/*               0             1            2           3   */

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)

#define MEMCMP64(RESULT, ADDR, VALUE, WORDS)            \
    __asm(  "                           \n"             \
            "   mov    %%d15,%2         \n"             \
            "   mov.aa %%a2,%1          \n"             \
            "   mov    %0,0             \n"             \
            "   ld.d   %%e6,[%%a2+]8    \n"             \
            "   jne    %%d15,%%d6,.+8   \n"             \
            "   jne    %%d15,%%d7,.+6   \n"             \
            "   loop   %3,.-8           \n"             \
            "   mov    %0,1             \n"             \
            :  "=d"(RESULT) : "a"(ADDR), "d"(VALUE), "a"(((WORDS)/2)-1) : "d6", "d7", "d15", "a2" )
/*               0             1            2           3   */

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
/* TBD */
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
  #error "No compiler defined!"
#endif


/*******************************************************************************
**                                                                            **
**                FLS_17_PMU driver specific code                             **
**                                                                            **
*******************************************************************************/

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)

/* FLS WriteCmdCycle start address */
extern uint32 *_lc_gb_FLS_AC_WRITE_SOURCE ;
/* FLS WriteCmdCycle end address */
extern uint32 *_lc_ge_FLS_AC_WRITE_SOURCE ; 
/* FLS EraseCmdCycle start address */
extern uint32 *_lc_gb_FLS_AC_ERASE_SOURCE ;
 /* FLS EraseCmdCycle end address */
extern uint32 *_lc_ge_FLS_AC_ERASE_SOURCE ;

/* FLS WriteCmdCycle start address */
#define FLS_AC_WRITE_SOURCE_START _lc_gb_FLS_AC_WRITE_SOURCE
/* FLS WriteCmdCycle end address */
#define FLS_AC_WRITE_SOURCE_END _lc_ge_FLS_AC_WRITE_SOURCE
/* FLS EraseCmdCycle start address */
#define FLS_AC_ERASE_SOURCE_START _lc_gb_FLS_AC_ERASE_SOURCE
 /* FLS EraseCmdCycle end address */
#define FLS_AC_ERASE_SOURCE_END _lc_ge_FLS_AC_ERASE_SOURCE

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)

/* FLS WriteCmdCycle start address */
extern const uint32 FLS_AC_WRITE_SOURCE_START;
/* FLS WriteCmdCycle end address */
extern const uint32 FLS_AC_WRITE_SOURCE_END; 
/* FLS EraseCmdCycle start address */
extern const uint32 FLS_AC_ERASE_SOURCE_START;
 /* FLS EraseCmdCycle end address */
extern const uint32 FLS_AC_ERASE_SOURCE_END;
 
#endif /* #if (_GNU_C_TRICORE_ == 1U) */ 
#elif defined _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)

/* FLS WriteCmdCycle start address */
extern const uint32 FLS_AC_WRITE_SOURCE_START;
/* FLS WriteCmdCycle end address */
extern const uint32 FLS_AC_WRITE_SOURCE_END; 
/* FLS EraseCmdCycle start address */
extern const uint32 FLS_AC_ERASE_SOURCE_START;
 /* FLS EraseCmdCycle end address */
extern const uint32 FLS_AC_ERASE_SOURCE_END; 
 
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

/************* End of FLS_17_PMU driver specific code *************************/

#endif /* MCAL_COMPILER_H  */
