/******************************************************************************/
/*                                                                            */
/* !Layer          : MATH                                                     */
/*                                                                            */
/* !Component      : MATH                                                     */
/*                                                                            */
/* !Module         : MATH                                                     */
/* !Description    : Source of MATH component                                 */
/*                                                                            */
/* !File           : ACTEMS_LdexpF.c                                          */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/ACTEMS_Ldex$*/
/* $Revision::   1.0          $$Author::   ADELVARE    $$Date::   17 Jun 2011$*/
/******************************************************************************/

#include "ACTEMS_LdexpF.h"

float32 ACTEMS_LdexpF(float32 _f, sint32 _i)
{
    uint32 u32local = (*(uint32 *)(&_f));

    if (_f == 0.0F) {
        _f = 0.0F;
    } else if (0xFF != (uint8)(u32local >> 23)) {
       if (_i > 0)
       {
           if (_i > 278)
           {
              if (1 == (u32local >> 31)) {
                  u32local = 0xFF800000;
                  _f = *(float32 *)(&u32local);
              } else {
                  u32local = 0x7F800000;
                  _f = *(float32 *)(&u32local);
              }
           } else {
              while (_i > 30)
              {
                  _f *= (float32) (1L << 30);
                  _i -= 30;
              }
              _f *= (float32) (1L << _i);
           }
       }
       else
       {
           if (_i < -280)
           {
               _f = 0.0F;
           } else {
              while (_i < -30)
              {
                  _f /= (float32)(1L << 30);
                  _i += 30;
              }
              _f /= (float32)(1L << -_i);
           }
       }
    }
    return _f;
}

