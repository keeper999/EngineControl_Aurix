/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_OPT                                                                                         */
/* !Description     : CCP optional services                                                                           */
/*                                                                                                                    */
/* !File            : CCP_Opt.c                                                                                       */
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
/* 1 / CCP_udtTest                                                                                                    */
/* 2 / CCP_udtDnld6                                                                                                   */
/* 3 / CCP_udtDnld6AsyncResp                                                                                          */
/* 4 / CCP_udtShoUpld                                                                                                 */
/* 5 / CCP_udtShoUpldAsyncResp                                                                                        */
/* 6 / CCP_udtSetSsnSts                                                                                               */
/* 7 / CCP_udtGetSsnSts                                                                                               */
/* 8 / CCP_udtGetSeed                                                                                                 */
/* 9 / CCP_udtUnlck                                                                                                   */
/* 10 / CCP_udtSelCalPage                                                                                             */
/* 11 / CCP_udtGetAcvCalPage                                                                                          */
/* 12 / CCP_udtBldCks                                                                                                 */
/* 13 / CCP_udtBldCksAsyncResp                                                                                        */
/* 14 / CCP_udtMove                                                                                                   */
/* 15 / CCP_udtMoveAsyncResp                                                                                          */
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
#ifndef CCP_coOPT_SRV_TEST
   #error CCP_coOPT_SRV_TEST not defined
#endif
#ifndef CCP_coSLAVE_STN_ADR_USR
   #error CCP_coSLAVE_STN_ADR_USR not defined
#endif
#ifndef CCP_coOPT_SRV_DNLD6
   #error CCP_coOPT_SRV_DNLD6 not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coOPT_SRV_DNLD6_ASYNC_RESP
   #error CCP_coOPT_SRV_DNLD6_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_SHO_UPLD
   #error CCP_coOPT_SRV_SHO_UPLD not defined
#endif
#ifndef CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP
   #error CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_SSN_STS
   #error CCP_coOPT_SRV_SSN_STS not defined
#endif
#ifndef CCP_coCAL_STORE_FEATURE
   #error CCP_coCAL_STORE_FEATURE not defined
#endif
#ifndef CCP_coDAQ_RESU_FEATURE
   #error CCP_coDAQ_RESU_FEATURE not defined
#endif
#ifndef CCP_coADDL_STS
   #error CCP_coADDL_STS not defined
#endif
#ifndef CCP_coOPT_SRV_CAL_PAGE
   #error CCP_coOPT_SRV_CAL_PAGE not defined
#endif
#ifndef CCP_coOPT_SRV_CKS
   #error CCP_coOPT_SRV_CKS not defined
#endif
#ifndef CCP_coOPT_SRV_MOVE
   #error CCP_coOPT_SRV_MOVE not defined
#endif
#ifndef CCP_coOPT_SRV_CKS_ASYNC_RESP
   #error CCP_coOPT_SRV_CKS_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_MOVE_ASYNC_RESP
   #error CCP_coOPT_SRV_MOVE_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif

/**********************************************************************************************************************/
/* FUNCTIONS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtTest                                                                                         */
/*                                                                                                                    */
/* !Description : Test presence of the slave with the specified station address which is available for CCP            */
/*                communication. This command does not establish a logical connection nor does it trigger any         */
/*                activities in the specified slave.                                                                  */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = TEST 0x05                                                  */
/*               1           byte           Command Counter = CTR                                                     */
/*               2,3         word           station address (Intel format)                                            */
/*               4..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
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
/* !Range   : CCP_udtCMD_STS_NO_RESP, CCP_udtCMD_STS_NO_ERR                                                           */
#if (CCP_coOPT_SRV_TEST == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtTest(void)
   {
      uint16  u16LocalStnAdr;
      boolean bLocalStnAdrVldtd;


      u16LocalStnAdr = CCP_uniBuf.uniCmd.strTest.u16StnAdr;
# if (CCP_coSLAVE_STN_ADR_USR == CCP_coACVD)
      bLocalStnAdrVldtd = CCP_bUsrStnAdrChk(CCP_u8USR_SRV_TEST, u16LocalStnAdr);
# else
      bLocalStnAdrVldtd = ((u16LocalStnAdr == CCP_u16STN_ADR) ? TRUE : FALSE);
# endif
      return((bLocalStnAdrVldtd != FALSE) ? CCP_udtCMD_STS_NO_ERR : CCP_udtCMD_STS_NO_RESP);
   }
