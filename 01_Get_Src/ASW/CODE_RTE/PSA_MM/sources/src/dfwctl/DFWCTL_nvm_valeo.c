/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DFWCTL                                               */
/* !Description     : DFWCTL component.                                    */
/*                                                                            */
/* !Module          : DFWCTL                                               */
/* !Description     : Init functions for DFWCTL eeprom                     */
/*                                                                            */
/* !File            : DFWCTL_nvm_valeo.c                                               */
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

#ifndef _DFWCTL_NVM_VALEO__C_
#define _DFWCTL_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "DFWCTL_nvm_valeo.h"

void DFWCTL_NVRAM_int16_const__nvmini (void)
{
   DfwCtl_sNV_Z1_CST_16BIT = DfwCtl_sNV_Z1_CST_16BIT_r;
}

#endif/* _DFWCTL_NVM_VALEO__C_ */
