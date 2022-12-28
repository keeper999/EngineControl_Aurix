/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCPUSR                                                                                          */
/* !Description     : User functions definition                                                                       */
/*                                                                                                                    */
/* !File            : CCPUSR.c                                                                                        */
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
#include "DEVHAL.h"
#include "IfxScu_reg.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/* !Comment: Checksum size */
#define CCPUSR_u8CKS_SIZE 2

#define CCPUSR_DFLT_CALIB_PAGE_RAM_ADDR (CCPUSR_DFLT_CALIB_PAGE_ADDR + CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_RAM \
                                         - CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_ROM)

/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/
#define CCP_START_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"

uint8 CCPUSR_enuCalStoreStatus;
uint32 CCPUSR_u32ActivePageAddr;

#define CCP_STOP_SEC_VAR_UNSPECIFIED
#include "Ccp_MemMap.h"

/**********************************************************************************************************************/
/* INTERNAL FUNCTIONS DEFINITION                                                                                      */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : CCPUSR_udtMemoryControlWriteRight                                                                   */
/* !Description : Check if Write access is allowed for the memory range                                               */
/**********************************************************************************************************************/
static CCP_tudtCmdSts CCPUSR_udtMemoryControlWriteRight
(
   P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8SrcAddr,
   uint8                                  u8SizeOfData
)
{
   CCP_tudtCmdSts udtlocalStatus;
   uint16_least   u16LocalLoop;

   udtlocalStatus = CCP_udtCMD_STS_ACS_DENIED;

   for (u16LocalLoop = 0; u16LocalLoop < 2 * CCPUSR_NB_WRITABLE_ZONE; u16LocalLoop += 2)
   {
      if (  ((uint32)pu8SrcAddr >= CCPUSR_kau32WritableMemoryZone[u16LocalLoop])
         && ((uint32)pu8SrcAddr <= (CCPUSR_kau32WritableMemoryZone[u16LocalLoop + 1] - u8SizeOfData)))
      {
         udtlocalStatus = CCP_udtCMD_STS_NO_ERR;
      }
   }

   return (udtlocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : CCPUSR_udtMemoryControlReadRight                                                                    */
/* !Description : Check if read access is allowed for the memory range                                                */
/**********************************************************************************************************************/
static CCP_tudtCmdSts CCPUSR_udtMemoryControlReadRight
(
   P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8SrcAddr,
   uint8                                  u8SizeOfData
)
{
   CCP_tudtCmdSts udtlocalStatus;
   uint16_least   u16LocalLoop;


   udtlocalStatus = CCP_udtCMD_STS_ACS_DENIED;

   for (u16LocalLoop = 0; u16LocalLoop < 2 * CCPUSR_NB_READ_ONLY_ZONE; u16LocalLoop += 2)
   {
      if (  ((uint32)pu8SrcAddr >= CCPUSR_kau32ReadOnlyMemoryZone[u16LocalLoop])
         && ((uint32)pu8SrcAddr <= (CCPUSR_kau32ReadOnlyMemoryZone[u16LocalLoop + 1] - u8SizeOfData)))
      {
         udtlocalStatus = CCP_udtCMD_STS_NO_ERR;
      }
   }
   
   /* If not found check in writeable memory -> writeable memory has read allowed access right too */
   if (udtlocalStatus != CCP_udtCMD_STS_NO_ERR)
   {
      udtlocalStatus = CCPUSR_udtMemoryControlWriteRight(pu8SrcAddr, u8SizeOfData);
   }
   
   return (udtlocalStatus);
}

#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

/**********************************************************************************************************************/
/* !Description: CCP user initialisation                                                                              */
/**********************************************************************************************************************/
FUNC(void, CCP_USR_CODE) CCP_vidUsrIni(void)
{
#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   CCPUSR_vidDaqListIni();
#endif /* (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */
   CCPUSR_enuCalStoreStatus = CCPUSR_CAL_STORE_INIT;

   if (DEVHAL_bCheckEmulCard() == TRUE)
   {
      CCPUSR_u32ActivePageAddr = CCPUSR_DFLT_CALIB_PAGE_RAM_ADDR;
   }
   else
   {
      CCPUSR_u32ActivePageAddr = CCPUSR_DFLT_CALIB_PAGE_ADDR;
   }
}

/**********************************************************************************************************************/
/* !Description: Notify end of session                                                                                */
/**********************************************************************************************************************/
FUNC(void, CCP_USR_CODE) CCP_vidUsrNtfySsnTrmd(void)
{
}

#if (CCP_coSLAVE_DEV_ID_USR == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Get device identification location and length                                                     */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrGetDevId
   (
      /* !Comment: Pointer to a buffer to store the identifier location                                               */
      P2VAR(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pstrMta,
      /* !Comment: Pointer to a buffer to store the identifier length                                                 */
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)       pu8Len
   )
   {
      #error Not implemented
   }
#endif /* (CCP_coSLAVE_DEV_ID_USR == CCP_coACVD) */

#if (CCP_coSLAVE_STN_ADR_USR == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: check the received station address                                                                */
   /*******************************************************************************************************************/
   /* !Comment: check the received station address valid(TRUE) or not(FALSE)                                          */
   FUNC(boolean, CCP_USR_CODE) CCP_bUsrStnAdrChk
   (
      /* !Comment: Service requesting to check the Station Address                                                    */
      /* !Range  : CCP_u8USR_SRV_CNCT, CCP_u8USR_SRV_DCNCT, CCP_u8USR_SRV_TEST (guaranted by caller)                  */
      uint8 u8UsrSrv,
      /* !Comment: the station address received                                                                       */
      uint16 u16StnAdr
   )
   {
      #error Not implemented
   }
#endif /* (CCP_coSLAVE_STN_ADR_USR == CCP_coACVD) */

/**********************************************************************************************************************/
/* !Description: Read data at a specified location                                                                    */
/**********************************************************************************************************************/
/* !Comment: Status of the request                                                                                    */
/* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_ACS_DENIED                                                         */
FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrReadMem
(
   /* !Comment: Service requesting to read data                                                                       */
   /* !Range  : CCP_u8USR_SRV_SHO_UPLD, CCP_u8USR_SRV_UPLD                                                            */
   /*           (guaranted by caller)                                                                                 */
   uint8                                          u8UsrSrv,
   /* !Comment: Location of data                                                                                      */
   P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta,
   /* !Comment: Pointer to a buffer to store the data                                                                 */
   P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)         pu8Data,
   /* !Comment: Size of the data to read                                                                              */
   /* !Unit   : Byte                                                                                                  */
   uint8                                          u8DataSize
)
{
   uint8_least                            u8LocalIdx;
   P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8Src;
   CCP_tudtCmdSts                         udtLocalStatus;


   COMPILER_UNUSED_PARAMETER(u8UsrSrv);

   pu8Src = (P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA))pkstrMta->u32Adr;

   udtLocalStatus = CCPUSR_udtMemoryControlReadRight(pu8Src, u8DataSize);
   if (udtLocalStatus == CCP_udtCMD_STS_NO_ERR)
   {
      for (u8LocalIdx = 0; u8LocalIdx < u8DataSize; u8LocalIdx++)
      {
         *pu8Data = *pu8Src;
         pu8Data++;
         pu8Src++;
      }
   }
   return(udtLocalStatus);
}

