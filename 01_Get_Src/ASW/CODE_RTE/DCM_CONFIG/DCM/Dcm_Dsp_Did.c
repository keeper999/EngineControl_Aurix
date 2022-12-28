/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dsp                                                     */
/* !Description     : Diagnostic Communication Manager                        */
/*                                                                            */
/* !Module          : Dsp                                                     */
/* !Description     : Diagnostic Service Processing                           */
/*                                                                            */
/* !File            : Dcm_Dsp_Did.c                                           */
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
/* $Archive::   Y:/Prod_01/B791031T0/archives/B791031T0/04_Software_Component$*/
/* $Revision::   1.21.1.0 $$Author::   aalaa          $$Date::   Jul 07 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file
*
* \par
*   Internals of the module DSP. \n
*   This file contains the internals of the module DSP.  */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup  Dsp_Comp_Id Dsp Component
* Diagnostic Service Processing
* \{
*/
/*! \defgroup DSP_Module_Id Dsp Module
* This is the grouping of Dsp module members.
* \{
*/
/******************************************************************************/


/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#include "Dcm.h"
#include "Dcm_Cfg.h"
#include "Dcm_Internal.h"
#include "Rte_Dcm.h"
#include "SchM_Dcm.h"


#if (DCM_bNVM_USED == STD_ON)
#include "Nvm.h"
#endif

#if (DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/* PRQA L:L1                                                                  */


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* State machine values of DspInternal_u8DSP_STATUS & DspInternal_u8DSP_SUBSTATUS */

/*!	\Description  Cancelling the current service */
#define u8CANCEL                           0x7F

/*!	\Description  Read Condition Check function is pending */
#define u8RDBI_COND_CHK_PEND     0x01
/*!	\Description  Read function is pending */
#define u8RDBI_READ_PENDING                0x02
/*!	\Description  Next step is to read next Did */
#define u8RDBI_READ_NEXT_DID               0x03
/*!	\Description  Next step is to read next signal */
#define u8RDBI_READ_NEXT_SIG            0x04


/*!	\Description  Write function is pending */
#define u8WDBI_PENDING                     0x01
/*!	\Description  Next step is to write next signal */
#define u8WDBI_WRITE_NEXT_DATA             0x02


/* Sub-status values of IOControl should never coincide with RDBI sub-status
   values */
/*!	\Description  Control function is pending */
#define u8IOCTRL_PENDING                   0x11
/*!	\Description  Next step is to control next signal */
#define u8IOCTRL_CONT_NXT_DATA         0x12


/* DID Types */
/*!	\Description  Type of DID is UDS */
#define u8DID_UDS  ((uint8)0)
/*!	\Description  Type of DID is OBD - Range 1 */
#define u8DID_OBD1 ((uint8)2)
/*!	\Description  Type of DID is OBD - Range 2 */
#define u8DID_OBD2 ((uint8)3)
/*!	\Description  Type of DID is OBD - Range 3 */
#define u8DID_OBD3 ((uint8)4)
/*!	\Description  Type of DID is OBD - Range 1 - Availability - Service $01 */
#define u8DID_OBD1_AVAIL ((uint8)1)
/*!	\Description  Type of DID is OBD - Range 2 - Availability - Service $06 */
#define u8DID_OBD2_AVAIL ((uint8)6)
/*!	\Description  Type of DID is OBD - Range 3 - Availability - Service $09 */
#define u8DID_OBD3_AVAIL ((uint8)9)


/* DID Ranges */
/*!	\Description  Minimum of DID range1 of UDS */
#define u16UDS_DID_RANGE1_MIN ((uint16)0x00FF)
/*!	\Description  Maximum of DID range1 of UDS */
#define u16UDS_DID_RANGE1_MAX ((uint16)0xF1FF)

/*!	\Description  Minimum of range of Dynamic DIDs */
#define u16DYN_DID_RANGE_MIN ((uint16)0xF200)
/*!	\Description  Maximum of range of Dynamic DIDs */
#define u16DYN_DID_RANGE_MAX ((uint16)0xF3FF)

/*!	\Description  Minimum of DID range1 of OBD */
#define u16OBD_DID_RANGE1_MIN ((uint16)0xF400)
/*!	\Description  Maximum of DID range1 of OBD */
#define u16OBD_DID_RANGE1_MAX ((uint16)0xF4FF)

/*!	\Description  Minimum of DID range2 of OBD */
#define u16OBD_DID_RANGE2_MIN ((uint16)0xF600)
/*!	\Description  Maximum of DID range2 of OBD */
#define u16OBD_DID_RANGE2_MAX ((uint16)0xF6FF)

/*!	\Description  Minimum of DID range3 of OBD */
#define u16OBD_DID_RANGE3_MIN ((uint16)0xF800)
/*!	\Description  Maximum of DID range3 of OBD */
#define u16OBD_DID_RANGE3_MAX ((uint16)0xF8FF)

/*!	\Description  Minimum of DID range2 of UDS */
#define u16UDS_DID_RANGE2_MIN ((uint16)0xF900)
/*!	\Description  Maximum of DID range2 of UDS */
#define u16UDS_DID_RANGE2_MAX ((uint16)0xFEFF)

/*! \Description  DID defined by ISO for active session */
#define u16ACTIVE_SESSION_DID ((uint16)0xF186)

/* InputOutputControl Service macros */
/*!	\Description  Valid values of IOControlParam inside IOControl message */
#define u8IOCTRL_RET_CTRL_ECU  (uint8)0 
/*!	\Description  Valid values of IOControlParam inside IOControl message */
#define u8IOCTRL_RESET_DEFAULT      (uint8)1
/*!	\Description  Valid values of IOControlParam inside IOControl message */
#define u8IOCTRL_FREEZE_STATE  (uint8)2
/*!	\Description  Valid values of IOControlParam inside IOControl message */
#define u8IOCTRL_SHORT_ADJUST (uint8)3

/*!	\Description  Index of ControlState field inside PR message of IOControl */
#define u16IOCTRL_PR_CT_ST_IDX (uint16)3
/*!	\Description  Value of IOControlParam in the IOControl message (VNR Name) */
#define u8IOCTRL_CONTROL_PARAM        (pkstrMsgContext->reqData[2])
/*!	\Description  Value of IOControlParam in the IOCtrl message (AutoSAR Name)*/
#define u8IOCTRL_CTRL_PARAM_AR     (pMsgContext->reqData[2])
/*!	\Description  Value of IOControlState in the IOControl message */
#define u8IOCTRL_CTRL_STATE           (pkstrMsgContext->reqData[3])
/*!	\Description  Value of Did inside the IOControl message */
#define u16IOCTRL_DATA_ID             ((uint16)\
                                      ((((uint32)pMsgContext->reqData[0])<<8) +\
                                         (uint32)pMsgContext->reqData[1]))


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3456]: Macros are used for performance.   */
/* PRQA S 3453 ++                                                             */

/*! \Description  Masks of size one byte starts from the most significant bit */
#define u8MSB_MASK(x)         ((uint8)(0x80>>(x)))

/*! \Description  Current signal index based on the current context Id */
#define u8DSP_SIGNAL_INDEX       (Dsp_au8SignalIndex[u8IdContext])

/*! \Description  Current Tx buffer index based on the current context Id */
#define u16DSP_TX_BUFF_INDEX     (Dsp_au16TxBufferIndex[u8IdContext])

/*! \Description  Current data length based on the current context Id */
#define u16DSP_DATA_LEN          (Dsp_au16DataLength[u8IdContext])

/*! \Description  Current Did array index based on the current context Id */
#define u16DSP_DID_ARR_INDEX     (Dsp_au16DidArrayIndex[u8IdContext])

/*! \Description  Current number of Dids based on the current context Id */
#define u16DSP_NUM_DID           (Dsp_au16NumOfDid[u8IdContext])

/*! \Description  Current xxx based on the current context Id */
#define bDSP_IOCTRL_MASK         (Dsp_abIoCtrlMaskExist[u8IdContext])

/*! \Description  Current xxx based on the current context Id */
#define au8DSP_SIGNAL_BUFF       (Dsp_au8SignalBuffer[u8IdContext])

/*! \Description  Current xxx based on the current context Id */
#define u16DSP_DID_IDX          (Dsp_au16DidIndices[u8IdContext])

/*! \Description  Current xxx based on the current context Id */
#define au8DSP_DID_TYPES         (Dsp_au8DidTypes[u8IdContext])

/*! \Description  Current xxx based on the current context Id */
#define u16DSP_RX_BUFF_INDEX     (Dsp_au16RxBufferIndex[u8IdContext])

/*! \Description  Current xxx based on the current context Id */
#define u16DSP_DID_LST_DATA_LEN (Dsp_au16DidLastDataLength[u8IdContext])





/* !Deviation : Macros are needed for code readability and maintenance       */ 
/* PRQA S 3459 ++ */
#define vidRESPOND_NRC(u8NegRespCode) \
 do { \
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE; \
    DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context],u8NegRespCode);\
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]); \
 } while(0)

#define vidRESPOND_OK() \
 do { \
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE; \
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]); \
 } while(0)
/* PRQA S 3459 -- */

/* PRQA S 3453 --                                                             */


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

#if (DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
#define u8PERIODIC_MODE_IDLE   (uint8)0x00
#define u8PERIODIC_MODE_SLOW   (uint8)0x01
#define u8PERIODIC_MODE_MEDIUM (uint8)0x02
#define u8PERIODIC_MODE_FAST   (uint8)0x03
#define u8PERIODIC_MODE_STOP   (uint8)0x04
/*! \Description  Data structure for the periodic schedular                  */ 
typedef struct {
  uint8   u8DID;
  uint8   u8Mode;
  boolean bCall;
  #if (DCM_u32PERIODIC_MAX_RESPONSES > 0)
  uint32  u32Responses;
  #endif
} tstrPeriodicScheduler;

/*! \Description  Data structure for ReadDataByPeriodicIdentifier service    */ 
typedef struct {
  uint16                u16CounterSlow;
  uint16                u16CounterMedium;
  uint16                u16CounterFast;
  tstrPeriodicScheduler strScheduler[DCM_u8MAX_NUM_PERIODIC_TX];
} tstrPeriodicData;
#endif

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"

#if (DCM_bIO_CONTROL_EN == STD_ON)

/* !Deviation : Variables are defined in C files not header files   */
/* PRQA S 3406 L2                                                            */
/*! \Description Flag indicating if return all signals to ECU control is in
                 progress or not */
/*! \Range       TRUE, FALSE */
VAR(boolean,DCM_VAR) DspInternal_beRetCtrl;

/*! \Description Flag indicating if return all signals to ECU control is in
                 pending status or not */
/*! \Range       TRUE, FALSE */
VAR(boolean,DCM_VAR) DspInternal_beRetCtrlPending;
/* PRQA L:L2                                                            */

#endif

#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"


#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if (DCM_bIO_CONTROL_EN == STD_ON)
/*! \Description Flag indicating existance of ControlEnableMask in
                 InputOutputControl message */
/*! \Range       TRUE, FALSE */
static VAR(boolean,DCM_VAR) Dsp_abIoCtrlMaskExist[DspInternal_u8MAX_NUM_INTERNAL_REQ];
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON     ||     \
       DCM_bWDBI_EN == STD_ON)

/* !Deviation : Inhibit MISRA rule [3218, 3207]: Global variable used in more
                than one function but due to configuration, functions may be
                disabled and it appears as if only used in one function or
                none.                                                         */
/* PRQA S 3218 ++                                                             */
/* PRQA S 3207 ++                                                             */

/*! \Description  Buffer to store the value of a Data */
static VAR(uint8,DCM_VAR)
  Dsp_au8SignalBuffer[DspInternal_u8MAX_NUM_INTERNAL_REQ]
                     [DCM_u16DSP_MAX_DID_SIGNAL_SIZE];

/*! \Description  Arrays of indices & types of DIDs inside configuration array*/
#if (DCM_u16DSP_MAX_DID_TO_READ != 0U)
  static VAR(uint16,DCM_VAR)
    Dsp_au16DidIndices[DspInternal_u8MAX_NUM_INTERNAL_REQ][DCM_u16DSP_MAX_DID_TO_READ];
  static VAR(uint8,DCM_VAR)
    Dsp_au8DidTypes[DspInternal_u8MAX_NUM_INTERNAL_REQ][DCM_u16DSP_MAX_DID_TO_READ];
#else
  static VAR(uint16,DCM_VAR)
    Dsp_au16DidIndices[DspInternal_u8MAX_NUM_INTERNAL_REQ][DCM_u16NUM_OF_DIDS];
  static VAR(uint8,DCM_VAR)
    Dsp_au8DidTypes[DspInternal_u8MAX_NUM_INTERNAL_REQ][DCM_u16NUM_OF_DIDS];
#endif

/* PRQA S 3207 ++                                                             */
/* PRQA S 3218 --                                                             */
#endif

#if (DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
static VAR(tstrPeriodicData,DCM_VAR) Dsp_strPeriodicData;
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON     ||     \
       DCM_bWDBI_EN == STD_ON)
/*! \Description Current signal index inside the Did config array */
/*! \Range       0..NumOfDidSignal-1 */
/* PRQA S 2200 ++                                                             */
static VAR(uint8,DCM_VAR) Dsp_au8SignalIndex[DspInternal_u8MAX_NUM_INTERNAL_REQ];
/* PRQA S 2200 --                                                             */
#endif

#if (DCM_bRDBI_EN == STD_ON     ||     \
       DCM_bWDBI_EN == STD_ON)

/* !Deviation : Inhibit MISRA rule [3218, 3207]: Global variable used in more
                than one function but due to configuration, functions may be
                disabled and it appears as if only used in one function or
                none.                                                         */
/* PRQA S 3218 ++                                                             */
/* PRQA S 3207 ++                                                             */
/*! \Description Current index inside the buffer of Rx */
/*! \Range       0..RxBufferSize-1 */
static VAR(uint16,DCM_VAR) Dsp_au16RxBufferIndex[DspInternal_u8MAX_NUM_INTERNAL_REQ];
/* PRQA S 3207 --                                                             */
/* PRQA S 3218 --                                                             */

#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON)
/*! \Description Current index inside the buffer of Tx */
/*! \Range       0..TxBufferSize-1 */
static VAR(uint16,DCM_VAR) Dsp_au16TxBufferIndex[DspInternal_u8MAX_NUM_INTERNAL_REQ];

/*! \Description Current signal data length */
/*! \Range       0..65535 */
static VAR(uint16,DCM_VAR) Dsp_au16DataLength[DspInternal_u8MAX_NUM_INTERNAL_REQ];

/*! \Description Current Did index inside the DSP local DID array */
/*! \Range       0..DCM_u16DSP_MAX_DID_TO_READ-1 */
static VAR(uint16,DCM_VAR) Dsp_au16DidArrayIndex[DspInternal_u8MAX_NUM_INTERNAL_REQ];

/*! \Description Number of supported DIDs inside the request message */
static VAR(uint16,DCM_VAR) Dsp_au16NumOfDid[DspInternal_u8MAX_NUM_INTERNAL_REQ];
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)

/*! \Description Did last signal data length */
/*! \Range       0..65535 */
static VAR(uint16,DCM_VAR) Dsp_au16DidLastDataLength[DspInternal_u8MAX_NUM_INTERNAL_REQ];

#endif

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"

#if (DCM_bIO_CONTROL_EN == STD_ON)
/*! \Description Current signal index for ReturnAllDidControlToEcu */
/*! \Range       0..NumOfDidSignal-1 */
/* !Deviation : Variables are defined in C files not header files   */
/* PRQA S 3406 L2                                                            */
VAR(uint8,DCM_VAR) DspInternal_u8eRetCtrlSignalIndex;
/* PRQA L:L2                                                            */
#endif

#if(DCM_bREAD_SCALING_DATA_EN == STD_ON)
/*! \Description Signal index to be processed in next cycle for              
                 ReadScalingDataByIdentifier */
/*! \Range       0..255 */
static VAR(uint8,DCM_VAR) Dsp_u8ScalingIndex;
#endif

#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"


#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"

#if (DCM_bIO_CONTROL_EN == STD_ON)
/* !Deviation : Variables are defined in C files not header files   */
/* PRQA S 3406 L2                                                            */
/*! \Description Current Did index for ReturnAllDidControlToEcu */
/*! \Range       0..DCM_u16NUM_OF_DIDS */
VAR(uint16,DCM_VAR) DspInternal_u16eRetCtrlDidIndex;
/* PRQA L:L2                                                            */

#endif

#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/* PRQA L:L1 */

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 


#if ((DCM_bIO_CONTROL_EN == STD_ON) || (DCM_bWDBI_EN == STD_ON))
static FUNC(boolean,DCM_CODE) bExtractSignalFromDid (
    uint16 u16DidArrayIndex,
    uint8  u8SignalIndex,
    uint32 u32DataRef,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext,
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8NegResCode,
    uint8 u8ServiceStatus);
#endif


#if (DCM_bIO_CONTROL_EN == STD_ON)
static FUNC(boolean,DCM_CODE) bCheckDidCtrlSess(uint16 u16DidIndex);
static FUNC(boolean,DCM_CODE) bCheckDidCtrlSec(uint16 u16DidIndex);
static uint8 u8CallIoControlAppl(uint32 u32DataRef,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext,
    uint8 u8IOCTRLOpStatus);
static FUNC(boolean,DCM_CODE) bIoControlDid (
    Dcm_OpStatusType u8IOCTRLOpStatus,
    uint8 u8NumOfSigToCtrl,
    uint8 u8SignalIndexStart,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext);
#endif

#if (DCM_bWDBI_EN == STD_ON)
static FUNC(boolean,DCM_CODE) bCheckDidWriteSession(uint16 u16DidIndex);
static FUNC(boolean,DCM_CODE) bCheckDidWriteSec(uint16 u16DidIndex);
static FUNC(boolean,DCM_CODE) bWriteDidAllSignals (
       uint8 u8SignalIndexStart,
       Dcm_OpStatusType u8WriteCheckStatus,
       boolean bFixedLength,
       uint16 u16NumOfSignalsToWrite,
       P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pstrMsgContext,
       P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode);
#endif
  

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON)
static FUNC(boolean,DCM_CODE) bCheckDidReadSession(uint16 u16DidIndex);
static FUNC(boolean,DCM_CODE) bCheckDidReadSecurity(uint16 u16DidIndex);
static FUNC(boolean,DCM_CODE) bCheckDidSupported(
    uint16 u16Did,P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DidIndex);
static FUNC(boolean,DCM_CODE) bReadDidSignal(uint16 u16DidArrayIndex,
         uint8  u8SignalIndex,
         P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8NegResCode,
         Dcm_OpStatusType u8ReadOpStatus,
         uint8 u8ServiceStatus,
         Dcm_IdContextType u8IdContext);
static FUNC(boolean,DCM_CODE) bReadActiveSessionDid (
         P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8NegResCode,
         uint8 u8ServiceStatus,
         Dcm_IdContextType u8IdContext);
static FUNC(boolean,DCM_CODE) bReadMaxNumofDid (
         P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8NegResCode,
         uint8 u8ServiceStatus,
         Dcm_IdContextType u8IdContext);
static FUNC(boolean,DCM_CODE) bCheckDidConditions (
        uint16 u16DidArrayIndex,
        uint8  u8SignalIndexStart,
        Dcm_OpStatusType u8CondCheckStatus,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
        P2VAR(boolean,AUTOMATIC,AUTOMATIC) pbLoopEnd,
        uint8 u8ServiceStatus,
        Dcm_IdContextType u8IdContext);
static FUNC(boolean,DCM_CODE) bReadDidAllSignals (
        uint16 u16DidArrayIndex,
        uint8  u8SignalIndexStart,
        Dcm_OpStatusType u8ReadCheckStatus,
        uint16 u16NumOfSignalsToRead,
        P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pstrMsgContext,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
        P2VAR(boolean,AUTOMATIC,AUTOMATIC) pbLoopEnd,
        P2VAR(uint16,AUTOMATIC,AUTOMATIC) pu16NumOfReadSignals,
        uint8 u8ServiceStatus);
static FUNC(boolean,DCM_CODE) bFullCheckDid (
        P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode);

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
static FUNC(uint32,DCM_CODE) u32ReadingGetFullLength (
        P2VAR(uint32,AUTOMATIC,AUTOMATIC) pu32MaximumData,
        uint8 u8IdContext);
#endif
#endif

#if(DCM_bREAD_SCALING_DATA_EN == STD_ON)
static FUNC(uint32,DCM_CODE) u32ScalingGetFullLength(
  P2VAR(uint32,AUTOMATIC,AUTOMATIC) pu32MaximumData,
  uint8 u8IdContext);
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
static FUNC(boolean,DCM_CODE) bEnoughSlotsInScheduler(
  P2VAR(uint8,AUTOMATIC,AUTOMATIC) au8DidList,
  VAR(uint8,AUTOMATIC)             u8DidCount);
static FUNC(void,DCM_CODE) vidUpdateScheduler(
  VAR(uint8,AUTOMATIC) u8Did,
  VAR(uint8,AUTOMATIC) u8TxMode);
#endif

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

