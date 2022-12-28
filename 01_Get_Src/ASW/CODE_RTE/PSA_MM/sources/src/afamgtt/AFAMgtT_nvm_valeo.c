/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AFAMgtT                                               */
/* !Description     : AFAMgtT component.                                    */
/*                                                                            */
/* !Module          : AFAMgtT                                               */
/* !Description     : Init functions for AFAMgtT eeprom                     */
/*                                                                            */
/* !File            : AFAMgtT_nvm_valeo.c                                               */
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

#ifndef _AFAMGTT_NVM_VALEO__C_
#define _AFAMGTT_NVM_VALEO__C_

#include "tl_defines.h"
#include "tl_basetypes.h"
#include "AFAMgtT_nvm_valeo.h"

void AFAMgtT_NVRAM_int8_const__nvmini (void)
{
   AFAMgtT_sNV_Z1_CONST_8BIT = AFAMgtT_sNV_Z1_CONST_8BIT_r;
}

#endif/* _AFAMGTT_NVM_VALEO__C_ */