#if (  (CCP_coSRV_UPLD_ASYNC_RESP == CCP_coACVD) \
    || (CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP == CCP_coACVD))
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data upload                                                       */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrReadMemSts
   (
      /* !Comment: Pointer to a buffer to store the data                                                              */
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8Data
   )
   {
      #error Not implemented
   }
#endif /* (  (CCP_coSRV_UPLD_ASYNC_RESP == CCP_coACVD)          */
       /* || (CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP == CCP_coACVD)) */

/**********************************************************************************************************************/
/* !Description: Writes data at a specified location                                                                  */
/**********************************************************************************************************************/
/* !Comment: Status of the request                                                                                    */
/* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_ACS_DENIED                                                         */
FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrWrMem
(
   /* !Comment: Service requesting to write data                                                                      */
   /* !Range  : CCP_u8USR_SRV_DNLD6, CCP_u8USR_SRV_DNLD                                                               */
   /*           (guaranted by caller)                                                                                 */
   uint8                                          u8UsrSrv,
   /* !Comment: Destination of data                                                                                   */
   P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta,
   /* !Comment: Pointer to the data                                                                                   */
   P2CONST(uint8, AUTOMATIC, CCP_APPL_DATA)       pku8Data,
   /* !Comment: Size of the data to write                                                                             */
   /* !Unit   : Byte                                                                                                  */
   uint8                                          u8DataSize
)
{
   uint32                                 u32LocAddr;
   uint8_least                            u8LocIdx;
   P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocDst;
   CCP_tudtCmdSts                         udtLocalStatus;


   COMPILER_UNUSED_PARAMETER(u8UsrSrv);

   u32LocAddr = pkstrMta->u32Adr;
   
   /* Allow the download only if Calibration are in RAM */
   /* CCPUSR_u32ActivePageAddr can becomes = to CCPUSR_DFLT_CALIB_PAGE_RAM_ADDR on devaid only */
   if (CCPUSR_u32ActivePageAddr == CCPUSR_DFLT_CALIB_PAGE_RAM_ADDR)
   {
      /* TODO: For best maintainability, address shall be provided by linker */
      if (  (u32LocAddr >= (uint32)CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_ROM)
         && (u32LocAddr < ((uint32)CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_ROM + CCPUSR_CALIBRATION_SIZE)) )
      {
         u32LocAddr = u32LocAddr + (uint32)( CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_RAM
                                           - CCPUSR_START_ADDRESS_OF_CALIBRATION_IN_ROM);
      }
   }

   pu8LocDst = (P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA))u32LocAddr;
   
   udtLocalStatus = CCPUSR_udtMemoryControlWriteRight(pu8LocDst, u8DataSize);
   if (udtLocalStatus == CCP_udtCMD_STS_NO_ERR)
   {
      for (u8LocIdx = 0; u8LocIdx < u8DataSize; u8LocIdx++)
      {
         *pu8LocDst = *pku8Data;
         pku8Data++;
         pu8LocDst++;
      }
      /* Data cache shall be invalidated for the 3 cores  */
      DEVHAL_vidInvalidateDataCache();
   }
   return(udtLocalStatus);
}

