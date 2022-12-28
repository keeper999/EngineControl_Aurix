/******************************************************************************/
/*                                                                            */
/* !Layer          : MATH                                                     */
/*                                                                            */
/* !Component      : MATH                                                     */
/*                                                                            */
/* !Module         : MATH                                                     */
/* !Description    : Source of MATH component                                 */
/*                                                                            */
/* !File           : ACTEMS_FloorF.c                                          */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/ACTEMS_Floo$*/
/* $Revision::   1.0          $$Author::   ADELVARE    $$Date::   17 Jun 2011$*/
/******************************************************************************/

#include "ACTEMS_FloorF.h"

float32 ACTEMS_FloorF(float32 _f)
{
   float32  flocalOut;
   uint32 u32local;
   uint32 u32localTemp;
   uint8  u8localExpBrut;
   uint8  u8localExp150;

   u32local = (*(uint32 *)(&_f));

   if (0x80000000 == u32local) {
      flocalOut = _f;
   } else if (0x00000000 == u32local) {
      flocalOut = _f;
   } else {
      u8localExpBrut = (uint8)(u32local >> 23);
      if (0xFF == u8localExpBrut) {
         flocalOut = _f;
      } else if (u8localExpBrut < 127) {
         if (1 == (u32local >> 31)) {
            flocalOut = -1.0F;
         } else {
            flocalOut = 0.0F;
         }
      } else if (u8localExpBrut > 150) {
         flocalOut = _f;
      } else {
         u8localExp150 = (uint8)(150 - u8localExpBrut);
         if (1 == (u32local >> 31)) {
            if (0 != (u32local & ((1 << u8localExp150) - 1))) {
               u32localTemp = ((u32local >> u8localExp150) + 1) << u8localExp150;
               flocalOut = *(float32 *)(&u32localTemp);
            } else {
               u32localTemp = (u32local >> u8localExp150) << u8localExp150;
               flocalOut = *(float32 *)(&u32localTemp);
            }
         } else {
            u32localTemp = (u32local >> u8localExp150) << u8localExp150;
            flocalOut = *(float32 *)(&u32localTemp);
         }
      }
   }
   return flocalOut;
}
