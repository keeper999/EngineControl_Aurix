/******************************************************************************/
/*                                                                            */
/* !Layer           : Service Layer                                           */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Diagnostic Communication Manager                        */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Diagnostic Communication Manager                        */
/*                                                                            */
/* !File            : Dcm_Internal.h                                          */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   I:/PROJETS/LIBEMB/LOG/COM/DCM/LOG/Dcm_Internal.h_v           $*/
/* $Revision::   1.6      $$Author::   lvoilmy         $$Date::   22 Nov 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef DCM_INTERNAL_H
#define DCM_INTERNAL_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "Dcm_Dsp_DataServices.h"
#include "Dcm_Cfg.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* State machine values of DspInternal_u8DSP_STATUS & DspInternal_u8DSP_SUBSTATUS */

#define DspInternal_u8BLOCKED                  0xFF

/*!	\Description  Ongoing ReadDataByID Service State */
#define DspInternal_u8RDBI                             0x22

/*!	\Description  Ongoing WriteDataByID Service State */
#define DspInternal_u8WDBI                             0x2E

/*!	\Description  Ongoing IOControlByID Service State */
#define DspInternal_u8IOCTRL                           0x2F

/*! \Description  ReadScalingDataByIdentifier service ID                     */ 
#define DspInternal_u8READ_SCALING_DATA                0x24

/*! \Description  ReadDTCInformation service ID                           /n */ 
#define DspInternal_u8READ_DTC_INFO       (uint8)0x19

/*! Description  reportDTCSnapshotRecordByDTCNumber                       /n */ 
#define DspInternal_u8R2_SNAPSHOTREC_BYDTC    0x04U

/*! Description  reportDTCSnapshotRecordByRecordNumber                    /n */ 
#define DspInternal_u8R3_SNAPSHOTREC_BYNUM    0x05U

/*! Description  reportDTCExtendedDataRecordByDTCNumber                   /n */ 
#define DspInternal_u8R4_EXT_DATA_BY_DTC      0x06U
/*! Description  reportMirrorMemoryDTCExtendedDataRecordByDTCNumber       /n */ 
#define DspInternal_u8R4_M_EXT_DATA_BY_DTC    0x10U



/******************************************************************************/
/*! \Description Negative Response Service Id  \n
    \Range       [0x7F]                        \n
*******************************************************************************/

/*!	\Description  Idle State */
#define DspInternal_u8IDLE                             0x00

#define DspInternal_u8SID_NEG_RESP           (uint8)0x7F

#define E_PAUSE         (Std_ReturnType) 20

#if(DCM_bROE_ENABLED == STD_OFF && DCM_bPERIODIC_TRANS_ENABLED == STD_OFF)
#define DspInternal_u8MAX_NUM_INTERNAL_REQ   (uint8)1
#endif
#if(DCM_bROE_ENABLED == STD_ON && DCM_bPERIODIC_TRANS_ENABLED == STD_OFF)
#define DspInternal_u8MAX_NUM_INTERNAL_REQ   (uint8)2
#endif
#if(DCM_bROE_ENABLED == STD_OFF && DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
#define DspInternal_u8MAX_NUM_INTERNAL_REQ   (uint8)((uint8)1+DCM_u8MAX_NUM_PERIODIC_TX)
#endif
#if(DCM_bROE_ENABLED == STD_ON && DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
#define DspInternal_u8MAX_NUM_INTERNAL_REQ   (uint8)((uint8)2+DCM_u8MAX_NUM_PERIODIC_TX)
#endif

#define DspInternal_u8DSL_MAIN_PROT_CONTEXT  (uint8)0

/******************************************************************************/
/*! \Description Used to set the resDataLen to a value that indicates to the  \n
                 DSL that the response should be suppressed.
  \Range         0x00 \n
*******************************************************************************/
#define DspInternal_udtSUPPRESS_RESP_LENGTH (Dcm_MsgLenType)0x00

/******************************************************************************/
/*! \Description Length of Negative Response  \n
    \Range       [0x03]                       \n
*******************************************************************************/
#define DspInternal_u8NEG_RESPONSE_LENGTH   (uint8)0x03

/******************************************************************************/
/*! \Description Number of Masks    \n
    \Range       [33]               \n
*******************************************************************************/
#define DspInternal_u8MASKS_NUM      33U

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3456]: Macros are used for performance.   */
/* PRQA S 3453 ++                                                             */

