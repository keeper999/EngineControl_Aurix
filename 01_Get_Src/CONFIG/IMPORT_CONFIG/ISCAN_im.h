/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ISCAN                                                   */
/* !Description     : ISCAN Component.                                        */
/*                                                                            */
/* !Module          : ISCAN                                                   */
/* !Description     : interface du module  ISCAN                              */
/*                                                                            */
/* !File            : ISCAN_IM.H                                              */
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
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/IMPORT_CONFIG/ISCAN_im.h_v $*/
/* $Revision::   1.6      $$Author::   croche2       $$Date::   11 Jun 2014 1$*/
/* $Author::   croche2                               $$Date::   11 Jun 2014 1$*/
/******************************************************************************/
#ifndef ISCAN_IM_H
#define ISCAN_IM_H

#include "NOPROD.h"
#include "ACCPCALCRPOS.h"
#include "ACCPFRM.h"
#include "ACCPMNGMODSECU.h"
#include "ACPRESACQ.H"
#include "ACQCOT.H"
#include "ACQWKUSIG.H"
#include "BRKASIACQ.H"
#include "CANSECUCHKDATA.h"
#include "CKMNGIF.H"
#include "COFANCMDDIAG.h"
#include "COHCAN.h"
#include "CRSCTLBSITREAT.H"
#include "CRSCTLINTREATIF.h"
#include "CRSCTLOUTTREAT.h"
#include "CTRLCFG.h"
#include "DC.h"
#include "DIAGBRKPED.h"

#include "DCM_GEN.H"
#include "TIENGSTOP.h"
#include "ECUMNG.H"
#include "FHCANF305.H"
#include "FHCANF30D.H"
#include "FHCANF329.H"
#include "FHCANF349.h"
#include "FHCANF34D.H"
#include "FHCANF38D.H"
#include "FHCANF3AD.H"
#include "FHCANF3C9.h"
#include "FHCANF3CD.H"
#include "FHCANF412.H"
#include "FHCANF432.H"
#include "FHCANF44D.H"
#include "FHCANF489.h"
#include "FHCANF495.H"
#include "FHCANF4F2.H"
#include "FHCANF50D.H"
#include "FHCANF50E.H"
#include "FHCanF532.H"
#include "FHCANF552.H"
#include "FHCANF572.H"
#include "FHCANF57C.H"
#include "FHCANF592.H"
#include "FHCANF5B2.H"
#include "FHCANF612.H"
#include "FHCANF7F2.H"
#include "FLOWMNG.h"
#include "FRM.h"
#include "FUCNS.H"
#include "GD.h"
#include "GMIL.h"
#include "GOBD.h"
#include "IFAIRSYSIGSYS.H"
#include "IFRTE.h"
#include "INFOCRASH.H"
#include "INTOBDSRV.H"
#include "JDD.H"
#include "JDDISCANIF.H"
#include "MUXDIAGON.h"
#include "MUXTQREQ.h"
#include "NEUTPOSNACQ.h"
#include "NVMSRV.h"
#include "OILPRESACQ.h"
//#include "OILLVLACQ.H"                                  /* LTHI */
#include "PWRLRLY.H"
#include "Rte_GDGAR.H"
#include "RVSSTDIAG.h"
#include "SAIMMO.H"
#include "SFTYMGTIFTQ.H"
#include "SPTMOD.H"
#include "TOILEST.H"
#include "TQSYSVLD.h"
#include "TUNCFG.h"
#include "VEHMNG.H"
#include "VEHSPDACQ.H"
#include "WKU.H"
#include "DFTLIMSGMGT.H"
#include "ACCPEM.H"	

/* Stub CANTP */
#define CANTP_u8NB_OF_USDT_NWL 2
#define CAN_UUDT_NWL  CANTP_u8NB_OF_USDT_NWL

/* ESC : VEMS V02 ECU#060373 */
#include  "VEMS.H"
#define TRANSITOIRE RTE_MODE_RCD_Mode_TRANSITORY