#endif /* CCP_coOPT_SRV_TEST == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtDnld6                                                                                        */
/*                                                                                                                    */
/* !Description : Write data to slave at address specified by a previous call to "set_mta".The number of data is 6.   */
/*                The data block with the fixed length (size) of 6 bytes contained in the CRO will be copied into     */
/*                memory, starting at the current Memory Transfer Address0 (MTA0).                                    */
/*                The MTA0 pointer will be post-incremented by the value of 6.                                        */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = DNLOAD_6 0x23                                              */
/*               1           byte           Command Counter = CTR                                                     */
/*               2..7        bytes          6 bytes of data to be transferred                                         */
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
/* !Number      : 2                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_ACS_DENIED                                */
#if (CCP_coOPT_SRV_DNLD6 == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnld6(void)
   {
      CCP_tudtCmdSts                         udtLocalCmdSts;
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;


      #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
         if ((CCP_u8ProtnSts & CCP_u8CAL_PROTD) != 0)
         {
            return(CCP_udtCMD_STS_KEY_REQ);
         }
      #endif

      pu8LocalData   = &CCP_uniBuf.uniCmd.strDnld6.au8Data[0];
      udtLocalCmdSts = CCP_udtUsrWrMem(CCP_u8USR_SRV_DNLD6, &CCP_astrMta[0], pu8LocalData, CCP_u8DNLD6_DA_SIZE);

      CCP_astrMta[0].u32Adr += CCP_u8DNLD6_DA_SIZE;

      if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
      {
         CCP_uniBuf.uniAck.strDnld6.u32Adr    = CCP_astrMta[0].u32Adr;
         CCP_uniBuf.uniAck.strDnld6.u8AdrExtn = CCP_astrMta[0].u8Extn;
      }
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_DNLD6 == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtDnld6AsyncResp                                                                               */
/*                                                                                                                    */
/* !Description : Asynchronous response to DNLOAD_6 service this background routine to download 6 bytes data          */
/*                and send the response to the DNLOAD_6 command.                                                      */
/* !Number      : 3                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coOPT_SRV_DNLD6_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnld6AsyncResp(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrWrMemSts();
      if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
      {
         CCP_uniBuf.uniAck.strDnld6.u32Adr    = CCP_astrMta[0].u32Adr;
         CCP_uniBuf.uniAck.strDnld6.u8AdrExtn = CCP_astrMta[0].u8Extn;
      }
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_DNLD6_ASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtShoUpld                                                                                      */
/*                                                                                                                    */
/* !Description : Read data from slave at address specified in the message.                                           */
/*                The number of data can be between 1 and 5.                                                          */
/*                A data block of the specified length (size), starting at source address will be copied into the     */
/*                corresponding DTO data field. The MTA0 pointer remains unchanged.                                   */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = SHORT_UP 0x0F                                              */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           size of data block to be uploaded                                         */
/*                                          in bytes (1..5)                                                           */
/*               3           byte           Address extension                                                         */
/*               4..7        unsigned long  Address                                                                   */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          requested data bytes                                                      */
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
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG, CCP_udtCMD_STS_ACS_DENIED                         */
#if (CCP_coOPT_SRV_SHO_UPLD == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtShoUpld(void)
   {
      uint8                                  u8LocalDataSize;
      CCP_tstrMta                            strLocalMta;
      CCP_tudtCmdSts                         udtLocalCmdSts;
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;


      u8LocalDataSize = CCP_uniBuf.uniCmd.strShoUpld.u8DataSize;
      if (  (u8LocalDataSize <= CCP_u8UPLD_MAX_DA_SIZE)
         && (u8LocalDataSize != 0))
      {
         strLocalMta.u32Adr = CCP_uniBuf.uniCmd.strShoUpld.u32Adr;
         strLocalMta.u8Extn = CCP_uniBuf.uniCmd.strShoUpld.u8AdrExtn;

         pu8LocalData   = &CCP_uniBuf.uniAck.strShoUpld.au8Data[0];
         udtLocalCmdSts = CCP_udtUsrReadMem(CCP_u8USR_SRV_SHO_UPLD, &strLocalMta, pu8LocalData, u8LocalDataSize);
         return(udtLocalCmdSts);
      }
      return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
   }
#endif /* CCP_coOPT_SRV_SHO_UPLD == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtShoUpldAsyncResp                                                                             */
/*                                                                                                                    */
/* !Description : Asynchronous response to SHORT_UP service                                                           */
/*                this background routine to upload 1-5 bytes data and send the response to the SHORT_UP command.     */
/* !Number      : 5                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtShoUpldAsyncResp(void)
   {
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;
      CCP_tudtCmdSts                         udtLocalCmdSts;


      pu8LocalData   = &CCP_uniBuf.uniAck.strUpld.au8Data[0];
      udtLocalCmdSts = CCP_udtUsrReadMemSts(pu8LocalData);
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_SHO_UPLD_ASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtSetSsnSts                                                                                    */
/*                                                                                                                    */
/* !Description : Set session status.                                                                                 */
/*                The session status bits are read/write to the slave and are to be cleared on power-up, on session   */
/*                log-off and in applicable fault conditions.                                                         */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = SET_S_STATUS 0x0C                                          */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Session status bits (table below)                                         */
/*               3..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
/*               Session status bits:                                                                                 */
/*               0  SS_CAL              Calibration data initialized                                                  */
/*               1  SS_DAQ              DAQ list(s) initialized                                                       */
/*               2  SS_RESUME           Request to save DAQ setup during                                              */
/*                                      shutdown in ECU.                                                              */
/*               3..5                   reserved (in CCP specification)                                               */
/*               6  SS_STORE            Request to save calibration data                                              */
/*                                      during shut-down                                                              */
/*               7  SS_RUN              Session in progress                                                           */
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
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG                                                    */
#if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSetSsnSts(void)
   {
      uint8   u8LocalSsnSts;
      #if (  (CCP_coCAL_STORE_FEATURE == CCP_coACVD) \
          || (  (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) \
             && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD)) )
      boolean bLocalStt;
      #endif


      u8LocalSsnSts = CCP_uniBuf.uniCmd.strSetSsnSts.u8SsnSts;
      if ((u8LocalSsnSts & CCP_u8UNKNOWN_SSN_STS_MASK) == 0)
      {
         #if (CCP_coCAL_STORE_FEATURE == CCP_coACVD)
            /* Check CCP_u8STORE_REQ bit changed */
            if (((u8LocalSsnSts ^ CCP_u8SsnSts) & CCP_u8STORE_REQ)!= 0)
            {
               bLocalStt = (((u8LocalSsnSts & CCP_u8STORE_REQ) != 0) ? TRUE : FALSE);
               CCP_vidUsrNtfyCalStoreSttChgd(bLocalStt);
            }
         #endif

         #if (  (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) \
             && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD))
            /* Check CCP_u8RESU_REQ bit changed */
            if (((u8LocalSsnSts ^ CCP_u8SsnSts) & CCP_u8RESU_REQ)!= 0)
            {
               bLocalStt = (((u8LocalSsnSts & CCP_u8RESU_REQ) != 0) ? TRUE : FALSE);
               CCP_vidUsrNtfyDaqResuSttChgd(bLocalStt);
            }
         #endif

         CCP_u8SsnSts = u8LocalSsnSts;

         return(CCP_udtCMD_STS_NO_ERR);
      }
      return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
   }
