/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : NTARIDLCHK                                               */
/*                                                                            */
/* !Module         : NTARIDLCHK                                               */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : NTARIDLCHK.H                                             */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/NTARIDLCHK/NTARIDLCHK.$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   05 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef NTARIDLCHK_H
#define NTARIDLCHK_H

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
extern const boolean  SftyMgt_bInhIniIdlDyn_C;
extern const boolean  SftyMgt_bInhIniNTarIdlStrt_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_stGBxAT_C;
extern const uint8  SftyMgt_tiDlyNTarIdlDynDft_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_nGrdNTarIdlDyn_C;
extern const uint16  SftyMgt_facIncMaxTarIdl_C;
extern const uint16  SftyMgt_nMinEngSetTqSysAcv_C;
extern const uint16  SftyMgt_nOfsErrTarIdl_C;
extern const uint16  SftyMgt_nOfsNTarIdlDyn_C;
extern const uint16  SftyMgt_nTarIdlDynThd_C;
extern const uint16  SftyMgt_nTarIdlIni_C;
extern const uint16  SftyMgt_nTarIdlMax_C;
extern const uint16  SftyMgt_tiDlyNTarIdlDftOn_C;
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
extern boolean SftyMgt_bDgoNIdl;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void NTARIDLCHK_vidEntryInit(void);
void SftyMgt_SdlMid_nTarIdlChk(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* NTARIDLCHK_H */

/*-------------------------------- end of file -------------------------------*/
