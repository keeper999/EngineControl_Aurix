/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_DAQ                                                                                         */
/* !Description     : CCP services for DAQ lists management                                                           */
/*                                                                                                                    */
/* !File            : CCP_Daq.c                                                                                       */
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
/* 1 / CCP_vidDaqListIni                                                                                              */
/* 2 / CCP_udtGetDaqSize                                                                                              */
/* 3 / CCP_udtSetDaqPtr                                                                                               */
/* 4 / CCP_udtWrDaqElmCfg                                                                                             */
/* 5 / CCP_udtStrtStop                                                                                                */
/* 6 / CCP_udtStrtStopAll                                                                                             */
/* 7 / CCP_vidDaqListStop                                                                                             */
/* 8 / CCP_vidDaqListStrt                                                                                             */
/* 9 / CCP_vidDaqListSetEvent                                                                                         */
/* 10 / CCP_vidDaqListTxMgr                                                                                           */
/* 11 / CCP_vidDaqListReadDynCfg                                                                                      */
/* 12 / CCP_vidDaqListWrDynCfg                                                                                        */
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/VE_S97/LOG/60_ComponentArchive/Archives/COMP_SWC_BSW_MCAL_MPC5676/Mcal.c_v                        $*/
/* $Revision::   1.7                                                                                                 $*/
/* $Author::   vbecquet                               $$Date::   14 Jun 2012 13:43:52                                $*/
/**********************************************************************************************************************/

#include "CCP.h"
#include "CCP_L.h"
#include "CCP_Cfg.h"
#include "CCP_Usr.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coDAQ_DYN_CAN_ID
   #error CCP_coDAQ_DYN_CAN_ID not defined
#endif
#ifndef CCP_coDAQ_MNG_EXTD_CAN_ID
   #error CCP_coDAQ_MNG_EXTD_CAN_ID not defined
#endif
#ifndef CCP_coDAQ_LIST_ID_EQ_EVT_ID
   #error CCP_coDAQ_LIST_ID_EQ_EVT_ID not defined
#endif
#ifndef CCP_coDAQ_ININ_STS_CHK
   #error CCP_coDAQ_ININ_STS_CHK not defined
#endif
#ifndef CCP_coDAQ_RESU_FEATURE
   #error CCP_coDAQ_RESU_FEATURE not defined
#endif
#ifndef CCP_coDAQ_ELM_SIZE_MAX
   #error CCP_coDAQ_ELM_SIZE_MAX not defined
#endif
#ifndef CCP_coDAQ_ELM_SIZE_MAX_8_BITS
   #error CCP_coDAQ_ELM_SIZE_MAX_8_BITS not defined
#endif
#ifndef CCP_coDAQ_ELM_SIZE_MAX_16_BITS
   #error CCP_coDAQ_ELM_SIZE_MAX_16_BITS not defined
#endif
#ifndef CCP_coDAQ_ELM_SIZE_MAX_32_BITS
   #error CCP_coDAQ_ELM_SIZE_MAX_32_BITS not defined
#endif