/*
extern void ISCAN_EveRxn_092(void); *
extern void ISCAN_EveRxn_0A8(void); *
extern void ISCAN_EveRxn_0E0(void); *
extern void ISCAN_EveRxn_30D(void); *
extern void ISCAN_EveRxn_329(void); *
extern void ISCAN_EveRxn_349(void); *
extern void ISCAN_EveRxn_34D(void); *
extern void ISCAN_EveRxn_38D(void); *
extern void ISCAN_EveRxn_3CD(void); *
extern void ISCAN_EveRxn_412(void); *
extern void ISCAN_EveRxn_432(void); *
extern void ISCAN_EveRxn_44D(void); *
extern void ISCAN_EveRxn_4C8(void); *
extern void ISCAN_EveRxn_4F2(void); *
extern void ISCAN_EveRxn_50D(void); *
extern void ISCAN_EveRxn_50E(void); *
extern void ISCAN_EveRxn_552(void); *
extern void ISCAN_EveRxn_55F(void); *
extern void ISCAN_EveRxn_592(void); *
extern void ISCAN_EveRxn_5B2(void); *
extern void ISCAN_EveRxn_612(void); *
extern void ISCAN_EveRxn_772(void); *
extern void ISCAN_EveRxn_7F2(void); *
extern void ISCAN_EveRxn_3C9(void); *
extern void ISCAN_EveRxn_3AD(void); *
extern void ISCAN_EveRxn_305(void); *
extern void ISCAN_EveRxn_451(void); *
extern void ISCAN_EveRxn_495(void); *
extern void ISCAN_EveRxn_572(void); *
extern void ISCAN_EveRxn_792(void); *
*/

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 412            */
/* !Number      : IM.1                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_412() \
do \
{ \
   Can_EveRxn412_FHCanF412();\
   Can_EveRxn412_CohCan();\
   Fu_EveRxn412_FuLvl();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 432            */
/* !Number      : IM.2                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_432() \
do \
{ \
   boolean bLocalCtrl_bAcv_FuTnkPmp;\
   Can_EveRxn432_FHCanF432();\
   Can_EveRxn432_FHCanF432If();\
   /* FuPmp_RxnIdDaRcdDml();           FuPmp_EveRxnIdDaRcdDml in OS */\
   VEMS_vidGET(Ctrl_bAcv_FuTnkPmp, bLocalCtrl_bAcv_FuTnkPmp);\
   if (bLocalCtrl_bAcv_FuTnkPmp == 0)\
   {\
      FuPmp_EveRxnIdDaRcdDml();\
   }\
   PwrlRly_EveRxnIdDaRcdDml();\
   EcuSt_EveRxn432_Wku();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 552            */
/* !Number      : IM.3                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_552() \
do \
{ \
   Can_EveRxn552_FHCanF552();\
   Cf_EveRxn552_FlowMng();\
   EngSt_EveRxn552_TiEngStop();\
   EngSt_EveRxn552_EngStrtStop();\
   EngSt_EveRxn552_TiEngStopIf();\
/*    FuSys_EveRxn552(); */\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 552bis         */
/* !Number      : IM.26                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_552bis() \
do \
{ \
   Can_EveRxn552_FHCanF552();\
   Can_EveRxn552_FHCanF552_FlowMng();\
   Cf_EveRxn552bis_FlowMng();\
   EngSt_EveRxn552bis_TiEngStop();\
   EngSt_EveRxn552_EngStrtStop();\
   VehSpd_EveRxn552_VehMux();\
   /* FuSys_EveRxn552_bis();   FuSys_EveRxn552bis in os */\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 592            */
/* !Number      : IM.4                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_592() \
do \
{ \
   Can_EveRxn592_FHCanF592();\
   Can_EveRxn592_FHCanF592If();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 34D            */
/* !Number      : IM.5                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_34D() \
do \
{ \
   Can_EveRxn34D_FHCanF34DAVIf();\
   Can_EveRxn34D_FHCanF34D();\
   Can_EveRxn34D_FHCanF34DIf();\
   Can_EveRxn34D_FHCanF34DIf2();\
   SftyMgt_EveRxn34D_ifTqMon();\
   SftyMgt_EveRxn34D_DiagSftyLvl2();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 38D            */
/* !Number      : IM.6                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_38D() \
do \
{ \
   Can_EveRxn38D_FHCanF38D();\
   Can_EveRxn38D_FHCanF38DIf();\
   rte_RE_TqSys_EveSyncFrame38D_Tra();\
   SftyMgt_EveRxn38D_ifTqMon();\
   SftyMgt_EveRxn38D_DiagSftyLvl2();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 50E            */
/* !Number      : IM.7                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_50E() \
do \
{ \
   Can_EveRxn50E_FHCanF50E();\
   Can_EveRxn50E_CohCan();\
   CrsCtl_EveRxn50E_CrsCtlBsiTreat();\
   Can_EveRxn50E_FHCanF50EIf2();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 7F2            */
/* !Number      : IM.8                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_7F2() \
do \
{ \
   Can_EveRxn7F2_FHCanF7F2_FlowMng();\
   ISCAN_EveRxn7F2_If();\
   Can_EveRxn7F2_FHCanF7F2AVIf();\
   Can_EveRxn7F2_FHCanF7F2();\
   Can_EveRxn7F2_CohCan();\
   VehSpd_EveRxn7F2_VehMux();\
   Can_EveRxn7F2_TiEngStop();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 7F2            */
/* !Number      : IM.9                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_0A8() \
do \
{ \
   SAIMMO_EveRxn0A8();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 7F2            */
/* !Number      : IM.10                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_0E0() \
do \
{ \
   SAIMMO_EveRxn0E0();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 7F2            */
