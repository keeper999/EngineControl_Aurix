/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : IFAUTHDFTSTT                                             */
/*                                                                            */
/* !Module         : IFAUTHDFTSTT                                             */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : IFAUTHDFTSTT.H                                           */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEMS                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFAUTHDFTSTT/IFAUTHDFT$*/
/* $Revision::   1.1   $$Author::   MBENFR$$Date::   Sep 23 2011 14:28:10    $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef IFAUTHDFTSTT_H
#define IFAUTHDFTSTT_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bInhSTTCord;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void IFAUTHDFTSTT_vidEntryInit(void);
void SftyMgt_SdlMid_IfSftyMgtSTT(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* IFAUTHDFTSTT_H */

/*-------------------------------- end of file -------------------------------*/
