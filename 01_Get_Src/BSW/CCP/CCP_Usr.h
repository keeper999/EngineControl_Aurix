/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP                                                                                             */
/* !Description     : User functions declaration                                                                      */
/*                                                                                                                    */
/* !File            : CCP_Usr.h                                                                                       */
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

#ifndef CCP_USR_H
#define CCP_USR_H

#include "CCP_Typ.h"
#include "CCP_Cfg.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coACVD
   #error CCP_coACVD not defined
#endif
#ifndef CCP_coSLAVE_DEV_ID_USR
   #error CCP_coSLAVE_DEV_ID_USR not defined
#endif
#ifndef CCP_coSLAVE_STN_ADR_USR
   #error CCP_coSLAVE_STN_ADR_USR not defined
#endif
#ifndef CCP_coSRV_UPLD_ASYNC_RESP
   #error CCP_coSRV_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP
   #error CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coSRV_DNLD_ASYNC_RESP
   #error CCP_coSRV_DNLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DNLD6_ASYNC_RESP
   #error CCP_coOPT_SRV_DNLD6_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_SSN_STS
   #error CCP_coOPT_SRV_SSN_STS not defined
#endif
#ifndef CCP_coCAL_STORE_FEATURE
   #error CCP_coCAL_STORE_FEATURE not defined
#endif
#ifndef CCP_coADDL_STS
   #error CCP_coADDL_STS not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coOPT_SRV_CAL_PAGE
   #error CCP_coOPT_SRV_CAL_PAGE not defined
#endif
#ifndef CCP_coOPT_SRV_CKS
   #error CCP_coOPT_SRV_CKS not defined
#endif
#ifndef CCP_coOPT_SRV_CKS_ASYNC_RESP
   #error CCP_coOPT_SRV_CKS_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_MOVE
   #error CCP_coOPT_SRV_MOVE not defined
#endif
#ifndef CCP_coOPT_SRV_MOVE_ASYNC_RESP
   #error CCP_coOPT_SRV_MOVE_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_PROG
   #error CCP_coOPT_SRV_PROG not defined
#endif
#ifndef CCP_coOPT_SRV_PROG_ASYNC_RESP
   #error CCP_coOPT_SRV_PROG_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP
   #error CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif
#ifndef CCP_coDAQ_DYN_CAN_ID
   #error CCP_coDAQ_DYN_CAN_ID not defined
#endif
#ifndef CCP_coDAQ_RESU_FEATURE
   #error CCP_coDAQ_RESU_FEATURE not defined
#endif

/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/
/* !MComment: Identifier of services calling a common callback                                                        */
#define CCP_u8USR_SRV_DNLD     0
#define CCP_u8USR_SRV_DNLD6    1
#define CCP_u8USR_SRV_UPLD     2
#define CCP_u8USR_SRV_SHO_UPLD 3
#define CCP_u8USR_SRV_PROG     4
#define CCP_u8USR_SRV_PROG6    5
#define CCP_u8USR_SRV_CNCT     6
#define CCP_u8USR_SRV_DCNCT    7
#define CCP_u8USR_SRV_TEST     8


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/**********************************************************************************************************************/
/* !Description: CCP user initialisation                                                                              */
/**********************************************************************************************************************/
FUNC(void, CCP_USR_CODE) CCP_vidUsrIni(void);

/**********************************************************************************************************************/
/* !Description: Copy received command message into "au8Data"                                                         */
/**********************************************************************************************************************/
FUNC(void, CCP_USR_CODE) CCP_vidUsrRxCmd
(
   /* !Comment: Buffer to fill with command message                                                                   */
   uint8 au8Data[8]
);

/**********************************************************************************************************************/
/* !Description: Send command response                                                                                */
/**********************************************************************************************************************/
FUNC(void, CCP_USR_CODE) CCP_vidUsrTxCmdResp
(
   /* !Comment: Buffer containing message to send                                                                     */
   const uint8 aku8Data[8]
);

/**********************************************************************************************************************/
/* !Description: Notify end of session                                                                                */
/**********************************************************************************************************************/
FUNC(void, CCP_USR_CODE) CCP_vidUsrNtfySsnTrmd(void);

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
   );