#if (DCM_bIO_CONTROL_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To     CDD-DSP-0001(0), CDD-DSP-0002(0), CDD-# DSP-0003(0)       \n\n
    \Description  Return all the IO signals to ECU control                    \n
    \param[in]    u16DidIndexStart Start index of the Did inside the array    \n
    \Range        0..DCM_u16NUM_OF_DIDS                                       \n
    \param[in]    u8SignalIndexStart Start index of the signal inside the Did \n
    \Range        0..255                                                      \n
    \param[in]    u8NumOfSigToCtrl Max number of signals to control per
                                          function call                       \n
    \Range        0..255                                                      \n
    \param[in]    u8IOCTRLOpStatus OpStatus to give in the first call to
                                   application interface                      \n
    \Range        DCM_INITIAL, DCM_PENDING                                    \n
    \param[out]   pu8NegResCode The NRC to be reported                        \n
    \Range        0..255                                                      \n
    \return       void                                                        \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_vidIoCtrlReturnAllDidCtrlToEcu (
  uint16 u16DidIndexStart,
  uint8 u8SignalIndexStart,
  uint8 u8NumOfSigToCtrl,
  Dcm_OpStatusType u8IOCTRLOpStatus,
  Dcm_NegativeResponseCodeType * pu8NegResCode)
{
  /*! Define local variables: */

  /*! - Index of Did inside Dids array */
  uint16                  u16DidIndex;

  /*! - Signal index inside the Did configuration */
  uint8                   u8SignalIndex;

  /*! - Return value from IO control functions */
  Std_ReturnType          u8ControlReturn;

  /*! - Reference to Data inside the Did configuration */
  uint32                  u32DataRef;

  /*! - Flag to stop the loop of signals */
  boolean                 bLoopEnd = FALSE;

  /*! - To count number of signals that have been controlled */
  uint8                   u8NumOfCtrlSignals = 0;

  /*! - A pointer to the DidAccess configuration structure */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                          pkstrDidAccess;

  DspInternal_beRetCtrlPending = FALSE;
  DspInternal_beRetCtrl = FALSE;

  /*! Loop in DcmDspDid array */
  for (u16DidIndex = u16DidIndexStart;
       (u16DidIndex < DCM_u16NUM_OF_DIDS) && (bLoopEnd == FALSE);
       u16DidIndex++)
  {
    pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex]
                      .pkstrDspDidInfoRef->strDcmDspDidAccess;
    
    if ((pkstrDidAccess->pkstrDcmDspDidControl) != 
        (P2CONST(void,AUTOMATIC,AUTOMATIC))0)
    {
      /*! If any of the IOControl flags is set */
      if ((pkstrDidAccess->pkstrDcmDspDidControl->bDcmDspDidReturnControlToEcu
                                                                       == TRUE) &&
            ((pkstrDidAccess->pkstrDcmDspDidControl->bDcmDspDidFreezeCurrentState
                                                                       == TRUE)
            || (pkstrDidAccess->pkstrDcmDspDidControl->bDcmDspDidResetToDefault
                                                                       == TRUE)
            || (pkstrDidAccess->pkstrDcmDspDidControl->
                                         bDcmDspDidShortTermAdjustment == TRUE)))
      {
        /*! Loop on all signals inside the Did */
        for (u8SignalIndex = u8SignalIndexStart;
             (u8SignalIndex < Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
             u8NumOfDidSignal)
             && (bLoopEnd == FALSE);
             u8SignalIndex++)
        {
          u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
            pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;
        
          /*! Based on UsePort, call the RetCtrlToEcu function of the signal */
          switch (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                  u8DcmDspDataUsePort)
          {
            case USE_ECU_SIGNAL:
            u8ControlReturn = E_OK;
            (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              pfDcmDspDataEcuSignal)(u8IOCTRL_RET_CTRL_ECU, NULL_PTR);
            break;

            case USE_DATA_SYNCH_CLIENT_SERVER:
            u8ControlReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              pfDcmDspDataReturnControlToEcuSync)(pu8NegResCode);
            break;

            case USE_DATA_ASYNCH_CLIENT_SERVER:
            u8ControlReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
             pfDcmDspDataReturnControlToEcuAsync)(u8IOCTRLOpStatus,pu8NegResCode);
            break;

            case USE_FNC:
            u8ControlReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              pfDcmDspDataReturnControlToEcuFnc)(u8IOCTRLOpStatus,pu8NegResCode);
            break;

            default:
            u8ControlReturn = E_NOT_OK;
            break;
          }

          /*! If Pending, halt and continue next function call */
          if (u8ControlReturn == E_PENDING)
          {
            bLoopEnd = TRUE;
            DspInternal_u16eRetCtrlDidIndex = u16DidIndex;
            DspInternal_u8eRetCtrlSignalIndex = u8SignalIndex;
            DspInternal_beRetCtrlPending = TRUE;
            DspInternal_beRetCtrl = TRUE;
          }
          else
          {
            u8NumOfCtrlSignals++;

            /*! Check if it exceeded number of signals to control per func call */
            if ((u8NumOfSigToCtrl != 0) &&
                (u8NumOfCtrlSignals == u8NumOfSigToCtrl))
            {
              /*! Stop if limit is exceeded */
              bLoopEnd = TRUE;

              if ((Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                   u8NumOfDidSignal - 1) > u8SignalIndex)
              {
                DspInternal_u16eRetCtrlDidIndex = u16DidIndex;
                DspInternal_u8eRetCtrlSignalIndex = u8SignalIndex + 1;
                DspInternal_beRetCtrlPending = FALSE;
                DspInternal_beRetCtrl = TRUE;
              }
              else if (u16DidIndex < (uint16)(DCM_u16NUM_OF_DIDS - 1))
              {
                DspInternal_u16eRetCtrlDidIndex = u16DidIndex + 1;
                DspInternal_u8eRetCtrlSignalIndex = 0;
                DspInternal_beRetCtrlPending = FALSE;
                DspInternal_beRetCtrl = TRUE;
              }
              else
              {
                /* Last signal in last Did, nothing to be done */
              }
            }
          }
          u8IOCTRLOpStatus = DCM_INITIAL;
        }
      }
    }
    u8SignalIndexStart = 0;
  }
}
/* PRQA S 4700 --                                                             */
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON ||         \
       DCM_bWDBI_EN == STD_ON)           \

/******************************************************************************/
/*! \Trace_To    CDD-1014(0)                                                \n\n
    \Description Checks if the specified Did is supported or not.
                 And if supported, it indicates its index inside the config
                 array.                                                       \n
    \param[in]   u16Did       Data Identifier to be checked.                  \n
    \Range       0..65535                                                     \n
    \param[out]  u16DidIndex  Index of the Did inside the DspDid config array.\n
    \Range       0..(DCM_u16NUM_OF_DIDS-1)                                    \n
    \return      Did is supported or not.                                     \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckDidSupported(
    uint16 u16Did,
    P2VAR(uint16,AUTOMATIC,DCM_VAR) pu16DidIndex)
{
  /*! Define local variables: */

  /*! - The function return value */
  boolean bReturn = FALSE;
  
  /*! - A loop end flag */
  boolean bLoopEnd = FALSE;
  
  /*! - A loop index */
  uint16  u16LoopIndex;

  /*! Loop in DcmDspDid array searching for the required Did. */
  /* !Deviation : Inhibit MISRA rule [2465]: For Loop Only executed once 
                  because it is dependent on the configuration                */
  /* PRQA S 2465 ++                                                           */
  for (u16LoopIndex=0;
      (u16LoopIndex < DCM_u16NUM_OF_DIDS) && (bLoopEnd == FALSE);
      u16LoopIndex++)
  {
    /* PRQA S 2465 --                                                         */
    if (Dcm_kstreDspConfig.astrDcmDspDid[u16LoopIndex].u16DcmDspDidIdentifier
         == u16Did)
    {
      bLoopEnd = TRUE;

      /*! If found, check if this Did is marked as "used" or not. */
      if (Dcm_pkstrePbConfig->strPbDcmDspConfig.pkstrDcmDspDid[u16LoopIndex]
           .bDcmDspDidUsed == TRUE)
      {
        /*! If marked as "used", then the function returns TRUE and the index
        of Did inside the array is assigned to the output parameter
        DidIndex. */
        bReturn = TRUE;
        *pu16DidIndex = u16LoopIndex;
      }
      /*! Else, the function returns FALSE. */
    }
  }

  return bReturn;
}

#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1017(0)                                                \n\n
    \Description Checks if the Did can be read inside the current session     \n
    \param[in]   u16DidIndex  Index of the Did inside the DspDid config array.\n
    \Range       0..(DCM_u16NUM_OF_DIDS-1)                                    \n
    \return      Did can be read inside current session or not.               \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckDidReadSession (uint16 u16DidIndex)
{
  /*! Define local variables: */

  /*! - Current active session */
  Dcm_SesCtrlType u8CurrentSesCtrl;
  Dcm_SesCtrlType u8ConfigSesCtrl;
  
  /*! - The function return value */
  boolean         bReturn = FALSE;
  
  /*! - A loop index */
  uint8           u8LoopIndex;
  
  /*! - A pointer to the DidAccess configuration structure */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                  pkstrDidAccess;

  /*! Get the current session. */
  (void)Dcm_GetSesCtrlType(&u8CurrentSesCtrl);
  
  /*! If the ReadSessionRef of the Did is pointing to NULL. */
  pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex]
                    .pkstrDspDidInfoRef->strDcmDspDidAccess;
  if (pkstrDidAccess->pkstrDcmDspDidRead->ppkstrDcmDspDidReadSessionRef
                               == (Dcm_tpkstrDspSessionRowType*)NULL_PTR)
  {
    /*! Then, the function returns TRUE. */
    bReturn = TRUE;
  }
  else
  {
    /*! Else, loop on all the sessions levels configured for this Did. */
    for (u8LoopIndex = 0;
         (bReturn != TRUE) &&
         (u8LoopIndex < pkstrDidAccess->pkstrDcmDspDidRead->u8NumofSessRef);
         u8LoopIndex++)
    {
      u8ConfigSesCtrl = pkstrDidAccess->pkstrDcmDspDidRead->
          ppkstrDcmDspDidReadSessionRef[u8LoopIndex]->u8DcmDspSessionLevel;
      /*! If any of the configured sessions levels equals to the current level,
          then the function returns TRUE. */
      if ((u8CurrentSesCtrl == u8ConfigSesCtrl) ||
          (u8ConfigSesCtrl == DCM_ALL_SESSION_LEVEL))
      {
        bReturn = TRUE;
      }
      /*! Else, it returns FALSE. */
    }
  }

  return bReturn;
}

#endif

#if (DCM_bWDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1038(0)                                                \n\n
    \Description Checks if the Did can be written inside the current session  \n
    \param[in]   u16DidIndex  Index of the Did inside the DspDid config array.\n
    \Range       0..(DCM_u16NUM_OF_DIDS-1)                                    \n
    \return      Did can be written inside current session or not.            \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckDidWriteSession (uint16 u16DidIndex)
{
  /*! Define local variables: */

  /*! - Current active session */
  Dcm_SesCtrlType u8CurrentSesCtrl;
  Dcm_SesCtrlType u8ConfigSesCtrl;

  /*! - The function return value */
  boolean         bReturn = FALSE;
  
  /*! - A loop index */
  uint8           u8LoopIndex;
  
  /*! - A pointer to the DidAccess configuration structure */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                  pkstrDidAccess;

  /*! Get the current session. */
  (void)Dcm_GetSesCtrlType(&u8CurrentSesCtrl);

  /*! If the WriteSessionRef of the Did is pointing to NULL. */
  pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex]
                    .pkstrDspDidInfoRef->strDcmDspDidAccess;
  if (pkstrDidAccess->pkstrDcmDspDidWrite->ppkstrDcmDspDidWriteSessionRef
        == (Dcm_tpkstrDspSessionRowType*)NULL_PTR)
  {
    /*! Then, the function returns TRUE. */
    bReturn = TRUE;
  }
  else
  {
    /*! Else, loop on all the sessions levels configured for this Did. */
    for (u8LoopIndex = 0;
         (bReturn != TRUE) &&
         (u8LoopIndex < pkstrDidAccess->pkstrDcmDspDidWrite->u8NumofSessRef);
         u8LoopIndex++)
    {
      u8ConfigSesCtrl = pkstrDidAccess->pkstrDcmDspDidWrite->
            ppkstrDcmDspDidWriteSessionRef[u8LoopIndex]->u8DcmDspSessionLevel;
      /*! If any of the configured sessions levels equals to the current level,
          then the function returns TRUE. */
      if ((u8CurrentSesCtrl == u8ConfigSesCtrl) ||
          (u8ConfigSesCtrl == DCM_ALL_SESSION_LEVEL))
      {
        bReturn = TRUE;
      }
      /*! Else, it returns FALSE. */
    }
  }

  return bReturn;
}

#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1053(0)                                                \n\n
    \Description Checks if the Did can be controlled inside current session   \n
    \param[in]   u16DidIndex  Index of the Did inside the DspDid config array.\n
    \Range       0..(DCM_u16NUM_OF_DIDS-1)                                    \n
    \return      Did can be controlled inside current session or not.         \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckDidCtrlSess (uint16 u16DidIndex)
{
  /*! Define local variables: */

  /*! - Current active session */
  Dcm_SesCtrlType u8CurrentSesCtrl;
  Dcm_SesCtrlType u8ConfigSesCtrl;

  /*! - The function return value */
  boolean         bReturn = FALSE;
  
  /*! - A loop index */
  uint8           u8LoopIndex;
  
  /*! - A pointer to the DidAccess configuration structure */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                  pkstrDidAccess;

  /*! Get the current session. */
  (void)Dcm_GetSesCtrlType(&u8CurrentSesCtrl);

  /*! If the ControlSessionRef of the Did is pointing to NULL. */
  pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex]
                    .pkstrDspDidInfoRef->strDcmDspDidAccess;
  if (pkstrDidAccess->pkstrDcmDspDidControl->ppkstrDcmDspDidControlSessionRef
        == (Dcm_tpkstrDspSessionRowType*)NULL_PTR)
  {
    /*! Then, the function returns TRUE. */
    bReturn = TRUE;
  }
  else
  {
    /*! Else, loop on all the sessions levels configured for this Did. */
    for (u8LoopIndex = 0;
        (bReturn != TRUE) &&
        (u8LoopIndex < pkstrDidAccess->pkstrDcmDspDidControl->u8NumofSessRef);
        u8LoopIndex++)
    {
      u8ConfigSesCtrl = pkstrDidAccess->pkstrDcmDspDidControl->
            ppkstrDcmDspDidControlSessionRef[u8LoopIndex]->u8DcmDspSessionLevel;
      /*! If any of the configured sessions levels equals to the current level,
          then the function returns TRUE. */
      if ((u8CurrentSesCtrl == u8ConfigSesCtrl) ||
          (u8ConfigSesCtrl == DCM_ALL_SESSION_LEVEL))
      {
        bReturn = TRUE;
      }
      /*! Else, it returns FALSE. */
    }
  }

  return bReturn;
}

#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1018(0)                                                \n\n
    \Description Checks if the Did can be read inside the current security
                 level.                                                       \n
    \param[in]   u16DidIndex  Index of the Did inside the DspDid config array.\n
    \Range       0..(DCM_u16NUM_OF_DIDS-1)                                    \n
    \return      Did can be read inside current security level or not.        \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckDidReadSecurity(uint16 u16DidIndex)
{
  /*! Define local variables: */

  /*! - Current security level */
  Dcm_SecLevelType u8CurrentSecLevel;
  Dcm_SecLevelType u8ConfigSecLevel;
  
  /*! - The function return value */
  boolean          bReturn = FALSE;
  
  /*! - A loop index */
  uint8            u8LoopIndex;
  
  /*! - A pointer to the DidAccess configuration structure */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                   pkstrDidAccess;

  /*! Get the current security level */
  (void)Dcm_GetSecurityLevel(&u8CurrentSecLevel);

  /*! If the ReadSecurityLevelRef of the Did is pointing to NULL. */
  pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex]
                    .pkstrDspDidInfoRef->strDcmDspDidAccess;
  if (pkstrDidAccess->pkstrDcmDspDidRead->ppkstrDcmDspDidReadSecurityLevelRef
        == (Dcm_tpkstrDspSecurityRowType*)NULL_PTR)
  {
    /*! Then, the function returns TRUE. */
    bReturn = TRUE;
  }
  else
  {
    /*! Else, loop on all the security levels configured for this Did. */
    for (u8LoopIndex = 0;
        (bReturn != TRUE) &&
        (u8LoopIndex < pkstrDidAccess->pkstrDcmDspDidRead->u8NumofSecRef);
        u8LoopIndex++)
    {
      u8ConfigSecLevel = pkstrDidAccess->pkstrDcmDspDidRead->
            ppkstrDcmDspDidReadSecurityLevelRef[u8LoopIndex]->
            u8DcmDspSecurityLevel;
      /*! If any of the configured security levels equals to the current level,
          then the function returns TRUE. */
      if ((u8CurrentSecLevel == u8ConfigSecLevel) ||
          (u8ConfigSecLevel == DCM_SEC_LEV_ALL))
      {
        bReturn = TRUE;
      }
      /*! Else, it returns FALSE. */
    }
  }

  return bReturn;
}

#endif

#if (DCM_bWDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1042(0)                                                \n\n
    \Description Checks if the Did can be written inside the current security
                 level.                                                       \n
    \param[in]   u16DidIndex  Index of the Did inside the DspDid config array.\n
    \Range       0..(DCM_u16NUM_OF_DIDS-1)                                    \n
    \return      Did can be written inside current security level or not.     \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckDidWriteSec (uint16 u16DidIndex)
{
  /*! Define local variables: */

  /*! - Current security level */
  Dcm_SecLevelType u8CurrentSecLevel;
  Dcm_SecLevelType u8ConfigSecLevel;

  /*! - The function return value */
  boolean          bReturn = FALSE;
  
  /*! - A loop index */
  uint8            u8LoopIndex;
  
  /*! - A pointer to the DidAccess configuration structure */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                   pkstrDidAccess;

  /*! Get the current security level */
  (void)Dcm_GetSecurityLevel(&u8CurrentSecLevel);

  /*! If the WriteSecurityLevelRef of the Did is pointing to NULL. */
  pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex]
                    .pkstrDspDidInfoRef->strDcmDspDidAccess;
  if (pkstrDidAccess->pkstrDcmDspDidWrite->ppkstrDcmDspDidWriteSecurityLevelRef
        == (Dcm_tpkstrDspSecurityRowType*)NULL_PTR)
  {
    /*! Then, the function returns TRUE. */
    bReturn = TRUE;
  }
  else
  {
    /*! Else, loop on all the security levels configured for this Did. */
    for (u8LoopIndex = 0;
        (bReturn != TRUE) &&
        (u8LoopIndex < pkstrDidAccess->pkstrDcmDspDidWrite->u8NumofSecRef);
        u8LoopIndex++)
    {
      u8ConfigSecLevel = pkstrDidAccess->pkstrDcmDspDidWrite->
            ppkstrDcmDspDidWriteSecurityLevelRef[u8LoopIndex]->
            u8DcmDspSecurityLevel;
      /*! If any of the configured security levels equals to the current level,
          then the function returns TRUE. */
      if ((u8CurrentSecLevel == u8ConfigSecLevel) ||
          (u8ConfigSecLevel == DCM_SEC_LEV_ALL))
      {
        bReturn = TRUE;
      }
      /*! Else, it returns FALSE. */
    }
  }

  return bReturn;
}

#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1054(0)                                                \n\n
    \Description Checks if the Did can be controlled inside the current security
                 level.                                                       \n
    \param[in]   u16DidIndex  Index of the Did inside the DspDid config array.\n
    \Range       0..(DCM_u16NUM_OF_DIDS-1)                                    \n
    \return      Did can be controlled inside current security level or not.  \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bCheckDidCtrlSec (uint16 u16DidIndex)
{
  /*! Define local variables: */

  /*! - Current security level */
  Dcm_SecLevelType u8CurrentSecLevel;
  Dcm_SecLevelType u8ConfigSecLevel;

  /*! - The function return value */
  boolean          bReturn = FALSE;
  
  /*! - A loop index */
  uint8            u8LoopIndex;
  
  /*! - A pointer to the DidAccess configuration structure */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                   pkstrDidAccess;

  /*! Get the current security level */
  (void)Dcm_GetSecurityLevel(&u8CurrentSecLevel);

  /*! If the ControlSecurityLevelRef of the Did is pointing to NULL. */
  pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex]
                    .pkstrDspDidInfoRef->strDcmDspDidAccess;
  if (pkstrDidAccess->pkstrDcmDspDidControl->
      ppkstrDcmDspDidControlSecurityLevelRef ==
            (Dcm_tpkstrDspSecurityRowType*)NULL_PTR)
  {
    /*! Then, the function returns TRUE. */
    bReturn = TRUE;
  }
  else
  {
    /*! Else, loop on all the security levels configured for this Did. */
    for (u8LoopIndex = 0;
        (bReturn != TRUE) &&
        (u8LoopIndex < pkstrDidAccess->pkstrDcmDspDidControl->u8NumofSecRef);
        u8LoopIndex++)
    {
      u8ConfigSecLevel = pkstrDidAccess->pkstrDcmDspDidControl->
            ppkstrDcmDspDidControlSecurityLevelRef[u8LoopIndex]->
            u8DcmDspSecurityLevel;
      /*! If any of the configured security levels equals to the current level,
          then the function returns TRUE. */
      if ((u8CurrentSecLevel == u8ConfigSecLevel) ||
          (u8ConfigSecLevel == DCM_SEC_LEV_ALL))
      {
        bReturn = TRUE;
      }
      /*! Else, it returns FALSE. */
    }
  }

  return bReturn;
}

