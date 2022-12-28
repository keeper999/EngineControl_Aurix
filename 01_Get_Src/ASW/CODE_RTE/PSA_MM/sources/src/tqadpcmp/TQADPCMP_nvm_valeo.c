/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQADPCMP                                               */
/* !Description     : TQADPCMP component.                                    */
/*                                                                            */
/* !Module          : TQADPCMP                                               */
/* !Description     : Init functions for TQADPCMP eeprom                     */
/*                                                                            */
/* !File            : TQADPCMP_nvm_valeo.c                                               */
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

#ifndef _TQADPCMP_NVM_VALEO__C_
#define _TQADPCMP_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "TQADPCMP_nvm_valeo.h"

void TQADPCMP_NVRAM_int16_const__nvmini (void)
{
   TqAdpCmp_sNV_Z1_CST_16BIT = TqAdpCmp_sNV_Z1_CST_16BIT_r;
}

void TQADPCMP_NVRAM_int32_const__nvmini (void)
{
   TqAdpCmp_sNV_Z1_CST_32BIT = TqAdpCmp_sNV_Z1_CST_32BIT_r;
}

void TQADPCMP_NVRAM_int8_const__nvmini (void)
{
   TqAdpCmp_sNV_Z1_CST_8BIT = TqAdpCmp_sNV_Z1_CST_8BIT_r;
}

#endif/* _TQADPCMP_NVM_VALEO__C_ */
