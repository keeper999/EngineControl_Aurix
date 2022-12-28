/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : MONAUTHOSTT                                              */
/*                                                                            */
/* !Module         : MONAUTHOSTT                                              */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : MONAUTHOSTT_L.H                                          */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/MONAUTHOSTT/MONAUTHOST$*/
/* $Revision::   1.3.1.3  $$Author::   mbenfrad       $$Date::   23 May 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef MONAUTHOSTT_L_H
#define MONAUTHOSTT_L_H

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
extern const uint8  MONAUTHOSTT_u8Inhib;
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
extern boolean MONAUTHOSTT_bActiveDelay_Prev;
extern boolean MONAUTHOSTT_bDftDrvTra2010AMTMrg;
extern boolean MONAUTHOSTT_bDftStaAuthAMTMerge;
extern boolean MONAUTHOSTT_bInhEngStopMTCfMerge;
extern boolean MONAUTHOSTT_bRStrtAuthSTTMerge;
extern boolean SftyMgt_bDftDrivTraFRM;
extern boolean SftyMgt_bDftDrvTra_MP;
extern boolean SftyMgt_bDftDrvTra2010AM;
extern boolean SftyMgt_bDftDrvTra2010AMT;
extern boolean SftyMgt_bDftEngGradTra;
extern boolean SftyMgt_bDftEngGradTraMonAcv;
extern boolean SftyMgt_bDftStaAuthAM;
extern boolean SftyMgt_bDftStaAuthAMT;
extern boolean SftyMgt_bDgoDrvTraFRM;
extern boolean SftyMgt_bDgoDrvTraSfty;
extern boolean SftyMgt_bDgoSTTDrvTra;
extern boolean SftyMgt_bEna2010AMCf;
extern boolean SftyMgt_bEna2010AMTCf;
extern boolean SftyMgt_bEnaAMCf;
extern boolean SftyMgt_bEnaAMTCf;
extern boolean SftyMgt_bEnaMTSTTADCf;
extern boolean SftyMgt_bEnaNotMTSTTADCf;
extern boolean SftyMgt_bEnaNotSTTADCf;
extern boolean SftyMgt_bEnaSTTADCf;
extern boolean SftyMgt_bEngAuth_MP;
extern boolean SftyMgt_bEngGradThd_MP;
extern boolean SftyMgt_bInhEngStopMTCf;
extern boolean SftyMgt_bInhEngStopNotMTCf;
extern boolean SftyMgt_bRStrtAuthNotSTT;
extern boolean SftyMgt_bRStrtAuthSTT;
extern boolean SftyMgt_bStrtAuth;
extern boolean SftyMgt_bStrtRStrtAuth;
extern boolean SftyMgt_bStrtRStrtReqCord;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 MONAUTHOSTT_u8tiDlyOnDftSTT;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_nTiEngGrad_MP;
extern uint16 MONAUTHOSTT_u16Counter;
extern uint16 MONAUTHOSTT_u16Counter1;
extern uint16 MONAUTHOSTT_u16Counter2;
extern uint16 MONAUTHOSTT_u16Counter3;
extern uint16 MONAUTHOSTT_u16Counter4;
extern uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev;
extern uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev1;
extern uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev2;
extern uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev3;
extern uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev4;
extern uint16 MONAUTHOSTT_u16spdVehSecuPrev;
extern uint16 SftyMgt_nEngTiDly_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void MONAUTHOSTT_vidArch2004_2010_BVA(void);
void MONAUTHOSTT_vidArch2004_2010BVMP(void);
void MONAUTHOSTT_vidArchi2010_et_BVMP(void);
void MONAUTHOSTT_vidArchi2010et_BVA(void);
void MONAUTHOSTT_vidAutorisationDem(void);
void MONAUTHOSTT_vidAutorisRedemSTT(void);
void MONAUTHOSTT_vidAutorRedemSansSTT(void);
void MONAUTHOSTT_vidCalcul_Defaut_CdT(void);
void MONAUTHOSTT_vidCompGenDefautSTT(void);
void MONAUTHOSTT_vidConfigArchiEEBV(void);
void MONAUTHOSTT_vidCoord_defaut_CdT(void);
void MONAUTHOSTT_vidCoordAutDemRedem(void);
void MONAUTHOSTT_vidCoordSecuriADML(void);
void MONAUTHOSTT_vidCrdDemdAutDmRdmN1(void);
void MONAUTHOSTT_vidCrdEmbConNeutConf(void);
void MONAUTHOSTT_vidInitOutput(void);
void MONAUTHOSTT_vidMergeSTTConfig(void);
void MONAUTHOSTT_vidMiseEnPlaceFRMBVA(void);
void MONAUTHOSTT_vidSecuEmbConNeutBVA(void);
void MONAUTHOSTT_vidSecurEmbrContNeut(void);
void MONAUTHOSTT_vidSecurisationADML(void);
void MONAUTHOSTT_vidSecurisationSTTDA(void);
void MONAUTHOSTT_vidSecuriser_STT(void);
void MONAUTHOSTT_vidSTTConfiguration(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* MONAUTHOSTT_L_H */

/*-------------------------------- end of file -------------------------------*/