#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-0022(0), CDD-1020(0), CDD-1022(0), CDD-1023(0), CDD-1024(0)
                 CDD-1547(0), CDD-DSP-0007(0), CDD-DSP-0009(0)              \n\n
    \Description Read a signal whose index = u8DSP_SIGNAL_INDEX in Did
                 whose index = u16DSP_DID_ARR_INDEX.                          \n
    \param[in]   u16DidArrayIndex  The index of DID inside the supported DID
                                   array.                                     \n
    \Range       0..u16DSP_NUM_DID-1                                         \n
    \param[in]   u8SignalIndex  The signal index inside the DID configuration.\n
    \Range       0..Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                 u8NumOfDidSignal-1                                           \n
    \param[out]  u8NegResCode  The NRC that occured while reading the signal. \n
    \Range       0x14, DCM_E_CONDITIONSNOTCORRECT                             \n
    \param[in]   u8ReadOpStatus   OpStatus to use in the first call to
                                  application interface                       \n
    \Range       DCM_INITIAL, DCM_PENDING                                     \n
    \param[in]   u8ServiceStatus  The diagnostic service that requests the
                                  read                                        \n
    \Range       DspInternal_u8RDBI, DspInternal_u8IOCTRL                                             \n
    \param[in]   u8IdContext      The message context ID                      \n
    \Range       0..DspInternal_u8MAX_NUM_INTERNAL_REQ                                \n
    \return      An NRC occured while reading or not.                         \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static FUNC(boolean,DCM_CODE) bReadDidSignal (
    uint16                           u16DidArrayIndex,
    uint8                            u8SignalIndex,
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8NegResCode,
    Dcm_OpStatusType                 u8ReadOpStatus,
    uint8                            u8ServiceStatus,
    Dcm_IdContextType                u8IdContext)
{
  /*! Define local variables: */

  /*! - Flag indicating NRC is to be sent or not - The function return value */
  boolean               bSendNegResp = FALSE;

  /*! - Reference to the Data configuration linked to the Did signal */
  uint32                u32DataRef;

  /*! - Value returned from functions configured for the Did */
  Std_ReturnType        u8DidFuncReturn = E_NOT_OK;

  /*! - Index of Did inside the array */
  uint16                u16DidIndex;

#if (DCM_bNVM_USED == STD_ON)
    /*! - Request result of NVM service */
  NvM_RequestResultType NvMReqResult;
#endif

  /*! - A data UsePort configuration value */
  Dcm_PortUsedType      u8PortUsed;

  /*! - A data position inside the Did in bits */
  uint16                u16DataPos;

  /*! - Protocol index */
  uint8                 u8ProtocolIndex;

  /*! - Endianness conversion is needed or not */
  boolean               bEndianConv;

  /*! - Total length of a data */
  uint16                u16TotalLength;

  /*! - A data type */
  Dcm_DspDataTypeType   u8DataType;

  u16DidIndex = u16DSP_DID_IDX[u16DidArrayIndex];

  u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
      pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;

  u8PortUsed =Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].u8DcmDspDataUsePort;

  u16DataPos = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
    pkstrDcmDspDidSignal[u8SignalIndex].u16DcmDspDidDataPos;

  /*! If this is the first call to this function for this DidSignal */
  if (u8ReadOpStatus == DCM_INITIAL)
  {
    /*! If the signal is of fixed length, */
    if(Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
         pkstrDcmDspDataInfoRef->bDcmDspDataFixedLength == TRUE)
    {
      /*! Get the signal length from configuration. */
      u16DSP_DATA_LEN  = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        u16DcmDspDataSize;
    }
    else
    {
      /*! Else, use the configured function to get the signal length. */
      switch (u8PortUsed)
      {
        case USE_DATA_SYNCH_CLIENT_SERVER:
        u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
           pfDcmDspDataReadDataLengthSync)(&u16DSP_DATA_LEN);
        break;

        case USE_DATA_ASYNCH_CLIENT_SERVER:
        u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          pfDcmDspDataReadDataLengthAsync)(&u16DSP_DATA_LEN);
        break;

        default: /* Fnc or others */
        u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          pfDcmDspDataReadDataLengthFnc)(&u16DSP_DATA_LEN);
        break;
      }

      if (u8DidFuncReturn == E_NOT_OK)
      {
        bSendNegResp = TRUE;
        *pu8NegResCode = DCM_E_CONDITIONSNOTCORRECT;
      }
    }

    /*! If OK */
    if (bSendNegResp == FALSE)
    {
      /*! Check if the Tx buffer remaining capacity is sufficient compared to
          the signal size, */
      if (((uint32)(u16DSP_TX_BUFF_INDEX +
           ((u16DataPos + u16DSP_DATA_LEN + 7)/8))) >
           DspInternal_pu8DSP_MSGCONTEXT->resMaxDataLen)
      {
        /*! If insufficient, then the function returns TRUE and set NRC by
            RESPONSETOOLONG. */
        bSendNegResp = TRUE;
        *pu8NegResCode = DCM_E_RESPONSETOOLONG;

        /*! And report Buffer Overflow to DET */
        #if (DCM_DEV_ERROR_DETECT == STD_ON)
        if (u8ServiceStatus == DspInternal_u8RDBI)
        {
          Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
              Dcm_u8UDS_RDBI_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
        }
        else
        {
          Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
              Dcm_u8IO_CTRL_BY_IDENT_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
        }
        #endif
      }
    }
  }

  /*! If OK */
  if (bSendNegResp == FALSE)
  {
    u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                      pkstrDcmDslProtocolRx[DspInternal_pu8DSP_MSGCONTEXT->dcmRxPduId].
                      u8DcmDslProtocolIndex;
    
    /*! Conversion only in case of sender/receiver interface used and 
        reading from IoHwAb */
    if ((u8PortUsed == USE_ECU_SIGNAL) 
         || (u8PortUsed == USE_DATA_SENDER_RECEIVER))
    {
      bEndianConv = Dcm_kstreDslConfig.astrDcmDslProtocolRow[u8ProtocolIndex].
        bDcmDslProtocolEndiannessConvEnabled;
    }
    else
    {
      bEndianConv = FALSE;
    }

    u8DataType = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
      u8DcmDspDataType;

    /*! Based on the configured data type, set the TotalLength */
    if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
         pkstrDcmDspDataInfoRef->bDcmDspDataFixedLength == TRUE)
    {
      if ((u8DataType == BOOLEAN) || (u8DataType == UINT8) ||
           (u8DataType == SINT8))
      {
        u16TotalLength = 8;
      }
      else if ((u8DataType == UINT16) || (u8DataType == SINT16))
      {
        u16TotalLength = 16;
      }
      else /* UINT32 or SINT32 */
      {
        u16TotalLength = 32;
      }
    }
    else
    {
      u16TotalLength = 0;
    }

    /*! If some app interface is pending and the cancel flag is raised */
    if ((u8ReadOpStatus == DCM_PENDING)
          && (DspInternal_pu8DSP_MSGCONTEXT->msgAddInfo.cancelOperation == 1))
    {
      /*! To cancel the app interface */
      u8ReadOpStatus = DCM_CANCEL;
    }
    
    /*! Based on the configuration parameter DataUsePort, read the signal. */
    switch (u8PortUsed)
    {
    #if (DCM_bNVM_USED == STD_ON)
    case USE_BLOCK_ID:
      if (u8ReadOpStatus == DCM_INITIAL)
      {
        /*! If first call for this signal, then call NvM_ReadBlock */
        u8DidFuncReturn = NvM_ReadBlock(
          Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          udtDcmDspDataBlockIdRef, au8DSP_SIGNAL_BUFF);

        if (u8DidFuncReturn == E_NOT_OK)
        {
          bSendNegResp = TRUE;
          *pu8NegResCode =DCM_E_CONDITIONSNOTCORRECT;
        }
        else
        {
          DspInternal_u8DSP_SUBSTATUS = u8RDBI_READ_PENDING;
        }
      }
      else if (u8ReadOpStatus == DCM_PENDING)
      {
        /* Else, then should poll on the status from NvM */
        u8DidFuncReturn = NvM_GetErrorStatus(
          Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          udtDcmDspDataBlockIdRef, &NvMReqResult);

        if (u8DidFuncReturn == E_NOT_OK)
        {
          bSendNegResp = TRUE;
          *pu8NegResCode =DCM_E_CONDITIONSNOTCORRECT;
        }
        else if (NvMReqResult == NVM_REQ_PENDING)
        {
          DspInternal_u8DSP_SUBSTATUS = u8RDBI_READ_PENDING;
        }
        /*! If status is ok, then inject the signal into response message */
        else if (NvMReqResult == NVM_REQ_OK)
        {
          DspInternal_vidInjectSignalIntoBuff (
            au8DSP_SIGNAL_BUFF,
            &DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX],
            (uint16)(u16DataPos/8),
            (uint8)(u16DataPos%8),
            u16DSP_DATA_LEN, u16TotalLength, bEndianConv);
        }
        else
        {
          bSendNegResp = TRUE;
          *pu8NegResCode =DCM_E_CONDITIONSNOTCORRECT;
        }
      }
      else
      {
        /*! Do nothing at cancellation as current processed block can't
            be interrupted [NVM537] */
      }
      break;
    #endif

    case USE_DATA_SENDER_RECEIVER:
      u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataReadSr)(au8DSP_SIGNAL_BUFF);
      break;

    case USE_DATA_SYNCH_CLIENT_SERVER:
      u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          pfDcmDspDataReadSync)(au8DSP_SIGNAL_BUFF);
      break;

    case USE_ECU_SIGNAL:
      u8DidFuncReturn = E_OK;
      (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          pfDcmDspDataReadEcuSignal)(au8DSP_SIGNAL_BUFF);
      break;

    case USE_FNC:
      u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          pfDcmDspDataReadFnc)(
            u8ReadOpStatus, au8DSP_SIGNAL_BUFF);
      break;

    case USE_DATA_ASYNCH_CLIENT_SERVER:
      u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
           pfDcmDspDataReadAsync)(
             u8ReadOpStatus,au8DSP_SIGNAL_BUFF);
      break;

    default:
      break;
    }

    /*! To complete cancelling the service, call ProcessingDone
    and set status to idle & cancel */
    if (u8ReadOpStatus == DCM_CANCEL)
    {
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      DspInternal_u8DSP_STATUS = u8CANCEL;
    }
    /*! For all DataUsePort except the NVM_BLOCK_ID */
    else if (u8PortUsed != USE_BLOCK_ID)
    {
      /*! If OK, then inject the signal into the response message buffer */
      if (u8DidFuncReturn == E_OK)
      {
        DspInternal_vidInjectSignalIntoBuff (
          au8DSP_SIGNAL_BUFF,
          &DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX],
          (uint16)(u16DataPos/8),
          (uint8)(u16DataPos%8),
          u16DSP_DATA_LEN, u16TotalLength, bEndianConv);
      }
      else if(u8DidFuncReturn == E_PENDING)
      {
        DspInternal_u8DSP_SUBSTATUS = u8RDBI_READ_PENDING;
      }
      else
      {
        bSendNegResp = TRUE;
        *pu8NegResCode =DCM_E_CONDITIONSNOTCORRECT;
      }
    }
    else
    {
      /*! Do Nothing */
    }
  }

  return bSendNegResp;
}
/* PRQA S 4700 --                                                             */
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To    CDD-0945(0)                                                \n\n
    \Description Calculates the whole response message size and gets the max
                 size of any DID inside the message.                          \n
    \param[out]  pu32MaximumData   Max size of DID data value                 \n
    \Range       2..max                                                       \n
    \return      Total size of the response message (DID & values excluding
                 anything else in the message)                                \n
    \Range       1..max                                                       \n
*******************************************************************************/
static FUNC(uint32,DCM_CODE) u32ReadingGetFullLength (
        P2VAR(uint32,AUTOMATIC,AUTOMATIC) pu32MaximumData,
        uint8 u8IdContext)
{
  uint16         u16DidIndex;
  /*! If zero is returned, this indicates an error */
  uint32         u32ResLength = 0;
  uint32         u32DidSize;
  uint32         u32DataRef;
  uint8          u8DidSignal;
  Std_ReturnType u8DidFuncReturn;
  uint16         u16DataSize;
  boolean        bLoopEnd = FALSE;
  uint8          u8ObdDid;

  *pu32MaximumData = 0;
  
  /*! If there are DIDs in the array to measure their length, */
  if (u16DSP_NUM_DID > 0)
  {
    /*! Loop on all DIDs in the array */
    for (u16DidIndex = 0;
         (u16DidIndex < u16DSP_NUM_DID)
         && (bLoopEnd == FALSE);
         u16DidIndex++)
    {
      /*! The DID size starts from the 2 bytes of the DID identifier */
      u32DidSize = 2;

      /*! Based on the type of the DID */
      switch (au8DSP_DID_TYPES[u16DidIndex])
      {
        /*! For availabilty DIDs: */
        case u8DID_OBD1_AVAIL:
        case u8DID_OBD2_AVAIL:
        case u8DID_OBD3_AVAIL:
        /*! Get the DID size */
        u16DataSize = 0;
        u8ObdDid = (uint8)(u16DSP_DID_IDX[u16DidIndex] & 0x00FF);
        DspInternal_vidSetAvailablRes(
          &u8ObdDid,
          1,
          au8DSP_SIGNAL_BUFF,
          &u16DataSize,
          au8DSP_DID_TYPES[u16DidIndex]);
        
        /*! Compare the DID size to the current max */
        u32DidSize += u16DataSize - 1;
        if (u32DidSize > *pu32MaximumData)
        {
          *pu32MaximumData = u32DidSize;
        }
        break;
      
        /*! For DIDs of UDS type: */
        case u8DID_UDS:
        /*! Loop on all the signals inside this DID */
        for (u8DidSignal = 0;
             (u8DidSignal < Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                             u8NumOfDidSignal)
             && (bLoopEnd == FALSE);
             u8DidSignal++)
        {
          u32DataRef = Dcm_kstreDspConfig.
            astrDcmDspDid[u16DSP_DID_IDX[u16DidIndex]].
            pkstrDcmDspDidSignal[u8DidSignal].u32DcmDspDidDataRef;

          /*! If the signal is of fixed length, */
          if(Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
               pkstrDcmDspDataInfoRef->bDcmDspDataFixedLength == TRUE)
          {
            /*! Get the signal length from configuration. */
            u16DataSize  = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              u16DcmDspDataSize;
          }
          else
          {
            /*! Get the signal length based on the UsePort */
            switch (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                      u8DcmDspDataUsePort)
            {
              case USE_DATA_SYNCH_CLIENT_SERVER:
              u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                pfDcmDspDataReadDataLengthSync)(&u16DataSize);
              break;

              case USE_DATA_ASYNCH_CLIENT_SERVER:
              u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                pfDcmDspDataReadDataLengthAsync)(&u16DataSize);
              break;

              default: /* Fnc or others */
              u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                pfDcmDspDataReadDataLengthFnc)(&u16DataSize);
              break;
            }
          }
          
          if (u8DidFuncReturn == E_OK)
          {
            u32DidSize += u16DataSize;
            /*! If first signal in the DID */
            if (u8DidSignal == 0)
            {
              /*! Compare current max with data size + 2 */
              if ((uint32)(u16DataSize + 2) > *pu32MaximumData)
              {
                *pu32MaximumData = u16DataSize + 2;
              }
            }
            else
            {
              /*! Else, compare current max with data size */
              if (u16DataSize > *pu32MaximumData)
              {
                *pu32MaximumData = u16DataSize;
              }
            }
          }
          else
          {
            /*! Error returned, exit from loop */
            bLoopEnd = TRUE;
            u32DidSize = 0;
            u32ResLength = 0;
          }
        }
        break;

        /*! For OBD 1st range (PID) */
        case u8DID_OBD1:
        #if(DCM_u8NUM_OF_PIDS > 0U)
          /*! Get the DID size */
          u32DidSize += Dcm_kstreDspConfig.
            astrDcmDspPid[u16DSP_DID_IDX[u16DidIndex]].u8DcmDspPidSize;
          /*! The PID value can't be splitted, so compare current max with the
              whole DID size */
          if (u32DidSize > *pu32MaximumData)
          {
            *pu32MaximumData = u32DidSize;
          }
        #else
          /*! OBD type not configured, Error */
          bLoopEnd = TRUE;
          u32DidSize = 0;
          u32ResLength = 0;
        #endif
        break;

        /*! For OBD 2nd range (OBD MID) */
        case u8DID_OBD2:
        #if (DCM_u8NUM_OBDMID > 0U)
          /*! Get the DID size */
          u32DidSize += Dcm_kstreDspConfig.astrDcmDspTestResultObdmidTid
            [u16DSP_DID_IDX[u16DidIndex]].u8NumOfTids * 9;
          /*! Compare current max with minimum non-splittable size (11 bytes) */
          if (11 > *pu32MaximumData)
          {
            *pu32MaximumData = 11;
          }
        #else
          /*! OBD type not configured, Error */
          bLoopEnd = TRUE;
          u32DidSize = 0;
          u32ResLength = 0;
        #endif
        break;

        /*! For OBD 3rd range (Veh Info) */
        case u8DID_OBD3:
        #if (DCM_u8NUM_OF_VEHICLE_INFO > 0U)
          /*! Loop on all the signals inside the DID to calc the size */
          for (u8DidSignal = 0; u8DidSignal < Dcm_kstreDspConfig.
            astrDcmDspVehInfo[u16DSP_DID_IDX[u16DidIndex]].u8NumVehInfoData;
            u8DidSignal++)
          {
            u16DataSize = Dcm_kstreDspConfig.astrDcmDspVehInfo
              [u16DSP_DID_IDX[u16DidIndex]].
              pkstrDcmDspVehInfoData[u8DidSignal].u8DcmDspVehInfoDataSize;
            u32DidSize += u16DataSize;

            /*! For 1st signal in the DID */
            if (u8DidSignal == 0)
            {
              /*! Compare current max with data size + 3 (DID + no. of data) */
              if ((uint32)(3 + u16DataSize) > *pu32MaximumData)
              {
                *pu32MaximumData = 3 + u16DataSize;
              }
            }
            else
            {
              /*! Else, compare current max with data size */
              if (u16DataSize > *pu32MaximumData)
              {
                *pu32MaximumData = u16DataSize;
              }
            }
          }
          /*! Increment the size by 1 as the DID is 2 bytes and OBD api
              returns it 1 byte */
          u32DidSize++;
        #else
          /*! OBD type not configured, Error */
          bLoopEnd = TRUE;
          u32DidSize = 0;
          u32ResLength = 0;
        #endif
        break;
      }

      /*! Accumulate DID size into the response size */
      u32ResLength += u32DidSize;
    }
  }

  return u32ResLength;
}

#endif
#endif

#if (DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-0019(0), CDD-1014(0), CDD-1015(0), CDD-1016(0), CDD-1017(0)
                 CDD-1018(0), CDD-1019(0), CDD-3022(0)                      \n\n
    \Description Check on all the Dids in the request message if they are
                 supported, security enabled and accessible in current session.
                 Also the referenced Dids.                                    \n
    \param[in]   pstrMsgContext  Message context                              \n
    \Range       Null, not Null                                               \n
    \param[out]  pu8NegResCode   NRC to be reported                           \n
    \Range       0..255                                                       \n
    \return      Flag raised if NRC should be reported                        \n
    \Range       FALSE, TRUE                                                  \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static FUNC(boolean,DCM_CODE) bFullCheckDid (
         P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext,
         P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode)
{
  boolean bSendNegResp = TRUE;
  boolean bLoopEnd = FALSE;
  uint16  u16Did;
  uint16  u16DidIndex = 0;
  uint8   u8DidRef;
  uint16  u16DidRefIndex;
  boolean bDidFound;
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
          pkstrDidAccess;
  boolean bIsDidSupported;
  boolean bIsDidReadSecurity;
  boolean bIsDidReadSession;
  uint16  u16NumOfDid = 0;
  uint16  u16RxBufferIndex;
  uint8   u8DidType;
  uint8   u8IdContext;
  uint8   u8ObdDid;
  uint8   u8ObdDidIndex;
  uint16  u16DidIndexStore;

  u8IdContext = pkstrMsgContext->idContext;
  
  /*! Loop on every DID in the request message. */
  for (u16RxBufferIndex = 0;
       (u16RxBufferIndex < pkstrMsgContext->reqDataLen)
       && (bLoopEnd == FALSE);
       u16RxBufferIndex = (uint16)(u16RxBufferIndex + 2))

  {
    u16Did = pkstrMsgContext->reqData[u16RxBufferIndex];
    u16Did = (uint16)((u16Did << 8) + 
      pkstrMsgContext->reqData[u16RxBufferIndex + 1]);
    bDidFound = FALSE;
    *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;
    u8ObdDid = (uint8)(u16Did & 0x00FF);
    
    /*! Check the following for each DID: */

    /*!   Supported or not */
    /*! If DID is an OBD availability ID */
    if ((((u16Did >= u16OBD_DID_RANGE1_MIN) && (u16Did <= u16OBD_DID_RANGE1_MAX))
      || ((u16Did >= u16OBD_DID_RANGE2_MIN) && (u16Did <= u16OBD_DID_RANGE2_MAX))
      || ((u16Did >= u16OBD_DID_RANGE3_MIN) && (u16Did <= u16OBD_DID_RANGE3_MAX)))
      && ((u8ObdDid % 0x20) == 0))
    {
      bIsDidSupported = TRUE;
      /*! For availability DIDs, the required info to be stored is the DID
          identifier itself */
      u16DidIndexStore = u16Did;
      /*! Assign the DID type based on the DID range */
      if (u16Did <= u16OBD_DID_RANGE1_MAX)
      {
        u8DidType = u8DID_OBD1_AVAIL;
      }
      else if (u16Did <= u16OBD_DID_RANGE2_MAX)
      {
        u8DidType = u8DID_OBD2_AVAIL;
      }
      else /*((u16Did >= u16OBD_DID_RANGE3_MIN) && (u16Did <= u16OBD_DID_RANGE3_MAX))*/
      {
        u8DidType = u8DID_OBD3_AVAIL;
      }
    }
    /*! If DID in the UDS or OBD ranges */
    else
    {
      bIsDidSupported = bCheckDidSupported(u16Did,&u16DidIndex);
      if (bIsDidSupported == TRUE)
      {
        if ((u16Did < u16OBD_DID_RANGE1_MIN) || (u16Did > u16OBD_DID_RANGE3_MAX))
        {
          u8DidType = u8DID_UDS;
          u16DidIndexStore = u16DidIndex;
        }
        /*! In non-availability OBD range for service $01 */
        else if (u16Did <= u16OBD_DID_RANGE1_MAX)
        {
          
          #if(DCM_u8NUM_OF_PIDS > 0U)
          u8DidType = u8DID_OBD1;
          bIsDidSupported = DspInternal_bIsPIDSupported (u8ObdDid, &u8ObdDidIndex);
          u16DidIndexStore = (uint16)u8ObdDidIndex;
          #else
          bIsDidSupported = FALSE;
          #endif
         
        }
        /*! In non-availability OBD range for service $06 */
        else if ((u16Did >= u16OBD_DID_RANGE2_MIN) && (u16Did <= u16OBD_DID_RANGE2_MAX))
        {
          #if (DCM_u8NUM_OBDMID > 0U)
          u8DidType = u8DID_OBD2;
          bIsDidSupported = DspInternal_bIsSupportedOBDMID (u8ObdDid, &u8ObdDidIndex);
          u16DidIndexStore = (uint16)u8ObdDidIndex;
          #else
          bIsDidSupported = FALSE;
          #endif
        }
        /*! In non-availability OBD range for service $09 */
        else if (u16Did >= u16OBD_DID_RANGE3_MIN)
        {
          #if (DCM_u8NUM_OF_VEHICLE_INFO > 0U)
          u8DidType = u8DID_OBD3;
          bIsDidSupported = DspInternal_bIsSupportedVehInfo (u8ObdDid, &u8ObdDidIndex);
          u16DidIndexStore = (uint16)u8ObdDidIndex;
          #else
          bIsDidSupported = FALSE;
          #endif
        }
        else
        {
          /*! Not in the OBD 3 ranges, then it's invalid DID */
          bIsDidSupported = FALSE;
        }
      }
    }

    if(bIsDidSupported == TRUE)
    {
      pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
        pkstrDspDidInfoRef->strDcmDspDidAccess;

      if (pkstrDidAccess->pkstrDcmDspDidRead != (Dcm_DspDidReadType*)NULL_PTR)
      {
        bIsDidReadSession = FALSE;
        /*!   Has read access in current security level */
        bIsDidReadSecurity = bCheckDidReadSecurity(u16DidIndex);
        if(bIsDidReadSecurity == TRUE)
        {
          /*!   Has read access in current session */
          bIsDidReadSession = bCheckDidReadSession(u16DidIndex);
       
        }
        else
        {
          /*! If no read access in current security, then NRC
              "SECUTITYACCESSDENIED" with no need to check other DIDs */
          bLoopEnd = TRUE;
          bSendNegResp = TRUE;
          *pu8NegResCode = DCM_E_SECURITYACCESSDENIED;
        }

        if((bIsDidReadSecurity == TRUE) && 
           (bIsDidReadSession == TRUE))
        {
          #if (DCM_u16DSP_MAX_DID_TO_READ != 0U)
          /*! If the number of Dids reached maximum and another supported
          Did is found, report NRC */
          if (u16NumOfDid == (uint16)DCM_u16DSP_MAX_DID_TO_READ)
          {
            bSendNegResp = TRUE;
            bLoopEnd = TRUE;
            *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;
          }
          else
          {
          #endif
            bSendNegResp = FALSE;
            /* !Deviation : Inhibit rule [3353]: u16DidIndexStore and u8DidType        */
            /*              are set at this point                                      */
            /* PRQA S 3353 ++                                                          */
            u16DSP_DID_IDX[u16NumOfDid] = u16DidIndexStore;
            au8DSP_DID_TYPES[u16NumOfDid] = u8DidType;
            /* PRQA S 3353 ++                                                          */
            u16NumOfDid++;
            bDidFound = TRUE;
          #if (DCM_u16DSP_MAX_DID_TO_READ != 0U)
          }
          #endif
        }
      }
    }

    /*! If there is no Security Denied and the Did references other Dids, */
    if ((bDidFound == TRUE) && (Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                             pkstrDcmDspDidRef != (uint16*)NULL_PTR))
    {
      /*! Loop on referenced Dids to check them */
      for (u8DidRef = 0;
          (u8DidRef<Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].u8NumOfDidRef)
           && (bLoopEnd == FALSE);
           u8DidRef++)
      {
        u16DidRefIndex = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                           pkstrDcmDspDidRef[u8DidRef];
        
        /*! Supported or not */
        if (Dcm_pkstrePbConfig->strPbDcmDspConfig.
              pkstrDcmDspDid[u16DidRefIndex].bDcmDspDidUsed  == TRUE)
        {
          u16Did = Dcm_kstreDspConfig.astrDcmDspDid[u16DidRefIndex].
            u16DcmDspDidIdentifier;
          u8ObdDid = (uint8)(u16Did & 0x00FF);

          /*! If DID in the UDS range */
          if ((u16Did < u16OBD_DID_RANGE1_MIN) || (u16Did > u16OBD_DID_RANGE3_MAX))
          {
            u8DidType = u8DID_UDS;
            u16DidIndexStore = u16DidRefIndex;
            bIsDidSupported = TRUE;
          }
          /*! If DID is an OBD availability ID */
          else if ((u8ObdDid % 0x20) == 0)
          {
            bIsDidSupported = TRUE;
            /*! For availability DIDs, the required info to be stored is the DID
                identifier itself */
            u16DidIndexStore = u16Did;
            /*! Assign the DID type based on the DID range */
            if (u16Did <= u16OBD_DID_RANGE1_MAX)
            {
              u8DidType = u8DID_OBD1_AVAIL;
            }
            else if ((u16Did >= u16OBD_DID_RANGE2_MIN) && (u16Did <= u16OBD_DID_RANGE2_MAX))
            {
              u8DidType = u8DID_OBD2_AVAIL;
            }
            else if (u16Did >= u16OBD_DID_RANGE3_MIN)
            {
              u8DidType = u8DID_OBD3_AVAIL;
            }
            else
            {
              /*! Not in the OBD 3 ranges, then it's invalid DID */
              bIsDidSupported = FALSE;
            }
          }
          /*! In non-availability OBD range for service $01 */
          else if (u16Did <= u16OBD_DID_RANGE1_MAX)
          {
            #if(DCM_u8NUM_OF_PIDS > 0U)
            u8DidType = u8DID_OBD1;
            bIsDidSupported = DspInternal_bIsPIDSupported (u8ObdDid, &u8ObdDidIndex);
            u16DidIndexStore = (uint16)u8ObdDidIndex;
            #else
            bIsDidSupported = FALSE;
            #endif
          }
          /*! In non-availability OBD range for service $06 */
          else if ((u16Did >= u16OBD_DID_RANGE2_MIN) && (u16Did <= u16OBD_DID_RANGE2_MAX))
          {
            #if (DCM_u8NUM_OBDMID > 0U)
            u8DidType = u8DID_OBD2;
            bIsDidSupported = DspInternal_bIsSupportedOBDMID (u8ObdDid, &u8ObdDidIndex);
            u16DidIndexStore = (uint16)u8ObdDidIndex;
            #else
            bIsDidSupported = FALSE;
            #endif
          }
          /*! In non-availability OBD range for service $09 */
          else if (u16Did >= u16OBD_DID_RANGE3_MIN)
          {
            #if (DCM_u8NUM_OF_VEHICLE_INFO > 0U)
            u8DidType = u8DID_OBD3;
            bIsDidSupported = DspInternal_bIsSupportedVehInfo (u8ObdDid, &u8ObdDidIndex);
            u16DidIndexStore = (uint16)u8ObdDidIndex;
            #else
            bIsDidSupported = FALSE;
            #endif
          }
          else
          {
            /*! Not in the OBD 3 ranges, then it's invalid DID */
            bIsDidSupported = FALSE;
          }

          if (bIsDidSupported == TRUE)
          {
            pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DidRefIndex].
              pkstrDspDidInfoRef->strDcmDspDidAccess;
            bSendNegResp = FALSE;

            if (pkstrDidAccess->pkstrDcmDspDidRead != (Dcm_DspDidReadType*)NULL_PTR)
            {
              bIsDidReadSession = FALSE;
              /*!   Has read access in current security level */
              bIsDidReadSecurity = bCheckDidReadSecurity(u16DidRefIndex);
              if(bIsDidReadSecurity == TRUE)
              {
                /*!   Has read access in current session */
                bIsDidReadSession = bCheckDidReadSession(u16DidRefIndex);
             
              }
              else
              {
                /*! If no read access in current security, then NRC
                    "SECUTITYACCESSDENIED" with no need to check other DIDs */
                bLoopEnd = TRUE;
                bSendNegResp = TRUE;
                *pu8NegResCode = DCM_E_SECURITYACCESSDENIED;
              } 

              /* !Deviation : Inhibit rule [0715]: Nesting of control structures can't be   */
              /*              simplified                                                    */
              /* PRQA S 0715 ++                                                             */
              if((bIsDidReadSecurity == TRUE) &&
                (bIsDidReadSession == TRUE))
              {
                #if (DCM_u16DSP_MAX_DID_TO_READ != 0U)
                /*! If the number of Dids reached maximum and another supported
                Did is found, report NRC */
                if (u16NumOfDid == (uint16)DCM_u16DSP_MAX_DID_TO_READ)
                {
                  bSendNegResp = TRUE;
                  bLoopEnd = TRUE;
                  *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;
                }
                else
                {
                #endif
                  bSendNegResp = FALSE;
                  u16DSP_DID_IDX[u16NumOfDid] = u16DidIndexStore;
                  au8DSP_DID_TYPES[u16NumOfDid] = u8DidType;
                  u16NumOfDid++;
                #if (DCM_u16DSP_MAX_DID_TO_READ != 0U)
                }
                #endif
              }
              /* PRQA S 0715 --                                                             */
            }
    
          }
        }
      }
    }
  }

  u16DSP_NUM_DID = u16NumOfDid;
  return bSendNegResp;
}

