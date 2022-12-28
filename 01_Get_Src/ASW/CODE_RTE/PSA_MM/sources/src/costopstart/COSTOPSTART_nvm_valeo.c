/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COSTOPSTART                                               */
/* !Description     : COSTOPSTART component.                                    */
/*                                                                            */
/* !Module          : COSTOPSTART                                               */
/* !Description     : Init functions for COSTOPSTART eeprom                     */
/*                                                                            */
/* !File            : COSTOPSTART_nvm_valeo.c                                               */
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

#ifndef _COSTOPSTART_NVM_VALEO__C_
#define _COSTOPSTART_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "COSTOPSTART_nvm_valeo.h"

void COSTOPSTART_NVRAM_int16_const_1__nvmini (void)
{
   CoStopStart_sNV_Z1_CST_16BIT_1 = CoStopStart_sNV_Z1_CST_16BIT_1_r;
}

void COSTOPSTART_NVRAM_int8_const_1__nvmini (void)
{
   CoStopStart_sNV_Z1_CST_8BIT_1 = CoStopStart_sNV_Z1_CST_8BIT_1_r;
}

void COSTOPSTART_NVRAM_int8_const_2__nvmini (void)
{
   CoStopStart_sNV_Z1_CST_8BIT_2 = CoStopStart_sNV_Z1_CST_8BIT_2_r;
}

void COSTOPSTART_NVRAM_int8_const_3__nvmini (void)
{
   CoStopStart_sNV_Z1_CST_8BIT_3 = CoStopStart_sNV_Z1_CST_8BIT_3_r;
}

void COSTOPSTART_NVRAM_boolean_const_1__nvmini (void)
{
   CoStopStart_sNV_Z1_CST_BOOLEAN_1 = CoStopStart_sNV_Z1_CST_BOOLEAN_1_r;
}

void COSTOPSTART_NVRAM_boolean_const_2__nvmini (void)
{
   CoStopStart_sNV_Z1_CST_BOOLEAN_2 = CoStopStart_sNV_Z1_CST_BOOLEAN_2_r;
}

#endif/* _COSTOPSTART_NVM_VALEO__C_ */
