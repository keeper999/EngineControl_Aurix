/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TrbActSys                                               */
/* !Description     : TrbActSys component.                                    */
/*                                                                            */
/* !Module          : TrbActSys                                               */
/* !Description     : Init functions for TrbActSys eeprom                     */
/*                                                                            */
/* !File            : TrbActSys_nvm_valeo.c                                               */
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

#ifndef _TRBACTSYS_NVM_VALEO__C_
#define _TRBACTSYS_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "TrbActSys_nvm_valeo.h"

void TrbActSys_NVRAM_int32_const__nvmini (void)
{
   TrbActSys_sNV_Z1_CONST_32BIT = TrbActSys_sNV_Z1_CONST_32BIT_r;
}

#endif/* _TRBACTSYS_NVM_VALEO__C_ */