#if (  (CCP_coSRV_DNLD_ASYNC_RESP == CCP_coACVD) \
    || (CCP_coOPT_SRV_DNLD6_ASYNC_RESP == CCP_coACVD))
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data download                                                     */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrWrMemSts(void)
   {
      #error Not implemented
   }
#endif /* (  (CCP_coSRV_DNLD_ASYNC_RESP == CCP_coACVD)       */
       /* || (CCP_coOPT_SRV_DNLD6_ASYNC_RESP == CCP_coACVD)) */

#if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
   #if (CCP_coCAL_STORE_FEATURE == CCP_coACVD)
      /****************************************************************************************************************/
      /* !Description: Request to store calibration                                                                   */
      /****************************************************************************************************************/
      FUNC(void, CCP_USR_CODE) CCP_vidUsrNtfyCalStoreSttChgd
      (
         /* !Comment: State of Calibration Store bit (TRUE: request to store calibrations)                            */
         boolean bCalStoreStt
      )
      {
         if (bCalStoreStt == TRUE)
         {
            CCPUSR_enuCalStoreStatus = CCPUSR_CAL_STORE_REQUESTED;
         }
         else
         {
            CCPUSR_enuCalStoreStatus = CCPUSR_CAL_STORE_INIT;
         }
      }
   #endif /* (CCP_coCAL_STORE_FEATURE == CCP_coACVD) */

   #if (CCP_coADDL_STS == CCP_coACVD)
      /****************************************************************************************************************/
      /* !Description: Read additional session status information                                                     */
      /****************************************************************************************************************/
      FUNC(void, CCP_USR_CODE) CCP_vidUsrGetAddlSts
      (
         /* !Comment: Pointer to a buffer to store the status qualifier                                               */
         P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8StsQualifier,
         /* !Comment: Pointer to a 3 bytes buffer to store the information                                            */
         P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8Sts
      )
      {
         #error Not implemented
      }
   #endif /* (CCP_coADDL_STS == CCP_coACVD) */
