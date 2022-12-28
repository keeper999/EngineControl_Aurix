/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCP_SRV                                                                                         */
/* !Description     : Declaration of CCP messages                                                                     */
/*                                                                                                                    */
/* !File            : CCP_SRV.h                                                                                       */
/*                                                                                                                    */
/* !Scope           : PrivateComponent                                                                                */
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

#ifndef CCP_SRV_H
#define CCP_SRV_H

#include "CCP_Typ.h"

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation options are defined                                                            */
/**********************************************************************************************************************/
#ifndef CCP_coMSB_FIRST
   #error CCP_coMSB_FIRST not defined
#endif
#ifndef CCP_coCPU_BYTE_ORDER
   #error CCP_coCPU_BYTE_ORDER not defined
#endif

/**********************************************************************************************************************/
/* TYPES                                                                                                              */
/**********************************************************************************************************************/
/* !Comment: The buffers containing data before transmission and after reception of messages is aligned               */
/*           by construction on a 4 bytes boundary => 16-bits and 32-bits data in messages that are correclty aligned */
/*           can be declared directly as uint16 and uint32.                                                           */
/*           This is also possible because the endianess of data is not specified by the protocol (except for station */
/*           address) but specific to each ECU and configured in the ASAP2 file                                       */

/* !MComment: declaration of CONNECT messages type                                                                    */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   /* !Comment: endianess is managed directly in configuration                                                        */
   uint16 u16StnAdr;
   uint8  au8NotUsed[4];
}
CCP_tstrCmdCnct;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckCnct;

/* !MComment: declaration of EXCHANGE_ID messages type                                                                */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8Prm[6];
}
CCP_tstrCmdExchId;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8Len;
   uint8 u8DataTyp;
   uint8 u8ResAvlyMask;
   uint8 u8ResProtnMask;
   uint8 u8NotUsed;
}
CCP_tstrAckExchId;

/* !MComment: declaration of GET_SEED messages type                                                                   */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8ReqSlaveRes;
   uint8 au8NotUsed[5];
}
CCP_tstrCmdGetSeed;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8ProtnSts;
   uint8 au8Key[4];
}
CCP_tstrAckGetSeed;

/* !MComment: declaration of UNLOCK messages type                                                                     */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8Key[6];
}
CCP_tstrCmdUnlck;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8CurPvlgSts;
   uint8 au8NotUsed[4];
}
CCP_tstrAckUnlck;

/* !MComment: declaration of SET_MTA messages type                                                                    */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8MtaIdx;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrCmdSetMta;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckSetMta;

/* !MComment: declaration of DNLOAD messages type                                                                     */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8DataSize;
   uint8 au8Data[5];
}
CCP_tstrCmdDnld;

typedef struct
{
   uint8  u8PktId;
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrAckDnld;

/* !MComment: declaration of DNLOAD_6 messages type                                                                   */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8Data[6];
}
CCP_tstrCmdDnld6;

typedef struct
{
   uint8  u8PktId;
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrAckDnld6;

/* !MComment: declaration of UPLOAD messages type                                                                     */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8DataSize;
   uint8 au8NotUsed[5];
}
CCP_tstrCmdUpld;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8Data[5];
}
CCP_tstrAckUpld;

/* !MComment: declaration of SHORT_UP messages type                                                                   */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8DataSize;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrCmdShoUpld;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8Data[5];
}
CCP_tstrAckShoUpld;

/* !MComment: declaration of SELECT_CAL_PAGE messages type                                                            */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[6];
}
CCP_tstrCmdSelCalPage;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckSelCalPage;

/* !MComment: declaration of GET_DAQ_SIZE messages type                                                               */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8ListIdx;
   uint8  u8NotUsed;
   uint32 u32CanId;
}
CCP_tstrCmdGetDaqSize;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8NoOdt;
   uint8 u8FirstPidOfDaq;
   uint8 au8NotUsed[3];
}
CCP_tstrAckGetDaqSize;

/* !MComment: declaration of SET_DAQ_PTR messages type                                                                */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8ListIdx;
   uint8 u8OdtIdx;
   uint8 u8ElmIdx;
   uint8 au8NotUsed[3];
}
CCP_tstrCmdSetDaqPtr;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckSetDaqPtr;

/* !MComment: declaration of WRITE_DAQ messages type                                                                  */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8Size;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrCmdWrDaq;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckWrDaq;

/* !MComment: declaration of START_STOP messages type                                                                 */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8Mod;
   uint8  u8ListIdx;
   uint8  u8OdtLstIdx;
   uint8  u8EveChn;
   uint16 u16Pslr;
}
CCP_tstrCmdStrtStop;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckStrtStop;

