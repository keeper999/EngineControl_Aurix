/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TrbActGsl                                               */
/* !Description     : TrbActGsl component.                                    */
/*                                                                            */
/* !Module          : TrbActGsl                                               */
/* !Description     : Init functions for TrbActGsl eeprom                     */
/*                                                                            */
/* !File            : TrbActGsl_nvm_valeo.c                                               */
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

#ifndef _TRBACTGSL_NVM_VALEO__C_
#define _TRBACTGSL_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "TrbActGsl_nvm_valeo.h"

void TrbActGsl_NVRAM_int16_const__nvmini (void)
{
   TrbActGsl_sNV_Z1_CONST_16BIT = TrbActGsl_sNV_Z1_CONST_16BIT_r;
}

#endif/* _TRBACTGSL_NVM_VALEO__C_ */
