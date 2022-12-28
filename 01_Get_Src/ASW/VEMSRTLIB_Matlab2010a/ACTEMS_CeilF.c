/******************************************************************************/
/*                                                                            */
/* !Layer          : MATH                                                     */
/*                                                                            */
/* !Component      : MATH                                                     */
/*                                                                            */
/* !Module         : MATH                                                     */
/* !Description    : Source of MATH component                                 */
/*                                                                            */
/* !File           : ACTEMS_CeilF.c                                           */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/ACTEMS_Ceil$*/
/* $Revision::   1.0          $$Author::   adelvare    $$Date::   03 Oct 2012$*/
/******************************************************************************/

#include "ACTEMS_CeilF.h"

#include "ACTEMS_Single.h"

float32 ACTEMS_CeilF(float32 _f)
{
   float32  flocalOut;
   uint32   u32local;

   u32local = SINGLE_GET_U32(_f);

   if (SINGLE_ZERO_NEG == u32local) {
      flocalOut = _f;
   } else if (SINGLE_ZERO_POS == u32local) {
      flocalOut = _f;
   } else {
      uint8  u8localExpBrut;

      u8localExpBrut = SINGLE_GET_EXP(u32local);
      if (0xFF == u8localExpBrut) {
         flocalOut = _f;
      } else if (u8localExpBrut < 127) {
         if (SINGLE_IS_NEG(u32local)) {
            flocalOut = 0.0F;
         } else {
            flocalOut = 1.0F;
         }
      } else if (u8localExpBrut > 150) {
         flocalOut = _f;
      } else {
         uint8   u8localExp150;
         uint32  u32frac;
         uint32  u32localTemp;

         u8localExp150 = (uint8)(150 - u8localExpBrut);
         u32frac = SINGLE_GET_FRACTION(u32local);
         if (SINGLE_IS_POS(u32local)) {
            if (0 != (u32frac & ((1 << u8localExp150) - 1))) {
               u32localTemp = SINGLE_SET_POS(((((u32frac >> u8localExp150) + 1) << u8localExp150)), u8localExpBrut);
            } else {
               u32localTemp = SINGLE_SET_POS((((u32frac >> u8localExp150) << u8localExp150)), u8localExpBrut);
            }
         } else {
            u32localTemp = SINGLE_SET_NEG((((u32frac >> u8localExp150) << u8localExp150)), u8localExpBrut);
         }
         flocalOut = SINGLE_SET_U32(u32localTemp);
      }
   }
   return flocalOut;
}
