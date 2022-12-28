/******************************************************************************/
/*                                                                            */
/* !Layer          : MATH                                                     */
/*                                                                            */
/* !Component      : MATH                                                     */
/*                                                                            */
/* !Module         : MATH                                                     */
/* !Description    : Source of MATH component                                 */
/*                                                                            */
/* !File           : ACTEMS_FabsF.c                                          */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/ACTEMS_Fabs$*/
/* $Revision::   1.0          $$Author::   ADELVARE    $$Date::   17 Jun 2011$*/
/******************************************************************************/

#include "ACTEMS_FabsF.h"

float32 ACTEMS_FabsF(float32 _f)
{
   float32 flocal;
   if (_f < 0.0F) {
      flocal = - _f;
   } else {
      flocal = _f;
   }
   return flocal;
}