/* PRQA S 4700 --                                                             */
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1021(0), CDD-1547(0), CDD-1524(0)                      \n\n
    \Description Check conditions of reading of all data inside a DID         \n
    \param[in]   u16DidArrayIndex    Index of Did inside the array            \n
    \Range       0..u16DSP_NUM_DID-1                                         \n
    \param[in]   u8SignalIndexStart  Signal index inside the DID to start with\n
    \Range       0..u8NumOfDidSignal-1                                        \n
    \param[in]   u8CondCheckStatus   The OpStatus of the first call to 
                                     application condition check interface    \n
    \Range       DCM_INITIAL, DCM_PENDING                                     \n
    \param[out]  pu8NegResCode       The NRC to be reported                   \n
    \Range       0..255                                                       \n
    \param[out]  pbLoopEnd           Flag indicating if the loop on data is
                                     terminated                               \n
    \Range       TRUE, FALSE                                                  \n
    \param[in]   u8ServiceStatus     Service which requests this check        \n
    \Range       DspInternal_u8RDBI, DspInternal_u8IOCTRL                                             \n
    \param[in]   u8IdContext         Context Id of current protocol           \n
    \Range       0..DspInternal_u8MAX_NUM_INTERNAL_REQ                                \n
    \return      An NRC occured while condition checking or not.              \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static FUNC(boolean,DCM_CODE) bCheckDidConditions (
         uint16 u16DidArrayIndex,
         uint8  u8SignalIndexStart,
         Dcm_OpStatusType u8CondCheckStatus,
         P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
         P2VAR(boolean,AUTOMATIC,AUTOMATIC) pbLoopEnd,
         uint8 u8ServiceStatus,
         Dcm_IdContextType u8IdContext)
{
  uint8   u8SignalIndex;
  uint8   u8CondCheckReturn;
  uint8   u8ErrorCode = 0;
  uint16  u16DidIndex;
  uint32  u32DataRef;
  boolean bSendNegResp = FALSE;

  u16DidIndex = u16DSP_DID_IDX[u16DidArrayIndex];

  #if(DCM_bRDBI_EN == STD_ON)
  /*! If the Did is of ActiveSession, then return "No NRC is to be reported" */
  if ((Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].u16DcmDspDidIdentifier
        == u16ACTIVE_SESSION_DID)
      || (Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].u16DcmDspDidIdentifier
        == DCM_u16MAX_NUM_DIDS_1REQ_DID))
  {
    bSendNegResp = FALSE;
  }
  else
  {
  #endif
    /*! Else, loop on all signals inside the Did */
    for (u8SignalIndex = u8SignalIndexStart;
        (u8SignalIndex < Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                         u8NumOfDidSignal)
        && (*pbLoopEnd == FALSE);
         u8SignalIndex++)
        
    {
      u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                   pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;

      /*! If some app interface is pending and the cancel flag is raised */
      if ((u8CondCheckStatus == DCM_PENDING)
            && (DspInternal_pu8DSP_MSGCONTEXT->msgAddInfo.cancelOperation == 1))
      {
        /*! To cancel the app interface */
        u8CondCheckStatus = DCM_CANCEL;
      }
      
      /*! If above checks are ok, then call the configured function to check
          conditions for reading this DID */
      switch (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].u8DcmDspDataUsePort)
      {
        case USE_DATA_SYNCH_CLIENT_SERVER:
        u8CondCheckReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataConditionCheckReadSync)(&u8ErrorCode);
        break;

        case USE_DATA_ASYNCH_CLIENT_SERVER:
        u8CondCheckReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataConditionCheckReadAsync)(u8CondCheckStatus,&u8ErrorCode);
        break;

        case USE_FNC:
        u8CondCheckReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataConditionCheckReadFnc)(u8CondCheckStatus,&u8ErrorCode);
        break;

        default:
        if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              pfDcmDspDataConditionCheckReadFnc != NULL_PTR)
        {
          u8CondCheckReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataConditionCheckReadFnc)(u8CondCheckStatus,&u8ErrorCode);
        }
        else
        {
          u8CondCheckReturn = E_OK;
        }
        break;
      }

      /*! To complete cancelling the service, call ProcessingDone
          and set status to idle & cancel */
      if (u8CondCheckStatus == DCM_CANCEL)
      {
        *pbLoopEnd = TRUE;
        DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
        DspInternal_u8DSP_STATUS = u8CANCEL;
      }
      /*! If the conditions check result is pending, then refer the
          operation to the MainFunc */
      else if(u8CondCheckReturn == E_PENDING)
      {
        DspInternal_u8DSP_SUBSTATUS = u8RDBI_COND_CHK_PEND;
        u16DSP_DID_ARR_INDEX = u16DidArrayIndex;
        u8DSP_SIGNAL_INDEX = u8SignalIndex;
        *pbLoopEnd = TRUE;
        DspInternal_u8DSP_STATUS = u8ServiceStatus;
      }
      /*! If the conditions check result is not ok, then the NRC returned
          from the condition check  function is to be sent. No need to
          continue looping. */
      else if (u8CondCheckReturn != E_OK)
      {
        bSendNegResp = TRUE;
        *pbLoopEnd = TRUE;
        *pu8NegResCode = u8ErrorCode;
      }
      else
      {
        /* E_OK, nothing to be done */
      }

      u8CondCheckStatus = DCM_INITIAL;
    }
  #if(DCM_bRDBI_EN == STD_ON)
  }
  #endif

  return bSendNegResp;
}
/* PRQA S 4700 --                                                             */
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||     \
       DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-0020(0)                                                \n\n
    \Description Read all signals inside a DID                                \n
    \param[in]   u16DidArrayIndex  The index of DID inside the supported DID
                                   array.                                     \n
    \Range       0..u16DSP_NUM_DID-1                                         \n
    \param[in]   u8SignalIndexStart  Signal index inside the DID to start with\n
    \Range       0..u8NumOfDidSignal-1                                        \n
    \param[in]   u8ReadCheckStatus   OpStatus to use in the first call to
                                     application interface                    \n
    \Range       DCM_INITIAL, DCM_PENDING                                     \n
    \param[in]   u16NumOfSignalsToRead Max number of signals to read per
                                       function call                          \n
    \Range       0..65535                                                     \n
    \param[out]  pstrMsgContext      Pointer to the message context           \n
    \Range       Null, Not Null                                               \n
    \param[out]  pu8NegResCode       NRC to be reported                       \n
    \Range       0..255                                                       \n
    \param[out]  pbLoopEnd           Flag indicating if the loop on data is
                                     terminated                               \n
    \Range       TRUE, FALSE                                                  \n
    \param[out]  pu16NumOfReadSignals   Number of signals that were read      \n
    \Range       0..65535                                                     \n
    \param[in]   u8ServiceStatus     Service which requests this read         \n
    \Range       DspInternal_u8RDBI, DspInternal_u8IOCTRL                                             \n
    \return      An NRC occured while reading or not.                         \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static FUNC(boolean,DCM_CODE) bReadDidAllSignals (
         uint16 u16DidArrayIndex,
         uint8  u8SignalIndexStart,
         Dcm_OpStatusType u8ReadCheckStatus,
         uint16 u16NumOfSignalsToRead,
         P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pstrMsgContext,
         P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
         P2VAR(boolean,AUTOMATIC,AUTOMATIC) pbLoopEnd,
         P2VAR(uint16,AUTOMATIC,AUTOMATIC) pu16NumOfReadSignals,
         uint8 u8ServiceStatus)
{
  uint16                   u16DidIndex;
  boolean                  bSendNegResp = FALSE;
  uint8                    u8SignalIndex;
  uint16                   u16DataPos;
  Dcm_IdContextType        u8IdContext;
  uint16                   u16Did;

  u8IdContext = pstrMsgContext->idContext;

  u16DidIndex = u16DSP_DID_IDX[u16DidArrayIndex];

  #if(DCM_bRDBI_EN == STD_ON)
  /*! Check if this is the DID of Active Session */
  if ((Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].u16DcmDspDidIdentifier ==
        u16ACTIVE_SESSION_DID)
      || (Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].u16DcmDspDidIdentifier ==
        DCM_u16MAX_NUM_DIDS_1REQ_DID))
  {
    if (Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].u16DcmDspDidIdentifier ==
          u16ACTIVE_SESSION_DID)
    {
      /*! Call the read function of active session */
      bSendNegResp = bReadActiveSessionDid(pu8NegResCode, u8ServiceStatus,
                     u8IdContext);
    }
    else
    {
      /*! Call the read function of max num of DIDs in one request */
      bSendNegResp = bReadMaxNumofDid(pu8NegResCode, u8ServiceStatus,
                     u8IdContext);
    }

    if (bSendNegResp == FALSE)
    {
      (*pu16NumOfReadSignals)++;
      /*! If limit of read signals reached, stop & continue at next func call */
      if ((u16NumOfSignalsToRead != 0)
            && (*pu16NumOfReadSignals == u16NumOfSignalsToRead))
      {
        if (u16DidArrayIndex == (u16DSP_NUM_DID - 1))
        {
          DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
        }
        else
        {
          u8DSP_SIGNAL_INDEX = 0;
          u16DSP_DID_ARR_INDEX = (uint16)(u16DidArrayIndex + 1);
          /*! Save the message context pointer */
          DspInternal_pu8DSP_MSGCONTEXT = pstrMsgContext;
          DspInternal_u8DSP_SUBSTATUS = u8RDBI_READ_NEXT_DID;
          DspInternal_u8DSP_STATUS = u8ServiceStatus;
        }
      }
    }
    else
    {
      *pbLoopEnd = TRUE;
    }
  }
  else
  {
  #endif
    /*! If it is the first signal to be read in current Did. */
    if ((u8ServiceStatus == DspInternal_u8RDBI) && (u8ReadCheckStatus == DCM_INITIAL)
          && (u8SignalIndexStart == 0))
    {
      /*! Check on the resMaxDataLen */
      if (pstrMsgContext->resMaxDataLen >= (uint32)(u16DSP_TX_BUFF_INDEX + 2))
      {
        /*! Then, fill Tx buffer with the Did and increment the buffer index. */
        u16Did = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                 u16DcmDspDidIdentifier;
        pstrMsgContext->resData[u16DSP_TX_BUFF_INDEX] =
          (uint8)((u16Did & 0xFF00) >> 8);
        pstrMsgContext->resData[u16DSP_TX_BUFF_INDEX+ (uint16)1] =
          (uint8)(u16Did & 0x00FF);
        u16DSP_TX_BUFF_INDEX = (uint16)(u16DSP_TX_BUFF_INDEX + (uint16)2);
      }
      else
      {
        /*! If buffer overflow, report NRC "ResponseTooLong" & report to DET */
        bSendNegResp = TRUE;
        *pu8NegResCode = DCM_E_RESPONSETOOLONG;

        #if (DCM_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
            Dcm_u8UDS_RDBI_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
        #endif
      }
    }

    if (bSendNegResp == FALSE)
    {
      /*! If conditions are ok, */ 
      for (u8SignalIndex = u8SignalIndexStart;
          (u8SignalIndex < Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                           u8NumOfDidSignal)
           && (*pbLoopEnd == FALSE);
           u8SignalIndex++)
      {
        /*! Begin reading the DID signals. */
        bSendNegResp = bReadDidSignal(u16DidArrayIndex, u8SignalIndex,
          pu8NegResCode, u8ReadCheckStatus, u8ServiceStatus, u8IdContext);

        if (DspInternal_u8DSP_STATUS == u8CANCEL)
        {
          *pbLoopEnd = TRUE;
        }
        else if (bSendNegResp == TRUE)
        {
          *pbLoopEnd = TRUE;
        }
        /*! If read operation is pending, then continue at next function call */
        else if (DspInternal_u8DSP_SUBSTATUS == u8RDBI_READ_PENDING)
        {
          *pbLoopEnd = TRUE;
          u16DSP_DID_ARR_INDEX = u16DidArrayIndex;
          u8DSP_SIGNAL_INDEX = u8SignalIndex;
          DspInternal_pu8DSP_MSGCONTEXT = pstrMsgContext;
          DspInternal_u8DSP_STATUS = u8ServiceStatus;
        }
        else
        {
          (*pu16NumOfReadSignals)++;

          /*! If this is the last signal to be read in this DID */
          if ((Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                u8NumOfDidSignal - 1) == u8SignalIndex)
          {
            /*! Moving u16DSP_TX_BUFF_INDEX to point to the byte just after the
                last written Did */
            u16DataPos = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                pkstrDcmDspDidSignal[u8SignalIndex].u16DcmDspDidDataPos;
            u16DSP_TX_BUFF_INDEX = (uint16)(u16DSP_TX_BUFF_INDEX +
                                      ((u16DSP_DATA_LEN + u16DataPos + 7)/8));
          }
          
          /*! If limit of read signals is reached, continue at next func call */
          if ((u16NumOfSignalsToRead != 0)
                && (*pu16NumOfReadSignals == u16NumOfSignalsToRead))
          {
            *pbLoopEnd = TRUE;
            if ((Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                 u8NumOfDidSignal - 1) > u8SignalIndex)
            {
              u16DSP_DID_ARR_INDEX = u16DidArrayIndex;
              u8DSP_SIGNAL_INDEX = (uint8)(u8SignalIndex + 1);
              /*! Save the message context pointer */
              DspInternal_pu8DSP_MSGCONTEXT = pstrMsgContext;
              DspInternal_u8DSP_SUBSTATUS = u8RDBI_READ_NEXT_SIG;
              DspInternal_u8DSP_STATUS = u8ServiceStatus;
            }
            else if (u16DidArrayIndex < (u16DSP_NUM_DID - 1))
            {
              u16DSP_DID_ARR_INDEX = (uint16)(u16DidArrayIndex + 1);
              u8DSP_SIGNAL_INDEX = 0;
              /*! Save the message context pointer */
              DspInternal_pu8DSP_MSGCONTEXT = pstrMsgContext;
              DspInternal_u8DSP_SUBSTATUS = u8RDBI_READ_NEXT_DID;
              DspInternal_u8DSP_STATUS = u8ServiceStatus;
            }
            else
            {
              /* Last signal in the last Did in the message */
            }
          }
          /* If last signal in the Did and not the last Did in the message */
          else if ((u16DidArrayIndex < (u16DSP_NUM_DID - 1))
            && ((Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                   u8NumOfDidSignal - 1) == u8SignalIndex))
          {
            u16DSP_DID_ARR_INDEX = (uint16)(u16DidArrayIndex + 1);
            u8DSP_SIGNAL_INDEX = 0;
            /*! Save the message context pointer */
            DspInternal_pu8DSP_MSGCONTEXT = pstrMsgContext;
            DspInternal_u8DSP_SUBSTATUS = u8RDBI_READ_NEXT_DID;
            DspInternal_u8DSP_STATUS = u8ServiceStatus;
          }
          else
          {
            /*! Do Nothing */
          }

          if  (((Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
                 u8NumOfDidSignal - 1) == u8SignalIndex)
                 && (u16DidArrayIndex == (u16DSP_NUM_DID - 1)))
          {
            /* Last signal in the last Did in the message */
            DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
            *pbLoopEnd = TRUE;
          }
        }

        u8ReadCheckStatus = DCM_INITIAL;
      }
    }
  #if(DCM_bRDBI_EN == STD_ON)  
  }
  #endif
  
  return bSendNegResp;
}
/* PRQA S 4700 --                                                             */

#endif


#if (DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To      CDD-0962(0)                                              \n\n
    \Description   Function to read Active Session DID                        \n
    \param[out]    pu8NegResCode     NRC occured while reading DID            \n
    \Range         0..255                                                     \n
    \param[in]     u8ServiceStatus   Service which requests this read         \n
    \Range         DspInternal_u8RDBI, DspInternal_u8IOCTRL                                           \n
    \param[in]     u8IdContext       The message context ID                   \n
    \Range         0..DspInternal_u8MAX_NUM_INTERNAL_REQ                              \n
    \return        An NRC occured while reading or not.                       \n
    \Range         TRUE, FALSE                                                \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bReadActiveSessionDid (
               P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8NegResCode,
               uint8 u8ServiceStatus,
               Dcm_IdContextType u8IdContext)
{
  Dcm_SesCtrlType u8ActiveSession;
  boolean         bSendNegResp = FALSE;
  
  if (u16DSP_TX_BUFF_INDEX > (DspInternal_pu8DSP_MSGCONTEXT->resMaxDataLen-3))
  {
    /*! If insufficient buffer, then the function returns TRUE and set NRC by
        RESPONSETOOLONG. */
    bSendNegResp = TRUE;
    *pu8NegResCode = DCM_E_RESPONSETOOLONG;

    /*! Report BufferOverflow to DET */
    #if (DCM_DEV_ERROR_DETECT == STD_ON)
    if (u8ServiceStatus == DspInternal_u8RDBI)
    {
      Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
          Dcm_u8UDS_RDBI_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
    }
    else
    {
      Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
          Dcm_u8IO_CTRL_BY_IDENT_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
    }
    #endif
  }
  else
  {
    /*! Get the active session by Dcm_GetSesCtrlType */
    (void)Dcm_GetSesCtrlType(&u8ActiveSession);
   
    /*! And fill the response message */
    DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX] =
      (uint8)((u16ACTIVE_SESSION_DID & 0xFF00) >> 8);
    DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX + (uint16)1] =
      (uint8)(u16ACTIVE_SESSION_DID & 0x00FF);
    DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX + (uint16)2] =
      u8ActiveSession;
    u16DSP_TX_BUFF_INDEX = (uint16)(u16DSP_TX_BUFF_INDEX + (uint16)3);
  }

  return bSendNegResp;
}

/******************************************************************************/
/*! \Trace_To      CDD-1990(0)                                              \n\n
    \Description   Function to read max number of DIDs in one request         \n
    \param[out]    pu8NegResCode     NRC occured while reading DID            \n
    \Range         0..255                                                     \n
    \param[in]     u8ServiceStatus   Service which requests this read         \n
    \Range         DspInternal_u8RDBI, DspInternal_u8IOCTRL                                           \n
    \param[in]     u8IdContext       The message context ID                   \n
    \Range         0..DspInternal_u8MAX_NUM_INTERNAL_REQ                              \n
    \return        An NRC occured while reading or not.                       \n
    \Range         TRUE, FALSE                                                \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bReadMaxNumofDid (
               P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8NegResCode,
               uint8 u8ServiceStatus,
               Dcm_IdContextType u8IdContext)
{
  boolean         bSendNegResp = FALSE;
  
  if (u16DSP_TX_BUFF_INDEX > (DspInternal_pu8DSP_MSGCONTEXT->resMaxDataLen-4))
  {
    /*! If insufficient buffer, then the function returns TRUE and set NRC by
        RESPONSETOOLONG. */
    bSendNegResp = TRUE;
    *pu8NegResCode = DCM_E_RESPONSETOOLONG;

    /*! Report BufferOverflow to DET */
    #if (DCM_DEV_ERROR_DETECT == STD_ON)
    if (u8ServiceStatus == DspInternal_u8RDBI)
    {
      Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
          Dcm_u8UDS_RDBI_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
    }
    else
    {
      Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
          Dcm_u8IO_CTRL_BY_IDENT_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
    }
    #endif
  }
  else
  {
    /*! And fill the response message */
    DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX] =
      (uint8)((DCM_u16MAX_NUM_DIDS_1REQ_DID & 0xFF00) >> 8);
    DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX + (uint16)1] =
      (uint8)(DCM_u16MAX_NUM_DIDS_1REQ_DID & 0x00FF);
    DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX + (uint16)2] =
      (uint8)(((uint16)DCM_u16DSP_MAX_DID_TO_READ & 0xFF00) >> 8);
    DspInternal_pu8DSP_MSGCONTEXT->resData[u16DSP_TX_BUFF_INDEX + (uint16)3] =
      (uint8)((uint16)DCM_u16DSP_MAX_DID_TO_READ & 0x00FF);
    u16DSP_TX_BUFF_INDEX = (uint16)(u16DSP_TX_BUFF_INDEX + (uint16)4);
  }

  return bSendNegResp;
}


