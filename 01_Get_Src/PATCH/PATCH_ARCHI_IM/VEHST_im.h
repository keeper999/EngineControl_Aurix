/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHST                                                */
/* !Description     : VEHST Component.                                     */
/*                                                                            */
/* !Module          : VEHST                                                */
/* !Description     : interface du module  VEHST                           */
/*                                                                            */
/* !File            : VEHST_IM.H                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/VEH$*/
/* $Revision::   1.4 $$Author::   ynicaise       $$Date::   03 Nov 2$  */
/* $Author::   ynicaise                          $$Date::   03 Nov 2$  */
/******************************************************************************/
#ifndef VEHST_IM_H
#define VEHST_IM_H

#include "ACQAIRT.H"
#include "ACQCOT.h"
#include "AVRMISFCNT.H"
#include "CKMNGIF.h"
#include "CLCNFISAGAIN.H"
#include "CLUSWTDIAG.H"
#include "CSTRFUCONCESTIM.H"
#include "ECUMNG.h"
#include "FARSTRAMON.H"
#include "FAR_FARSPMGRONOFF.H"
#include "HEATSENO2US.H"
#include "IFRTE.h"
#include "INJCTL_INJFARCTLMGR.H"
#include "InjCutOffMgr.h"
#include "INMNFPRESDIAG.H"
#include "KNKCRITZONE.H"
#include "mFuSpCrk.h"
#include "SC.h"
#include "SYNCCKDIAG.H"
#include "UPLSACQ.H"

#include "MATHSRV.h"


/***************************************************************************************/
/* !Description : Evenement CRANKING vers RUNNING                             */
/* !Number      : IM.1                                                        */
/* !Reference   : V02 NT 08 05290 / 1                                         */
/*                                                                            */
/* !LastAuthor  : V. VOYER                                                    */
/***************************************************************************************/
#define EngSt_EveCrTR_VehSt()\
do \
{\
   SenAct_EveCrTR_AcqAdc(); /* PSL */ \
   GDGAR_EveCrkRun();                     /* GD_EveCrTR in OS */\
   GD_EveCrTR_DCIf();\
   SenAct_EveCrTR_tECUAcq();\
   SenAct_EveCrTR_tECUAcqIf();\
   Inj_EveCrTR_InjCmd();\
   IgLim_EveCrTR_CritZone();\
   IgLim_EveCrTR_FastCor();\
   IgLim_EveCrTR_CritZoneIf();\
   EngSt_EveCrTR_EngrunSt();\
   SenO2Us_EveCrTR_UpLsAcq();\
   SenO2Ds_EveCrTR_DsLsAcq();\
   HeatSenO2_EveCrTR_UsMgr();\
   HeatSenO2_EveCrTR_DsMgr();\
   HeatSenO2_EveCrTR_HotSenO2Flg();\
   CoT_EveCrTR_FctDiagCoT();\
   CoT_EveCrTR_AcqCoT();\
   Far_EveCrTR_FarSpMgr();\
   InjCtl_EveCrTR_FarCtlMgr();\
   StraMon_EveCrTR_FarStraMon();\
   Clu_EveCrTR_CluSwtDiag();\
   AirT_EveCrTR_AcqAirT();\
   rte_RE_UsThrMT_008_DRE();\
   rte_RE_InMdlT_013_DRE();\
   rte_RE_InMdlT_015_DRE();\
   Cstr_EveCrTR_FuConcEstim();\
   Cstr_EveCrTR_CstrEfcRed();\
   Misf_EveCrTR_AvrMisfCnt();\
   KnkTreat_EveCrTR_RblCritZone();\
   /*KnKTreat_EveCrTR();*/\
} \
while (0)

/***************************************************************************************/
/* !Description : Evenement RUNNING vers CRANKING                             */
/* !Number      : IM.2                                                        */
/* !Reference   : V02 NT 08 05290 / 1                                         */
/*                                                                            */
/* !LastAuthor  : V. VOYER                                                    */
/***************************************************************************************/
#define EngSt_EveRTCr_VehSt()\
do \
{\
   IgLim_EveRTCr_CritZone();\
   IgLim_EveRTCr_FastCor();\
   IgLim_EveRTCr_CritZoneIf();\
   Sync_EveRTCr_CkDiagSts();\
   InjCrk_EveRTCr_AntiFlood();\
   InjSys_EveRTCr_mFuSpCrk();\
   InjCrk_EveRTCr_AntiFloodIf();\
   KnkTreat_EveRTCr_RblCritZone();\
   /*KnKTreat_EveRTCr();*/\
} \
while (0)

/***************************************************************************************/
/* !Description : Evénement STALL vers CRANKING                               */
/* !Number      : IM.3                                                        */
/* !Reference   : V02 NT 08 05290 / 1                                         */
/*                                                                            */
/* !LastAuthor  : V. VOYER                                                    */
/***************************************************************************************/
#define EngSt_EveStTCr_VehSt()\
do \
{\
   Sync_EveStTCr_CkDiagSts();\
   InjCutOff_EveStTCr_CutOff();\
   InjCrk_EveStTCr_AntiFlood();\
   InjSys_EveStTCr_InjSpMgt();\
   InjCrk_EveStTCr_AntiFloodIf();\
   HeatSenO2_EveStTCr_UsMgr();\
   HeatSenO2_EveStTCr_DsMgr();\
   Inj_EveStTCr_InjCmd();\
} \
while (0)

/***************************************************************************************/
/* !Description : Evénement CRANKING vers STALL                               */
/* !Number      : IM.4                                                        */
/* !Reference   : n'existe pas encore                                         */
/*                                                                            */
/* !LastAuthor  : V. VOYER                                                    */
/***************************************************************************************/
#define EngSt_EveCrTSt_VehSt()\
do \
{\
   GDGAR_EveCrTst();             /* GD_EveCrTSt in OS */\
   Sync_EveCrTSt_CkDiagSts();\
   AirPres_EveCrTSt_InMnfPresDiag();\
} \
while (0)

#endif /*VEHST_IM_H */
/*-------------------------------- end of file -------------------------------*/
