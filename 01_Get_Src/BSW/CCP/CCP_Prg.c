/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_PRG                                                                                         */
/* !Description     : CCP services for non-volatile memory programming                                                */
/*                                                                                                                    */
/* !File            : CCP_Prg.c                                                                                       */
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
/* 1 / CCP_udtProg                                                                                                    */
/* 2 / CCP_udtProgAsyncResp                                                                                           */
/* 3 / CCP_udtProg6                                                                                                   */
/* 4 / CCP_udtProg6AsyncResp                                                                                          */
/* 5 / CCP_udtClrMem                                                                                                  */
/* 6 / CCP_udtClrMemAsyncResp                                                                                         */
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
#ifndef CCP_coOPT_SRV_PROG
   #error CCP_coOPT_SRV_PROG not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coOPT_SRV_PROG_ASYNC_RESP
   #error CCP_coOPT_SRV_PROG_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP
   #error CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP not defined
#endif

/**********************************************************************************************************************/
/* FUNCTIONS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtProg                                                                                         */
/*                                                                                                                    */
/* !Description : Program data in non-volatile memory at address specified by a previous call to "set_mta".           */
/*                The number of data can be between 1 and 5.                                                          */
/*               The data block of the specified length (size) contained in                                           */
/*               the CRO will be programmed into non-volatile memory (FLASH,                                          */
/*               EEPROM), starting at current MTA0. The MTA0 pointer will be                                          */
/*               post-incremented by the value of 'size'.                                                             */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = PROGRAM 0x18                                               */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Size of data block to follow                                              */
/*                                          in bytes                                                                  */
/*               3..7        bytes          Data to be programmed max. 5 bytes                                        */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           MTA0 extension address                                                    */
/*                                          (after post-increment)                                                    */
/*               4..7        bytes          MTA0 address(after post-increment)                                        */
/*                                                                                                                    */
/* !Number      : 1                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_RESP_PND,  */
/*            CCP_udtCMD_STS_ACS_DENIED                                                                               */
#if (CCP_coOPT_SRV_PROG == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProg(void)
   {
      uint8                                  u8LocalDataSize;
      CCP_tudtCmdSts                         udtLocalCmdSts;
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8PGM_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      u8LocalDataSize = CCP_uniBuf.uniCmd.strProg.u8DataSize;
      if (u8LocalDataSize <= CCP_u8PROG_MAX_DA_SIZE)
      {
         pu8LocalData   = &CCP_uniBuf.uniCmd.strProg.au8Data[0];
         udtLocalCmdSts = CCP_udtUsrProg(CCP_u8USR_SRV_PROG, &CCP_astrMta[0], pu8LocalData, u8LocalDataSize);

         CCP_astrMta[0].u32Adr += u8LocalDataSize;

         if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
         {
            CCP_uniBuf.uniAck.strProg.u32Adr    = CCP_astrMta[0].u32Adr;
            CCP_uniBuf.uniAck.strProg.u8AdrExtn = CCP_astrMta[0].u8Extn;
         }
         return(udtLocalCmdSts);
      }
      return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
   }