#endif /* (CCP_coOPT_SRV_SSN_STS == CCP_coACVD) */

#if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request of a seed to unlock a resource                                                            */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrGetSeed
   (
      /* !Comment: Resource identifier                                                                                */
      /* !Range  : CCP_u8CAL_RES, CCP_u8DAQ_RES, CCP_u8PGM_RES                                                        */
      /*           (guaranted by caller)                                                                              */
      uint8 u8Res,
      /* !Comment: Pointer to a buffer to store the seed                                                              */
      uint8 au8Key[4]
   )
   {
      #error Not implemented
   }

   /*******************************************************************************************************************/
   /* !Description: Check key to unlock a resource                                                                    */
   /*******************************************************************************************************************/
   /* !Comment: Status of the check                                                                                   */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_ACS_LOCKD                                                       */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrChkKey
   (
      /* !Comment: Resource identifier                                                                                */
      /* !Range  : CCP_u8CAL_RES, CCP_u8DAQ_RES, CCP_u8PGM_RES                                                        */
      /*           (guaranted by caller)                                                                              */
      uint8       u8Res,
      /* !Comment: Key to check                                                                                       */
      const uint8 aku8Key[6]
   )
   {
      #error Not implemented
   }
#endif /* (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD) */

#if (CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Select a calibration page                                                                         */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_ACS_DENIED                                                      */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrSelCalPage
   (
      /* !Comment: Location of calibration page                                                                       */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta
   )
   {
      CCP_tudtCmdSts udtReturnCode;
      
      udtReturnCode = CCP_udtCMD_STS_ACS_DENIED;
      if (DEVHAL_bCheckEmulCard() == TRUE)
      {
         if (pkstrMta->u32Adr == CCPUSR_DFLT_CALIB_PAGE_ADDR)
         {
            /* request Working page in FLASH */
            DEVHAL_vidDisableOverlay();
            CCPUSR_u32ActivePageAddr = CCPUSR_DFLT_CALIB_PAGE_ADDR;
            udtReturnCode = CCP_udtCMD_STS_NO_ERR;
         }
         else
         {
            if (pkstrMta->u32Adr == CCPUSR_DFLT_CALIB_PAGE_RAM_ADDR)
            {
               /* request Working page in RAM */
               DEVHAL_vidEnableOverlay();
               CCPUSR_u32ActivePageAddr = CCPUSR_DFLT_CALIB_PAGE_RAM_ADDR;
               udtReturnCode = CCP_udtCMD_STS_NO_ERR;
            }
            /* else the page address is not good and we answer access denied */
         }
      }
      return(udtReturnCode);
   }

   /*******************************************************************************************************************/
   /* !Description: Get start address of current active calibration page                                              */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrGetAcvCalPage
   (
      /* !Comment: Pointer to a buffer to store the page location                                                     */
      P2VAR(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pstrMta
   )
   {

      pstrMta->u32Adr = CCPUSR_u32ActivePageAddr;
      pstrMta->u8Extn = CCPUSR_DFLT_CALIB_PAGE_EXTN;
   }
#endif /* (CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD) */

#if (CCP_coOPT_SRV_CKS == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request to build checksum                                                                         */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED                             */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrBldCks
   (
      /* !Comment: Start address for checksum calculation                                                             */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta,
      /* !Comment: Block size                                                                                         */
      /* !Unit   : Byte                                                                                               */
      uint32                                         u32BlkSize,
      /* !Comment: Pointer to a buffer to store the checksum size                                                     */
      /* !Range  : Checksum size between 1 and 4                                                                      */
      /* !Unit   : Byte                                                                                               */
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)         pu8CksSize,
      /* !Comment: Pointer to a buffer to store the calculated checksum (buffer is aligned on a 4-byte boundary)      */
      uint8                                          au8CksData[4]
   )
   {
      uint32                                  u32LocalIdx;
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA)  pu8Data;
      uint16                                  u16LocalChecksum;
      P2VAR(uint16, AUTOMATIC, CCP_APPL_DATA) pu16Cks;


      u16LocalChecksum = 0;
      pu8Data          = (P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA))pkstrMta->u32Adr;
      for (u32LocalIdx = 0; u32LocalIdx < u32BlkSize; u32LocalIdx++)
      {
         u16LocalChecksum += *pu8Data;
         pu8Data++;
      }
      pu16Cks     = (P2VAR(uint16, AUTOMATIC, CCP_APPL_DATA))&au8CksData[0];
      *pu16Cks    = u16LocalChecksum;
      *pu8CksSize = CCPUSR_u8CKS_SIZE;
      return (CCP_udtCMD_STS_NO_ERR);
   }
