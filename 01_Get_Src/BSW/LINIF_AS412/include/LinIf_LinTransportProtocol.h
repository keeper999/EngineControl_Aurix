/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_LinTransportProtocol                              */
/*!Description     : The "LinTransportProtocol" subcomponent header file.     */
/*                                                                            */
/*!\File             LinIf_LinTransportProtocol.h                            */
/* \par              The "LinTransportProtocol" subcomponent header file.    */
/*!Scope           : Private component                                       */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.5      $$Author::   mnabil         $$Date::   Jan 29 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_LINTRANSPORTPROTOCOL_H
#define LINIF_LINTRANSPORTPROTOCOL_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf_Types.h"
#include "LinIf_Types_Internal.h"
#include "LinIf_Cfg.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define LINIF_START_SEC_CODE
#include "Memmap.h"


extern FUNC(void, LINIF_CODE) LinIf_vidTPSendFrame(
    VAR(uint8, AUTOMATIC) u8ChannelIndex,
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend);


extern FUNC(void, LINIF_CODE) LinIf_vidTPMain(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel);


extern FUNC(void, LINIF_CODE) LinIf_vidTPTimeoutHandler(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel);


extern FUNC(void, LINIF_CODE) LinIf_vidTPTxConf(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   VAR(boolean, AUTOMATIC) bTransmissionOK);


extern FUNC(void, LINIF_CODE) LinIf_vidTPRxInd(
   VAR(uint8, AUTOMATIC) u8ChannelIndex);


extern FUNC(void, LINIF_CODE) LinIf_vidTPSRFNoResp(
   VAR(uint8, AUTOMATIC) u8ChannelIndex);

#define LINIF_STOP_SEC_CODE
#include "Memmap.h"

#endif /* LINIF_LINTRANSPORTPROTOCOL_H */

/*-------------------------------- end of file -------------------------------*/
