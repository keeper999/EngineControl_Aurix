/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COEMSTT                                               */
/* !Description     : COEMSTT component.                                    */
/*                                                                            */
/* !Module          : COEMSTT                                               */
/* !Description     : Init functions for COEMSTT eeprom                     */
/*                                                                            */
/* !File            : COEMSTT_nvm_valeo.c                                               */
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

#ifndef _COEMSTT_NVM_VALEO__C_
#define _COEMSTT_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "COEMSTT_nvm_valeo.h"

void COEMSTT_NVRAM_int16_const_1__nvmini (void)
{
   CoEmSTT_sNV_Z1_CST_16BIT_1 = CoEmSTT_sNV_Z1_CST_16BIT_1_r;
}

void COEMSTT_NVRAM_int32_const_1__nvmini (void)
{
   CoEmSTT_sNV_Z1_CST_32BIT_1 = CoEmSTT_sNV_Z1_CST_32BIT_1_r;
}

void COEMSTT_NVRAM_int8_const_1__nvmini (void)
{
   CoEmSTT_sNV_Z1_CST_8BIT_1 = CoEmSTT_sNV_Z1_CST_8BIT_1_r;
}

#endif/* _COEMSTT_NVM_VALEO__C_ */