/******************************************************************************/
/*! \Trace_To    CDD-1013(0), CDD-DSP-0010(0), CDD-DSP-0013(0), CDD-DSP-0004(0)
                                                                            \n\n
    \Description MainFunction handling the ReadDataById diag service          \n
    \param[in]   u8IdContext      The message context ID                      \n
    \Range       0..DspInternal_u8MAX_NUM_INTERNAL_REQ                                \n
    \return      Void                                                         \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_vidMainRdbi (
  Dcm_IdContextType u8IdContext)
{
  boolean                      bSendNegResp = FALSE;
  uint16                       u16DidArrayIndex;
  boolean                      bLoopEnd = FALSE;
  Dcm_NegativeResponseCodeType u8NegResCode = 0;
  uint16                       u16NumOfReadSignals = 0;
  uint8                        u8DidType;

  /*! If Cancellation bit is high and DSP sub status is Read Next Signal
      or Read Next DID Then */
  if ((DspInternal_pu8DSP_MSGCONTEXT->msgAddInfo.cancelOperation == 1) &&
      ((DspInternal_u8DSP_SUBSTATUS == u8RDBI_READ_NEXT_SIG) ||
      (DspInternal_u8DSP_SUBSTATUS == u8RDBI_READ_NEXT_DID)))
  {
    /*! Set DSP sub status to IDLE */
    DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;

    /*! Set Dsp status to Cancel */
    DspInternal_u8DSP_STATUS = u8CANCEL;
  }
  /*! Else */
  else
  {
    /*! Check the sub status */
    switch (DspInternal_u8DSP_SUBSTATUS)
    {
      /*! If ConditionCheck is pending, then continue by ConditionCheck starting
          last signal in current DID. Then, Begin reading signals from the DID
          starting from the first signal */
      case u8RDBI_COND_CHK_PEND:
      /*! Set DSP sub status to IDLE */
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
     
      bSendNegResp = bCheckDidConditions (u16DSP_DID_ARR_INDEX, u8DSP_SIGNAL_INDEX,
        DCM_PENDING, &u8NegResCode, &bLoopEnd, DspInternal_u8RDBI, u8IdContext);
      if ((bSendNegResp == FALSE) && (bLoopEnd == FALSE))
      {
        bSendNegResp = bReadDidAllSignals (u16DSP_DID_ARR_INDEX, 0, DCM_INITIAL,
                                           DCM_u16DSP_SIGNALS_TO_READ_IN_TASK,
                                           DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
                                           &bLoopEnd, &u16NumOfReadSignals,
                                           DspInternal_u8RDBI);
      }
      break;

      /*! If ReadOperation is pending, then continue by reading signals from the
          current DID starting from the last read signal */
      case u8RDBI_READ_PENDING:
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      bSendNegResp = bReadDidAllSignals (u16DSP_DID_ARR_INDEX, u8DSP_SIGNAL_INDEX,
                                         DCM_PENDING,
                                         DCM_u16DSP_SIGNALS_TO_READ_IN_TASK,
                                         DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
                                         &bLoopEnd, &u16NumOfReadSignals, DspInternal_u8RDBI);
      break;

      /*! If no operation is pending, then continue by reading the next signals
          from the current DID. */
      case u8RDBI_READ_NEXT_SIG:
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      bSendNegResp = bReadDidAllSignals (u16DSP_DID_ARR_INDEX, u8DSP_SIGNAL_INDEX,
                                         DCM_INITIAL,
                                         DCM_u16DSP_SIGNALS_TO_READ_IN_TASK,
                                         DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
                                         &bLoopEnd, &u16NumOfReadSignals, DspInternal_u8RDBI);
      break;

      case u8RDBI_READ_NEXT_DID:
      /*! If no operation is pending, and the last signal in the current DID was
          already read. */
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      /*! No extra functions to be called */
      break;
      default:
      break;
    }
  }

  /*! If OK & no cancellation, */
  if ((DspInternal_u8DSP_STATUS != u8CANCEL) && (bSendNegResp == FALSE))
  {
    /*! Begin looping on rest of DIDs to check condition and read their data */
    for (u16DidArrayIndex = u16DSP_DID_ARR_INDEX;
         (u16DidArrayIndex < u16DSP_NUM_DID)
         && (bLoopEnd == FALSE);
         u16DidArrayIndex++)
    {
      u8DidType = au8DSP_DID_TYPES[u16DidArrayIndex];

      /*! Check the DID range, should be inside UDS range. */
      if (u8DidType == u8DID_UDS)
      {
        bSendNegResp = bCheckDidConditions (u16DidArrayIndex, 0, DCM_INITIAL,
                                            &u8NegResCode, &bLoopEnd, DspInternal_u8RDBI,
                                            u8IdContext);
        if ((bSendNegResp == FALSE) && (bLoopEnd == FALSE))
        {
          bSendNegResp = bReadDidAllSignals (u16DidArrayIndex, 0, DCM_INITIAL,
                                             DCM_u16DSP_SIGNALS_TO_READ_IN_TASK,
                                             DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
                                             &bLoopEnd, &u16NumOfReadSignals,
                                             DspInternal_u8RDBI);
        }
      }
      else
      {
        /*! OBD range, not implemented */
        /*! So NRC RequestOutOfRange */
        bSendNegResp = TRUE;
        bLoopEnd = TRUE;
        u8NegResCode = DCM_E_REQUESTOUTOFRANGE;
      }
    }
  }

  /*! If no cancellation */
  if (DspInternal_u8DSP_STATUS != u8CANCEL)
  {
    /*! Report the NRC if an error has occured */
    if (bSendNegResp == TRUE)
    {
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_SetNegResponse(DspInternal_pu8DSP_MSGCONTEXT,u8NegResCode);  
      DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
    }
    else if (DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
    {
      /*! Set the response length in the message context */
      DspInternal_pu8DSP_MSGCONTEXT->resDataLen = u16DSP_TX_BUFF_INDEX;
      /*! Call processing done of the DSD */
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
    }
    else
    {
      /* Nothing */
    }
  }
  else
  {
    /*! Service is cancelled, return status to idle */
    DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
    DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
  }
}
/* PRQA S 4700 --                                                             */
#endif

#if (DCM_bWDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1037(0), CDD-DSP-0014(0), CDD-DSP-0011(0), CDD-DSP-0005(0)
                                                                            \n\n
    \Description MainFunction handling the ReadDataById diag service          \n
    \param[in]   u8IdContext      The message context ID                      \n
    \Range       0..DspInternal_u8MAX_NUM_INTERNAL_REQ                                \n
    \return      Void.                                                        \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_vidMainWdbi
  (Dcm_IdContextType u8IdContext)
{
  uint32                       u32DataRef;
  boolean                      bFixedLength;
  boolean                      bSendNegResp = FALSE;
  Dcm_NegativeResponseCodeType u8NegResCode = 0;

  u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
    pkstrDcmDspDidSignal[u8DSP_SIGNAL_INDEX].u32DcmDspDidDataRef;

  bFixedLength = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
    pkstrDcmDspDataInfoRef->bDcmDspDataFixedLength;
    
  /*! If the Sub Status is pending, then it continues writing the Did signals
      starting from last written signal and with OpStatus = PENDING */
  if(DspInternal_u8DSP_SUBSTATUS == u8WDBI_PENDING)
  {
    
    DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
    bSendNegResp = bWriteDidAllSignals (u8DSP_SIGNAL_INDEX, DCM_PENDING,
      bFixedLength, DCM_u16DSP_SIGNALS_TO_WRITE_IN_TASK, DspInternal_pu8DSP_MSGCONTEXT,
      &u8NegResCode);
  }
  /*! If the Sub Status is ReadNextData, then it continues writing the Did
      signals starting from recorded signal and with OpStatus = INITIAL */
  else if (DspInternal_u8DSP_SUBSTATUS == u8WDBI_WRITE_NEXT_DATA)
  {
    if (DspInternal_pu8DSP_MSGCONTEXT->msgAddInfo.cancelOperation == 1)
    {
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      DspInternal_u8DSP_STATUS = u8CANCEL;
    }
    else
    {
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      bSendNegResp = bWriteDidAllSignals (u8DSP_SIGNAL_INDEX, DCM_INITIAL,
        bFixedLength, DCM_u16DSP_SIGNALS_TO_WRITE_IN_TASK, DspInternal_pu8DSP_MSGCONTEXT,
        &u8NegResCode);
    }
  }
  else
  {
    /* Nothing */
  }

  if (DspInternal_u8DSP_STATUS == u8CANCEL)
  {
    DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
    DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
  }
  /*! If flag is raised, then send the NRC */
  else if(bSendNegResp == TRUE)
  {
    DsdInternal_SetNegResponse(DspInternal_pu8DSP_MSGCONTEXT,u8NegResCode);  
    DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
  }
  else
  {
    /*! Else, if writing the DID is finished correctly */
    if (DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
    {
      /*! Fill the response with the DID and call ProcessingDone */
      DspInternal_pu8DSP_MSGCONTEXT->resData[0] = DspInternal_pu8DSP_MSGCONTEXT->reqData[0];
      DspInternal_pu8DSP_MSGCONTEXT->resData[1] = DspInternal_pu8DSP_MSGCONTEXT->reqData[1];
      DspInternal_pu8DSP_MSGCONTEXT->resDataLen = 2;
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
    }
  }
}

#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1543(0), CDD-0098(0), CDD-DSP-0012(0), CDD-DSP-0015(0),
                 CDD-DSP-0006(0)                                            \n\n
    \Description MainFunction handling the IOControlById diag service         \n
    \param[in]   u8IdContext      The message context ID                      \n
    \Range       0..DspInternal_u8MAX_NUM_INTERNAL_REQ                                \n
    \return      Void.                                                        \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_vidMainIoctrl(
  Dcm_IdContextType u8IdContext)
{
  Dcm_NegativeResponseCodeType u8NegResCode = 0;
  boolean                      bSendNegResp = FALSE;
  boolean                      bLoopEnd = FALSE;
  uint16                       u16NumOfReadSignals = 0;
  boolean                      bReturnValue;
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                               pkstrDidAccess;

  /*! If cancellation bit is high and the DSP sub status is 
      Read Next signal or Did or IOCTRL */
  if ((DspInternal_pu8DSP_MSGCONTEXT->msgAddInfo.cancelOperation == 1) &&
      ((DspInternal_u8DSP_SUBSTATUS == u8RDBI_READ_NEXT_SIG)    ||
       (DspInternal_u8DSP_SUBSTATUS == u8RDBI_READ_NEXT_DID)       ||
       (DspInternal_u8DSP_SUBSTATUS == u8IOCTRL_CONT_NXT_DATA)))
  {
    /*! Set DSP substatus to IDLE */
    DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
    /*! Set DSP status to u8CANCEL */
    DspInternal_u8DSP_STATUS = u8CANCEL;
  }
  else
  {
    /*! If the Sub Status is pending, then it continues controling the Did signals
        starting from last controlled signal and with OpStatus = PENDING */
    if(DspInternal_u8DSP_SUBSTATUS == u8IOCTRL_PENDING)
    {
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      bSendNegResp = bIoControlDid (DCM_PENDING,
        DCM_u16DSP_SIGNALS_TO_CONTROL_IN_TASK, u8DSP_SIGNAL_INDEX, &u8NegResCode,
        DspInternal_pu8DSP_MSGCONTEXT);
    }
    /*! If the Sub Status is ControlNextData, then continues controlling the Did
        signals starting from recorded signal and with OpStatus = INITIAL */
    else if (DspInternal_u8DSP_SUBSTATUS == u8IOCTRL_CONT_NXT_DATA)
    {
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      bSendNegResp = bIoControlDid (DCM_INITIAL,
        DCM_u16DSP_SIGNALS_TO_CONTROL_IN_TASK, u8DSP_SIGNAL_INDEX, &u8NegResCode,
        DspInternal_pu8DSP_MSGCONTEXT);
    }
    else
    {
    }
  }
  
  if (DspInternal_u8DSP_STATUS == u8CANCEL)
  {
    /*! Do nothing */
  }
  /*! If the Sub Status is Idle, this means that it has just finished
      controlling all signals, then it continues checking condition of all
      signals and with OpStatus = INITIAL */
  else if (DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
  {
    if (bSendNegResp == FALSE)
    {
      bSendNegResp = TRUE;
      u8NegResCode = DCM_E_REQUESTOUTOFRANGE;

      pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
        pkstrDspDidInfoRef->strDcmDspDidAccess;

      /*! Check the following for the DID: */
      if (pkstrDidAccess->pkstrDcmDspDidRead != 
          (P2CONST(void,AUTOMATIC,AUTOMATIC))0)
      {
        /*!   Has read access in current session */
        bReturnValue = bCheckDidReadSession(u16DSP_DID_IDX[0]);
        if(bReturnValue == TRUE)
        {
          /*!   Has read access in current security level */
          bReturnValue = bCheckDidReadSecurity(u16DSP_DID_IDX[0]);
          if(bReturnValue == TRUE)
          {
            bSendNegResp = FALSE;
          }
          else
          {
            /*! If no read access in current security, then NRC
                "SECUTITYACCESSDENIED" */
            u8NegResCode = DCM_E_SECURITYACCESSDENIED;
          }
        }
      }
      /*! If DID is not supported or has no read access in current session,
          then NRC "REQUESTOUTOFRANGE" */
    }

    u16DSP_TX_BUFF_INDEX = u16IOCTRL_PR_CT_ST_IDX;
    u16DSP_NUM_DID = 1;

    /*! If everything is OK, then call the CheckDidConditions function to check
        the read conditions of every signal */
    if (bSendNegResp == FALSE)
    {
      bSendNegResp = bCheckDidConditions (0, 0, DCM_INITIAL, &u8NegResCode,
                                          &bLoopEnd, DspInternal_u8IOCTRL, u8IdContext);
      
      /*! If the Sub Status is Idle, this means that it has just finished
          checking condition all signals, then it continues reading of all
          signals and with OpStatus = INITIAL */
      if ((bSendNegResp == FALSE) && (DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
           && (bLoopEnd == FALSE))
      {
        bSendNegResp = bReadDidAllSignals (0, 0, DCM_INITIAL,
          DCM_u16DSP_SIGNALS_TO_READ_IN_TASK, DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
          &bLoopEnd, &u16NumOfReadSignals, DspInternal_u8IOCTRL);
      }
    }
  }
  /*! If the Sub Status is ConditionCheckPending, this means that it has stopped
      at condition check a signal, then it continues checking condition starting
      this signal and with OpStatus = PENDING */
  else if (DspInternal_u8DSP_SUBSTATUS == u8RDBI_COND_CHK_PEND)
  {
    DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
    bSendNegResp = bCheckDidConditions (0, u8DSP_SIGNAL_INDEX, DCM_PENDING,
      &u8NegResCode, &bLoopEnd, DspInternal_u8IOCTRL, u8IdContext);

    /*! If the Sub Status is Idle, this means that it has just finished
        checking condition all signals, then it continues reading of all
        signals and with OpStatus = INITIAL */
    if ((bSendNegResp == FALSE) && (DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
         && (bLoopEnd == FALSE))
    {
      bSendNegResp = bReadDidAllSignals (0, 0, DCM_INITIAL,
        DCM_u16DSP_SIGNALS_TO_READ_IN_TASK, DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
        &bLoopEnd, &u16NumOfReadSignals, DspInternal_u8IOCTRL);
    }
  }
  /*! If the Sub Status is ReadPending, this means that it has stopped
      at reading a signal, then it continues reading signals starting
      this signal and with OpStatus = PENDING */
  else if (DspInternal_u8DSP_SUBSTATUS == u8RDBI_READ_PENDING)
  {
    DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
    bSendNegResp = bReadDidAllSignals (0, u8DSP_SIGNAL_INDEX, DCM_PENDING,
      DCM_u16DSP_SIGNALS_TO_READ_IN_TASK, DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
      &bLoopEnd, &u16NumOfReadSignals, DspInternal_u8IOCTRL);
  }
  /*! If the Sub Status is ReadNextSignal, this means that it has stopped
      after reading a signal, then it continues reading signals starting
      the next signal and with OpStatus = INITIAL */
  else if (DspInternal_u8DSP_SUBSTATUS == u8RDBI_READ_NEXT_SIG)
  {
    DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
    bSendNegResp = bReadDidAllSignals (0, u8DSP_SIGNAL_INDEX, DCM_INITIAL,
      DCM_u16DSP_SIGNALS_TO_READ_IN_TASK, DspInternal_pu8DSP_MSGCONTEXT, &u8NegResCode,
      &bLoopEnd, &u16NumOfReadSignals, DspInternal_u8IOCTRL);
  }
  else
  {
    /* Do Nothing */
  }

  /*! If service is not cancelled */
  if (DspInternal_u8DSP_STATUS != u8CANCEL)
  {
    /*! If flag is raised, send the NRC */
    if(bSendNegResp == TRUE)
    {
      DsdInternal_SetNegResponse(DspInternal_pu8DSP_MSGCONTEXT,u8NegResCode);
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
    }
    else
    {
      /*! If flag is down and the sub status is IDLE, this means that all
          IOControl, ConditionCheck & Reading are finished. Thus, prepare the
          response message and send it. */
      if(DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
      {
        /* Filling PR with Did from request */
        DspInternal_pu8DSP_MSGCONTEXT->resData[0] = DspInternal_pu8DSP_MSGCONTEXT->reqData[0];
        DspInternal_pu8DSP_MSGCONTEXT->resData[1] = DspInternal_pu8DSP_MSGCONTEXT->reqData[1];
        /* Filling PR with IOControlParam from request */
        DspInternal_pu8DSP_MSGCONTEXT->resData[2] = DspInternal_pu8DSP_MSGCONTEXT->reqData[2];
        DspInternal_pu8DSP_MSGCONTEXT->resDataLen = u16DSP_TX_BUFF_INDEX;
        DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
        DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
      }
    }
  }
  else
  {
    /*! Service is cancelled, return status to idle */
    DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
    DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
  }
}
/* PRQA S 4700 --                                                             */
#endif



#if (DCM_bWDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-0092(0), CDD-1547(0), CDD-1044(0), CDD-1045(0), CDD-1523(0)
                 CDD-0096(0)                                                \n\n
    \Description Writes all the signals in a given DID                        \n
    \param[in]   u8SignalIndexStart  Signal index inside the DID to start with\n
    \Range       0..u8NumOfDidSignal-1                                        \n
    \param[in]   u8WriteCheckStatus  OpStatus to use in the first call to
                                     application interface                    \n
    \Range       DCM_INITIAL, DCM_PENDING                                     \n
    \param[in]   bFixedLength      Flag to indicate if the Did contains non-
                                   fixed length signal or fixed length signals\n
    \Range       FALSE, TRUE                                                  \n
    \param[in]   u16NumOfSignalsToWrite  Max number of signals to write per
                                         function call                        \n
    \Range       0..65535                                                     \n
    \param[out]  pstrMsgContext      Pointer to the message context           \n
    \Range       Null, Not Null                                               \n
    \param[out]  pu8NegResCode       NRC to be reported                       \n
    \Range       0..255                                                       \n
    \return      An NRC occured while writing or not.                         \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static FUNC(boolean,DCM_CODE) bWriteDidAllSignals (
         uint8 u8SignalIndexStart,
         Dcm_OpStatusType u8WriteCheckStatus,
         boolean bFixedLength,
         uint16 u16NumOfSignalsToWrite,
         P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pstrMsgContext,
         P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode)
{
  uint16                      u16NumOfWrittenSignals = 0;
  boolean                     bSendNegResp = FALSE;
  boolean                     bLoopEnd = FALSE;
  uint8                       u8SignalIndex;
  uint32                      u32DataRef;
  Std_ReturnType              u8WriteReturn;
  uint8                       u8ErrorCode = 0;
#if (DCM_bNVM_USED == STD_ON)
  NvM_BlockIdType             u8BlockId;
  NvM_RequestResultType       u8NvMReqResult;
#endif
  Dcm_IdContextType           u8IdContext;
  const uint16                LOC_ku16NonFixDataLen =
                               (uint16)(pstrMsgContext->reqDataLen - (uint32)2);

  u8IdContext = pstrMsgContext->idContext;

  /*! Loop on signals inside the DID */
  for (u8SignalIndex = u8SignalIndexStart;
       (u8SignalIndex < Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
         u8NumOfDidSignal)
         && (bLoopEnd == FALSE);
       u8SignalIndex++)
  {
    u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
      pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;

    /*! If this is the first time for this signal, then extract the signal value
        from the request message */
    if (u8WriteCheckStatus == DCM_INITIAL)
    {
      u16DSP_RX_BUFF_INDEX = 2;
      bSendNegResp = bExtractSignalFromDid (0, u8SignalIndex, u32DataRef,
        pstrMsgContext, pu8NegResCode, DspInternal_u8WDBI);
    }
    
    if (bSendNegResp == TRUE)
    {
      bLoopEnd = TRUE;
    }
    else
    {
      /*! If some app interface is pending and the cancel flag is raised */
      if ((u8WriteCheckStatus == DCM_PENDING)
            && (DspInternal_pu8DSP_MSGCONTEXT->msgAddInfo.cancelOperation == 1))
      {
        /*! To cancel the app interface */
        u8WriteCheckStatus = DCM_CANCEL;
      }

      /*! Based on the configured UsePort of the signal, and based on if
          the signal is fixed length or non-fixed length, call the proper
          write operation */
      switch (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].u8DcmDspDataUsePort)
      {
        case USE_DATA_SYNCH_CLIENT_SERVER:
        if(bFixedLength == TRUE)
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteFixedSync)(au8DSP_SIGNAL_BUFF,
            &u8ErrorCode);
        }
        else
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteNotFixedSync)(au8DSP_SIGNAL_BUFF,
            LOC_ku16NonFixDataLen, &u8ErrorCode);
        }
        break;
        
        case USE_DATA_ASYNCH_CLIENT_SERVER:
        if(bFixedLength == TRUE)
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteFixedAsync)(au8DSP_SIGNAL_BUFF,
            u8WriteCheckStatus, &u8ErrorCode);
        }
        else
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteNotFixedAsync)(au8DSP_SIGNAL_BUFF,
            LOC_ku16NonFixDataLen, u8WriteCheckStatus,
            &u8ErrorCode);
        }
        break;
        
        case USE_DATA_SENDER_RECEIVER:
        if(bFixedLength == TRUE)
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteFixedSr)(au8DSP_SIGNAL_BUFF);
        }
        else
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteNotFixedSr)
            (LOC_ku16NonFixDataLen, au8DSP_SIGNAL_BUFF);
        }
        /*! As the SR doesn't return an NRC code, use NRC
            GeneralProgrammingFailure in case of error. */
        if (u8WriteReturn != E_OK)
        {
          u8ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
        }
        break;
        
        /*! If UsePort = BlockId, then lock the NvM block then write into it
            using the NvM module APIs */
        #if (DCM_bNVM_USED == STD_ON)
          case USE_BLOCK_ID:
          u8BlockId = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                        udtDcmDspDataBlockIdRef;
          if (u8WriteCheckStatus == DCM_INITIAL)
          {
            NvM_SetBlockLockStatus (u8BlockId, TRUE);
            u8WriteReturn = NvM_WriteBlock (u8BlockId, au8DSP_SIGNAL_BUFF);
            if (u8WriteReturn == E_NOT_OK)
            {
              u8ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            }
            else /* E_OK */
            {
              /*! E_OK means the job is queued but not executed yet */
              u8WriteReturn = E_PENDING;
            }
          }
          else if (u8WriteCheckStatus == DCM_PENDING)
          /*! If this is the 2nd call to the function for the same signal,
              then poll on the NvM block status */
          {
            u8WriteReturn = NvM_GetErrorStatus (u8BlockId, &u8NvMReqResult);
            if (u8WriteReturn == E_NOT_OK)
            {
              u8ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            }
            else if (u8NvMReqResult == NVM_REQ_PENDING)
            {
              u8WriteReturn = E_PENDING;
            }
            else if (u8NvMReqResult == NVM_REQ_OK)
            {
              u8WriteReturn = E_OK;
            }
            else
            {
              u8WriteReturn = E_NOT_OK;
              u8ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            }
            /*! If the status is other thing than Pending, then unlock the NvM
                block Id */
            if (u8NvMReqResult != NVM_REQ_PENDING)
            {
              NvM_SetBlockLockStatus (u8BlockId, FALSE);
            }
          }
          else
          {
            /*! At cancellation, the current processed block can't
                be interrupted [NVM537] */
            /*! Just unlock the locked NvM block */
            NvM_SetBlockLockStatus (u8BlockId, FALSE);
          }
          break;
        #endif
        
        default: /* USE_FNC or others */
        if(bFixedLength == TRUE)
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteFixedFnc)(au8DSP_SIGNAL_BUFF,
            u8WriteCheckStatus, &u8ErrorCode);
        }
        else
        {
          u8WriteReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pfDcmDspDataWriteNotFixedFnc)(au8DSP_SIGNAL_BUFF,
            LOC_ku16NonFixDataLen, u8WriteCheckStatus,
            &u8ErrorCode);
        }
        break;
      }

      /*! To complete cancelling the service, call ProcessingDone
          and set status to idle & cancel */
      if (u8WriteCheckStatus == DCM_CANCEL)
      {
        bLoopEnd = TRUE;
        DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
        DspInternal_u8DSP_STATUS = u8CANCEL;
      }
      else if (u8WriteReturn == E_OK)
      {
        if (bFixedLength == TRUE)
        {
          u16NumOfWrittenSignals++;

          /*! If this is the last signal in the DID, then stop the loop */
          if (u8SignalIndex == (Dcm_kstreDspConfig.astrDcmDspDid
                [u16DSP_DID_IDX[0]].u8NumOfDidSignal - 1))
          {
            bLoopEnd = TRUE;
          }
          /*! If the limit of signals to write is reached, then stop to continue
              on another function call */
          else if ((u16NumOfSignalsToWrite != 0) 
                     && (u16NumOfWrittenSignals == u16NumOfSignalsToWrite))
          {
            bLoopEnd = TRUE;
            DspInternal_u8DSP_SUBSTATUS = u8WDBI_WRITE_NEXT_DATA;
            u8DSP_SIGNAL_INDEX = u8SignalIndex + 1;
            DspInternal_pu8DSP_MSGCONTEXT = pstrMsgContext;
            DspInternal_u8DSP_STATUS = DspInternal_u8WDBI;
          }
          else
          {
            /* Continue to next Signal */
          }
        }
        else
        {
          bLoopEnd = TRUE;
        }
      }
      /*! If the write operation is pending, then stop the loop and continue
          at next function call */
      else if(u8WriteReturn == E_PENDING)
      {
        DspInternal_u8DSP_SUBSTATUS = u8WDBI_PENDING;
        bLoopEnd = TRUE;
        u8DSP_SIGNAL_INDEX = u8SignalIndex;
        DspInternal_pu8DSP_MSGCONTEXT = pstrMsgContext;
        DspInternal_u8DSP_STATUS = DspInternal_u8WDBI;
      }
      else
      {
        bLoopEnd = TRUE;
        bSendNegResp = TRUE;
        *pu8NegResCode = u8ErrorCode;
      }

      u8WriteCheckStatus = DCM_INITIAL;
    }
  }

  return bSendNegResp;
}
/* PRQA S 4700 --                                                             */
#endif

