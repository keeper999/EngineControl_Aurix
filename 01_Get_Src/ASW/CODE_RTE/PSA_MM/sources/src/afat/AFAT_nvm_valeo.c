/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AFAT                                               */
/* !Description     : AFAT component.                                    */
/*                                                                            */
/* !Module          : AFAT                                               */
/* !Description     : Init functions for AFAT eeprom                     */
/*                                                                            */
/* !File            : AFAT_nvm_valeo.c                                               */
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

#ifndef _AFAT_NVM_VALEO__C_
#define _AFAT_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "AFAT_nvm_valeo.h"

void AFAT_NVRAM_int16_calib__nvmini (void)
{
   AFAT_sNV_Z1_CALIB_16BIT = AFAT_sNV_Z1_CALIB_16BIT_r;
}

void AFAT_NVRAM_int32_calib__nvmini (void)
{
   AFAT_sNV_Z1_CALIB_32BIT = AFAT_sNV_Z1_CALIB_32BIT_r;
}

void AFAT_NVRAM_int8_calib__nvmini (void)
{
   AFAT_sNV_Z1_CALIB_8BIT = AFAT_sNV_Z1_CALIB_8BIT_r;
}

void AFAT_NVRAM_boolean_calib__nvmini (void)
{
   AFAT_sNV_Z1_CALIB_BOOLEAN = AFAT_sNV_Z1_CALIB_BOOLEAN_r;
}

void AFAT_NVRAM_int16_const__nvmini (void)
{
   AFAT_sNV_Z1_CONST_16BIT = AFAT_sNV_Z1_CONST_16BIT_r;
}

void AFAT_NVRAM_int8_const__nvmini (void)
{
   AFAT_sNV_Z1_CONST_8BIT = AFAT_sNV_Z1_CONST_8BIT_r;
}

void AFAT_NVRAM_boolean_const__nvmini (void)
{
   AFAT_sNV_Z1_CONST_BOOLEAN = AFAT_sNV_Z1_CONST_BOOLEAN_r;
}

#endif/* _AFAT_NVM_VALEO__C_ */
