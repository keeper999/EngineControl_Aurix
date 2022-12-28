/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_SRV                                                                                         */
/* !Description     : CCP mandatory services                                                                          */
/*                                                                                                                    */
/* !File            : CCP_Srv.c                                                                                       */
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
/* 1 / CCP_udtCnct                                                                                                    */
/* 2 / CCP_udtGetCcpVers                                                                                              */
/* 3 / CCP_udtExchId                                                                                                  */
/* 4 / CCP_udtSetMta                                                                                                  */
/* 5 / CCP_udtDnld                                                                                                    */
/* 6 / CCP_udtDnldAsyncResp                                                                                           */
/* 7 / CCP_udtUpld                                                                                                    */
/* 8 / CCP_udtUpldAsyncResp                                                                                           */
/* 9 / CCP_udtDcnct                                                                                                   */
/* 10 / CCP_udtFcnNotAvl                                                                                              */
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
#ifndef CCP_coSLAVE_STN_ADR_USR
   #error CCP_coSLAVE_STN_ADR_USR not defined
#endif
#ifndef CCP_coSLAVE_DEV_ID_USR
   #error CCP_coSLAVE_DEV_ID_USR not defined
#endif
#ifndef CCP_coOPT_SRV_SEED_KEY
   #error CCP_coOPT_SRV_SEED_KEY not defined
#endif
#ifndef CCP_coSRV_DNLD_ASYNC_RESP
   #error CCP_coSRV_DNLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coSRV_UPLD_ASYNC_RESP
   #error CCP_coSRV_UPLD_ASYNC_RESP not defined
#endif
#ifndef CCP_coOPT_SRV_DAQ_LIST
   #error CCP_coOPT_SRV_DAQ_LIST not defined
#endif
#ifndef CCP_coOPT_SRV_SSN_STS
   #error CCP_coOPT_SRV_SSN_STS not defined
#endif
#ifndef CCP_coDAQ_RESU_FEATURE
   #error CCP_coDAQ_RESU_FEATURE not defined
#endif