#if ((DCM_bIO_CONTROL_EN == STD_ON) || (DCM_bWDBI_EN == STD_ON))
/******************************************************************************/
/*! \Trace_To    CDD-1064(0), CDD-1047(0)                                   \n\n
    \Description Extract a signal value from the message. Read signal length &
                 Apply endianess conversion.                                  \n
    \param[in]   u16DidArrayIndex  Index of Did inside the array              \n
    \Range       0..u16DSP_NUM_DID-1                                         \n
    \param[in]   u8SignalIndex     Index of Signal inside the DID             \n
    \Range       0..u8NumOfDidSignal-1                                        \n
    \param[in]   u32DataRef        Reference of this signal from configuration\n
    \Range                                                                    \n
    \param[in]   pstrMsgContext    Message context                            \n
    \Range       Null, not Null                                               \n
    \param[out]  pu8NegResCode     NRC to be reported                         \n
    \Range       0..255                                                       \n
    \return      An NRC occured while writing or not.                         \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
/* Deviation: the function has high cyclomatic complexity as it depends    \n
              on several parameters, and it will not be readable in case   \n
              we splitted into several functions                           \n  */
/* PRQA S 4700 ++ */
static FUNC(boolean,DCM_CODE) bExtractSignalFromDid (
    uint16 u16DidArrayIndex,
    uint8  u8SignalIndex,
    uint32 u32DataRef,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext,
    P2VAR(uint8,AUTOMATIC,AUTOMATIC) pu8NegResCode,
    uint8 u8ServiceStatus)
{
  uint16           u16DataPos;
  uint16           u16DataSize;
  uint8            u8ProtocolIndex;
  boolean          bEndianConv;
  uint8            u8DataType;
  uint16           u16TotalLength;
  boolean          bSendNegResp = FALSE;
  Std_ReturnType   u8DidFuncReturn;
  boolean          bSigned;
  uint8            u8IdContext;
  Dcm_PortUsedType u8PortUsed;

  u8IdContext = pkstrMsgContext->idContext;

  u16DataPos = Dcm_kstreDspConfig.
    astrDcmDspDid[u16DSP_DID_IDX[u16DidArrayIndex]].
    pkstrDcmDspDidSignal[u8SignalIndex].u16DcmDspDidDataPos;
    
  /*! If the signal is of fixed length, */
  if(Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
       pkstrDcmDspDataInfoRef->bDcmDspDataFixedLength == TRUE)
  {
    /*! Get the signal length from configuration. */
    u16DataSize  = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
      u16DcmDspDataSize;
  }
  else
  {
    /*! Else, use the configured function to get the signal length. */
    switch (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].u8DcmDspDataUsePort)
    {
      case USE_DATA_SYNCH_CLIENT_SERVER:
      u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataReadDataLengthSync)(&u16DataSize);
      break;

      case USE_DATA_ASYNCH_CLIENT_SERVER:
      u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataReadDataLengthAsync)(&u16DataSize);
      break;

      default: /* Fnc or others */
      u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataReadDataLengthFnc)(&u16DataSize);
      break;
    }

    if (u8DidFuncReturn == E_NOT_OK)
    {
      bSendNegResp = TRUE;
      *pu8NegResCode = DCM_E_CONDITIONSNOTCORRECT;
    }
  }

  if (bSendNegResp == FALSE)
  {
    u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
            pkstrDcmDslProtocolRx[pkstrMsgContext->dcmRxPduId].
            u8DcmDslProtocolIndex;
    u8PortUsed = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                 u8DcmDspDataUsePort;

    /*! Conversion only in case of sender/receiver interface used and 
        reading from IoHwAb */
    if ( ((u8PortUsed == USE_ECU_SIGNAL)
           && (u8ServiceStatus == DspInternal_u8IOCTRL))
      || ((u8PortUsed == USE_DATA_SENDER_RECEIVER)
           && (u8ServiceStatus == DspInternal_u8WDBI)) )
    {
      bEndianConv = Dcm_kstreDslConfig.astrDcmDslProtocolRow[u8ProtocolIndex].
        bDcmDslProtocolEndiannessConvEnabled;
    }
    else
    {
      bEndianConv = FALSE;
    }

    u8DataType = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
      u8DcmDspDataType;

    /*! Prepare the total length of the signal based on its configured type */
    if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
       pkstrDcmDspDataInfoRef->bDcmDspDataFixedLength == TRUE)
    {
      if ((u8DataType == BOOLEAN) || (u8DataType == UINT8)
            || (u8DataType == SINT8))
      {
        u16TotalLength = 8;
      }
      else if ((u8DataType == UINT16) || (u8DataType == SINT16))
      {
        u16TotalLength = 16;
      }
      else /* UINT32 or SINT32 */
      {
        u16TotalLength = 32;
      }

      if ((u8DataType == SINT8) || (u8DataType == SINT16)
           || (u8DataType == SINT32))
      {
        bSigned = TRUE;
      }
      else
      {
        bSigned = FALSE;
      }
    }
    else
    {
      u16TotalLength = 0;
      bSigned = FALSE;
    }

    /*! Call ExtractSignalFromBuff to extract and make the endianess conversion
        of the signal */
    DspInternal_vidExtractSignalFromBuff (
      &pkstrMsgContext->reqData[u16DSP_RX_BUFF_INDEX],
      au8DSP_SIGNAL_BUFF,
      (uint16)(u16DataPos/8),
      (uint8)(u16DataPos%8),
      u16DataSize, u16TotalLength, bEndianConv, bSigned);
  }

  return bSendNegResp;
}
/* PRQA S 4700 -- */
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static uint8 u8CallIoControlAppl(uint32 u32DataRef,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext,
    uint8 u8IOCTRLOpStatus)
{
  Std_ReturnType u8ControlReturn = E_NOT_OK;
  uint8          u8IdContext;

  u8IdContext = pkstrMsgContext->idContext;

  switch(Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
    u8DcmDspDataUsePort)
  {
  case USE_FNC:
    switch (u8IOCTRL_CONTROL_PARAM)
    {
    case u8IOCTRL_RET_CTRL_ECU:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataReturnControlToEcuFnc != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataReturnControlToEcuFnc)
          (u8IOCTRLOpStatus, pu8NegResCode);
      }
      break;

    case u8IOCTRL_RESET_DEFAULT:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataResetToDefaultFnc != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].pfDcmDspDataResetToDefaultFnc)
          (u8IOCTRLOpStatus, pu8NegResCode);
      }
      break;

    case u8IOCTRL_FREEZE_STATE:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataFreezeCurrentStateFnc != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataFreezeCurrentStateFnc)
          (u8IOCTRLOpStatus, pu8NegResCode);
      }
      break;

    default: /* u8IOCTRL_SHORT_ADJUST */
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataShortTermAdjustmentFnc != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataShortTermAdjustmentFnc)
          (au8DSP_SIGNAL_BUFF, u8IOCTRLOpStatus, pu8NegResCode);
      }
      break;
    }
    break;

  case USE_DATA_ASYNCH_CLIENT_SERVER:
    switch (u8IOCTRL_CONTROL_PARAM)
    {
    case u8IOCTRL_RET_CTRL_ECU:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataReturnControlToEcuAsync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataReturnControlToEcuAsync)(u8IOCTRLOpStatus,
          pu8NegResCode);
      }
      break;

    case u8IOCTRL_RESET_DEFAULT:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataResetToDefaultAsync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].pfDcmDspDataResetToDefaultAsync)
          (u8IOCTRLOpStatus,pu8NegResCode);
      }
      break;

    case u8IOCTRL_FREEZE_STATE:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataFreezeCurrentStateAsync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataFreezeCurrentStateAsync)(u8IOCTRLOpStatus,
          pu8NegResCode);
      }
      break;

    default: /* u8IOCTRL_SHORT_ADJUST */
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataShortTermAdjustmentAsync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataShortTermAdjustmentAsync)(au8DSP_SIGNAL_BUFF,
          u8IOCTRLOpStatus,pu8NegResCode);
      }
      break;
    }
    break;

  case USE_DATA_SYNCH_CLIENT_SERVER:
    switch (u8IOCTRL_CONTROL_PARAM)
    {
    case u8IOCTRL_RET_CTRL_ECU:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataReturnControlToEcuSync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataReturnControlToEcuSync)
          (pu8NegResCode);
      }
      break;

    case u8IOCTRL_RESET_DEFAULT:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataResetToDefaultSync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].pfDcmDspDataResetToDefaultSync)
          (pu8NegResCode);
      }
      break;

    case u8IOCTRL_FREEZE_STATE:
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataFreezeCurrentStateSync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataFreezeCurrentStateSync)
          (pu8NegResCode);
      }
      break;

    default: /* u8IOCTRL_SHORT_ADJUST */
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pfDcmDspDataShortTermAdjustmentSync != NULL_PTR)
      {
        u8ControlReturn = (*Dcm_kstreDspConfig.
          astrDcmDspData[u32DataRef].
          pfDcmDspDataShortTermAdjustmentSync)
          (au8DSP_SIGNAL_BUFF,pu8NegResCode);
      }
      break;
    }
    break;

  default:
    /* Invalid Use_Port */
    break;
  }

  return u8ControlReturn;

}
/* PRQA S 4700 --                                                             */


/******************************************************************************/
/*! \Trace_To    CDD-1055(0), CDD-1056(0), CDD-1057(0), CDD-1058(0), CDD-1059(0)
                 CDD-1060(0), CDD-1542(0), CDD-1547(0), CDD-0207(0), CDD-0208(0)
                 CDD-0209(0), CDD-0210(0), CDD-1526(0), CDD-1527(0), CDD-1528(0)
                 CDD-1529(0)                                                \n\n
    \Description IO control for all signals inside the DID                    \n
    \param[in]   u8IOCTRLOpStatus   OpStatus to use in the first call to
                                    application interface                     \n
    \Range       DCM_INITIAL, DCM_PENDING                                     \n
    \param[in]   u8NumOfSigToCtrl  Max number of signals to be IO
                                          controlled per function call        \n
    \Range       0..255                                                       \n
    \param[in]   u8SignalIndexStart  Signal index inside the DID to start with\n
    \Range       0..u8NumOfDidSignal-1                                        \n
    \param[out]  pu8NegResCode  The NRC that occured while controlling the
                                signal.                                       \n
    \Range       0..255                                                       \n
    \param[out]  pstrMsgContext    Message context                            \n
    \Range       Null, not Null                                               \n
    \return      An NRC occured while reading or not.                         \n
    \Range       TRUE, FALSE                                                  \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static FUNC(boolean,DCM_CODE) bIoControlDid (
    Dcm_OpStatusType u8IOCTRLOpStatus,
    uint8 u8NumOfSigToCtrl,
    uint8 u8SignalIndexStart,
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,AUTOMATIC) pu8NegResCode,
    P2CONST(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pkstrMsgContext)
{
  boolean                         bSendNegResp = FALSE;
  uint32                          u32DataRef;
  Std_ReturnType                  u8ControlReturn;
  uint8                           u8SignalIndex;
  boolean                         bLoopEnd = FALSE;
  uint8                           u8NumberOfDidSignal;
  boolean                         bSignalControlEnable;
  uint8                           u8NumOfCtrlSignals;
  P2VAR (uint8,AUTOMATIC,DCM_VAR) pu8ControlEnableMask;
  Dcm_IdContextType               u8IdContext;
  uint16                          u16DataPos;
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                                  pkstrDidAccess;

  u8IdContext = pkstrMsgContext->idContext;

  pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]]
                    .pkstrDspDidInfoRef->strDcmDspDidAccess;

  /*! Check the configured application function interfaces not to be Null
      pointers based on the IO Control Parameter in the message */
  switch (u8IOCTRL_CONTROL_PARAM)
  {
    case u8IOCTRL_RET_CTRL_ECU:

    if (pkstrDidAccess->pkstrDcmDspDidControl->bDcmDspDidReturnControlToEcu
                                                                       == FALSE)
    {  
      /*! Set Negative response code to DCM_E_REQUESTOUTOFRANGE*/
      *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;
      bSendNegResp = TRUE;
    }
    break;
    
    case u8IOCTRL_RESET_DEFAULT:
    if (pkstrDidAccess->pkstrDcmDspDidControl->bDcmDspDidResetToDefault ==FALSE)
    {
      /*! Set Negative response code to DCM_E_REQUESTOUTOFRANGE*/
      *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;
      bSendNegResp = TRUE;
    }
    break;

    case u8IOCTRL_FREEZE_STATE:
    if (pkstrDidAccess->pkstrDcmDspDidControl->bDcmDspDidFreezeCurrentState 
                                                                       == FALSE)
    { 
      /*! Set Negative response code to DCM_E_REQUESTOUTOFRANGE*/
      *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;
      bSendNegResp = TRUE;
    }
    break;

    case u8IOCTRL_SHORT_ADJUST:
    if (pkstrDidAccess->pkstrDcmDspDidControl->bDcmDspDidShortTermAdjustment 
                                                                       == FALSE)
    { 
      /*! Set Negative response code to DCM_E_REQUESTOUTOFRANGE*/
      *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;
      bSendNegResp = TRUE;
    }
    break;

    default:
    /* Nothing */
    break;
  }

  if (bSendNegResp == FALSE)
  {
    /*! If ControlMask exists in the message, Prepare a pointer to its value */
    u8NumberOfDidSignal = Dcm_kstreDspConfig.
           astrDcmDspDid[u16DSP_DID_IDX[0]].u8NumOfDidSignal;
    if (bDSP_IOCTRL_MASK == TRUE)
    {
      if (u8IOCTRL_CONTROL_PARAM == u8IOCTRL_SHORT_ADJUST)
      {
        u16DataPos = Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
          pkstrDcmDspDidSignal[u8NumberOfDidSignal-1].u16DcmDspDidDataPos;

        pu8ControlEnableMask = &pkstrMsgContext->
          reqData[3 + ((u16DataPos + u16DSP_DID_LST_DATA_LEN + 7)/8)];
      }
      else
      {
        pu8ControlEnableMask = &u8IOCTRL_CTRL_STATE;
      }
    }

    u8NumOfCtrlSignals = 0;

    /*! Loop on all signals inside the DID */
    for (u8SignalIndex = u8SignalIndexStart;
        (u8SignalIndex < u8NumberOfDidSignal) && (bLoopEnd == FALSE);
        u8SignalIndex++)
    {
      if (bDSP_IOCTRL_MASK == TRUE)
      {
        /* !Deviation : pu8ControlEnableMask is set before under the same 
                        condition above */
        /* PRQA S 3353 L1 */ 
        bSignalControlEnable = (pu8ControlEnableMask[u8NumberOfDidSignal/8]
          & u8MSB_MASK(u8SignalIndex%8)) > 0;
        /* PRQA L:L1                                                            */
      }
      else
      {
        bSignalControlEnable = TRUE;
      }

      /*! If mask bit is raised (or there is no mask) */
      if (bSignalControlEnable == TRUE)
      {
        u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
            pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;
           
        /*! If ControlParam is ShortAdjust, then extract the signal value from
            the Did value inside the message */
        if ((u8IOCTRLOpStatus == DCM_INITIAL) 
              && (u8IOCTRL_CONTROL_PARAM == u8IOCTRL_SHORT_ADJUST))
        {
          bSendNegResp = bExtractSignalFromDid (0, u8SignalIndex, u32DataRef, 
                                                pkstrMsgContext, pu8NegResCode,
                                                DspInternal_u8IOCTRL);
        }
        
        if (bSendNegResp == FALSE)
        {
          /*! If UsePort = EcuSignal, then use Application functions for
              EcuSignal */
          if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                u8DcmDspDataUsePort == USE_ECU_SIGNAL)
          {
            if (u8IOCTRL_CONTROL_PARAM == u8IOCTRL_SHORT_ADJUST)
            {
              (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                pfDcmDspDataEcuSignal)
                (u8IOCTRL_CONTROL_PARAM, au8DSP_SIGNAL_BUFF);
            }
            else
            {
              (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
                pfDcmDspDataEcuSignal)(u8IOCTRL_CONTROL_PARAM, NULL_PTR);
            }
            u8ControlReturn = E_OK;
          }
          else
          {
            /*! NRC 31 is reported if the application interface is a null
                pointer or the DataUsePort is configured invalid */
            
            *pu8NegResCode = DCM_E_REQUESTOUTOFRANGE;

            /*! If some app interface is pending and the cancel flag is raised */
            if ((u8IOCTRLOpStatus == DCM_PENDING)
                  && (DspInternal_pu8DSP_MSGCONTEXT->msgAddInfo.cancelOperation == 1))
            {
              /*! To cancel the app interface */
              u8IOCTRLOpStatus = DCM_CANCEL;
            }

            /*! Else, then based on the configured UsePort, and based on the
                control param, call the needed application interface */

            u8ControlReturn = 
              u8CallIoControlAppl(u32DataRef,pu8NegResCode,pkstrMsgContext,u8IOCTRLOpStatus);
        
          }

          /*! To complete cancelling the service, call ProcessingDone
              and set status to idle & cancel */
          if (u8IOCTRLOpStatus == DCM_CANCEL)
          {
            bLoopEnd = TRUE;
            DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
            DspInternal_u8DSP_STATUS = u8CANCEL;
          }
          /*! If OK, */
          else if (u8ControlReturn == E_OK)
          {
            /*! Check that the max limit of signals to control is not reached */
            u8NumOfCtrlSignals++;
            if ((u8NumOfSigToCtrl != 0)
                  && (u8NumOfCtrlSignals == u8NumOfSigToCtrl))
            {
              bLoopEnd = TRUE;
              DspInternal_u8DSP_SUBSTATUS = u8IOCTRL_CONT_NXT_DATA;
              u8DSP_SIGNAL_INDEX = u8SignalIndex + 1;
            }
          }
          /*! If result is pending, then stop and continue the loop next
              funcation call */
          else if (u8ControlReturn == E_PENDING)
          {
            DspInternal_u8DSP_SUBSTATUS = u8IOCTRL_PENDING;
            bLoopEnd = TRUE;
            u8DSP_SIGNAL_INDEX = u8SignalIndex;
          }
          else
          {
            bLoopEnd = TRUE;
            bSendNegResp = TRUE;
          }
        }
      }

      u8IOCTRLOpStatus = DCM_INITIAL;
    }
  }

  return bSendNegResp;
}
/* PRQA S 4700 --                                                             */
#endif


