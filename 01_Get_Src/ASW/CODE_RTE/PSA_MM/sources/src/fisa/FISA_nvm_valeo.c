/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FISA                                               */
/* !Description     : FISA component.                                    */
/*                                                                            */
/* !Module          : FISA                                               */
/* !Description     : Init functions for FISA eeprom                     */
/*                                                                            */
/* !File            : FISA_nvm_valeo.c                                               */
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

#ifndef _FISA_NVM_VALEO__C_
#define _FISA_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "FISA_nvm_valeo.h"

void FISA_NVRAM_int8_const_1__nvmini (void)
{
   FISA_sNV_Z1_CST_8BIT_1 = FISA_sNV_Z1_CST_8BIT_1_r;
}

#endif/* _FISA_NVM_VALEO__C_ */
