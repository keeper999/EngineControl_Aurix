/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TPM                                               */
/* !Description     : TPM component.                                    */
/*                                                                            */
/* !Module          : TPM                                               */
/* !Description     : Init functions for TPM eeprom                     */
/*                                                                            */
/* !File            : TPM_nvm_valeo.c                                               */
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

#ifndef _TPM_NVM_VALEO__C_
#define _TPM_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "TPM_nvm_valeo.h"

void TPM_NVRAM_int16_const__nvmini (void)
{
   TPM_sNV_Z1_CST_16BIT = TPM_sNV_Z1_CST_16BIT_r;
}

#endif/* _TPM_NVM_VALEO__C_ */