#if(DCM_bREAD_SCALING_DATA_EN == STD_ON)
/* Deviation: the function has high cyclomatic complexity only in case    \n */ 
/*            paged buffering in ON as the function will have more open   \n */ 
/*            conditions, while spliting them in different functions will \n */ 
/*            not make the function readable                              \n */ 
/* PRQA S 4700 ++ */ 
/******************************************************************************/
/*! \Trace_To     CDD-DSP-0074(0),CDD-DSP-0075(0),CDD-DSP-0078(0),            \n
                  CDD-DSP-0076(0),CDD-DSP-0077(0),CDD-DSP-0114(0),            \n
                  CDD-DSP-0139(0),CDD-DSP-0117(0)                             \n
    \Description  Main function for the ReadScalingDataById service           \n
    \param[in]    Context number                                              \n
    \Range        0..255                                                      \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_vidMainReadScaling(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  uint8                        u8SignalIndex;
  uint16                       u16DidIndex;
  Dcm_OpStatusType             u8LocalOpStatus = DspInternal_au8eSubStatus[u8Context];
  uint32                       u32ResLength;
  uint32                       u32DataRef;
  boolean                      bSendNegResp;
  Std_ReturnType               u8ReturnGetScaling;
  Dcm_NegativeResponseCodeType u8NegResCode;


  if(DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    if (DspInternal_abePagedMode[u8Context] != TRUE)
    #endif
    {
      DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    }
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
  }
  else
  {
    #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    if (  (  (DspInternal_abePagedMode[u8Context] == TRUE)
          && (DspInternal_abePageUpdate[u8Context] == TRUE))
       || (DspInternal_abePagedMode[u8Context] == FALSE))
    #endif
    {
      u32ResLength = DspInternal_apstreMsgContext[u8Context]->resDataLen;
      u16DidIndex = Dsp_au16DidIndices[u8Context][0];
      bSendNegResp = TRUE;
      u8ReturnGetScaling = E_OK;
      for (u8SignalIndex=Dsp_u8ScalingIndex;
           ((u8SignalIndex<Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
             u8NumOfDidSignal) && (u8ReturnGetScaling == E_OK));
           u8SignalIndex++)
      {
        u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DidIndex].
          pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;
        if (  (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
               u8DcmDspDataUsePort == USE_FNC)
           && (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
               pfDcmDspDataGetScalingInfo != NULL_PTR))
        {
          bSendNegResp = FALSE;
          u32ResLength += Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            pkstrDcmDspDataInfoRef->u32DcmDspDataScalingInfoSize;
          #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
          /*! if the buffer already filled to its maximum */ 
          if (u32ResLength > DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
          {
            /*! process page */ 
            DsdInternal_ProcessPage(u8Context,
              DspInternal_apstreMsgContext[u8Context]->resDataLen);
            /*! initialize next page */ 
            DspInternal_apstreMsgContext[u8Context]->resDataLen = 0;
            DspInternal_au8eSubStatus[u8Context] = DCM_INITIAL;
            /*! wait for next update page */ 
            DspInternal_abePageUpdate[u8Context] = FALSE;
            /*! resest signal index to read the same signal again next cycle */ 
            /* PRQA S 2469 ++ */ 
            u8SignalIndex--;
            /* PRQA S 2469 -- */ 
          }
          else
          #endif
          {
            u8ReturnGetScaling = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef]
              .pfDcmDspDataGetScalingInfo)(u8LocalOpStatus, 
              &DspInternal_apstreMsgContext[u8Context]->resData[u32ResLength],
              &u8NegResCode);
            DspInternal_apstreMsgContext[u8Context]->resDataLen = u32ResLength;
            u8LocalOpStatus = DCM_INITIAL;
          }
        }
      }
      Dsp_u8ScalingIndex = u8SignalIndex - 1;
      /*! in case the DID has no Data with scaling information               */ 
      if (bSendNegResp == TRUE)
      {
        /* PRQA S 3361 ++ */ 
        vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
        /* PRQA S 3361 -- */ 
      }
      else
      {
        if (u8ReturnGetScaling == E_OK)
        {
          #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
          if (DspInternal_abePagedMode[u8Context] == TRUE)
          {
            if (DspInternal_abePageUpdate[u8Context] == TRUE)
            {
              /*! process page */ 
              DsdInternal_ProcessPage(u8Context,
                DspInternal_apstreMsgContext[u8Context]->resDataLen);
              /*! re-initialize variables */ 
              DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
              DspInternal_au8eSubStatus[u8Context] = DCM_INITIAL;
              DspInternal_abePagedMode[u8Context] = TRUE;
              DspInternal_abePageUpdate[u8Context] = FALSE;
            }
          }
          else
          #endif
          {
            /*! Positive response                                            */ 
            /* PRQA S 3361 ++ */ 
            vidRESPOND_OK();
            /* PRQA S 3361 -- */ 
          }
        }
        else if (u8ReturnGetScaling == E_PENDING)
        {
          /*! Set state machine with Read Scaling state                      */ 
          DspInternal_au8eStatus[u8Context] = DspInternal_u8READ_SCALING_DATA;
          DspInternal_au8eSubStatus[u8Context] = DCM_PENDING;
        }
        else if (u8ReturnGetScaling == E_NOT_OK)
        {
          #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
          if (DspInternal_abePagedMode[u8Context] == TRUE)
          {
            /*! Report Det error                                             */ 
            #if (DCM_DEV_ERROR_DETECT == STD_ON)
            /*! Report to Det                                                */ 
            Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                              Dcm_u8UDS_READ_SCALING_ID,
                              DCM_E_INTERFACE_VALUE_OUT_OF_RANGE);
            #endif
            DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
          }
          else
          #endif
          {
            /*! Deviation: This branch will be entered unless                */ 
            /*             u8ReturnGetScaling = E_NOT_OK that will not happen*/ 
            /*             without setting u8NegResCode by                   */ 
            /*             pfDcmDspDataGetScalingInfo                        */ 
            /* PRQA S 3361,3353 ++ */ 
            vidRESPOND_NRC(u8NegResCode);
            /* PRQA S 3361,3353 -- */ 
          }
        }
        else
        {
          /*! Report Det error                                               */ 
          #if (DCM_DEV_ERROR_DETECT == STD_ON)
          /*! Report to Det                                                  */ 
          Det_ReportError (DCM_MODULE_ID, Dcm_u8INSTANCE_ID,
                            Dcm_u8UDS_READ_SCALING_ID,
                            DCM_E_INTERFACE_VALUE_OUT_OF_RANGE);
          #endif
          DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
        }
      }
    }
  }
}
/* PRQA S 4700 -- */ 
#endif

#if(DCM_bREAD_SCALING_DATA_EN == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-DSP-0112(0)                                           \n\n
    \Description  Get the full response length for ReadScalingDataById serv.  \n
*******************************************************************************/
static FUNC(uint32,DCM_CODE) u32ScalingGetFullLength(
  P2VAR(uint32,AUTOMATIC,AUTOMATIC) pu32MaximumData,
  uint8 u8IdContext)
{
  uint8        u8SignalIndex;
  const uint16 LOC_ku16Did = u16DSP_DID_IDX[0];
  uint32       u32ResLength = 0;
  uint32       u32DataRef;


  if (Dcm_kstreDspConfig.astrDcmDspDid[LOC_ku16Did].u8NumOfDidSignal > 0)
  {
    *pu32MaximumData = Dcm_kstreDspConfig.astrDcmDspData[0].
        pkstrDcmDspDataInfoRef->u32DcmDspDataScalingInfoSize + 2;
    for (u8SignalIndex=0;
         u8SignalIndex <
         Dcm_kstreDspConfig.astrDcmDspDid[LOC_ku16Did].u8NumOfDidSignal;
         u8SignalIndex++)
    {
      u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[LOC_ku16Did].
        pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;
      u32ResLength += Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pkstrDcmDspDataInfoRef->u32DcmDspDataScalingInfoSize;
      if (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].pkstrDcmDspDataInfoRef
          ->u32DcmDspDataScalingInfoSize > *pu32MaximumData)
      {
        *pu32MaximumData = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
        pkstrDcmDspDataInfoRef->u32DcmDspDataScalingInfoSize;
      }
    }
  }
  else
  {
    *pu32MaximumData = 0;
  }
  return u32ResLength;
}
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-DSP-0091(0),CDD-DSP-0092(0),CDD-DSP-0093(0),            \n
                  CDD-DSP-0094(0),CDD-DSP-0140(0)                             \n
    \Description  Main function for the ReadDataByPeriodicIdentifier service  \n
    \param[in]    Context number                                              \n
    \Range        0..255                                                      \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_vidMainPeriodicIdentifiers(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  uint8   u8Index;
  boolean bReturnValue;


  /*! increment all counters                                                 */ 
  Dsp_strPeriodicData.u16CounterSlow++;
  Dsp_strPeriodicData.u16CounterMedium++;
  Dsp_strPeriodicData.u16CounterFast++;
  /*! IF slow counter is elapsed                                             */ 
  if (Dsp_strPeriodicData.u16CounterSlow == DCM_u16PERIODIC_SLOW_RATE)
  {
    /*! reload slow counter                                                  */ 
    Dsp_strPeriodicData.u16CounterSlow = 0;
    /*! set call-flag for each DID with slow                                 */ 
    for (u8Index=0; u8Index<DCM_u8MAX_NUM_PERIODIC_TX; u8Index++)
    {
      if (Dsp_strPeriodicData.strScheduler[u8Index].u8Mode ==
          u8PERIODIC_MODE_SLOW)
      {
        Dsp_strPeriodicData.strScheduler[u8Index].bCall = TRUE;
      }
    }
  }
  /*! IF medium counter is elapsed                                           */ 
  if (Dsp_strPeriodicData.u16CounterMedium == DCM_u16PERIODIC_MEDIUM_RATE)
  {
    /*! reload medium counter                                                */ 
    Dsp_strPeriodicData.u16CounterMedium = 0;
    /*! set call-flag for each DID with medium                               */ 
    for (u8Index=0; u8Index<DCM_u8MAX_NUM_PERIODIC_TX; u8Index++)
    {
      if (Dsp_strPeriodicData.strScheduler[u8Index].u8Mode ==
          u8PERIODIC_MODE_MEDIUM)
      {
        Dsp_strPeriodicData.strScheduler[u8Index].bCall = TRUE;
      }
    }
  }
  /*! IF fast counter is elapsed                                             */ 
  if (Dsp_strPeriodicData.u16CounterFast == DCM_u16PERIODIC_FAST_RATE)
  {
    /*! reload fast counter                                                  */ 
    Dsp_strPeriodicData.u16CounterFast = 0;
    /*! set call-flag for each DID with fast                                 */ 
    for (u8Index=0; u8Index<DCM_u8MAX_NUM_PERIODIC_TX; u8Index++)
    {
      if (Dsp_strPeriodicData.strScheduler[u8Index].u8Mode ==
          u8PERIODIC_MODE_FAST)
      {
        Dsp_strPeriodicData.strScheduler[u8Index].bCall = TRUE;
      }
    }
  }
  /*! Call DslInternal_ResponseOnOneDataByPeriodicId for all DIDs with       */ 
  /*! call-flag is set, then clear the flag for DIDs returning DCM_E_OK      */ 
  for (u8Index=0; u8Index<DCM_u8MAX_NUM_PERIODIC_TX; u8Index++)
  {
    if (Dsp_strPeriodicData.strScheduler[u8Index].bCall == TRUE)
    {
      bReturnValue = DslInternal_ResponseOnOneDataByPeriodicId(
        Dsp_strPeriodicData.strScheduler[u8Index].u8DID);
      if (bReturnValue == DCM_E_OK)
      {
        Dsp_strPeriodicData.strScheduler[u8Index].bCall = FALSE;
        #if (DCM_u32PERIODIC_MAX_RESPONSES > 0)
        Dsp_strPeriodicData.strScheduler[u8Index].u32Responses++;
        if (Dsp_strPeriodicData.strScheduler[u8Index].u32Responses >=
            DCM_u32PERIODIC_MAX_RESPONSES)
        {
          Dsp_strPeriodicData.strScheduler[u8Index].u8Mode = 
            u8PERIODIC_MODE_IDLE;
        }
        #endif
      }
    }
  }
}
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To                                                                 \n
    \Description  Init function for the ReadDataByPeriodicIdentifier service  \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_vidInitPeriodicIdentifiers(void)
{
  uint8 u8Index;


  for(u8Index=0; u8Index<DCM_u8MAX_NUM_PERIODIC_TX; u8Index++)
  {
    Dsp_strPeriodicData.strScheduler[u8Index].u8DID = 0;
    Dsp_strPeriodicData.strScheduler[u8Index].u8Mode = u8PERIODIC_MODE_IDLE;
    Dsp_strPeriodicData.strScheduler[u8Index].bCall = FALSE;
    #if (DCM_u32PERIODIC_MAX_RESPONSES > 0)
    Dsp_strPeriodicData.strScheduler[u8Index].u32Responses = 0;
    #endif
  }
  Dsp_strPeriodicData.u16CounterSlow = 0;
  Dsp_strPeriodicData.u16CounterMedium = 0;
  Dsp_strPeriodicData.u16CounterFast = 0;
}
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-DSP-0095(0)                                             \n
    \Description  Check if there are enough slots for the required periodic   \n
                  Identifiers                                                 \n
    \param[in]    Array of requested periodic DIDs                            \n
    \param[in]    Number of requested DIDs                                    \n
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bEnoughSlotsInScheduler(
  P2VAR(uint8,AUTOMATIC,AUTOMATIC) au8DidList,
  VAR(uint8,AUTOMATIC)             u8DidCount)
{
  boolean bDidExist;
  uint8   u8Index;
  uint8   u8DidIndex;
  uint8   u8NonExistingCount = 0;
  uint8   u8EmptySlotsCount = 0;


  /*! Count number of requested DIDs that are not already existing in the    */ 
  /*! scheduler                                                              */ 
  for (u8DidIndex=0; u8DidIndex<u8DidCount; u8DidIndex++)
  {
    bDidExist = FALSE;
    for (u8Index=0; 
         ((u8Index<DCM_u8MAX_NUM_PERIODIC_TX) && (bDidExist == FALSE));
         u8Index++)
    {
      if (Dsp_strPeriodicData.strScheduler[u8Index].u8DID ==
          au8DidList[u8DidIndex])
      {
        bDidExist = TRUE;
      }
    }
    if (bDidExist == FALSE)
    {
      u8NonExistingCount++;
    }
  }
  /*! Count the number of empty slots in the scheduler                       */ 
  for (u8Index=0; u8Index<DCM_u8MAX_NUM_PERIODIC_TX; u8Index++)
  {
    if (  (Dsp_strPeriodicData.strScheduler[u8Index].u8Mode<1)
       || (Dsp_strPeriodicData.strScheduler[u8Index].u8Mode>4))
    {
      u8EmptySlotsCount++;
    }
  }
  /*! IF the not existing DIDs are more than the empty slots                 */ 
  if (u8NonExistingCount > u8EmptySlotsCount)
  {
    /*! RETURN FALSE                                                         */ 
    bReturnValue = FALSE;
  }
  /*! ELSE: RETURN TRUE                                                      */ 
  else
  {
    bReturnValue = TRUE;
  }
  return bReturnValue;
}
#endif

#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-DSP-0087(0),CDD-DSP-0088(0),CDD-DSP-0089(0),            \n
                  CDD-DSP-0096(0)                                             \n
    \Description  Add a periodic DID to the periodic scheduler                \n
    \param[in]    The low byte of the requested DID (0xF2XX)                  \n
    \param[in]    The trasmissionMode requested for the periodic DID          \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidUpdateScheduler(
  VAR(uint8,AUTOMATIC) u8Did,
  VAR(uint8,AUTOMATIC) u8TxMode)
{
  uint8   u8Index;
  boolean bDidExist = FALSE;
  uint8   u8DidIndex;


  /*! LOOP on all slots in the scheduler                                     */ 
  for (u8Index=0; 
       ((u8Index<DCM_u8MAX_NUM_PERIODIC_TX) && (bDidExist == FALSE));
       u8Index++)
  {
    /*! IF the requested DID is found                                        */ 
    if (Dsp_strPeriodicData.strScheduler[u8Index].u8DID == u8Did)
    {
      bDidExist = TRUE;
      /*! update DID mode in the scheduler                                   */ 
      Dsp_strPeriodicData.strScheduler[u8Index].u8Mode = u8TxMode;
      if (u8TxMode == u8PERIODIC_MODE_STOP)
      {
        Dsp_strPeriodicData.strScheduler[u8Index].bCall = TRUE;
      }
      else
      {
        #if (DCM_u32PERIODIC_MAX_RESPONSES > 0)
        Dsp_strPeriodicData.strScheduler[u8Index].u32Responses = 0;
        #endif
      }
    }
    /*! ELSE IF the slot is empty                                            */ 
    else
    {
      if (  (Dsp_strPeriodicData.strScheduler[u8Index].u8Mode<1)
         || (Dsp_strPeriodicData.strScheduler[u8Index].u8Mode>3))
      {
        /*! keep the slot number                                             */ 
        u8DidIndex = u8Index;
      }
    }
  }
  /*! IF DID in not existing in the scheduler                                */ 
  if ((bDidExist == FALSE) && (u8TxMode != u8PERIODIC_MODE_STOP))
  {
    /*! insert DID to the scheduler                                          */ 
    Dsp_strPeriodicData.strScheduler[u8DidIndex].u8DID = u8Did;
    Dsp_strPeriodicData.strScheduler[u8DidIndex].u8Mode = u8TxMode;
    Dsp_strPeriodicData.strScheduler[u8DidIndex].bCall = FALSE;
    #if (DCM_u32PERIODIC_MAX_RESPONSES > 0)
    Dsp_strPeriodicData.strScheduler[u8DidIndex].u32Responses = 0;
    #endif
  }
}
#endif


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/


