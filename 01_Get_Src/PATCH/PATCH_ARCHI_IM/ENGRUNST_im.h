/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGRUNST                                                */
/* !Description     : ENGRUNST Component.                                     */
/*                                                                            */
/* !Module          : ENGRUNST                                                */
/* !Description     : interface du module  ENGRUNST                           */
/*                                                                            */
/* !File            : ENGRUNST_IM.H                                           */
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
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/ENGRUN$*/
/* $Revision::   1.1 $$Author::   ynicaise       $$Date::   13 Oct 2$  */
/* $Author::   ynicaise                          $$Date::   13 Oct 2$  */
/******************************************************************************/
#ifndef ENGRUNST_IM_H
#define ENGRUNST_IM_H

#include "CKMNGIF.h"
#include "ACQCOT.h"
#include "THRCORRDPOSN.h"
#include "ACCPCALCRPOS.h"
#include "IFCATMDLSYS.h"
#include "IFAIRSYSIGSYS.h"
#include "TUNCFG.h"
#include "FHCANF34D.h"
#include "IFRTE.h"
#include "IDLSYSCUTOFF.h"
#include "DCM_MANU.h"
#include "GDGAR.h"
#include "FRM.h"
#include "GDFRMDEF.h"
#include "NOPROD.h"
#include "NVMSRV.h"
#include "IFRTE.H"
#include "FAR_FARSPMGRONOFF.H"

#include "MATHSRV.h"


/***************************************************************************************/
/* !Description : Transition ERUN_ENGINE_OVERRUN_FCO vers ERUN_NORMAL_RUNNING */
/* !Number      : IM.5                                                        */
/* !Reference   : V02 NT 08 05237 / 1                                         */
/*                                                                            */
/* !LastAuthor  : V. VOYER                                                    */
/***************************************************************************************/
#define EngSt_EveEORF_EngrunSt()\
do\
{\
   rte_RE_AdvMinT_008_DRE();\
}\
while(0)

/***************************************************************************************/
/* !Description : Transition ERUN_NORMAL_RUNNING vers ERUN_FULL_LOAD          */
/* !Number      : IM.6                                                        */
/* !Reference   : V02 NT 08 05237 / 1                                         */
/*                                                                            */
/* !LastAuthor  : V. VOYER                                                    */
/***************************************************************************************/
#define EngSt_EveNTFL_EngrunSt()\
do\
{\
   Far_EveNTFL_FarSpMgr();\
}\
while(0)

/***************************************************************************************/
/* !Description : Entrée en ERUN_ENGINE_OVERRUN_FCO ou                        */
/*                ERUN_ENGINE_OVERSPEED_FCO                                   */
/* !Number      : IM.7                                                        */
/* !Reference   : V02 NT 08 05237 / 1                                         */
/*                                                                            */
/* !LastAuthor  : V. VOYER                                                    */
/***************************************************************************************/
#define EngSt_EveTOSR_EngrunSt()\
do\
{\
 	Far_EveTOSR_FarSpMgr();\
}\
while(0)

#endif /*ENGRUNST_IM_H */
/*-------------------------------- end of file -------------------------------*/