#endif /* CCP_coOPT_SRV_SSN_STS == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtGetSsnSts                                                                                    */
/*                                                                                                                    */
/* !Description : Get session status.                                                                                 */
/*                                                                                                                    */
/*                Note: the use of additional status information is manufacturer and/or project specific, it is not   */
/*                part of this protocol specification. For example, additional status information could contain an    */
/*                incremental checksum result, that keeps track of the current session activities.                    */
/*                                                                                                                    */
/*                If the return information does not contain additional status information, the additional status     */
/*                information qualifier has to be false (0).                                                          */
/*                                                                                                                    */
/*                If the additional status information is not false, it may be used to determine the type of          */
/*                additional status information.                                                                      */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = GET_S_STATUS 0x0D                                          */
/*               1           byte           Command Counter = CTR                                                     */
/*               2..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           Session status                                                            */
/*               4           byte           additional status information                                             */
/*                                          qualifier                                                                 */
/*               5..7        bytes          additional status information                                             */
/*                                          (optional)                                                                */
/* !Number      : 7                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR                                                                                   */
#if (CCP_coOPT_SRV_SSN_STS == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetSsnSts(void)
   {
      CCP_uniBuf.uniAck.strGetSsnSts.u8SsnSts = CCP_u8SsnSts;
      #if (CCP_coADDL_STS == CCP_coACVD)
         CCP_vidUsrGetAddlSts(&CCP_uniBuf.uniAck.strGetSsnSts.u8AddlStsInfoQlfr,
                              &CCP_uniBuf.uniAck.strGetSsnSts.au8AddlStsInfo[0]);
      #else
         CCP_uniBuf.uniAck.strGetSsnSts.u8AddlStsInfoQlfr = 0;
      #endif
      return(CCP_udtCMD_STS_NO_ERR);
   }