/**********************************************************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                                                         */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListIni                                                                                   */
/*                                                                                                                    */
/* !Description : Initialisation of the DAQ lists manager                                                             */
/* !Number      : 1                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidDaqListIni(void)
   {
      uint8_least                                            u8LocalListIdx;
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;


      CCP_strDaqListSeldElm.u8ElmIdx = CCP_u8DAQ_NO_ELMS_PER_ODT;

      for (u8LocalListIdx = 0; u8LocalListIdx < CCP_u8DAQ_NO_LISTS; u8LocalListIdx++)
      {
         pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8LocalListIdx];

         pstrLocalDaqListDynCfg->vbStopTx         = FALSE;
         pstrLocalDaqListDynCfg->bLstOdtProcd     = TRUE;
         pstrLocalDaqListDynCfg->u8OdtLstIdx      = 0;
         pstrLocalDaqListDynCfg->vu8TxSt          = CCP_u8DAQ_TX_ST_DONE;
         pstrLocalDaqListDynCfg->vbEvtSet         = FALSE;
# if (CCP_coDAQ_LIST_ID_EQ_EVT_ID != CCP_coACVD)
         pstrLocalDaqListDynCfg->u8EveChn         = 0;
# endif
         pstrLocalDaqListDynCfg->vu8CfgChgdCtr    = 0;
         pstrLocalDaqListDynCfg->u8CfgChgdAckdCtr = 0;
         pstrLocalDaqListDynCfg->vu8Mod           = CCP_u8DAQ_MOD_STOP;
         pstrLocalDaqListDynCfg->u16Ctr           = 0;
         pstrLocalDaqListDynCfg->u16Pslr          = 0;
      }
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtGetDaqSize                                                                                   */
/*                                                                                                                    */
/* !Description : Initialize DAQ list and return its format                                                           */
/*               Returns the size of the specified DAQ list as the number of                                          */
/*               available ObjectDescriptorTables (ODTs) and clears the                                               */
/*               current list.                                                                                        */
/*               If the specified list number is not available, size = 0                                              */
/*               should be returned. The DAQ list is initialized and data                                             */
/*               acquisition by this list is stopped.                                                                 */
/*               An individual CAN Identifier may be assigned to a DAQ list                                           */
/*               to configure multi ECU data acquisition. This feature is                                             */
/*               optional. If the given identifier isn't possible, an error                                           */
/*               code is returned. 29 bit CAN identifiers are marked by the                                           */
/*               most significant bit set.                                                                            */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = GET_DAQ_SIZE 0x14                                          */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           DAQ list number (0,1,...)                                                 */
/*               3           byte           don't care                                                                */
/*               4..7        unsigned long  CAN Identifier of DTO dedicated to list number                            */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           DAQ list size (= number of ODTs in this list)                             */
/*               4           byte           First PID of DAQ list                                                     */
/*               5..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 2                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_PRM_OUT_OF_RNG                            */
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetDaqSize(void)
   {
      uint8_least    u8LocalListIdx;
      CCP_tudtCmdSts udtLocalCmdSts;
      #if (CCP_coDAQ_DYN_CAN_ID == CCP_coACVD)
         uint32      u32LocalCanId;
      #endif
      #if (CCP_coDAQ_MNG_EXTD_CAN_ID == CCP_coACVD)
         boolean     bLocalIsExtdCanId;
      #endif


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8DAQ_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      u8LocalListIdx = (uint8_least)CCP_uniBuf.uniCmd.strGetDaqSize.u8ListIdx;
      if (u8LocalListIdx < CCP_u8DAQ_NO_LISTS)
      {
         #if (CCP_coDAQ_DYN_CAN_ID == CCP_coACVD)
            u32LocalCanId = CCP_uniBuf.uniCmd.strGetDaqSize.u32CanId;

            #if (CCP_coDAQ_MNG_EXTD_CAN_ID == CCP_coACVD)
               if ((u32LocalCanId & CCP_udtDAQ_CAN_ID_IS_EXTD) != 0)
               {
                  bLocalIsExtdCanId = TRUE;
               }
               else
               {
                  bLocalIsExtdCanId = FALSE;
               }
               u32LocalCanId &= CCP_udtDAQ_CAN_ID_MASK;

               if (  (  (bLocalIsExtdCanId == TRUE)
                     && (u32LocalCanId > CCP_udtEXTD_CAN_ID_MAX_ID))
                  || (  (bLocalIsExtdCanId == FALSE)
                     && (u32LocalCanId > CCP_udtSTD_CAN_ID_MAX_ID)))
            #else
               bLocalIsExtdCanId = FALSE;
               if (u32LocalCanId > CCP_udtSTD_CAN_ID_MAX_ID)
            #endif
            {
               return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
            }

            CCP_vidDaqListStop(u8LocalListIdx);
            udtLocalCmdSts = CCP_udtUsrDaqListSetCanId((uint8)u8LocalListIdx, bLocalIsExtdCanId, u32LocalCanId);
         #else
            CCP_vidDaqListStop(u8LocalListIdx);
            udtLocalCmdSts = CCP_udtCMD_STS_NO_ERR;
         #endif
         CCP_vidUsrDaqListClr((uint8)u8LocalListIdx);

         CCP_uniBuf.uniAck.strGetDaqSize.u8NoOdt         = CCP_kastrDaqListStatCfg[u8LocalListIdx].u8NoOdt;
         CCP_uniBuf.uniAck.strGetDaqSize.u8FirstPidOfDaq = CCP_kastrDaqListStatCfg[u8LocalListIdx].u8FirstPid;

         return(udtLocalCmdSts);
      }
      CCP_uniBuf.uniAck.strGetDaqSize.u8NoOdt = 0;
      return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtSetDaqPtr                                                                                    */
/*                                                                                                                    */
/* !Description : Set pointer on an element of the DAQ list                                                           */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = SET_DAQ_PTR 0x15                                           */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           DAQ list number (0,1,...)                                                 */
/*               3           byte           Object Descriptor Table ODT number (0,1,...)                              */
/*               4           byte           Element number within ODT(0,1,...)                                        */
/*               5..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 3                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_PRM_OUT_OF_RNG,                           */
/*            CCP_udtCMD_STS_DAQ_PROCESSOR_BUSY                                                                       */
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSetDaqPtr(void)
   {
      uint8 u8LocalListIdx;
      uint8 u8LocalOdtIdx;
      uint8 u8LocalElmIdx;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8DAQ_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      u8LocalListIdx = CCP_uniBuf.uniCmd.strSetDaqPtr.u8ListIdx;
      u8LocalOdtIdx  = CCP_uniBuf.uniCmd.strSetDaqPtr.u8OdtIdx;
      u8LocalElmIdx  = CCP_uniBuf.uniCmd.strSetDaqPtr.u8ElmIdx;
      if (  (u8LocalListIdx < CCP_u8DAQ_NO_LISTS)
         && (u8LocalOdtIdx < CCP_kastrDaqListStatCfg[u8LocalListIdx].u8NoOdt)
         && (u8LocalElmIdx < CCP_u8DAQ_NO_ELMS_PER_ODT))
      {
         if (CCP_astrDaqListDynCfg[u8LocalListIdx].vu8Mod == CCP_u8DAQ_MOD_STOP)
         {
            CCP_strDaqListSeldElm.u8ListIdx = u8LocalListIdx;
            CCP_strDaqListSeldElm.u8OdtIdx  = u8LocalOdtIdx;
            CCP_strDaqListSeldElm.u8ElmIdx  = u8LocalElmIdx;

            return(CCP_udtCMD_STS_NO_ERR);
         }
         return(CCP_udtCMD_STS_DAQ_PROCESSOR_BUSY);
      }
      CCP_strDaqListSeldElm.u8ElmIdx = CCP_u8DAQ_NO_ELMS_PER_ODT;
      return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtWrDaqElmCfg                                                                                  */
/*                                                                                                                    */
/* !Description : Writes one entry (description of single DAQ element) to a                                           */
/*               DAQ list defined by the DAQ list pointer (see SET_DAQ_PTR).                                          */
/*               The following DAQ element sizes are defined: 1 byte,                                                 */
/*               2 bytes (type word), 4 bytes (type long/Float).                                                      */
/*               An ECU may not support individual address extensions for                                             */
/*               each element and 2 or 4 byte element sizes. It is the                                                */
/*               responsibility of the slave device, that all bytes of a DAQ                                          */
/*               element are consistent upon transmission.                                                            */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = WRITE_DAQ 0x16                                             */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Size of DAQ element                                                       */
/*                                          in bytes { 1, 2, 4 }                                                      */
/*               3           byte           Address extension of DAQ element                                          */
/*               4..7        unsigned long  Address of DAQ element                                                    */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 4                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_PRM_OUT_OF_RNG, CCP_udtCMD_STS_WRG_SEQ    */
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtWrDaqElmCfg(void)
   {
      uint8          u8LocalElmIdx;
      uint8          u8LocalElmSize;
      uint8          u8LocalListIdx;
      uint8          u8LocalOdtIdx;
      CCP_tstrMta    strLocalMta;
      CCP_tudtCmdSts udtLocalCmdSts;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8DAQ_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      u8LocalElmIdx = CCP_strDaqListSeldElm.u8ElmIdx;
      if (u8LocalElmIdx < CCP_u8DAQ_NO_ELMS_PER_ODT)
      {
         u8LocalElmSize = CCP_uniBuf.uniCmd.strWrDaq.u8Size;
         #if (CCP_coDAQ_ELM_SIZE_MAX == CCP_coDAQ_ELM_SIZE_MAX_8_BITS)
            if (u8LocalElmSize == 1)
         #elif (CCP_coDAQ_ELM_SIZE_MAX == CCP_coDAQ_ELM_SIZE_MAX_16_BITS)
            if (  (u8LocalElmSize == 1)
               || (u8LocalElmSize == 2))
         #elif (CCP_coDAQ_ELM_SIZE_MAX == CCP_coDAQ_ELM_SIZE_MAX_32_BITS)
            if (  (u8LocalElmSize == 1)
               || (u8LocalElmSize == 2)
               || (u8LocalElmSize == 4))
         #else
            #error CCP_coDAQ_ELM_SIZE_MAX not correct
         #endif
         {
            u8LocalListIdx = CCP_strDaqListSeldElm.u8ListIdx;
            /* !Comment: Should be OK but check for robustness                                                        */
            if (u8LocalListIdx >= CCP_u8DAQ_NO_LISTS)
            {
               return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
            }
            u8LocalOdtIdx = CCP_strDaqListSeldElm.u8OdtIdx;
            /* !Comment: Should be OK but check for robustness                                                        */
            if (u8LocalOdtIdx >= CCP_kastrDaqListStatCfg[u8LocalListIdx].u8NoOdt)
            {
               return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
            }
            if (CCP_astrDaqListDynCfg[u8LocalListIdx].vu8Mod == CCP_u8DAQ_MOD_STOP)
            {
               strLocalMta.u32Adr = CCP_uniBuf.uniCmd.strWrDaq.u32Adr;
               strLocalMta.u8Extn = CCP_uniBuf.uniCmd.strWrDaq.u8AdrExtn;

               udtLocalCmdSts = CCP_udtUsrWrDaqElmCfg(u8LocalListIdx, u8LocalOdtIdx, u8LocalElmIdx,
                                                      &strLocalMta, u8LocalElmSize);
               return(udtLocalCmdSts);
            }
            return(CCP_udtCMD_STS_DAQ_PROCESSOR_BUSY);
         }
         return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
      }
      return(CCP_udtCMD_STS_WRG_SEQ);
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtStrtStop                                                                                     */
/*                                                                                                                    */
/* !Description : Start specified DAQ list or prepare it for synchronized start.                                      */
/*               This command is used to start or to stop the data                                                    */
/*               acquisition or to prepare a synchronized start of the                                                */
/*               specified DAQ list.                                                                                  */
/*               The Last ODT number specifies which ODTs (From 0 to Last ODT                                         */
/*               number) of this DAQ list should be transmitted. The Event                                            */
/*               Channel No. specifies the generic signal source that                                                 */
/*               effectively determines the data transmission timing. To                                              */
/*               allow reduction of the desired transmission rate, a                                                  */
/*               prescaler may be applied to the Event Channel. The prescaler                                         */
/*               value factor must be greater than or equal to 1. The mode                                            */
/*               parameter is defined as follows: 0x00 stops specified DAQ                                            */
/*               list, 0x01 starts specified DAQ list, 0x02 prepares DAQ list                                         */
/*               for synchronized start.                                                                              */
/*               The start/stop mode parameter = 0x02 (prepare to start data                                          */
/*               transmission) configures the DAQ list with the provided                                              */
/*               parameters but does not start the data acquisition of the                                            */
/*               specified list. This parameter is used for a synchronized                                            */
/*               start of all configured DAQ lists. In case the slave device                                          */
/*               is not capable of performing the synchronized start of the                                           */
/*               data acquisition, the slave device may then start data                                               */
/*               transmission if this parameter is true (not zero).                                                   */
/*               The ECU specific properties of event channels and DAQ lists                                          */
/*               may be described in the slave device description (ASAP2).                                            */
/*               Structure of data in CRO:                                                                            */
/*                                                                                                                    */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = START_STOP 0x06                                            */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Mode : start / stop /                                                     */
/*                                          prepare data tranmission                                                  */
/*               3           byte           DAQ list number                                                           */
/*               4           byte           Last ODT number                                                           */
/*               5           byte           Event Channel No.                                                         */
/*               6,7         word           Transmission rate prescaler                                               */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 5                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_DAQ_LIST_ININ_REQ,                        */
/*            CCP_udtCMD_STS_ACS_DENIED, CCP_udtCMD_STS_PRM_OUT_OF_RNG                                                */
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtStrtStop(void)
   {
      uint8_least                                            u8LocalListIdx;
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;
      uint8_least                                            u8LocalPrevMod;
      uint8_least                                            u8LocalMod;
      uint8                                                  u8LocalOdtLstIdx;
      uint8                                                  u8LocalEveChn;
      uint16                                                 u16LocalPslr;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8DAQ_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      #if (CCP_coDAQ_ININ_STS_CHK == CCP_coACVD)
         if ((CCP_u8SsnSts & CCP_u8DAQ_INID) != 0)
         {
            return(CCP_udtCMD_STS_DAQ_LIST_ININ_REQ);
         }
      #endif

      u8LocalListIdx = (uint8_least)CCP_uniBuf.uniCmd.strStrtStop.u8ListIdx;
      if (u8LocalListIdx < CCP_u8DAQ_NO_LISTS)
      {
         pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8LocalListIdx];

         u8LocalPrevMod = pstrLocalDaqListDynCfg->vu8Mod;
         u8LocalMod     = (uint8_least)CCP_uniBuf.uniCmd.strStrtStop.u8Mod;
         if (u8LocalMod == CCP_u8DAQ_MOD_STOP)
         {
            CCP_vidDaqListStop(u8LocalListIdx);

            return(CCP_udtCMD_STS_NO_ERR);
         }

         u8LocalOdtLstIdx = CCP_uniBuf.uniCmd.strStrtStop.u8OdtLstIdx;
         u8LocalEveChn    = CCP_uniBuf.uniCmd.strStrtStop.u8EveChn;
         u16LocalPslr     = CCP_uniBuf.uniCmd.strStrtStop.u16Pslr;
         if (  (  (u8LocalMod == CCP_u8DAQ_MOD_STRT)
               || (u8LocalMod == CCP_u8DAQ_MOD_SYNCD_STRT))
            && (u8LocalOdtLstIdx < CCP_kastrDaqListStatCfg[u8LocalListIdx].u8NoOdt)
            && (u8LocalEveChn < CCP_u8DAQ_NO_EVE_CHNS)
            && (u16LocalPslr > 0))
         {
            if (u8LocalPrevMod == CCP_u8DAQ_MOD_STRT)
            {
               /* !Comment: stop daq list to update configuration                                                     */
               CCP_vidDaqListStop(u8LocalListIdx);
            }

            pstrLocalDaqListDynCfg->u8OdtLstIdx = u8LocalOdtLstIdx;
# if (CCP_coDAQ_LIST_ID_EQ_EVT_ID != CCP_coACVD)
            pstrLocalDaqListDynCfg->u8EveChn    = u8LocalEveChn;
# endif
            pstrLocalDaqListDynCfg->u16Pslr     = u16LocalPslr;
            CCP_vidDaqListStrt(u8LocalListIdx, u8LocalMod);

            return(CCP_udtCMD_STS_NO_ERR);
         }
         return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
      }
      return(CCP_udtCMD_STS_ACS_DENIED);
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtStrtStopAll                                                                                  */
/*                                                                                                                    */
/* !Description : Start all "prepared to start" DAQ lists or stop all running DAQ lists.                              */
/*                                                                                                                    */
/*               This command is used to start the periodic transmission of                                           */
/*               all DAQ lists configured with the previously sent START_STOP                                         */
/*               command (start/stop mode = 2) as "prepared to start" in a                                            */
/*               synchronized manner.  The command is used to stop the                                                */
/*               periodic transmission of all DAQ lists, including those not                                          */
/*               started synchronized.                                                                                */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = START_STOP 0x08                                            */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           0x00 stops,                                                               */
/*                                          0x01 starts data transmission                                             */
/*               3..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 6                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_DAQ_LIST_ININ_REQ,                        */
/*            CCP_udtCMD_STS_PRM_OUT_OF_RNG                                                                           */
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtStrtStopAll(void)
   {
      uint8_least    u8LocalMod;
      uint8_least    u8LocalListIdx;
      CCP_tudtCmdSts udtLocalCmdSts;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8DAQ_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      #if (CCP_coDAQ_ININ_STS_CHK == CCP_coACVD)
         if ((CCP_u8SsnSts & CCP_u8DAQ_INID) != 0)
         {
            return(CCP_udtCMD_STS_DAQ_LIST_ININ_REQ);
         }
      #endif

      u8LocalMod = (uint8_least)CCP_uniBuf.uniCmd.strStrtStopAll.u8Mod;
      switch (u8LocalMod)
      {
         case CCP_u8DAQ_MOD_STOP:
            for (u8LocalListIdx = 0; u8LocalListIdx < CCP_u8DAQ_NO_LISTS; u8LocalListIdx++)
            {
               CCP_vidDaqListStop(u8LocalListIdx);
            }
            udtLocalCmdSts = CCP_udtCMD_STS_NO_ERR;
            break;

         case CCP_u8DAQ_MOD_STRT:
            for (u8LocalListIdx = 0; u8LocalListIdx < CCP_u8DAQ_NO_LISTS; u8LocalListIdx++)
            {
               if (CCP_astrDaqListDynCfg[u8LocalListIdx].vu8Mod == CCP_u8DAQ_MOD_SYNCD_STRT)
               {
                  CCP_vidDaqListStrt(u8LocalListIdx, CCP_u8DAQ_MOD_STRT);
               }
            }
            udtLocalCmdSts = CCP_udtCMD_STS_NO_ERR;
            break;

         default:
            udtLocalCmdSts = CCP_udtCMD_STS_PRM_OUT_OF_RNG;
            break;
      }
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListStop                                                                                  */
/*                                                                                                                    */
/* !Description : Stop specified DAQ list (internal function).                                                        */
/* !Number      : 7                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidDaqListStop
   (
      /* !Comment : Index of the DAQ list to stop                                                                     */
      /* !Range   : 0..(CCP_u8DAQ_NO_LISTS-1)                                                                         */
      /*            (index shall be checked by caller)                                                                */
      uint8_least u8ListIdx
   )
   {
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;
      uint8_least                                            u8LocalPrevMod;


      pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8ListIdx];

      u8LocalPrevMod = pstrLocalDaqListDynCfg->vu8Mod;

      /* !Comment : First, disable the action of SetEvent for the DAQ list.                                           */
      /*            Then, request to stop sending ODTs of the DAQ list. This will be done after the current ODT,      */
      /*            if any pending, has been sent.                                                                    */
      /*            This order is mandatory to guarantee that the "TxMngr" function will be able to check "bStopTx"   */
      /*            before it is cleared by the "SetEvent" function                                                   */
      pstrLocalDaqListDynCfg->vu8Mod = CCP_u8DAQ_MOD_STOP;
      pstrLocalDaqListDynCfg->vu8CfgChgdCtr++;
      if (  (u8LocalPrevMod == CCP_u8DAQ_MOD_STRT)
         && (CCP_u8DaqNoStrtdList > 0))
      {
         CCP_u8DaqNoStrtdList--;
      }
      pstrLocalDaqListDynCfg->vbStopTx = TRUE;
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListStrt                                                                                  */
/*                                                                                                                    */
/* !Description : Start specified DAQ list or prepare it for synchronized start.                                      */
/* !Number      : 8                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidDaqListStrt
   (
      /* !Comment : Index of the DAQ list to start                                                                    */
      /* !Range   : 0..(CCP_u8DAQ_NO_LISTS-1)                                                                         */
      /*            (index shall be checked by caller)                                                                */
      uint8_least u8ListIdx,
      /* !Comment : Start mode                                                                                        */
      /* !Range   : CCP_u8DAQ_MOD_STRT, CCP_u8DAQ_MOD_SYNCD_STRT                                                      */
      /*            (mode shall be checked by caller)                                                                 */
      uint8_least u8Mod
   )
   {
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;
      uint8_least                                            u8LocalPrevMod;


      pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8ListIdx];

      u8LocalPrevMod = pstrLocalDaqListDynCfg->vu8Mod;

      pstrLocalDaqListDynCfg->vu8Mod = (uint8)u8Mod;
      pstrLocalDaqListDynCfg->vu8CfgChgdCtr++;
      if (  (u8Mod == CCP_u8DAQ_MOD_STRT)
         && (u8LocalPrevMod != CCP_u8DAQ_MOD_STRT)
         && (CCP_u8DaqNoStrtdList < CCP_u8DAQ_NO_LISTS))
      {
         CCP_u8DaqNoStrtdList++;
      }
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListSetEvent                                                                              */
/*                                                                                                                    */
/* !Description : Set event to send associated DAQ list(s).                                                           */
/* !Number      : 9                                                                                                   */
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
      /* !Comment : Event channel to set                                                                              */
      /* !Range   : 0..(CCP_u8DAQ_NO_EVE_CHNS-1)                                                                      */
      uint8 u8EveChn
   )
   {
      uint8_least                                            u8LocalListIdx;
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;
      uint8                                                  u8LocalCfgChgdCtr;
      uint16_least                                           u16LocalCtr;
      uint8                                                  u8LocalFirstPid;
      uint8                                                  u8LocalOdtLstIdx;


      if (CCP_u8DaqNoStrtdList > 0)
      {
# if (CCP_coDAQ_LIST_ID_EQ_EVT_ID == CCP_coACVD)
         for (u8LocalListIdx = u8EveChn; u8LocalListIdx < CCP_u8DAQ_NO_LISTS; u8LocalListIdx = CCP_u8DAQ_NO_LISTS)
         {
# else
         for (u8LocalListIdx = 0; u8LocalListIdx < CCP_u8DAQ_NO_LISTS; u8LocalListIdx++)
         {
# endif
            pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8LocalListIdx];

            if (pstrLocalDaqListDynCfg->vu8Mod != CCP_u8DAQ_MOD_STRT)
            {
               continue;
            }
# if (CCP_coDAQ_LIST_ID_EQ_EVT_ID != CCP_coACVD)
            if (pstrLocalDaqListDynCfg->u8EveChn != u8EveChn)
            {
               continue;
            }
# endif

            /* !Comment : Check update in the daq list dynamic configuration                                          */
            u8LocalCfgChgdCtr = pstrLocalDaqListDynCfg->vu8CfgChgdCtr;
            if (u8LocalCfgChgdCtr != pstrLocalDaqListDynCfg->u8CfgChgdAckdCtr)
            {
               pstrLocalDaqListDynCfg->u8CfgChgdAckdCtr = u8LocalCfgChgdCtr;

               if (pstrLocalDaqListDynCfg->vu8Mod != CCP_u8DAQ_MOD_STRT)
               {
                  continue;
               }
               u16LocalCtr = 1;
            }
            else
            {
               u16LocalCtr = pstrLocalDaqListDynCfg->u16Ctr;
               if (u16LocalCtr == 0)
               {
                  continue;
               }
            }

            /* !Comment : Send daq list when prescaler expired                                                        */
            u16LocalCtr--;
            if (u16LocalCtr != 0)
            {
               pstrLocalDaqListDynCfg->u16Ctr = (uint16)u16LocalCtr;
               continue;
            }

            /* !Comment : Check validity of last ODT index                                                            */
            u8LocalOdtLstIdx = pstrLocalDaqListDynCfg->u8OdtLstIdx;
            if (u8LocalOdtLstIdx >= CCP_kastrDaqListStatCfg[u8LocalListIdx].u8NoOdt)
            {
               /* !Comment: Last ODT index is invalid => DAQ list transmission is disabled                            */
               pstrLocalDaqListDynCfg->u16Ctr = 0;
               continue;
            }

            /* !Comment : Everything is checked, transmission can be managed                                          */
            pstrLocalDaqListDynCfg->u16Ctr   = pstrLocalDaqListDynCfg->u16Pslr;
            pstrLocalDaqListDynCfg->vbEvtSet = TRUE;
            if (pstrLocalDaqListDynCfg->vu8TxSt == CCP_u8DAQ_TX_ST_DONE)
            {
               pstrLocalDaqListDynCfg->vbEvtSet     = FALSE;
               pstrLocalDaqListDynCfg->vu8TxSt      = CCP_u8DAQ_TX_ST_RUNNG;
               pstrLocalDaqListDynCfg->vbStopTx     = FALSE;
               pstrLocalDaqListDynCfg->bLstOdtProcd = FALSE;

               u8LocalFirstPid = CCP_kastrDaqListStatCfg[u8LocalListIdx].u8FirstPid;
               CCP_vidUsrDaqListTxMgrInit((uint8)u8LocalListIdx, u8LocalFirstPid, u8LocalOdtLstIdx);
               CCP_vidDaqListTxMgr((uint8)u8LocalListIdx);
            }
         }
      }
   }
#endif /* CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_vidDaqListTxMgr                                                                                 */
/*                                                                                                                    */
/* !Description : Manage the transmission of ODTs of the specified DAQ list.                                          */
/* !Number      : 10                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_CODE) CCP_vidDaqListTxMgr
   (
      /* !Comment : Index of the DAQ list to transmit                                                                 */
      /* !Range   : 0..(CCP_u8DAQ_NO_LISTS-1)                                                                         */
      uint8 u8ListIdx
   )
   {
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;


      if (u8ListIdx < CCP_u8DAQ_NO_LISTS)
      {
         pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8ListIdx];

         if (pstrLocalDaqListDynCfg->vbStopTx == FALSE)
         {
            if (pstrLocalDaqListDynCfg->bLstOdtProcd == FALSE)
            {
               pstrLocalDaqListDynCfg->bLstOdtProcd = CCP_bUsrDaqListTxMgr(u8ListIdx);
            }
            else
            {
               if (pstrLocalDaqListDynCfg->vbEvtSet == TRUE)
               {
                  pstrLocalDaqListDynCfg->vbEvtSet = FALSE;
                  CCP_vidUsrDaqListTxOvrn(u8ListIdx);
               }
               else
               {
                  pstrLocalDaqListDynCfg->vu8TxSt = CCP_u8DAQ_TX_ST_DONE;
               }
            }
         }
         else
         {
            pstrLocalDaqListDynCfg->vu8TxSt = CCP_u8DAQ_TX_ST_DONE;
            /* !Comment: "bStopTx" will be cleared by "SetEvent" to do this   */
            /*           in only one location and to take in account the fact */
            /*           that there could be no pending ODT to send when this */
            /*           boolean has been set                                 */

            /* !Comment: Indicates CCPUSR that a daq list has been stopped */
            CCP_vidUsrDaqListStopd(u8ListIdx);
         }
      }
   }
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
   )
   {
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;


      if (u8ListIdx < CCP_u8DAQ_NO_LISTS)
      {
         pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8ListIdx];

         *pu8Mod       = pstrLocalDaqListDynCfg->vu8Mod;
         *pu8OdtLstIdx = pstrLocalDaqListDynCfg->u8OdtLstIdx;
# if (CCP_coDAQ_LIST_ID_EQ_EVT_ID != CCP_coACVD)
         *pu8EveChn    = pstrLocalDaqListDynCfg->u8EveChn;
# else
         *pu8EveChn    = CCP_u8DAQ_NO_EVE_CHNS;
# endif
         *pu16Pslr     = pstrLocalDaqListDynCfg->u16Pslr;
      }
   }
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
   )
   {
      P2VAR(CCP_tstrDaqListDynCfg, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListDynCfg;
      uint8_least                                            u8LocalPrevMod;


      if (u8ListIdx < CCP_u8DAQ_NO_LISTS)
      {
         pstrLocalDaqListDynCfg = &CCP_astrDaqListDynCfg[u8ListIdx];

         u8LocalPrevMod = pstrLocalDaqListDynCfg->vu8Mod;

         pstrLocalDaqListDynCfg->vu8Mod      = u8Mod;
         pstrLocalDaqListDynCfg->u8OdtLstIdx = u8OdtLstIdx;
# if (CCP_coDAQ_LIST_ID_EQ_EVT_ID != CCP_coACVD)
         pstrLocalDaqListDynCfg->u8EveChn    = u8EveChn;
# endif
         pstrLocalDaqListDynCfg->u16Pslr     = u16Pslr;

         pstrLocalDaqListDynCfg->vu8CfgChgdCtr++;

         if (  (u8Mod == CCP_u8DAQ_MOD_STRT)
            && (u8LocalPrevMod != CCP_u8DAQ_MOD_STRT)
            && (CCP_u8DaqNoStrtdList < CCP_u8DAQ_NO_LISTS))
         {
            CCP_u8DaqNoStrtdList++;
         }
      }
   }
#endif /*    (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */
       /* && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD) */

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