/* !Number      : IM.11                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_3CD() \
do \
{ \
   Can_EveRxn3CD_FHCanF3CD();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 7F2            */
/* !Number      : IM.12                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_4C8() \
do \
{ \
   RlyPwr_EveRxn4c8_CrashVeh();\
   ISCAN_EveRxn4C8_If();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 4F2            */
/* !Number      : IM.14                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_4F2() \
do \
{ \
   Can_EveRxn4F2_FHCanF4F2AVIf();\
   Can_EveRxn4F2_FHCanF4F2();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 489            */
/* !Number      : IM.15                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_489() \
do \
{ \
   Can_EveRxn489_FHCanF489();\
   Can_EveRxn489_FHCanF489_FlowMng();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 329            */
/* !Number      : IM.16                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_329() \
do \
{ \
   Can_EveRxn329_FHCanF329();\
   SftyMgt_EveRxn329_ifTqMon();\
   SftyMgt_EveRxn329_DiagSftyLvl2();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 30D            */
/* !Number      : IM.17                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_30D() \
do \
{ \
   Can_EveRxn30D_FHCanF30D();\
   Can_EveRxn30D_FHCanF30DIf();\
   rte_RE_TqSys_EveSyncFrame30D_Tra();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 44D            */
/* !Number      : IM.18                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_44D() \
do \
{ \
   Can_EveRxn44D_FHCanF44D();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 612            */
/* !Number      : IM.19                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_612() \
do \
{ \
   Can_EveRxn612_FHCanF612();\
   Can_EveRxn612_FHCanF612If();\
   Fu_EveRxn612_FuLvl();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 5B2            */
/* !Number      : IM.20                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_5B2() \
do \
{ \
   Can_EveRxn5B2_FHCanF5B2();\
   Can_EveRxn5B2_CohCan();\
   Can_EveRxn5B2_TiEngStop();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 50D            */
/* !Number      : IM.21                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_50D() \
do \
{ \
   Can_EveRxn50D_FHCanF50D();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 50Dbis         */
/* !Number      : IM.21.1                                                 */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_50Dbis() \
do \
{ \
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 349            */
/* !Number      : IM.22                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_349() \
do \
{ \
   Can_EveRxn349_FHCanF349();\
   Can_EveRxn349_FHCanF349If_2();\
   Can_EveRxn349_FHCanF349_FlowMng();\
   SftyMgt_EveRxn349_ifTqMon();\
   SftyMgt_EveRxn349_DiagSftyLvl2();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 092            */
/* !Number      : IM.23                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_092() \
do \
{ \
	DIAGCAN_EveRxn092IntElec();         /* DIAGCAN_EveRxn092 in OS */\
	DIAGCAN_EveRxn092_If(); \
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 772            */
/* !Number      : IM.24                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_772() \
do \
{ \
   GD_EveRxn772();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 55F            */
/* !Number      : IM.25                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_55F() \
do \
{ \
   GD_EveRxn55F();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 3C9            */
/* !Number      : IM.28                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_3C9() \
do \
{ \
   Can_EveRxn3C9_FHCanF3C9();\
   Can_EveRxn3C9_FHCanF3C9If();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 3AD            */
/* !Number      : IM.29                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_3AD() \
do \
{ \
   Can_EveRxn3AD_FHCanF3AD();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 305            */
/* !Number      : IM.30                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_305() \
do \
{ \
   Can_EveRxn305_FHCanF305();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 305bis         */
/* !Number      : IM.30.1                                                 */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_305bis() \
do \
{ \
   /* ISCAN_EveRxn305bis(); vide selon OS */\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 451            */
/* !Number      : IM.31                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_451() \
do \
{ \
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 495            */
/* !Number      : IM.32                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_495() \
do \
{ \
   Can_EveRxn495_FHCanF495();\
   Can_EveRxn495_FHCanF495If();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 572            */
/* !Number      : IM.33                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_572() \
do \
{ \
   ISCAN_EveRxn572_If();\
   Can_EveRxn572_FHCanF572();\
   Can_EveRxn572_CohCan();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 792            */
/* !Number      : IM.34                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_792() \
do \
{ \
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 532            */
/* !Number      : IM.34                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_532() \
do \
{ \
   Can_EveRxn532_FHCanF532();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 57C            */
/* !Number      : IM.34                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_57C() \
do \
{ \
   Can_EveRxn57C_FHCanF57C();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 4B2            */
/* !Number      : IM.35                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_4B2() \
do \
{ \
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 4D2            */
/* !Number      : IM.36                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_4D2() \
do \
{ \
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 492            */
/* !Number      : IM.37                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_492() \
do \
{ \
} \
while (0)


#endif  /*ISCAN_IM_H*/
/*-------------------------------- end of file -------------------------------*/
