/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/* !Description     : CAN Calibration Protocol                                                                        */
/*                                                                                                                    */
/* !Module          : CCP                                                                                             */
/* !Description     : API of the Component                                                                            */
/*                                                                                                                    */
/* !File            : CCP.h                                                                                           */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
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

#ifndef CCP_H
#define CCP_H

#include "CCP_Typ.h"
#include "CCP_Cfg.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif
#ifndef CCP_coASYNC_RESP
   #error CCP_coASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif
#ifndef CCP_coDAQ_RESU_FEATURE
   #error CCP_coDAQ_RESU_FEATURE not defined
#endif

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
#define CCP_udtSTT_CNCTD      1
#define CCP_udtSTT_DCNCTD     2
#define CCP_udtSTT_TMP_DCNCTD 3


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidIni                                                                                          */
/*                                                                                                                    */
/* !Description : Initialize the CCP                                                                                  */
/* !Number      : 1                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Runnable : CCP_vidIni                                                                                             */
/* !Trigger  : reset                                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
FUNC(void, CCP_CODE) CCP_vidIni
(
   /* !Comment: CPP initialization parameters (NULL_PTR: use default settings)                                        */
   P2CONST(CCP_tstrIniPrms, AUTOMATIC, CCP_APPL_DATA) pkstrIniPrms
);

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidMonr                                                                                         */
/*                                                                                                                    */
/* !Description : Manage the CCP protocol                                                                             */
/* !Number      : 2                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Runnable : CCP_vidMonr                                                                                            */
/* !Trigger  : CAN message received                                                                                   */
/*                                                                                                                    */
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
FUNC(void, CCP_CODE) CCP_vidMonr(void);

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidAsyncRespMonr                                                                                */
/*                                                                                                                    */
/* !Description : Manage the asynchronous responses                                                                   */
/* !Number      : 3                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Runnable : CCP_vidAsyncRespMonr                                                                                   */
/* !Trigger  : can be called at the end of an action or periodically (period shall be compatible with timeout         */
/*             duration)                                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coASYNC_RESP == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidAsyncRespMonr(void);
#endif

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtGetState                                                                                     */
/*                                                                                                                    */
/* !Description : Returns the state of the CCP protocol                                                               */
/* !Number      : 4                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : state of the CCP protocol                                                                               */
/* !Range   : CCP_udtSTT_CNCTD, CCP_udtSTT_DCNCTD, CCP_udtSTT_TMP_DCNCTD                                              */
FUNC(CCP_tudtState, CCP_CODE) CCP_udtGetState(void);

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListSetEvent                                                                              */
/*                                                                                                                    */
/* !Description : Set event to send associated DAQ list(s).                                                           */
/* !Number      : 5                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidDaqListSetEvent
   (
      uint8 u8EveChn /* !Comment : Event channel to set                                                               */
                     /* !Range   : 0..(CCP_u8DAQ_NO_EVE_CHNS-1)                                                       */
   );
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListTxMgr                                                                                 */
/*                                                                                                                    */
/* !Description : Manage the transmission of ODTs of the specified DAQ list.                                          */
/* !Number      : 6                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !Runnable : CCP_vidDaqListTxMgr                                                                                    */
/* !Trigger  : at the end of the transmission of 1 or several ODTs to send the rest of the DAQ list                   */
/*             (shall be called also after the last ODT is sent)                                                      */
/*                                                                                                                    */
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidDaqListTxMgr
   (
      uint8 u8ListIdx /* !Comment : Index of the DAQ list to transmit                                                 */
                      /* !Range   : 0..(CCP_u8DAQ_NO_LISTS-1)                                                         */
   );
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListReadDynCfg                                                                            */
/*                                                                                                                    */
/* !Description : Read the dynamic configuration of the specified DAQ list.                                           */
/* !Number      : 11                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (  (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) \
    && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD))
   FUNC(void, CCP_CODE) CCP_vidDaqListReadDynCfg
   (
      /* !Comment : Index of the DAQ list                                                                             */
      /* !Range   : 0..(CCP_u8DAQ_NO_LISTS-1)                                                                         */
      uint8                                   u8ListIdx,
      /* !Comment : Pointer on the data to store the mode of the DAQ list                                             */
      /* !Range   : CCP_u8DAQ_MOD_STOP, CCP_u8DAQ_MOD_STRT, CCP_u8DAQ_MOD_SYNCD_STRT                                  */
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)  pu8Mod,
      /* !Comment : Pointer on the data to store the index of the last ODT of the DAQ list                            */
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)  pu8OdtLstIdx,
      /* !Comment : Pointer on the data to store the event channel associated with the DAQ list                       */
      /* !Range   : 0..(CCP_u8DAQ_NO_EVE_CHNS-1)                                                                      */
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)  pu8EveChn,
      /* !Comment : Pointer on the data to store the prescaler of the DAQ list                                        */
      P2VAR(uint16, AUTOMATIC, CCP_APPL_DATA) pu16Pslr
   );
#endif /*    (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */
       /* && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD) */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListWrDynCfg                                                                              */
/*                                                                                                                    */
/* !Description : Write the dynamic configuration of the specified DAQ list.                                          */
/*                To be used at reset if the resume feature is activated.                                             */
/* !Number      : 12                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (  (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) \
    && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD))
   FUNC(void, CCP_CODE) CCP_vidDaqListWrDynCfg
   (
      /* !Comment : Index of the DAQ list                                                                             */
      /* !Range   : 0..(CCP_u8DAQ_NO_LISTS-1)                                                                         */
      uint8  u8ListIdx,
      /* !Comment : Mode of the DAQ list                                                                              */
      /* !Range   : CCP_u8DAQ_MOD_STOP, CCP_u8DAQ_MOD_STRT, CCP_u8DAQ_MOD_SYNCD_STRT                                  */
      uint8  u8Mod,
      /* !Comment : Index of the last ODT of the DAQ list                                                             */
      uint8  u8OdtLstIdx,
      /* !Comment : Event channel associated with the DAQ list                                                        */
      /* !Range   : 0..(CCP_u8DAQ_NO_EVE_CHNS-1)                                                                      */
      uint8  u8EveChn,
      /* !Comment : Prescaler of the DAQ list                                                                         */
      uint16 u16Pslr
   );
#endif /*    (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */
       /* && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD) */

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

#endif /* CCP_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
