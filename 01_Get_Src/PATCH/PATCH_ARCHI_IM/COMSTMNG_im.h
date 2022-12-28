/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COMSTMNG                                                */
/* !Description     : COMSTMNG Component.                                     */
/*                                                                            */
/* !Module          : COMSTMNG                                                */
/* !Description     : interface du module  COMSTMNG                           */
/*                                                                            */
/* !File            : COMSTMNG_IM.H                                           */
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
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/COMSTMN$*/
/* $Revision::   1.0.$$Author::   ynicaise       $$Date::   30 Oct 2$  */
/* $Author::   ynicaise                          $$Date::   30 Oct 2$  */
/******************************************************************************/
#ifndef COMSTMNG_IM_H
#define COMSTMNG_IM_H

#include "COMSTMNG_L.h"
#include "ECUMNG.H"
#include "IFRTE.h"
#include "MATHSRV.h"

#include "CanIf.h"
#include "CanTp_PBCfg.h"
#include "Can.h"
#include "com.h"
#include "ComM_Cfg.h"
#include "ComM_Types.h"
#include "Lin_17_AscLin.h"
#include "LinIf_PBcfg.h"
#include "Lin.h"


// #include "CanSM_Cfg.h"
extern const uint8 CanSMConfiguration;

// #include "PduR_PBCfg.h"
/******************************************************************************/
/*! \Description    Number of PB PduR configuration structures \n
    \Range          0..255 \n
*******************************************************************************/

#define PduR_u8NUMBER_OF_PB_CONFIGS         1U

#define    PduRRoutingTables    (*(PduR_akpkstreConfigArray[0]))

#define PDUR_START_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/
/*! \Description    Exporting the PB configuration array of the PduR module \n
*******************************************************************************/
#if(PduR_u8NUMBER_OF_PB_CONFIGS > 0U)
extern const * PduR_akpkstreConfigArray[PduR_u8NUMBER_OF_PB_CONFIGS];
#endif

#define PDUR_STOP_SEC_CALIB_CONST_UNSPECIFIED
#include "MemMap.h"


#endif /*COMSTMNG_IM_H */
/*-------------------------------- end of file -------------------------------*/