#endif /* CCP_coOPT_SRV_SSN_STS == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtGetSeed                                                                                      */
/*                                                                                                                    */
/*                                                                                                                    */
/* !Description : Get seed to unlock slave resource or function.                                                      */
/*                Only one resource or function may be requested with one GET_SEED command. If more than one resource */
/*                is requested, the GET_SEED command together with the following UNLOCK command has to be performed   */
/*                multiple times.                                                                                     */
/*                Returns 'seed' data for a seed&key algorithm for computing the 'key' to unlock the requested        */
/*                function for authorized access.                                                                     */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = GET_SEED 0x12                                              */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Requested slave resource or                                               */
/*                                          function (Resource Mask)                                                  */
/*               3..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           Protection status (true or false)                                         */
/*               4..7        bytes          'seed' data                                                               */
/*                                                                                                                    */
/* !Number      : 8                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG                                                    */
#if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetSeed(void)
   {
      uint8 u8LocalProtnChk;


      u8LocalProtnChk = CCP_uniBuf.uniCmd.strGetSeed.u8ReqSlaveRes;
      if (  (u8LocalProtnChk == CCP_u8CAL_RES)
         || (u8LocalProtnChk == CCP_u8DAQ_RES)
         || (u8LocalProtnChk == CCP_u8PGM_RES))
      {
         if ((CCP_u8ProtnSts & u8LocalProtnChk) == 0)
         {
            CCP_uniBuf.uniAck.strGetSeed.u8ProtnSts = CCP_u8RES_UNLCKD;
         }
         else
         {
            CCP_u8UnlckResReq = u8LocalProtnChk;

            CCP_uniBuf.uniAck.strGetSeed.u8ProtnSts = CCP_u8RES_LOCKD;
            CCP_vidUsrGetSeed(u8LocalProtnChk, &CCP_uniBuf.uniAck.strGetSeed.au8Key[0]);
         }
         return (CCP_udtCMD_STS_NO_ERR);
      }
      return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
   }
