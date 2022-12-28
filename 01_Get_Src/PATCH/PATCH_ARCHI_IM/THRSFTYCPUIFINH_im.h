/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSFTYCPUIFINH                                                */
/* !Description     : THRSFTYCPUIFINH Component.                                     */
/*                                                                            */
/* !Module          : THRSFTYCPUIFINH                                                */
/* !Description     : interface du module  THRSFTYCPUIFINH                           */
/*                                                                            */
/* !File            : THRSFTYCPUIFINH_IM.H                                           */
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
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/THRSFTYCPUIFI$*/
/* $Revision::   1.1 $$Author::   ynicaise       $$Date::   13 Oct 2$  */
/* $Author::   ynicaise                          $$Date::   13 Oct 2$  */
/******************************************************************************/
#ifndef THRSFTYCPUIFINH_IM_H
#define THRSFTYCPUIFINH_IM_H

#include "THRSFTYMNG.h"
#include "THRMNGSERVO.h"
#include "THRPOSMES.h"
#include "GDGAR.h"
#include "GDFRMDEF.h"
#include "MCWDG.H"
#include "SFTYMGTIFTQ.H"

#include "MATHSRV.h"

/* Creeer une issue sur ce define a voir FTOU */
#define Thr_EveChkLih_MngServo() \
do \
{ \
   Thr_EveChkLih_MngServo_ThrStopClcn();\
   Thr_EveChkLih_ThrSftyMng();\
   SftyMgt_EveChkLih_ifTqMon();\
} \
while (0)

#endif /*THRSFTYCPUIFINH_IM_H */
/*-------------------------------- end of file -------------------------------*/
