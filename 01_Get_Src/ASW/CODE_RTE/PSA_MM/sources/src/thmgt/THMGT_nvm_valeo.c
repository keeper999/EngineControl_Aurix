/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THMGT                                               */
/* !Description     : THMGT component.                                    */
/*                                                                            */
/* !Module          : THMGT                                               */
/* !Description     : Init functions for THMGT eeprom                     */
/*                                                                            */
/* !File            : THMGT_nvm_valeo.c                                               */
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

#ifndef _THMGT_NVM_VALEO__C_
#define _THMGT_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "THMGT_nvm_valeo.h"

void THMGT_NVRAM_int8_const__nvmini (void)
{
   ThMgt_sNV_Z1_CST_8BIT = ThMgt_sNV_Z1_CST_8BIT_r;
}

void THMGT_NVRAM_boolean_const__nvmini (void)
{
   ThMgt_sNV_Z1_CST_BOOLEAN = ThMgt_sNV_Z1_CST_BOOLEAN_r;
}

#endif/* _THMGT_NVM_VALEO__C_ */
