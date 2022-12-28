/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCKEFCFIL                                               */
/*                                                                            */
/* !Module         : TQCKEFCFIL                                               */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQCKEFCFIL.C75                                           */
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

#include "STD_TYPES.h"
#include "TQCKEFCFIL.h"
#include "TQCKEFCFIL_l.h"

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
const boolean  SftyMgt_bInhDgoDeceAcv_C = 0;
const boolean  SftyMgt_bInhDgoFilIpCnt_C = 0;
const boolean  SftyMgt_bInhDgoTqDrivFil_C = 0;
const boolean  SftyMgt_bNoGearDeceSel_C = 0;
const boolean  SftyMgt_bThdPha8Sel_C = 0;
const boolean  SftyMgt_bTqCkDrivFilLimSel_C = 0;
const boolean  SftyMgt_bTypAcvCll_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_facTiPha9Max_M[SFTYMGT_FACTIPHA9MAX_M_LNS][SFTYMGT_FACTIPHA9MAX_M_COLS] = {0};
const uint8  SftyMgt_noGearDrivFil_A[SFTYMGT_NOGEARDRIVFIL_A_COLS] = {0};
const uint8  SftyMgt_tiDlyOnDgoFilInvld_C = 0;
const uint8  SftyMgt_tiDlyOnDgoFilIpCnt_C = 0;
const uint8  SftyMgt_tiDlyOnDgoTqDrivFil_C = 0;
const uint8  TQCKEFCFIL_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_tqCkDrivFilMax_C = 0;
const sint16  SftyMgt_tqCkDrivFilMin_C = 0;
const sint16  SftyMgt_tqCkDrivNotFilMax_C = 0;
const sint16  SftyMgt_tqCkDrivNotFilMin_C = 0;
const sint16  SftyMgt_tqErrDrivFilThd_C = 0;
const sint16  SftyMgt_tqFilDifMin_C = 0;
const sint16  SftyMgt_tqOfsDrivFiNotDeceIp_C = 0;
const sint16  SftyMgt_tqOfsTqCkEfcFilThd_C = 0;
const uint16  SftyMgt_facPha10Max_T[SFTYMGT_FACPHA10MAX_T_COLS] = {0};
const uint16  SftyMgt_facPha8Max_T[SFTYMGT_FACPHA8MAX_T_COLS] = {0};
const uint16  SftyMgt_facPha9Max_T[SFTYMGT_FACPHA9MAX_T_COLS] = {0};
const uint16  SftyMgt_facTiPha10Max_M[SFTYMGT_FACTIPHA10MAX_M_LNS][SFTYMGT_FACTIPHA10MAX_M_COLS] = {0};
const uint16  SftyMgt_facTiPha11Max_M[SFTYMGT_FACTIPHA11MAX_M_LNS][SFTYMGT_FACTIPHA11MAX_M_COLS] = {0};
const uint16  SftyMgt_nEngThdDrivFil_A[SFTYMGT_NENGTHDDRIVFIL_A_COLS] = {0};
const uint16  SftyMgt_nEngTiDrivFil_A[SFTYMGT_NENGTIDRIVFIL_A_COLS] = {0};
const uint16  SftyMgt_rAccPThdTqCll_C = 0;
const uint16  SftyMgt_tiDlyPha10Max_M[SFTYMGT_TIDLYPHA10MAX_M_LNS][SFTYMGT_TIDLYPHA10MAX_M_COLS] = {0};
const uint16  SftyMgt_tiDlyPha11Max_M[SFTYMGT_TIDLYPHA11MAX_M_LNS][SFTYMGT_TIDLYPHA11MAX_M_COLS] = {0};
const uint16  SftyMgt_tiDlyPha9Max_M[SFTYMGT_TIDLYPHA9MAX_M_LNS][SFTYMGT_TIDLYPHA9MAX_M_COLS] = {0};
const uint16  SftyMgt_tiOfsDrivFilDeceIpThd_C = 0;
const uint16  SftyMgt_tqFilDrivFil_A[SFTYMGT_TQFILDRIVFIL_A_COLS] = {0};
const uint16  SftyMgt_tqThdPha10Max_M[SFTYMGT_TQTHDPHA10MAX_M_LNS][SFTYMGT_TQTHDPHA10MAX_M_COLS] = {0};
const uint16  SftyMgt_tqThdPha8BasMax_M[SFTYMGT_TQTHDPHA8BASMAX_M_LNS][SFTYMGT_TQTHDPHA8BASMAX_M_COLS] = {0};
const uint16  SftyMgt_tqThdPha8TypMax_M[SFTYMGT_TQTHDPHA8TYPMAX_M_LNS][SFTYMGT_TQTHDPHA8TYPMAX_M_COLS] = {0};
const uint16  SftyMgt_tqThdPha9BasMax_M[SFTYMGT_TQTHDPHA9BASMAX_M_LNS][SFTYMGT_TQTHDPHA9BASMAX_M_COLS] = {0};
const uint16  SftyMgt_tqThdPha9TypMax_M[SFTYMGT_TQTHDPHA9TYPMAX_M_LNS][SFTYMGT_TQTHDPHA9TYPMAX_M_COLS] = {0};
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
boolean SftyMgt_bAccPThdTqCll_MP;
boolean SftyMgt_bDeceAcv_MP;
boolean SftyMgt_bDeceAcvIniEdge;
boolean SftyMgt_bDgoDrivFilDeceAcv;
boolean SftyMgt_bDgoDrivFilDeceIpCnt;
boolean SftyMgt_bDgoDrivFilTq;
boolean SftyMgt_bDgoTqCkEfcFil;
boolean SftyMgt_bDiPha10;
boolean SftyMgt_bDiPha11;
boolean SftyMgt_bDrivFilDeceAcvInvld;
boolean SftyMgt_bDrivFilDeceIp;
boolean SftyMgt_bDrivFilDeceIpCntInvld;
boolean SftyMgt_bDrivFilTqInvld;
boolean SftyMgt_bEnaDrivFilDeceIpCntRst;
boolean SftyMgt_bEnaDrivFilDeceIpCntRun;
boolean TQCKEFCFIL_bDeceIpCntRunPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 SftyMgt_idxDeceAcv;
uint8 SftyMgt_noGearDeceIni;
uint8 SftyMgt_noGearDeceIniTmp;
uint8 SftyMgt_tiDlyDrivFilDecePha10;
uint8 SftyMgt_tiDlyDrivFilDecePha11;
uint8 SftyMgt_tiDlyPha10;
uint8 SftyMgt_tiDlyPha11;
uint8 SftyMgt_tiDlyPha9;
uint8 TQCKEFCFIL_u8DlyOnDgoInvdCounter;
uint8 TQCKEFCFIL_u8tiDlyOnDgoCounter;
uint8 TQCKEFCFIL_u8tiDlyOnDgoIpCounter;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_tqCkDeceIni;
sint16 SftyMgt_tqCkDrivNotFil;
sint16 SftyMgt_tqCkEfcFilTol;
sint16 SftyMgt_tqDifIniPha9;
sint16 SftyMgt_tqIntlPha10;
sint16 SftyMgt_tqIntlPha11;
sint16 SftyMgt_tqSlop;
sint16 SftyMgt_tqSlopPha10;
sint16 SftyMgt_tqSlopPha11;
sint16 SftyMgt_tqSlopPha9;
sint16 SftyMgt_tqThdPha10;
sint16 SftyMgt_tqThdPha8;
sint16 SftyMgt_tqThdPha9;
uint16 SftyMgt_idxNEngThdDrivFil[SFTYMGT_IDXNENGTHDDRIVFIL_COLS];
uint16 SftyMgt_idxNEngTiDrivFil[SFTYMGT_IDXNENGTIDRIVFIL_COLS];
uint16 SftyMgt_idxNoGearDrivFil[SFTYMGT_IDXNOGEARDRIVFIL_COLS];
uint16 SftyMgt_idxTqFilDrivFil[SFTYMGT_IDXTQFILDRIVFIL_COLS];
uint16 SftyMgt_nEngDeceIni;
uint16 SftyMgt_tiDlyDrivFilDeceTotTol;
uint16 SftyMgt_tiDrivFilDeceIpCnt;
uint16 SftyMgt_tiDrivFilDeceIpCntRst;
uint16 SftyMgt_tiDrivFilDeceIpCntRun;
uint16 TQCKEFCFIL_u16ClcParaIdxNEngThd;
uint16 TQCKEFCFIL_u16ClcParaIdxNEngTi;
uint16 TQCKEFCFIL_u16ClcParaIdxNoGear;
uint16 TQCKEFCFIL_u16ClcParaIdxTqFil;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

