/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : MONAUTHOSTT                                              */
/*                                                                            */
/* !Module         : MONAUTHOSTT                                              */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : MONAUTHOSTT.C75                                          */
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
/* $Revision::   1.3.1.2  $$Author::   mbenfrad       $$Date::   23 May 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MONAUTHOSTT.h"
#include "MONAUTHOSTT_l.h"

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
const boolean  SftyMgt_bInhDftDrvTraFRM_C = 0;
const boolean  SftyMgt_bInhDftEngGradTra_C = 0;
const boolean  SftyMgt_bInhDftStaAuth_C = 0;
const boolean  SftyMgt_bInhDftSTTDrvTra_C = 0;
const boolean  SftyMgt_bInhDftTra2010_C = 0;
const boolean  SftyMgt_bInhDgoDrvTraSfty_C = 0;
const boolean  SftyMgt_bInhNoEgdGearSfty_C = 0;
const boolean  SftyMgt_bInhStaAuth_C = 0;
const boolean  SftyMgt_bInhVehSecu_C = 0;
const boolean  SftyMgt_bNoEgdGearSftyCf_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  MONAUTHOSTT_u8Inhib = 0;
const uint8  SftyMgt_noTiDlyStepNEngGrad_C = 0;
const uint8  SftyMgt_st2004_C = 0;
const uint8  SftyMgt_stDrvTraInvld_C = 0;
const uint8  SftyMgt_stTqReqChaASR_C = 0;
const uint8  SftyMgt_stTypAM_C = 0;
const uint8  SftyMgt_stTypAMT_C = 0;
const uint8  SftyMgt_stTypMT_C = 0;
const uint8  SftyMgt_tiDlyOnDftSTT_C = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_nTiEngGradThd_C = 0;
const uint16  SftyMgt_nEngGradHi_C = 0;
const uint16  SftyMgt_nEngGradLo_C = 0;
const uint16  SftyMgt_rCluPThdClsTraLo_C = 0;
const uint16  SftyMgt_rCluThdSTTChk_C = 0;
const uint16  SftyMgt_spdVehGrad_C = 0;
const uint16  SftyMgt_spdVehThdSTTChk1_C = 0;
const uint16  SftyMgt_tiDlyInhEngStopSTTReq_C = 0;
const uint16  SftyMgt_tiDlyOnDftDrvTra_C = 0;
const uint16  SftyMgt_tiDlyOnDftDrvTraFRM_C = 0;
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
boolean MONAUTHOSTT_bActiveDelay_Prev;
boolean MONAUTHOSTT_bDftDrvTra2010AMTMrg;
boolean MONAUTHOSTT_bDftStaAuthAMTMerge;
boolean MONAUTHOSTT_bInhEngStopMTCfMerge;
boolean MONAUTHOSTT_bRStrtAuthSTTMerge;
boolean Sfty_bInhDrvTraSfty;
boolean Sfty_bInhEngStopSTTReq;
boolean SftyMgt_bDftDrivTraFRM;
boolean SftyMgt_bDftDrvTra_MP;
boolean SftyMgt_bDftDrvTra2010AM;
boolean SftyMgt_bDftDrvTra2010AMT;
boolean SftyMgt_bDftEngGradTra;
boolean SftyMgt_bDftEngGradTraMonAcv;
boolean SftyMgt_bDftStaAuthAM;
boolean SftyMgt_bDftStaAuthAMT;
boolean SftyMgt_bDftSTT;
boolean SftyMgt_bDgoDrvTra;
boolean SftyMgt_bDgoDrvTraFRM;
boolean SftyMgt_bDgoDrvTraSfty;
boolean SftyMgt_bDgoInhEngStopSTT;
boolean SftyMgt_bDgoSTTDrvTra;
boolean SftyMgt_bEna2010AMCf;
boolean SftyMgt_bEna2010AMTCf;
boolean SftyMgt_bEnaAMCf;
boolean SftyMgt_bEnaAMTCf;
boolean SftyMgt_bEnaMTSTTADCf;
boolean SftyMgt_bEnaNotMTSTTADCf;
boolean SftyMgt_bEnaNotSTTADCf;
boolean SftyMgt_bEnaSTTADCf;
boolean SftyMgt_bEngAuth_MP;
boolean SftyMgt_bEngGradThd_MP;
boolean SftyMgt_bInhEngStopMTCf;
boolean SftyMgt_bInhEngStopNotMTCf;
boolean SftyMgt_bMonRunDrvTra;
boolean SftyMgt_bMonRunInhEngStopSTT;
boolean SftyMgt_bRStrtAuthNotSTT;
boolean SftyMgt_bRStrtAuthSTT;
boolean SftyMgt_bStrtAuth;
boolean SftyMgt_bStrtRStrtAuth;
boolean SftyMgt_bStrtRStrtReqCord;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 MONAUTHOSTT_u8tiDlyOnDftSTT;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_nTiEngGrad_MP;
uint16 MONAUTHOSTT_u16Counter;
uint16 MONAUTHOSTT_u16Counter1;
uint16 MONAUTHOSTT_u16Counter2;
uint16 MONAUTHOSTT_u16Counter3;
uint16 MONAUTHOSTT_u16Counter4;
uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev;
uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev1;
uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev2;
uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev3;
uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev4;
uint16 MONAUTHOSTT_u16spdVehSecuPrev;
uint16 SftyMgt_nEngTiDly_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