/*! \Description  Status of the DSP based on the current context Id */
#define DspInternal_u8DSP_STATUS          (DspInternal_au8eStatus[u8IdContext])
/*! \Description  Sub-Status of the DSP based on the current context Id */
#define DspInternal_u8DSP_SUBSTATUS       (DspInternal_au8eSubStatus[u8IdContext])
/*! \Description  Saved message context based on the current context Id */
#define DspInternal_pu8DSP_MSGCONTEXT     (DspInternal_apstreMsgContext[u8IdContext])

/* PRQA S 3453 --                                                             */


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(Dcm_DslType,DCM_CFG_CONST) Dcm_kstreDslConfig;
extern CONST(Dcm_DsdType,DCM_CFG_CONST) Dcm_kstreDsdConfig;
extern CONST(Dcm_DspType,DCM_CFG_CONST) Dcm_kstreDspConfig;

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#if (DCM_bIO_CONTROL_EN == STD_ON)
/*! \Description Current signal index for ReturnAllDidControlToEcu */
/*! \Range       0..NumOfDidSignal-1 */
extern VAR(uint8,DCM_VAR) DspInternal_u8eRetCtrlSignalIndex;

/*! \Description Current Did index for ReturnAllDidControlToEcu */
/*! \Range       0..DCM_u16NUM_OF_DIDS */
extern VAR(uint16,DCM_VAR) DspInternal_u16eRetCtrlDidIndex;

/*! \Description Flag indicating if return all signals to ECU control is in
                 progress or not */
/*! \Range       TRUE, FALSE */
extern VAR(boolean,DCM_VAR) DspInternal_beRetCtrl;

/*! \Description Flag indicating if return all signals to ECU control is in
                 pending status or not */
/*! \Range       TRUE, FALSE */
extern VAR(boolean,DCM_VAR) DspInternal_beRetCtrlPending;
#endif




#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*! \Description Pointer to the current message context                     */
/*! \Range       Null, Not Null                                             */
extern P2VAR(Dcm_MsgContextType,DCM_VAR,DCM_VAR)
                    DspInternal_apstreMsgContext[DspInternal_u8MAX_NUM_INTERNAL_REQ];

/*! \Description Dsp Main State Machine */
/*! \Range       DspInternal_u8IDLE, DSP_u8CLEAR_DIAG_INFO, DspInternal_u8RDBI, DspInternal_u8WDBI, DspInternal_u8IOCTRL    */
extern uint8 DspInternal_au8eStatus[DspInternal_u8MAX_NUM_INTERNAL_REQ];

/*! \Description Dsp Sub State Machine */
/*! \Range       DspInternal_u8IDLE, DspInternal_u8RDBI_CONDITION_CHECK_PENDING,
                 DspInternal_u8RDBI_READ_PENDING, DspInternal_u8RDBI_READ_NEXT_DID,
                 DspInternal_u8RDBI_READ_NEXT_SIGNAL, DspInternal_u8WDBI_PENDING,
                 DspInternal_u8WDBI_WRITE_NEXT_DATA
                 ReadDTCInformation:                                     /n
                 u8R1_NUM_DTC_BY_STM,         u8R5_NUM_DTC_BY_SEVMSK,    /n
                 u8R1_DTC_BY_STM,             u8R5_DTC_BY_SEVMASK,       /n
                 u8R1_M_DTC_BY_STM,           u8R6_SEV_INFO_OF_DTC,      /n
                 u8R1_NUM_M_DTC_BY_STM,       u8R7_SUPPORTED_DTC,        /n
                 u8R1_NUM_OBDDTC_BY_STM,     u8R7_FIRST_FAIL_DTC,        /n
                 u8R1_OBD_DTC_BY_STM,         u8R7_FIRST_CONF_DTC,       /n
                 u8R2_SNAPSHOT_ID,            u8R7_RECENT_FAIL_DTC,      /n
                 DspInternal_u8R2_SNAPSHOTREC_BYDTC,     u8R7_RECENT_CONF_DTC,       /n
                 DspInternal_u8R3_SNAPSHOTREC_BYNUM,     u8R7_FAULT_DET_COUNTER,     /n
                 DspInternal_u8R4_EXT_DATA_BY_DTC,        u8R7_DTC_WITH_PERM_ST,     /n
                 DspInternal_u8R4_M_EXT_DATA_BY_DTC,                                 /n
                                                                         /n
                 RoutineControl:                                         /n
                 u8RC_START_PENDING,      u8RC_STOP_RCRRP_OK,            /n
                 u8RC_START_RCRRP,        u8RC_RESULT_PENDING,           /n
                 u8RC_START_RCRRP_OK,     u8RC_RESULT_RCRRP,             /n
                 u8RC_STOP_PENDING,       u8RC_RESULT_RCRRP_OK,          /n
                 u8RC_STOP_RCRRP                                         /n
                                                                         /n */