#endif /* CCP_coOPT_SRV_SEED_KEY == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtUnlck                                                                                        */
/*                                                                                                                    */
/*                                                                                                                    */
/* !Description : Unlocks the slave devices security protection (if applicable) using a 'key' computed from 'seed'.   */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = UNLOCK 0x13                                                */
/*               1           byte           Command Counter = CTR                                                     */
/*               2...        bytes          'key'                                                                     */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           Current Provilege Status                                                  */
/*                                          (Resource Mask)                                                           */
/*               4..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 9                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_ACS_LOCKD                                 */
#if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtUnlck(void)
   {
      uint8          u8LocalUnlckRqst;
      CCP_tudtCmdSts udtLocalCmdSts;


      u8LocalUnlckRqst = CCP_u8UnlckResReq;
      if (u8LocalUnlckRqst != 0)
      {
         CCP_u8UnlckResReq = 0;

         udtLocalCmdSts = CCP_udtUsrChkKey(u8LocalUnlckRqst, &CCP_uniBuf.uniCmd.strUnlck.au8Key[0]);
         if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
         {
            CCP_u8ProtnSts &= (uint8)(~u8LocalUnlckRqst);

            CCP_uniBuf.uniAck.strUnlck.u8CurPvlgSts = CCP_u8ProtnSts;
            return(CCP_udtCMD_STS_NO_ERR);
         }
         return(CCP_udtCMD_STS_ACS_LOCKD);
      }
      return(CCP_udtCMD_STS_KEY_REQ);
   }
#endif /* CCP_coOPT_SRV_SEED_KEY == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtSelCalPage                                                                                   */
/*                                                                                                                    */
/*                                                                                                                    */
/* !Description : Activate the calibration page pointed to by a previous call to "set_mta".                           */
/*               This command's function depends on the ECU implementation.                                           */
/*               The previously initialized MTA0 points to the start of the                                           */
/*               calibration data page that is selected as the currently                                              */
/*               active page by this command.                                                                         */
/*               Using two blocks of ECU memory for calibration, the SET_MTA                                          */
/*               and the SELECT_CAL_PAGE commands can be used for a kind of                                           */
/*               'emergency interrupt' from the master device in order to                                             */
/*               bring the slave system into a 'safe state' by preparing the                                          */
/*               change of these two memory blocks with the SET_MTA command                                           */
/*               and executing the change immediately with SELECT_CAL_PAGE.                                           */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code= SELECT_CAL_PAGE 0x11                                        */
/*               1           byte           Command Counter = CTR                                                     */
/*               2..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 10                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_ACS_DENIED                                                        */
#if (CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSelCalPage(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrSelCalPage(&CCP_astrMta[0]);
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtGetAcvCalPage                                                                                */
/*                                                                                                                    */
/*                                                                                                                    */
/* !Description : Get start address of current active calibration page                                                */
/*               This command returns the start address of the calibration                                            */
/*               page that is currently active in the slave device.                                                   */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = GET_ACTIVE_CAL_PAGE                                        */
/*                                                         0x09                                                       */
/*               1           byte           Command Counter = CTR                                                     */
/*               2..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           Address extension                                                         */
/*               4..7        unsigned long  Address                                                                   */
/*                                                                                                                    */
/* !Number      : 11                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR                                                                                   */
#if (CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetAcvCalPage(void)
   {
      CCP_tstrMta strLocalMta;


      CCP_vidUsrGetAcvCalPage(&strLocalMta);
      CCP_uniBuf.uniAck.strGetAcvCalPage.u32Adr    = strLocalMta.u32Adr;
      CCP_uniBuf.uniAck.strGetAcvCalPage.u8AdrExtn = strLocalMta.u8Extn;
      return(CCP_udtCMD_STS_NO_ERR);
   }
