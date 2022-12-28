/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQVSCTLCHK                                               */
/*                                                                            */
/* !Module         : TQVSCTLCHK                                               */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQVSCTLCHK.H                                             */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQVSCTLCHK/TQVSCTLCHK.$*/
/* $Revision::   1.2      $$Author::   MBENFRAD       $$Date::   Nov 10 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQVSCTLCHK_H
#define TQVSCTLCHK_H

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

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
extern const boolean  SftyMgt_bInhAcvNotEfcTqPTMin_C;
extern const boolean  SftyMgt_bInhDftBrkPedPress_C;
extern const boolean  SftyMgt_bInhDftTqVSCtl_C;
extern const boolean  SftyMgt_bTypTqVSCtl_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_stAcvEfcTqPTMinVSCtl_C;
extern const uint8  SftyMgt_stAcvNotEfcTqPTMin_C;
extern const uint8  SftyMgt_tiDlyOnDftTqVSCtl_C;
extern const uint8  SftyMgt_tiDlyOnDftVSCtl_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_tqCkEfcThdVSCtl_C;
extern const sint16  SftyMgt_tqOfsDftVSCtl_C;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bDeac0TqVSCtl;
extern boolean SftyMgt_bDgoVSCtl;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_TqVSCtlChk(void);
void TQVSCTLCHK_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQVSCTLCHK_H */

/*-------------------------------- end of file -------------------------------*/