extern uint8 DspInternal_au8eSubStatus[DspInternal_u8MAX_NUM_INTERNAL_REQ];

#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
extern VAR(boolean,DCM_VAR) DspInternal_abePageUpdate[DspInternal_u8MAX_NUM_INTERNAL_REQ];
extern VAR(boolean,DCM_VAR) DspInternal_abePagedMode[DspInternal_u8MAX_NUM_INTERNAL_REQ];
#endif

extern P2CONST(Dcm_ConfigType,DCM_VAR,DCM_APPL_CONST) Dcm_pkstrePbConfig;
extern VAR(boolean,DCM_VAR) Dcm_beInitDone;


#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
extern CONST(Dcm_tpfu8RoutineSubfunction,DCM_CFG_CONST)
  DspInternal_akpfeRoutineStart[DCM_u8NUM_OF_ROUTINES];

extern CONST(Dcm_tpfu8RoutineSubfunction,DCM_CFG_CONST)
  DspInternal_akpfeRoutineStop[DCM_u8NUM_OF_ROUTINES];

extern CONST(Dcm_tpfu8ResultSubfunction,DCM_CFG_CONST)
  DspInternal_akpfeRoutineRequestResult[DCM_u8NUM_OF_ROUTINES];
#endif

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
#if((DCM_bECU_RESET_EN == STD_ON) || (DCM_bJUMP_TO_BOOT_EN == STD_ON))
extern VAR(Dcm_ResetModeType,DCM_VAR)  Dcm_u8eRequestedResetMode;
#endif

extern VAR(Dcm_SesCtrlType,DCM_VAR) Dcm_u8eRequestedSesMode;

#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"
/* PRQA L:L1 */

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */
/*              for memory allocation and should be included several times.  */
/* PRQA S 5087,0838 L1 */
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */

/******************************************************************************/
/********                          DSP                           **************/
/******************************************************************************/
#if ((DCM_bIO_CONTROL_EN == STD_ON)           || \
     (DCM_bRDBI_EN == STD_ON)                 || \
     (DCM_bROUTINE_CONTROL_ENABLED == STD_ON) || \
     (DCM_bOBD_SERVICES_ENABLED == STD_ON))
extern FUNC(void,DCM_CODE) DspInternal_vidInjectSignalIntoBuff(
   P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8SignalIn,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)   pu8BuffOut,
   VAR(uint16,AUTOMATIC)                  u16DataStartByte,
   VAR(uint8,AUTOMATIC)                   u8DataBitOffset,
   VAR(uint16,AUTOMATIC)                  u16LengthBits,
   VAR(uint16,AUTOMATIC)                  u16TotalLength,
   VAR(boolean,AUTOMATIC)                 bEndianConv);
#endif

#if ((DCM_bWDBI_EN == STD_ON)                 || \
     (DCM_bROUTINE_CONTROL_ENABLED == STD_ON) || \
     (DCM_bREAD_DTC_INFO_ENABLED == STD_ON)   || \
     (DCM_bIO_CONTROL_EN == STD_ON))
extern FUNC(void,DCM_CODE) DspInternal_vidExtractSignalFromBuff(
   P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8BuffIn,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)   pu8SignalOut,
   VAR(uint16,AUTOMATIC)                  u16DataStartByte,
   VAR(uint8,AUTOMATIC)                   u8DataBitOffset,
   VAR(uint16,AUTOMATIC)                  u16LengthBits,
   VAR(uint16,AUTOMATIC)                  u16TotalLength,
   VAR(boolean,AUTOMATIC)                 bEndianConv,
   VAR(boolean,AUTOMATIC)                 bSigned);
#endif

extern FUNC(void,DCM_CODE) DspInternal_Init(void);
extern FUNC(void,DCM_CODE) DspInternal_Main(void);

extern void DspInternal_SecurityAccess(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);
    
extern void DspInternal_ControlDTCSetting(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);   

