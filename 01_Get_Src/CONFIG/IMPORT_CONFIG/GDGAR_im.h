/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDGAR                                                   */
/* !Description     : GDGAR Component.                                        */
/*                                                                            */
/* !Module          : GDGAR                                                   */
/* !Description     : interface du module  GDGAR                              */
/*                                                                            */
/* !File            : GDGAR_IM.H                                              */
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
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/IMPORT_CONFIG/GDGAR_im.h_v $*/
/* $Revision::   1.0      $$Author::   fsanchez2     $$Date::   04 Mar 2014 1$*/
/* $Author::   fsanchez2                             $$Date::   04 Mar 2014 1$*/
/******************************************************************************/

#ifndef GDGAR_IM_H
#define GDGAR_IM_H

#include "ACCPCALCRPOS.H"
#include "ACQWKUSIG.H"
#include "AVRMISFCNT.H"
#include "CKMNGIF.H"
#include "COFANCMDDIAG.H"
#include "DC.H"
#include "DGOTEST.H"
#include "ECUMNG.H"
#include "ENGSTRTSTOP.H"
#include "FHCANF432.H"
#include "FHCANF489.h"
#include "FHCANF552.H"
#include "FLOWMNG.H"
#include "FRM.H"
#include "FRM_L.H" /* a cause de FRM_abTypAcvOptRvCcDd en private*/
#include "GD.h"
#include "GDEXTINT.h"
#include "GDFRM.h"
#include "GDFRMDEF.H"
#include "GDU.H"
#include "GMIL.H"
#include "GOBD.H"
#include "HRDRCVMNG.H"
#include "IFAIRSYSIGSYS.H"
#include "INDICOBD.h"
#include "InjCutOffMgr.H"
#include "INTOBDSRV.H"
#include "ISFHCAN.H"
#include "IUPRGENDEN.h"
#include "IUPRSPCDEN.h"
#include "JDDISCANIF.H"
#include "MEM.h"
#include "NOPROD.h"
#include "NVMSRV.H"
#include "OBDSRV06.h"
#include "RC01.H"
#include "RLYPWR.H"
#include "STATUSOFDTC.h"
#include "SUPSRV.h"
#include "SWFAIL.H"
#include "SYNCEXCMDIAG.H"
#include "SYNCINCMDIAG.H"
#include "TUNCFG.H"
#include "VEHMNG.H"
#include "VLVACTEXSERVO.H"
#include "WUC.h"


#define DC_vidExitEveGlbStrt()\
do\
{\
      RC01_vidMngEveGlbDCStrt();\
      GOBD_vidMngEveGlbDCStrt();\
      WUC_vidMngEveGlobDCStrt();\
      IUPRGENDEN_vidMngEveGlbDCStrt();\
      IuprSpcDen_GlbDCStrt();\
      GD_GlbDCStrt();\
      GDU_vidGlbDCStrt();\
}\
while(0)

/* --------------------------------------------- */
/* Event : EveRstDft                             */
/* Call all functions need for reset GD default  */
/* --------------------------------------------- */
#define GDEXTINT_EveRstDft()\
do\
{\
   Srv_EveRstDft_ObdSrv06();\
   GD_EveRstDft();\
   CoFan_EveRstDft_CmdDiagCoFan();\
   Srv_EveRstDft_NvmDiag();\
}\
while(0)

/* --------------------------------------------- */
/* Event : EveRstDftObd                          */
/* Call all functions need for reset OBD default */
/* --------------------------------------------- */
#define GDEXTINT_EveRstDftObd()\
do\
{\
   Misf_EveRstDftObd_AvrMisfCnt();\
   Srv_EveRstDftObd_ObdSrv06();\
   GD_EveRstDftObd();\
}\
while(0) 

/* --------------------------------------------- */
/* Event : EveSendDftLog                         */ 
/* --------------------------------------------- */
#define GD_EveSendDftLog_DftLogTx()\
do\
{\
   Can_EveSendDftLog();\
}\
while(0)

/* --------------------------------------------- */
/* Event : CALL_PrepaDataIscanBuffer             */ 
/* --------------------------------------------- */
#define JDD_vidPrepaDataIscanBuffer()\
do\
{\
   JDDISCANIF_PrepaDataIscanBuffer();\
}\
while(0)

/******bouchonnage pour l'obd*******/
#define OBD_vidMngEveRstDftCal()
/***********************************/
#endif /*GDGAR_IM_H */
/*-------------------------------- end of file -------------------------------*/
