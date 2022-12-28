/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SFTYMNGR                                                 */
/*                                                                            */
/* !Module         : SFTYMNGR                                                 */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : SFTYMNGR.H                                               */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR.H_v $*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   26 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef SFTYMNGR_H
#define SFTYMNGR_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_STDFTLADD_T_COLS               (10)

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
extern const boolean  SftyMgt_bEnaDftKeyOff_C;
extern const boolean  SftyMgt_bInhDftAutChk_nEng_C;
extern const boolean  SftyMgt_bInhDftEMEdge_C;
extern const boolean  SftyMgt_bInhDftIpAutChkIni_C;
extern const boolean  SftyMgt_bInhDftIpECU_nEng_C;
extern const boolean  SftyMgt_bInhDftIpEM_C;
extern const boolean  SftyMgt_bInhDftIpSTT_C;
extern const boolean  SftyMgt_bInhDftIpVSCtl_C;
extern const boolean  SftyMgt_bInhDftNomTest_C;
extern const boolean  SftyMgt_bInhDftSatMem_C;
extern const boolean  SftyMgt_bInhDftSTTEdge_C;
extern const boolean  SftyMgt_bInhDftVSCtlEdge_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_noSdlOnRstHw_C;
extern const uint8  SftyMgt_noSdlOnRstSw_C;
extern const uint8  SftyMgt_stDftLadd_T[SFTYMGT_STDFTLADD_T_COLS];
extern const uint8  SftyMgt_stEngStop_C;
extern const uint8  SftyMgt_stLih_C;
extern const uint8  SftyMgt_stNom_C;
extern const uint8  SftyMgt_stRstHw_C;
extern const uint8  SftyMgt_stRstSw_C;
extern const uint8  SftyMgt_stSfty3EngStopReq_C;
extern const uint8  SftyMgt_stSfty3RstHwReq_C;
extern const uint8  SftyMgt_tiDlyInhDftIpECULadd_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const uint16  SftyMgt_ctStopWrMemThd_C;
extern const uint16  SftyMgt_nEngInhDftIpAutChkThd_C;
extern const uint16  SftyMgt_nEngInhDftIpECUThd_C;
extern const uint16  SftyMgt_spdVehAftsThd_C;
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
extern boolean SftyMgt_bDgoIrvECU;
extern boolean SftyMgt_bDgoIrvEM;
extern boolean SftyMgt_bDgoIrvEngStop;
extern boolean SftyMgt_bDgoIrvSTT;
extern boolean SftyMgt_bDgoIrvVSCtl;
extern boolean SftyMgt_bDgoRvLih;
extern boolean SftyMgt_bInhSTT;
extern boolean SftyMgt_bMonRunIrvECU;
extern boolean SftyMgt_bMonRunIrvEM;
extern boolean SftyMgt_bMonRunIrvEngStop;
extern boolean SftyMgt_bMonRunIrvSTT;
extern boolean SftyMgt_bMonRunIrvVSCtl;
extern boolean SftyMgt_bMonRunRvLih;
extern boolean SftyMgt_bRstHwReq;
extern boolean SftyMgt_bRstHwReqAnt;
extern boolean SftyMgt_bRstSwReq;
extern boolean SftyMgt_bRstSwReqAnt;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 SftyMgt_ctDftLadd;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 SftyMgt_prm_bDftHisAfts1;
extern uint16 SftyMgt_prm_bDftHisAfts2;
extern uint16 SftyMgt_prm_bDftHisAfts3;
extern uint16 SftyMgt_prm_bDftHisAfts4;
extern uint16 SftyMgt_prm_bDftHisAfts5;
extern uint16 SftyMgt_prm_bDftHisAfts6;
extern uint16 SftyMgt_prm_bDftHisAfts7;
extern uint16 SftyMgt_prm_bDftHisAfts8;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_SftyMgr(void);
void SFTYMNGR_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SFTYMNGR_H */

/*-------------------------------- end of file -------------------------------*/