/**********************************************************************************************************************/
/* FUNCTIONS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "CCP_MemMap.h"

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtCnct                                                                                         */
/*                                                                                                                    */
/* !Description : Connects to a slave                                                                                 */
/*               This command establishes a continuous logical point-to-point                                         */
/*               connection with the selected slave station for the master-                                           */
/*               slave command protocol.                                                                              */
/*               All following protocol commands refer to this station only,                                          */
/*               until another station is selected. A CONNECT command to                                              */
/*               another station temporarily disconnects the active station                                           */
/*               (see DISCONNECT). A CONNECT command to an already connected                                          */
/*               station is acknowledged. A slave device does not respond to                                          */
/*               any commands unless being addressed by a prior CONNECT                                               */
/*               command with the correct station address. The station                                                */
/*               address is specified as a number in little-endian byte order                                         */
/*               (Intel format, low byte first).                                                                      */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = CONNECT 0x01                                               */
/*               1           byte           Command Counter = CTR                                                     */
/*               2,3         word           station address (Intel format)                                            */
/*               3..7        bytes          don't care                                                                */
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
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtCnct(void)
{
   uint16  u16LocalStnAdr;
   boolean bLocalStnAdrVldtd;


   u16LocalStnAdr = CCP_uniBuf.uniCmd.strCnct.u16StnAdr;
#if (CCP_coSLAVE_STN_ADR_USR == CCP_coACVD)
   bLocalStnAdrVldtd = CCP_bUsrStnAdrChk(CCP_u8USR_SRV_CNCT, u16LocalStnAdr);
#else
   bLocalStnAdrVldtd = ((u16LocalStnAdr == CCP_u16STN_ADR) ? TRUE : FALSE);
#endif
   if (bLocalStnAdrVldtd != FALSE)
   {
      CCP_udtState = CCP_udtSTT_CNCTD;
      return (CCP_udtCMD_STS_NO_ERR);
   }
   if (CCP_udtState == CCP_udtSTT_CNCTD)
   {
      CCP_udtState = CCP_udtSTT_TMP_DCNCTD;
   }
   return(CCP_udtCMD_STS_NO_RESP);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtGetCcpVers                                                                                   */
/*                                                                                                                    */
/* !Description : Returns the version of the CCP protocol                                                             */
/*               This command performs a mutual identification of the                                                 */
/*               protocol version used in the master and in the slave device                                          */
/*               to agree on a common protocol version.                                                               */
/*               This command is expected to be executed prior to the                                                 */
/*               EXCHANGE_ID command.                                                                                 */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code =GET_CCP_VERSION 0x1B                                        */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Main Protocol version (desired)                                           */
/*               3           byte           Release within version (desired)                                          */
/*               4..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3           byte           Main Protocol version implemented                                         */
/*               4           byte           Release within version implemented                                        */
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
/* !Range   : CCP_udtCMD_STS_NO_ERR                                                                                   */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtGetCcpVers(void)
{
   CCP_uniBuf.uniAck.strGetCcpVers.u8MaiPtclVers     = CCP_u8MAI_PTCL_CCP_VERS;
   CCP_uniBuf.uniAck.strGetCcpVers.u8RleasWithinVers = CCP_u8RLEAS_PTCL_CCP_VERS;

   return(CCP_udtCMD_STS_NO_ERR);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtExchId                                                                                       */
/*                                                                                                                    */
/* !Description : Exchange station identifications between master and slave                                           */
/*               Mask bits, Command Code =GET_exchange_ID 0x17                                                        */
/*               Bit 7 reserved                                                                                       */
/*               Bit 6 PGM                                                                                            */
/*               Bit 5 reserved                                                                                       */
/*               Bit 4 reserved                                                                                       */
/*               Bit 3 reserved                                                                                       */
/*               Bit 2 reserved                                                                                       */
/*               Bit 1 DAQ                                                                                            */
/*               Bit 0 CAL                                                                                            */
/*               Resource Availability: if bit=true specified resource is                                             */
/*               available.                                                                                           */
/*               Resource Protection: if bit=true specified resource is                                               */
/*               protected against unauthorized access (needs UNLOCK)                                                 */
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
/* !Range   : CCP_udtCMD_STS_NO_ERR                                                                                   */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtExchId(void)
{
   #if (CCP_coSLAVE_DEV_ID_USR == CCP_coACVD)
      CCP_vidUsrGetDevId(&CCP_astrMta[0], &CCP_uniBuf.uniAck.strExchId.u8Len);
   #else
      CCP_uniBuf.uniAck.strExchId.u8Len = CCP_u8SLAVE_DEV_ID_LEN;

      CCP_astrMta[0].u32Adr = CCP_u32SLAVE_DEV_ID_ADR;
      CCP_astrMta[0].u8Extn = CCP_u8SLAVE_DEV_ID_EXTN;
   #endif
   CCP_uniBuf.uniAck.strExchId.u8DataTyp = CCP_u8SLAVE_DEV_ID_TYPE;

   CCP_uniBuf.uniAck.strExchId.u8ResAvlyMask  = CCP_u8RES_CFG;
   CCP_uniBuf.uniAck.strExchId.u8ResProtnMask = CCP_u8PROTN_CFG;

   return(CCP_udtCMD_STS_NO_ERR);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtSetMta                                                                                       */
/*                                                                                                                    */
/* !Description : Set Memory Transfer Address                                                                         */
/* Design Info:  This command will initialize a base pointer (32Bit +                                                 */
/*               extension) for all following memory transfers. The address                                           */
/*               extension depends on the slave controller's organization and                                         */
/*               may identify a switchable memory bank or a memory segment.                                           */
/*               The MTA number (handle) is used to identify different                                                */
/*               transfer address locations (pointers). MTA0 is used by the                                           */
/*               commands DNLOAD, UPLOAD, DNLOAD_6, SELECT_CAL_PAGE, CLEAR_                                           */
/*               MEMORY, PROGRAM, and PROGRAM_6. MTA1 is used by the MOVE                                             */
/*               command. See also command 'MOVE'.                                                                    */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = SET_MTA 0x02                                               */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           Memory transfer address MTA                                               */
/*                                          number (0,1)                                                              */
/*               3           byte           Address extension                                                         */
/*               4..7        bytes          Address                                                                   */
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
/* !Comment   : status of the service                                                                                 */
/* !Range     : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG                                                  */
/* !Deviation : CCP_udtCMD_STS_ACS_DENIED not returned by this service because it is more logical to do the check     */
/*              when the linked action will be known (compatible with XCP)                                            */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtSetMta(void)
{
   uint8 u8LocalMtaIdx;


   u8LocalMtaIdx = CCP_uniBuf.uniCmd.strSetMta.u8MtaIdx;
   if (u8LocalMtaIdx <= CCP_u8NO_MTA)
   {
      CCP_astrMta[u8LocalMtaIdx].u32Adr = CCP_uniBuf.uniCmd.strSetMta.u32Adr;
      CCP_astrMta[u8LocalMtaIdx].u8Extn = CCP_uniBuf.uniCmd.strSetMta.u8AdrExtn;

      return(CCP_udtCMD_STS_NO_ERR);
   }
   return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtDnld                                                                                         */
/*                                                                                                                    */
/* !Description : Write data to slave at address specified by a previous call to "set_mta".                           */
/*                The number of data can be between 1 and 5.                                                          */
/*                The data block with the specified length (size) contained                                           */
/*                in the CRO will be copied into memory, starting at the                                              */
/*                current Memory Transfer Address0 (MTA0). The MTA0 pointer                                           */
/*                will be post-incremented by the value of 'size'.                                                    */
/*                                                                                                                    */
/*                Structure of data in CRO:                                                                           */
/*                Position    Type           Description                                                              */
/*                =========== ============== ================================                                         */
/*                0           byte           Command Code = DNLOAD 0x03                                               */
/*                1           byte           Command Counter = CTR                                                    */
/*                2           byte           size of data block to follow in bytes                                    */
/*                3..7        bytes          data to be transferred (up to 5 bytes)                                   */
/*                Structure of data in DTO:                                                                           */
/*                Position    Type           Description                                                              */
/*                =========== ============== ================================                                         */
/*                0           byte           Packet ID: 0xFF                                                          */
/*                1           byte           Command Return Code                                                      */
/*                2           byte           Command Counter = CTR                                                    */
/*                3           byte           MTA0 extension (after post-increment)                                    */
/*                4..7        bytes          MTA0 address (after post-increment)                                      */
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
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG, CCP_udtCMD_STS_KEY_REQ, CCP_udtCMD_STS_ACS_DENIED */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnld(void)
{
   uint8                                  u8LocalDataSize;
   CCP_tudtCmdSts                         udtLocalCmdSts;
   P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;


   #if (CCP_coOPT_SRV_SEED_KEY == CCP_coACVD)
      if ((CCP_u8ProtnSts & CCP_u8CAL_PROTD) != 0)
      {
         return(CCP_udtCMD_STS_KEY_REQ);
      }
   #endif

   u8LocalDataSize = CCP_uniBuf.uniCmd.strDnld.u8DataSize;
   if (  (u8LocalDataSize <= CCP_u8DNLD_MAX_DA_SIZE)
      && (u8LocalDataSize != 0))
   {
      pu8LocalData   = &CCP_uniBuf.uniCmd.strDnld.au8Data[0];
      udtLocalCmdSts = CCP_udtUsrWrMem(CCP_u8USR_SRV_DNLD, &CCP_astrMta[0], pu8LocalData, u8LocalDataSize);

      CCP_astrMta[0].u32Adr += u8LocalDataSize;

      if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
      {
         CCP_uniBuf.uniAck.strDnld.u32Adr    = CCP_astrMta[0].u32Adr;
         CCP_uniBuf.uniAck.strDnld.u8AdrExtn = CCP_astrMta[0].u8Extn;
      }
      return(udtLocalCmdSts);
   }
   return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtDnldAsyncResp                                                                                */
/*                                                                                                                    */
/* !Description : Asynchronous response to download service                                                           */
/*                this background routine to download 1-5 bytes data                                                  */
/*                and send the response to the DNLOAD command.                                                        */
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
#if (CCP_coSRV_DNLD_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDnldAsyncResp(void)
   {
      CCP_tudtCmdSts udtLocalCmdSts;


      udtLocalCmdSts = CCP_udtUsrWrMemSts();
      if (udtLocalCmdSts == CCP_udtCMD_STS_NO_ERR)
      {
         CCP_uniBuf.uniAck.strDnld.u32Adr    = CCP_astrMta[0].u32Adr;
         CCP_uniBuf.uniAck.strDnld.u8AdrExtn = CCP_astrMta[0].u8Extn;
      }
      return(udtLocalCmdSts);
   }
#endif /* CCP_coSRV_DNLD_ASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtUpld                                                                                         */
/*                                                                                                                    */
/* !Description : Read data from slave at address specified by a previous call to "set_mta".                          */
/*                The number of data can be between 1 and 5.                                                          */
/*                A data block of the specified length (size), starting at                                            */
/*                current MTA0, will be copied into the corresponding DTO data                                        */
/*                field. The MTA0 pointer will be post-incremented by the                                             */
/*                value of 'size'.                                                                                    */
/*                                                                                                                    */
/*                Structure of data in CRO:                                                                           */
/*                Position    Type           Description                                                              */
/*                =========== ============== ================================                                         */
/*                0           byte           Command Code = UPLOAD 0x04                                               */
/*                1           byte           Command Counter = CTR                                                    */
/*                2           byte           size of data block to be uploaded in bytes                               */
/*                3..7        bytes          don't care                                                               */
/*                Structure of data in DTO:                                                                           */
/*                Position    Type           Description                                                              */
/*                =========== ============== ================================                                         */
/*                0           byte           Packet ID: 0xFF                                                          */
/*                1           byte           Command Return Code                                                      */
/*                2           byte           Command Counter = CTR                                                    */
/*                3..7        bytes          requested data bytes                                                     */
/*                                                                                                                    */
/* !Number      : 7                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG, CCP_udtCMD_STS_ACS_DENIED                         */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtUpld(void)
{
   uint8                                  u8LocalDataSize;
   CCP_tudtCmdSts                         udtLocalCmdSts;
   P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;


   u8LocalDataSize = CCP_uniBuf.uniCmd.strUpld.u8DataSize;
   if (  (u8LocalDataSize <= CCP_u8UPLD_MAX_DA_SIZE)
      && (u8LocalDataSize != 0))
   {
      pu8LocalData   = &CCP_uniBuf.uniAck.strUpld.au8Data[0];
      udtLocalCmdSts = CCP_udtUsrReadMem(CCP_u8USR_SRV_UPLD, &CCP_astrMta[0], pu8LocalData, u8LocalDataSize);

      CCP_astrMta[0].u32Adr += u8LocalDataSize;

      return(udtLocalCmdSts);
   }
   return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtUpldAsyncResp                                                                                */
/*                                                                                                                    */
/* !Description : Asynchronous response to upload service                                                             */
/*                this background routine to download 1-5 bytes data                                                  */
/*                and send the response to the UPLOAD command.                                                        */
/* !Number      : 8                                                                                                   */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_RESP_PND                                                          */
#if (CCP_coSRV_UPLD_ASYNC_RESP == CCP_coACVD)
   FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtUpldAsyncResp(void)
   {
      P2VAR(uint8, AUTOMATIC, CCP_APPL_DATA) pu8LocalData;
      CCP_tudtCmdSts                         udtLocalCmdSts;


      pu8LocalData   = &CCP_uniBuf.uniAck.strUpld.au8Data[0];
      udtLocalCmdSts = CCP_udtUsrReadMemSts(pu8LocalData);
      return(udtLocalCmdSts);
   }
#endif /* CCP_coSRV_UPLD_ASYNC_RESP == CCP_coACVD */

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtDcnct                                                                                        */
/*                                                                                                                    */
/* !Description : Disconnects from master                                                                             */
/*               The disconnect can be temporary, setting the slave device in                                         */
/*               an "off line" state or with parameter 0x01 terminating the                                           */
/*               calibration session.                                                                                 */
/*               Terminating the session invalidates all state information                                            */
/*               and resets the slave protection status.                                                              */
/*               A temporary disconnect doesn't stop the transmission of DAQ                                          */
/*               messages. The MTA values, the DAQ setup, the session status,                                         */
/*               and the protection status are unaffected by the temporary                                            */
/*               disconnect and remain unchanged.                                                                     */
/*               If the ECU supports the resume feature and the resume bit                                            */
/*               was set with a SET_SESSION_STATUS command, the DAQ related                                           */
/*               functions behave like in a temporary disconnect. The                                                 */
/*               protection status for DAQ remains unlocked.                                                          */
/*               Station address is specified as a number in little-endian                                            */
/*               byte order (Intel format, low byte first).                                                           */
/*                                                                                                                    */
/*               Structure of data in CRO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Command Code = DISCONNECT 0x07                                            */
/*               1           byte           Command Counter = CTR                                                     */
/*               2           byte           0x00 temporary,                                                           */
/*                                          0x01 end of session                                                       */
/*               3           byte           don't care                                                                */
/*               4,5         word           Station address (Intel format)                                            */
/*               6..7        bytes          don't care                                                                */
/*               Structure of data in DTO:                                                                            */
/*               Position    Type           Description                                                               */
/*               =========== ============== =================================                                         */
/*               0           byte           Packet ID: 0xFF                                                           */
/*               1           byte           Command Return Code                                                       */
/*               2           byte           Command Counter = CTR                                                     */
/*               3..7        bytes          don't care                                                                */
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
/* !Range   : CCP_udtCMD_STS_NO_RESP, CCP_udtCMD_STS_NO_ERR, CCP_udtCMD_STS_PRM_OUT_OF_RNG                            */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtDcnct(void)
{
   uint16  u16LocalStnAdr;
   boolean bLocalStnAdrVldtd;
   uint8   u8LocalReqdStt;


   u16LocalStnAdr = CCP_uniBuf.uniCmd.strDcnct.u16StnAdr;
#if (CCP_coSLAVE_STN_ADR_USR == CCP_coACVD)
   bLocalStnAdrVldtd = CCP_bUsrStnAdrChk(CCP_u8USR_SRV_DCNCT, u16LocalStnAdr);
#else
   bLocalStnAdrVldtd = ((u16LocalStnAdr == CCP_u16STN_ADR) ? TRUE : FALSE);
#endif
   if (bLocalStnAdrVldtd != FALSE)
   {
      u8LocalReqdStt = CCP_uniBuf.uniCmd.strDcnct.u8Mod;
      if (  (u8LocalReqdStt == CCP_u8DCNCT_MOD_PRMNT)
         || (u8LocalReqdStt == CCP_u8DCNCT_MOD_TMP))
      {
         if (u8LocalReqdStt == CCP_u8DCNCT_MOD_TMP)
         {
            CCP_udtState = CCP_udtSTT_TMP_DCNCTD;
            return(CCP_udtCMD_STS_NO_ERR);
         }

         CCP_vidUsrNtfySsnTrmd();

         #if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
            #if (  (CCP_coOPT_SRV_SSN_STS == CCP_coACVD) \
                && (CCP_coDAQ_RESU_FEATURE == CCP_coACVD))
               if ((CCP_u8SsnSts & CCP_u8RESU_REQ) == 0)
               {
                  CCP_vidDaqListIni();
               }
            #else
               CCP_vidDaqListIni();
            #endif
         #endif

         CCP_vidSsnIni();
         return(CCP_udtCMD_STS_NO_ERR);
      }
      return(CCP_udtCMD_STS_PRM_OUT_OF_RNG);
   }
   return(CCP_udtCMD_STS_NO_RESP);
}

/*********************************************** <AUTO_FUNCTION_HEADER> ***********************************************/
/*                                                                                                                    */
/* !FuncName    : CCP_udtFcnNotAvl                                                                                    */
/*                                                                                                                    */
/* !Description : Called when requested function not available                                                        */
/* !Number      : 10                                                                                                  */
/* !Reference   : CAN Calibration Protocol 2.1                                                                        */
/*                                                                                                                    */
/* !Trace_To    : NONE                                                                                                */
/*                                                                                                                    */
/********************************************** </AUTO_FUNCTION_HEADER> ***********************************************/
/* !LastAuthor  :  R. Danioux                                                                                         */
/********************************************* <AUTO_FUNCTION_PROTOTYPE> **********************************************/
/* !Comment : status of the service                                                                                   */
/* !Range   : CCP_udtCMD_STS_FCN_NOT_AVL                                                                              */
FUNC(CCP_tudtCmdSts, CCP_CODE) CCP_udtFcnNotAvl(void)
{
   return(CCP_udtCMD_STS_FCN_NOT_AVL);
}

#define CCP_STOP_SEC_CODE
#include "CCP_MemMap.h"

/*---------------------------------------------------- end of file ---------------------------------------------------*/