#endif /* (CCP_coSLAVE_DEV_ID_USR == CCP_coACVD) */

#if (CCP_coSLAVE_STN_ADR_USR == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: check the received station address                                                                */
   /*******************************************************************************************************************/
   /* !Comment: check the received station address valid(TRUE) or not(FALSE)                                          */
   FUNC(boolean, CCP_USR_CODE) CCP_bUsrStnAdrChk
   (
      /* !Comment: Service requesting to check the Station Address                                                    */
      /* !Range  : CCP_u8USR_SRV_CNCT, CCP_u8USR_SRV_DCNCT, CCP_u8USR_SRV_TEST(guaranted by caller)                   */
      uint8 u8UsrSrv,
      /* !Comment: the station address received                                                                       */
      uint16 u16StnAdr
   );
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
);

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
   );
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
);

#if (  (CCP_coSRV_DNLD_ASYNC_RESP == CCP_coACVD) \
    || (CCP_coOPT_SRV_DNLD6_ASYNC_RESP == CCP_coACVD))
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data download                                                     */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrWrMemSts(void);
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
      );
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
      );
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
   );

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
   );
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
   );

   /*******************************************************************************************************************/
   /* !Description: Get start address of current active calibration page                                              */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrGetAcvCalPage
   (
      /* !Comment: Pointer to a buffer to store the page location                                                     */
      P2VAR(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pstrMta
   );
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
   );
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
   );
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
   );
#endif /* (CCP_coOPT_SRV_MOVE == CCP_coACVD) */

#if (CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data moving                                                       */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrMoveSts(void);
#endif /* (CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD) */

#if (CCP_coOPT_SRV_PROG == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request to clear non-volatile memory                                                              */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED                             */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrClrNVMem
   (
      /* !Comment: Start address of block to erase                                                                    */
      P2CONST(CCP_tstrMta, AUTOMATIC, CCP_APPL_DATA) pkstrMta,
      /* !Comment: Block size                                                                                         */
      /* !Unit   : Byte                                                                                               */
      uint32                                         u32BlkSize
   );

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
   );
#endif /* (CCP_coOPT_SRV_PROG == CCP_coACVD) */

#if (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data write in non-volatile memory                                 */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrProgSts(void);
#endif /* (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD) */

#if (CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD)
   /*******************************************************************************************************************/
   /* !Description: Request status for asynchronous data clear of non-volatile memory                                 */
   /*******************************************************************************************************************/
   /* !Comment: Status of the request                                                                                 */
   /* !Range  : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                        */
   FUNC(CCP_tudtCmdSts, CCP_USR_CODE) CCP_udtUsrClrMemSts(void);
#endif /* (CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD) */

#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
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
      );
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
   );

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
   );

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
   );

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
   );

   /*******************************************************************************************************************/
   /* !Description: Signal that the DAQ list has been stopped                                                         */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrDaqListStopd
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   );

   /*******************************************************************************************************************/
   /* !Description: Signal an overrun of the DAQ list                                                                 */
   /*******************************************************************************************************************/
   FUNC(void, CCP_USR_CODE) CCP_vidUsrDaqListTxOvrn
   (
      /* !Comment: DAQ list index                                                                                     */
      /* !Range:   0..(CCP_u8DAQ_NO_LISTS-1)                                                                          */
      /*           (guaranted by caller)                                                                              */
      uint8 u8ListIdx
   );

   #if (CCP_coDAQ_RESU_FEATURE == CCP_coACVD)
      /****************************************************************************************************************/
      /* !Description: Request to store DAQ list configuration                                                        */
      /****************************************************************************************************************/
      FUNC(void, CCP_USR_CODE) CCP_vidUsrNtfyDaqResuSttChgd
      (
         /* !Comment: State of DAQ Resume bit (TRUE: request to store DAQ list configuration)                         */
         boolean bDaqResuStt
      );
   #endif /* (CCP_coDAQ_RESU_FEATURE == CCP_coACVD) */
#endif /* (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

#endif /* CCP_USR_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
