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
#ifndef VERSION_MAPPING_H
#define VERSION_MAPPING_H

#include "STD_TYPES.h"

#define VERSION_START_SEC_KRN_VER_MAPPING
#include "MemMap.h"

extern const uint16 Version_mapping;

#define VERSION_STOP_SEC_KRN_VER_MAPPING
#include "MemMap.h"

#endif /*VERSION_MAPPING_H*/
/* end of file*/