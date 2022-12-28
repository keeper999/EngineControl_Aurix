/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCSTT                                                */
/* !Description     : SYNCSTT Component.                                     */
/*                                                                            */
/* !Module          : SYNCSTT                                                */
/* !Description     : interface du module  SYNCSTT                           */
/*                                                                            */
/* !File            : SYNCSTT_IM.H                                           */
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
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/SYNCS$*/
/* $Revision::   1.2 $$Author::   ynicaise       $$Date::   03 Nov 2$  */
/* $Author::   ynicaise                          $$Date::   03 Nov 2$  */
/******************************************************************************/
#ifndef SYNCSTT_IM_H
#define SYNCSTT_IM_H

#include "COSYNC.h"
#include "CKMNGIF.h"
#include "VLVACTINENDSTOP.h"
#include "VLVACTEXENDSTOP.h"
#include "GDGAR.h"
#include "FRM.h"
#include "TUNCFG.h"
#include "CTRLCFG.h"
#include "GDFRMDEF.h"
#include "InjSysMgrCrk.h"
#include "IGCOILMNG.H"

#include "MATHSRV.h"

/* appel externe - call in SYNCSTT, a voir avec FTOU */
#define Sync_EveSyncAccu_SyncSTT()\
do \
{\
	Sync_EveSyncAccu_AcqSyncSTT();\
	IgCmd_EveSyncAccu_IgCoilMng();\
}\
while (0)

/* appel externe - call in SYNCSTT, a voir avec FTOU */
#define Sync_EveSyncNotAccu_SyncSTT()\
do \
{\
   InjSys_EveCkSnNtAc_InjSysMgrCrk();\
   InjSys_EveCkSnNtAc_InjSpMgt();\
   InjSys_EveCkSnNtAc_mFuInj();\
   InjSys_EveCkSnNtAc_mFuInjSyncIf();\
   InjrM_EveCkSnOn_InjrMdlIf();\
   Inj_EveSyncNotAccu_InjCmd();\
}\
while (0)

#endif /*SYNCSTT_IM_H */
/*-------------------------------- end of file -------------------------------*/
