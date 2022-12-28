/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ExMGslT2                                               */
/* !Description     : ExMGslT2 component.                                    */
/*                                                                            */
/* !Module          : ExMGslT2                                               */
/* !Description     : Init functions for ExMGslT2 eeprom                     */
/*                                                                            */
/* !File            : ExMGslT2_nvm_valeo.c                                               */
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

#ifndef _EXMGSLT2_NVM_VALEO__C_
#define _EXMGSLT2_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "ExMGslT2_nvm_valeo.h"

void ExMGslT2_NVRAM_int16_const__nvmini (void)
{
   ExMGslT2_sNV_Z1_CONST_16BIT = ExMGslT2_sNV_Z1_CONST_16BIT_r;
}

#endif/* _EXMGSLT2_NVM_VALEO__C_ */
