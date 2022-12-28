/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PRODELEM                                               */
/* !Description     : PRODELEM component.                                    */
/*                                                                            */
/* !Module          : PRODELEM                                               */
/* !Description     : Init functions for PRODELEM eeprom                     */
/*                                                                            */
/* !File            : PRODELEM_nvm_valeo.c                                               */
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

#ifndef _PRODELEM_NVM_VALEO__C_
#define _PRODELEM_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "PRODELEM_nvm_valeo.h"

void PRODELEM_NVRAM_int16_const_1__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_16BIT_1 = ProdElEm_sNV_Z1_CST_16BIT_1_r;
}

void PRODELEM_NVRAM_int16_const_2__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_16BIT_2 = ProdElEm_sNV_Z1_CST_16BIT_2_r;
}

void PRODELEM_NVRAM_int32_const_1__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_32BIT_1 = ProdElEm_sNV_Z1_CST_32BIT_1_r;
}

void PRODELEM_NVRAM_int32_const_2__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_32BIT_2 = ProdElEm_sNV_Z1_CST_32BIT_2_r;
}

void PRODELEM_NVRAM_int32_const_3__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_32BIT_3 = ProdElEm_sNV_Z1_CST_32BIT_3_r;
}

void PRODELEM_NVRAM_int8_const_1__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_8BIT_1 = ProdElEm_sNV_Z1_CST_8BIT_1_r;
}

void PRODELEM_NVRAM_int8_const_2__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_8BIT_2 = ProdElEm_sNV_Z1_CST_8BIT_2_r;
}

void PRODELEM_NVRAM_boolean_const_1__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_BOOLEAN_1 = ProdElEm_sNV_Z1_CST_BOOLEAN_1_r;
}

void PRODELEM_NVRAM_boolean_const_2__nvmini (void)
{
   ProdElEm_sNV_Z1_CST_BOOLEAN_2 = ProdElEm_sNV_Z1_CST_BOOLEAN_2_r;
}

#endif/* _PRODELEM_NVM_VALEO__C_ */
