/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SFTYMNGR                                                 */
/*                                                                            */
/* !Module         : SFTYMNGR                                                 */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : SFTYMNGR_L.H                                             */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_L.H_$*/
/* $Revision::   1.13     $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef SFTYMNGR_L_H
#define SFTYMNGR_L_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_PRM_BDFTHISAFTS_COLS           (8)
#define SFTYMGT_PRM_BDFTHISEVEDFT_COLS         (4)
#define SFTYMGT_PRM_BDFTHISEVEDFTAFTS_COLS     (4)
#define SFTYMGT_PRM_BDFTHISEVEINIAFTS_COLS     (4)
#define SFTYMGT_PRM_BDFTHISEVEKEYOFF_COLS      (4)
#define SFTYMGT_PRM_BDFTHISOLD_COLS            (4)
#define SFTYMGT_PRM_BFRFEVEDFT_COLS            (8)
#define SFTYMGT_PRM_BFRFEVEKEYOFF_COLS         (8)
#define SFTYMGT_PRM_BFRFOLD_COLS               (8)

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st104 */
#define NOMINAL_EM                        1
#define DEFAUT_EM                         2
#define IRV_EM                            3
#define LADDER_EM                         4
/*extern uint8 SFTYMNGR_stDiagEMState;*/

/* enum st102 */
#define NOMINAL_STT                       1
#define DEFAUT_STT                        2
#define IRV_STT                           3
#define LADDER_STT                        4
/*extern uint8 SFTYMNGR_stDiagSTTState;*/

/* enum st101 */
#define NOMINAL_VSCTL                     1
#define DEFAUT_VSCTL                      2
#define IRV_VSCTL                         3
#define LADDER_VSCTL                      4
/*extern uint8 SFTYMNGR_stDiagVSCtlState;*/

