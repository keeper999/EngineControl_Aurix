/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : UsThrMT                                               */
/* !Description     : UsThrMT component.                                    */
/*                                                                            */
/* !Module          : UsThrMT                                               */
/* !Description     : Init functions for UsThrMT eeprom                     */
/*                                                                            */
/* !File            : UsThrMT_nvm_valeo.c                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/SWC_PSA/AirSys/XXX/XXX_nvm.c_v     $*/
/* $Revision::   X.X                                                        $*/
/* $Author::   XXXXXXXXX                               $$Date::   25 Aug 2010 $*/
/******************************************************************************/

#ifndef _USTHRMT_NVM_VALEO__C_
#define _USTHRMT_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "UsThrMT_nvm_valeo.h"

void UsThrMT_NVRAM_int16_calib__nvmini (void)
{
   UsThrMT_sNV_Z1_CALIB_16BIT = UsThrMT_sNV_Z1_CALIB_16BIT_r;
}

#endif/* _USTHRMT_NVM_VALEO__C_ */
