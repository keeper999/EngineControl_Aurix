/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STOPSTRTEM                                               */
/* !Description     : STOPSTRTEM component.                                    */
/*                                                                            */
/* !Module          : STOPSTRTEM                                               */
/* !Description     : Init functions for STOPSTRTEM eeprom                     */
/*                                                                            */
/* !File            : STOPSTRTEM_nvm_valeo.c                                               */
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

#ifndef _STOPSTRTEM_NVM_VALEO__C_
#define _STOPSTRTEM_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "STOPSTRTEM_nvm_valeo.h"

void STOPSTRTEM_NVRAM_int16_const_3__nvmini (void)
{
   StopStrtEm_sNV_Z1_CST_16BIT_3 = StopStrtEm_sNV_Z1_CST_16BIT_3_r;
}

void STOPSTRTEM_NVRAM_int32_const_1__nvmini (void)
{
   StopStrtEm_sNV_Z1_CST_32BIT_1 = StopStrtEm_sNV_Z1_CST_32BIT_1_r;
}

void STOPSTRTEM_NVRAM_int32_const_2__nvmini (void)
{
   StopStrtEm_sNV_Z1_CST_32BIT_2 = StopStrtEm_sNV_Z1_CST_32BIT_2_r;
}

#endif/* _STOPSTRTEM_NVM_VALEO__C_ */