extern void DspInternal_RequestDownload(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);  
    
extern void DspInternal_TransferData(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);  

extern void DspInternal_RequestTransferExit(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);     

extern void DspInternal_TesterPresent(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);

extern void DspInternal_DiagnosticSessionControl(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);

extern void DspInternal_ECUReset(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);

#if (DCM_bRDBI_EN == STD_ON)
  extern void DspInternal_ReadDataByIdentifier(
      P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);
  extern FUNC(void,DCM_CODE) DspInternal_vidMainRdbi (Dcm_IdContextType u8IdContext);
#endif
#if(DCM_bREAD_DTC_INFO_ENABLED == STD_ON)
  extern FUNC(void,DCM_CODE) DspInternal_vidMainReadDTCInfo(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
#endif

#if (DCM_bWDBI_EN == STD_ON)
  extern void DspInternal_WriteDataByIdentifier(
      P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);
  extern FUNC(void,DCM_CODE) DspInternal_vidMainWdbi (Dcm_IdContextType u8IdContext);
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)
  extern void DspInternal_InputOutputControlByIdentifier (
      P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
  extern FUNC(void,DCM_CODE) DspInternal_vidMainIoctrl (Dcm_IdContextType u8IdContext);
  extern FUNC(void,DCM_CODE) DspInternal_vidIoCtrlReturnAllDidCtrlToEcu (
          uint16 u16DidIndexStart,
          uint8 u8SignalIndexStart,
          uint8 u8NumOfSigToCtrl,
          Dcm_OpStatusType u8IOCTRLOpStatus,
          Dcm_NegativeResponseCodeType * pu8NegResCode);
#endif

extern void DspInternal_ClearDiagnosticInformation(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);

extern void DspInternal_DcmConfirmation(Dcm_IdContextType idContext,
                                 PduIdType dcmRxPduId,
                                 Dcm_ConfirmationStatusType status);

extern FUNC(void,DCM_CODE) DspInternal_vidSessionTransNotify
  (Dcm_SesCtrlType u8OldSession, Dcm_SesCtrlType u8NewSession);
extern FUNC(void,DCM_CODE) DspInternal_vidProtPreemptNotify(void);

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)

extern FUNC(void,DCM_CODE) DspInternal_UpdatePage(Dcm_IdContextType idContext);
#endif

#if(DCM_bROE_ENABLED == STD_ON)
extern FUNC(void,DCM_CODE) DspInternal_vidCancelRoeTransmissions(void);
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
extern FUNC(void,DCM_CODE) DspInternal_vidCancelPeriodicTransmissions(void);
#endif

