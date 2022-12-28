/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : EOMGSL                                               */
/* !Description     : EOMGSL component.                                    */
/*                                                                            */
/* !Module          : EOMGSL                                               */
/* !Description     : Init functions for EOMGSL eeprom                     */
/*                                                                            */
/* !File            : EOMGSL_nvm_valeo.c                                               */
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

#ifndef _EOMGSL_NVM_VALEO__C_
#define _EOMGSL_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "EOMGSL_nvm_valeo.h"

void EOMGSL_NVRAM_int32_const__nvmini (void)
{
   EOMGsl_sNV_Z1_CST_32BIT = EOMGsl_sNV_Z1_CST_32BIT_r;
}

#endif/* _EOMGSL_NVM_VALEO__C_ */