/* !MComment: declaration of DISCONNECT messages type                                                                 */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8Mod;
   uint8  u8NotUsed;
   /* !Comment: endianess is managed directly in configuration                                                        */
   uint16 u16StnAdr;
   uint8  au8NotUsed2[2];
}
CCP_tstrCmdDcnct;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckDcnct;

/* !MComment: declaration of SET_S_STATUS messages type                                                               */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8SsnSts;
   uint8 au8NotUsed[5];
}
CCP_tstrCmdSetSsnSts;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckSetSsnSts;

/* !MComment: declaration of GET_S_STATUS messages type                                                               */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[6];
}
CCP_tstrCmdGetSsnSts;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8SsnSts;
   uint8 u8AddlStsInfoQlfr;
   uint8 au8AddlStsInfo[3];
}
CCP_tstrAckGetSsnSts;

/* !MComment: declaration of BUILD_CHKSUM messages type                                                               */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   #if (CCP_coCPU_BYTE_ORDER == CCP_coMSB_FIRST)
      uint16 u16BlkSizeMSW;
      uint16 u16BlkSizeLSW;
   #else
      uint16 u16BlkSizeLSW;
      uint16 u16BlkSizeMSW;
   #endif
   uint8 au8NotUsed[2];
}
CCP_tstrCmdBldCks;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8CksDataSize;
   uint8 au8CksData[4];
}
CCP_tstrAckBldCks;

/* !MComment: declaration of CLEAR_MEMORY messages type                                                               */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   #if (CCP_coCPU_BYTE_ORDER == CCP_coMSB_FIRST)
      uint16 u16BlkSizeMSW;
      uint16 u16BlkSizeLSW;
   #else
      uint16 u16BlkSizeLSW;
      uint16 u16BlkSizeMSW;
   #endif
   uint8 au8NotUsed[2];
}
CCP_tstrCmdClrMem;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckClrMem;

/*   !MComment: declaration of PROGRAM messages type                                                                  */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8DataSize;
   uint8 au8Data[5];
}
CCP_tstrCmdProg;

typedef struct
{
   uint8  u8PktId;
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrAckProg;

/* !MComment: declaration of PROGRAM_6 messages type                                                                  */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8Data[6];
}
CCP_tstrCmdProg6;

typedef struct
{
   uint8  u8PktId;
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrAckProg6;

/* !MComment: declaration of MOVE messages type                                                                       */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   #if (CCP_coCPU_BYTE_ORDER == CCP_coMSB_FIRST)
      uint16 u16BlkSizeMSW;
      uint16 u16BlkSizeLSW;
   #else
      uint16 u16BlkSizeLSW;
      uint16 u16BlkSizeMSW;
   #endif
   uint8 au8NotUsed[2];
}
CCP_tstrCmdMove;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckMove;

/* !MComment: declaration of DIAG_SERVICE messages type                                                               */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint16 u16DiagcSrvIdx;
   uint8  au8Prm[4];
}
CCP_tstrCmdDiagcSrv;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8Len;
   uint8 u8DataTyp;
   uint8 au8NotUsed[3];
}
CCP_tstrAckDiagcSrv;

/* !MComment: declaration of ACTION_SERVICE messages type                                                             */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint16 u16ActnSrvIdx;
   uint8  au8Prm[4];
}
CCP_tstrCmdActnSrv;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8Len;
   uint8 u8DataTyp;
   uint8 au8NotUsed[3];
}
CCP_tstrAckActnSrv;

/* !MComment: declaration of TEST messages type                                                                       */
typedef struct
{
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   /* !Comment: endianess is managed directly in configuration                                                        */
   uint16 u16StnAdr;
   uint8  au8NotUsed[4];
}
CCP_tstrCmdTest;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckTest;

/* !MComment: declaration of START_STOP_ALL messages type                                                             */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8Mod;
   uint8 au8NotUsed[5];
}
CCP_tstrCmdStrtStopAll;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[5];
}
CCP_tstrAckStrtStopAll;

/* !MComment: declaration of GET_ACTIVE_CAL_PAGE messages type                                                        */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 au8NotUsed[6];
}
CCP_tstrCmdGetAcvCalPage;

typedef struct
{
   uint8  u8PktId;
   uint8  u8CmdCod;
   uint8  u8CmdCtr;
   uint8  u8AdrExtn;
   uint32 u32Adr;
}
CCP_tstrAckGetAcvCalPage;

/* !MComment: declaration of GET_CCP_VERSION messages type                                                            */
typedef struct
{
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8MaiPtclVers;
   uint8 u8RleasWithinVers;
   uint8 au8NotUsed[4];
}
CCP_tstrCmdGetCcpVers;

typedef struct
{
   uint8 u8PktId;
   uint8 u8CmdCod;
   uint8 u8CmdCtr;
   uint8 u8MaiPtclVers;
   uint8 u8RleasWithinVers;
   uint8 au8NotUsed[3];
}
CCP_tstrAckGetCcpVers;