#if(DCM_bREAD_DTC_INFO_ENABLED == STD_ON)
extern FUNC(void,DCM_CODE) DspInternal_ReadDTCInformation(
   P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
#endif

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
extern FUNC(void,DCM_CODE) DspInternal_RoutineControl(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
#endif

#if(DCM_bREAD_SCALING_DATA_EN == STD_ON)
extern FUNC(void,DCM_CODE) DspInternal_ReadScalingDataByIdentifier(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pstrMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_vidMainReadScaling(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
extern FUNC(void,DCM_CODE) DspInternal_ReadDataByPeriodicIdentifier(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_vidMainPeriodicIdentifiers(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
extern FUNC(void,DCM_CODE) DspInternal_vidInitPeriodicIdentifiers(void);
#endif

#if (DCM_bOBD_SERVICES_ENABLED == STD_ON)
extern FUNC(void, DCM_CODE) DspInternal_OBDMain(uint8 u8IdContext);
extern FUNC(void, DCM_CODE) DspInternal_OBDService01(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService02(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService03(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService04(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService06(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService07(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService08(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService09(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DspInternal_OBDService0A(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);
#endif

#if((DCM_bOBD_SERVICES_ENABLED == STD_ON)||(DCM_bRDBI_EN == STD_ON))
extern FUNC(boolean, DCM_CODE) DspInternal_bIsSupportedVehInfo (
    uint8 u8VehInfoType,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8VehInfoIdx);
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_udtReadVehInfoData (
  uint8 u8VehInfoIdx,
  Dcm_OpStatusType udtOpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8Buffer,
  P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufferIndex,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8DataIndex,
  uint32 u32MaxResLen);
extern FUNC(boolean, DCM_CODE) DspInternal_bIsSupportedOBDMID (
    uint8 u8OBDMID,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8Index);
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_udtReadMIDData(
    uint8 u8MID,
    P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufferIndex,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8DataIndex,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8Buffer,
    uint16 u16MaxLength);
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_udtReadPIDData (
  uint8 u8PIDIndex,
  Dcm_OpStatusType udtOpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8Buffer,
  P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufferIndex,
  P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8DataIndex,
  uint8 u8Context);
extern FUNC(boolean, DCM_CODE) DspInternal_bIsPIDSupported (
    VAR(uint8, DCM_VAR) u8PID, 
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pu8PIDIndex);
extern FUNC(void, DCM_CODE) DspInternal_vidSetAvailablRes(
    P2CONST(uint8,AUTOMATIC,DCM_VAR) pku8InBuffer,
    uint8 u8BufInLength,
    P2VAR(uint8,AUTOMATIC,DCM_VAR) pu8OutBuffer,
    P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16BufOutLength,
    uint8 u8ServiceID);
#endif
/******************************************************************************/
/********                          DSD                           **************/
/******************************************************************************/
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
extern FUNC(void,DCM_CODE) DsdInternal_Init(void);
extern FUNC(void,DCM_CODE) DsdInternal_Main(void);
extern FUNC(void,DCM_CODE) DsdInternal_StartPagedProcessing(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);
extern FUNC(void,DCM_CODE) DsdInternal_ProcessPage(
    Dcm_IdContextType idContext,Dcm_MsgLenType FilledPageLen);
extern FUNC(void,DCM_CODE) DsdInternal_UpdatePage(Dcm_IdContextType idContext);
extern FUNC(void,DCM_CODE) DsdInternal_CancelPagedBuffer(void);
#endif

extern FUNC(void,DCM_CODE) DsdInternal_SetNegResponse(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext ,
    uint8 u8NegRespCode);

extern FUNC(void,DCM_CODE) DsdInternal_Confirmation(
    Dcm_IdContextType idContext,
    PduIdType dcmRxPduId,
    NotifResultType result);

extern FUNC(void,DCM_CODE) DsdInternal_ProcessingDone(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext);

extern FUNC(void,DCM_CODE) DsdInternal_DataIndication(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
    uint8  u8ProtocolSIDTable);

/******************************************************************************/
/********                          DSL                           **************/
/******************************************************************************/
extern FUNC(void,DCM_CODE) DslInternal_Main(void);
extern FUNC(void,DCM_CODE) DslInternal_Init(void);

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
extern FUNC(void,DCM_CODE) DslInternal_ProcessPage(
    Dcm_IdContextType idContext,
    Dcm_MsgLenType FilledPageLen);
extern FUNC(void,DCM_CODE) DslInternal_PageBufferFailed(
    Dcm_IdContextType u8IdContext);
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
FUNC(Dcm_StatusType, DCM_CODE) DslInternal_ResponseOnOneDataByPeriodicId(
    uint8 u8PeriodicId);
#endif

#if(DCM_bROE_ENABLED == STD_ON)
#if(DCM_bDSP_ROE_QUEUE_ENABLED == STD_ON)
FUNC(Dcm_StatusType, DCM_CODE) DslInternal_ResponseOnOneEvent(
    Dcm_MsgLenType MsgLen,
    PduIdType DcmRxPduId,
    boolean bQueued);
FUNC(void, DCM_CODE) DslInternal_vidClearRoeTxQueue(void);
#else
FUNC(Dcm_StatusType, DCM_CODE) DslInternal_ResponseOnOneEvent(
    Dcm_MsgLenType MsgLen,
    PduIdType DcmRxPduId);
FUNC(void, DCM_CODE) DslInternal_vidClearRoeTxQueue(void);
#endif
#endif

extern FUNC(void,DCM_CODE) DslInternal_ProcessingDone(
    Dcm_IdContextType idContext);
      
extern FUNC(void,DCM_CODE) DslInternal_SetSecurityLevel(
    Dcm_SecLevelType SecurityLevel);

extern FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType(
    Dcm_SesCtrlType SesCtrlType);

extern FUNC(void,DCM_CODE) DslInternal_vidForceRCRRP(
    Dcm_IdContextType udtIdContext);

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */
/*              for memory allocation and should be included several times.  */
/* PRQA S 5087,0838 L1 */

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/* PRQA L:L1 */

#endif /* DCM_INTERNAL_H */

/*-------------------------------- end of file -------------------------------*/
