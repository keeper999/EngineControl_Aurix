/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCPUSR                                                                                          */
/* !Description     : User functions definition                                                                       */
/*                                                                                                                    */
/* !File            : CCPUSR_Daq.c                                                                                    */
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

#include "Std_Types.h"
#include "Ccp.h"
#include "Ccp_L.h"
#include "CCP_Usr.h"
#include "CCPUSR.h"
#include "CCPUSR_Cfg.h"
#include "CCPUSR_Daq.h"
#include "CCPUSR_Daq_Cfg.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif
#ifndef CCP_coDAQ_ELM_SIZE_MAX
   #error CCP_coDAQ_ELM_SIZE_MAX not defined
#endif
#ifndef CCP_coDAQ_ELM_SIZE_MAX_8_BITS
   #error CCP_coDAQ_ELM_SIZE_MAX_8_BITS not defined
#endif
#ifndef CCP_coDAQ_FILL_WHOLE_LIST
   #error CCP_coDAQ_FILL_WHOLE_LIST not defined
#endif


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/* !Comment: Element sizes */
#define CCPUSR_U8_SIZE  1
#define CCPUSR_U16_SIZE 2
#define CCPUSR_U32_SIZE 4


/**********************************************************************************************************************/
/* TYPES                                                                                                              */
/**********************************************************************************************************************/
typedef struct
{
   uint8  u8OdtLstIdx;
   uint8  u8OdtToTxIdx;
   uint16 u16ElmToTxIdx;
}
CCPUSR_tstrDaqListData;


/**********************************************************************************************************************/
/* INTERNAL FUNCTIONS DECLARATION                                                                                     */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "MemMap.h"

#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   static FUNC(void, CCP_USR_CODE) CCPUSR_vidDaqListSrchNextActvDaqList
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   );
#endif /* (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */

#define CCP_STOP_SEC_CODE
#include "MemMap.h"


/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/
#define CCP_START_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"

static P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) CCPUSR_apu8DaqListElmAdr[CCP_u16DAQ_NO_ELMS];
#if (CCP_coDAQ_ELM_SIZE_MAX != CCP_coDAQ_ELM_SIZE_MAX_8_BITS)
   static uint8 CCPUSR_au8DaqListElmSize[CCP_u16DAQ_NO_ELMS];
#endif
#if (CCP_coDAQ_FILL_WHOLE_LIST == CCP_coACVD)
   static uint8 CCPUSR_au8DaqListElmVal[CCP_u16DAQ_NO_ELMS];
#endif

static CCPUSR_tstrDaqListData CCPUSR_astrDaqListData[CCP_u8DAQ_NO_LISTS];

static uint8 CCPUSR_u8DaqListInvalidData = 0;

/* !Comment: Priority used to define which daqlist is authorized to transmit its ODTs.                                */
/*           Priority is defined by the order of definition (first daqlist has the highest priority).                 */
static volatile uint8 CCPUSR_vu8DaqListPrio = UINT8_MAX;

