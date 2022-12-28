/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : Version_mapping                                         */
/* !Description     : Version_mapping.                                        */
/*                                                                            */
/* !Module          : VERSION_MAPPING                                         */
/* !Description     : definition de la version du mapping                     */
/*                                                                            */
/* !File            : VERSION_MAPPING.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/VERSION_MAPPING/version_map$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   fsanchez2                              $$Date::   04 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Version_mapping.h"

#define VERSION_START_SEC_KRN_VER_MAPPING
#include "MemMap.h"

const uint16 Version_mapping = 0x000AU;

#define VERSION_STOP_SEC_KRN_VER_MAPPING
#include "MemMap.h"

/* end of file*/