#if (DCM_bRDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-0021(0), CDD-0023(0), CDD-1013(0), CDD-3022(0), CDD-1995(0)
                 CDD-2050(0), CDD-DSP-0016(0)                               \n\n
    \Description UDS Service ReadDataByIdentifier.                            \n
    \param[in]   pMsgContext  Message Context containing the request, the
                              response and other message related info.        \n
    \Range       NULL_PTR, not NULL_PTR                                       \n
    \return      void.                                                        \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void, DCM_CODE) DspInternal_ReadDataByIdentifier(
  P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  Dcm_NegativeResponseCodeType u8NegResCode = 0;
  boolean                      bLoopEnd = FALSE;
  uint16                       u16NumOfReadSignals;
  uint16                       u16DidArrayIndex;
  uint8                        u8DidType;
  boolean                      bSendNegResp = FALSE;
  Dcm_IdContextType            u8IdContext;

  u8IdContext = pMsgContext->idContext;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! Check that the DSP is not busy doing other services (In DET Only). */
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_001();
  /* PRQA S 3141 --                                                         */
  /* PRQA S 3138 --                                                         */

  if (DspInternal_u8DSP_STATUS == DspInternal_u8IDLE)
  {
    DspInternal_u8DSP_STATUS = DspInternal_u8BLOCKED;
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_001();
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
#endif

    /*! If the request contains even number of bytes (as each DID is
        2 bytes long), */
    if (((pMsgContext->reqDataLen % 2) == 0) && ((pMsgContext->reqDataLen != 0)))
    {
      /*! Check the number of DIDs in request, if larger than the configured max
          limit, then NRC "INCORRECTMESSAGELENGTHORINVALIDFORMAT" is to be sent
          (except if the limit = 0). */
      u16DSP_NUM_DID = (uint16)(pMsgContext->reqDataLen / 2) ;
      
      #if (DCM_u16DSP_MAX_DID_TO_READ != 0U)
      if (u16DSP_NUM_DID > (uint16)DCM_u16DSP_MAX_DID_TO_READ)
      {
        bSendNegResp = TRUE;
        u8NegResCode = DCM_E_REQUESTOUTOFRANGE;
      }
      #endif
    }
    else
    {
      /*! Else, the request message doesn't contain even number of bytes,
          thus NRC is to be sent of "INCORRECTMESSAGELENGTHORINVALIDFORMAT" */
      bSendNegResp = TRUE;
      u8NegResCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }

    /*! If ok, then check the Did regarding session, securty, support. */
    if(bSendNegResp == FALSE)
    {
      bSendNegResp = bFullCheckDid(pMsgContext, &u8NegResCode);
    }

    if(bSendNegResp == FALSE)
    {
      u16DSP_TX_BUFF_INDEX = 0;
      u16NumOfReadSignals = 0;
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      DspInternal_pu8DSP_MSGCONTEXT = pMsgContext;
      
      /*! If ok, then begin looping on the supported & valid DIDs */
      for (u16DidArrayIndex = 0;
           ((u16DidArrayIndex < u16DSP_NUM_DID)
           && (bLoopEnd == FALSE));
           u16DidArrayIndex++)

      {
        u8DidType = au8DSP_DID_TYPES[u16DidArrayIndex];

        /*! If outside the OBD range, then CheckDidCondition and Read based on
            UDS protocol */
        if (u8DidType == u8DID_UDS)
        {
          bSendNegResp = bCheckDidConditions (u16DidArrayIndex, 0, DCM_INITIAL,
                           &u8NegResCode, &bLoopEnd, DspInternal_u8RDBI, u8IdContext);
          if ((bSendNegResp == FALSE) && (bLoopEnd == FALSE))
          {
            bSendNegResp = bReadDidAllSignals (u16DidArrayIndex, 0, DCM_INITIAL,
                                               DCM_u16DSP_SIGNALS_TO_READ_SYNC,
                                               pMsgContext, &u8NegResCode,
                                               &bLoopEnd, &u16NumOfReadSignals,
                                               DspInternal_u8RDBI);
          }
        }
        else
        {
          /*! OBD range, not implemented */
          /*! So NRC RequestOutOfRange */
          bSendNegResp = TRUE;
          bLoopEnd = TRUE;
          u8NegResCode = DCM_E_REQUESTOUTOFRANGE;
        }
      }
    }

    if (DspInternal_u8DSP_STATUS == u8CANCEL)
    {
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
    }
    /*! If any error happens, then report NRC */
    else if(bSendNegResp == TRUE)
    {
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_SetNegResponse(pMsgContext,u8NegResCode);  
      DsdInternal_ProcessingDone(pMsgContext);
    }
    /*! If SubStatus is Idle, then this means that everything has finished
        correctly, So prepare the response message */
    else if (DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
    {
      /*! Set the response length in the message context */
      pMsgContext->resDataLen = u16DSP_TX_BUFF_INDEX;
      /*! Call processing done of the DSD */
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(pMsgContext);
    }
    else
    {
      /* Nothing */
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
  else
  {
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_001();
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
  }
#endif
}
/* PRQA S 4700 --                                                             */
#endif

#if (DCM_bWDBI_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1037(0), CDD-0091(0), CDD-0093(0), CDD-1038(0), CDD-1039(0)
                 CDD-1040(0), CDD-1041(0), CDD-1042(0), CDD-1043(0), CDD-1046(0)
                 CDD-DSP-0017(0), CDD-DSP-0011(0)                           \n\n
    \Description UDS Service WriteDataByIdentifier.                           \n
    \param[in]   pMsgContext  Message Context containing the request, the
                              response and other message related info.        \n
    \Range       NULL_PTR, not NULL_PTR                                       \n
    \return      void.                                                        \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void, DCM_CODE) DspInternal_WriteDataByIdentifier (
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  boolean                                               bFixedLength = TRUE;
  uint32                                                u32DataRef;
  uint8                                                 u8SignalIndex;
  boolean                                               bLoopEnd = FALSE;
  uint16                                                u16TotalDataLength;
  uint16                                                u16Did;
  Dcm_NegativeResponseCodeType                          u8NegResCode;
  boolean                                               bSendNegResp;
  boolean                                               bReturn;
  Dcm_IdContextType                                     u8IdContext;
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST) pkstrDidAccess;

  u8IdContext= pMsgContext->idContext;

                                                                    
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! Check that the DSP is not busy doing other services */
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_001();
  /* PRQA S 3141 --                                                         */
  /* PRQA S 3138 --                                                         */
  if (DspInternal_u8DSP_STATUS == DspInternal_u8IDLE)
  {
    DspInternal_u8DSP_STATUS = DspInternal_u8BLOCKED;
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_001();
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
#endif

  /*! Check Did is supported or not. */
    u16Did = (uint16)((((uint32)pMsgContext->reqData[0])<<8) +
               (uint32)pMsgContext->reqData[1]);
    bSendNegResp = TRUE;
    u8NegResCode = DCM_E_REQUESTOUTOFRANGE;

    /*! Check if the Did is inside the UDS range1 */
    if ((u16Did >= u16UDS_DID_RANGE1_MIN) && (u16Did <= u16UDS_DID_RANGE1_MAX))
    {
      bReturn = bCheckDidSupported (u16Did, &u16DSP_DID_IDX[0]);
      if ((bReturn == TRUE) && (Dcm_kstreDspConfig.
             astrDcmDspDid[u16DSP_DID_IDX[0]].u8NumOfDidSignal != 0))
      {
        pkstrDidAccess = &Dcm_kstreDspConfig.
          astrDcmDspDid[u16DSP_DID_IDX[0]].
          pkstrDspDidInfoRef->strDcmDspDidAccess;

        if(pkstrDidAccess->pkstrDcmDspDidWrite != 
          (P2CONST(Dcm_DspDidWriteType, TYPEDEF, DCM_APPL_CONST))NULL_PTR)
        {
          /*! Check Did can be written under current session & security */
          bReturn = bCheckDidWriteSession(u16DSP_DID_IDX[0]);
          if(bReturn == TRUE)
          {
            bReturn = bCheckDidWriteSec(u16DSP_DID_IDX[0]);
            if(bReturn == TRUE)
            {
              bSendNegResp = FALSE;
            }
            else
            {
              u8NegResCode = DCM_E_SECURITYACCESSDENIED;
            }
          }
        }
      }
    }
    else if ((u16Did >= u16DYN_DID_RANGE_MIN) 
              && (u16Did <= u16DYN_DID_RANGE_MAX))
    {
      /*! No DID is configured as Dynamic */
    }
    else
    {
      /*! Invalid DID */
    }

    /*! Check Did signals lengths and compare to the request message length. */
    if(bSendNegResp == FALSE)
    {
      bFixedLength = TRUE;
      
      for (u8SignalIndex = 0;
           ((u8SignalIndex < Dcm_kstreDspConfig.
             astrDcmDspDid[u16DSP_DID_IDX[0]].u8NumOfDidSignal)
             && (bLoopEnd == FALSE));
           u8SignalIndex++)
      {
        u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
            pkstrDcmDspDidSignal[u8SignalIndex].u32DcmDspDidDataRef;

        if((Dcm_kstreDspConfig.
            astrDcmDspData[u32DataRef].pkstrDcmDspDataInfoRef->
            bDcmDspDataFixedLength == FALSE))
        {
          bFixedLength = FALSE;
          /*! If there is a non-fixed length signal, then the DID should consist
              only of this signal, otherwise NRC 0x31 */
          if(Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
               u8NumOfDidSignal != 1)
          {
            bLoopEnd = TRUE;
            bSendNegResp = TRUE;
            u8NegResCode = DCM_E_REQUESTOUTOFRANGE;
          }
        }
      }

      /*! Calculate the total length from last signal in the loop */
      if (bFixedLength == TRUE)
      {
        /* Deviation: Variable is always set before used          */
        /* PRQA S 3353 ++ */
        u16TotalDataLength = Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          u16DcmDspDataSize + Dcm_kstreDspConfig.astrDcmDspDid
          [u16DSP_DID_IDX[0]].pkstrDcmDspDidSignal[u8SignalIndex-1].
          u16DcmDspDidDataPos;
        /* PRQA S 3353 -- */
      }

      /*! If message length is incorrect, then NRC */
      /* Deviation: Variable is always set before used */
      /* PRQA S 3353 ++ */
      if (((bFixedLength == TRUE) && (((u16TotalDataLength+7)/8) != 
            (pMsgContext->reqDataLen-2)))
             || ((bFixedLength == FALSE) && (pMsgContext->reqDataLen < 3)))
      /* PRQA S 3353 -- */
      {
        bSendNegResp = TRUE;
        u8NegResCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
    }

    /*! Write Did signals. */
    if(bSendNegResp == FALSE)
    {
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      u16DSP_RX_BUFF_INDEX = 2;
      bSendNegResp = bWriteDidAllSignals (0, DCM_INITIAL, bFixedLength,
                                          DCM_u16DSP_SIGNALS_TO_WRITE_SYNC,
                                          pMsgContext, &u8NegResCode);
    }

    if (DspInternal_u8DSP_STATUS == u8CANCEL)
    {
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
    }
    /*! If error occurs, then report NRC */
    else if(bSendNegResp == TRUE)
    {
      DsdInternal_SetNegResponse(pMsgContext,u8NegResCode);
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(pMsgContext);
    }
    else
    {
      /*! If writing all signals is finished */
      if((DspInternal_u8DSP_SUBSTATUS != u8WDBI_PENDING) 
           && (DspInternal_u8DSP_SUBSTATUS != u8WDBI_WRITE_NEXT_DATA))
      {
        pMsgContext->resData[0] = pMsgContext->reqData[0];
        pMsgContext->resData[1] = pMsgContext->reqData[1];
        pMsgContext->resDataLen = 2;
        DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
        DsdInternal_ProcessingDone(pMsgContext);
      }
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
  else
  {
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_001();
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
  }
#endif
}
/* PRQA S 4700 --                                                             */
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1048(0), CDD-1049(0), CDD-1050(0), CDD-1051(0), CDD-1052(0)
                 CDD-1053(0), CDD-1054(0), CDD-1543(0), CDD-0097(0), CDD-0098(0)
                 CDD-0099(0), CDD-0100(0), CDD-0101(0), CDD-0102(0), CDD-0207(0)
                 CDD-0208(0), CDD-0209(0), CDD-0210(0), CDD-DSP-0017(0)
                 CDD-DSP-0012(0), CDD-DSP-0018(0)                           \n\n
    \Description UDS Service InputOutputControlByIdentifier.                  \n
    \param[in]   pMsgContext  Message Context containing the request, the
                              response and other message related info.        \n
    \Range       NULL_PTR, not NULL_PTR                                       \n
    \return      void.                                                        \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void, DCM_CODE) DspInternal_InputOutputControlByIdentifier (
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  /*! Define local variables: */

  /*! - A data identifier */
  uint16                       u16Did;
  /*! - Number of signals inside a Did */
  uint8                        u8NumberOfDidSignal;
  /*! - Flag indicating sending NRC or not */
  boolean                      bSendNegResp = FALSE;
  /*! - An NRC */
  Dcm_NegativeResponseCodeType u8NegResCode = 0;
  /*! - Flag indicating end of loop */
  boolean                      bLoopEnd = FALSE;
  /*! - Counter of read signals in the service */
  uint16                       u16NumOfReadSignals = 0;
  /*! - Context Id of current message protocol */
  Dcm_IdContextType            u8IdContext;
  /*! - Pointer to Access structure of a Did */
  P2CONST(Dcm_DspDidAccessType,AUTOMATIC,DCM_CFG_CONST)
                               pkstrDidAccess;
  /*! - Value returned from functions configured for the Did */
  Std_ReturnType               u8DidFuncReturn;
  /*! - Position of signal inside a DID */
  uint16                       u16DataPos;
  /*! - Reference to configuration of signals */
  uint32                       u32DataRef;
  boolean                      bReturn;

  u8IdContext = pMsgContext->idContext;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  /*! If DET_ON, Check that the DSP is not busy doing other services */
  /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
  /*              during integration phase                                  */
  /* PRQA S 3141 ++                                                         */
  /* PRQA S 3138 ++                                                         */
  SchM_Enter_Dcm_Access_001();
  /* PRQA S 3141 --                                                         */
  /* PRQA S 3138 --                                                         */
  if (DspInternal_u8DSP_STATUS == DspInternal_u8IDLE)
  {
    /*! If idle, then lock the state to prohibit further calling to diag
        services or the periodic function. */
    DspInternal_u8DSP_STATUS = DspInternal_u8BLOCKED;
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_001();
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
#endif

    /*! Check that the request message length is 3 bytes minimum. */
    /*! Check that the inputOutputControlParameter has a valid value. */
    if (pMsgContext->reqDataLen < 3)
    {
      /*! If less than 3 bytes, then NRC "INCORRECTMESSAGELENGTHORINVALIDFORMAT"*/
      bSendNegResp = TRUE;
      u8NegResCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else if (u8IOCTRL_CTRL_PARAM_AR > u8IOCTRL_SHORT_ADJUST)
    {
      /*! If invalid param value, then NRC "REQUESTOUTOFRANGE" */
      bSendNegResp = TRUE;
      u8NegResCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
      /*! Else Do Nothing */
    }

    /*! If checks passed OK */
    if (bSendNegResp == FALSE)
    {
      u16Did = u16IOCTRL_DATA_ID;
      bSendNegResp = TRUE;
      u8NegResCode = DCM_E_REQUESTOUTOFRANGE;

      /*! Check Did is supported or not. */
      /*! If supported, get the index of Did inside the configuration */
      bReturn = bCheckDidSupported (u16Did, &u16DSP_DID_IDX[0]);
      if(bReturn == TRUE)
      {
        pkstrDidAccess = &Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
          pkstrDspDidInfoRef->strDcmDspDidAccess;

        /*! Check that this Did has control access */
        if(pkstrDidAccess->pkstrDcmDspDidControl != 
          (P2CONST(Dcm_DspDidControlType, TYPEDEF, DCM_APPL_CONST))NULL_PTR)
        {
          /*! Check that this Did has control access under current session */
          bReturn = bCheckDidCtrlSess(u16DSP_DID_IDX[0]);
          if(bReturn == TRUE)
          {
            /*! Check that this Did has control access under current security */
            bReturn = bCheckDidCtrlSec(u16DSP_DID_IDX[0]);
            if(bReturn == TRUE)
            {
              /*! If all checks passed, then no NRC */
              bSendNegResp = FALSE;
            }
            else
            {
              /*! If security check failed, then NRC SECUTITYACCESSDENIED */
              u8NegResCode = DCM_E_SECURITYACCESSDENIED;
            }
          }
        }
      }
      /*! If Did is not supported or no access under current session, then NRC
      REQUESTOUTOFRANGE */
    }

    /*! If all are OK, */
    if (bSendNegResp == FALSE)
    {
      u8NumberOfDidSignal = Dcm_kstreDspConfig.
        astrDcmDspDid[u16DSP_DID_IDX[0]].u8NumOfDidSignal;

      /*! Check the request message format: */
      /*! In case of ShortTermAdjustment, the request length should be either 3
      (ControlParam + Did) + number of signals inside the Did,
      or a ControlEnableMask field can exist where each bit corresponds to
      a signal. */
      if (u8IOCTRL_CTRL_PARAM_AR == u8IOCTRL_SHORT_ADJUST)
      {
        u16DataPos = Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
          pkstrDcmDspDidSignal[u8NumberOfDidSignal-1].u16DcmDspDidDataPos;
        u32DataRef = Dcm_kstreDspConfig.astrDcmDspDid[u16DSP_DID_IDX[0]].
          pkstrDcmDspDidSignal[u8NumberOfDidSignal-1].u32DcmDspDidDataRef;

        /*! If the signal is of fixed length, */
        if(Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
          pkstrDcmDspDataInfoRef->bDcmDspDataFixedLength == TRUE)
        {
          /*! Get the signal length from configuration. */
          u16DSP_DID_LST_DATA_LEN = Dcm_kstreDspConfig.
            astrDcmDspData[u32DataRef].u16DcmDspDataSize;
        }
        else
        {
          /*! Else, use the configured function to get the signal length. */
          switch (Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
            u8DcmDspDataUsePort)
          {
          case USE_DATA_SYNCH_CLIENT_SERVER:
            u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              pfDcmDspDataReadDataLengthSync)(&u16DSP_DID_LST_DATA_LEN);
            break;

          case USE_DATA_ASYNCH_CLIENT_SERVER:
            u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              pfDcmDspDataReadDataLengthAsync)(&u16DSP_DID_LST_DATA_LEN);
            break;

          default: /* Fnc or others */
            u8DidFuncReturn = (*Dcm_kstreDspConfig.astrDcmDspData[u32DataRef].
              pfDcmDspDataReadDataLengthFnc)(&u16DSP_DID_LST_DATA_LEN);
            break;
          }

          if (u8DidFuncReturn == E_NOT_OK)
          {
            bSendNegResp = TRUE;
            u8NegResCode = DCM_E_CONDITIONSNOTCORRECT;
          }
        }

        if (bSendNegResp == FALSE)
        {
          if (pMsgContext->reqDataLen == 
            (3 + ((u16DataPos + u16DSP_DID_LST_DATA_LEN + 7)/8)))
          {
            bDSP_IOCTRL_MASK = FALSE;
          }
          else if (((pMsgContext->reqDataLen) ==
            (3 + ((u16DataPos + u16DSP_DID_LST_DATA_LEN + 7)/8)
            + ((u8NumberOfDidSignal + 7)/8))) && (u8NumberOfDidSignal > 1))
          {
            bDSP_IOCTRL_MASK = TRUE;
          }
          else
          {
            /*! Otherwise, NRC INCORRECTMESSAGELENGTHORINVALIDFORMAT */
            bSendNegResp = TRUE;
            u8NegResCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
          }
        }
      }
      else
      {
        /*! In case of other ControlParam, the request length should be either 3
        (ControlParam + Did), or a ControlEnableMask field can exist where
        each bit corresponds to a signal */
        if (pMsgContext->reqDataLen == 3)
        {
          bDSP_IOCTRL_MASK = FALSE;
        }
        else if ((pMsgContext->reqDataLen == ((3 + ((u8NumberOfDidSignal+7)/8))))
          && (u8NumberOfDidSignal > 1))
        {
          bDSP_IOCTRL_MASK = TRUE;
        }
        else
        {
          /*! Otherwise, NRC INCORRECTMESSAGELENGTHORINVALIDFORMAT */
          bSendNegResp = TRUE;
          u8NegResCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
      }
    }

    /*! If all are OK, */
    if (bSendNegResp == FALSE)
    {
      /*! Set the sub status as Idle and call the IOControl function to start
      controlling signals inside the DID starting from 1st signal, with
      DCM_INITIAL OpStatus and stopping looping after exceeding the max
      configured number of signals synchrously */
      DspInternal_u8DSP_SUBSTATUS = DspInternal_u8IDLE;
      u16DSP_RX_BUFF_INDEX = u16IOCTRL_PR_CT_ST_IDX;
      bSendNegResp = bIoControlDid(DCM_INITIAL,
        DCM_u16DSP_SIGNALS_TO_CONTROL_SYNC, 0, &u8NegResCode, pMsgContext);
    }

    /*! If SubStatus is Idle and all checks/operations are OK, */
    if ((DspInternal_u8DSP_STATUS != u8CANCEL) && (DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE))
    {
      if (bSendNegResp == FALSE)
      {
        bSendNegResp = TRUE;
        u8NegResCode = DCM_E_REQUESTOUTOFRANGE;

        /*! Check the following for the DID: */
        /*! /Deviation The pointer will be initialized in all sequences        */ 
        /* PRQA S 3353 ++ */ 
        if (pkstrDidAccess->pkstrDcmDspDidRead != 
          (P2CONST(Dcm_DspDidReadType, TYPEDEF, DCM_APPL_CONST))NULL_PTR)
          /* PRQA S 3353 -- */ 
        {
          /*!   Has read access in current session */
          bReturn = bCheckDidReadSession(u16DSP_DID_IDX[0]);
          if(bReturn == TRUE)
          {
            /*!   Has read access in current security level */
            bReturn = bCheckDidReadSecurity(u16DSP_DID_IDX[0]);
            if(bReturn == TRUE)
            {
              bSendNegResp = FALSE;
            }
            else
            {
              /*! If no read access in current security, then NRC
              "SECUTITYACCESSDENIED" */
              u8NegResCode = DCM_E_SECURITYACCESSDENIED;
            }
          }
        }
        /*! If DID is not supported or has no read access in current session,
        then NRC "REQUESTOUTOFRANGE" */
      }

      u16DSP_TX_BUFF_INDEX = u16IOCTRL_PR_CT_ST_IDX;
      u16DSP_NUM_DID = 1;
      DspInternal_pu8DSP_MSGCONTEXT = pMsgContext;

      /*! If everything is OK, then call the CheckDidConditions function to check
      the read conditions of every signal */
      if (bSendNegResp == FALSE)
      {
        bSendNegResp = bCheckDidConditions (0, 0, DCM_INITIAL,
          &u8NegResCode, &bLoopEnd, DspInternal_u8IOCTRL,u8IdContext);
        /*! If ok, then call the read operation/function starting from 1st signal
        and not exceeding the configured Sync limit */
        if ((bSendNegResp == FALSE) && (bLoopEnd == FALSE))
        {
          bSendNegResp = bReadDidAllSignals (0, 0, DCM_INITIAL,
            DCM_u16DSP_SIGNALS_TO_READ_SYNC,
            pMsgContext, &u8NegResCode,
            &bLoopEnd, &u16NumOfReadSignals,
            DspInternal_u8IOCTRL);
        }
      }
    }

    if (DspInternal_u8DSP_STATUS == u8CANCEL)
    {
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(DspInternal_pu8DSP_MSGCONTEXT);
    }
    /*! At end, if any check/operation is not OK */
    else if(bSendNegResp == TRUE)
    {
      /*! Send the detected NRC and return the status to Idle */
      DsdInternal_SetNegResponse(pMsgContext,u8NegResCode);  
      DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
      DsdInternal_ProcessingDone(pMsgContext);
    }
    else
    {
      /*! Else, if no pending operation, */
      if(DspInternal_u8DSP_SUBSTATUS == DspInternal_u8IDLE)
      {
        /*! Filling PR with Did from request */
        pMsgContext->resData[0] = pMsgContext->reqData[0];
        pMsgContext->resData[1] = pMsgContext->reqData[1];
        /*! Filling PR with IOControlParam from request */
        pMsgContext->resData[2] = pMsgContext->reqData[2];
        /*! Setting the response message length to correspond to the last filled
        byte in the PR */
        pMsgContext->resDataLen = u16DSP_TX_BUFF_INDEX;
        /*! Set status to Idle and call ProcessingDone */
        DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
        DsdInternal_ProcessingDone(pMsgContext);
      }
      else
      {
        /*! If still there are pending operations, save the context and set
        status to IoCtrl */
        DspInternal_u8DSP_STATUS = DspInternal_u8IOCTRL;
        DspInternal_pu8DSP_MSGCONTEXT = pMsgContext;
      }
    }

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
  else
  {
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Exit_Dcm_Access_001();
    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
  }
#endif
}

/* PRQA S 4700 --                                                             */
#endif

#if(DCM_bREAD_SCALING_DATA_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS ReadScalingDataByIdentifier (24) service. \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0030(0),CDD-0031(0),CDD-0032(0),CDD-0034(0),CDD-0036(0),
                CDD-DSP-0080(0),CDD-DSP-0113(0),CDD-DSP-0117(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_ReadScalingDataByIdentifier(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pstrMsgContext)
{
  Dcm_NegativeResponseCodeType u8NegResCode = 0;
  uint8                        u8Context;
  boolean                      bSendNegResp;
  uint32                       u32ResLength;
  uint32                       u32MaximumData;


  /*! Save message context                                                   */ 
  u8Context = pstrMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pstrMsgContext;
  DspInternal_au8eStatus[u8Context] = DspInternal_u8BLOCKED;
  DspInternal_au8eSubStatus[u8Context] = DspInternal_u8IDLE;
  if (pstrMsgContext->reqDataLen != 2)
  {
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
  else
  {
    /*! check the Did regarding session, securty, support.                   */ 
    bSendNegResp = bFullCheckDid(pstrMsgContext, &u8NegResCode);
    if (bSendNegResp == TRUE)
    {
      /* PRQA S 3361 ++ */ 
      vidRESPOND_NRC(u8NegResCode);
      /* PRQA S 3361 -- */ 
    }
    else
    {
      Dsp_u8ScalingIndex = 0;
      /*! check if the total length will fit in the buffer or not */ 
      u32ResLength = u32ScalingGetFullLength(&u32MaximumData, u8Context);
      if (u32ResLength > DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
      {
        #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
        if (u32MaximumData <= DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
        {
          DspInternal_abePagedMode[u8Context] = TRUE;
          DspInternal_abePageUpdate[u8Context] = FALSE;
          DspInternal_apstreMsgContext[u8Context]->resDataLen = 2 + u32ResLength;
          DsdInternal_StartPagedProcessing(DspInternal_apstreMsgContext[u8Context]);
          DspInternal_apstreMsgContext[u8Context]->resDataLen = 2;
          DspInternal_au8eSubStatus[u8Context] = DCM_INITIAL;
        }
        else
        #endif
        {
          /* PRQA S 3361 ++ */ 
          vidRESPOND_NRC(DCM_E_RESPONSETOOLONG);
          /* PRQA S 3361 -- */ 
        }
      }
      else
      {
        DspInternal_au8eSubStatus[u8Context] = DCM_INITIAL;
        DspInternal_apstreMsgContext[u8Context]->resDataLen = 2;
        DspInternal_vidMainReadScaling(u8Context);
      }
    }
  }
}
#endif


#if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS ReadDataByPeriodicIdentifier (2A) service. \n
    \param[in]   pstrMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To :  CDD-0058(0),CDD-0060(0),CDD-0063(0),CDD-0065(0),CDD-0067(0),
                 CDD-0068(0),CDD-DSP-0081(0),CDD-DSP-0082(0),CDD-DSP-0090(0),
                 CDD-DSP-0095(0),CDD-DSP-0097(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_ReadDataByPeriodicIdentifier(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pstrMsgContext)
{
  boolean bReturnValue;
  boolean bSessionOK;
  uint8   u8Context;
  uint8   u8Index;
  uint8   au8DidList[DCM_u8MAX_NUM_PERIODIC_TX];
  uint8   u8DidCount;
  uint16  u16Did;
  uint16  u16DidIndex;


  u8Context = pstrMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pstrMsgContext;
  /*! IF request length is greater than or equal 2                           */ 
  if (pstrMsgContext->reqDataLen != 2)
  {
    /*! IF transmissionMode is supported (1->4)                              */ 
    /*! AND number of requested DIDs are less than maximum                   */ 
    if(  ((pstrMsgContext->reqData[0]>=1) && (pstrMsgContext->reqData[0]<=4))
      && (pstrMsgContext->reqDataLen <= (DCM_u8MAX_NUM_PERIODIC_TX+1)))
    {
      /*! set [SessionNOK] and [SecurityNOK]                                 */ 
      bSessionOK = FALSE;
      u8DidCount = 0;
      /*! LOOP on requested DIDs                                             */ 
      for (u8Index=pstrMsgContext->reqDataLen-1; u8Index>0; u8Index--)
      {
        u16Did = 0xF200 + pstrMsgContext->reqData[u8Index];
        /*! IF DID is supported                                              */ 
        bReturnValue = bCheckDidSupported(u16Did,&u16DidIndex);
        if (bReturnValue == TRUE)
        {
          /*! IF session is OK                                               */ 
          bReturnValue = bCheckDidReadSession(u16DidIndex);
          if (bReturnValue == TRUE)
          {
            /*! set [SessionOK]                                              */ 
            bSessionOK = TRUE;
            /*! IF security is OK                                            */ 
            bReturnValue = bCheckDidReadSecurity(u16DidIndex);
            if (bReturnValue == TRUE)
            {
              /*! set [SecurityOK]                                           */ 
              /*! add to DID list to be inserted into the schedular          */ 
              au8DidList[u8DidCount] = pstrMsgContext->reqData[u8Index];
              u8DidCount++;
            }
          }
        }
      }
      /*! END LOOP                                                           */ 
      /*! IF [SessionOK]                                                     */ 
      if (bSessionOK == TURE)
      {
        /*! IF [SecurityOK]                                                  */ 
        if (u8DidCount > 0)
        {
          bReturnValue = bEnoughSlotsInScheduler(au8DidList, u8DidCount);
          /*! IF there are no enough slots in the schedular                  */ 
          if (bReturnValue != TRUE)
          {
            /*! NRC31                                                        */ 
            /* PRQA S 3361 ++ */ 
            vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
            /* PRQA S 3361 -- */ 
          }
          /*! ELSE                                                           */ 
          else
          {
            /*! LOOP on the DIDs list                                        */ 
            for(u8Index=0; u8Index<u8DidCount; u8Index++)
            {
              vidUpdateScheduler(au8DidList[u8Index],
                pstrMsgContext->reqData[0]);
            }
            /*! END LOOP                                                     */ 
            /*! +ve Response                                                 */ 
            pstrMsgContext->resDataLen = 0;
            /* PRQA S 3361 ++ */ 
            vidRESPOND_OK();
            /* PRQA S 3361 -- */ 
          }
        }
        /*! ELSE [SessionNOK]                                                */ 
        else
        {
          /*! NRC33                                                          */ 
          /* PRQA S 3361 ++ */ 
          vidRESPOND_NRC(DCM_E_SECURITYACCESSDENIED);
          /* PRQA S 3361 -- */ 
        }
      }
      /*! ELSE [SessionNOK]                                                  */ 
      else
      {
        /*! NRC31                                                            */ 
        /* PRQA S 3361 ++ */ 
        vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
        /* PRQA S 3361 -- */ 
      }
    }
    /*! ELSE (transmissionMode is not supported OR too much DIDs)            */ 
    else
    {
      /*! NRC31                                                              */ 
      /* PRQA S 3361 ++ */ 
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */ 
    }
  }
  /*! ELSEIF request length equals 1 AND transmissionMode equals stopSending */ 
  else if (  (pstrMsgContext->reqDataLen == 1)
          && (pstrMsgContext->reqData[0] == u8PERIODIC_MODE_STOP))
  {
    /*! Stop all DIDs                                                        */ 
    for(u8Index=0; u8Index<DCM_u8MAX_NUM_PERIODIC_TX; u8Index++)
    {
      Dsp_strPeriodicData.strScheduler[u8Index].u8Mode = u8PERIODIC_MODE_STOP;
      Dsp_strPeriodicData.strScheduler[u8Index].bCall = TRUE;
    }
    /*! +ve Response                                                         */ 
    pstrMsgContext->resDataLen = 0;
    /* PRQA S 3361 ++ */ 
    vidRESPOND_OK();
    /* PRQA S 3361 -- */ 
  }
  /*! ELSE (request length is not correct)                                   */ 
  else
  {
    /*! NRC13                                                                */ 
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
}
#endif

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 


/** \} */ /* end of DSP module group */
/** \} */ /* end of DSP Component group */
/*-------------------------------- end of file -------------------------------*/

/* !Deviation : Inhibit MISRA rule [0862]: This is the way MemMap is used     */
/* PRQA S 0862 L1 */

/* PRQA L:L1 */
