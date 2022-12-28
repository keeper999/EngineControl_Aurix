/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_Def                                                                                         */
/* !Description     : Local data of the Component                                                                     */
/*                                                                                                                    */
/* !File            : CCP_Def.c                                                                                       */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT 2009 VALEO                                                                                               */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/VE_S97/LOG/60_ComponentArchive/Archives/COMP_SWC_BSW_MCAL_MPC5676/Mcal.c_v                        $*/
/* $Revision::   1.7                                                                                                 $*/
/* $Author::   vbecquet                               $$Date::   14 Jun 2012 13:43:52                                $*/
/**********************************************************************************************************************/

#include "CCP_Typ.h"
#include "CCP_L.h"
#include "CCP_Cfg.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif
#ifndef CCP_coOPT_SRV_SSN_STS
   #error CCP_coOPT_SRV_SSN_STS not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coASYNC_RESP
   #error CCP_coASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif

/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/
#define CCP_START_SEC_VAR_UNSPECIFIED
#include "CCP_MemMap.h"

VAR(CCP_tudtState, CCP_VAR) CCP_udtState;

VAR(CCP_tuniPtclMsgBuf, CCP_VAR) CCP_uniBuf;

VAR(CCP_tstrMta, CCP_VAR) CCP_astrMta[CCP_u8NO_MTA];

#if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
   VAR(uint8, CCP_VAR) CCP_u8SsnSts;
#endif

#if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
   VAR(uint8, CCP_VAR) CCP_u8ProtnSts;
   VAR(uint8, CCP_VAR) CCP_u8UnlckResReq;
#endif

#if (CCP_coASYNC_RESP == CCP_coACVD)
   VAR(boolean,         CCP_VAR) CCP_bAsyncRespPnd;
   VAR(CCP_tudtCmdCode, CCP_VAR) CCP_udtAsyncRespCmdCode;
#endif

#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   VAR(CCP_tstrDaqListSeldElm, CCP_VAR) CCP_strDaqListSeldElm;

   VAR(uint8, CCP_VAR) CCP_u8DaqNoStrtdList;

   VAR(CCP_tstrDaqListDynCfg, CCP_VAR) CCP_astrDaqListDynCfg[CCP_u8DAQ_NO_LISTS];
#endif

#define CCP_STOP_SEC_VAR_UNSPECIFIED
#include "CCP_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