/* enum st103 */
#define KEYOFF                            1
#define DEFAUT_INACTIF                    2
#define DEFAUT_ACTIF                      3
#define FIN_ESCALADE_DEFAUT_ACTIF         4
#define FIN_ESCALADE_DEFAUT_INACTIF       5
/*extern uint8 SFTYMNGR_stEscaladeDefautsState;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SFTYMNGR_u8Inhib;
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
extern uint8 SFTYMNGR_stDiagEMState;
extern uint8 SFTYMNGR_stDiagSTTState;
extern uint8 SFTYMNGR_stDiagVSCtlState;
extern uint8 SFTYMNGR_stEscaladeDefautsState;
extern boolean SftyMgt_bDftIpECUCord;
extern boolean SftyMgt_bDftIpEMLadd;
extern boolean SftyMgt_bDftIpEnaAutChkPrio;
extern boolean SftyMgt_bDftIpEnaECU;
extern boolean SftyMgt_bDftIpEnaEM;
extern boolean SftyMgt_bDftIpEnaSTT;
extern boolean SftyMgt_bDftIpEnaVSCtl;
extern boolean SftyMgt_bDftIpSTTLadd;
extern boolean SftyMgt_bDftIpVSCtlLadd;
extern boolean SftyMgt_bDgoIni;
extern boolean SftyMgt_bDgoIrvECUTmp;
extern boolean SftyMgt_bDgoIrvEdgeECU;
extern boolean SftyMgt_bDgoIrvEdgeEM;
extern boolean SftyMgt_bDgoIrvEdgeSTT;
extern boolean SftyMgt_bDgoIrvEdgeVSCtl;
extern boolean SftyMgt_bDgoIrvEMTmp;
extern boolean SftyMgt_bDgoIrvSTTTmp;
extern boolean SftyMgt_bDgoIrvVSCtlTmp;
extern boolean SftyMgt_bDgoSatMem;
extern boolean SftyMgt_bDgoSatMemEveDft;
extern boolean SftyMgt_bDgoSatMemEveKeyOff;
extern boolean SftyMgt_bDgoSatMemEveSat;
extern boolean SftyMgt_bEnaWrMem;
extern boolean SftyMgt_bEveDftWrMem;
extern boolean SftyMgt_bEveDftWrMemEna;
extern boolean SftyMgt_bEveIniDftWrMemEna;
extern boolean SftyMgt_bEveIniEna;
extern boolean SftyMgt_bEveKeyOffWrMem;
extern boolean SftyMgt_bEveKeyOffWrMemEna;
extern boolean SftyMgt_bEveMemSat;
extern boolean SftyMgt_bEveWrMem;
extern boolean SftyMgt_bInhDftEdge;
extern boolean SftyMgt_bInhDftIpAutChkPrioNEng;
extern boolean SftyMgt_bInhDftIpECU_nEng;
extern boolean SftyMgt_bInhDftIpECULadd;
extern boolean SftyMgt_bKeyOffEdge;
extern boolean SftyMgt_bPresentInitVar;
extern boolean SftyMgt_bSfty3EngStopReqEdge;
extern boolean SftyMgt_bSfty3RstHwReqEdge;
extern boolean SFTYMNGR_bExtKeyOffPrev;
extern boolean SFTYMNGR_bResetAutomate;
extern boolean SFTYMNGR_bRstHwReqAntPrev1;
extern boolean SFTYMNGR_bRstHwReqAntPrev2;
extern boolean SFTYMNGR_bRstHwReqAntPrev3;
extern boolean SFTYMNGR_bRstHwReqAntPrev4;
extern boolean SFTYMNGR_bRstSwReqAntPrev1;
extern boolean SFTYMNGR_bRstSwReqAntPrev2;
extern boolean SFTYMNGR_bRstSwReqAntPrev3;
extern boolean SFTYMNGR_bRstSwReqAntPrev4;
extern boolean SFTYMNGR_bSfty3RstHwReqPrev;
extern boolean SFTYMNGR_bSftyEngStopReqPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern uint32 SftyMgt_prm_bDftHisEveDft[SFTYMGT_PRM_BDFTHISEVEDFT_COLS];
extern uint32 SftyMgt_prm_bDftHisEveDftAfts[SFTYMGT_PRM_BDFTHISEVEDFTAFTS_COLS];
extern uint32 SftyMgt_prm_bDftHisEveIniAfts[SFTYMGT_PRM_BDFTHISEVEINIAFTS_COLS];
extern uint32 SftyMgt_prm_bDftHisEveKeyOff[SFTYMGT_PRM_BDFTHISEVEKEYOFF_COLS];
extern uint32 SftyMgt_prm_bDftHisOld[SFTYMGT_PRM_BDFTHISOLD_COLS];
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 SftyMgt_ctDftLaddCord;
extern uint8 SftyMgt_ctDftLaddEveDft;
extern uint8 SftyMgt_ctDftLaddEveKeyOff;
extern uint8 SftyMgt_stDftLaddIp;
extern uint8 SFTYMNGR_u8ctDftLaddPrev;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 SftyMgt_ctWrMemEveDft;
extern uint16 SftyMgt_ctWrMemEveKeyOff;
extern uint16 SftyMgt_ctWrMemOld;
extern uint16 SftyMgt_prm_bDftHisAfts[SFTYMGT_PRM_BDFTHISAFTS_COLS];
extern uint16 SftyMgt_prm_bFrfEveDft[SFTYMGT_PRM_BFRFEVEDFT_COLS];
extern uint16 SftyMgt_prm_bFrfEveKeyOff[SFTYMGT_PRM_BFRFEVEKEYOFF_COLS];
extern uint16 SftyMgt_prm_bFrfOld[SFTYMGT_PRM_BFRFOLD_COLS];
extern uint16 SFTYMNGR_u16CntTurnOffDlySmpl;
extern uint16 SFTYMNGR_u16RstTurnOffDlySmpl;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/
#define TMS_START_SEC_CODE
#include "MemMap.h"
void SFTYMNGR_vidAdaptationEdge(void);
void SFTYMNGR_vidAppliqueInhiDefaut(void);
void SFTYMNGR_vidCalcCompteurEscalade(void);
void SFTYMNGR_vidCalculeMiseEnVeille(void);
void SFTYMNGR_vidCalculeSeuilRPM(void);
void SFTYMNGR_vidCasDefaut(void);
void SFTYMNGR_vidCasKeyOff(void);
void SFTYMNGR_vidCasSaturaEcritureMem(void);
void SFTYMNGR_vidCondEcriMemSurDefaut(void);
void SFTYMNGR_vidConditionSatMem(void);
void SFTYMNGR_vidConstrTramMemKeyoff(void);
void SFTYMNGR_vidConstruitTrameDft(void);
void SFTYMNGR_vidCoordDefautEdgeECU(void);
void SFTYMNGR_vidCoordinatDefautDgo(void);
void SFTYMNGR_vidCoordinationDiagECU(void);
void SFTYMNGR_vidDetDftPresentInit(void);
void SFTYMNGR_vidEcritMem(void);
void SFTYMNGR_vidEcritMemEEP(void);
void SFTYMNGR_vidEcritMemSat(void);
void SFTYMNGR_vidEcriTramMemSurDefaut(void);
void SFTYMNGR_vidEcrTramMemSurKeyoff(void);
void SFTYMNGR_vidEnFormeContexteGD(void);
void SFTYMNGR_vidEscaladeAttenteECU(void);
void SFTYMNGR_vidEscaladeDftECU(void);
void SFTYMNGR_vidEscaladeEM(void);
void SFTYMNGR_vidEscaladeSTT(void);
void SFTYMNGR_vidEscaladeVSCtl(void);
void SFTYMNGR_vidEvenementEcritMem(void);
void SFTYMNGR_vidExtraitMem(void);
void SFTYMNGR_vidGereEscalade(void);
void SFTYMNGR_vidIFTHENELSEWrMem(void);
void SFTYMNGR_vidInitOutput(void);
void SFTYMNGR_vidMemSansDefaut(void);
void SFTYMNGR_vidMemSansDefautEveDft(void);
void SFTYMNGR_vidMergeTrameCtxtGD(void);
void SFTYMNGR_vidSyntheseDefautECU(void);
void SFTYMNGR_vidSyntheseDefauts(void);
void SFTYMNGR_vidTraitDelaiRecAntiEsc(void);
void SFTYMNGR_vidTraiteMem1(void);
void SFTYMNGR_vidTraiteMem2(void);
void SFTYMNGR_vidTraiteNbEcritures(void);
void SFTYMNGR_vidTraitEnvoiDgoArreMot(void);
void SFTYMNGR_vidTraitEnvoiDgoEM(void);
void SFTYMNGR_vidTraitEnvoiDgoLimpHom(void);
void SFTYMNGR_vidTraitEnvoiDgoSTT(void);
void SFTYMNGR_vidTraitEnvoiDgoVSCtl(void);
void SFTYMNGR_vidTraitEnvoiResetHard(void);
void SFTYMNGR_vidTraitEnvoiResetSoft(void);
void SFTYMNGR_vidTrmCtxtVrGDDefaut(void);
void SFTYMNGR_vidTrmCtxtVrGDInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SFTYMNGR_L_H */

/*-------------------------------- end of file -------------------------------*/