#define CCP_STOP_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: DAQ list initialisation                                                                           */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCPUSR_vidDaqListIni(void)
   {
      uint8 u8LocalListIdx;


      for (u8LocalListIdx = 0; u8LocalListIdx < CCP_u8DAQ_NO_LISTS; u8LocalListIdx++)
      {
         CCPUSR_astrDaqListData[u8LocalListIdx].u8OdtToTxIdx = UINT8_MAX;
      }
   }

   #if (CCP_coDAQ_DYN_CAN_ID == CCP_coACVD)
      /****************************************************************************************************************/
      /* !Description: Set DAQ list CAN identifier                                                                    */
      /****************************************************************************************************************/
      /* !Comment: Status of the request                                                                              */
      /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG                                               */
      FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrDaqListSetCanId
      (
         /* !Comment: DAQ list index                                                                                  */
         /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                       */
         /*           (guaranted by caller)                                                                           */
         uint8   u8ListIdx,
         /* !Comment: TRUE if extended CAN identifier, FALSE otherwise                                                */
         boolean bIsExtdCanId,
         /* !Comment: CAN identifier                                                                                  */
         /* !Range:   0..CCP_udtSTD_CAN_ID_MAX_ID  if bIsExtdCanId == FALSE                                           */
         /*           0..CCP_udtEXTD_CAN_ID_MAX_ID if bIsExtdCanId == TRUE                                            */
         /*           (guaranted by caller)                                                                           */
         uint32  u32CanId
      )
      {
         #error Not implemented
      }
   #endif /* (CCP_coDAQ_DYN_CAN_ID == CCP_coACVD) */

   /*******************************************************************************************************************/
   /* !Description: Request to clear the DAQ list                                                                     */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrDaqListClr
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   )
   {
      P2CONST(CCP_tstrDaqListStatCfg, AUTOMATIC, CCP_APPL_DATA) pkstr8LocalDaqListStatCfg;
      /* !Range: 0..((254*7)-1)                                                                                       */
      uint16_least                                              u16LocalFirstElmIdx;
      /* !Range: 0..((254*7)-1)                                                                                       */
      uint16_least                                              u16LocalLastElmIdx;
      /* !Range: 0..((254*7)-1)                                                                                       */
      uint16_least                                              u16LocalElmIdx;


      CCPUSR_astrDaqListData[u8ListIdx].u8OdtToTxIdx = UINT8_MAX;

      pkstr8LocalDaqListStatCfg = &CCP_kastrDaqListStatCfg[u8ListIdx];

      u16LocalFirstElmIdx = ((uint16_least)pkstr8LocalDaqListStatCfg->u8FirstPid) * 7;
      u16LocalLastElmIdx  = (u16LocalFirstElmIdx + ((((uint16_least)pkstr8LocalDaqListStatCfg->u8NoOdt) * 7) - 1));

      for (u16LocalElmIdx = u16LocalFirstElmIdx; u16LocalElmIdx <= u16LocalLastElmIdx; u16LocalElmIdx++)
      {
         CCPUSR_apu8DaqListElmAdr[u16LocalElmIdx] = &CCPUSR_u8DaqListInvalidData;
         #if (CCP_coDAQ_ELM_SIZE_MAX != CCP_coDAQ_ELM_SIZE_MAX_8_BITS)
            CCPUSR_au8DaqListElmSize[u16LocalElmIdx] = 0;
         #endif

         #if (CCP_coDAQ_FILL_WHOLE_LIST == CCP_coACVD)
            CCPUSR_au8DaqListElmVal[u16LocalElmIdx] = 0;
         #endif
      }
   }

   /*******************************************************************************************************************/
   /* !Description: Configure an element of a DAQ list                                                                */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG                                                  */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrWrDaqElmCfg
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8                                          u8ListIdx,
      /* !Comment: Relative ODT index within the DAQ list                                                             */
      /* !Range:   0..(CCP_u8DAQ_NO_ODTS(u8ListIdx)-1)                                                                */
      /*           (guaranted by caller)                                                                              */
      uint8                                          u8OdtIdx,
      /* !Comment: Index of element in ODT                                                                            */
      /* !Range:   0..(CCP_u8DAQ_NO_ELMS_PER_ODT-1)                                                                   */
      /*           (guaranted by caller)                                                                              */
      uint8                                          u8ElmIdx,
      /* !Comment: Address of element                                                                                 */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta,
      /* !Comment: Element size                                                                                       */
      /* !Range:   1, 2, 4                                                                                            */
      /*           (guaranted by caller)                                                                              */
      uint8                                          u8ElmSize
   )
   {
      /* !Range: 0..((254*7)-1)                                                                                       */
      uint16_least                                                            u16LocalFirstElmIdx;
      P2VAR(P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA), AUTOMATIC, CCP_APPL_DATA) ppu8LocalElmAdr;
      #if (CCP_coDAQ_ELM_SIZE_MAX != CCP_coDAQ_ELM_SIZE_MAX_8_BITS)
         P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)                               pu8LocalElmSize;
         uint8_least                                                          u8LocalNrOfElmUsed;
         uint8_least                                                          u8LocalIdx;
         uint8_least                                                          u8LocalElmToUpdIdx;
         P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)                               pu8LocalData;
      #endif


      u16LocalFirstElmIdx = ((uint16_least)CCP_kastrDaqListStatCfg[u8ListIdx].u8FirstPid + u8OdtIdx) * 7;
      ppu8LocalElmAdr     = &CCPUSR_apu8DaqListElmAdr[u16LocalFirstElmIdx];
      #if (CCP_coDAQ_ELM_SIZE_MAX == CCP_coDAQ_ELM_SIZE_MAX_8_BITS)
         *ppu8LocalElmAdr = (P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA))pkstrMta->u32Adr;
      #else
         pu8LocalElmSize = &CCPUSR_au8DaqListElmSize[u16LocalFirstElmIdx];

         /* Checks that the previous element is configured and not the following one */
         if (  (  (u8ElmIdx > 0)
               && (pu8LocalElmSize[u8ElmIdx - 1] == 0))
            || (  (u8ElmIdx < (CCP_u8DAQ_NO_ELMS_PER_ODT - 1))
               && (pu8LocalElmSize[u8ElmIdx + 1] != 0)))
         {
            return (CCP_udtCMD_STS_PRM_OUT_OF_RNG); /* Should be CCP_udtCMD_STS_DAQ_CFG (XCP 1.0) */
         }

         /* Checks that there is enough room to store the new data */
         u8LocalNrOfElmUsed = 0;
         if (u8ElmIdx != 0)
         {
            u8LocalIdx  = 0;
            do
            {
               u8LocalNrOfElmUsed += pu8LocalElmSize[u8LocalIdx];
               u8LocalIdx ++;
            }
            while (u8LocalIdx < u8ElmIdx);
         }
         if ((u8LocalNrOfElmUsed + u8ElmSize) > CCP_u8DAQ_NO_ELMS_PER_ODT)
         {
            return (CCP_udtCMD_STS_PRM_OUT_OF_RNG);
         }

         u8LocalElmToUpdIdx = u8LocalNrOfElmUsed;
         pu8LocalData       = (P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA))pkstrMta->u32Adr;

         ppu8LocalElmAdr[u8LocalElmToUpdIdx] = pu8LocalData;
         if (u8ElmSize != CCPUSR_U8_SIZE)
         {
            ppu8LocalElmAdr[u8LocalElmToUpdIdx + 1] = pu8LocalData + 1;
            if (u8ElmSize == CCPUSR_U32_SIZE)
            {
               ppu8LocalElmAdr[u8LocalElmToUpdIdx + 2] = pu8LocalData + 2;
               ppu8LocalElmAdr[u8LocalElmToUpdIdx + 3] = pu8LocalData + 3;
            }
         }
         pu8LocalElmSize[u8ElmIdx] = u8ElmSize;
      #endif /* (CCP_coDAQ_ELM_SIZE_MAX == CCP_coDAQ_ELM_SIZE_MAX_8_BITS) */
      return (CCP_udtCMD_STS_NO_ERR);
   }

   /*******************************************************************************************************************/
   /* !Description: Initialisation of the DAQ list transmission                                                       */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrDaqListTxMgrInit
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx,
      /* !Comment: First PID of the DAQ list                                                                          */
      /* !Range:   0..253                                                                                             */
      /*           (guaranted by caller)                                                                              */
      uint8 u8FirstPid,
      /* !Comment: Relative index within the DAQ list of the last ODT to send                                         */
      /* !Range:   0..(CCP_u8DAQ_NO_ODTS(u8ListIdx)-1)                                                                */
      /*           (guaranted by caller)                                                                              */
      uint8 u8OdtLstIdx
   )
   {
      uint8                                                                      u8LocalListPrio;
      P2VAR(CCPUSR_tstrDaqListData, AUTOMATIC, CCP_APPL_DATA)                    pstrLocalDaqListData;
      /* !Range: 0..((254*7)-1)                                                                                       */
      uint16_least                                                               u16LocalFirstElmIdx;
      /* !Range: 0..((254*7)-1)                                                                                       */
      #if (CCP_coDAQ_FILL_WHOLE_LIST == CCP_coACVD)
         P2VAR(P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA), AUTOMATIC, CCP_APPL_DATA) ppu8LocalElmAdr;
         P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)                                  pu8LocalBufDst;
         uint8_least                                                             u8LocalOdtIdx;
      #endif


      u8LocalListPrio = CCPUSR_vu8DaqListPrio;
      if (u8LocalListPrio > u8ListIdx)
      {
         CCPUSR_vu8DaqListPrio = u8ListIdx;
      }

      pstrLocalDaqListData = &CCPUSR_astrDaqListData[u8ListIdx];

      pstrLocalDaqListData->u8OdtLstIdx   = u8FirstPid + u8OdtLstIdx;
      pstrLocalDaqListData->u8OdtToTxIdx  = u8FirstPid;
      u16LocalFirstElmIdx                 = u8FirstPid * 7;
      pstrLocalDaqListData->u16ElmToTxIdx = (uint16)u16LocalFirstElmIdx;

      #if (CCP_coDAQ_FILL_WHOLE_LIST == CCP_coACVD)
         pu8LocalBufDst  = &CCPUSR_au8DaqListElmVal[u16LocalFirstElmIdx];
         ppu8LocalElmAdr = &CCPUSR_apu8DaqListElmAdr[u16LocalFirstElmIdx];

         for (u8LocalOdtIdx = 0; u8LocalOdtIdx <= u8OdtLstIdx; u8LocalOdtIdx++)
         {
            CCPUSR_vidCRIT_SECT_ENTER();
            *pu8LocalBufDst = *(*ppu8LocalElmAdr);
            pu8LocalBufDst++;
            ppu8LocalElmAdr++;
            *pu8LocalBufDst = *(*ppu8LocalElmAdr);
            pu8LocalBufDst++;
            ppu8LocalElmAdr++;
            *pu8LocalBufDst = *(*ppu8LocalElmAdr);
            pu8LocalBufDst++;
            ppu8LocalElmAdr++;
            *pu8LocalBufDst = *(*ppu8LocalElmAdr);
            pu8LocalBufDst++;
            ppu8LocalElmAdr++;
            *pu8LocalBufDst = *(*ppu8LocalElmAdr);
            pu8LocalBufDst++;
            ppu8LocalElmAdr++;
            *pu8LocalBufDst = *(*ppu8LocalElmAdr);
            pu8LocalBufDst++;
            ppu8LocalElmAdr++;
            *pu8LocalBufDst = *(*ppu8LocalElmAdr);
            pu8LocalBufDst++;
            ppu8LocalElmAdr++;
            CCPUSR_vidCRIT_SECT_EXIT();
         }
      #endif
   }

   /*******************************************************************************************************************/
   /* !Description: Send ODT(s) of the DAQ list                                                                       */
   /*******************************************************************************************************************/
   /* !Comment: Request to send the last ODT of the DAQ list has been done (TRUE) or not (FALSE)                      */
   FUNC(boolean, CCP_USR_CODE) CCP_bUsrDaqListTxMgr
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   )
   {
      uint8                                                                      u8LocalListPrio;
      P2VAR(CCPUSR_tstrDaqListData, AUTOMATIC, CCP_APPL_DATA)                    pstrLocalDaqListData;
      /* !Range: 0..((254*7)-1)                                                                                       */
      uint16_least                                                               u16LocalFirstElmIdx;
      CCP_tuniDaqMsgBuf                                                          uniLocalDaqBuf;
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)                                     pu8LocalBufDst;
      #if (CCP_coDAQ_FILL_WHOLE_LIST == CCP_coACVD)
         P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)                                  pu8LocalBufSrc;
      #else
         P2VAR(P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA), AUTOMATIC, CCP_APPL_DATA) ppu8LocalElmAdr;
      #endif

      u8LocalListPrio = CCPUSR_vu8DaqListPrio;
      if (u8LocalListPrio < u8ListIdx)
      {
         return(FALSE);
      }

      pstrLocalDaqListData = &CCPUSR_astrDaqListData[u8ListIdx];

      u16LocalFirstElmIdx = pstrLocalDaqListData->u16ElmToTxIdx;
      pstrLocalDaqListData->u16ElmToTxIdx += CCP_u8DAQ_NO_ELMS_PER_ODT;

      pu8LocalBufDst = &uniLocalDaqBuf.uniDaq.au8Prm[0];
      #if (CCP_coDAQ_FILL_WHOLE_LIST == CCP_coACVD)
         pu8LocalBufSrc = &CCPUSR_au8DaqListElmVal[u16LocalFirstElmIdx];

         *pu8LocalBufDst = *pu8LocalBufSrc;
         pu8LocalBufDst++;
         pu8LocalBufSrc++;
         *pu8LocalBufDst = *pu8LocalBufSrc;
         pu8LocalBufDst++;
         pu8LocalBufSrc++;
         *pu8LocalBufDst = *pu8LocalBufSrc;
         pu8LocalBufDst++;
         pu8LocalBufSrc++;
         *pu8LocalBufDst = *pu8LocalBufSrc;
         pu8LocalBufDst++;
         pu8LocalBufSrc++;
         *pu8LocalBufDst = *pu8LocalBufSrc;
         pu8LocalBufDst++;
         pu8LocalBufSrc++;
         *pu8LocalBufDst = *pu8LocalBufSrc;
         pu8LocalBufDst++;
         pu8LocalBufSrc++;
         *pu8LocalBufDst = *pu8LocalBufSrc;
      #else
         ppu8LocalElmAdr = &CCPUSR_apu8DaqListElmAdr[u16LocalFirstElmIdx];

         CCPUSR_vidCRIT_SECT_ENTER();
         *pu8LocalBufDst = *(*ppu8LocalElmAdr);
         pu8LocalBufDst++;
         ppu8LocalElmAdr++;
         *pu8LocalBufDst = *(*ppu8LocalElmAdr);
         pu8LocalBufDst++;
         ppu8LocalElmAdr++;
         *pu8LocalBufDst = *(*ppu8LocalElmAdr);
         pu8LocalBufDst++;
         ppu8LocalElmAdr++;
         *pu8LocalBufDst = *(*ppu8LocalElmAdr);
         pu8LocalBufDst++;
         ppu8LocalElmAdr++;
         *pu8LocalBufDst = *(*ppu8LocalElmAdr);
         pu8LocalBufDst++;
         ppu8LocalElmAdr++;
         *pu8LocalBufDst = *(*ppu8LocalElmAdr);
         pu8LocalBufDst++;
         ppu8LocalElmAdr++;
         *pu8LocalBufDst = *(*ppu8LocalElmAdr);
         CCPUSR_vidCRIT_SECT_EXIT();
      #endif

      uniLocalDaqBuf.uniDaq.u8PktId = pstrLocalDaqListData->u8OdtToTxIdx++;
      CCPUSR_vidSendDaqMessage(u8ListIdx, &uniLocalDaqBuf.au8Data[0]);

      if (pstrLocalDaqListData->u8OdtToTxIdx > pstrLocalDaqListData->u8OdtLstIdx)
      {
         CCPUSR_vidDaqListSrchNextActvDaqList(u8ListIdx);
         return(TRUE);
      }
      else
      {
         return(FALSE);
      }
   }

   /*******************************************************************************************************************/
   /* !Description: Signal that the DAQ list has been stopped                                                         */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrDaqListStopd
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   )
   {
      CCPUSR_astrDaqListData[u8ListIdx].u8OdtToTxIdx = UINT8_MAX;

      CCPUSR_vidDaqListSrchNextActvDaqList(u8ListIdx);
   }

   /*******************************************************************************************************************/
   /* !Description: Search for next active daqlist to update the priority and continue ODTs transmission              */
   /*******************************************************************************************************************/
   static FUNC(void, CCP_USR_CODE) CCPUSR_vidDaqListSrchNextActvDaqList
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   )
   {
      uint8_least                                             u8LocalListIdx;
      P2VAR(CCPUSR_tstrDaqListData, AUTOMATIC, CCP_APPL_DATA) pstrLocalDaqListData;


      CCPUSR_vu8DaqListPrio = UINT8_MAX;
      for (u8LocalListIdx = (u8ListIdx + 1); u8LocalListIdx < CCP_u8DAQ_NO_LISTS; u8LocalListIdx++)
      {
         pstrLocalDaqListData = &CCPUSR_astrDaqListData[u8LocalListIdx];
         if (pstrLocalDaqListData->u8OdtToTxIdx <= pstrLocalDaqListData->u8OdtLstIdx)
         {
            CCPUSR_vu8DaqListPrio = (uint8)u8LocalListIdx;
            CCP_vidDaqListTxMgr((uint8)u8LocalListIdx);
            break;
         }
      }
   }

   /*******************************************************************************************************************/
   /* !Description: Signal an overrun of the DAQ list                                                                 */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrDaqListTxOvrn
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   )
   {
      CCP_tuniDaqMsgBuf uniLocalDaqBuf;


      uniLocalDaqBuf.au8Data[0] = CCP_u8PID_EVT_MSG;
      uniLocalDaqBuf.au8Data[1] = (uint8)CCP_udtCMD_STS_DAQ_PROCESSOR_OVLD;
      uniLocalDaqBuf.au8Data[2] = u8ListIdx;
      CCPUSR_vidSendDaqMessage(u8ListIdx, &uniLocalDaqBuf.au8Data[0]);
   }

   #if (CCP_coDAQ_RESU_FEATURE == CCP_coACVD)
      /****************************************************************************************************************/
      /* !Description: Request to store DAQ list configuration                                                        */
      /****************************************************************************************************************/
      FUNC(void, CCP_USR_CODE) CCP_vidUsrNtfyDaqResuSttChgd
      (
         /* !Comment: State of DAQ Resume bit (TRUE: request to store DAQ list configuration)                         */
         boolean bDaqResuStt
      )
      {
         #error Not implemented
      }
   #endif /* (CCP_coDAQ_RESU_FEATURE == CCP_coACVD) */
#endif /* (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */

#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
