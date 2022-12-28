/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQDGOHAL                                                */
/* !Description     : ACQDGOHAL Component.                                     */
/*                                                                            */
/* !Module          : ACQDGOHAL                                                */
/* !Description     : interface du module  ACQDGOHAL                           */
/*                                                                            */
/* !File            : ACQDGOHAL_IM.H                                           */
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
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/ACQDGOH$*/
/* $Revision::   1.2 $$Author::   ynicaise       $$Date::   03 Nov 2$  */
/* $Author::   ynicaise                          $$Date::   03 Nov 2$  */
/******************************************************************************/
#ifndef ACQDGOHAL_IM_H
#define ACQDGOHAL_IM_H

#include "BATTVOLTACQ.h"
#include "CTRLCFG.h"
#include "DGOHAL.h"
#include "DRVRSENO2US.h"
#include "ELECITGRMOD.h"
#include "FRM.h"
#include "GDGAR.h"
#include "IFRTE.h"
#include "NOPROD.h"
#include "WKU.h"

/* anciennement défini via l'OIL TLE7209.OIL sur EB_DT, n'existe pas sur 6_2 */
#define DGOHAL_bfFAULT_CMD_THR_HB        0
#define DGOHAL_bfFAULT_CMD_THR_SCW       0
#define DGOHAL_bfVALID_CMD_THR_HB        0
#define DGOHAL_bfVALID_CMD_THR_SCW       0

/* To be remove */
#define DGOHAL_udt_DMTR                  DGOHAL_udtDMTR_HOLD_EN
#define DGOHAL_udtCHAUFFAGE_BLOW_BY_1    DGOHAL_udtCHAUFFAGE_BLOW_BY
#define DGOHAL_udtCHAUFFAGE_BLOW_BY_2    0
#define DGOHAL_udtCP                     DGOHAL_udtCANISTER_PURGE_VALVE
#define DGOHAL_udtDML_1                  0
#define DGOHAL_udtENGST                  0
#define DGOHAL_udtMAIN_RELAY             DGOHAL_udtMAIN_RLY 


#endif /*ACQDGOHAL_IM_H */
/*-------------------------------- end of file -------------------------------*/
