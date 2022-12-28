/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ThrSpT                                               */
/* !Description     : ThrSpT component.                                    */
/*                                                                            */
/* !Module          : ThrSpT                                               */
/* !Description     : Init functions for ThrSpT eeprom                     */
/*                                                                            */
/* !File            : ThrSpT_nvm_valeo.c                                               */
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

#ifndef _THRSPT_NVM_VALEO__C_
#define _THRSPT_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "ThrSpT_nvm_valeo.h"

void ThrSpT_NVRAM_int32_const__nvmini (void)
{
   ThrSpT_sNV_Z1_CONST_32BIT = ThrSpT_sNV_Z1_CONST_32BIT_r;
}

#endif/* _THRSPT_NVM_VALEO__C_ */
