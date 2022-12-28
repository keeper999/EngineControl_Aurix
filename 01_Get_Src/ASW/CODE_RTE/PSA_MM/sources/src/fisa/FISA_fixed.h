/******************************************************************************/
/*                                                                            */
/* !Layer :             APPLI                                                 */
/*                                                                            */
/* !Component :         FISA                                                  */
/* !Description :                                                             */
/*                                                                            */
/* !Module :            FISA_Fixed                                            */
/* !Description :       Calcul en fixed point                                 */
/*                                                                            */
/* !File :              FISA_Fixed.h                                          */
/*                                                                            */
/* !Scope :             Public                                                */
/*                                                                            */
/* !Target :            All                                                   */
/*                                                                            */
/* !Vendor :            Valeo                                                 */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_fixed.h_v          $*/
/* $Revision::   1.9       $$Author::   flavergn   $$Date::   21 Jul 2010 15:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
#ifndef _FISA_FIXED_H_
#define _FISA_FIXED_H_

#include "Rte_FISA.h"

#define SIGNE_MOINS 1
#define SIGNE_PLUS  0

#define MINSCHAR  ((SInt8)(-127-1))
#define MAXSCHAR  ((SInt8)127)
#define MINUCHAR  ((UInt8)0)
#define MAXUCHAR  ((UInt8)255)
#define MINUSHORT ((UInt16)0)
#define MAXUSHORT ((UInt16)65535)
#define MINSSHORT ((SInt16)(-32767-1))
#define MAXSSHORT ((SInt16)32767)
#define MINULONG  ((UInt32)0UL)
#define MAXULONG  ((UInt32)4294967295UL)
#define MINSLONG  ((SInt32)(-2147483647L - 1))
#define MAXSLONG  ((SInt32)2147483647L)

typedef struct
{
  VAR(Boolean,FISA_VAR)  sign;
  VAR(UInt16,FISA_VAR)   mantisse;
  VAR(SInt16,FISA_VAR)   exposant;
} ts_fixed;

#define MUL_FIX(f1,f2,f3) multiplier_fixed(f1.sign, f1.mantisse, f1.exposant, \
                                            f2.sign, f2.mantisse, f2.exposant, f3)
#define DIV_FIX(f1,f2,f3) diviser_fixed(f1.sign, f1.mantisse, f1.exposant, \
                                            f2.sign, f2.mantisse, f2.exposant, f3)
#define ADD_FIX(f1,f2,f3) additionner_fixed(f1.sign, f1.mantisse, f1.exposant, \
                                            f2.sign, f2.mantisse, f2.exposant, f3)
#define SUB_FIX(f1,f2,f3) soustraire_fixed(f1.sign, f1.mantisse, f1.exposant, \
                                           f2.sign, f2.mantisse, f2.exposant, f3)
#define MIN_FIX(f1,f2,f3) minimum_fixed(f1.sign, f1.mantisse, f1.exposant, \
                                           f2.sign, f2.mantisse, f2.exposant, f3)
#define MAX_FIX(f1,f2,f3) maximum_fixed(f1.sign, f1.mantisse, f1.exposant, \
                                           f2.sign, f2.mantisse, f2.exposant, f3)


#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

FUNC(void,FISA_CODE) U16_to_fixed(Boolean sign, UInt16 mantisse, SInt16 exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) fixed);

FUNC(void,FISA_CODE) S16_to_fixed(SInt16 mantisse, SInt16 exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) fixed);

FUNC(void,FISA_CODE) S32_to_fixed(SInt32 mantisse,
                  SInt16 exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) fixed);

FUNC(SInt16,FISA_CODE) fixed_to_S16(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant);

FUNC(UInt32,FISA_CODE) fixed_to_U32(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant);

FUNC(SInt32,FISA_CODE) fixed_to_S32(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant);


/* Les fonctions suivantes ne doivent pas etre appelees directement, passer par les macros */

FUNC(void,FISA_CODE) multiplier_fixed(  Boolean f1_sign,
                    UInt16  f1_mantisse,
                    SInt16  f1_exposant,
                    Boolean f2_sign,
                    UInt16  f2_mantisse,
                    SInt16  f2_exposant,
                    P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3);

FUNC(void,FISA_CODE) diviser_fixed(  Boolean f1_sign,
                  UInt16  f1_mantisse,
                  SInt16  f1_exposant,
                  Boolean f2_sign,
                  UInt16  f2_mantisse,
                  SInt16  f2_exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3);

FUNC(void,FISA_CODE) minimum_fixed(  Boolean f1_sign,
                  UInt16  f1_mantisse_p,
                  SInt16  f1_exposant,
                  Boolean f2_sign,
                  UInt16  f2_mantisse_p,
                  SInt16  f2_exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3);

FUNC(void,FISA_CODE) maximum_fixed(  Boolean f1_sign,
                  UInt16  f1_mantisse_p,
                  SInt16  f1_exposant,
                  Boolean f2_sign,
                  UInt16  f2_mantisse_p,
                  SInt16  f2_exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3);

FUNC(void,FISA_CODE) additionner_fixed(  Boolean f1_sign,
                    UInt16  f1_mantisse_p,
                    SInt16  f1_exposant,
                    Boolean f2_sign,
                    UInt16  f2_mantisse_p,
                    SInt16  f2_exposant,
                    P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3);

FUNC(void,FISA_CODE) soustraire_fixed(  Boolean f1_sign,
                    UInt16  f1_mantisse_p,
                    SInt16  f1_exposant,
                    Boolean f2_sign,
                    UInt16  f2_mantisse_p,
                    SInt16  f2_exposant,
                    P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3);

#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

#endif

