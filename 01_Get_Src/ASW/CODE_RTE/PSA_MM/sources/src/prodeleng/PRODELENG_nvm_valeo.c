/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PRODELENG                                               */
/* !Description     : PRODELENG component.                                    */
/*                                                                            */
/* !Module          : PRODELENG                                               */
/* !Description     : Init functions for PRODELENG eeprom                     */
/*                                                                            */
/* !File            : PRODELENG_nvm_valeo.c                                               */
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

#ifndef _PRODELENG_NVM_VALEO__C_
#define _PRODELENG_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "PRODELENG_nvm_valeo.h"

void PRODELENG_NVRAM_int32_const_1__nvmini (void)
{
   ProdElEng_sNV_Z1_CST_32BIT_1 = ProdElEng_sNV_Z1_CST_32BIT_1_r;
}

#endif/* _PRODELENG_NVM_VALEO__C_ */
