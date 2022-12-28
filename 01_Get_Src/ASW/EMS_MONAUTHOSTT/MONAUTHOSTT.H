/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : MONAUTHOSTT                                              */
/*                                                                            */
/* !Module         : MONAUTHOSTT                                              */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : MONAUTHOSTT.H                                            */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/MONAUTHOSTT/MONAUTHOST$*/
/* $Revision::   1.1.1.1  $$Author::   mbenfrad       $$Date::   23 May 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef MONAUTHOSTT_H
#define MONAUTHOSTT_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SftyMgt_tiSdlDrvTra_SC            40           /* 40 */

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
extern const boolean  SftyMgt_bInhDftDrvTraFRM_C;
extern const boolean  SftyMgt_bInhDftEngGradTra_C;
extern const boolean  SftyMgt_bInhDftStaAuth_C;
extern const boolean  SftyMgt_bInhDftSTTDrvTra_C;
extern const boolean  SftyMgt_bInhDftTra2010_C;
extern const boolean  SftyMgt_bInhDgoDrvTraSfty_C;
extern const boolean  SftyMgt_bInhNoEgdGearSfty_C;
extern const boolean  SftyMgt_bInhStaAuth_C;
extern const boolean  SftyMgt_bInhVehSecu_C;
extern const boolean  SftyMgt_bNoEgdGearSftyCf_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_noTiDlyStepNEngGrad_C;
extern const uint8  SftyMgt_st2004_C;
extern const uint8  SftyMgt_stDrvTraInvld_C;
extern const uint8  SftyMgt_stTqReqChaASR_C;
extern const uint8  SftyMgt_stTypAM_C;
extern const uint8  SftyMgt_stTypAMT_C;
extern const uint8  SftyMgt_stTypMT_C;
extern const uint8  SftyMgt_tiDlyOnDftSTT_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_nTiEngGradThd_C;
extern const uint16  SftyMgt_nEngGradHi_C;
extern const uint16  SftyMgt_nEngGradLo_C;
extern const uint16  SftyMgt_rCluPThdClsTraLo_C;
extern const uint16  SftyMgt_rCluThdSTTChk_C;
extern const uint16  SftyMgt_spdVehGrad_C;
extern const uint16  SftyMgt_spdVehThdSTTChk1_C;
extern const uint16  SftyMgt_tiDlyInhEngStopSTTReq_C;
extern const uint16  SftyMgt_tiDlyOnDftDrvTra_C;
extern const uint16  SftyMgt_tiDlyOnDftDrvTraFRM_C;
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
extern boolean Sfty_bInhDrvTraSfty;
extern boolean Sfty_bInhEngStopSTTReq;
extern boolean SftyMgt_bDftSTT;
extern boolean SftyMgt_bDgoDrvTra;
extern boolean SftyMgt_bDgoInhEngStopSTT;
extern boolean SftyMgt_bMonRunDrvTra;
extern boolean SftyMgt_bMonRunInhEngStopSTT;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void MONAUTHOSTT_vidEntryInit(void);
void SftyMgt_SdlMid_STTDrvTra(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* MONAUTHOSTT_H */

/*-------------------------------- end of file -------------------------------*/