/* !Comment: declaration of Command Receive Object type                                                               */
typedef union
{
   CCP_tstrCmdCnct          strCnct;
   CCP_tstrCmdExchId        strExchId;
   CCP_tstrCmdGetSeed       strGetSeed;
   CCP_tstrCmdUnlck         strUnlck;
   CCP_tstrCmdSetMta        strSetMta;
   CCP_tstrCmdDnld          strDnld;
   CCP_tstrCmdDnld6         strDnld6;
   CCP_tstrCmdUpld          strUpld;
   CCP_tstrCmdShoUpld       strShoUpld;
   CCP_tstrCmdSelCalPage    strSelCalPage;
   CCP_tstrCmdGetDaqSize    strGetDaqSize;
   CCP_tstrCmdSetDaqPtr     strSetDaqPtr;
   CCP_tstrCmdWrDaq         strWrDaq;
   CCP_tstrCmdStrtStop      strStrtStop;
   CCP_tstrCmdDcnct         strDcnct;
   CCP_tstrCmdSetSsnSts     strSetSsnSts;
   CCP_tstrCmdGetSsnSts     strGetSsnSts;
   CCP_tstrCmdBldCks        strBldCks;
   CCP_tstrCmdClrMem        strClrMem;
   CCP_tstrCmdProg          strProg;
   CCP_tstrCmdProg6         strProg6;
   CCP_tstrCmdMove          strMove;
   CCP_tstrCmdDiagcSrv      strDiagcSrv;
   CCP_tstrCmdActnSrv       strActnSrv;
   CCP_tstrCmdTest          strTest;
   CCP_tstrCmdStrtStopAll   strStrtStopAll;
   CCP_tstrCmdGetAcvCalPage strGetAcvCalPage;
   CCP_tstrCmdGetCcpVers    strGetCcpVers;
}
CCP_tuniCmdRxObj;

/* !Comment: declaration of Data Transmission Object type                                                             */
typedef union
{
   CCP_tstrAckCnct          strCnct;
   CCP_tstrAckExchId        strExchId;
   CCP_tstrAckGetSeed       strGetSeed;
   CCP_tstrAckUnlck         strUnlck;
   CCP_tstrAckSetMta        strSetMta;
   CCP_tstrAckDnld          strDnld;
   CCP_tstrAckDnld6         strDnld6;
   CCP_tstrAckUpld          strUpld;
   CCP_tstrAckShoUpld       strShoUpld;
   CCP_tstrAckSelCalPage    strSelCalPage;
   CCP_tstrAckGetDaqSize    strGetDaqSize;
   CCP_tstrAckSetDaqPtr     strSetDaqPtr;
   CCP_tstrAckWrDaq         strWrDaq;
   CCP_tstrAckStrtStop      strStrtStop;
   CCP_tstrAckDcnct         strDcnct;
   CCP_tstrAckSetSsnSts     strSetSsnSts;
   CCP_tstrAckGetSsnSts     strGetSsnSts;
   CCP_tstrAckBldCks        strBldCks;
   CCP_tstrAckClrMem        strClrMem;
   CCP_tstrAckProg          strProg;
   CCP_tstrAckProg6         strProg6;
   CCP_tstrAckMove          strMove;
   CCP_tstrAckDiagcSrv      strDiagcSrv;
   CCP_tstrAckActnSrv       strActnSrv;
   CCP_tstrAckTest          strTest;
   CCP_tstrAckStrtStopAll   strStrtStopAll;
   CCP_tstrAckGetAcvCalPage strGetAcvCalPage;
   CCP_tstrAckGetCcpVers    strGetCcpVers;
}
CCP_tuniDataTxObj;

/* !Comment: declaration of Daqlist transmission Object type                                                          */
typedef struct
{
   uint8 u8PktId;
   uint8 au8Prm[7];
}
CCP_tstrDaqTxObj;

/* !MComment: declaration of message buffers type                                                                     */
typedef union
{
   uint32 au32Data[2]; /* !Comment: alignment on 4-byte boundary                                                      */
   uint8  au8Data[8];
   struct
   {
      uint8 u8CmdCod;
      uint8 u8CmdCtr;
      uint8 au8Prm[6];
   }
   strReq;
   struct
   {
      uint8 u8PktId;
      uint8 u8CmdRtnCod;
      uint8 u8CmdCtr;
      uint8 au8Prm[5];
   }
   strResp;
   CCP_tuniCmdRxObj  uniCmd;
   CCP_tuniDataTxObj uniAck;
}
CCP_tuniPtclMsgBuf;

typedef union
{
   uint32           au32Data[2]; /* !Comment: alignment on 4-byte boundary                                            */
   uint8            au8Data[8];
   CCP_tstrDaqTxObj uniDaq;
}
CCP_tuniDaqMsgBuf;


#endif /* CCP_SRV_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
