/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCKEFCFIL                                               */
/*                                                                            */
/* !Module         : TQCKEFCFIL                                               */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : TQCKEFCFIL_L.H                                           */
/*                                                                            */
/* !Scope          : Private                                                  */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKEFCFIL/TQCKEFCFIL_$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   05 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQCKEFCFIL_L_H
#define TQCKEFCFIL_L_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_IDXNENGTHDDRIVFIL_COLS         (2)
#define SFTYMGT_IDXNENGTIDRIVFIL_COLS          (2)
#define SFTYMGT_IDXNOGEARDRIVFIL_COLS          (2)
#define SFTYMGT_IDXTQFILDRIVFIL_COLS           (2)

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
extern const uint8  TQCKEFCFIL_u8Inhib;
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
extern boolean SftyMgt_bAccPThdTqCll_MP;
extern boolean SftyMgt_bDeceAcv_MP;
extern boolean SftyMgt_bDeceAcvIniEdge;
extern boolean SftyMgt_bDgoDrivFilDeceAcv;
extern boolean SftyMgt_bDgoDrivFilDeceIpCnt;
extern boolean SftyMgt_bDgoDrivFilTq;
extern boolean SftyMgt_bDiPha10;
extern boolean SftyMgt_bDiPha11;
extern boolean SftyMgt_bDrivFilDeceAcvInvld;
extern boolean SftyMgt_bDrivFilDeceIp;
extern boolean SftyMgt_bDrivFilDeceIpCntInvld;
extern boolean SftyMgt_bDrivFilTqInvld;
extern boolean SftyMgt_bEnaDrivFilDeceIpCntRst;
extern boolean SftyMgt_bEnaDrivFilDeceIpCntRun;
extern boolean TQCKEFCFIL_bDeceIpCntRunPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 SftyMgt_idxDeceAcv;
extern uint8 SftyMgt_noGearDeceIni;
extern uint8 SftyMgt_noGearDeceIniTmp;
extern uint8 SftyMgt_tiDlyDrivFilDecePha10;
extern uint8 SftyMgt_tiDlyDrivFilDecePha11;
extern uint8 SftyMgt_tiDlyPha10;
extern uint8 SftyMgt_tiDlyPha11;
extern uint8 SftyMgt_tiDlyPha9;
extern uint8 TQCKEFCFIL_u8DlyOnDgoInvdCounter;
extern uint8 TQCKEFCFIL_u8tiDlyOnDgoCounter;
extern uint8 TQCKEFCFIL_u8tiDlyOnDgoIpCounter;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_tqCkDeceIni;
extern sint16 SftyMgt_tqCkDrivNotFil;
extern sint16 SftyMgt_tqCkEfcFilTol;
extern sint16 SftyMgt_tqDifIniPha9;
extern sint16 SftyMgt_tqIntlPha10;
extern sint16 SftyMgt_tqIntlPha11;
extern sint16 SftyMgt_tqSlop;
extern sint16 SftyMgt_tqSlopPha10;
extern sint16 SftyMgt_tqSlopPha11;
extern sint16 SftyMgt_tqSlopPha9;
extern sint16 SftyMgt_tqThdPha10;
extern sint16 SftyMgt_tqThdPha8;
extern sint16 SftyMgt_tqThdPha9;
extern uint16 SftyMgt_idxNEngThdDrivFil[SFTYMGT_IDXNENGTHDDRIVFIL_COLS];
extern uint16 SftyMgt_idxNEngTiDrivFil[SFTYMGT_IDXNENGTIDRIVFIL_COLS];
extern uint16 SftyMgt_idxNoGearDrivFil[SFTYMGT_IDXNOGEARDRIVFIL_COLS];
extern uint16 SftyMgt_idxTqFilDrivFil[SFTYMGT_IDXTQFILDRIVFIL_COLS];
extern uint16 SftyMgt_nEngDeceIni;
extern uint16 SftyMgt_tiDlyDrivFilDeceTotTol;
extern uint16 SftyMgt_tiDrivFilDeceIpCnt;
extern uint16 SftyMgt_tiDrivFilDeceIpCntRst;
extern uint16 SftyMgt_tiDrivFilDeceIpCntRun;
extern uint16 TQCKEFCFIL_u16ClcParaIdxNEngThd;
extern uint16 TQCKEFCFIL_u16ClcParaIdxNEngTi;
extern uint16 TQCKEFCFIL_u16ClcParaIdxNoGear;
extern uint16 TQCKEFCFIL_u16ClcParaIdxTqFil;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void TQCKEFCFIL_vidCalcCntDecIPOutRng(void);
void TQCKEFCFIL_vidCalcDecAcvOutOfRng(void);
void TQCKEFCFIL_vidCalcDiffCplePPhase(void);
void TQCKEFCFIL_vidCalcDrivFilOutRnge(void);
void TQCKEFCFIL_vidCalcDureeDesPhases(void);
void TQCKEFCFIL_vidCalcEtCoordPentes(void);
void TQCKEFCFIL_vidCalcPfDecelInit(void);
void TQCKEFCFIL_vidCalcPfDecelParam(void);
void TQCKEFCFIL_vidCalcPfTqFiltre(void);
void TQCKEFCFIL_vidCalcPfTqNonfiltere(void);
void TQCKEFCFIL_vidCalcPrevfDecelInit(void);
void TQCKEFCFIL_vidCalcSeuilCpleDecIp(void);
void TQCKEFCFIL_vidCalculEstimation(void);
void TQCKEFCFIL_vidCalculPenteDeceIp(void);
void TQCKEFCFIL_vidCalculTempoDeceIp(void);
void TQCKEFCFIL_vidcalIdxFacPreLookup(void);
void TQCKEFCFIL_vidChoiPteDecIPCalCpt(void);
void TQCKEFCFIL_vidComptDrivFilDeceIP(void);
void TQCKEFCFIL_vidCptInctDrvFilDecIP(void);
void TQCKEFCFIL_vidDbncDfDrvFilDcIPCn(void);
void TQCKEFCFIL_vidDbnceDeftTqDrivFil(void);
void TQCKEFCFIL_vidDebounceDeftDecAcv(void);
void TQCKEFCFIL_vidIFTHENComptDeceAcv(void);
void TQCKEFCFIL_vidIncCptDrivFilDecIP(void);
void TQCKEFCFIL_vidInitOutput(void);
void TQCKEFCFIL_vidPriseCmptRapportBV(void);
void TQCKEFCFIL_vidSyntheseDefTqCkEfc(void);
void TQCKEFCFIL_vidSyntPtDrivFilDecIP(void);
void TQCKEFCFIL_vidTreatSdlNiv1VNiv2(void);
void TQCKEFCFIL_vidValidation(void);
void TQCKEFCFIL_vidValidtqCkEfcFil(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQCKEFCFIL_L_H */

/*-------------------------------- end of file -------------------------------*/
