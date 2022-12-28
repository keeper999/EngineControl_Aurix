/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCKEFCFIL                                               */
/*                                                                            */
/* !Module         : TQCKEFCFIL                                               */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQCKEFCFIL.H                                             */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKEFCFIL/TQCKEFCFIL.$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   05 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQCKEFCFIL_H
#define TQCKEFCFIL_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_FACPHA10MAX_T_COLS             (12)
#define SFTYMGT_FACPHA8MAX_T_COLS              (12)
#define SFTYMGT_FACPHA9MAX_T_COLS              (12)
#define SFTYMGT_FACTIPHA10MAX_M_LNS           (12)
#define SFTYMGT_FACTIPHA10MAX_M_COLS           (7)
#define SFTYMGT_FACTIPHA11MAX_M_LNS           (12)
#define SFTYMGT_FACTIPHA11MAX_M_COLS           (7)
#define SFTYMGT_FACTIPHA9MAX_M_LNS            (12)
#define SFTYMGT_FACTIPHA9MAX_M_COLS            (7)
#define SFTYMGT_NENGTHDDRIVFIL_A_COLS          (12)
#define SFTYMGT_NENGTIDRIVFIL_A_COLS           (8)
#define SFTYMGT_NOGEARDRIVFIL_A_COLS           (7)
#define SFTYMGT_TIDLYPHA10MAX_M_LNS           (8)
#define SFTYMGT_TIDLYPHA10MAX_M_COLS           (7)
#define SFTYMGT_TIDLYPHA11MAX_M_LNS           (8)
#define SFTYMGT_TIDLYPHA11MAX_M_COLS           (7)
#define SFTYMGT_TIDLYPHA9MAX_M_LNS            (8)
#define SFTYMGT_TIDLYPHA9MAX_M_COLS            (7)
#define SftyMgt_tiSdlTqCkEfcFil_SC        40          /* 40 */
#define SFTYMGT_TQFILDRIVFIL_A_COLS            (12)
#define SFTYMGT_TQTHDPHA10MAX_M_LNS           (12)
#define SFTYMGT_TQTHDPHA10MAX_M_COLS           (7)
#define SFTYMGT_TQTHDPHA8BASMAX_M_LNS         (12)
#define SFTYMGT_TQTHDPHA8BASMAX_M_COLS         (7)
#define SFTYMGT_TQTHDPHA8TYPMAX_M_LNS         (12)
#define SFTYMGT_TQTHDPHA8TYPMAX_M_COLS         (7)
#define SFTYMGT_TQTHDPHA9BASMAX_M_LNS         (12)
#define SFTYMGT_TQTHDPHA9BASMAX_M_COLS         (7)
#define SFTYMGT_TQTHDPHA9TYPMAX_M_LNS         (12)
#define SFTYMGT_TQTHDPHA9TYPMAX_M_COLS         (7)

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
extern const boolean  SftyMgt_bInhDgoDeceAcv_C;
extern const boolean  SftyMgt_bInhDgoFilIpCnt_C;
extern const boolean  SftyMgt_bInhDgoTqDrivFil_C;
extern const boolean  SftyMgt_bNoGearDeceSel_C;
extern const boolean  SftyMgt_bThdPha8Sel_C;
extern const boolean  SftyMgt_bTqCkDrivFilLimSel_C;
extern const boolean  SftyMgt_bTypAcvCll_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_facTiPha9Max_M[SFTYMGT_FACTIPHA9MAX_M_LNS][SFTYMGT_FACTIPHA9MAX_M_COLS];
extern const uint8  SftyMgt_noGearDrivFil_A[SFTYMGT_NOGEARDRIVFIL_A_COLS];
extern const uint8  SftyMgt_tiDlyOnDgoFilInvld_C;
extern const uint8  SftyMgt_tiDlyOnDgoFilIpCnt_C;
extern const uint8  SftyMgt_tiDlyOnDgoTqDrivFil_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_tqCkDrivFilMax_C;
extern const sint16  SftyMgt_tqCkDrivFilMin_C;
extern const sint16  SftyMgt_tqCkDrivNotFilMax_C;
extern const sint16  SftyMgt_tqCkDrivNotFilMin_C;
extern const sint16  SftyMgt_tqErrDrivFilThd_C;
extern const sint16  SftyMgt_tqFilDifMin_C;
extern const sint16  SftyMgt_tqOfsDrivFiNotDeceIp_C;
extern const sint16  SftyMgt_tqOfsTqCkEfcFilThd_C;
extern const uint16  SftyMgt_facPha10Max_T[SFTYMGT_FACPHA10MAX_T_COLS];
extern const uint16  SftyMgt_facPha8Max_T[SFTYMGT_FACPHA8MAX_T_COLS];
extern const uint16  SftyMgt_facPha9Max_T[SFTYMGT_FACPHA9MAX_T_COLS];
extern const uint16  SftyMgt_facTiPha10Max_M[SFTYMGT_FACTIPHA10MAX_M_LNS][SFTYMGT_FACTIPHA10MAX_M_COLS];
extern const uint16  SftyMgt_facTiPha11Max_M[SFTYMGT_FACTIPHA11MAX_M_LNS][SFTYMGT_FACTIPHA11MAX_M_COLS];
extern const uint16  SftyMgt_nEngThdDrivFil_A[SFTYMGT_NENGTHDDRIVFIL_A_COLS];
extern const uint16  SftyMgt_nEngTiDrivFil_A[SFTYMGT_NENGTIDRIVFIL_A_COLS];
extern const uint16  SftyMgt_rAccPThdTqCll_C;
extern const uint16  SftyMgt_tiDlyPha10Max_M[SFTYMGT_TIDLYPHA10MAX_M_LNS][SFTYMGT_TIDLYPHA10MAX_M_COLS];
extern const uint16  SftyMgt_tiDlyPha11Max_M[SFTYMGT_TIDLYPHA11MAX_M_LNS][SFTYMGT_TIDLYPHA11MAX_M_COLS];
extern const uint16  SftyMgt_tiDlyPha9Max_M[SFTYMGT_TIDLYPHA9MAX_M_LNS][SFTYMGT_TIDLYPHA9MAX_M_COLS];
extern const uint16  SftyMgt_tiOfsDrivFilDeceIpThd_C;
extern const uint16  SftyMgt_tqFilDrivFil_A[SFTYMGT_TQFILDRIVFIL_A_COLS];
extern const uint16  SftyMgt_tqThdPha10Max_M[SFTYMGT_TQTHDPHA10MAX_M_LNS][SFTYMGT_TQTHDPHA10MAX_M_COLS];
extern const uint16  SftyMgt_tqThdPha8BasMax_M[SFTYMGT_TQTHDPHA8BASMAX_M_LNS][SFTYMGT_TQTHDPHA8BASMAX_M_COLS];
extern const uint16  SftyMgt_tqThdPha8TypMax_M[SFTYMGT_TQTHDPHA8TYPMAX_M_LNS][SFTYMGT_TQTHDPHA8TYPMAX_M_COLS];
extern const uint16  SftyMgt_tqThdPha9BasMax_M[SFTYMGT_TQTHDPHA9BASMAX_M_LNS][SFTYMGT_TQTHDPHA9BASMAX_M_COLS];
extern const uint16  SftyMgt_tqThdPha9TypMax_M[SFTYMGT_TQTHDPHA9TYPMAX_M_LNS][SFTYMGT_TQTHDPHA9TYPMAX_M_COLS];
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
extern boolean SftyMgt_bDgoTqCkEfcFil;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_tqCkEfcFil(void);
void TQCKEFCFIL_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQCKEFCFIL_H */

/*-------------------------------- end of file -------------------------------*/