#endif /* CCP_coOPT_SRV_PROG == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtProgAsyncResp                                                                                */
/*                                                                                                                    */
/* !Description : Asynchronous response to program service                                                            */
/*                this background routine to Program 1-5 bytes data                                                   */
/*                and send the response to the Program command.                                                       */
/* !Number      : 2                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProgAsyncResp(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrProgSts();
      if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
      {
         CCP_uniBuf.uniAck.strProg.u32Adr    = CCP_astrMta[0].u32Adr;
         CCP_uniBuf.uniAck.strProg.u8AdrExtn = CCP_astrMta[0].u8Extn;
      }
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtProg6                                                                                        */
/*                                                                                                                    */
/* !Description : Program data in non-volatile memory at address specified by a previous call to "set_mta".           */
/*                The number of data is 6.                                                                            */
/*                                                                                                                    */
/*               The data block of the length (size) of 6 bytes contained in                                          */
/*               the CRO will be programmed into non-volatile memory (FLASH,                                          */
/*               EEPROM), starting at current MTA0. The MTA0 pointer will be                                          */
/*               post-incremented by 6.                                                                               */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = PROGRAM_6 0x22                                             */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Size of data block to follow                                              */
/*                                          in bytes                                                                  */
/*               2..7        bytes          Data to be programmed (6 bytes)                                           */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           MTA0 extension address                                                    */
/*                                          (after post-increment)                                                    */
/*               4..7        bytes          MTA0 address(after post-increment)                                        */
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
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED       */
#if (CCP_coOPT_SRV_PROG == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProg6(void)
   {
      CCP_tudtCmdSts                         udtLocalCmdSts;
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8PGM_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      pu8LocalData   = &CCP_uniBuf.uniCmd.strProg6.au8Data[0];
      udtLocalCmdSts = CCP_udtUsrProg(CCP_u8USR_SRV_PROG6, &CCP_astrMta[0], pu8LocalData, CCP_u8PROG6_DA_SIZE);

      CCP_astrMta[0].u32Adr += CCP_u8PROG6_DA_SIZE;

      if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
      {
         CCP_uniBuf.uniAck.strProg6.u32Adr    = CCP_astrMta[0].u32Adr;
         CCP_uniBuf.uniAck.strProg6.u8AdrExtn = CCP_astrMta[0].u8Extn;
      }
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_PROG == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtProg6AsyncResp                                                                               */
/*                                                                                                                    */
/* !Description : Asynchronous response to program_6 service                                                          */
/*                this background routine to Program 6 bytes data                                                     */
/*                and send the response to the Program command.                                                       */
/* !Number      : 4                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtProg6AsyncResp(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrProgSts();
      if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
      {
         CCP_uniBuf.uniAck.strProg6.u32Adr    = CCP_astrMta[0].u32Adr;
         CCP_uniBuf.uniAck.strProg6.u8AdrExtn = CCP_astrMta[0].u8Extn;
      }
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_PROG_ASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtClrMem                                                                                       */
/*                                                                                                                    */
/* !Description : Erase data in non-volatile memory at address specified by a previous call to "set_mta".             */
/*                The size of the block is defined in the message.                                                    */
/*                                                                                                                    */
/*                 Structure of data in CRO:                                                                          */
/*                 Position    Type           Description                                                             */
/*                 =========== ============== ===============================                                         */
/*                 0           byte           Command Code = CLEAR_MEMORY 0x10                                        */
/*                 1           byte           Command Counter = CTR                                                   */
/*                 2..5        bytes          Memory size                                                             */
/*                 6..7        bytes          don't care                                                              */
/*                 Structure of data in DTO:                                                                          */
/*                 Position    Type           Description                                                             */
/*                 =========== ============== ===============================                                         */
/*                 0           byte           Packet ID: 0xFF                                                         */
/*                 1           byte           Command Return Code                                                     */
/*                 2           byte           Command Counter = CTR                                                   */
/*                 3..7        bytes          don't care                                                              */
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
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED       */
#if (CCP_coOPT_SRV_PROG == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtClrMem(void)
   {
      uint32         u32LocalBlkSize;
      CCP_tudtCmdSts udtLocalCmdSts;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8PGM_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      u32LocalBlkSize = ( ((uint32)CCP_uniBuf.uniCmd.strClrMem.u16BlkSizeMSW << 16)
                        + CCP_uniBuf.uniCmd.strClrMem.u16BlkSizeLSW);
      udtLocalCmdSts  = CCP_udtUsrClrNVMem(&CCP_astrMta[0], u32LocalBlkSize);
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_PROG == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtClrMemAsyncResp                                                                              */
/*                                                                                                                    */
/* !Description : Asynchronous response to clear memory service                                                       */
/*                this background routine to erase FLASH EPROM data                                                   */
/*                and send the response to the Program command.                                                       */
/* !Number      : 6                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtClrMemAsyncResp(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrClrMemSts();
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_CLR_MEM_ASYNC_RESP == CCP_coACVD */

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