#endif /* (CCP_coOPT_SRV_CKS == CCP_coACVD) */

#if (CCP_coOPT_SRV_CKS_ASYNC_RESP == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request status and checksum for asynchronous checksum                                             */
   /*               build                                                                                             */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrBldCksSts
   (
      /* !Comment: Pointer to a buffer to store the checksum size                                                     */
      /* !Range  : Checksum size between 1 and 4                                                                      */
      /* !Unit   : Byte                                                                                               */
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8CksSize,
      /* !Comment: Pointer to a buffer to store the calculated checksum (buffer is aligned on a 4-byte boundary)      */
      uint8                                  au8CksData[4]
   )
   {
      #error Not implemented
   }
#endif /* (CCP_coOPT_SRV_CKS_ASYNC_RESP == CCP_coACVD) */

#if (CCP_coOPT_SRV_MOVE == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request to move data                                                                              */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED                             */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrMove
   (
      /* !Comment: Source address                                                                                     */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMtaSrc,
      /* !Comment: Destination address                                                                                */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMtaDst,
      /* !Comment: Block size                                                                                         */
      /* !Unit   : Byte                                                                                               */
      uint32                                         u32BlkSize
   )
   {
      #error Not implemented
   }
#endif /* (CCP_coOPT_SRV_MOVE == CCP_coACVD) */

#if (CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data moving                                                       */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrMoveSts(void)
   {
      #error Not implemented
   }
#endif /* (CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD) */

#if (CCP_coOPT_SRV_PROG == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request to clear non-volatile memory                                                              */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED                             */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrClrMem
   (
      /* !Comment: Start address of block to erase                                                                    */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta,
      /* !Comment: Block size                                                                                         */
      /* !Unit   : Byte                                                                                               */
      uint32                                         u32BlkSize
   )
   {
      #error Not implemented
   }

   /*******************************************************************************************************************/
   /* !Description: Request to write data in non-volatile memory                                                      */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED                             */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrProg
   (
      /* !Comment: Service requesting to write data                                                                   */
      /* !Range  : CCP_u8USR_SRV_PROG6, CCP_u8USR_SRV_PROG                                                            */
      /*           (guaranted by caller)                                                                              */
      uint8                                          u8UsrSrv,
      /* !Comment: Destination address                                                                                */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta,
      /* !Comment: Pointer to the data                                                                                */
      P2CONST(uint8, AUTOMATIC, CCP_APPL_DATA)       pku8Data,
      /* !Comment: Data size                                                                                          */
      /* !Unit   : Byte                                                                                               */
      uint8                                          u8DataSize
   )
   {
      #error Not implemented
   }
#endif /* (CCP_coOPT_SRV_PROG == CCP_coACVD) */

#if (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data write in non-volatile memory                                 */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrProgSts(void)
   {
      #error Not implemented
   }
#endif /* (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD) */

#if (CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data clear of non-volatile memory                                 */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrClrMemSts(void)
   {
      #error Not implemented
   }
#endif /* (CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD) */

/**********************************************************************************************************************/
/* !Description: CCP user main function                                                                               */
/**********************************************************************************************************************/
FUNC(void, CCP_USR_CODE) CCP_vidMainFunction(void)
{
   if (DEVHAL_bCheckEmulCard() == TRUE)
   {
      if (CCPUSR_enuCalStoreStatus == CCPUSR_CAL_STORE_WAIT_CONDITION)
      {
         if (DEVHAL_udtCheckEngineState() == E_OK)
         {
            CCPUSR_enuCalStoreStatus = CCPUSR_CAL_STORE_CONDITION_OK;
            DEVHAL_vidCopyCalibrationInFlash();
         }
      }
   }
}

#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
