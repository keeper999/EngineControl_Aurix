/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CCP                                                     */
/*                                                                            */
/* !Module          : CCP_CFG                                                 */
/* !Description     : Configuration of the Component                          */
/*                                                                            */
/* !File            : CCP_CFG.C                                               */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::                                                               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* Generated on 11/10/14, 10:16:14 by Genecode v2.6.0.0                       */
/******************************************************************************/

#include "CCP_Typ.h"
#include "CCP_L.h"
#include "CCP_Cfg.h"

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
#define CCP_START_SEC_CONST_UNSPECIFIED
#include "CCP_MemMap.h"

/* !Comment: list of activated services                                       */
CONST(CCP_tpfudtSrvFcn, CCP_CONST) CCP_kapfudtSrvFcn[CCP_udtNO_SRVS] =
{
   &CCP_udtFcnNotAvl,
   &CCP_udtCnct,
   &CCP_udtSetMta,
   &CCP_udtDnld,
   &CCP_udtUpld,
   &CCP_udtTest,
   &CCP_udtStrtStop,
   &CCP_udtDcnct,
   &CCP_udtStrtStopAll,
   &CCP_udtGetAcvCalPage,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtSetSsnSts,
   &CCP_udtGetSsnSts,
   &CCP_udtBldCks,
   &CCP_udtShoUpld,
   &CCP_udtFcnNotAvl,
   &CCP_udtSelCalPage,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtGetDaqSize,
   &CCP_udtSetDaqPtr,
   &CCP_udtWrDaqElmCfg,
   &CCP_udtExchId,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtGetCcpVers,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtFcnNotAvl,
   &CCP_udtDnld6
};

/* !Comment: device identifier                                                */
CONST(uint8, CCP_CONST) CCP_kaudtDevId[sizeof("P2017_BSW")] = "P2017_BSW";

/* !Comment: DAQ lists configuration                                          */
CONST(CCP_tstrDaqListStatCfg, CCP_CONST)
   CCP_kastrDaqListStatCfg[CCP_u8DAQ_NO_LISTS] =
{
   {8, 0},
   {8, 8},
   {8, 16},
   {8, 24}
};

#define CCP_STOP_SEC_CONST_UNSPECIFIED
#include "CCP_MemMap.h"


/*-------------------------------- end of file -------------------------------*/