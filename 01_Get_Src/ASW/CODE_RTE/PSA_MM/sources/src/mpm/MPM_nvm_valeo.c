/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MPM                                               */
/* !Description     : MPM component.                                    */
/*                                                                            */
/* !Module          : MPM                                               */
/* !Description     : Init functions for MPM eeprom                     */
/*                                                                            */
/* !File            : MPM_nvm_valeo.c                                               */
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

#ifndef _MPM_NVM_VALEO__C_
#define _MPM_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "MPM_nvm_valeo.h"

void MPM_NVRAM_int16_const__nvmini (void)
{
   MPM_sNV_Z1_CST_16BIT = MPM_sNV_Z1_CST_16BIT_r;
}

void MPM_NVRAM_int32_const__nvmini (void)
{
   MPM_sNV_Z1_CST_32BIT = MPM_sNV_Z1_CST_32BIT_r;
}

void MPM_NVRAM_int32_const_1__nvmini (void)
{
   MPM_sNV_Z1_CST_32BIT_1 = MPM_sNV_Z1_CST_32BIT_1_r;
}

void MPM_NVRAM_int32_const_2__nvmini (void)
{
   MPM_sNV_Z1_CST_32BIT_2 = MPM_sNV_Z1_CST_32BIT_2_r;
}

#endif/* _MPM_NVM_VALEO__C_ */
