/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SAIMMO                                                   */
/* !Description     : SAIMMO Component.                                        */
/*                                                                            */
/* !Module          : SAIMMO                                                   */
/* !Description     : interface du module  SAIMMO                              */
/*                                                                            */
/* !File            : SAIMMO_IM.H                                              */
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
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/IMPORT_CONFIG/SAIMMO_IM.H_v $*/
/* $Revision::   1.0      $$Author::   fsanchez2     $$Date::   04 Mar 2014 1$*/
/* $Author::   fsanchez2                             $$Date::   04 Mar 2014 1$*/
/******************************************************************************/
#ifndef SAIMMO_IM_H
#define SAIMMO_IM_H

#include "ACQWKUSIG.h"
#include "COHCAN.H"
#include "DCM_MANU.h"
#include "DFTLIMSGMGT.H"
#include "ECUMNG.h"
#include "FRM.h"
#include "GDGAR.h"
#include "IFRTE.h"
#include "ISCANF072.H"
#include "ISCANF0E8.H"
#include "ISFHCAN.H"
#include "MUXDIAGON.H"
#include "NOPROD.h"
#include "NVMDIAG.h"
#include "NVMSRV.h"
#include "RND.h"
#include "SWFAIL.h"

#define Immo_ReqWrCod      RE_Immo_003_OIE   
#define Immo_GetConf       RE_Immo_009_OIE
#define Immo_ReqMatch      RE_Immo_004_OIE
#define Immo_Init          RE_Immo_001_OIE
#define Immo_EndWr         RE_Immo_006_OIE
#define Immo_ReqReadSt     RE_Immo_010_OIE
#define Immo_KeyMgt        RE_Immo_005_OIE
#define Immo_100ms         RE_Immo_002_OIE
#define Immo_ReqCtlCod     RE_Immo_008_OIE

/* See with FTOU */
#define Can_EveSaimmo_TxFrame072() \
do \
{ \
   ISCAN_vidEve_Tx_EAC_CMM_BSI_072();\
   ISCAN_vidEve_Tx_RQD_CMM_BSI_072();\
} \
while (0)

#define Can_EveSaimmo_TxFrame0E8() \
do \
{ \
   ISCAN_vidEve_Tx_EAC_CMM_UCC_0E8();\
   ISCAN_vidEve_Tx_RQD_CMM_UCC_0E8();\
} \
while (0)


#endif  /*SAIMMO_IM_H*/
/*-------------------------------- end of file -------------------------------*/
