/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ISFHCAN                                                 */
/* !Description     : ISFHCAN Component.                                      */
/*                                                                            */
/* !Module          : ISFHCAN                                                 */
/* !Description     : interface du module  ISFHCAN                            */
/*                                                                            */
/* !File            : ISFHCAN_IM.H                                            */
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
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/ISFHCAN_$*/
/* $Revision::   1.0.1.4  $$Author::   ynicaise      $$Date::   31 Oct 2014 2$*/
/* $Author::   ynicaise                              $$Date::   31 Oct 2014 2$*/
/******************************************************************************/
#ifndef ISFHCAN_IM_H
#define ISFHCAN_IM_H

#include "ACCPEM.H"
#include "ACCPFRM.H"
#include "ACQCOT.H"
#include "ACTRTSTMEAP.H"
#include "COM_MIVIE_im.H"
#include "CTRLCFG.H"
#include "ELECITGRMOD.H"
#include "FULVL.H"
#include "IFAIRSYSIGSYS.H"
#include "MUXDIAGON.H"
#include "NOPROD.h"
#include "OILLVLACQ.H"
#include "SPTMOD.H"
#include "WKU.H"
#include "FHCANF552.H"
#include "TIENGSTOP.H"


/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 552            */
/* !Number      : IM.3                                                    */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_BSI_552() \
do \
{ \
   Cf_EveRxn552_FlowMng();\
   ENGST_EveRxn552();\
   /* EngSt_EveRxn552_TiEngStopIf(); */\
   FuSys_EveRxn552();\
} \
while (0)

/**************************************************************************/
/* !Description : Evenement emis sur reception de la trame 552bis         */
/* !Number      : IM.26                                                   */
/* !Reference   : NONE                                                    */
/*                                                                        */
/* !LastAuthor  : V. VOYER                                                */
/**************************************************************************/
#define ISCAN_EveRxn_V2_BSI_552() \
do \
{ \
   Can_EveRxn552_FHCanF552_FlowMng();\
   FuSysM_EveRxn552_tFuM();\
   Cf_EveRxn552bis_FlowMng();\
/*  EngSt_EveRxn552bis(); */\
/*  VehSpd_EveRxn552bis();*/\
/*  FuSys_EveRxn552_bis();  FuSys_EveRxn552bis in os */\
   FuSysM_EveRxn552_tFuM();\
} \
while (0)

#endif  /*ISFHCAN_IM_H*/
/*-------------------------------- end of file -------------------------------*/
