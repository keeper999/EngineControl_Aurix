/**
 * \file IntrinsicsGnuc.h
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
 *
 *
 * $Revision: 1415 $
 * $Date: 2013-02-19 16:15:13 +0100 (Di, 19 Feb 2013) $
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Cpu_Intrinsics_Gnuc Intrinsics for GNU compiler
 * \ingroup IfxLld_Cpu_Intrinsics
 *
 */
#ifndef INTRINSICSGNUC_H
#define INTRINSICSGNUC_H


//dbg

/******************************************************************************/
/*#include "Ifx_Types.h"*/
/******************************************************************************/

typedef long                fract;
typedef short               sfract;
typedef long long           laccum;
typedef long                __packb; //MSMRK should be struct of four chars
typedef unsigned long       __upackb;//MSMRK should be struct of four unsigned chars
typedef long                __packhw; //MSMRK should be struct of two shorts
typedef unsigned long       __upackhw;//MSMRK should be struct of two unsigned shorts
typedef unsigned long       uint32;         /**< \brief                    0 .. 4294967295               */

#define IFX_INLINE                  static inline   //__attribute__((always_inline))


/* Note: you must use a numerical constant here (not an integer variable),
   otherwise the assembler will issue an error message.  */
#define __bisr(intlvl) __tric_bisr(intlvl)
#define _bisr(intlvl) __tric_bisr(intlvl)
#define __tric_bisr(intlvl) __asm__ volatile ("bisr "STRINGIFY(intlvl) : : : "memory")

/* Note: The parameter "regaddr" in the _mfcr and _mtcr macros may either
   be specified as a 16-bit constant or as a symbolic name (e.g., $psw).  */
#ifndef __MFCR
#define __MFCR(regaddr) __tric_mfcr(regaddr & 0xffff)
#endif

#define __mfcr(regaddr) __tric_mfcr(regaddr)
#define _mfcr(regaddr) __tric_mfcr(regaddr)
#define __tric_mfcr(regaddr) \
 ({ int res; __asm__ volatile ("mfcr %0,%1": "=d" (res) :"i"(regaddr): "memory"); res; })
//  ({ int res; __asm__ volatile ("mfcr %0,"STRINGIFY(regaddr) : "=d" (res) : : "memory"); res; })	//dbg



#ifndef __MTCR
#define __MTCR(regaddr,val) __tric_mtcr(regaddr & 0xffff,val)
#endif

#define __mtcr(regaddr,val) __tric_mtcr(regaddr,val)
#define _mtcr(regaddr,val) __tric_mtcr(regaddr,val)
#define __tric_mtcr(regaddr,val) \
   __asm__ volatile ("mtcr %0,%1\n\tisync"::"i"(regaddr),"d"(val):"memory")
//  { int newval = (val); __asm__ volatile ("mtcr "STRINGIFY(regaddr)",%0" : : "d" (newval) : "memory"); } // dbg

/* Note: you must use a numerical constant here (not an integer variable),
   otherwise the assembler will issue an error message.  */
#define _syscall(svcno) __tric_syscall(svcno)
#define __syscall(svcno) __tric_syscall(svcno)
#define __tric_syscall(svcno) __asm__ volatile ("syscall "STRINGIFY(svcno) : : : "memory")

#define _disable() __asm__ volatile ("disable" : : : "memory")
#define _enable() __asm__ volatile ("enable" : : : "memory")
#define _debug() __asm__ volatile ("debug" : : : "memory")
#define _isync() __asm__ volatile ("isync" : : : "memory")
#define _dsync() __asm__ volatile ("dsync" : : : "memory")
#define _rstv() __asm__ volatile ("rstv" : : : "memory")
#define _rslcx() __asm__ volatile ("rslcx" : : : "memory")
#define _svlcx() __asm__ volatile ("svlcx" : : : "memory")
#define _nop() __asm__ volatile ("nop")

#ifndef __CLZ
#define __CLZ(val)      __builtin_clz(val)
#endif
#ifndef __CTZ
#define __CTZ(val)      __builtin_ctz(val)
#endif
#ifndef __ABS
#define __ABS(val)      __builtin_abs(val)
#endif






//dbg


/* *INDENT-OFF* */
#define STRINGIFY(x)    #x