#endif /* CCP_coOPT_SRV_CAL_PAGE == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtBldCks                                                                                       */
/*                                                                                                                    */
/* !Description : Calculate the checksum of the block pointed to by a previous call to "set_mta".                     */
/*                The size of the block is defined in the message.                                                    */
/*                The calculation can be done immediately or in background.                                           */
/*               It Returns a checksum result of the memory block                                                     */
/*               that is defined by MTA0 (memory transfer area start address)                                         */
/*               and block 'size'. The checksum algorithm may be manufacturer                                         */
/*               and/or project specific, it is not part of this specification                                        */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== ==================================                                        */
/*               0           byte           Command Code = BUILD_CHKSUM 0x0E                                          */
/*               1           byte           Command Counter = CTR                                                     */
/*               2..5        unsigned long  block size in bytes                                                       */
/*               6..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== ==================================                                        */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           size of checksum data                                                     */
/*               4..7        bytes          checksum data                                                             */
/*                                          (implementation specific)                                                 */
/*                                                                                                                    */
/* !Number      : 12                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED                               */
#if (CCP_coOPT_SRV_CKS == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtBldCks(void)
   {
      uint32         u32LocalBlkSize;
      CCP_tudtCmdSts udtLocalCmdSts;


      u32LocalBlkSize = ( ((uint32)CCP_uniBuf.uniCmd.strBldCks.u16BlkSizeMSW << 16)
                        + CCP_uniBuf.uniCmd.strBldCks.u16BlkSizeLSW);
      udtLocalCmdSts  = CCP_udtUsrBldCks(&CCP_astrMta[0], u32LocalBlkSize,
                                         &CCP_uniBuf.uniAck.strBldCks.u8CksDataSize,
                                         &CCP_uniBuf.uniAck.strBldCks.au8CksData[0]);
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_CKS == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtBldCksAsyncResp                                                                              */
/*                                                                                                                    */
/* !Description : Asynchronous response to checksum calculation                                                       */
/*               this background routine to compute the checksum and send the                                         */
/*               response to the BUILD_CHKSUM command.                                                                */
/*                                                                                                                    */
/* !Number      : 13                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coOPT_SRV_CKS_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtBldCksAsyncResp(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrBldCksSts(&CCP_uniBuf.uniAck.strBldCks.u8CksDataSize,
                                           &CCP_uniBuf.uniAck.strBldCks.au8CksData[0]);
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_CKS_ASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtMove                                                                                         */
/*                                                                                                                    */
/* !Description : Copy data from the block pointed to by a previous call to "set_mta(0)" to the block pointed to by a */
/*                previous call to "set_mta(1)".                                                                      */
/*                The size of the block is defined in the message.                                                    */
/*                The copy can be done immediately or in background.                                                  */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== ==================================                                        */
/*               0           byte           Command Code = MOVE 0x19                                                  */
/*               1           byte           Command Counter = CTR                                                     */
/*               2..5        long           Size (number of bytes) of data                                            */
/*                                          block to move                                                             */
/*               6..7        bytes          don't care                                                                */
/*                                                                                                                    */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== ==================================                                        */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
/*                                                                                                                    */
/* !Number      : 14                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND, CCP_udtCMD_STS_ACS_DENIED                               */
#if (CCP_coOPT_SRV_MOVE == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtMove(void)
   {
      uint32         u32LocalBlkSize;
      CCP_tudtCmdSts udtLocalCmdSts;


      u32LocalBlkSize = ( ((uint32)CCP_uniBuf.uniCmd.strMove.u16BlkSizeMSW << 16)
                        + CCP_uniBuf.uniCmd.strMove.u16BlkSizeLSW);
      udtLocalCmdSts  = CCP_udtUsrMove(&CCP_astrMta[0], &CCP_astrMta[1], u32LocalBlkSize);
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_MOVE == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtMoveAsyncResp                                                                                */
/*                                                                                                                    */
/* !Description : Asynchronous response to move service                                                               */
/*               this background routine to copy data and send the response                                           */
/*               to the MOVE command.                                                                                 */
/*                                                                                                                    */
/* !Number      : 15                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtMoveAsyncResp(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrMoveSts();
      return(udtLocalCmdSts);
   }
#endif /* CCP_coOPT_SRV_MOVE_ASYNC_RESP == CCP_coACVD */

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
