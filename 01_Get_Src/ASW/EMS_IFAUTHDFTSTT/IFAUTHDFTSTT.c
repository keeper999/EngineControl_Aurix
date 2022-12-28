/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : IFAUTHDFTSTT                                             */
/*                                                                            */
/* !Module         : IFAUTHDFTSTT                                             */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : IFAUTHDFTSTT.C75                                         */
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
/* $Revision::   1.3  $$Author::   MBENFRA$$Date::   Sep 23 2011 14:28:08    $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IFAUTHDFTSTT.h"
#include "IFAUTHDFTSTT_l.h"

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

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  IFAUTHDFTSTT_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
boolean SftyMgt_bEnaNotSTTCf;
boolean SftyMgt_bEnaSTTCf;
boolean SftyMgt_bInhSTTCord;
boolean SftyMgt_bInhSTTCordNotSTTCf;
boolean SftyMgt_bInhSTTCordSTTCf;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