/** Function call without return
 */
#define __non_return_call(fun)   __asm__ volatile ("j "#fun)

/** Jump and link
 */
IFX_INLINE void __jump_and_link(void (*fun)(void))
{
   __asm__ volatile ("jli %0"::"a"(fun));
}

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_any_type Cross type arithmetic operation
 *
 * Macro compatible with float, fix point, signed integer and unsigned integer
 *
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define __minX(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define __maxX(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define __saturateX(X,Min,Max)          ( __minX(__maxX(X, Min), Max) )
#define __checkrangeX(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_singed_integer Signed integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define __saturate(X,Min,Max)           ( __min(__max(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_unsinged_integer Unsigned integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define __saturateu(X,Min,Max)           ( __minu(__maxu(X, Min), Max) )
/** \} */


/** \defgroup IfxLld_Cpu_Intrinsics_Gnucmin_max Minimum and Maximum of (Short) Integers
 These intrinsic functions return the minimum or maximum of a signed integer, unsigned integer or short integer.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Return maximum of two integers
 */
IFX_INLINE int __max(int a, int b)
{
    int res;
    __asm__ volatile ("max %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return maximum of two short integers
 */
IFX_INLINE int __maxs(short a, short b)
{
    int res;
    __asm__ volatile ("max.h %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}
/** Return maximum of two unsigned integers
 */
IFX_INLINE unsigned __maxu(unsigned a, unsigned b)
{
    unsigned res;
    __asm__ volatile ("max.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two integers
 */
IFX_INLINE int __min(int a, int b)
{
    int res;
    __asm__ volatile ("min %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two short integers
 */
IFX_INLINE short __mins(short a, short b)
{
    short res;
    __asm__ volatile ("min.h %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two unsigned integers
 */
IFX_INLINE unsigned __minu(unsigned a, unsigned b)
{
    unsigned res;
    __asm__ volatile ("min.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** \} */

/** \defgroup intrinsicstasking_float Floating point operation
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */
//#define __saturate(X,Min,Max)           ( __minf(__maxf(X, Min), Max) ) // dbg

#define __sqrf(X)                       ((X) * (X))
#define __sqrtf(X)                      sqrtf(X)
#define __checkrange(X,Min,Max)         (((X) >= (Min)) && ((X) <= (Max)))

#define __roundf(X)                     ((((X) - (int)(X)) > 0.5) ? (1 + (int)(X)) : ((int)(X)))
#define __absf(X)                       ( ((X) < 0.0) ? -(X) : (X) )
#define __minf(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define __maxf(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define __saturatef(X,Min,Max)          ( __minf(__maxf(X, Min), Max) )
#define __checkrangef(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))

#define __abs_stdreal(X)                ( ((X) > 0.0) ? (X) : -(X) )
#define __min_stdreal(X,Y)              ( ((X) < (Y)) ? (X) : (Y) )
#define __max_stdreal(X,Y)              ( ((X) > (Y)) ? (X) : (Y) )
#define __saturate_stdreal(X,Min,Max)    ( __min_stdreal(__max_stdreal(X, Min), Max) )

#define __neqf(X,Y)                     ( ((X) > (Y)) ||  ((X) < (Y)) )     /**< X != Y */
#define __leqf(X,Y)                     ( !((X) > (Y)) )     /**< X <= Y */
#define __geqf(X,Y)                     ( !((X) < (Y)) )     /**< X >= Y */
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucfractional Fractional Arithmetic Support
 The next table provides an overview of intrinsic functions to convert fractional values. Note that the
 TASKING VX-toolset C compiler for TriCore fully supports the fractional type so normally you should not
 need these intrinsic functions (except for __mulfractlong). For compatibility reasons the TASKING C
 compiler does support these functions.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Count the consecutive number of bits that have the same value as bit 15 of an sfract
 */
IFX_INLINE short __clssf(sfract a)
{
    short res;
    __asm__ volatile ("cls  %0,%1":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert fract to float
 */
IFX_INLINE float __fract_to_float(fract a)
{
    float res;
    __asm__ volatile ("q31tof  %0,%1,%2":"=d"(res):"d"(a), "d"(0):"memory");
    return res;
}

/** Convert float to fract
 */
IFX_INLINE fract __float_to_fract(float a)
{
    fract res;
    __asm__ volatile ("ftoq31  %0,%1,%2":"=d"(res):"d"(a), "d"(0):"memory");
    return res;
}

/** Convert laccum to fract
 */
IFX_INLINE fract __getfract(laccum a)
{
    fract res;
    __asm__ volatile ("dextr  %0,%H1,%L1,0x11":"=&d" (res):"d" (a):"memory");
    return res;
}

/** Multiply-add with rounding. Returns the rounded result of ( a + b * c )
 */
IFX_INLINE sfract __mac_r_sf(sfract a, sfract b, sfract c)
{
    sfract res;
    __asm__ volatile ("maddrs.q  %0,%1,%2U,%3U,1":"=d"(res):"d"(a), "d"(b), "d"(c):"memory");
    return res;
}

/** Multiply-add sfract. Returns ( a + b * c )
 */
IFX_INLINE sfract __mac_sf(sfract a, sfract b, sfract c)
{
    sfract res;
    __asm__ volatile ("madds.q  %0,%1,%2U,%3U,1":"=d"(res):"d"(a), "d"(b), "d"(c):"memory");
    return res;
}

/** Integer part of the multiplication of a fract and a fract
 */
IFX_INLINE long __mulfractfract(fract a, fract b)
{
    long res;
    __asm__ volatile ("mul.q %0,%1,%2,1":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Integer part of the multiplication of a fract and a long
 */
IFX_INLINE long __mulfractlong(fract a, long b)
{
    long res;
    __asm__ volatile ("mul.q %0,%1,%2,1":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Convert fract to sfract
 */
IFX_INLINE sfract __round16(fract a)
{
    sfract res;
    __asm__ volatile ("mov.u  %0,0x8000        \n\
                    adds  %0,%1              \n\
                    insert  %0,%0,0,0,0x10 "
                      :"=&d"(res):"d"(a):"memory");
    return res;
}

/** Convert signed short to sfract
 */
IFX_INLINE sfract __s16_to_sfract(short a)
{
    sfract res;
    __asm__ volatile ("sh  %0,%1,16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert sfract to signed short
 */
IFX_INLINE short __sfract_to_s16(sfract a)
{
    signed short res;
    __asm__ volatile ("sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert sfract to unsigned short
 */
IFX_INLINE unsigned short __sfract_to_u16(sfract a)
{
    unsigned short res;
    __asm__ volatile ("sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Left/right shift of an laccum
 */
IFX_INLINE laccum __shaaccum(laccum a, int b)
{
    laccum res;
    __asm__ volatile ("jge   %2,0,0f        \n\
                    sha   %H0,%H1,%2     \n\
                    rsub  %2,%2,0        \n\
                    dextr %L0,%H1,%L1,%2 \n\
                    j  1f                \n\
                    0:dextr %H0,%H1,%L1,%2 \n\
                    sha   %L0,%L1,%2     \n\
                    1:"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Left/right shift of an fract
 */
IFX_INLINE fract __shafracts(fract a, int b)
{
    fract res;
    __asm__ volatile ("shas  %0,%1,%2":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Left/right shift of an sfract
 */
IFX_INLINE sfract __shasfracts(sfract a, int b)
{
    sfract res;
    __asm__ volatile ("shas  %0,%1,%2":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Convert unsigned short to sfract
 */
IFX_INLINE sfract __u16_to_sfract(unsigned short a)
{
    sfract res;
    __asm__ volatile ("sh  %0,%1,16":"=d"(res):"d"(a):"memory");
    return res;
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucinsert Insert / Extract Bit-fields and Bits
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Extract a bit-field (bit pos to bit pos+width) from value
 */
IFX_INLINE int __extr(int a, unsigned p, unsigned w)
{
    int res;
    __asm__ volatile ("mov %%d14,%2  \n\
                     mov %%d15,%3  \n\
                     extr %0,%1,%%e14"
                      : "=d" (res) : "d" (a), "d" (p), "d" (w):"d14", "d15");
    return res;
}


/** Load a single bit.
 */
#define __getbit(address, bitoffset) ((*(address) & (1U << (bitoffset))) != 0)

/** Return trg but replace trgbit by srcbit in src.
 */
IFX_INLINE int __ins(int trg, const int trgbit, int src, const int srcbit)
{
    int res;
    __asm__ volatile ("ins.t %0,%1,%2,%3,%4":"=d"(res):"d"(trg), "i"(trgbit), "d"(src), "i"(srcbit));
    return res;
}

/** Extract bit-field (width bits starting at bit 0) from src and insert it in trg at pos.
 */
IFX_INLINE int __insert(int a, int b, int p, const int w)
{ // dbg	because bugged
    int res;
    __asm__ volatile ("mov %%d14,%3  \n\
                     mov %%d15,%4  \n\
                     insert %0,%1,%2,%%e14"
                      :"=d"(res):"d"(a), "d"(b), "d"(p), "d"(w):"d14", "d15");
    return res;
}

/** Return trg but replace trgbit by inverse of srcbit in src.
 */
IFX_INLINE int __insn(int trg, const int trgbit, int src, const int srcbit)
{
    int res;
    __asm__ volatile ("insn.t %0,%1,%2,%3,%4":"=d"(res):"d"(trg), "i"(trgbit), "d"(src), "i"(srcbit));
    return res;
}

/** \} */


/** \defgroup IfxLld_Cpu_Intrinsics_Gnucinterrupt_handling Interrupt Handling
 The next table provides an overview of the intrinsic functions to read or set interrupt handling.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Set CPU priority number [0..255] (or [0..1023] for TriCore 1.6.x) and enable interrupts immediately at function entry
 */
//#define __bisr(intlvl) __asm__ volatile ("bisr "#intlvl : : : "memory") // dbg

/** Disable interrupts. Only supported for TriCore1
 */
#define __disable() __asm__ volatile ("disable" : : : "memory")

/** Disable interrupts and return previous interrupt state (enabled or disabled). Direct supported for TriCore1.6. Emulated on TC1.3.1
 */
IFX_INLINE int __disable_and_save(void)
{
    int res;
    __asm__ volatile("disable %0":"=d"(res));
    return res;
}

/** Enable interrupts immediately at function entry
 */
#define __enable() __asm__ volatile ("enable" : : : "memory")

/** Restore interrupt state. Direct supported for TriCore1.6. Emulated on TC1.3.1
 */
IFX_INLINE void __restore(int ie)
{
    __asm__ volatile ("restore %0"::"d"(ie));
}

/** Call a system call function number
 */
#define __syscall(svcno) __tric_syscall(svcno)
#define __tric_syscall(svcno) __asm__ volatile ("syscall "STRINGIFY(svcno) : : : "memory")
/** \} */


/** \defgroup IfxLld_Cpu_Intrinsics_Gnucmiscellaneous Miscellaneous Intrinsic Functions
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/**  Write back and invalidate cache address "p". Generates CACHEA.WI [Ab].
 */
IFX_INLINE void __cacheawi(unsigned char* p)
{
    __asm__ volatile("cachea.wi [%0]0"::"a"(p));
}
/**  Write back and invalidate cache index "p". Generates CACHEI.WI [Ab].
 */
IFX_INLINE void __cacheiwi(unsigned char* p)
{
    __asm__ volatile("cachei.wi [%0]0"::"a"(p));
}

/**  Write back and invalidate cache address \"p\" and return post incremented
 * value of \"p\". Generates CACHEA.WI [Ab+].
 */
IFX_INLINE unsigned char* __cacheawi_bo_post_inc(unsigned char* p)
{
    __asm__ volatile("cachea.wi  [%0+]0"::"a"(p));
    return p;
}

/** Multiply two 32-bit numbers to an intermediate 64-bit result, and scale
 * back the result to 32 bits. To scale back the result, 32 bits are extracted
 * from the intermediate 64-bit result: bit 63-offset to bit 31-offset.
 */
IFX_INLINE int __mulsc(int a, int b, int offset)
{
    int res;
    __asm__ volatile("mul  %%e12,%1,%2      \n\
                    dextr  %0,%%d13,%%d12,%3"
                     :"=d"(res):"d"(a), "d"(b), "d"(offset):"d12", "d13");
    return res;
}

/**  Rotate operand left count times. The bits that are shifted out are inserted at the right side (bit 31 is shifted to bit 0).
 */
IFX_INLINE unsigned __rol(unsigned operand, unsigned int count)
{
    unsigned res;
    __asm__ volatile("dextr  %0,%1,%1,%2":"=d"(res):"d"(operand), "d"(count):"memory");
    return res;
}

/**  Rotate operand right count times. The bits that are shifted out are inserted at the left side (bit 0 is shifted to bit 31).
 */
IFX_INLINE unsigned __ror(unsigned operand, unsigned int count)
{
    unsigned res;
    __asm__ volatile("rsub %2,%2,0 \n\
                    dextr  %0,%1,%1,%2"
                     :"=d"(res):"d"(operand), "d"(count):"memory");
    return res;
}
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucpacked Packed Data Type Support
 The next table provides an overview of the intrinsic functions for initialization of packed data type.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/**  Absolute value of __packb
 */
IFX_INLINE __packb __absb(__packb a)
{
    __packb res;
    __asm__ volatile ("abs.b %0,%1"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Absolute value of __packhw
 */
IFX_INLINE __packhw __absh(__packhw a)
{
    __packhw res;
    __asm__ volatile ("abs.h %0,%1"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Absolute value of __packhw using saturation
 */
IFX_INLINE __packhw __abssh(__packhw a)
{
    __packb res;
    __asm__ volatile ("abss.h %0,%1"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first byte from a __packb
 */
IFX_INLINE char __extractbyte1(__packb a)
{
    char res;
    __asm__ volatile ("extr  %0,%1,0,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second byte from a __packb
 */
IFX_INLINE char __extractbyte2(__packb a)
{
    char res;
    __asm__ volatile ("extr  %0,%1,8,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract third byte from a __packb
 */
IFX_INLINE char __extractbyte3(__packb a)
{
    char res;
    __asm__ volatile ("extr  %0,%1,16,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Extract fourth byte from a __packb
 */
IFX_INLINE char __extractbyte4(__packb a)
{
    char res;
    __asm__ volatile ("extr  %0,%1,24,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first short from a __packhw
 */
IFX_INLINE short __extracthw1(__packhw a)
{
    short res;
    __asm__ volatile ("extr  %0,%1,0,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second short from a __packhw
 */
IFX_INLINE short __extracthw2(__packhw a)
{
    short res;
    __asm__ volatile ("extr  %0,%1,16,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first unsigned byte from a __packb
 */
IFX_INLINE unsigned char __extractubyte1(__upackb a)
{
    unsigned char res;
    __asm__ volatile ("extr  %0,%1,0,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second unsigned byte from a __packb
 */
IFX_INLINE unsigned char __extractubyte2(__upackb a)
{
    unsigned char res;
    __asm__ volatile ("extr  %0,%1,8,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract third unsigned byte from a __packb
 */
IFX_INLINE unsigned char __extractubyte3(__upackb a)
{
    unsigned char res;
    __asm__ volatile ("extr  %0,%1,16,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract fourth unsigned byte from a __packb
 */
IFX_INLINE unsigned char __extractubyte4(__upackb a)
{
    unsigned char res;
    __asm__ volatile ("extr  %0,%1,24,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first unsigned short from a __packhw
 */
IFX_INLINE unsigned short __extractuhw1(__upackhw a)
{
    unsigned short res;
    __asm__ volatile ("extr  %0,%1,0,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second unsigned short from a __packhw
 */
IFX_INLINE unsigned short __extractuhw2(__upackhw a)
{
    unsigned short res;
    __asm__ volatile ("extr  %0,%1,16,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Extract first byte from a __packb
 */
IFX_INLINE char __getbyte1(__packb* a)
{
    char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract second byte from a __packb
 */
IFX_INLINE char __getbyte2(__packb* a)
{
    char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,8,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract third byte from a __packb
 */
IFX_INLINE char __getbyte3(__packb* a)
{
    char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract fourth byte from a __packb
 */
IFX_INLINE char __getbyte4(__packb* a)
{
    char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,24,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract first short from a __packhw
 */
IFX_INLINE short __gethw1(__packhw* a)
{
    short res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}
/**  Extract second short from a __packhw
 */
IFX_INLINE short __gethw2(__packhw* a)
{
    short res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract first unsigned byte from a __packb
 */
IFX_INLINE unsigned char __getubyte1(__upackb* a)
{
    unsigned char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract second unsigned byte from a __packb
 */
IFX_INLINE unsigned char __getubyte2(__upackb* a)
{
    unsigned char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,8,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract third unsigned byte from a __packb
 */
IFX_INLINE unsigned char __getubyte3(__upackb* a)
{
    unsigned char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract fourth unsigned byte from a __packb
 */
IFX_INLINE unsigned char __getubyte4(__upackb* a)
{
    unsigned char res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,24,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract first unsigned short from a __packhw
 */
IFX_INLINE unsigned short __getuhw1(__upackhw* a)
{
    unsigned short res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract second unsigned short from a __packhw
 */
IFX_INLINE unsigned short __getuhw2(__upackhw* a)
{
    unsigned short res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Initialize  __packb with four integers
 */
IFX_INLINE __packb __initpackb(int a, int b, int c, int d)
{
    __packb res;
    __asm__ volatile ("insert  %3,%3,%4,8,8   \n\
                    insert  %4,%1,%2,8,8   \n\
                    insert  %0,%4,%3,16,16 "
                      :"=d"(res):"d"(a), "d"(b), "d"(c), "d"(d):"memory");
    return res;
}

/** Initialize  __packb with a long integer
 */
IFX_INLINE __packb __initpackbl(long a)
{
    return (__packb) a;
}

/** Initialize  __packhw with two integers
 */
IFX_INLINE __packhw __initpackhw(short a, short b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Initialize  __packhw with a long integer
 */
IFX_INLINE __packhw __initpackhwl(long a)
{
    return a;
}

/** Initialize  __packb with four unsigned integers
 */
IFX_INLINE __upackb    __initupackb( unsigned a, unsigned b, unsigned c, unsigned d)
{
    __upackb res;
    __asm__ volatile ("insert  %3,%3,%4,8,8   \n\
                    insert  %1,%1,%2,8,8   \n\
                    insert  %0,%1,%3,16,16"
                      :"=d"(res):"d"(a), "d"(b), "d"(c), "d"(d):"memory");
    return res;
}

/**  Initialize  __packhw with two unsigned integers
 */
IFX_INLINE __upackhw    __initupackhw( unsigned short a, unsigned short b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}


/** Insert char into first byte of a __packb
 */
IFX_INLINE __packb __insertbyte1(__packb a, char b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,0,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert char into second byte of a __packb
 */
IFX_INLINE __packb __insertbyte2(__packb a, char b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,8,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert char into third byte of a __packb
 */
IFX_INLINE __packb __insertbyte3(__packb a, char b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,16,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert char into fourth byte of a __packb
 */
IFX_INLINE __packb __insertbyte4(__packb a, char b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,24,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert char into first unsigned byte of a __packb
 */
IFX_INLINE __upackb    __insertubyte1( __upackb a, unsigned char b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,0,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert char into second unsigned byte of a __packb
 */
IFX_INLINE __upackb    __insertubyte2( __upackb a, unsigned char b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,8,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert char into third unsigned byte of a __packb
 */
IFX_INLINE __upackb     __insertubyte3( __upackb a, unsigned char b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,16,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert char into fourth unsigned byte of a __packb
 */
IFX_INLINE __upackb     __insertubyte4( __upackb a, unsigned char b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,24,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert short into first halfword of a __packhw
 */
IFX_INLINE __packhw __inserthw1(__packhw a, short b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,0,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert short into second halfword of a __packhw
 */
IFX_INLINE __packhw __inserthw2(__packhw a, short b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert unsigned short into first halfword of a __upackhw
 */
IFX_INLINE __upackhw    __insertuhw1( __upackhw a, unsigned short b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,0,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert unsigned short into second halfword of a __upackhw
 */
IFX_INLINE __upackhw    __insertuhw2( __upackhw a, unsigned short b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two  __packb values
 */
IFX_INLINE __packb __minb(__packb a, __packb b)
{
    __packb res;
    __asm__ volatile ("min.b %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two __upackb  values
 */
IFX_INLINE __upackb     __minbu( __upackb  a, __upackb  b)
{
    __upackb res;
    __asm__ volatile ("min.bu %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two  __packhw values
 */
IFX_INLINE __packhw __minh(__packhw a, __packhw b)
{
    __packhw res;
    __asm__ volatile ("min.h %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two __upackhw values
 */
IFX_INLINE __upackhw    __minhu( __upackhw a, __upackhw b)
{
    __upackhw res;
    __asm__ volatile ("min.hu %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert char into first byte of a __packb
 */
IFX_INLINE void __setbyte1(__packb* a, char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert char into second byte of a __packb
 */
IFX_INLINE void __setbyte2(__packb* a, char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,8,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert char into third byte of a __packb
 */
IFX_INLINE void __setbyte3(__packb* a, char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert char into fourth byte of a __packb
 */
IFX_INLINE void __setbyte4(__packb* a, char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,24,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert short into first halfword of a __packhw
 */
IFX_INLINE void __sethw1(__packhw* a, short b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert short into second halfword of a __packhw
 */
IFX_INLINE void __sethw2(__packhw* a, short b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert unsigned char into first byte of a __upackb
 */
IFX_INLINE void __setubyte1(__upackb* a, unsigned char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert unsigned char into second byte of a __upackb
 */
IFX_INLINE void __setubyte2(__upackb* a, unsigned char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,8,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert unsigned char into third byte of a __upackb
 */
IFX_INLINE void __setubyte3(__upackb* a, unsigned char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert unsigned char into fourth byte of a __upackb
 */
IFX_INLINE void __setubyte4(__upackb* a, unsigned char b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,24,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert unsigned short into first halfword of a __upackhw
 */
IFX_INLINE void __setuhw1(__upackhw* a, unsigned short b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}


/**  Insert unsigned short into second halfword of a __upackhw
 */
IFX_INLINE void __setuhw2(__upackhw* a, unsigned short b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucregister Register Handling
 The next table provides an overview of the intrinsic functions that you can use to access control registers.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/**  Return absolute value
 */
#define __abs(a) __builtin_abs(a)

/** Return absolue difference of two integers
 */
IFX_INLINE int __absdif(int a, int b)
{
    int res;
    __asm__ volatile ("absdif %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/**  Return absolute value with saturation
 */
IFX_INLINE int __abss(int a)
{
    int res;
    __asm__ volatile ("abss %0, %1": "=d" (res) : "d" (a));
    return res;
}

/**  Count leading ones in int
 */
IFX_INLINE int __clo(int a)
{
    int res;
    __asm__ volatile ("clo %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Count number of redundant sign bits (all consecutive bits with the same value as bit 31
 */
IFX_INLINE int __cls(int a)
{
    int res;
    __asm__ volatile ("cls %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Count leading zeros in int
 */
#define  __clz(a) __builtin_clz(a)

/**  Return absolute double precision floating-point value
 */
IFX_INLINE double __fabs(double d)
{
    double res;
    __asm__ volatile ("insert  %0,%1,0,31,1": "=d" (res) : "d" (d):"memory");
    return res;
}

/**  Return absolute floating-point value
 */
IFX_INLINE float __fabsf(float f)
{
    float res;
    __asm__ volatile ("insert  %0,%1,0,31,1": "=d" (res) : "d" (f):"memory");
    return res;
}

/**  Move contents of the addressed core SFR into a data register
 */
//#define __mfcr(regaddr)  \	 // dbg
//({ int res; __asm__ volatile ("mfcr %0,"#regaddr : "=d" (res) : : "memory"); res; }) // dbg

/**  Move contents of a data register (second int) to the addressed core SFR (first int)
 */
//#define __mtcr(regaddr,val) __asm__ volatile ("mtcr %0,%1\n\tisync"::"i"(regaddr),"d"(val):"memory") // dbg

/**  Return parity
 */
IFX_INLINE int __parity(int a)
{
    double res;
    __asm__ volatile ("parity  %0,%1": "=d" (res) : "d" (a):"memory");
    return res;
}

/**  Return saturated byte
 */
IFX_INLINE char __satb(int a)
{
    char res;
    __asm__ volatile ("sat.b %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated unsigned byte
 */
IFX_INLINE unsigned char __satbu(int a)
{
    unsigned char res;
    __asm__ volatile ("sat.bu %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated halfword
 */
IFX_INLINE short __sath(int a)
{
    char res;
    __asm__ volatile ("sat.h %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated unsignedhalfword
 */
IFX_INLINE unsigned short __sathu(int a)
{
    char res;
    __asm__ volatile ("sat.hu %0,%1":"=d"(res):"d"(a));
    return res;
}

/** \} */


/** \defgroup IfxLld_Cpu_Intrinsics_Gnucsaturation Saturation Arithmetic Support
 These intrinsics support saturation arithmetic
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** add signed with saturation
 */
IFX_INLINE int __adds(int a, int b)
{
    int res;
    __asm__ volatile ("adds %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** add unsigned with saturation
 */
IFX_INLINE unsigned __addsu(unsigned a, unsigned b)
{
    unsigned res;
    __asm__ volatile ("adds.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** substract signed with saturation
 */
IFX_INLINE int __subs(int a, int b)
{
    int res;
    __asm__ volatile ("subs %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** substract unsigned with saturation
 */
IFX_INLINE unsigned __subsu(unsigned a, unsigned b)
{
    unsigned res;
    __asm__ volatile ("subs.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucsingle_assembly Insert Single Assembly Instruction
 The next table provides an overview of the intrinsic functions that you can use to insert a single assembly
 instruction.You can also use inline assembly but these intrinsics provide a shorthand for frequently used
 assembly instructions.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Insert DEBUG instruction
 */
IFX_INLINE void __debug(void)
{
    __asm__ volatile ("debug" : : : "memory");
}

/** Insert DSYNC instruction
 */
IFX_INLINE void __dsync(void)
{
    __asm__ volatile ("dsync" : : : "memory");
}

/** Insert ISYNC instruction
 */
IFX_INLINE void __isync(void)
{
    __asm__ volatile ("isync" : : : "memory");
}

/** Insert LDMST instruction. Note that all operands must be word-aligned.
 */
IFX_INLINE void __ldmst(volatile unsigned* address, unsigned mask, unsigned value)
{
    __asm__ volatile("mov %H2,%1 \n\
                  ldmst [%0]0,%A2"
                     ::"a"(address), "d"(mask), "d"((long long)value));
}

/** Insert NOP instruction
 */
IFX_INLINE void __nop(void)
{
    __asm__ volatile ("nop" : : : "memory");
}

/** Insert a loop over cnt NOP instruction
 */
IFX_INLINE void __nops(void* cnt)
{
    __asm__ volatile ("0: nop \n\
        loop %0,0b"
                      ::"a"(((char*)cnt)-1));
}

/** Insert RSLCX instruction
 */
IFX_INLINE void __rslcx(void)
{
    __asm__ volatile ("rslcx" : : : "memory");
}

/** Insert SVLCX instruction
 */
IFX_INLINE void __svlcx(void)
{
    __asm__ volatile ("svlcx" : : : "memory");
}

/** Insert SWAP instruction. Note that all operands must be word-aligned.
 */
IFX_INLINE unsigned __swap(unsigned* place, unsigned value)
{
    unsigned res;
    __asm__ volatile("swap.w [%1]0,%2":"=d"(res):"a"(place), "0"(value));
    return res;
}

/** Insert n NOP instruction
 */
#define NOP(n)   __asm(".rept " #n "\n\tnop\n\t.endr\n")

/** \} */

/* FIXME use inline instead of #define */
#define __setareg(areg,val) \
  	{ uint32 reg_val= (uint32)val; \
		asm volatile (" mov.a\t %%"#areg",%0"::"d"(reg_val)); }

#define __setreg(areg,val) \
{ \
   asm volatile ("mov.aa %%"#areg", %0" :: "a" (val)); \
}
//dbg

/**__mtcr (CPU_CCTRL, 0);
*/

IFX_INLINE void __stopPerfCounters(void)
{
    __asm__ volatile("mov %%d0,0\n\
                  mtcr 0xFC00,%%d0\n\
                  isync\n"
            : : :"d0"); /* FIXME check that the parameter d0 is understood by the compiler as a register used by the inline */
}

/******************************************************************************/
/* *INDENT-ON* */
#endif /* INTRINSICSGNUC_H */
