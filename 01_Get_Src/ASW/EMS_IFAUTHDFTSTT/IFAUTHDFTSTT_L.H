/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : IFAUTHDFTSTT                                             */
/*                                                                            */
/* !Module         : IFAUTHDFTSTT                                             */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : IFAUTHDFTSTT_L.H                                         */
/*                                                                            */
/* !Scope          : Private                                                  */
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
/* $Revision::   1.2      $$Author::   MBENFRAD       $$Date::   Sep 23 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef IFAUTHDFTSTT_L_H
#define IFAUTHDFTSTT_L_H

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

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  IFAUTHDFTSTT_u8Inhib;
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
extern boolean SftyMgt_bEnaNotSTTCf;
extern boolean SftyMgt_bEnaSTTCf;
extern boolean SftyMgt_bInhSTTCordNotSTTCf;
extern boolean SftyMgt_bInhSTTCordSTTCf;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void IFAUTHDFTSTT_vidInitOutput(void);
void IFAUTHDFTSTT_vidIrfAutrstDftSTT(void);
void IFAUTHDFTSTT_vidSansSTTCfg(void);
void IFAUTHDFTSTT_vidSTTConfig(void);
void IFAUTHDFTSTT_vidSTTPrstCfg(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* IFAUTHDFTSTT_L_H */

/*-------------------------------- end of file -------------------------------*/
