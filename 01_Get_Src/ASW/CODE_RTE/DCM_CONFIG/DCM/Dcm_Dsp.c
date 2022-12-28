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
/* !File            : Dcm_Dsp.c                                               */
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
/* $Revision::   1.127.1.3$$Author::   manwar         $$Date::   24 Oct 2011 $*/
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
#include "Dem.h"
#include "Rte_Dcm.h"
#include "SchM_Dcm.h"
#include "BswM_Dcm.h"


#if (DCM_bNVM_USED == STD_ON)
#include "Nvm.h"
#endif

#if (DCM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON || DCM_bRMBA_EN == STD_ON || \
    DCM_bWMBA_EN == STD_ON || DCM_bREQUEST_DOWNLOAD_EN == STD_ON || \
    DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
#include "Dcm_Callouts.h"
#endif
/* PRQA L:L1                                                                  */

#if(DCM_bINTER_MOD_VER_CHECK == STD_ON)
/******************************************************************************/
/* Intermodule Version Checking                                              */
/******************************************************************************/
#if (DCM_bNVM_USED == STD_ON)
/* Check versus NVM */
#ifdef NVM_AR_RELEASE_MAJOR_VERSION
#ifdef NVM_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (NVM_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "NVM AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (NVM_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "NVM AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "NVM AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "NVM AR RELEASE MAJOR VERSION not defined"
#endif
#endif
#endif /* #if(DCM_bINTER_MOD_VER_CHECK == STD_ON) */

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* State machine values of DspInternal_u8DSP_STATUS & DspInternal_u8DSP_SUBSTATUS */

/*! \Description  ReadDTCInformation sub-functions                        /n */ 
#define u8SUB_FUNCTION        0U

/*! \Description  RoutineControl service ID                               /n */ 
#define u8ROUTINE_CONTROL     (uint8)0x31U
/*! \Description  RoutineControl/subfunction (startRoutine)               /n */ 
#define u8RC_START_ROUTINE    (uint8)0x01U
/*! \Description  RoutineControl/subfunction (stopRoutine)                /n */ 
#define u8RC_STOP_ROUTINE     (uint8)0x02U
/*! \Description  RoutineControl/subfunction (requestRoutineResult)       /n */ 
#define u8RC_REQ_ROUT_RES     (uint8)0x03U
/*! \Description  RoutineControl/routineControlOptionRecord index         /n */ 
#define u8RC_OPTION_REC_IND   3


#define u8MAIN_RMBA   (uint8)0x23
#define u8MAIN_WMBA  (uint8)0x3D


/*! \Description  Security Access Sub-Status : Compare Key Pending       /n */ 
#define u8SA_COMPARE_PENDING   (uint8)0x00
/*! \Description  Security Access Sub-Status : Get Seed Pending       /n */ 
#define u8SA_GET_SEED_PENDING  (uint8)0x01
/*! \Description  Clear Diagnostic Information Pending Status       /n */
#define u8MAIN_CDI_PEND          (uint8)0x14
/*! \Description  Security Access Pending Status       /n */
#define u8MAIN_SA_PEND           (uint8)0x27
/*! \Description  Transfer Data Pending Status       /n */
#define u8MAIN_TRANS_DATA_PEND   (uint8)0x36

/*! \Description Ecu Reset Pending Status       /n */
#define u8MAIN_ECU_RESET_PEND    (uint8)0x11

/*! \Description DiagnosticSessionControl Pending Status       /n */
#define u8MAIN_SESS_PEND         (uint8)0x10

/*! \Description Substate machine states for DiagnosticSessionControl /n */
#define u8SUB_SESS_NORM            (uint8)1
#define u8SUB_SESS_BOOT            (uint8)2
#define u8SUB_SESS_BOOT_PEND       (uint8)3

/*! \Description Substate machine states for SecurityAccess /n */
#define u8SUB_SA_COMPARE_PEND      (uint8)1
#define u8SUB_SA_GET_SEED_PEND     (uint8)2



/*! \Description  Substate machine states for RoutineControl              /n */ 
#define u8RC_IDLE             (uint8)0x00
#define u8RC_START_PENDING    (uint8)0x01
#define u8RC_START_CPENDING   (uint8)0x02
#define u8RC_START_RCRRP      (uint8)0x03
#define u8RC_START_RCRRP_OK   (uint8)0x04
#define u8RC_STOP_PENDING     (uint8)0x05
#define u8RC_STOP_CPENDING    (uint8)0x06
#define u8RC_STOP_RCRRP       (uint8)0x07
#define u8RC_STOP_RCRRP_OK    (uint8)0x08
#define u8RC_RESULT_PENDING   (uint8)0x09
#define u8RC_RESULT_CPENDING  (uint8)0x0A
#define u8RC_RESULT_RCRRP     (uint8)0x0B
#define u8RC_RESULT_RCRRP_OK  (uint8)0x0C


/******************************************************************************/
/*! \Description communicationType: Normal Communication Messages.  \n
  \Range         1 \n
*******************************************************************************/
#define u8CC_NCM       (uint8)1

/******************************************************************************/
/*! \Description communicationType: Network Management Communication Messages.\n
  \Range         2 \n
*******************************************************************************/
#define u8CC_NWMCM     (uint8)2

/******************************************************************************/
/*! \Description communicationType: Network Management Communication Messages
 *               and Normal Communication Messages.  \n
  \Range         3 \n
*******************************************************************************/
#define u8CC_NWMCMANCM (uint8)3

/******************************************************************************/
/*! \Description Request Length of CommunicationControl service.[without SID]
  \Range         2 \n
*******************************************************************************/
#define u8CC_REQ_LEN (uint8)2

/******************************************************************************/
/*! \Description Response Length of CommunicationControl service.[without RSID]
  \Range         1 \n
*******************************************************************************/
#define u8CC_RES_LEN (uint8)1

/******************************************************************************/
/*! \Description CommunicationControl SubFunction : enableRxAndTx.
  \Range         0 \n
*******************************************************************************/
#define u8CC_SUBFUNC_ERXTX  (uint8)0

/******************************************************************************/
/*! \Description CommunicationControl SubFunction : enableRxAndDisableTx.
  \Range         1 \n
*******************************************************************************/
#define u8CC_SUBFUNC_ERXDTX (uint8)1

/******************************************************************************/
/*! \Description CommunicationControl SubFunction : disableRxAndEnableTx.
  \Range         2 \n
*******************************************************************************/
#define u8CC_SUBFUNC_DRXETX (uint8)2

/******************************************************************************/
/*! \Description CommunicationControl SubFunction : disableRxAnddisableTx.
  \Range         3 \n
*******************************************************************************/
#define u8CC_SUBFUNC_DRXTX  (uint8)3

#define u8NEG_CODE_RCRP (uint8)(0x78)



#if(DCM_bECU_RESET_EN == STD_ON)
/******************************************************************************/
/*!   \Description Request Length for EcuReset UDS service \n
*******************************************************************************/
#define u8ER_REQ_LEN       (uint8)1

/******************************************************************************/
/*!   \Description Response Length for EcuReset UDS service with
 *                 enableRapidPowerShutDown sub-function. \n
*******************************************************************************/
#define u8ER_ERPSD_RES_LEN (uint8)2

/******************************************************************************/
/*!   \Description Response Length for EcuReset UDS service \n
*******************************************************************************/
#define u8ER_RES_LEN       (uint8)1

#endif

#if(DCM_bSES_CONTROL_EN == STD_ON)
/******************************************************************************/
/*!   \Description Response Length for DiagnosticSessionControl UDS service \n
*******************************************************************************/
#define u8DSC_RES_LEN     (uint8)5

/******************************************************************************/
/*!   \Description Request Length for DiagnosticSessionControl UDS service \n
*******************************************************************************/
#define u8DSC_REQ_LEN      (uint8)1

/******************************************************************************/
/*!   \Description DiagnosticSessionControl UDS service service Id\n
*******************************************************************************/
#define u8DSC_SID          (uint8)0x10

#endif

#if(DCM_bCDTCS_EN == STD_ON)
/******************************************************************************/
/*!   \Description Request Length for ControlDTCSetting UDS service \n
*******************************************************************************/
#define u8CDTCS_REQ_LEN    (uint8)1

/******************************************************************************/
/*!   \Description Response Length for ControlDTCSetting UDS service \n
*******************************************************************************/
#define u8CDTCS_RES_LEN    (uint8)1

/******************************************************************************/
/*!   \Description ControlDTCSetting UDS service  On sub-function\n
*******************************************************************************/
#define u8CDTCS_SUBFUNC_ON  (uint8)(0x01)

/******************************************************************************/
/*!   \Description ControlDTCSetting UDS service  Off sub-function\n
*******************************************************************************/
#define u8CDTCS_SUBFUNC_OFF (uint8)(0x02)

#endif

#if(DCM_bTESTER_PRESENT_EN == STD_ON)
/******************************************************************************/
/*!   \Description Request Length for TesterPresent UDS service \n
*******************************************************************************/
#define u8TP_REQ_LEN      (uint8)1

/******************************************************************************/
/*!   \Description Response Length for TesterPresent UDS service \n
*******************************************************************************/
#define u8TP_RES_LEN      (uint8)1

/******************************************************************************/
/*!   \Description TesterPresent Zero Subfunction UDS service \n
*******************************************************************************/
#define u8TP_SUBFUNC_ZERO (uint8)0

#endif

#if(DCM_bLINK_CONTROL_EN == STD_ON)
/******************************************************************************/
/*!   \Description Request LinkControl Service ID \n
*******************************************************************************/
#define u8LC_SID          (uint8)(0x87)

#endif


#if(DCM_bCDTCI_EN == STD_ON)
/******************************************************************************/
/*!   \Description Request Length for ClearDiagnosticInformation UDS service \n
*******************************************************************************/
#define u8CDTCI_REQ_LEN          (uint8)3

/******************************************************************************/
/*!   \Description Response Length for ClearDiagnosticInformation UDS service \n
*******************************************************************************/
#define u8CDTCI_RES_LEN          (uint8)0

#endif


#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)
/******************************************************************************/
/*!   \Description Used by transferData service : This return code
                   shall be sent ifthe download module length does not meet
                   the requirements of the memorySize parameter sent in the
                   request message of the requestDownload service. \n
*******************************************************************************/
#define u8NR_TD_SUSPENDED      (uint8)0x71


/******************************************************************************/
/*!   \Description Used by TransferData service : This return code shall be sent
 *                 if the server detects an error in the sequence of the
                   blockSequenceCounter.  \n
*******************************************************************************/
#define u8NR_WRONG_BS_COUNT (uint8)0x73

#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)
/******************************************************************************/
/*!   \Description requiredTimeDelayNotExpired  negative response error code. \n
*******************************************************************************/
#define u8NR_DELAY_NOT_EXP       (uint8)0x37


/******************************************************************************/
/*! \Description SecurityAccess Service ID. \n
  \Range         0x27 \n
*******************************************************************************/
#define u8SEC_ACCESS_SID (uint8)0x27


/******************************************************************************/
/*!   \Description exceededNumberOfAttempts negative response error code. \n *
*******************************************************************************/
#define u8NR_EXC_NUM_OF_ATT          (uint8)0x36

/******************************************************************************/
/*!   \Description invalidKey negative response  error code which is sent
   if an expected "sendKey" sub-function value is received and the value of the
    key does not match the server's internally stored/calculated key.  \n

*******************************************************************************/
#define u8NR_INVALID_KEY                  (uint8)0x35

#endif


#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)
/******************************************************************************/
/*!   \Description Minimum request Length for TransferData UDS service \n
*******************************************************************************/
#define u8TD_MIN_REQ_LEN (uint8)2

/******************************************************************************/
/*!   \Description Response Length for TransferData UDS service \n
*******************************************************************************/
#define u8TD_REQ_DOWN_RES_LEN     (uint8)1

/******************************************************************************/
/*!   \Description Response Length for TransferData UDS service \n
*******************************************************************************/
#define u8TD_RES_LEN     (uint8)1

/******************************************************************************/
/*!   \Description Minimum request Length for RequestDownload UDS service \n
*******************************************************************************/
#define u8RD_MIN_REQ_LEN (uint8)4

/******************************************************************************/
/*!   \Description Response Length for RequestDownload UDS service \n
*******************************************************************************/
#define u8RD_RES_LEN     (uint8)5

/******************************************************************************/
/*!   \Description Request Length for RequestTransferExit UDS service \n
*******************************************************************************/
#define u8RTE_REQ_LEN   (uint8)0

/******************************************************************************/
/*!   \Description Response Length for RequestTransferExit UDS service \n
*******************************************************************************/
#define u8RTE_RES_LEN   (uint8)0

/******************************************************************************/
/*!   \Description Maximum Memory address supported.[uint32] \n
*******************************************************************************/
#define u32MAX_MEM_ADDRESS         4294967295UL


/******************************************************************************/
/*!   \Description Value of parameter lengthFormatIdentifier in the positive
 *                 response of requestDownload service, where the high nibble
 *                 indicates the number of bytes of maxNumberOfBlockLength. \n
*******************************************************************************/
#define u8RD_LEN_FORMAT_IDENT      (uint8)0x40

/******************************************************************************/
/*!   \Description Mask to access the low nibble of
 *                 addressAndLengthFormatIdentifier which contains the number
 *                 of bytes of the memoryAddress parameter.[In RequestDownload
 *                 request message]  \n
*******************************************************************************/
#define u8ADDR_FORMAT_MASK         (uint8)0x0F

/******************************************************************************/
/*!   \Description Max to access the high nibble of
 *                 addressAndLengthFormatIdentifier which contains the number
 *                 of bytes of the memorySize parameter.[In RequestDownload
 *                 request message]   \n
*******************************************************************************/
#define u8LEN_FORMAT_MASK          (uint8)0xF0

#endif

#define u8RMBA_MIN_REQ_LEN (uint8)3
#define u8WMBA_MIN_REQ_LEN (uint8)4

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3456]: Macros are used for performance.   */
/* PRQA S 3453 ++                                                             */

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

/* !Deviation : Inhibit MISRA rule [3456]: Parameter is needed to be evaluated
 *              more than once.                                               */
/* PRQA S 3456 ++                                                             */
/*! \Description  Swap the bytes of a 16-bit data */
#define u16SWAP_BYTES(u16Word)               \
  ((((u16Word) & ((uint16)0x00FF)) << 8) |   \
   (((u16Word) & ((uint16)0xFF00)) >> 8))

/*! \Description  Swap the bytes of a 32-bit data */
#define u32SWAP_BYTES(u32Word)            \
  ((((u32Word) & 0x000000FFUL) << 24) |   \
   (((u32Word) & 0x0000FF00UL) << 8)  |   \
   (((u32Word) & 0x00FF0000UL) >> 8)  |   \
   (((u32Word) & 0xFF000000UL) >> 24))
/* PRQA S 3456 --                                                             */
/* PRQA S 3453 --                                                             */

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)

typedef struct{
  uint32 u32MemAddress;
  uint32 u32MemLength;
  uint8  u8NegCode;
}tstrCheckMemAccess;

/******************************************************************************/
/*! \Description Memory Access Type. \n\n
  \Range       u8DOWNLOAD_MEMORY,u8READ_MEMORY,u8WRITE_MEMORY,u8UPLOAD_MEMORY \n
*******************************************************************************/
typedef uint8 tu8MemoryAccessType;
#define u8DOWNLOAD_MEMORY (uint8)0x00
#define u8READ_MEMORY     (uint8)0x01
#define u8WRITE_MEMORY    (uint8)0x02
#define u8UPLOAD_MEMORY   (uint8)0x03

#endif

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/* !Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*              for memory allocation and should be included several times.  */ 
/* PRQA S 5087,0838 L1 */ 
#if (DCM_bWDBI_EN == STD_ON ||                 \
     DCM_bIO_CONTROL_EN == STD_ON ||           \
     DCM_bRDBI_EN == STD_ON ||                 \
     DCM_bROUTINE_CONTROL_ENABLED == STD_ON || \
     DCM_bROUTINE_CONTROL_ENABLED == STD_ON || \
     DCM_bOBD_SERVICES_ENABLED == STD_ON)
   
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*! Description  Array of masks used to extract/inject signals in DIDs */
static CONST(uint32,DCM_CONST) aku32BitsMask[DspInternal_u8MASKS_NUM] = {
  0x00000000UL, 
  0x00000001UL, 
  0x00000003UL, 
  0x00000007UL, 
  0x0000000FUL, 
  0x0000001FUL, 
  0x0000003FUL, 
  0x0000007FUL, 
  0x000000FFUL,
  0x000001FFUL,
  0x000003FFUL,
  0x000007FFUL,
  0x00000FFFUL,
  0x00001FFFUL,
  0x00003FFFUL,
  0x00007FFFUL,
  0x0000FFFFUL,
  0x0001FFFFUL,
  0x0003FFFFUL,
  0x0007FFFFUL,
  0x000FFFFFUL,
  0x001FFFFFUL,
  0x003FFFFFUL,
  0x007FFFFFUL,
  0x00FFFFFFUL,
  0x01FFFFFFUL,
  0x03FFFFFFUL,
  0x07FFFFFFUL,
  0x0FFFFFFFUL,
  0x1FFFFFFFUL,
  0x3FFFFFFFUL,
  0x7FFFFFFFUL,
  0xFFFFFFFFUL
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif



/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/* !Deviation : Bug in QAC */
/* PRQA S 3406 L2 */ 

#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/*! \Description Flag indication whether the service is being processed in a 
                 paged buffering mode or not */
/*! \Range       TRUE, FALSE */
VAR(boolean,DCM_VAR) DspInternal_abePagedMode[DspInternal_u8MAX_NUM_INTERNAL_REQ];

/*! \Description Flag indicating whether the Dcm_UpdatePage service have been 
                 called so Dsp shall fill the page or not */
/*! \Range       TRUE, FALSE */
VAR(boolean,DCM_VAR) DspInternal_abePageUpdate[DspInternal_u8MAX_NUM_INTERNAL_REQ];
#endif

#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"


#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/*! \Description Pointer to the current message context                     */
/*! \Range       Null, Not Null                                             */
P2VAR(Dcm_MsgContextType,DCM_VAR,DCM_VAR)
  DspInternal_apstreMsgContext[DspInternal_u8MAX_NUM_INTERNAL_REQ];

/*! \Description Dsp Main State Machine */
/*! \Range       DspInternal_u8IDLE, DSP_u8CLEAR_DIAG_INFO, DspInternal_u8RDBI, DspInternal_u8WDBI, DspInternal_u8IOCTRL    */
uint8 DspInternal_au8eStatus[DspInternal_u8MAX_NUM_INTERNAL_REQ];

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
uint8 DspInternal_au8eSubStatus[DspInternal_u8MAX_NUM_INTERNAL_REQ];

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* PRQA L:L2 */


#if(DCM_bCDTCI_EN == STD_ON)
#define DCM_START_SEC_VAR_32BIT
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Used by ClearDiagnosticInformation Service to
 *                 Store the value of DTC to clear   . \n
*******************************************************************************/
static VAR(uint32,DCM_VAR)  Dsp_u32CdiDtc;
#define DCM_STOP_SEC_VAR_32BIT
#include "MemMap.h"
#endif


#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)

#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Used by RequestDownload Service to indicate that a
 *                 request download session is active. \n
*******************************************************************************/
static VAR(boolean,DCM_VAR) Dsp_bReqDownOk;

/******************************************************************************/
/*!   \Description Used by the download function unit to indicate that the
 *                 first block to download will be recieved. \n
*******************************************************************************/
static VAR(boolean,DCM_VAR) Dsp_bRdFirstBlock;
#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Used by the download function unit to store the block
 *                 sequence counter. \n
*******************************************************************************/
static VAR(uint8,DCM_VAR)   Dsp_u8BlockSeqCount;
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_32BIT
#include "MemMap.h"

/******************************************************************************/
/*!   \Description Used by the download function unit to store current
 *                 download memory address. \n
*******************************************************************************/
static VAR(uint32,DCM_VAR)   Dsp_u32RdMemoryAddr;

/******************************************************************************/
/*!   \Description Used by the download function unit to store the
 *                 remaining bytes to receive. \n
*******************************************************************************/
static VAR(uint32,DCM_VAR)   Dsp_u32RdMemoryLen;
#define DCM_STOP_SEC_VAR_32BIT
#include "MemMap.h"


#endif





#if(DCM_bSES_CONTROL_EN == STD_ON)
/******************************************************************************/
/*!   \Description Used by DiagnosticSession Control Service to store
 *                 the requested session to perform the transition to this
 *                 session when the positive response confirmation
 *                 is received. \n *
*******************************************************************************/
#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
static VAR(uint8,DCM_VAR)   Dsp_u8ReqSesCtrl;
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif


#if(DCM_bLINK_CONTROL_EN == STD_ON || DCM_bJUMP_TO_BOOT_EN == STD_ON)
#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Used to store information needed by
                   Dcm_SetProgConditions  before jumping to the bootloader\n
*******************************************************************************/
static VAR(Dcm_ProgConditionsType,DCM_VAR)  Dsp_strDscLcProgCond;
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif

#if(DCM_bCOMM_CONTROL_EN == STD_ON)
static VAR(Dcm_CommunicationModeType,DCM_VAR) Dsp_u8RequestedCommMode;
#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)

#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Used SecurityAccess service : It is an array of Delay
                   OnBoot Timer for each security level.\n
*******************************************************************************/
static VAR(uint16,DCM_VAR)  Dsp_au16DelayOnBootTimer[DCM_u8NUM_SECURITY_LEVELS];

/******************************************************************************/
/*!   \Description Used SecurityAccess service : It is a Delay Timer
                   started if the number of failed attempts for a security
                   level reaches a certain limit.\n
*******************************************************************************/
static VAR(uint16,DCM_VAR)  Dsp_u16NumAttDelayTimer;
#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Used SecurityAccess service, To indicate that
                   the Seed is calculated by the Application. \n
*******************************************************************************/
static VAR(boolean,DCM_VAR) Dsp_bSeedCalc;
#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Used SecurityAccess service, To store the number of
                   failed attempts for each security level. \n
*******************************************************************************/
static VAR(uint8,DCM_VAR)   Dsp_au8NumOfAttempts[DCM_u8NUM_SECURITY_LEVELS];

/******************************************************************************/
/*!   \Description Used SecurityAccess service, To store the current requested
                   security Index in the configuration. \n
*******************************************************************************/
static VAR(uint8,DCM_VAR)   Dsp_u8CurrReqSecIndex;
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif


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

#if(DCM_bROE_ENABLED == STD_ON)
static FUNC(void,DCM_CODE) vidMainRoe(uint8 u8Context);
#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)
static FUNC(void,DCM_CODE) vidMainSecurityAccess(uint8 u8Context);

static FUNC(void,DCM_CODE) vidSecTimersHandling(void);

static FUNC(boolean,DCM_CODE) bSupplIndicCheck(
       uint8 u8CurrentSid,    
       CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
       CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode);
#endif

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
static FUNC(void,DCM_CODE) vidJumpToBootPend(void);
#endif

#if(DCM_bCDTCI_EN == STD_ON)
static FUNC(void,DCM_CODE)  vidMainClearDiagInfo(uint8 u8Context);
#endif

#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON || DCM_bREQUEST_UPLOAD_EN == STD_ON \
    || DCM_bWMBA_EN == STD_ON || DCM_bRMBA_EN == STD_ON )
static  FUNC(void,DCM_CODE)  vidMainRdTransferData(uint8 u8Context);
#endif

#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON || DCM_bREQUEST_UPLOAD_EN == STD_ON \
    || DCM_bWMBA_EN == STD_ON || DCM_bRMBA_EN == STD_ON )
static FUNC(boolean,DCM_CODE) bCheckMemoryAccess(
    uint8 u8Context,
    tu8MemoryAccessType u8MemoryAccessType,
    P2VAR(tstrCheckMemAccess,AUTOMATIC,AUTOMATIC)  pstrMemAccess);

static FUNC(boolean,DCM_CODE) bCheckMemorySecurityLevel(
    Dcm_SecLevelType u8CurrentSecurity,
    P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_CFG_CONST) ppkstrSecurityRef,
    uint8 u8NumOfSec);
#endif


#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
static FUNC(void,DCM_CODE) vidRcResponse(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context);

static FUNC(void,DCM_CODE) vidRcStart(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
   VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus);

static FUNC(void,DCM_CODE) vidRcStop(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
   VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus);

static FUNC(void,DCM_CODE) vidRcRequestResult(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
   VAR(Dcm_OpStatusType,AUTOMATIC) u8OpStatus);
static FUNC(void,DCM_CODE) vidMainRoutineControl(
    VAR(Dcm_IdContextType,AUTOMATIC) u8Context);
#endif

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON || DCM_bREQUEST_UPLOAD_EN == STD_ON \
    || DCM_bWMBA_EN == STD_ON || DCM_bRMBA_EN == STD_ON )
static FUNC(boolean,DCM_CODE) bCheckMemorySecurityLevel(
    Dcm_SecLevelType u8CurrentSecurity,
    P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_CFG_CONST) ppkstrSecurityRef,
    uint8 u8NumOfSec)
{
  uint8   u8SecIndex;
  boolean bSecFound = FALSE;
  boolean bEndLoop = FALSE;


  if(ppkstrSecurityRef !=
      (P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST))NULL_PTR)
  {

    for(u8SecIndex = 0;(u8SecIndex < u8NumOfSec) && (bEndLoop == FALSE)
    ;u8SecIndex++)
    {
      if(u8CurrentSecurity ==
          ppkstrSecurityRef[u8SecIndex]->u8DcmDspSecurityLevel)

      {
        bSecFound = TRUE;
        bEndLoop = TRUE;

      }
    }
  }
  else
  {
    bSecFound = TRUE;
  }

  return bSecFound;

}
#endif


#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON || DCM_bREQUEST_UPLOAD_EN == STD_ON \
    || DCM_bWMBA_EN == STD_ON || DCM_bRMBA_EN == STD_ON )
/******************************************************************************/
/*! \Description Used to Check that the format of
                 the received memory is correct and to check the
                 security access.\n

    \param[in]  u8MemoryAccessType   Memory Access Type \n
    \Range      u8DOWNLOAD_MEMORY  \n
    \param[out] pstrMemAccess   Pointer to MemoryAccess structure which
                                is used to return the extracted memory
                                address and length. And return the negative
                                response code if the format of the request is
                                not correct or security access is denied\n
    \Range      NOT NULL  \n
    \return      boolean.
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
static FUNC(boolean,DCM_CODE) bCheckMemoryAccess(
                   uint8 u8Context,
                   tu8MemoryAccessType u8MemoryAccessType,
                   P2VAR(tstrCheckMemAccess,AUTOMATIC,AUTOMATIC)  pstrMemAccess)
{

  Dcm_NegativeResponseCodeType u8NegRespCode = 0;
  Dcm_SecLevelType             u8CurrentSecurity;
  uint8                        u8AddrOffset;
  uint8                        u8LenOffset;
  uint8                        u8AddrFormat;
  uint8                        u8LenFormat;
  uint8                        u8RangeIndex;
  uint8                        u8NumOfRanges;
  boolean                      bFound = FALSE;
  boolean                      bSecAccepted;
  boolean                      bLoopEnd = FALSE;
  boolean                      bCheckFailed = FALSE;
  uint32                       u32MemoryAddress = 0;
  uint32                       u32MemoryLength  = 0;
  CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR)
                               LOC_kpstrMsgContext =
                               DspInternal_apstreMsgContext[u8Context];
  P2CONST(Dcm_DspMemoryRangeInfoType,AUTOMATIC,DCM_VAR)
                               pkstrMemoryRangeInfo;




  /*! Set a local pkstrMemoryRangeInfo to pointer to the correct MemoryRangeInfo
   *  according to the u8MemoryAccessType */

#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)

  if(u8MemoryAccessType == u8DOWNLOAD_MEMORY)
  {
    pkstrMemoryRangeInfo = Dcm_kstreDspConfig.strDcmDspMemory.
                          astrDcmDspDownloadMemoryRangeInfo;
    u8NumOfRanges = DCM_u8NUM_DOWNLOAD_MEM_RANGE;


  }
#endif
#if(DCM_bREQUEST_UPLOAD_EN == STD_ON && DCM_bREQUEST_DOWNLOAD_EN == STD_ON)
  else if(u8MemoryAccessType == u8UPLOAD_MEMORY)
  {
#else
  #if(DCM_bREQUEST_DOWNLOAD_EN == STD_OFF && DCM_bREQUEST_UPLOAD_EN == STD_ON)
  if(u8MemoryAccessType == u8UPLOAD_MEMORY)
  {  
  #endif
#endif
#if(DCM_bREQUEST_UPLOAD_EN == STD_ON)

    pkstrMemoryRangeInfo = Dcm_kstreDspConfig.strDcmDspMemory.
                           astrDcmDspUploadMemoryRangeInfo;
    u8NumOfRanges = DCM_u8NUM_UPLOAD_MEM_RANGE;

  }
#endif

#if((DCM_bRMBA_EN == STD_ON && DCM_bREQUEST_DOWNLOAD_EN == STD_ON) \
     || (DCM_bRMBA_EN == STD_ON && DCM_bREQUEST_UPLOAD_EN == STD_ON) )
  else if(u8MemoryAccessType == u8READ_MEMORY)
  {
#else
  #if(DCM_bRMBA_EN == STD_ON && DCM_bREQUEST_DOWNLOAD_EN == STD_OFF \
       && DCM_bREQUEST_UPLOAD_EN == STD_OFF )
  if(u8MemoryAccessType == u8READ_MEMORY)
  {
  #endif
#endif
#if(DCM_bRMBA_EN == STD_ON)
    pkstrMemoryRangeInfo = Dcm_kstreDspConfig.strDcmDspMemory.
                         astrDcmDspReadMemoryRangeInfo;
    u8NumOfRanges = DCM_u8NUM_READ_MEM_RANGE;

  }
#endif

#if((DCM_bWMBA_EN == STD_ON))
   
  #if((DCM_bREQUEST_DOWNLOAD_EN == STD_ON) \
     || (DCM_bREQUEST_UPLOAD_EN == STD_ON) \
     || (DCM_bRMBA_EN == STD_ON) )
  else
  {
    pkstrMemoryRangeInfo = Dcm_kstreDspConfig.strDcmDspMemory.
      astrDcmDspWriteMemoryRangeInfo;
    u8NumOfRanges = DCM_u8NUM_WRITE_MEM_RANGE;

  }
  #else
  pkstrMemoryRangeInfo = Dcm_kstreDspConfig.strDcmDspMemory.
      astrDcmDspWriteMemoryRangeInfo;
    u8NumOfRanges = DCM_u8NUM_WRITE_MEM_RANGE;
  #endif
#else

  #if((DCM_bREQUEST_DOWNLOAD_EN == STD_ON) \
     || (DCM_bREQUEST_UPLOAD_EN == STD_ON) \
     || (DCM_bRMBA_EN == STD_ON) )
  else
  {
    /*! Set Check failed to TRUE */
    bCheckFailed = TRUE;
    u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
  }
  #endif
#endif


  /*! IF the requesting service is RequestDownload or RequestUpload */
  if((u8MemoryAccessType == u8DOWNLOAD_MEMORY) ||
      (u8MemoryAccessType == u8UPLOAD_MEMORY))
  { 
    /*! Set the address offset to 2 */
    u8AddrOffset  = (uint8)2;
    /*! Extract the Address format */
    u8AddrFormat = (uint8)(LOC_kpstrMsgContext->reqData[1] & u8ADDR_FORMAT_MASK);
    /*! calculate the Memory length offset */
    u8LenOffset  = (uint8)(u8AddrFormat + (uint8)2);
    /*! Extract the length format */
    u8LenFormat = (uint8)((LOC_kpstrMsgContext->reqData[1] & u8LEN_FORMAT_MASK)>>4);
  }
  /*! ELSE */
  else
  {
    /*! Set the address offset to 1 */
    u8AddrOffset  = (uint8)1;
    /*! Extract the Address format */
    u8AddrFormat = (uint8)(LOC_kpstrMsgContext->reqData[0] & u8ADDR_FORMAT_MASK);
    /*! calculate the Memory length offset */
    u8LenOffset   = (uint8)(u8AddrFormat + (uint8)1);
    /*! Extract the length format */
    u8LenFormat = (uint8)((LOC_kpstrMsgContext->reqData[0] & u8LEN_FORMAT_MASK)>>4);

  }

  

  /*! If LenFormat > AddrFormat OR AddrFormat > 4 or LenFormat>4 or
   *     AddrFormat equals zero or LenFormat equals Zero THEN
   */
  if((u8LenFormat > u8AddrFormat) || (u8AddrFormat > (uint8)4)
        || (u8AddrFormat == 0) || (u8LenFormat == 0))       
  {
    /*! Set Check Failed to TRUE */
    bCheckFailed = TRUE;

    /*! Set u8NegRespCode to DCM_E_REQUESTOUTOFRANGE*/
    u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

  }


  /*! If Check Failed is FALSE THEN */
  if(bCheckFailed == FALSE)
  {
    /*! Calculate the MemoryAddress */
    if(u8AddrFormat == (uint8)1)
    {
      u32MemoryAddress = (uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset];
    }
    else if(u8AddrFormat == (uint8)2)
    {
      u32MemoryAddress =
          ((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset])<<8;
      u8AddrOffset++;

      u32MemoryAddress = u32MemoryAddress |
          ((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset]);
    }
    else if(u8AddrFormat == (uint8)3)
    {
      u32MemoryAddress =
          ((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset])<<16;
      u8AddrOffset++;

      u32MemoryAddress = u32MemoryAddress |
          (((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset])<<8);
      u8AddrOffset++;

      u32MemoryAddress = u32MemoryAddress |
          ((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset]);
    }
    else
    {
      u32MemoryAddress =
          ((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset])<<24;
      u8AddrOffset++;

      u32MemoryAddress = u32MemoryAddress |
          (((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset])<<16);
      u8AddrOffset++;

      u32MemoryAddress = u32MemoryAddress |
          (((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset])<<8);
      u8AddrOffset++;

      u32MemoryAddress = u32MemoryAddress |
          ((uint32)LOC_kpstrMsgContext->reqData[u8AddrOffset]);
    }

    /*! Calculate the MemoryLength */
    if(u8LenFormat == (uint8)1)
    {
      u32MemoryLength = (uint32)LOC_kpstrMsgContext->reqData[u8LenOffset] ;
    }
    else if(u8LenFormat == (uint8)2)
    {
      u32MemoryLength = ((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset])<<8 ;
      u8LenOffset++;

      u32MemoryLength = u32MemoryLength |
          ((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset]);
    }
    else if(u8LenFormat == (uint8)3)
    {
      u32MemoryLength = ((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset])<<16;
      u8LenOffset++;

      u32MemoryLength = u32MemoryLength |
          (((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset])<<8);
      u8LenOffset++;

      u32MemoryLength = u32MemoryLength |
          ((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset]);
    }
    else
    {
      u32MemoryLength = ((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset])<<24;
      u8LenOffset++;

      u32MemoryLength = u32MemoryLength |
          (((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset])<<16);
      u8LenOffset++;

      u32MemoryLength = u32MemoryLength |
          (((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset])<<8);
      u8LenOffset++;

      u32MemoryLength = u32MemoryLength |
          ((uint32)LOC_kpstrMsgContext->reqData[u8LenOffset]);
    }

    /*! IF request data length not equal to the Correct Request Length
     *  OR the requested MemoryLength equals Zero THEN*/
    if(u32MemoryLength == 0)
    {
      /*! Set Check Failed to TRUE */
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT*/
      u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

    }


    /*! If Check Failed is FALSE THEN */
    if(bCheckFailed == FALSE)
    {
      if((u32MAX_MEM_ADDRESS - u32MemoryAddress) < u32MemoryLength)
      {
        /*! Set Check Failed to TRUE */
        bCheckFailed = TRUE;

        /*! Set u8NegRespCode to DCM_E_REQUESTOUTOFRANGE*/
        u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
      }

    }

  }

  /*! If Check Failed is FALSE THEN */
  if(bCheckFailed == FALSE)
  {
    /*! Get current security level */
    (void)Dcm_GetSecurityLevel(&u8CurrentSecurity);


    /*! Check if the complete memory range to download (from memoryAddress
     *   parameter to memoryAddress + memorySize -1)  is inside the allowed
     *    memory ranges Else set check failed to TRUE and set the negative
     *    response code to DCM_E_REQUESTOUTOFRANGE*/

    /* !Deviation : For Loop Only executed once because it is dependent on
                the configuration */
    /* PRQA S 2465 L1                                                         */
    for(u8RangeIndex = 0 ;(u8RangeIndex < u8NumOfRanges)
    && (bLoopEnd == FALSE);u8RangeIndex++)
    {
/* PRQA L:L1
                                                                  */
      if(bFound == FALSE)
      {
        if(u32MemoryAddress >= pkstrMemoryRangeInfo[u8RangeIndex].
          u32DcmDspMemoryRangeLow)
        {
          bFound = TRUE;

        }
      }
      if(bFound == TRUE)
      {
        /*! Check this memory range security level */ 
        bSecAccepted = 
          bCheckMemorySecurityLevel(u8CurrentSecurity,
                                    pkstrMemoryRangeInfo[u8RangeIndex].
                                    ppkstrDcmDspMemoryRangeSecurityLevelRef,
                                    pkstrMemoryRangeInfo[u8RangeIndex].
                                    u8NumOfSecRef);

        if(bSecAccepted == TRUE)
        {
          /* !Deviation : Inhibit MISRA rule [3382]: Wraparound past zero will*/
          /*       not occur because there is check that u32MemoryLength  not
          *       equal zero.                                                */
          /* PRQA S 3382 ++                                                  */
          if(((u32MemoryAddress+u32MemoryLength)-(uint32)1) <=
            (pkstrMemoryRangeInfo[u8RangeIndex].u32DcmDspMemoryRangeHigh))
            /* PRQA S 3382 --                                                */
          {
            /*! Exit Loop*/
            bLoopEnd = TRUE;           
          }
          else
          {
            if(u8RangeIndex != (u8NumOfRanges-1))
            {
              if((pkstrMemoryRangeInfo[u8RangeIndex + 1].u32DcmDspMemoryRangeLow)
                  !=
              (pkstrMemoryRangeInfo[u8RangeIndex].u32DcmDspMemoryRangeHigh + 1))
              {
                /*! Exit Loop*/
                bLoopEnd = TRUE;
                /*! Set negative response code to DCM_E_REQUESTOUTOFRANGE*/
                u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
              }
            }
            else
            {
              /*! Exit Loop*/
              bLoopEnd = TRUE;
              /*! Set negative response code to DCM_E_REQUESTOUTOFRANGE*/
              u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
            }
          } 
        }        
        else
        {
          /*! Exit Loop*/
          bLoopEnd = TRUE;
          /*! Set negative response code to DCM_E_SECURITYACCESSDENIED*/
          u8NegRespCode = DCM_E_SECURITYACCESSDENIED;
        }
      }      
    }

    /*! If negative response to be sent */
    if((bLoopEnd == FALSE) || (u8NegRespCode != 0) )
    {
      /*! Set check failed flag to TRUE */

      bCheckFailed = TRUE;
      
    }
     
  }


  pstrMemAccess->u32MemAddress = u32MemoryAddress;
  pstrMemAccess->u32MemLength =  u32MemoryLength;
  pstrMemAccess->u8NegCode = u8NegRespCode;

  /*! IF check Failed if FALSE return TRUE ELSE return FALSE */
  return (!bCheckFailed);

}
#endif
/* PRQA S 4700 --                                                             */

#if(DCM_bRMBA_EN == STD_ON)
static FUNC(void,DCM_CODE)  vidMainRmba(uint8 u8Context)
{
  Dcm_ReturnReadMemoryType     udtReadMemReturn;
  uint8                        u8NegRespCode = 0;
  uint32                       u32MemLen;


    /*! If cancel flag is high */
  if(DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    DspInternal_abePageUpdate[u8Context] = FALSE;
    DspInternal_abePagedMode[u8Context] = FALSE;
#endif
    /*! Call processing done */
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    /*! Set the dsp status to Idle */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

  }
  else
  {
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    /*! If Paged buffer mode is OFF OR Paged buffer mode is ON and Paged
     *  Update is requested.
     */
    if((DspInternal_abePagedMode[u8Context] == FALSE) ||
        ((DspInternal_abePagedMode[u8Context] == TRUE) &&
            (DspInternal_abePageUpdate[u8Context])))
    {
#endif

    if(Dsp_u32RdMemoryLen >  DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
    {
      u32MemLen = DspInternal_apstreMsgContext[u8Context]->resMaxDataLen;
    }
    else
    {
      u32MemLen = Dsp_u32RdMemoryLen;
    }

    /*! call Dcm_ReadMemory to resume the read pending operation */
    udtReadMemReturn = Dcm_ReadMemory(
      0,
      Dsp_u32RdMemoryAddr,
      u32MemLen,
      DspInternal_apstreMsgContext[u8Context]->resData);

    /*! If reading is successful */
    if(udtReadMemReturn == DCM_READ_OK)
    {
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
      if(DspInternal_abePagedMode[u8Context] == TRUE)
      {
        if(Dsp_u32RdMemoryLen <=  DspInternal_apstreMsgContext[u8Context]->resMaxDataLen)
        {
          Dsp_u32RdMemoryLen = 0;
        }
        else
        {
          Dsp_u32RdMemoryLen -= DspInternal_apstreMsgContext[u8Context]->resMaxDataLen;
        }
        Dsp_u32RdMemoryAddr   += u32MemLen;
        Dsp_u32RdMemoryLen    -= u32MemLen;
        DspInternal_abePageUpdate[u8Context] = FALSE;
        DsdInternal_ProcessPage(u8Context,u32MemLen);
        if(Dsp_u32RdMemoryLen == 0)
        {
          /*! Set Dsp status to Idle*/
          DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
          DspInternal_abePageUpdate[u8Context] = FALSE;
          DspInternal_abePagedMode[u8Context] = FALSE;

        }
        
      }
      else
      {

        /*! Set Dsp status to Idle*/
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      }
     
#else

      /*! Set Dsp status to Idle*/
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
#endif


    }
    /*! ELSE : Reading from memory is pending */
    else if(udtReadMemReturn == DCM_READ_PENDING)
    {
      /*! Do Nothing */

    }
    /*! ELSE */
    else
    {
      #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
      if(DspInternal_abePagedMode[u8Context] == TRUE)
      {
        /*! Do Nothing (i.e Wait for paged buffer Timeout) */
      }
      else
      {
        /*! Set Dsp status to Idle*/
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
        /*! Set the negative response to DCM_E_GENERALPROGRAMMINGFAILURE */
        u8NegRespCode = DCM_E_GENERALPROGRAMMINGFAILURE;
      }
      #else
      /*! Set Dsp status to Idle*/
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      /*! Set the negative response to DCM_E_GENERALPROGRAMMINGFAILURE */
      u8NegRespCode = DCM_E_GENERALPROGRAMMINGFAILURE;
      #endif

    }
    
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    if(DspInternal_abePagedMode == FALSE)
    {
#endif
      /*! If Dsp status is IDLE */
      if(DspInternal_au8eStatus[u8Context] == DspInternal_u8IDLE)
      {
        /*! If  negative response to be sent */
        if(u8NegRespCode !=0)
        {
          /*! Call DsdInternal_SetNegResponse*/
          DsdInternal_SetNegResponse(
            DspInternal_apstreMsgContext[u8Context],
            u8NegRespCode);
        }
        /*! call DsdInternal_ProcessingDone */
        DsdInternal_ProcessingDone(
          DspInternal_apstreMsgContext[u8Context]);

      }
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    }
#endif

  #if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
  }
  #endif

  }

}
#endif

#if(DCM_bWMBA_EN == STD_ON)
static FUNC(void,DCM_CODE)  vidMainWmba(uint8 u8Context)
{
  Dcm_ReturnWriteMemoryType     udtWriteMemReturn;
  uint8                         u8NegRespCode = 0;
  uint8                         u8AddrFormat;
  uint8                         u8LenFormat;



  /*! If cancel flag is high */
  if(DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    /*! Call processing done */
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
    /*! Set the dsp status to Idle */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

  }
  else
  {
    /*! Get the Size of memoryAddress parameter */
    /*! Get the Size of memoryLength parameter */
    u8AddrFormat = DspInternal_apstreMsgContext[u8Context]->reqData[0] &
      u8ADDR_FORMAT_MASK;
    u8LenFormat = (DspInternal_apstreMsgContext[u8Context]->reqData[0] &
      u8LEN_FORMAT_MASK)>>4;


    /*! Call Dcm_WriteMemory */
    udtWriteMemReturn = Dcm_WriteMemory(
      0,
      Dsp_u32RdMemoryAddr,
      Dsp_u32RdMemoryLen,
      &DspInternal_apstreMsgContext[u8Context]->
      reqData[(uint8)1 + u8AddrFormat + u8LenFormat]);
    /*! If Dcm_WriteMemory returns OK */
    if(udtWriteMemReturn == DCM_WRITE_OK)
    {
      /*! Set the status to IDLE */
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

    }
    /*! Else If Dcm_WriteMemory returns pending */
    else if(udtWriteMemReturn == DCM_WRITE_PENDING)
    {
      /*! Do Nothing */

    }
    /*! ELSE */
    else
    {
      /*! Set the status to IDLE */
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      /*! set the negative response code to 0x72 */
      u8NegRespCode = DCM_E_GENERALPROGRAMMINGFAILURE;

    }

    /*! If Dsp status is IDLE */
    if(DspInternal_au8eStatus[u8Context] == DspInternal_u8IDLE)
    {
      /*! If negative response to be sent */
      if(u8NegRespCode != 0)
      {
        /*! Call DsdInternal_SetNegResponse*/
        DsdInternal_SetNegResponse(
          DspInternal_apstreMsgContext[u8Context],
          u8NegRespCode);
      }
      /*! Call DsdInternal_ProcessingDone*/
      DsdInternal_ProcessingDone(
        DspInternal_apstreMsgContext[u8Context]);

    }
  }

}
#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)

#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON)

/******************************************************************************/
/*! \Description Performs the Supplier Check for the requested service.\n
    \param[in]  u8CurrentSid   Service ID. \n
    \Range       0..255  \n
    \param[in] kpkstrMsgContext   Pointer to the MsgContext struct.
    \Range     NOT NULL  \n
    \param[out] kpu8NegCode   Pointer to Negative response error code which
                              is returned if check failed. \n
    \Range        NOT NULL  \n
    \return      TRUE is return if check failed, otherwise FALSE is returned.
*******************************************************************************/
static FUNC(boolean,DCM_CODE) bSupplIndicCheck(
       uint8 u8CurrentSid,    
       CONSTP2CONST(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) kpkstrMsgContext,
       CONSTP2VAR(uint8, AUTOMATIC,AUTOMATIC) kpu8NegCode)
{

#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
  uint8                        u8LoopIndex;
  boolean                      bNotOkReturned = FALSE;
  Dcm_NegativeResponseCodeType u8NotOkErrorCode = 0;
#endif
  Std_ReturnType               u8SupplReturn;
  boolean                      bCheckFailed      = FALSE;
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
  boolean                      bLoopEnd;
#endif

#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
  /*! Set the Loop End Flag to FALSE */
  bLoopEnd = FALSE;

  /*! Loop through all configured Supplier Indication Functions */
  for(u8LoopIndex = 0;(u8LoopIndex < (uint8)DCM_u8NUM_OF_SUPPL_INDIC) &&
  (bLoopEnd == FALSE);u8LoopIndex++)
  {
#endif

    /*! Call the current Xxx_SupplierIndication with the following params:
     * 1) Service Identifier
     * 2) reqData
     * 3) reqDataLen
     * 4) The Address of the local variable used to get the ErrorCode*/
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
    u8SupplReturn = (*Dcm_kstreDslConfig.apfu8SupplierIndication[u8LoopIndex])
                           (u8CurrentSid,
                            kpkstrMsgContext->reqData,
                            (uint16)kpkstrMsgContext->reqDataLen,
                            kpkstrMsgContext->msgAddInfo.reqType,
                            (uint8)kpkstrMsgContext->dcmRxPduId,
                            kpu8NegCode);
#endif

#if(DCM_u8NUM_OF_SUPPL_INDIC == 1U)
/* !Deviation : Indentation deviation because it is dependent on the
                configuration.   */
/* PRQA S 2215 L1                                                         */
    u8SupplReturn = (*Dcm_kstreDslConfig.apfu8SupplierIndication[0])(
        u8CurrentSid,
        kpkstrMsgContext->reqData,
        (uint16)kpkstrMsgContext->reqDataLen,
        kpkstrMsgContext->msgAddInfo.reqType,
        (uint8)kpkstrMsgContext->dcmRxPduId,
        kpu8NegCode);
/* PRQA L:L1                                                                  */
#endif

/*! IF the function return value is E_REQUEST_NOT_ACCEPTED THEN */
    if(u8SupplReturn == E_REQUEST_NOT_ACCEPTED)
    {
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)
      /*! Set the For Loop End Flag to TRUE */
      bLoopEnd = TRUE;
#endif

      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

      /*! Set the returned negative response code to 0. */
      *kpu8NegCode = 0;


    }
    /*! ELSE IF the return value is E_NOT_OK THEN */
    else if (u8SupplReturn == E_NOT_OK)
    {
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)

      /*! Set bNotOkReturned to TRUE. */
      bNotOkReturned = TRUE;
      /*! Set u8NotOkErrorCode with error code returned by
       *  Xxx_SupplierIndication.
       */
      u8NotOkErrorCode = *kpu8NegCode;
#endif
#if(DCM_u8NUM_OF_SUPPL_INDIC == 1U)
      /*! Set the Check Failed Flag to TRUE */
      bCheckFailed = TRUE;

#endif

    }
    /*! ELSE */
    else
    {
      /*! DO NOTHING */
    }
    /*! ENDIF */
#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)

  }
  /*! END LOOP */
#endif

#if(DCM_u8NUM_OF_SUPPL_INDIC != 1U)

  /*! IF the Check Failed Flag is  TRUE and bNotOkReturned is TRUE Then */
  if((bCheckFailed == FALSE) && (bNotOkReturned == TRUE))
  {

    /*! Set the Check Failed Flag to TRUE */
    bCheckFailed = TRUE;

    /*! Set the returned negative response code to u8NotOkErrorCode. */
    *kpu8NegCode = u8NotOkErrorCode;

  }
#endif

  /*! Return bCheckFailed */
  return(bCheckFailed);
}

#endif


/******************************************************************************/
/*! \Description Handles SecurityAccess service timers. \n
    \return      void.
*******************************************************************************/
static FUNC(void,DCM_CODE) vidSecTimersHandling(void)
{

  uint8          u8SecIndex;

  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Enter_Dcm_Access_002();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */

  /*! If the Num of attempts delay timer is On then decrement the timer*/

  if(Dsp_u16NumAttDelayTimer != (uint16)0)
  {
    Dsp_u16NumAttDelayTimer--;

  }

  /*! If the Delay on boot timer is On then decrement the timer*/

  for(u8SecIndex = 0 ; u8SecIndex < DCM_u8NUM_SECURITY_LEVELS ; u8SecIndex++)
  {
    if(Dsp_au16DelayOnBootTimer[u8SecIndex] != 0)
    {
      Dsp_au16DelayOnBootTimer[u8SecIndex]--;

    }

  }
  /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
  /*              during integration phase                                    */
  /* PRQA S 3141 ++                                                           */
  /* PRQA S 3138 ++                                                           */
  SchM_Exit_Dcm_Access_002();
  /* PRQA S 3141 --                                                           */
  /* PRQA S 3138 --                                                           */


}
#endif

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
/******************************************************************************/
/*! \Description Handles the jump to the bootloader if  Dcm_SetProgConditions
 *               is pending. \n
    \return      void.
*******************************************************************************/
static FUNC(void,DCM_CODE) vidJumpToBootPend(void)
{

  Std_ReturnType udtReturnSetProg;


  boolean        bLoopEnd = FALSE;
  uint8          u8ContextIdx;

/* !Deviation : For Loop Only executed once because it is dependent on
                the configuration DspInternal_u8MAX_NUM_INTERNAL_REQ */
/* PRQA S 2465 L1                                                             */
  for(u8ContextIdx = 0 ; (u8ContextIdx < DspInternal_u8MAX_NUM_INTERNAL_REQ)
  && (bLoopEnd == FALSE); u8ContextIdx++)
  {
/* PRQA L:L1                                                                  */

    if((DspInternal_au8eStatus[u8ContextIdx] == u8MAIN_SESS_PEND)
        && (DspInternal_au8eSubStatus[u8ContextIdx] == u8SUB_SESS_BOOT_PEND))
    {

      bLoopEnd = TRUE;


      if(DspInternal_apstreMsgContext[u8ContextIdx]->msgAddInfo.cancelOperation == TRUE)
      {
        DspInternal_au8eStatus[u8ContextIdx] = DspInternal_u8IDLE;
        DspInternal_au8eSubStatus[u8ContextIdx] = DspInternal_u8IDLE;
        DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8ContextIdx]);

      }
      else
      {
        /*! Call Dcm_SetProgConditions*/
        udtReturnSetProg = Dcm_SetProgConditions(&Dsp_strDscLcProgCond);

        /*! IF Dcm_SetProgConditions returns E_OK THEN */
        if(udtReturnSetProg == E_OK)
        {
          DspInternal_au8eStatus[u8ContextIdx] = DspInternal_u8IDLE;
          DspInternal_au8eSubStatus[u8ContextIdx] = DspInternal_u8IDLE;


          /*! Call BswM_Dcm_RequestResetMode with DCM_RESET_EXECUTION*/
          BswM_Dcm_RequestResetMode(DCM_RESET_EXECUTION);

          /*! Call DsdInternal_SetNegResponse with error code equal zero to
           *  suppress the response.
           */
          DsdInternal_SetNegResponse(
              DspInternal_apstreMsgContext[u8ContextIdx],
              DCM_u8E_SUPPRESS_RESPONSE);

          /*! Call DsdInternal_ProcessingDone. */
          DsdInternal_ProcessingDone(
              DspInternal_apstreMsgContext[u8ContextIdx]);


        }
        /*! ELSE IF Dcm_SetProgConditions returns E_PENDING THEN*/
        else if(udtReturnSetProg == E_PENDING)
        {
          /*! DO NOTHING */

        }
        /*! ELSE */
        else
        {
          DspInternal_au8eStatus[u8ContextIdx] = DspInternal_u8IDLE;
          DspInternal_au8eSubStatus[u8ContextIdx] = DspInternal_u8IDLE;
          /*! Call DsdInternal_SetNegResponse with error code equal zero to
           *  suppress the response.
           */
          DsdInternal_SetNegResponse(
              DspInternal_apstreMsgContext[u8ContextIdx],
              DCM_E_CONDITIONSNOTCORRECT);

          /*! Call DsdInternal_ProcessingDone. */
          DsdInternal_ProcessingDone(
              DspInternal_apstreMsgContext[u8ContextIdx]);

        }
      }
    }

  }


}
#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance.                    */
/* PRQA S 4700 ++                                                             */

/******************************************************************************/
/*! \Trace_To CDD-DSP-0021(0)
    \Description Main Function for SecurityAccess UDS service. \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void.
*******************************************************************************/
static FUNC(void,DCM_CODE)  vidMainSecurityAccess(uint8 u8Context)
{
  Std_ReturnType u8ReturnGetSeed;
  Std_ReturnType u8ReturnCompareKey;
  uint8          u8NegRespCode = 0;
  boolean        bSendNegResp = TRUE;
  const uint32   LOC_ku32AdrSize = Dcm_kstreDspConfig.strDcmDspSecurity.
                              akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
                              u32DcmDspSecurityADRSize;

  CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR)
                 LOC_kpstrMsgContext = DspInternal_apstreMsgContext[u8Context];



  /*! IF the cancelOperation bit is high THEN */
  if(DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)

  {
    bSendNegResp = FALSE;

    /*! IF Dsp SubStatus is u8SUB_SA_GET_SEED_PEND THEN */
    if(DspInternal_au8eSubStatus[u8Context] ==
        u8SUB_SA_GET_SEED_PEND)
    {
      /*! IF DcmDspSecurityADRSize equals Zero THEN*/
      if(LOC_ku32AdrSize == (uint32)0)
      {
        /*! - Call GetSeed with the Following parameters :
         *      SecurityAccessDataRecord = NULL_PTR,
         *      OpStatus = DCM_INITIAL
         *      Seed = &resData[1]
         *      ErrorCode = &u8NegRespCode */
        u8ReturnGetSeed = (*Dcm_kstreDspConfig.strDcmDspSecurity.
            akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
            pfu8GetSeed)(NULL_PTR,
                         DCM_CANCEL,
                         &LOC_kpstrMsgContext->resData[1],
                         &u8NegRespCode);
      }
      /*! ELSE */
      else
      {
        /*! - Call GetSeed with the Following parameters :
         *      SecurityAccessDataRecord = &reqData[1],
         *      OpStatus = DCM_INITIAL
         *      Seed = &resData[1]
         *      ErrorCode = &u8NegRespCode */
        u8ReturnGetSeed = (*Dcm_kstreDspConfig.strDcmDspSecurity.
            akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
            pfu8GetSeed)(
                &LOC_kpstrMsgContext->reqData[1],
                DCM_CANCEL,
                &LOC_kpstrMsgContext->resData[1],
                &u8NegRespCode);

      }
      /*! IF GetSeed returns E_PENDING */
      if(u8ReturnGetSeed == E_PENDING)
      {
        /*! DO NOTHING */
      }
      else
      {
        /*! Set the Dsp Status to IDLE. */
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      }
    }
    /*! IF Dsp SubStatus is u8SUB_SA_COMPARE_PEND THEN */
    else if(DspInternal_au8eSubStatus[u8Context] == u8SUB_SA_COMPARE_PEND)

    {
      /*! Call CompareKey with the following parameters:
       *  Key = &reqData[1]
       *  OpStatus = DCM_CANCEL
       */
      u8ReturnCompareKey = (*Dcm_kstreDspConfig.strDcmDspSecurity.
          akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
          pfu8CompareKey)(&LOC_kpstrMsgContext->reqData[1],
                          DCM_CANCEL);

      /*! IF CompareKey returns E_PENDING */
      if(u8ReturnCompareKey == E_PENDING)
      {
        /*! Do Nothing. */
      }
      else
      {
        /*! Set the Dsp Status to IDLE. */
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      }

    }
    /*! ELSE */
    else
    {
      /*! DO NOTHING */
    }

  }
  /*! ELSE */
  else
  {
    /*! IF DSP SubStatus is u8SUB_SA_GET_SEED_PEND THEN */
    if(DspInternal_au8eSubStatus[u8Context] == u8SUB_SA_GET_SEED_PEND)

    {
      /*! IF DcmDspSecurityADRSize equals Zero THEN*/
      if(LOC_ku32AdrSize == (uint32)0)
      {
        /*! - Call GetSeed with the Following parameters :
         *      SecurityAccessDataRecord = NULL_PTR,
         *      OpStatus = DCM_INITIAL
         *      Seed = &resData[1]
         *      ErrorCode = &u8NegRespCode */
        u8ReturnGetSeed = (*Dcm_kstreDspConfig.strDcmDspSecurity.
            akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
            pfu8GetSeed)(NULL_PTR,
                DCM_PENDING,
                &LOC_kpstrMsgContext->resData[1],
                &u8NegRespCode);
      }
      /*! ELSE */
      else
      {
        /*! - Call GetSeed with the Following parameters :
         *      SecurityAccessDataRecord = &reqData[1],
         *      OpStatus = DCM_INITIAL
         *      Seed = &resData[1]
         *      ErrorCode = &u8NegRespCode */
        u8ReturnGetSeed = (*Dcm_kstreDspConfig.strDcmDspSecurity.
            akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
            pfu8GetSeed)(
                &LOC_kpstrMsgContext->reqData[1],
                DCM_PENDING,
                &LOC_kpstrMsgContext->resData[1],
                &u8NegRespCode);

      }
      /*! IF GetSeed returns E_OK THEN */
      if(u8ReturnGetSeed == E_OK)
      {
        /*! Set Seed Calculated flag to TRUE */
        Dsp_bSeedCalc = TRUE;

        /*! Set SendNegResp flag to FALSE */
        bSendNegResp = FALSE;

        /*! Set the Dsp Status to IDLE. */
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

      }
      /*! ELSE IF GetSeed returns E_OK THEN */
      else if(u8ReturnGetSeed == E_PENDING)
      {
        /*! DO NOTHING . */
      }
      /*! ELSE */
      else
      {
        /*! Set the Dsp Status to IDLE. */
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      }
    }
    /*! IF DSP SubStatus is u8SUB_SA_COMPARE_PEND THEN */
    else if(DspInternal_au8eSubStatus[u8Context] ==
             u8SUB_SA_COMPARE_PEND)
    {
      /*! Call CompareKey with the following parameters:
       *  Key = &reqData[1]
       *  OpStatus = DCM_PENDING
       */
      u8ReturnCompareKey = (*Dcm_kstreDspConfig.strDcmDspSecurity.
          akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
          pfu8CompareKey)(&LOC_kpstrMsgContext->reqData[1],
              DCM_PENDING);

      /*! IF CompareKey returns E_OK THEN */
      if(u8ReturnCompareKey == E_OK )
      {
        /*! Set the New Security Level by calling DslInternal_SetSecurityLevel*/
        DslInternal_SetSecurityLevel(Dcm_kstreDspConfig.strDcmDspSecurity.
          akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].u8DcmDspSecurityLevel);

        /*! Set the Num of flase attempts for this security level to Zero. */
        Dsp_au8NumOfAttempts[Dsp_u8CurrReqSecIndex] = 0;

        /*! Set SendNegResp Flag to FALSE. */
        bSendNegResp = FALSE;

        /*! Set the DSP status to IDLE. */
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;


      }
      /*! ELSE IF CompareKey returns E_PENDING THEN */
      else if(u8ReturnCompareKey == E_PENDING)
      {
        /*! Do Nothing */

      }
      else
      {
        /*! Set the Dsp status to IDLE */
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

        /*! Set u8NegRespCode to 0x35(invalidKey) */
        u8NegRespCode = u8NR_INVALID_KEY;

        /*! Increment the Number of false attempts. */
        Dsp_au8NumOfAttempts[Dsp_u8CurrReqSecIndex]++;

        /*! If Number of False attempts is greater than or equal
         *    configuration parameter DcmDspSecurityNumAttDelay THEN
         */
        if(Dsp_au8NumOfAttempts[Dsp_u8CurrReqSecIndex] >= Dcm_kstreDspConfig.
            strDcmDspSecurity.akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
            u8DcmDspSecurityNumAttDelay)
        {
          /*! Set the Number of False attempts to Zero. */
          Dsp_au8NumOfAttempts[Dsp_u8CurrReqSecIndex] = 0;

          /*! Set NumAttDelayTimer with configuration parameter
           *  DcmDspSecurityDelayTime.
           */
          Dsp_u16NumAttDelayTimer = Dcm_kstreDspConfig.strDcmDspSecurity.
                                  akstrDcmDspSecurityRow[Dsp_u8CurrReqSecIndex].
                                  u16DcmDspSecurityDelayTime;

          /*! Set u8NegRespCode to 0x36.*/
          u8NegRespCode = u8NR_EXC_NUM_OF_ATT;

        }
      }

    }
    /*! ELSE */
    else
    {
      /*! DO NOTHING */
    }
  }

  if(DspInternal_au8eStatus[u8Context] == DspInternal_u8IDLE)
  {
    if(bSendNegResp == TRUE)
    {
      DsdInternal_SetNegResponse(LOC_kpstrMsgContext,u8NegRespCode);
    }
    DsdInternal_ProcessingDone(LOC_kpstrMsgContext);
  }

}
/* PRQA S 4700 --                                                             */
#endif

#if(DCM_bCDTCI_EN == STD_ON)
/******************************************************************************/
/*! \Trace_To CDD-DSP-0020(0)
    \Description Main Function for ClearDiagnosticInformation UDS service. \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void.
*******************************************************************************/
static FUNC(void,DCM_CODE)  vidMainClearDiagInfo(uint8 u8Context)
{

  Dem_ReturnClearDTCType       udtClearResult;
  Dcm_NegativeResponseCodeType u8NegRespCode = 0;


  /*! Set u8NegRespCode to Zero.
   *  IF the cancelOperation bit is High THEN
   *    - Call Dem_DcmCancelOperation.
   *    - Set the DSP status to DspInternal_u8IDLE.
   *  ELSE
   *    - Call Rte_Call_DcmIf_ClearDTC with parameters :
   *       DTC: Dsp_u32CdiDtc
   *       DTCKind: DEM_DTC_KIND_ALL_DTCS
   *       DTCOrigin: DEM_DTC_ORIGIN_PRIMARY_MEMORY
   *    IF Rte_Call_DcmIf_ClearDTC returns DEM_CLEAR_OK THEN
   *      - Set Dsp Status to Idle.
   *      - Set resDataLen to Zero.
   *    ELSE IF the function returns DEM_CLEAR_PENDING THEN
   *      - DO NOTHING.
   *    ELSE If the function returns DEM_CLEAR_WRONG_DTC THEN
   *      - Set Dsp Status to Idle.
   *      - Set u8NegRespCode to DCM_E_REQUESTOUTOFRANGE.
   *    ELSE
   *      - Set Dsp Status to Idle.
   *      - Set u8NegRespCode to DCM_E_CONDITIONSNOTCORRECT.
   *
   *    END IF
   *
   *  END IF
   *
   *  IF the DSP Status equal to DspInternal_u8IDLE THEN
   *    IF u8NegRespCode not equal to Zero THEN
   *      - Call DsdInternal_SetNegResponse.
   *    END IF
   *
   *    Call DsdInternal_ProcessingDone.
   *
   *  END IF
   */


  /*! If cancel operation is requested */
  if(DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    Dem_DcmCancelOperation();
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
    DspInternal_apstreMsgContext[u8Context]->resDataLen =
        (Dcm_MsgLenType)0;

  }
  else
  {

    udtClearResult = Rte_Call_DcmIf_ClearDTC(Dsp_u32CdiDtc,
                                             DEM_DTC_KIND_ALL_DTCS,
                                             DEM_DTC_ORIGIN_PRIMARY_MEMORY);
    if(udtClearResult == DEM_CLEAR_OK)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      DspInternal_apstreMsgContext[u8Context]->resDataLen =
          (Dcm_MsgLenType)u8CDTCI_RES_LEN;

    }
    else if(udtClearResult == DEM_CLEAR_PENDING)
    {

    }
    else if(udtClearResult == DEM_CLEAR_WRONG_DTC)
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
      DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
      u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
    }

  }

  if(DspInternal_au8eStatus[u8Context] == DspInternal_u8IDLE)
  {
    if(u8NegRespCode != 0)
    {
      DsdInternal_SetNegResponse(
          DspInternal_apstreMsgContext[u8Context],
          u8NegRespCode);

    }
    DsdInternal_ProcessingDone(
        DspInternal_apstreMsgContext[u8Context]);
  }

}
#endif

#if(DCM_bREQUEST_UPLOAD_EN == STD_ON ||DCM_bREQUEST_DOWNLOAD_EN == STD_ON )
/******************************************************************************/
/*! \Description Main Function for TransferData UDS service. \n
    \param[in]   u8Context
    \Range       0..(DspInternal_u8MAX_NUM_INTERNAL_REQ-1)
    \return      void.
*******************************************************************************/
static void vidMainRdTransferData(uint8 u8Context)

{
  Dcm_NegativeResponseCodeType     u8NegRespCode = 0;
  boolean                          bCheckFailed = FALSE;
  Dcm_ReturnWriteMemoryType        u8WriteMemReturn;
  CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR)
                                   LOC_kpstrMsgContext =
                                   DspInternal_apstreMsgContext[u8Context];

  /*! Call Dcm_WriteMemory*/
  u8WriteMemReturn = Dcm_WriteMemory(
                                     0,
                                     Dsp_u32RdMemoryAddr,
                                    (LOC_kpstrMsgContext->reqDataLen-1),
                                    &LOC_kpstrMsgContext->reqData[1]);

  /*! Dcm_WriteMemory returns DCM_WRITE_OK*/
  if(u8WriteMemReturn == DCM_WRITE_OK)
  {
    /*! Set the Dsp status to IDLE */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

    /*! Set Dsp_u32RdMemoryLen with the remaining bytes to download */
    Dsp_u32RdMemoryLen = Dsp_u32RdMemoryLen -
        (LOC_kpstrMsgContext->reqDataLen-(uint32)1);

    /*! Set Dsp_u32RdMemoryAddr with the next address to write to */
    Dsp_u32RdMemoryAddr = Dsp_u32RdMemoryAddr +
        (LOC_kpstrMsgContext->reqDataLen-(uint32)1);

    /*! set First Block to download flag to FALSE */
    Dsp_bRdFirstBlock = FALSE;

    /*! Set resDataLen to 1*/
    LOC_kpstrMsgContext->resDataLen = (Dcm_MsgLenType)u8TD_REQ_DOWN_RES_LEN;

    /*! Set resData[0] with reqData[0]*/
    LOC_kpstrMsgContext->resData[0] = LOC_kpstrMsgContext->reqData[0];

    /*! Dsp_u8BlockSeqCount equal 255 */
    if(Dsp_u8BlockSeqCount == (uint8)255)
    {
      /*! Set Dsp_u8BlockSeqCount to Zero */
      Dsp_u8BlockSeqCount = 0;

    }
    /*! ELSE */
    else
    {
      /*! Increment Dsp_u8BlockSeqCount*/
      Dsp_u8BlockSeqCount++;

    }
  }
  else if(u8WriteMemReturn == DCM_WRITE_PENDING)
  {
    /*! DO NOTHING */

  }
  /*! ELSE */
  else
  {
    /*! Set the Dsp status to IDLE */
    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

    /*! Set Check failed Flag to TRUE */
    bCheckFailed = TRUE;

    /*! Set u8NegRespCode with DCM_E_GENERALPROGRAMMINGFAILURE */
    u8NegRespCode = DCM_E_GENERALPROGRAMMINGFAILURE;

  }

  /*! If the Dsp status equals DspInternal_u8IDLE*/
  if(DspInternal_au8eStatus[u8Context] == DspInternal_u8IDLE)
  {
    /*! If check failed is TRUE */
    if(bCheckFailed ==  TRUE)
    {
      /*! Call DsdInternal_SetNegResponse*/
      DsdInternal_SetNegResponse(LOC_kpstrMsgContext,
          u8NegRespCode);

    }
    /*! Call DsdInternal_ProcessingDone*/
    DsdInternal_ProcessingDone(LOC_kpstrMsgContext);

  }

}
#endif

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-0106(0)                                               \n\n
    \Description  RoutineControl: send response                               \n
    \param[in]                                                                \n
    \Range                                                                    \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidRcResponse(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  /*! Copy subfunction to response                                           */ 
  DspInternal_apstreMsgContext[u8Context]->resData[u8SUB_FUNCTION] =
    DspInternal_apstreMsgContext[u8Context]->reqData[u8SUB_FUNCTION];
  /*! Copy routine identifier to response                                    */ 
  DspInternal_apstreMsgContext[u8Context]->resData[1] = 
    DspInternal_apstreMsgContext[u8Context]->reqData[1];
  DspInternal_apstreMsgContext[u8Context]->resData[2] = 
    DspInternal_apstreMsgContext[u8Context]->reqData[2];
  /*! Set response length                                                    */ 
  DspInternal_apstreMsgContext[u8Context]->resDataLen += 
    ((Dcm_MsgLenType)u8RC_OPTION_REC_IND);
  /*! RESPOND to service                                                     */ 
  /* PRQA S 3361 ++ */ 
  vidRESPOND_OK();
  /* PRQA S 3361 -- */ 
}
#endif

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-1070(0), CDD-1071(0), CDD-1072(0), CDD-1530(0)        \n\n
                  CDD-1531(0), CDD-1166(0), CDD-DSP-0040(0)                   \n
    \Description  RoutineControl: startRoutine subfunction                    \n
    \param[in]                                                                \n
    \Range                                                                    \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidRcStart(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
  VAR(Dcm_OpStatusType,AUTOMATIC)  u8OpStatus)
{
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)        pu8DataIn;
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)        pu8DataOut;
  VAR(uint16,AUTOMATIC)                       u16DataLength;
  VAR(Std_ReturnType,AUTOMATIC)               u8FuncReturn;
  VAR(Dcm_NegativeResponseCodeType,AUTOMATIC) u8ErrorCode;
  VAR(uint16,AUTOMATIC)                       u16RoutineId;
  VAR(uint8,AUTOMATIC)                        u8ProtocolIndex;
  VAR(boolean,AUTOMATIC)                      bItemFound;
  VAR(uint8,AUTOMATIC)                        u8Index;


  pu8DataIn =
    &(DspInternal_apstreMsgContext[u8Context]->reqData[u8RC_OPTION_REC_IND]);
  u16DataLength = (uint16)(DspInternal_apstreMsgContext[u8Context]->reqDataLen) 
    - (uint16)u8RC_OPTION_REC_IND;
  pu8DataOut =
    &(DspInternal_apstreMsgContext[u8Context]->resData[u8RC_OPTION_REC_IND]);

  /*! Search for routine id                                                  */ 
  u16RoutineId = 
    ((uint16)(((uint16)DspInternal_apstreMsgContext[u8Context]->reqData[1])<<8U)
     & ((uint16)0xFF00U)) |
    (((uint16)DspInternal_apstreMsgContext[u8Context]->reqData[2]) 
     & ((uint16)0x00FFU));
  bItemFound = FALSE;
  for (u8Index = 0;
       ((u8Index < DCM_u8NUM_OF_ROUTINES) && (bItemFound == FALSE));
       u8Index++)
  {
    if(Dcm_kstreDspConfig.astrDcmDspRoutine[u8Index].u16DcmDspRoutineIdentifier
        == u16RoutineId)
    {
      bItemFound = TRUE;
    }
  }
  /*! IF routine id is found                                                 */ 
  if (bItemFound == TRUE)
  {
    u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                pkstrDcmDslProtocolRx[DspInternal_apstreMsgContext[u8Context]->dcmRxPduId].
                u8DcmDslProtocolIndex;

    u8FuncReturn = DspInternal_akpfeRoutineStart[u8Index-1](
      Dcm_kstreDslConfig.astrDcmDslProtocolRow[u8ProtocolIndex].
      bDcmDslProtocolEndiannessConvEnabled,
      u8OpStatus, pu8DataIn, pu8DataOut, &u16DataLength, &u8ErrorCode);

    if (u8FuncReturn == E_OK)
    {
      if (  (u8OpStatus == DCM_CANCEL)
         || (DspInternal_au8eSubStatus[u8Context] == u8RC_START_CPENDING))
      {
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
        DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
      }
      else
      {
        DspInternal_apstreMsgContext[u8Context]->resDataLen = u16DataLength;
        /*! RESPOND to service                                                 */ 
        vidRcResponse(u8Context);
      }
    }
    else if (u8FuncReturn == E_PENDING)
    {
      if (  (u8OpStatus == DCM_CANCEL)
         || (DspInternal_au8eSubStatus[u8Context] == u8RC_START_CPENDING))
      {
        /*! Set substatus to PENDING (CANCEL)                                  */ 
        DspInternal_au8eSubStatus[u8Context]= u8RC_START_CPENDING;
      }
      else
      {
        /*! Set substatus to PENDING                                           */ 
        DspInternal_au8eSubStatus[u8Context]= u8RC_START_PENDING;
      }
    }
    else if (u8FuncReturn == E_FORCE_RCRRP)
    {
      /*! Force reponse pending NRC                                            */ 
      DspInternal_au8eSubStatus[u8Context]= u8RC_START_RCRRP;
      DslInternal_vidForceRCRRP(u8Context);
    }
    else
    {
      /*! NRC#(returned by RTE)                                                */ 
      /* PRQA S 3361 ++ */ 
      vidRESPOND_NRC(u8ErrorCode);
      /* PRQA S 3361 -- */ 
    }
  }
}
#endif

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-1070(0), CDD-1073(0), CDD-1074(0), CDD-1532(0)        \n\n
                  CDD-1533(0), CDD-DSP-0040(0)                                \n
    \Description  RoutineControl: stopRoutine subfunction                     \n
    \param[in]                                                                \n
    \Range                                                                    \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidRcStop(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
  VAR(Dcm_OpStatusType,AUTOMATIC)  u8OpStatus)
{
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)        pu8DataIn;
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)        pu8DataOut;
  VAR(uint16,AUTOMATIC)                       u16DataLength;
  VAR(Std_ReturnType,AUTOMATIC)               u8FuncReturn;
  VAR(Dcm_NegativeResponseCodeType,AUTOMATIC) u8ErrorCode;
  VAR(uint16,AUTOMATIC)                       u16RoutineId;
  VAR(uint8,AUTOMATIC)                        u8ProtocolIndex;
  VAR(boolean,AUTOMATIC)                      bItemFound;
  VAR(uint8,AUTOMATIC)                        u8Index;


  pu8DataIn =
    &(DspInternal_apstreMsgContext[u8Context]->reqData[u8RC_OPTION_REC_IND]);
  u16DataLength = (uint16)(DspInternal_apstreMsgContext[u8Context]->reqDataLen) - 
    (uint16)u8RC_OPTION_REC_IND;
  pu8DataOut =
    &(DspInternal_apstreMsgContext[u8Context]->resData[u8RC_OPTION_REC_IND]);

  /*! Search for routine id                                                  */ 
  u16RoutineId = 
    ((uint16)(((uint16)DspInternal_apstreMsgContext[u8Context]->reqData[1])<<8U)
     & ((uint16)0xFF00U)) |
    (((uint16)DspInternal_apstreMsgContext[u8Context]->reqData[2]) 
     & ((uint16)0x00FFU));
  bItemFound = FALSE;
  for (u8Index = 0;
       ((u8Index < DCM_u8NUM_OF_ROUTINES) && (bItemFound == FALSE));
       u8Index++)
  {
    if(Dcm_kstreDspConfig.astrDcmDspRoutine[u8Index].u16DcmDspRoutineIdentifier
        == u16RoutineId)
    {
      bItemFound = TRUE;
    }
  }
  /*! IF routine id is found                                                 */ 
  if (bItemFound == TRUE)
  {
    u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                pkstrDcmDslProtocolRx[DspInternal_apstreMsgContext[u8Context]->dcmRxPduId].
                u8DcmDslProtocolIndex;

    u8FuncReturn = DspInternal_akpfeRoutineStop[u8Index-1](
      Dcm_kstreDslConfig.astrDcmDslProtocolRow[u8ProtocolIndex].
      bDcmDslProtocolEndiannessConvEnabled,
      u8OpStatus, pu8DataIn, pu8DataOut, &u16DataLength, &u8ErrorCode);

    if (u8FuncReturn == E_OK)
    {
      if (  (u8OpStatus == DCM_CANCEL)
         || (DspInternal_au8eSubStatus[u8Context] == u8RC_STOP_CPENDING))
      {
        DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
        DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
      }
      else
      {
        DspInternal_apstreMsgContext[u8Context]->resDataLen = u16DataLength;
        /*! RESPOND to service                                                 */ 
        vidRcResponse(u8Context);
      }
    }
    else if (u8FuncReturn == E_PENDING)
    {
      if (  (u8OpStatus == DCM_CANCEL)
         || (DspInternal_au8eSubStatus[u8Context] == u8RC_STOP_CPENDING))
      {
        /*! Set substatus to PENDING (CANCEL)                                  */ 
        DspInternal_au8eSubStatus[u8Context]= u8RC_STOP_CPENDING;
      }
      else
      {
        /*! Set substatus to PENDING                                           */ 
        DspInternal_au8eSubStatus[u8Context]= u8RC_STOP_PENDING;
      }
    }
    else if (u8FuncReturn == E_FORCE_RCRRP)
    {
      /*! Force reponse pending NRC                                            */ 
      DspInternal_au8eSubStatus[u8Context]= u8RC_STOP_RCRRP;
      DslInternal_vidForceRCRRP(u8Context);
    }
    else
    {
      /*! NRC#(returned by RTE)                                                */ 
      /* PRQA S 3361 ++ */ 
      vidRESPOND_NRC(u8ErrorCode);
      /* PRQA S 3361 -- */ 
    }
  }
}
#endif

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */ 
/* PRQA S 4700 ++ */ 
/******************************************************************************/
/*! \Trace_To     CDD-1075(0), CDD-1076(0), CDD-1534(0), CDD-1535(0),         \n
                  CDD-DSP-0040(0)                                             \n
    \Description  RoutineControl: requestRoutineResult subfunction            \n
    \param[in]                                                                \n
    \Range                                                                    \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidRcRequestResult(
   VAR(Dcm_IdContextType,AUTOMATIC) u8Context,
   VAR(Dcm_OpStatusType,AUTOMATIC)  u8OpStatus)
{
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)        pu8DataOut;
  VAR(uint16,AUTOMATIC)                       u16DataLength;
  VAR(Std_ReturnType,AUTOMATIC)               u8FuncReturn;
  VAR(Dcm_NegativeResponseCodeType,AUTOMATIC) u8ErrorCode;
  VAR(uint16,AUTOMATIC)                       u16RoutineId;
  VAR(uint8,AUTOMATIC)                        u8ProtocolIndex;
  VAR(boolean,AUTOMATIC)                      bItemFound;
  VAR(uint8,AUTOMATIC)                        u8Index;


  if (DspInternal_apstreMsgContext[u8Context]->reqDataLen != 3)
  {
    /*! NRC13(returned by RTE)                                               */ 
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
  else
  {
    pu8DataOut =
      &(DspInternal_apstreMsgContext[u8Context]->resData[u8RC_OPTION_REC_IND]);

    /*! Search for routine id                                                  */ 
    u16RoutineId = 
      ((uint16)(((uint16)DspInternal_apstreMsgContext[u8Context]->reqData[1])<<8U)
       & ((uint16)0xFF00U)) |
      (((uint16)DspInternal_apstreMsgContext[u8Context]->reqData[2]) 
       & ((uint16)0x00FFU));
    bItemFound = FALSE;
    for (u8Index = 0;
         ((u8Index < DCM_u8NUM_OF_ROUTINES) && (bItemFound == FALSE));
         u8Index++)
    {
      if(Dcm_kstreDspConfig.astrDcmDspRoutine[u8Index].u16DcmDspRoutineIdentifier
          == u16RoutineId)
      {
        bItemFound = TRUE;
      }
    }
    /*! IF routine id is found                                                 */ 
    if (bItemFound == TRUE)
    {
      u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                pkstrDcmDslProtocolRx[DspInternal_apstreMsgContext[u8Context]->dcmRxPduId].
                u8DcmDslProtocolIndex;

      u8FuncReturn = DspInternal_akpfeRoutineRequestResult[u8Index-1](
        Dcm_kstreDslConfig.astrDcmDslProtocolRow[u8ProtocolIndex].
        bDcmDslProtocolEndiannessConvEnabled,
        u8OpStatus, pu8DataOut, &u16DataLength, &u8ErrorCode);

      if (u8FuncReturn == E_OK)
      {
        if (  (u8OpStatus == DCM_CANCEL)
           || (DspInternal_au8eSubStatus[u8Context] == u8RC_RESULT_CPENDING))
        {
          DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;
          DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
        }
        else
        {
          DspInternal_apstreMsgContext[u8Context]->resDataLen = u16DataLength;
          /*! RESPOND to service                                               */ 
          vidRcResponse(u8Context);
        }
      }
      else if (u8FuncReturn == E_PENDING)
      {
        if (  (u8OpStatus == DCM_CANCEL)
           || (DspInternal_au8eSubStatus[u8Context] == u8RC_RESULT_CPENDING))
        {
          /*! Set substatus to PENDING (CANCEL)                                */ 
          DspInternal_au8eSubStatus[u8Context]= u8RC_RESULT_CPENDING;
        }
        else
        {
          /*! Set substatus to PENDING                                         */ 
          DspInternal_au8eSubStatus[u8Context]= u8RC_RESULT_PENDING;
        }
      }
      else if (u8FuncReturn == E_FORCE_RCRRP)
      {
        /*! Force reponse pending NRC                                          */ 
        DspInternal_au8eSubStatus[u8Context]= u8RC_RESULT_RCRRP;
        DslInternal_vidForceRCRRP(u8Context);
      }
      else
      {
        /*! NRC#(returned by RTE)                                              */ 
        /* PRQA S 3361 ++ */ 
        vidRESPOND_NRC(u8ErrorCode);
        /* PRQA S 3361 -- */ 
      }
    }
  }
}
/* PRQA S 4700 -- */ 
#endif

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */ 
/* PRQA S 4700 ++ */ 
/******************************************************************************/
/*! \Trace_To     CDD-1065(0), CDD-DSP-0033(0)                              \n\n
    \Description  Main function for the RoutineControl service                \n
    \param[in]    Context number                                              \n
    \Range        0..255                                                      \n
*******************************************************************************/
static FUNC(void,DCM_CODE) vidMainRoutineControl(
  VAR(Dcm_IdContextType,AUTOMATIC) u8Context)
{
  if(DspInternal_apstreMsgContext[u8Context]->msgAddInfo.cancelOperation == 1)
  {
    switch (DspInternal_au8eSubStatus[u8Context])
    {
    case u8RC_START_PENDING:
    case u8RC_START_RCRRP:
    case u8RC_START_RCRRP_OK:
      vidRcStart(u8Context, DCM_CANCEL);
      break;
    case u8RC_STOP_PENDING:
    case u8RC_STOP_RCRRP:
    case u8RC_STOP_RCRRP_OK:
      vidRcStop(u8Context, DCM_CANCEL);
      break;
    case u8RC_RESULT_PENDING:
    case u8RC_RESULT_RCRRP:
    case u8RC_RESULT_RCRRP_OK:
      vidRcRequestResult(u8Context, DCM_CANCEL);
      break;
    case u8RC_START_CPENDING:
      vidRcStart(u8Context, DCM_PENDING);
      break;
    case u8RC_STOP_CPENDING:
      vidRcStop(u8Context, DCM_PENDING);
      break;
    case u8RC_RESULT_CPENDING:
      vidRcRequestResult(u8Context, DCM_PENDING);
      break;
    default:
      break;
    }
  }
  else
  {
    switch (DspInternal_au8eSubStatus[u8Context])
    {
    case u8RC_START_PENDING:
    case u8RC_START_CPENDING:
      vidRcStart(u8Context, DCM_PENDING);
      break;
    case u8RC_START_RCRRP_OK:
      vidRcStart(u8Context, DCM_FORCE_RCRRP_OK);
      break;
    case u8RC_STOP_PENDING:
    case u8RC_STOP_CPENDING:
      vidRcStop(u8Context, DCM_PENDING);
      break;
    case u8RC_STOP_RCRRP_OK:
      vidRcStop(u8Context, DCM_FORCE_RCRRP_OK);
      break;
    case u8RC_RESULT_PENDING:
    case u8RC_RESULT_CPENDING:
      vidRcRequestResult(u8Context, DCM_PENDING);
      break;
    case u8RC_RESULT_RCRRP_OK:
      vidRcRequestResult(u8Context, DCM_FORCE_RCRRP_OK);
      break;
    default:
      break;
    }
  }
}
/* PRQA S 4700 -- */ 
#endif


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#if ((DCM_bWDBI_EN == STD_ON)                   || \
     (DCM_bROUTINE_CONTROL_ENABLED == STD_ON)   || \
     (DCM_bREAD_DTC_INFO_ENABLED == STD_ON)     || \
     (DCM_bIO_CONTROL_EN == STD_ON))

/******************************************************************************/
/*! \Trace_To    CDD-1064(0), CDD-1047(0), CDD-DSP-0019(0), CDD-1077(0)     \n\n
    \Description Extract a signal value from the buffer containing Did. This is
                 based on signal position, size, total length and also apply
                 endiannes conversion.                                        \n
    \param[in]   pu8BuffIn         Pointer to the whole buffer of the Did     \n
    \Range       Not Null                                                     \n
    \param[out]  pu8SignalOut      Pointer to where the signal is extracted   \n
    \Range       Not Null                                                     \n
    \param[in]   u16DataStartByte  Start byte of the signal in the buffer     \n
    \Range       0..65535                                                     \n
    \param[in]   u8DataBitOffset   Bit offset of the signal inside the start
                                   byte                                       \n
    \Range       0..7                                                         \n
    \param[in]   u16LengthBits     Lenght of the signal in bits               \n
    \Range       0..65535                                                     \n
    \param[in]   u16TotalLength    It's the max length of the fixed size signals
                                   and zero for non-fixed size signals        \n
    \Range       32, 16, 8, 0                                                 \n
    \param[in]   bEndianConv       If endiness conversion is needed or not    \n
    \Range       TRUE, FALSE                                                  \n
    \return      Void.                                                        \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_vidExtractSignalFromBuff(
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8BuffIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8SignalOut,
  VAR(uint16,AUTOMATIC)  u16DataStartByte,
  VAR(uint8,AUTOMATIC)   u8DataBitOffset,
  VAR(uint16,AUTOMATIC)  u16LengthBits,
  VAR(uint16,AUTOMATIC)  u16TotalLength,
  VAR(boolean,AUTOMATIC) bEndianConv,
  VAR(boolean,AUTOMATIC) bSigned)
{
  VAR(uint16,AUTOMATIC) u16Length;
  VAR(uint16,AUTOMATIC) u16ByteIndex;
  VAR(uint8,AUTOMATIC)  u8MaskBits;
  VAR(uint8,AUTOMATIC)  u8Shift;
  VAR(uint16,AUTOMATIC) u16LengthBytes;
  VAR(uint16,AUTOMATIC) u16Signal;
  VAR(uint32,AUTOMATIC) u32Signal;


  u16Length = u16LengthBits;
  u8Shift = u8DataBitOffset;
  u16LengthBytes = ((u8DataBitOffset + u16LengthBits) / 8);
  if (((u8DataBitOffset + u16LengthBits) % 8) > 0)
  {
    u16LengthBytes++;
  }
  pu8SignalOut[0] = 0;
  for (u16ByteIndex=0; u16ByteIndex<u16LengthBytes; u16ByteIndex++)
  {
    if (u16Length > 8)
    {
      u8MaskBits = 8 - u8Shift;
      u16Length = u16Length - u8MaskBits;
    }
    else
    {
      u8MaskBits = (uint8)u16Length;
    }
    /*! \Deviation  Taking the lowest byte only from the lookup table        */ 
    /* PRQA S 4130 ++ */ 
    pu8SignalOut[u16ByteIndex] =
      (uint8)((pku8BuffIn[u16ByteIndex+u16DataStartByte] << u8Shift)
      & (((uint8)aku32BitsMask[8-u8MaskBits]) ^ ((uint8)0xFF)));
    /* PRQA S 4130 -- */ 
    /* if it's not the last byte then write the shited out bits in next byte */ 
    if (u16ByteIndex < (u16LengthBytes - 1))
    {
      pu8SignalOut[u16ByteIndex] = pu8SignalOut[u16ByteIndex] |
        (uint8)((pku8BuffIn[u16ByteIndex+u16DataStartByte+1] >> (8 - u8Shift))
        & ((uint8)aku32BitsMask[u8Shift]));
    }
  }
  if (u16TotalLength == 32)
  {
    u32Signal =  (((uint32)pu8SignalOut[0]) << 24) & 0xFF000000UL;
    u32Signal |= (((uint32)pu8SignalOut[1]) << 16) & 0x00FF0000UL;
    u32Signal |= (((uint32)pu8SignalOut[2]) << 8)  & 0x0000FF00UL;
    u32Signal |= (uint32)pu8SignalOut[3];
    if ((u32Signal & 0x80000000UL) > 0)
    {
      u32Signal = u32Signal >> (u16TotalLength - u16LengthBits);
      if (bSigned == TRUE)
      {
        u32Signal = u32Signal | (~aku32BitsMask[u16LengthBits]);
      }
    }
    else
    {
      u32Signal = u32Signal >> (u16TotalLength - u16LengthBits);
    }
    if (bEndianConv == TRUE)
    {
      u32Signal = u32SWAP_BYTES(u32Signal);
    }
    pu8SignalOut[0] = (uint8)((u32Signal >> 24) & 0x000000FFUL);
    pu8SignalOut[1] = (uint8)((u32Signal >> 16) & 0x000000FFUL);
    pu8SignalOut[2] = (uint8)((u32Signal >> 8) & 0x000000FFUL);
    pu8SignalOut[3] = (uint8)((u32Signal) & 0x000000FFUL);
  }
  else if (u16TotalLength == 16)
  {
    u16Signal = (uint16)(((uint16)pu8SignalOut[0]) << 8)  & ((uint16)0xFF00);
    u16Signal |= (uint16)pu8SignalOut[1];
    if ((u16Signal & (uint16)0x8000) > 0)
    {
      u16Signal = u16Signal >> (u16TotalLength - u16LengthBits);
      if (bSigned == TRUE)
      {
        u16Signal = 
          u16Signal | (uint16)(~aku32BitsMask[u16LengthBits]);
      }
    }
    else
    {
      u16Signal = u16Signal >> (u16TotalLength - u16LengthBits);
    }
    if (bEndianConv == TRUE)
    {
      u16Signal = u16SWAP_BYTES(u16Signal);
    }
    pu8SignalOut[0] = (uint8)(u16Signal >> 8);
    pu8SignalOut[1] = (uint8)(u16Signal);
  }
  else if (u16TotalLength == 8)
  {
    if ((*pu8SignalOut & (uint8)0x80) > 0)
    {
      *pu8SignalOut = *pu8SignalOut >> (u16TotalLength - u16LengthBits);
      if (bSigned == TRUE)
      {
        *pu8SignalOut = 
          *pu8SignalOut | (uint8)(~aku32BitsMask[u16LengthBits]);
      }
    }
    else
    {
      *pu8SignalOut = *pu8SignalOut >> (u16TotalLength - u16LengthBits);
    }
  }
  else
  {
  }
}
/* PRQA S 4700 --                                                             */
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON ||           \
     DCM_bRDBI_EN == STD_ON ||                 \
     DCM_bROUTINE_CONTROL_ENABLED == STD_ON || \
     DCM_bOBD_SERVICES_ENABLED == STD_ON)

/******************************************************************************/
/*! \Trace_To    CDD-1025(0), CDD-1064(0), CDD-DSP-0019(0), CDD-1077(0)     \n\n
    \Description Inject a signal value into the buffer containing Did. This is
                 based on signal position, size, total length and also apply
                 endiannes conversion.                                        \n
    \param[in]   pu8SignalIn       Pointer to the signal data                 \n
    \Range       Not Null                                                     \n
    \param[out]  pu8BuffOut        Pointer to where the signal is injected    \n
    \Range       Not Null                                                     \n
    \param[in]   u16DataStartByte  Start byte of the signal in the buffer     \n
    \Range       0..65535                                                     \n
    \param[in]   u8DataBitOffset   Bit offset of the signal inside the start
                                   byte                                       \n
    \Range       0..7                                                         \n
    \param[in]   u16LengthBits     Lenght of the signal in bits               \n
    \Range       0..65535                                                     \n
    \param[in]   u16TotalLength    It's the max length of the fixed size signals
                                   and zero for non-fixed size signals        \n
    \Range       32, 16, 8, 0                                                 \n
    \param[in]   bEndianConv       If endiness conversion is needed or not    \n
    \Range       TRUE, FALSE                                                  \n
    \return      Void.                                                        \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_vidInjectSignalIntoBuff(
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8SignalIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8BuffOut,
  VAR(uint16,AUTOMATIC) u16DataStartByte,
  VAR(uint8,AUTOMATIC)  u8DataBitOffset,
  VAR(uint16,AUTOMATIC) u16LengthBits,
  VAR(uint16,AUTOMATIC)  u16TotalLength,
  VAR(boolean,AUTOMATIC) bEndianConv)
{
  VAR(uint16,AUTOMATIC)              u16Length;
  VAR(uint16,AUTOMATIC)              u16ByteIndex;
  VAR(uint8,AUTOMATIC)               u8BitIndex;
  VAR(uint8,AUTOMATIC)               u8BitOffset;
  VAR(uint16,AUTOMATIC)              u16LengthBytes;
  VAR(uint32,AUTOMATIC)              u32InBufferTemp;
  VAR(uint16,AUTOMATIC)              u16InBufferTemp;
  VAR(uint8,AUTOMATIC)               u8InBufferTemp;
  P2CONST(uint8,AUTOMATIC,AUTOMATIC) pku8InBufferTemp;

  if (u16TotalLength == 32)
  {
    #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
    u32InBufferTemp =  (((uint32)pku8SignalIn[0]) << 24) & 0xFF000000UL;
    u32InBufferTemp |= (((uint32)pku8SignalIn[1]) << 16) & 0x00FF0000UL;
    u32InBufferTemp |= (((uint32)pku8SignalIn[2]) << 8)  & 0x0000FF00UL;
    u32InBufferTemp |= (uint32)pku8SignalIn[3];
    if (bEndianConv == TRUE)
    {
      /*! \Deviation  Used through the pointer pku8InBufferTemp */ 
      /* PRQA S 3199 ++ */ 
      u32InBufferTemp = u32SWAP_BYTES(u32InBufferTemp);
      /* PRQA S 3199 -- */ 
    }
    #else
    u32InBufferTemp =  (((uint32)pku8SignalIn[3]) << 24) & 0xFF000000UL;
    u32InBufferTemp |= (((uint32)pku8SignalIn[2]) << 16) & 0x00FF0000UL;
    u32InBufferTemp |= (((uint32)pku8SignalIn[1]) << 8)  & 0x0000FF00UL;
    u32InBufferTemp |= (uint32)pku8SignalIn[0];
    if (bEndianConv == FALSE)
    {
      /*! \Deviation  Used through the pointer pku8InBufferTemp */ 
      /* PRQA S 3199 ++ */ 
      u32InBufferTemp = u32SWAP_BYTES(u32InBufferTemp);
      /* PRQA S 3199 -- */ 
    }
    #endif
    u32InBufferTemp = u32InBufferTemp << (u16TotalLength - u16LengthBits);
    #if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /*! \Deviation  Used through the pointer pku8InBufferTemp */ 
    /* PRQA S 3199 ++ */ 
    u32InBufferTemp = u32SWAP_BYTES(u32InBufferTemp);
    /* PRQA S 3199 -- */ 
    #endif
    /*! \Deviation  Using unified buffer for all types, 
                    casting to less strict pointer */ 
    /* PRQA S 0310 ++ */ 
    pku8InBufferTemp = (P2CONST(uint8,AUTOMATIC,AUTOMATIC))&u32InBufferTemp;
    /* PRQA S 0310 -- */ 
  }
  else if (u16TotalLength == 16)
  {
    #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
    u16InBufferTemp = (uint16)(((uint16)pku8SignalIn[0]) << 8)  & (uint16)0xFF00;
    u16InBufferTemp |= (uint16)pku8SignalIn[1];
    if (bEndianConv == TRUE)
    {
      /*! \Deviation  Used through the pointer pku8InBufferTemp */ 
      /* PRQA S 3199 ++ */ 
      u16InBufferTemp = u16SWAP_BYTES(u16InBufferTemp);
      /* PRQA S 3199 -- */ 
    }
    #else
    u16InBufferTemp = (uint16)(((uint16)pku8SignalIn[1]) << 8)  & (uint16)0xFF00UL;
    u16InBufferTemp |= (uint16)pku8SignalIn[0];
    if (bEndianConv == FALSE)
    {
      /*! \Deviation  Used through the pointer pku8InBufferTemp */ 
      /* PRQA S 3199 ++ */ 
      u16InBufferTemp = u16SWAP_BYTES(u16InBufferTemp);
      /* PRQA S 3199 -- */ 
    }
    #endif
    u16InBufferTemp = u16InBufferTemp << (u16TotalLength - u16LengthBits);
    #if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /*! \Deviation  Used through the pointer pku8InBufferTemp */ 
    /* PRQA S 3199 ++ */ 
    u16InBufferTemp = u16SWAP_BYTES(u16InBufferTemp);
    /* PRQA S 3199 -- */ 
    #endif
    /*! \Deviation  Using unified buffer for all types, 
                    casting to less strict pointer */ 
    /* PRQA S 0310 ++ */ 
    pku8InBufferTemp = (P2CONST(uint8,AUTOMATIC,AUTOMATIC))&u16InBufferTemp;
    /* PRQA S 0310 -- */ 
  }
  else if (u16TotalLength == 8)
  {
    /*! \Deviation  Used through the pointer pku8InBufferTemp */ 
    /* PRQA S 3199 ++ */ 
    u8InBufferTemp = *pku8SignalIn << (u16TotalLength - u16LengthBits);
    /* PRQA S 3199 -- */ 
    pku8InBufferTemp = (P2CONST(uint8,AUTOMATIC,AUTOMATIC))&u8InBufferTemp;
  }
  else
  {
    pku8InBufferTemp = pku8SignalIn;
  }

  u16Length = u16LengthBits;
  u8BitOffset = u8DataBitOffset;
  u16LengthBytes = (u16LengthBits / 8);
  if ((u16LengthBits % 8) > 0)
  {
    u16LengthBytes++;
  }
  for (u16ByteIndex=0; u16ByteIndex<u16LengthBytes; u16ByteIndex++)
  {
    if ((u8BitOffset + u16Length) > 8)
    {
      u8BitIndex = (uint8)8 - u8BitOffset;
      u16Length = u16Length - u8BitIndex;
      if (u16Length >= u8BitOffset)
      {
        pu8BuffOut[u16ByteIndex+u16DataStartByte+1] =
          (uint8)((pu8BuffOut[u16ByteIndex+u16DataStartByte+1]
             &(uint8)aku32BitsMask[u8BitIndex]) |
          (((uint32)(pku8InBufferTemp[u16ByteIndex] << u8BitIndex))
             &((uint8)aku32BitsMask[u8BitIndex] ^ (uint8)0xFF)));
      }
      else
      {
        pu8BuffOut[u16ByteIndex+u16DataStartByte+1] =
          (uint8)((pu8BuffOut[u16ByteIndex+u16DataStartByte+1]
             & (uint8)aku32BitsMask[8-u16Length]) |
          ((uint32)(pku8InBufferTemp[u16ByteIndex] << u8BitIndex)
             & ((uint8)aku32BitsMask[8-u8BitIndex] ^ (uint8)0xFF)));
      }
      u16Length = u16Length - u8BitOffset;
    }
    else
    {
      u8BitIndex = (uint8)u16Length;
    }
    if ((u8BitIndex + u8BitOffset) >= 8)
    {
      pu8BuffOut[u16ByteIndex+u16DataStartByte] =
         (uint8)((pu8BuffOut[u16ByteIndex+u16DataStartByte]
            & ((uint8)aku32BitsMask[u8BitIndex] ^ (uint8)0xFF)) |
         ((pku8InBufferTemp[u16ByteIndex] >> u8BitOffset)
            & aku32BitsMask[u8BitIndex]));
    }
    else
    {
      pu8BuffOut[u16ByteIndex+u16DataStartByte] =
         (pu8BuffOut[u16ByteIndex+u16DataStartByte]
            & (uint8)((uint8)((uint8)aku32BitsMask[u8BitIndex]
                   << (uint8)(8 - u8BitIndex - u8BitOffset)) ^ (uint8)0xFF)) |
         ((uint8)(pku8InBufferTemp[u16ByteIndex] >> u8BitOffset)
            & (uint8)((uint8)aku32BitsMask[u8BitIndex]
                   << (8 - u8BitIndex - u8BitOffset)));
    }
  }
}
/* PRQA S 4700 --                                                             */
#endif

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
/******************************************************************************/
/*! \Trace_To     CDD-DSP-0114(0)                                           \n\n
    \Description                                                              \n
    \param[in]                                                                \n
    \Range                                                                    \n
    \return                                                                   \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_UpdatePage(Dcm_IdContextType idContext)
{
  DspInternal_abePageUpdate[idContext] = TRUE;
}
#endif

/******************************************************************************/
/*! \Trace_To    CDD-xxxx(0)                                                \n\n
    \Description                                                              \n
    \param[in]                                                                \n
    \Range                                                                    \n
    \return                                                                   \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_Init(void)
{
  Dcm_IdContextType u8IdContext;

#if(DCM_bSEC_ACCESS_EN == STD_ON)
  uint8             u8SecIndex;
#endif

#if(DCM_bECU_RESET_EN == STD_ON)

  Dcm_u8eRequestedResetMode = DCM_NO_RESET;
#endif

  

#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)
  Dsp_bReqDownOk = FALSE;
  Dsp_bRdFirstBlock = FALSE;
#endif
#if(DCM_bSES_CONTROL_EN == STD_ON)

  Dcm_u8eRequestedSesMode = DCM_DEFAULT_SESSION;

#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)

  Dsp_u16NumAttDelayTimer = (uint16)0;
  Dsp_bSeedCalc = FALSE;
  /* !Deviation : For Loop Only executed once because it is dependent on
                  the configuration */
  /* PRQA S 2465 L1                                                             */
  for(u8SecIndex = 0 ; u8SecIndex < DCM_u8NUM_SECURITY_LEVELS ; u8SecIndex++)
  /* PRQA L:L1                                                                  */
  {
    Dsp_au8NumOfAttempts[u8SecIndex] = 0;

    Dsp_au16DelayOnBootTimer[u8SecIndex] = Dcm_kstreDspConfig.strDcmDspSecurity.
        akstrDcmDspSecurityRow[u8SecIndex].
        u16DcmDspSecurityDelayTimeOnBoot;
  }
#endif

#if (DCM_bIO_CONTROL_EN == STD_ON)
  DspInternal_beRetCtrl = FALSE;
  DspInternal_beRetCtrlPending = FALSE;
#endif

  #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
  DspInternal_vidInitPeriodicIdentifiers();
  #endif

  /* !Deviation : For Loop Only executed once because it is dependent on
                  the configuration */
  /* PRQA S 2465 L1                                                           */
  for (u8IdContext = 0; u8IdContext <DspInternal_u8MAX_NUM_INTERNAL_REQ; u8IdContext++)
  /* PRQA L:L1                                                                */
  {
    DspInternal_u8DSP_STATUS = DspInternal_u8IDLE;
    DspInternal_au8eSubStatus[u8IdContext] = DspInternal_u8IDLE;
    #if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
    DspInternal_abePagedMode[u8IdContext] = FALSE;
    DspInternal_abePageUpdate[u8IdContext] = FALSE;
    #endif
  }
}

/******************************************************************************/
/*! \Trace_To    CDD-DSP-0032(0),CDD-DSP-0079(0)                            \n\n
    \Description Dsp Main Function                                            \n
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_Main(void)
{
#if (DCM_bIO_CONTROL_EN == STD_ON)
  Dcm_NegativeResponseCodeType u8NegResCode;
#endif
  Dcm_IdContextType            u8IdContext;

#if(DCM_bSEC_ACCESS_EN == STD_ON)
  vidSecTimersHandling();
#endif
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  vidJumpToBootPend();
#endif

  /*! Looping on all context IDs, and based on the Status, call the required
      main function */
  /* !Deviation : For Loop Only executed once because it is dependent on
                  the configuration */
  /* PRQA S 2465 L1                                                           */
  for (u8IdContext = 0; u8IdContext < DspInternal_u8MAX_NUM_INTERNAL_REQ; u8IdContext++)
  /* PRQA L:L1                                                                */
  {
    #if (DCM_bOBD_SERVICES_ENABLED == STD_ON)
    DspInternal_OBDMain(u8IdContext);
    #endif
    #if (DCM_DEV_ERROR_DETECT == STD_ON)
    /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be implemented*/
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_Dcm_Access_001();
    /* PRQA S 3138 --                                                         */
    /* PRQA S 3141 --                                                         */
    #endif

    /* !Deviation : Inhibit MISRA rule [3352]: Number of execution paths of   */
    /*              this 'switch' statement depends on the configuration      */
    /* PRQA S 3352 ++                                                         */
    switch (DspInternal_u8DSP_STATUS)
    {
    #if (DCM_bWDBI_EN == STD_ON)
    case DspInternal_u8WDBI:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                        implemented during integration phase            */
        /* PRQA S 3141 ++                                               */
        /* PRQA S 3138 ++                                               */
        SchM_Exit_Dcm_Access_001();
        /* PRQA S 3138 --                                               */
        /* PRQA S 3141 --                                               */
      #endif
      DspInternal_vidMainWdbi(u8IdContext);
      break;
    #endif

    #if (DCM_bRDBI_EN == STD_ON)
    case DspInternal_u8RDBI:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                      implemented during integration phase            */
      /* PRQA S 3141 ++                                               */
      /* PRQA S 3138 ++                                               */
      SchM_Exit_Dcm_Access_001();
      /* PRQA S 3138 --                                               */
      /* PRQA S 3141 --                                               */
      #endif
      DspInternal_vidMainRdbi(u8IdContext);
      break;
    #endif

    #if (DCM_bIO_CONTROL_EN == STD_ON)
    case DspInternal_u8IOCTRL:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                        implemented during integration phase            */
        /* PRQA S 3141 ++                                               */
        /* PRQA S 3138 ++                                               */
        SchM_Exit_Dcm_Access_001();
        /* PRQA S 3138 --                                               */
        /* PRQA S 3141 --                                               */
      #endif
      DspInternal_vidMainIoctrl(u8IdContext);
      break;
    #endif

    #if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
    case u8ROUTINE_CONTROL:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                        implemented during integration phase            */
        /* PRQA S 3141 ++                                               */
        /* PRQA S 3138 ++                                               */
        SchM_Exit_Dcm_Access_001();
        /* PRQA S 3138 --                                               */
        /* PRQA S 3141 --                                               */
      #endif
      vidMainRoutineControl(u8IdContext);
      break;
    #endif

    #if(DCM_bREAD_DTC_INFO_ENABLED == STD_ON)
    case DspInternal_u8READ_DTC_INFO:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                        implemented during integration phase            */
        /* PRQA S 3141 ++                                               */
        /* PRQA S 3138 ++                                               */
        SchM_Exit_Dcm_Access_001();
        /* PRQA S 3138 --                                               */
        /* PRQA S 3141 --                                               */
      #endif
      DspInternal_vidMainReadDTCInfo(u8IdContext);
      break;
    #endif

    #if(DCM_bCDTCI_EN == STD_ON)
    case u8MAIN_CDI_PEND:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                        implemented during integration phase            */
        /* PRQA S 3141 ++                                               */
        /* PRQA S 3138 ++                                               */
        SchM_Exit_Dcm_Access_001();
        /* PRQA S 3138 --                                               */
        /* PRQA S 3141 --                                               */
      #endif
      vidMainClearDiagInfo(u8IdContext);
      break;
    #endif

    #if(DCM_bSEC_ACCESS_EN == STD_ON)
    case u8MAIN_SA_PEND:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                        implemented during integration phase            */
        /* PRQA S 3141 ++                                               */
        /* PRQA S 3138 ++                                               */
        SchM_Exit_Dcm_Access_001();
        /* PRQA S 3138 --                                               */
        /* PRQA S 3141 --                                               */
      #endif
      vidMainSecurityAccess(u8IdContext);
      break;
    #endif

    #if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)
    case u8MAIN_TRANS_DATA_PEND:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
        /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                        implemented during integration phase            */
        /* PRQA S 3141 ++                                               */
        /* PRQA S 3138 ++                                               */
        SchM_Exit_Dcm_Access_001();
        /* PRQA S 3138 --                                               */
        /* PRQA S 3141 --                                               */
      #endif
      vidMainRdTransferData(u8IdContext);
      break;
    #endif

    #if(DCM_bREAD_SCALING_DATA_EN == STD_ON)
    case DspInternal_u8READ_SCALING_DATA:
      #if (DCM_DEV_ERROR_DETECT == STD_ON)
      /* !Deviation : Inhibit MISRA rule [3141,3138]: Macro is to be
                      implemented during integration phase            */
      /* PRQA S 3141 ++                                               */
      /* PRQA S 3138 ++                                               */
      SchM_Exit_Dcm_Access_001();
      /* PRQA S 3138 --                                               */
      /* PRQA S 3141 --                                               */
      #endif
      DspInternal_vidMainReadScaling(u8IdContext);
      break;
    #endif

    #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
    DspInternal_vidMainPeriodicIdentifiers(u8IdContext);
    #endif

    default:
      break;
    }
    /* PRQA S 3352 --                                                     */
  }

  /*! If returning all IO to ECU control is needed, then call the needed
      function. And the passed OpStatus is based on the flag of Pending
      is raised or not. */
  #if (DCM_bIO_CONTROL_EN == STD_ON)  
    if (DspInternal_beRetCtrl == TRUE)
    {
      if (DspInternal_beRetCtrlPending == TRUE)
      {
        DspInternal_vidIoCtrlReturnAllDidCtrlToEcu(DspInternal_u16eRetCtrlDidIndex,
          DspInternal_u8eRetCtrlSignalIndex,
          DCM_u16DSP_SIGNALS_TO_RET_CONTROL_IN_TASK,
          DCM_PENDING,
          &u8NegResCode);
      }
      else
      {
        DspInternal_vidIoCtrlReturnAllDidCtrlToEcu(DspInternal_u16eRetCtrlDidIndex,
          DspInternal_u8eRetCtrlSignalIndex,
          DCM_u16DSP_SIGNALS_TO_RET_CONTROL_IN_TASK,
          DCM_INITIAL,
          &u8NegResCode);
      }
    }
  #endif
}
/* PRQA S 4700 --                                                             */

/******************************************************************************/
/*! \Trace_To    CDD-xxxx(0)                                                \n\n
    \Description                                                              \n
    \param[in]                                                                \n
    \Range                                                                    \n
    \return                                                                   \n
*******************************************************************************/
/* Deviation: Autosar defined interface (dcmRxPduId is not used)             */ 
/* PRQA S 3206 ++ */ 
FUNC(void,DCM_CODE) DspInternal_DcmConfirmation(Dcm_IdContextType idContext,
                                 PduIdType dcmRxPduId,
                                 Dcm_ConfirmationStatusType status)
/* PRQA S 3206 -- */ 
{
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  Std_ReturnType udtReturnSetProg;

#endif

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
  if(DspInternal_abePagedMode[idContext] == TRUE)  
  {
    DspInternal_abePagedMode[idContext] = FALSE;
    DspInternal_abePageUpdate[idContext] = FALSE;
#if(DCM_bREAD_DTC_INFO_ENABLED == STD_ON)
    if(DspInternal_au8eStatus[idContext] == DspInternal_u8READ_DTC_INFO)
    {
      if((DspInternal_au8eSubStatus[idContext] == 
                                               (uint8)DspInternal_u8R2_SNAPSHOTREC_BYDTC) ||
        (DspInternal_au8eSubStatus[idContext] == 
                                               (uint8)DspInternal_u8R3_SNAPSHOTREC_BYNUM) ||
        (DspInternal_au8eSubStatus[idContext] == (uint8)DspInternal_u8R4_EXT_DATA_BY_DTC) ||
        (DspInternal_au8eSubStatus[idContext] == (uint8)DspInternal_u8R4_M_EXT_DATA_BY_DTC))
      {
        (void)Dem_EnableDTCRecordUpdate();
      }
    }
#endif
    DspInternal_au8eStatus[idContext] = DspInternal_u8IDLE;

  }
  
#endif

#if(DCM_bECU_RESET_EN == STD_ON)
  if(DspInternal_au8eStatus[idContext] == u8MAIN_ECU_RESET_PEND)
  {
    DspInternal_au8eStatus[idContext] = DspInternal_u8IDLE;
    BswM_Dcm_RequestResetMode(DCM_RESET_EXECUTION);
  }
#endif
#if(DCM_bSES_CONTROL_EN == STD_ON)
  if((DspInternal_au8eStatus[idContext] == u8MAIN_SESS_PEND) &&
      (DspInternal_au8eSubStatus[idContext] == u8SUB_SESS_NORM))
  {
    DspInternal_au8eStatus[idContext] = DspInternal_u8IDLE;
    DspInternal_au8eSubStatus[idContext] = DspInternal_u8IDLE;
    DslInternal_SetSesCtrlType(Dsp_u8ReqSesCtrl);
  }
#endif
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  if((DspInternal_au8eStatus[idContext] == u8MAIN_SESS_PEND) &&
      (DspInternal_au8eSubStatus[idContext] == u8SUB_SESS_BOOT))
  {

    udtReturnSetProg = Dcm_SetProgConditions(&Dsp_strDscLcProgCond);
    if(udtReturnSetProg == E_OK)
    {
      DspInternal_au8eStatus[idContext] = DspInternal_u8IDLE;
      DspInternal_au8eSubStatus[idContext] = DspInternal_u8IDLE;
      BswM_Dcm_RequestResetMode(DCM_RESET_EXECUTION);
    }
    else if(udtReturnSetProg == E_PENDING)
    {
      DspInternal_au8eSubStatus[idContext] = u8SUB_SESS_BOOT_PEND;

    }
    else
    {
      DspInternal_au8eStatus[idContext] = DspInternal_u8IDLE;
      DspInternal_au8eSubStatus[idContext] = DspInternal_u8IDLE;
    }

  }
#endif
#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
  if (DspInternal_au8eStatus[idContext] == u8ROUTINE_CONTROL)
  {
    switch (DspInternal_au8eSubStatus[idContext])
    {
    case u8RC_START_RCRRP:
      DspInternal_au8eSubStatus[idContext] = u8RC_START_RCRRP_OK;
      break;
    case u8RC_STOP_RCRRP:
      DspInternal_au8eSubStatus[idContext] = u8RC_STOP_RCRRP_OK;
      break;
    case u8RC_RESULT_RCRRP:
      DspInternal_au8eSubStatus[idContext] = u8RC_RESULT_RCRRP_OK;
      break;
    default:
      break;
    }
  }
#endif
}

/******************************************************************************/
/*! \Trace_To    CDD-DSP-0003(0), CDD-DSP-0031(0)                           \n\n
    \Description Notification function of protocol pre-emption                \n
    \param[in]   void                                                         \n
    \return      void                                                         \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_vidProtPreemptNotify(void)
{
  #if (DCM_bIO_CONTROL_EN == STD_ON)
    Dcm_NegativeResponseCodeType u8NegResCode;
  
    /*! Call ReturnAllToEcuControl to return all the Dids signals to the Ecu
        control. */
    DspInternal_vidIoCtrlReturnAllDidCtrlToEcu (0,0,
      DCM_u16DSP_SIGNALS_TO_RET_CONTROL_SYNC,DCM_INITIAL,&u8NegResCode);
  #endif
}

/******************************************************************************/
/*! \Trace_To    CDD-DSP-0002(0), CDD-3020(0), CDD-2085(0), CDD-DSP-0030(0),  \n
                 CDD-SIQ-3003(0)                                              \n
    \Description Notification function of session transition                  \n
    \param[in]   u8OldSession                                                 \n
    \Range       DCM_DEFAULT_SESSION..DCM_ALL_SESSION_LEVEL                   \n
    \param[in]   u8NewSession                                                 \n
    \Range       DCM_DEFAULT_SESSION..DCM_ALL_SESSION_LEVEL                   \n
    \return      void                                                         \n
*******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3206]: Usage of the input parameters of   */
/*              this function depends on the configuration.                   */
/* PRQA S 3206 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_vidSessionTransNotify
  (Dcm_SesCtrlType u8OldSession, Dcm_SesCtrlType u8NewSession)
{
  #if (DCM_bIO_CONTROL_EN == STD_ON)
    /*! If the session transition is to the default session, */
    if (u8NewSession == DCM_DEFAULT_SESSION)
    {
      Dcm_NegativeResponseCodeType u8NegResCode;
      
      /*! Call ReturnAllToEcuControl to return all the Dids signals to the Ecu
          control. */
      DspInternal_u8eRetCtrlSignalIndex = 0;
      DspInternal_u16eRetCtrlDidIndex = 0;
      DspInternal_vidIoCtrlReturnAllDidCtrlToEcu (0,0,
        DCM_u16DSP_SIGNALS_TO_RET_CONTROL_SYNC,DCM_INITIAL,&u8NegResCode);
    }
  #endif
  
  #if(  (DCM_bCDTCS_EN == STD_ON) \
     || (DCM_bPERIODIC_TRANS_ENABLED == STD_ON))
  if((u8OldSession != DCM_DEFAULT_SESSION) &&
      (u8NewSession == DCM_DEFAULT_SESSION))
  {
    #if(DCM_bCDTCS_EN == STD_ON)
    (void)Dem_EnableDTCSetting(DEM_DTC_GROUP_ALL_DTCS,
                                 DEM_DTC_KIND_ALL_DTCS);
    #endif
    #if(DCM_bPERIODIC_TRANS_ENABLED == STD_ON)
    DspInternal_vidInitPeriodicIdentifiers();
    #endif
  }
  #endif

  #if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
  Dcm_vidStopAllRoutines();
  #endif
}
/* PRQA S 3206 --                                                             */


#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)
/* Deviation: the function has high cyclomatic complexity as it depends   \n
              on several parameters, and it will not be readable in case  \n
              we splitted into several functions                          \n */ 
/* PRQA S 4700 ++ */ 
/******************************************************************************/
/*! \Trace_To     CDD-1065(0), CDD-1066(0), CDD-1067(0), CDD-1068(0),       \n\n
                  CDD-1069(0), CDD-0104(0), CDD-0105(0), CDD-0107(0),         \n
                  CDD-3021(0)                                                 \n
    \Description  RoutineControl service entry point                          \n
    \param[in]    Message context information                                 \n
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_RoutineControl(
  P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  VAR(uint8,AUTOMATIC)                                     u8Index;
  VAR(boolean,AUTOMATIC)                                   bItemFound;
  P2CONST(Dcm_DspRoutineType,AUTOMATIC,DCM_APPL_CONST)     LOC_pkstrRoutine;
  P2CONST(Dcm_DspRoutineInfoType,AUTOMATIC,DCM_APPL_CONST) LOC_pkstrRoutineInfo;
  VAR(uint16,AUTOMATIC)                                    u16RoutineId;
  VAR(Dcm_SesCtrlType,AUTOMATIC)                           u8CurrentSesCtrl;
  VAR(Dcm_SecLevelType,AUTOMATIC)                          u8CurrentSecLevel;
  VAR(uint8,AUTOMATIC)                                     u8Subfunction;
  VAR(Dcm_IdContextType,AUTOMATIC)                         u8Context;


  /*! Save message context                                                   */ 
  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;
  DspInternal_au8eSubStatus[u8Context] = u8RC_IDLE;
  DspInternal_au8eStatus[u8Context] = u8ROUTINE_CONTROL;
  if (pMsgContext->reqDataLen < 3)
  {
    /* PRQA S 3361 ++ */ 
    vidRESPOND_NRC(DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    /* PRQA S 3361 -- */ 
  }
  else
  {
    /*! Search for routine id                                                */ 
    u16RoutineId = 
       ((uint16)(((uint16)pMsgContext->reqData[1]) << 8u) & (uint16)0xFF00) |
       (((uint16)pMsgContext->reqData[2]) & (uint16)0x00FF);
    bItemFound = FALSE;
    for (u8Index = 0;
         ((u8Index < DCM_u8NUM_OF_ROUTINES) && (bItemFound == FALSE));
         u8Index++)
    {
      if(Dcm_kstreDspConfig.astrDcmDspRoutine[u8Index].
         u16DcmDspRoutineIdentifier == u16RoutineId)
      {
        bItemFound = TRUE;
      }
    }
    /*! IF routine id is found and used                                      */ 
    if ((bItemFound == TRUE) && 
       (Dcm_pkstrePbConfig->strPbDcmDspConfig.pkstrDcmDspRoutine[u8Index-1].
        bDcmDspRoutineUsed == TRUE))
    {
      LOC_pkstrRoutine = &Dcm_kstreDspConfig.astrDcmDspRoutine[u8Index-1];
      LOC_pkstrRoutineInfo = LOC_pkstrRoutine->pkstrDcmDspRoutineInfoRef;
      /*! Search available sessions                                          */ 
      (void)Dcm_GetSesCtrlType(&u8CurrentSesCtrl);
      bItemFound = FALSE;
      for (u8Index = 0;
           (  (u8Index < LOC_pkstrRoutineInfo->strDcmDspRoutineAuthorization.
               u8NumOfSessRef)
           && (bItemFound == FALSE));
           u8Index++)
      {
        if((LOC_pkstrRoutineInfo->strDcmDspRoutineAuthorization.
            ppkstrDcmDspRoutineSessionLevelRef[u8Index]->u8DcmDspSessionLevel ==
            DCM_ALL_SESSION_LEVEL)
          ||(LOC_pkstrRoutineInfo->strDcmDspRoutineAuthorization.
            ppkstrDcmDspRoutineSessionLevelRef[u8Index]->u8DcmDspSessionLevel ==
            u8CurrentSesCtrl))
        {
          bItemFound = TRUE;
        }
      }
      /*! IF routine is applicable in active session                         */ 
      if ((bItemFound == TRUE) || (u8Index == 0))
      {
        /*! Search available security level                                  */ 
        (void)Dcm_GetSecurityLevel(&u8CurrentSecLevel);
        bItemFound = FALSE;
        for (u8Index = 0;
             (  (u8Index < LOC_pkstrRoutineInfo->strDcmDspRoutineAuthorization.
                 u8NumOfSecRef)
             && (bItemFound == FALSE));
             u8Index++)
        {
          if(  (LOC_pkstrRoutineInfo->strDcmDspRoutineAuthorization.
                ppkstrDcmDspRoutineSecurityLevelRef[u8Index]->
                u8DcmDspSecurityLevel == DCM_SEC_LEV_ALL)
            || (LOC_pkstrRoutineInfo->strDcmDspRoutineAuthorization.
                ppkstrDcmDspRoutineSecurityLevelRef[u8Index]->
                u8DcmDspSecurityLevel == u8CurrentSecLevel))
          {
            bItemFound = TRUE;
          }
        }
        /*! IF security level is applicable                                  */ 
        if ((bItemFound == TRUE) || (u8Index == 0))
        {
          u8Subfunction = pMsgContext->reqData[u8SUB_FUNCTION];
          pMsgContext->resDataLen = 0;
          DspInternal_au8eSubStatus[u8Context] = u8RC_IDLE;
          /*! IF startRoutine                                                */ 
          if (u8Subfunction == u8RC_START_ROUTINE)
          {
            /*! CALL Rte Start operation                                     */ 
            vidRcStart(u8Context, DCM_INITIAL);
          }
          /*! ELSE IF stopRoutine AND stopRoutine is applicable              */ 
          else if (  (u8Subfunction == u8RC_STOP_ROUTINE)
                  && (LOC_pkstrRoutine->bDcmDspStopRoutineSupported == TRUE))
          {
            /*! CALL Rte Stop operation                                      */ 
            vidRcStop(u8Context, DCM_INITIAL);
          }
          /*! ELSE IF reqRoutineRes AND reqRoutineRes is applicable          */ 
          else if (  (u8Subfunction == u8RC_REQ_ROUT_RES)
                  && (LOC_pkstrRoutine->bDcmDspRequestResultsRoutineSupported
                      == TRUE))
          {
            /*! CALL Rte requestResult operation                             */ 
            vidRcRequestResult(u8Context, DCM_INITIAL);
          }
          /*! ELSE (subfunction not supported)                               */ 
          else
          {
            /*! NRC12                                                        */ 
            /* PRQA S 3361 ++ */ 
            vidRESPOND_NRC(DCM_E_SUBFUNCTIONNOTSUPPORTED);
            /* PRQA S 3361 -- */ 
          }
        }
        /*! ELSE (not applicable security level)                             */ 
        else
        {
          /*! NRC33                                                          */ 
          /* PRQA S 3361 ++ */ 
          vidRESPOND_NRC(DCM_E_SECURITYACCESSDENIED);
          /* PRQA S 3361 -- */ 
        }
      }
      /*! ELSE (not applicable session)                                      */ 
      else
      {
        /*! NRC31                                                            */ 
        /* PRQA S 3361 ++ */ 
        vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
        /* PRQA S 3361 -- */ 
      }
    }
    /*! ELSE (routine id is not found or not used)                           */ 
    else
    {
      /*! NRC31                                                              */ 
      /* PRQA S 3361 ++ */ 
      vidRESPOND_NRC(DCM_E_REQUESTOUTOFRANGE);
      /* PRQA S 3361 -- */ 
    }
  }
}
/* PRQA S 4700 -- */ 
#endif

#if(DCM_bECU_RESET_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS EcuReset (0x11) service. \n
    \param[in]   pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0963(0),CDD-0964(0),CDD-0965(0),CDD-0966(0),CDD-0967(0),
                CDD-0968(0),CDD-0969(0),CDD-0002(0),CDD-0003(0),CDD-0001(0)
*******************************************************************************/
FUNC(void,DCM_CODE)  DspInternal_ECUReset(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{

  Dcm_NegativeResponseCodeType u8NegRespCode = 0;
  Dcm_ResetModeType            u8ResetType;
  uint8                        u8Context;


  u8Context = pMsgContext->idContext;


  /*!  Set u8NegRespCode to Zero. */
  /*!  IF the request message length is equal to 1 THEN
   *    - Call BswM_Dcm_RequestResetMode with resetType.
   *      IF the reset mode is accepted THEN
   *        - set Dsp_bResetReq to TRUE.
   *        - set the resDataLen to 1.
   *        - set resData[0] with resetType.
   *          IF resetType is equal to DCM_ENABLE_RAPID_POWER_SHUTDOWN_RESET
   *            - set resDataLen to 2.
   *            - set resData[1] with config. parameter DcmDspPowerDownTime.
   *          END IF
   *      ELSE
   *        - set the negative response code to
   *          DCM_E_CONDITIONSNOTCORRECT.
   *      END IF
   *  ELSE
   *    - set the negative response code to
   *      DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT.
   *  END IF

   *  IF the negative response code not equal to Zero THEN
   *    - Call DsdInternal_SetNegResponse.
   *  END IF

   *  Call DsdInternal_ProcessingDone. */



  if (pMsgContext->reqDataLen == (Dcm_MsgLenType)u8ER_REQ_LEN)
  {
    u8ResetType = pMsgContext->reqData[0];

    Dcm_u8eRequestedResetMode = DCM_NO_RESET;
    BswM_Dcm_RequestResetMode(u8ResetType);
    if(Dcm_u8eRequestedResetMode == u8ResetType)
    {
      DspInternal_au8eStatus[u8Context] = u8MAIN_ECU_RESET_PEND;
      pMsgContext->resDataLen = (Dcm_MsgLenType)u8ER_RES_LEN;
      pMsgContext->resData[0]= u8ResetType;
      if(u8ResetType == DCM_ENABLE_RAPID_POWER_SHUTDOWN_RESET)
      {
        pMsgContext->resData[1]= Dcm_kstreDspConfig.u8DcmDspPowerDownTime;
        pMsgContext->resDataLen = (Dcm_MsgLenType)u8ER_ERPSD_RES_LEN;
      }

    }
    else
    {
      u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
    }
  }
  else
  {
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  if(u8NegRespCode != 0)
  {
    DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
  }
  DsdInternal_ProcessingDone(pMsgContext);

}
#endif
#if(DCM_bSES_CONTROL_EN == STD_ON)

/******************************************************************************/
/*! \Description Implements the UDS DiagnosticSessionControl (0x10) service. \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0955(0),CDD-0957(0),CDD-0958(0),CDD-0960(0),CDD-0197(0),
                CDD-0198(0),CDD-0199(0),CDD-0507(0),CDD-0193(0),CDD-1138(0),
                CDD-1139(0),CDD-1140(0),CDD-1519(0),CDD-1516(0),CDD-1520(0),
                CDD-1142(0),CDD-1143(0),CDD-DSP-0022(0),CDD-DSP-0170(0)
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE) DspInternal_DiagnosticSessionControl(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{

  Dcm_NegativeResponseCodeType u8NegRespCode = 0;
  Dcm_SesCtrlType              u8ReqSesCtrl;
  Dcm_SesCtrlType              u8CurrSesCtrl;
  uint16                       u16P2ReloadValue = 0;
  uint16                       u16P2StarReloadValue = 0;
  uint16                       u16P2InMs;
  uint16                       u16P2StarInMs;
  uint8                        u8ProtocolIndex;
  uint8                        u8SesIndex;
  boolean                      bSesFound = FALSE;
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  Dcm_SessionBootType          u8SessionForBoot = DCM_NO_BOOT;
#endif
  P2CONST(Dcm_DspSessionType,AUTOMATIC,DCM_CFG_CONST)
                               pkstrDspSessTableIdRef;
  uint8                        u8Context;

  u8Context = pMsgContext->idContext;



  /*! Set Local Variable u8NegRespCode to Zero. */
  /*! Get the Requesting Protocol Index.
   *  Get the Requesting Protocol Session Table Pointer.
   *  IF the reqDataLen equals 1 THEN
   *    - Get the Current Session Level of the DCM [call Dcm_GetSesCtrlType]
   *    - Search for the requested session level in the session rows configured
          in the session table.
   *    IF the requested Session level is not found
   *      - Set the negative response code to NRC 0x12 subfunction not supported
   *    ELSE
   *
   *      IF DcmDspSessionForBoot parameter equal to DCM_OEM_BOOT THEN
   *        - Call BswM_Dcm_RequestResetMode with Reset Type
   *          DCM_BOOTLOADER_RESET.
   *        IF the Requested Reset Mode is accepted THEN
   *          - Set the negative response code to NRC 0x78 (Response pending).
   *        ELSE
   *          - Set the negative response code to NRC 0x22 (Condition Not
   *            Correct)
   *        END IF
   *
   *      ELSE IF DcmDspSessionForBoot parameter equal to DCM_SYS_BOOT THEN
   *         - Call BswM_Dcm_RequestResetMode with Reset Type
   *           DCM_SS_BOOTLOADER_RESET.
   *         IF the Requested Reset Mode is accepted THEN
   *           - Set the negative response code to NRC 0x78 (Response pending).
   *         ELSE
   *            - Set the negative response code to NRC 0x22
   *             (Condition Not Correct).
   *         END IF
   *      ELSE
   *         - Call BswM_Dcm_RequestSessionMode with the requested session as
   *           a parameter.
   *
   *         IF the request session Mode is accepted THEN
   *           - Set the resDataLen to 5.
   *           - Set resData[0] to the requested session control.
   *           - Convert DcmDspSessionP2ServerMax to milliseconds by multiplying
   *             by the DCM_TASK_TIME_IN_MS.
   *           - Convert DcmDspSessionP2StarServerMax to milliSeconds by
   *             multiplying by the DCM_TASK_TIME_IN_MS.
   *          ELSE
   *            - Set the negative response code to NRC 0x22.
   *          END IF
   *        END IF

  *    ELSE
  *      - Set the negative response code to
  *        DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT.
  *    END IF
  *
  *  IF the Negative response code is not equal to zero THEN
        - Call DsdInternal_SetNegResponse .
      END IF
  *   Call DsdInternal_ProcessingDone to send the response */

  DspInternal_apstreMsgContext[u8Context] = pMsgContext;

  u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                    pkstrDcmDslProtocolRx[pMsgContext->dcmRxPduId].
                    u8DcmDslProtocolIndex;
  pkstrDspSessTableIdRef = Dcm_kstreDslConfig.
      astrDcmDslProtocolRow[u8ProtocolIndex].pkstrDcmDslProtocolSessionRef;

  u8ReqSesCtrl = pMsgContext->reqData[0];

  if (pMsgContext->reqDataLen == (Dcm_MsgLenType)u8DSC_REQ_LEN)
  {

    (void)Dcm_GetSesCtrlType(&u8CurrSesCtrl);

    for(u8SesIndex = 0;(u8SesIndex < pkstrDspSessTableIdRef->u8NumOfSessRows)
    && (bSesFound == FALSE); u8SesIndex++)
    {
      if(pkstrDspSessTableIdRef->ppkstrDcmDspSessionRowType[u8SesIndex]->
          u8DcmDspSessionLevel == u8ReqSesCtrl)
      {
        bSesFound = TRUE;

        u16P2ReloadValue = pkstrDspSessTableIdRef->
            ppkstrDcmDspSessionRowType[u8SesIndex]->
            u16DcmDspSessionP2ServerMax;

        u16P2StarReloadValue = pkstrDspSessTableIdRef->
            ppkstrDcmDspSessionRowType[u8SesIndex]->
            u16DcmDspSessionP2StarServerMax;



#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
        u8SessionForBoot = pkstrDspSessTableIdRef->
            ppkstrDcmDspSessionRowType[u8SesIndex]->
            u8DcmDspSessionForBoot;
#endif

      }
    }
    if(bSesFound == FALSE)
    {
      u8NegRespCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
    else
    {
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
      if(u8SessionForBoot == DCM_OEM_BOOT)
      {
        BswM_Dcm_RequestResetMode(DCM_BOOTLOADER_RESET);
        if(Dcm_u8eRequestedResetMode == DCM_BOOTLOADER_RESET)
        {
          DspInternal_au8eStatus[u8Context] = u8MAIN_SESS_PEND;
          DspInternal_au8eSubStatus[u8Context] = u8SUB_SESS_BOOT;
          Dsp_strDscLcProgCond.ProtocolId =
              Dcm_pkstrePbConfig->
              strPbDcmDslConfig.
              pkstrDcmDslProtocolRow[u8ProtocolIndex].
              u8DcmDslProtocolID;
          Dsp_strDscLcProgCond.Sid = u8DSC_SID;
          Dsp_strDscLcProgCond.SubFncId = u8ReqSesCtrl  ;
          Dsp_strDscLcProgCond.TesterSourceAddr =
              Dcm_pkstrePbConfig->strPbDcmDslConfig.
              pkstrDcmDslProtocolRx[pMsgContext->dcmRxPduId].
             u8DcmDslProtocolRxTesterSourceAddr;

        }
        else
        {
          u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
        }
      }
      else if(u8SessionForBoot == DCM_SYS_BOOT)
      {
        BswM_Dcm_RequestResetMode(DCM_SS_BOOTLOADER_RESET);

        if(Dcm_u8eRequestedResetMode == DCM_SS_BOOTLOADER_RESET)
        {
          DspInternal_au8eStatus[u8Context] = u8MAIN_SESS_PEND;
          DspInternal_au8eSubStatus[u8Context] = u8SUB_SESS_BOOT;
          Dsp_strDscLcProgCond.ProtocolId = Dcm_pkstrePbConfig->
                                        strPbDcmDslConfig.
                                        pkstrDcmDslProtocolRow[u8ProtocolIndex].
                                        u8DcmDslProtocolID;

          Dsp_strDscLcProgCond.Sid = u8DSC_SID;
          Dsp_strDscLcProgCond.SubFncId = u8ReqSesCtrl  ;
          Dsp_strDscLcProgCond.TesterSourceAddr =
              Dcm_pkstrePbConfig->strPbDcmDslConfig.
              pkstrDcmDslProtocolRx[pMsgContext->dcmRxPduId].
             u8DcmDslProtocolRxTesterSourceAddr;

        }
        else
        {
          u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
        }
      }
      else
      {
#endif
        /* !Deviation : Inhibit rule [2215]: Indentation level depends on
                        configuration                                         */
        /* PRQA S 2215 ++                                                     */
        BswM_Dcm_RequestSessionMode(u8ReqSesCtrl);

        if(Dcm_u8eRequestedSesMode == u8ReqSesCtrl)
        {
          Dsp_u8ReqSesCtrl = u8ReqSesCtrl;
          DspInternal_au8eStatus[u8Context] = u8MAIN_SESS_PEND;
          DspInternal_au8eSubStatus[u8Context] = u8SUB_SESS_NORM;
          pMsgContext->resDataLen = (Dcm_MsgLenType)u8DSC_RES_LEN;
          pMsgContext->resData[0] = u8ReqSesCtrl;
          u16P2InMs = (uint16)(u16P2ReloadValue * DCM_TASK_TIME_IN_MS);
          u16P2StarInMs = (uint16)(u16P2StarReloadValue * DCM_TASK_TIME_IN_MS);

          #if(DCM_bPSA_SPECIFIC_CONF == STD_ON)
          u16P2StarInMs = (uint16)(u16P2StarInMs/(uint16)10);
          #endif
          pMsgContext->resData[1] = (uint8)((u16P2InMs & 0xFF00)>>8);
          pMsgContext->resData[2] = (uint8)(u16P2InMs & 0x00FF);
          pMsgContext->resData[3] = (uint8)((u16P2StarInMs & 0xFF00)>>8);
          pMsgContext->resData[4] = (uint8)(u16P2StarInMs & 0x00FF);

        }
        else
        {
          u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        /* PRQA S 2215 --                                                     */
#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
      }
#endif
    }
  }
  else
  {
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  if(DspInternal_au8eSubStatus[u8Context] == u8SUB_SESS_BOOT)
  {
    DslInternal_vidForceRCRRP(u8Context);
  }
  else
  {
#endif

    if(u8NegRespCode != 0)
    {
      DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);

    }
    DsdInternal_ProcessingDone(pMsgContext);

#if(DCM_bJUMP_TO_BOOT_EN == STD_ON)
  }
#endif

}
/* PRQA S 4700 --                                                             */
#endif

#if(DCM_bCDTCS_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS ControlDTCSetting (0x85) service. \n
    \param[in]   pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-1079(0),CDD-1080(0),CDD-1081(0),CDD-0169(0),CDD-0170(0),
                CDD-0171(0),CDD-0200(0),CDD-0201(0),CDD-1985(0),CDD-0168(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_ControlDTCSetting(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{

  /*! Set local variable u8NegRespCode to Zero. */
  Dcm_NegativeResponseCodeType    u8NegRespCode = 0;
  Dem_ReturnControlDTCSettingType udtRetControlDtcSett;
  /*! Set local variable udtDtcGroup to DEM_DTC_GROUP_ALL_DTCS */
  Dem_DTCGroupType                udtDtcGroup = DEM_DTC_GROUP_ALL_DTCS;
      
  

  /*! IF the reqDataLen equals 1 THEN */
  if(pMsgContext->reqDataLen == (Dcm_MsgLenType)1)
  {
    /*! Do Nothing */

  }
  /*! Else If reqDataLen equals 4 THEN */
  else if(pMsgContext->reqDataLen == (Dcm_MsgLenType)4)
  {
    /*! Extract the DtcGroup from the message and store in udtDtcGroup */
    udtDtcGroup = ((((uint32)pMsgContext->reqData[1]) << 16) |
                  (((uint32)pMsgContext->reqData[2]) << 8) |
                  ((uint32)pMsgContext->reqData[3]));
  }
  /*! Else */
  else
  {
    /*! Set u8NegRespCode to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT*/
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }


  /*!   IF DTCSettingType(reqData[0]) is ON (0x01) THEN */
  /*!     - Call Dem_EnableDTCSetting with params: udtDtcGroup
   *        and DEM_DTC_KIND_ALL_DTCS. */
  /*!       IF Dem_EnableDTCSetting returns DEM_CONTROL_DTC_SETTING_OK THEN */
  /*!         - Set the Negative response flag to FALSE. */
  /*!         - Set resDataLen to 1. */
  /*!         - Set resData[0] with DTCSettingType(reqData[0]) */
  /*!       ELSE */
  /*!         - set the NegRespCode to DCM_E_CONDITIONSNOTCORRECT.  */
  /*!       END IF */
  if(u8NegRespCode == 0)
  {
    if(pMsgContext->reqData[0] == u8CDTCS_SUBFUNC_ON)
    {
      udtRetControlDtcSett = Dem_EnableDTCSetting(udtDtcGroup,
        DEM_DTC_KIND_ALL_DTCS);
      if(udtRetControlDtcSett == DEM_CONTROL_DTC_SETTING_OK )
      {
        pMsgContext->resDataLen = (Dcm_MsgLenType)u8CDTCS_RES_LEN;
        pMsgContext->resData[0] = pMsgContext->reqData[0];
      }
      else
      {
        u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
      }
    }
    /*!   ELSE IF DTCSettingType(reqData[0]) is OFF (0x02) THEN */
    /*!     - Call Dem_DisableDTCSetting with params: udtDtcGroup
    *        and DEM_DTC_KIND_ALL_DTCS. */
    /*!       IF Dem_DisableDTCSetting returns DEM_CONTROL_DTC_SETTING_OK THEN */
    /*!         - Set the Negative response flag to FALSE. */
    /*!         - Set resDataLen to 1. */
    /*!         - Set resData[0] with DTCSettingType(reqData[0]). */
    /*!       ELSE */
    /*!         - set the NegRespCode to DCM_E_CONDITIONSNOTCORRECT.  */
    /*!       END IF */

    else if(pMsgContext->reqData[0] == u8CDTCS_SUBFUNC_OFF)
    {
      udtRetControlDtcSett = Dem_DisableDTCSetting(udtDtcGroup,
        DEM_DTC_KIND_ALL_DTCS);
      if(udtRetControlDtcSett == DEM_CONTROL_DTC_SETTING_OK )
      {
        pMsgContext->resDataLen = (Dcm_MsgLenType)u8CDTCS_RES_LEN;
        pMsgContext->resData[0] = pMsgContext->reqData[0];

      }
      else
      {
        u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
      }

    }
    /*!   ELSE */
    /*!     - set the NegRespCode to DCM_E_SUBFUNCTIONNOTSUPPORTED. */
    /*!   END IF */
    else
    {
      u8NegRespCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
  }
  

  /*! IF u8NegRespCode not equal to Zero THEN */
  /*!   - Call DsdInternal_SetNegResponse.*/
  /*! END IF */

  /*! Call DsdInternal_ProcessingDone. */
  if(u8NegRespCode != 0)
  {
    DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);

  }
  DsdInternal_ProcessingDone(pMsgContext);

}
#endif

#if(DCM_bTESTER_PRESENT_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS TestPresent (0x3E) service.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0191(0),CDD-0192(0),CDD-1078(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_TesterPresent(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{

  Dcm_NegativeResponseCodeType u8NegRespCode = 0;

  /*! Set u8NegRespCode to Zero */
  /*! IF reqDataLen equal to 1 THEN */
  /*!   IF zeroSubFunction is requested THEN */
  /*!     - set Negative response flag to FALSE. */
  /*!     - set resDataLen to 1. */
  /*!     - set resData[0] with reqData[0]. */
  /*!   ELSE */
  /*!     - set NegRespCode with DCM_E_SUBFUNCTIONNOTSUPPORTED. */
  /*!   END IF */
  /*! ELSE   */
  /*!   - set NegRespCode with DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT. */
  /*! END IF */

  /*! IF the u8NegRespCode not equal to Zero THEN */
  /*!   - Call DsdInternal_SetNegResponse.*/
  /*! END IF */
  /*! Call DsdInternal_ProcessingDone. */

  if (pMsgContext->reqDataLen == (Dcm_MsgLenType)u8TP_REQ_LEN)
  {
    if(pMsgContext->reqData[0] == u8TP_SUBFUNC_ZERO)
    {
      pMsgContext->resData[0] = pMsgContext->reqData[0];
      pMsgContext->resDataLen = (Dcm_MsgLenType)u8TP_RES_LEN;
    }
    else
    {
      u8NegRespCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
  }
  else
  {
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }

  if(u8NegRespCode != 0)
  {
    DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);

  }
  DsdInternal_ProcessingDone(pMsgContext);
}
#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS SecurityAccess (0x27) service. \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0041(0),CDD-0043(0),CDD-0044(0),CDD-0215(0),CDD-0221(0),
                CDD-0037(0),CDD-0038(0),CDD-0039(0),CDD-0040(0),CDD-0045(0),
                CDD-0047(0),CDD-0050(0),CDD-0051(0),CDD-1030(0),CDD-1031(0),
                CDD-1032(0),CDD-1033(0),CDD-1034(0),CDD-1971(0),CDD-1521(0),
                CDD-1522(0),CDD-# DSP-0021(0),CDD-DSP-0023(0),CDD-DSP-0024(0),
                CDD-0945(0)
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance                     */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE)  DspInternal_SecurityAccess(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)

{

  Dcm_NegativeResponseCodeType u8NegRespCode = 0;
  Dcm_NegativeResponseCodeType u8ApplNegCode = 0;
  uint8                        u8SecAccessType;
  Dcm_SecLevelType             u8ReqSecLevel;
  Dcm_SecLevelType             u8CurrSecLevel;
  boolean                      bSecLevFound = FALSE;
  boolean                      bCheckFailed = FALSE;
  uint8                        u8SecIndex;
  uint32                       u32KeySize = 0;
  uint32                       u32AdrSize = 0;
  uint32                       u32SeedSize = 0;
  uint32                       u32SeedIndex;
  Std_ReturnType               u8ReturnGetSeed;
  Std_ReturnType               u8ReturnCompareKey;
  uint8                        u8ReqType;
  uint8                        u8InternalMainStatus = DspInternal_u8IDLE;
  uint8                        u8Context;


  u8Context = pMsgContext->idContext;


  DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;

  u8SecAccessType = pMsgContext->reqData[0];

  /*! If SecAccessType is Odd then the request is requestSeed Else then it is
   *   Send Key */

  u8ReqType = (uint8)(u8SecAccessType % (uint8)2);

  /*! - Calculate the requested security level = (securityAccessType+1)/2.*/
  u8ReqSecLevel = (uint8)(((uint16)u8SecAccessType + (uint16)1)>>1);

  /*! - Get the current security level using Dcm_GetSecurityLevel.*/
  (void)Dcm_GetSecurityLevel(&u8CurrSecLevel);


  /*!- Search for the requested security level in the DcmDspSecurity
   *   configuration container.
   */
  for(u8SecIndex = 0 ; ((u8SecIndex < DCM_u8NUM_SECURITY_LEVELS) &&
  (bSecLevFound == FALSE)) ; u8SecIndex++)
  {
    if(u8ReqSecLevel == Dcm_kstreDspConfig.strDcmDspSecurity.
        akstrDcmDspSecurityRow[u8SecIndex].
        u8DcmDspSecurityLevel)
    {
      bSecLevFound = TRUE;
      u32KeySize = Dcm_kstreDspConfig.strDcmDspSecurity.
          akstrDcmDspSecurityRow[u8SecIndex].
          u32DcmDspSecurityKeySize;
      u32AdrSize = Dcm_kstreDspConfig.strDcmDspSecurity.
          akstrDcmDspSecurityRow[u8SecIndex].
          u32DcmDspSecurityADRSize;

      u32SeedSize = Dcm_kstreDspConfig.strDcmDspSecurity.
          akstrDcmDspSecurityRow[u8SecIndex].
          u32DcmDspSecuritySeedSize;

    }
  }
  u8SecIndex--;


  Dsp_u8CurrReqSecIndex = u8SecIndex;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;

  /*! IF security Level not found */
  if(bSecLevFound == FALSE)
  {
    /*! Set u8NegRespCode to DCM_E_SUBFUNCTIONNOTSUPPORTED  */
    u8NegRespCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;

    /*! Set Check Failed flag to TRUE. */
    bCheckFailed = TRUE;

  }
  /*! END IF*/


  /*! IF check failed flag is FALSE and the request is "requestSeed" */
  if((bCheckFailed == FALSE) && (u8ReqType == (uint8)1))
  {
    /*! IF Seed is calculated before THEN */
    if(Dsp_bSeedCalc == TRUE)
    {
      /*! Set check failed flag to TRUE. */
        bCheckFailed = TRUE;

        /*! Set u8NegRespCode to DCM_E_REQUESTSEQUENCEERROR  */
        u8NegRespCode = DCM_E_REQUESTSEQUENCEERROR;

    }

#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON && \
    DCM_bPSA_SPECIFIC_CONF == STD_ON)
    /*! IF Check Failed Flag equal to FALSE THEN*/
    if(bCheckFailed == FALSE)
    {
      /*! Call bSupplIndicCheck */
      bCheckFailed = bSupplIndicCheck(u8SEC_ACCESS_SID,pMsgContext,&u8ApplNegCode);

      /*! If bSupplIndicCheck returned TRUE THEN */
      if(bCheckFailed == TRUE)
      {
        /*! Set u8NegRespCode with the error code returned by bSupplIndicCheck*/
        u8NegRespCode = u8ApplNegCode;
      }

    }
    /*! ENDIF */
#endif
    

    /*! IF the check failed flag is FALSE and the request message length
     *   not equal to 1 + DcmDspSecurityADRSize */
    if((bCheckFailed == FALSE) && (pMsgContext->reqDataLen != ((uint32)1 +
                                                    u32AdrSize)))
    {
      /*! Set check failed flag to TRUE. */
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT  */
      u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

    }


    /* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /* PRQA S 3138 ++                                                         */
    SchM_Enter_Dcm_Access_002();

    /* PRQA S 3141 --                                                         */
    /* PRQA S 3138 --                                                         */
    /*! If Check Failed is FALSE and  DelayOnBootTimer is not Active OR
     *      NumAttDelayTimer is Active. */
    if((bCheckFailed == FALSE) && ((Dsp_au16DelayOnBootTimer[u8SecIndex] != 0)||
                                 (Dsp_u16NumAttDelayTimer != 0)))
    {
      /*! Set check failed flag to TRUE. */
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode to 0x37 (requiredTimeDelayNotExpoired  */
      u8NegRespCode = u8NR_DELAY_NOT_EXP;

    }
/* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
/*              during integration phase                                    */
/* PRQA S 3141 ++                                                           */
/* PRQA S 3138 ++                                                           */
    SchM_Exit_Dcm_Access_002();
/* PRQA S 3141 --                                                           */
/* PRQA S 3138 --                                                           */

    /*! IF check failed flag is FALSE THEN */
    if(bCheckFailed == FALSE)
    {
      /*! IF current security level equals the
       *   requested security level THEN
       */
      if(u8CurrSecLevel == u8ReqSecLevel)
      {
        /*! - Set resData[0] to securityAccessType.*/
        pMsgContext->resData[0] = u8SecAccessType;

        /*! - Set the securitySeed to Zero.*/
        for( u32SeedIndex=1 ; (u32SeedIndex < (u32SeedSize+(uint32)1)) ;
            u32SeedIndex++)
        {
          pMsgContext->resData[u32SeedIndex] = 0;

        }
        /*! - Set resDataLen to 1+DcmDspSecuritySeedSize.*/
        pMsgContext->resDataLen = (uint32)1 + u32SeedSize;


      }
      /*! ELSE */
      else
      {
        /*! IF DcmDspSecurityADRSize equals Zero THEN*/
        if(u32AdrSize == (uint32)0)
        {
          /*! - Call GetSeed with the Following parameters :
           *      SecurityAccessDataRecord = NULL_PTR,
           *      OpStatus = DCM_INITIAL
           *      Seed = &resData[1]
           *      ErrorCode = &u8NegRespCode */
          u8ReturnGetSeed = (*Dcm_kstreDspConfig.strDcmDspSecurity.
                             akstrDcmDspSecurityRow[u8SecIndex].
                             pfu8GetSeed)(NULL_PTR,
                                          DCM_INITIAL,
                                          &pMsgContext->resData[1],
                                          &u8NegRespCode);
        }
        /*! ELSE */
        else
        {
          /*! - Call GetSeed with the Following parameters :
           *      SecurityAccessDataRecord = &reqData[1],
           *      OpStatus = DCM_INITIAL
           *      Seed = &resData[1]
           *      ErrorCode = &u8NegRespCode */
          u8ReturnGetSeed = (*Dcm_kstreDspConfig.strDcmDspSecurity.
                              akstrDcmDspSecurityRow[u8SecIndex].
              pfu8GetSeed)(&pMsgContext->reqData[1],
                           DCM_INITIAL,
                           &pMsgContext->resData[1],
                           &u8NegRespCode);
        }
        /*! - Set resDataLen to 1 + SeedSize.*/
        pMsgContext->resDataLen = (uint32)1 +  u32SeedSize;


        /*!  - Set resData[0] to securityAccessType. */
        pMsgContext->resData[0] = u8SecAccessType;

        /*! IF GetSeed returns E_OK THEN */
        if(u8ReturnGetSeed == E_OK)
        {
          /*! Set Seed Calculated flag to TRUE. */
          Dsp_bSeedCalc = TRUE;

        }
        /*! ELSE IF GetSeed returns E_PENDING THEN*/
        else if(u8ReturnGetSeed == E_PENDING)
        {

          /*! Set Dsp SubStatus to u8SUB_SA_GET_SEED_PEND */
          DspInternal_au8eSubStatus[u8Context] = u8SUB_SA_GET_SEED_PEND;


          /*! Set Dsp Status to u8MAIN_SA_PEND. */
          u8InternalMainStatus = u8MAIN_SA_PEND;

        }
        /*! ELSE */
        else
        {
          /*! Set Check Failed flag to TRUE.*/
          bCheckFailed = TRUE;

        }
      }
    }
  }

  /*! IF check failed flag is FALSE and the request is "sendKey" */
  if((bCheckFailed == FALSE) && (u8ReqType == (uint8)0))
  {
    /*! IF a previous requestSeed is Received THEN */
    if(Dsp_bSeedCalc == FALSE)
    {
      /*! Set Check Failed to TRUE. */
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode to DCM_E_REQUESTSEQUENCEERROR*/
      u8NegRespCode = DCM_E_REQUESTSEQUENCEERROR;

    }
#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON && \
    DCM_bPSA_SPECIFIC_CONF == STD_ON)
    /*! IF Check Failed Flag equal to FALSE THEN*/
    if(bCheckFailed == FALSE)
    {
      /*! Call bSupplIndicCheck */
      bCheckFailed = bSupplIndicCheck(u8SEC_ACCESS_SID,pMsgContext,&u8ApplNegCode);

      /*! If bSupplIndicCheck returned TRUE THEN */
      if(bCheckFailed == TRUE)
      {
        /*! Set u8NegRespCode with the error code returned by bSupplIndicCheck*/
        u8NegRespCode = u8ApplNegCode;
      }

    }
    /*! ENDIF */
#endif


    /*! IF Check Failed is TRUE and the request length not equal to
     *   1 + KeySize THEN
     */
    if((bCheckFailed == FALSE) && (pMsgContext->reqDataLen !=
                              ((uint32)1 + u32KeySize)))
    {
      /*! Set Check Failed to TRUE. */
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT*/
      u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

    }

    /*! IF check failed is FALSE THEN */
    if(bCheckFailed == FALSE)
    {
      /*! IF set Seed calculated flag to FALSE THEN */
      Dsp_bSeedCalc = FALSE;

      /*! Call CompareKey with the following parameters:
       *  Key = &reqData[1]
       *  OpStatus = DCM_INITIAL
       */
      u8ReturnCompareKey = (*Dcm_kstreDspConfig.strDcmDspSecurity.
          akstrDcmDspSecurityRow[u8SecIndex].
          pfu8CompareKey)(&pMsgContext->reqData[1],
                           DCM_INITIAL);

      /*! Set resDataLen to 1 */
      pMsgContext->resDataLen = (Dcm_MsgLenType)1;

      /*! Set resData[0] to SecAccessType*/
      pMsgContext->resData[0] = u8SecAccessType;

      /*! IF CompareKey returns E_OK*/
      if(u8ReturnCompareKey == E_OK )
      {
        /*! Reset the Number of failed attempts to Zero. */
        Dsp_au8NumOfAttempts[u8SecIndex] = 0;

        /*! Set the New Security Level by calling DslInternal_SetSecurityLevel*/
        DslInternal_SetSecurityLevel(u8ReqSecLevel);

      }
      /*! ELSE IF CompareKey returns E_PENDING */
      else if(u8ReturnCompareKey == E_PENDING)
      {

        /*! Set the Dsp Substatus to u8SUB_SA_COMPARE_PEND*/
        DspInternal_au8eSubStatus[u8Context] = u8SUB_SA_COMPARE_PEND;


        /*! Set the Dsp Status to u8MAIN_SA_PEND. */
        u8InternalMainStatus = u8MAIN_SA_PEND;

      }
      /*! ELSE */
      else
      {
        /*! Set check failed flag is TRUE */
        bCheckFailed = TRUE;

        /*! Set u8NegRespCode to 0x35(invalidKey) */
        u8NegRespCode = u8NR_INVALID_KEY;

        /*! Increment the Number of false attempts. */
        Dsp_au8NumOfAttempts[u8SecIndex]++;

        /*! If Number of False attempts is greater than or equal
         *    configuration parameter DcmDspSecurityNumAttDelay THEN
         */
        if(Dsp_au8NumOfAttempts[u8SecIndex] >= Dcm_kstreDspConfig.
            strDcmDspSecurity.akstrDcmDspSecurityRow[u8SecIndex].
            u8DcmDspSecurityNumAttDelay)
        {
          /*! Set the Number of False attempts to Zero. */
          Dsp_au8NumOfAttempts[u8SecIndex] = 0;

/* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
/*              during integration phase                                    */
/* PRQA S 3141 ++                                                           */
/* PRQA S 3138 ++                                                           */

          SchM_Enter_Dcm_Access_002();
/* PRQA S 3141 --                                                           */
/* PRQA S 3138 --                                                           */
          /*! Set NumAttDelayTimer with configuration parameter
           *  DcmDspSecurityDelayTime.
           */
          Dsp_u16NumAttDelayTimer = Dcm_kstreDspConfig.
                                    strDcmDspSecurity.
                                    akstrDcmDspSecurityRow[u8SecIndex].
                                    u16DcmDspSecurityDelayTime;
/* !Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
/*              during integration phase                                    */
/* PRQA S 3141 ++                                                           */
/* PRQA S 3138 ++                                                           */
          SchM_Exit_Dcm_Access_002();
/* PRQA S 3141 --                                                           */
/* PRQA S 3138 --                                                           */

          /*! Set u8NegRespCode to 0x36.*/
          u8NegRespCode = u8NR_EXC_NUM_OF_ATT;

        }
      }
    }
  }

  if(u8InternalMainStatus == DspInternal_u8IDLE)
  {
    /*! If check Failed Flag is TRUE */
    if(bCheckFailed == TRUE)
    {
      /*! Call DsdInternal_SetNegResponse*/
      DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
    }

    /*! Call DsdInternal_ProcessingDone*/
    DsdInternal_ProcessingDone(pMsgContext);

  }
  else
  {
    DspInternal_au8eStatus[u8Context] = u8InternalMainStatus;

  }

}
/* PRQA S 4700 --                                                             */
#endif


#if(DCM_bCDTCI_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS ClearDiagnosticInformation (0x14) service.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-0970(0),CDD-0971(0),CDD-0219(0),CDD-0220(0),CDD-0005(0),
                CDD-0006(0),CDD-0007(0),CDD-# DSP-0020(0)
*******************************************************************************/
FUNC(void,DCM_CODE) DspInternal_ClearDiagnosticInformation(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{
  uint32                       u32Dtc;
  Dem_ReturnClearDTCType       udtClearResult;
  Dcm_NegativeResponseCodeType u8NegRespCode = 0;
  uint8                        u8InternalMainStatus = DspInternal_u8IDLE;
  uint8                        u8Context;


  u8Context = pMsgContext->idContext;
  DspInternal_apstreMsgContext[u8Context] = pMsgContext;


  /*! Set Local variable u8NegRespCode to Zero.
   *  Set the DspInternal_apstreMsgContext for the received idContext to pMsgContext.
   *  IF reqDataLen equals 3 THEN
   *    - Get the groupOfDtc from the request message where groupOfDtc :
   *      high byte is reqData[0].
   *      Middle byte is reqData[1].
   *      Low byte is  reqData[2].
   *    - Call Rte_Call_DcmIf_ClearDTC with parameters :
   *       DTC: groupOfDTC from the service request
   *       DTCKind: DEM_DTC_KIND_ALL_DTCS
   *       DTCOrigin: DEM_DTC_ORIGIN_PRIMARY_MEMORY
   *    IF Rte_Call_DcmIf_ClearDTC returns DEM_CLEAR_OK THEN
   *      - Set resDataLen to Zero.
   *    ELSE IF the function returns DEM_CLEAR_PENDING THEN
   *      - Set Dsp_u32CdiDtc with the groupOfDTC.
   *      - Set the Main Context DSP status to u8MAIN_CDI_PEND.
   *
   *    ELSE If the function returns DEM_CLEAR_WRONG_DTC THEN
   *      - Set u8NegRespCode to DCM_E_REQUESTOUTOFRANGE.
   *    ELSE
   *      - Set u8NegRespCode to DCM_E_CONDITIONSNOTCORRECT.
   *
   *    END IF
   *
   *  ELSE
   *    - set u8NegRespCode to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT.
   *
   *  END IF
   *  IF the DSP Status equal to DspInternal_u8IDLE THEN
   *    IF u8NegRespCode not equal to Zero THEN
   *      - Call DsdInternal_SetNegResponse.
   *    END IF
   *
   *    Call DsdInternal_ProcessingDone.
   *
   *  END IF
   */

  
  if (pMsgContext->reqDataLen == (Dcm_MsgLenType)u8CDTCI_REQ_LEN)
  {
    u32Dtc = ((((uint32)pMsgContext->reqData[0]) << 16) |
              (((uint32)pMsgContext->reqData[1]) << 8) |
               ((uint32)pMsgContext->reqData[2]));

    udtClearResult = Rte_Call_DcmIf_ClearDTC(u32Dtc,
                                             DEM_DTC_KIND_ALL_DTCS,
                                             DEM_DTC_ORIGIN_PRIMARY_MEMORY);

    if(udtClearResult == DEM_CLEAR_OK)
    {
      pMsgContext->resDataLen = (Dcm_MsgLenType)u8CDTCI_RES_LEN;

    }
    else if(udtClearResult == DEM_CLEAR_PENDING)
    {
      Dsp_u32CdiDtc = u32Dtc;

      u8InternalMainStatus = u8MAIN_CDI_PEND;

    }
    else if(udtClearResult == DEM_CLEAR_WRONG_DTC)
    {
      u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
      u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;
    }

  }
  else
  {
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

  }

  if(u8InternalMainStatus == DspInternal_u8IDLE)
  {

    if(u8NegRespCode != 0)
    {
      DsdInternal_SetNegResponse(DspInternal_apstreMsgContext[u8Context],
        u8NegRespCode);

    }
    DsdInternal_ProcessingDone(DspInternal_apstreMsgContext[u8Context]);
  }
  else
  {
    DspInternal_au8eStatus[u8Context] = u8InternalMainStatus;

  }

}
#endif

#if(DCM_bCOMM_CONTROL_EN == STD_ON)

FUNC(Std_ReturnType,DCM_CODE) Dcm_EnableRxTxNormModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_ENABLE_RX_TX_NORM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}

FUNC(Std_ReturnType,DCM_CODE) Dcm_EnableRxDisableTxNormModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_ENABLE_RX_DISABLE_TX_NORM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}

FUNC(Std_ReturnType,DCM_CODE) Dcm_DisableRxDisableTxNormalModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_DISABLE_RX_TX_NORMAL;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}

FUNC(Std_ReturnType,DCM_CODE) Dcm_EnableRxTxNmModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_ENABLE_RX_TX_NM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}

FUNC(Std_ReturnType,DCM_CODE) Dcm_EnableRxDisableTxNmModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_ENABLE_RX_DISABLE_TX_NM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}

FUNC(Std_ReturnType,DCM_CODE) Dcm_DisableRxDisableTxNmModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_DISABLE_RX_TX_NM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}


FUNC(Std_ReturnType,DCM_CODE) Dcm_EnableRxTxNormNmModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_ENABLE_RX_TX_NORM_NM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}

FUNC(Std_ReturnType,DCM_CODE) Dcm_EnableRxDisableTxNormNmModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_ENABLE_RX_DISABLE_TX_NORM_NM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}

FUNC(Std_ReturnType,DCM_CODE) Dcm_DisableRxDisableTxNormNmModeEntry(void)
{
  Std_ReturnType u8Return = E_OK;
#if (DCM_DEV_ERROR_DETECT == STD_ON)
  if(Dcm_beInitDone == FALSE)
  {
    Det_ReportError(DCM_MODULE_ID,Dcm_u8INSTANCE_ID,
        Dcm_u8MODE_ENTRY, DCM_E_UNINIT);
    u8Return = E_NOT_OK;

  }
  else
  {
#endif

    Dsp_u8RequestedCommMode = DCM_DISABLE_RX_TX_NORM_NM;

#if (DCM_DEV_ERROR_DETECT == STD_ON)
  }
#endif
  return u8Return;

}



/******************************************************************************/
/*! \Description Implements the UDS CommunicationControl (0x28) service.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To    CDD-1100(0),CDD-1101(0),CDD-1102(0),CDD-1103(0),CDD-1104(0),
                 CDD-0052(0),CDD-0053(0),CDD-0216(0),CDD-0054(0),CDD-0055(0),
                 CDD-0056(0),CDD-0217(0) \n\n
*******************************************************************************/
FUNC(void,DCM_CODE)  DspInternal_CommunicationControl(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{

  Dcm_NegativeResponseCodeType u8NegRespCode = 0;
  Dcm_CommunicationModeType udtCommMode;
  uint8 u8CommTypeLowTwoBits = pMsgContext->reqData[1]& 0x03;
  uint8 u8CommTypeHighNibble = pMsgContext->reqData[1]& 0xF0;
  uint8 u8NetworkId;

  /*! IF the reqDataLen equals 2 THEN

   *    IF controlType(reqData[0]) equals enableRxAndTx(0)THEN
   *      IF communicationType(reqData[1]) least two bits equals
   *          1 (normalCommunicationMessages) THEN
   *      - Set Local variable udtCommMode to DCM_ENABLE_RX_TX_NORM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          2 (networkManagementCommunicationMessages)THEN
   *      - Set Local variable udtCommMode to DCM_ENABLE_RX_TX_NM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          3 (networkManagementCommunicationMessages and
                 normalCommunicationMessages ) THEN
   *      - Set Local variable udtCommMode to DCM_ENABLE_RX_TX_NORM_NM.
   *      ELSE
   *      - set the negative response code to DCM_E_REQUESTOUTOFRANGE.


   *    ELSE IF controlType equals enableRxAndDisableTx(1)THEN
   *      IF communicationType(reqData[1]) least two bits equals
   *          1 (normalCommunicationMessages) THEN
   *      - Set Local variable udtCommMode to DCM_ENABLE_RX_DISABLE_TX_NORM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          2 (networkManagementCommunicationMessages)THEN
   *      - Set Local variable udtCommMode to DCM_ENABLE_RX_DISABLE_TX_NM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          3 (networkManagementCommunicationMessages and
                 normalCommunicationMessages ) THEN
   *      - Set Local variable udtCommMode to DCM_ENABLE_RX_DISABLE_TX_NORM_NM.
   *      ELSE
   *      - set the negative response code to DCM_E_REQUESTOUTOFRANGE.

   *    ELSE IF controlType equals disableRxAndEnableTx(2)THEN
   *      IF communicationType(reqData[1]) least two bits equals
   *          1 (normalCommunicationMessages) THEN
   *      - Set Local variable udtCommMode to DCM_DISABLE_RX_ENABLE_TX_NORM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          2 (networkManagementCommunicationMessages)THEN
   *      - Set Local variable udtCommMode to DCM_DISABLE_RX_ENABLE_TX_NM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          3 (networkManagementCommunicationMessages and
                 normalCommunicationMessages ) THEN
   *      - Set Local variable udtCommMode to DCM_DISABLE_RX_ENABLE_TX_NORM_NM.
   *      ELSE
   *      - set the negative response code to DCM_E_REQUESTOUTOFRANGE.


   *    ELSE IF controlType equals disableRxAndTx (3)THEN

   *      IF communicationType(reqData[1]) least two bits equals
   *          1 (normalCommunicationMessages) THEN
   *      - Set Local variable udtCommMode to DCM_DISABLE_RX_TX_NORM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          2 (networkManagementCommunicationMessages)THEN
   *      - Set Local variable udtCommMode to DCM_DISABLE_RX_TX_NM.
   *      ELSE IF communicationType(reqData[1]) least two bits equals
   *          3 (networkManagementCommunicationMessages and
                 normalCommunicationMessages ) THEN
   *      - Set Local variable udtCommMode to DCM_DISABLE_RX_TX_NORM_NM.
   *      ELSE
   *      - set the negative response code to DCM_E_REQUESTOUTOFRANGE.

   *    ELSE
   *      - set the negative response code to DCM_E_SUBFUNCTIONNOTSUPPORTED
   *    END IF

   *    IF negative response code equals Zero [as default value] THEN

   *      IF communicationType(reqData[1]) high nibble equals 0xF0 THEN
   *        - Set local variable u8NetworkId with the network which the
   *           request is received on. [DcmDslProtocolRxChannelId]
   *      ELSE
   *        - Set local variable u8NetworkId with the high nibble of the
   *          communicationType.
   *      END IF
   *      - Call BswM_Dcm_RequestCommunicationMode with u8NetworkId and
   *        udtCommMode.
   *      IF the requested mode is accepted THEN
   *        - Set the resDataLen to 1.
   *        - Set resData[0] with controlType i.e reqData[0].
   *      ELSE
   *        - Set the Negative response code to DCM_E_CONDITIONSNOTCORRECT.
   *
   *      END IF
   *
   *    END IF


   *  ELSE
   *    - set the negative response code to
   *       DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT.
   *  END IF */

  
  if (pMsgContext->reqDataLen == (Dcm_MsgLenType)u8CC_REQ_LEN)
  {
    if(pMsgContext->reqData[0] == u8CC_SUBFUNC_ERXTX)
    {

      if(u8CommTypeLowTwoBits == u8CC_NCM)
      {
        udtCommMode = DCM_ENABLE_RX_TX_NORM ;
      }
      else if(u8CommTypeLowTwoBits == u8CC_NWMCM)
      {
        udtCommMode = DCM_ENABLE_RX_TX_NM;
      }

      else if(u8CommTypeLowTwoBits == u8CC_NWMCMANCM)
      {
        udtCommMode = DCM_ENABLE_RX_TX_NORM_NM;
      }
      else
      {
        u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

      }

    }

    else if(pMsgContext->reqData[0] == u8CC_SUBFUNC_ERXDTX)
    {

      if(u8CommTypeLowTwoBits == u8CC_NCM)
      {
        udtCommMode = DCM_ENABLE_RX_DISABLE_TX_NORM ;
      }

      else if(u8CommTypeLowTwoBits == u8CC_NWMCM)
      {
        udtCommMode = DCM_ENABLE_RX_DISABLE_TX_NM;
      }

      else if(u8CommTypeLowTwoBits == u8CC_NWMCMANCM)
      {
        udtCommMode = DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
      }
      else
      {

        u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

      }
    }

    else if(pMsgContext->reqData[0] == u8CC_SUBFUNC_DRXETX)
    {

      if(u8CommTypeLowTwoBits == u8CC_NCM)
      {
        udtCommMode = DCM_DISABLE_RX_ENABLE_TX_NORM ;
      }
      else if(u8CommTypeLowTwoBits == u8CC_NWMCM)
      {
        udtCommMode = DCM_DISABLE_RX_ENABLE_TX_NM;
      }
      else if(u8CommTypeLowTwoBits == u8CC_NWMCMANCM)
      {
        udtCommMode = DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
      }
      else
      {

        u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

      }
    }

    else if(pMsgContext->reqData[0] == u8CC_SUBFUNC_DRXTX)
    {
      if(u8CommTypeLowTwoBits == u8CC_NCM)
      {
        udtCommMode = DCM_DISABLE_RX_TX_NORMAL ;
      }
      else if(u8CommTypeLowTwoBits == u8CC_NWMCM)
      {
        udtCommMode = DCM_DISABLE_RX_TX_NM;
      }
      else if(u8CommTypeLowTwoBits == u8CC_NWMCMANCM)
      {
        udtCommMode = DCM_DISABLE_RX_TX_NM;
      }
      else
      {
        u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

      }
    }
    else
    {

      u8NegRespCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }

    if(u8NegRespCode == 0)
    {
      if(u8CommTypeHighNibble == 0xF0)
      {
        u8NetworkId = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                      pkstrDcmDslProtocolRx[pMsgContext->idContext].
                      u8DcmDslProtocolRxChannelId;
      }
      else
      {
        u8NetworkId = u8CommTypeHighNibble >>4;
      }
      BswM_Dcm_RequestCommunicationMode(u8NetworkId, udtCommMode);
      if(Dsp_u8RequestedCommMode == udtCommMode)
      {
        pMsgContext->resDataLen = (Dcm_MsgLenType)u8CC_RES_LEN;
        pMsgContext->resData[0] = pMsgContext->reqData[0];

      }
      else
      {

        u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;

      }
    }
  }
  else
  {

    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

  }

  /*!  IF the negative response code not equal to zero THEN
   *    - Call DsdInternal_SetNegResponse.
   *  END IF
   *  Call DsdInternal_ProcessingDone. */
  if(u8NegRespCode != 0)
  {
    DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
  }
  DsdInternal_ProcessingDone(pMsgContext);


}

#endif

#if(DCM_bLINK_CONTROL_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS LinkControl (0x87) service.\n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To    CDD-1141(0)
*******************************************************************************/
FUNC(void,DCM_CODE)  DspInternal_LinkControl(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)
{


  Dcm_NegativeResponseCodeType u8NegRespCode = u8NEG_CODE_RCRP;


  uint8 u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                    pkstrDcmDslProtocolRx[pMsgContext->dcmRxPduId].
                    u8DcmDslProtocolIndex;

  uint8 u8TesterSourceAddr = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                    pkstrDcmDslProtocolRx[pMsgContext->dcmRxPduId].
                    u8DcmDslProtocolRxTesterSourceAddr;

  /*! Set the Negative response code to 0x78 */

  /*! Call BswM_Dcm_RequestResetMode with DCM_BOOTLOADER_RESET. */
  /*! IF the reset mode is accepted THEN */
  /*!   - Store the ProtocolId,ServiceID,SubFncId,TesterSourceAddr in the
   *      Dsp_strDscLcProgCond global variable. */
  /*!   - Set Dsp_bBootReq to TRUE. */
  /*!   - Set Dsp_udtDscLclIdContext with idContext. */
  /*! ELSE */
  /*!   set the Negative response code to DCM_E_CONDITIONSNOTCORRECT*/
  /*! END IF*/


  Dcm_u8eRequestedResetMode = DCM_NO_RESET;
  BswM_Dcm_RequestResetMode(DCM_BOOTLOADER_RESET);

  if(Dcm_u8eRequestedResetMode == DCM_BOOTLOADER_RESET)
  {
    DspInternal_au8eStatus[pMsgContext->idContext] = u8MAIN_SESS_PEND;
    DspInternal_au8eSubStatus[pMsgContext->idContext] = u8SUB_SESS_BOOT;
    Dsp_strDscLcProgCond.ProtocolId = Dcm_pkstrePbConfig->
                                      strPbDcmDslConfig.
                                      pkstrDcmDslProtocolRow[u8ProtocolIndex].
                                      u8DcmDslProtocolID;
  
    Dsp_strDscLcProgCond.Sid = u8LC_SID;
    Dsp_strDscLcProgCond.SubFncId = pMsgContext->reqData[0];
    Dsp_strDscLcProgCond.TesterSourceAddr = u8TesterSourceAddr;

  }
  else
  {
    u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;  
  }

  if(u8NegRespCode == u8NEG_CODE_RCRP)
  {
    /*! Send Response pending */
    DslInternal_vidForceRCRRP(pMsgContext->idContext);
  }
  else
  {
    DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
    DsdInternal_ProcessingDone(pMsgContext);
  } 

}
#endif

#if(DCM_bRMBA_EN == STD_ON)

/******************************************************************************/
/*! \Description Implements the UDS ReadMemoryByAddress (0x23) service. \n
    \param[in]   pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To    CDD-0026(0),CDD-0024(0),CDD-0025(0),CDD-0027(0),CDD-0029(0),
                 CDD-1086(0),CDD-1087(0),CDD-1088(0),CDD-1089(0)
*******************************************************************************/
FUNC(void,DCM_CODE)  DspInternal_ReadMemoryByAddress(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)

{

  boolean                      bSendNegResp = TRUE;
  Dcm_NegativeResponseCodeType u8NegRespCode =
                                    DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  Dcm_ReturnReadMemoryType     udtReadMemReturn;
  uint8                        u8AddrFormat;
  uint8                        u8LenFormat;
  boolean                      bMemAccessReturn;
  tstrCheckMemAccess           strMemAccess;
  uint8                        u8Context;
  uint32                       u32MemLen;


  u8Context = pMsgContext->idContext;

  if((uint32)pMsgContext->reqDataLen > 0)
  {
    /*! Extract AddressFormat */
    u8AddrFormat = pMsgContext->reqData[0] & u8ADDR_FORMAT_MASK;
    /*! Extract LengthFormat */
    u8LenFormat = (pMsgContext->reqData[0] & u8LEN_FORMAT_MASK)>>4;

    /*! Check request length */
    if((uint32)pMsgContext->reqDataLen == ((uint32)1+
      (uint32)u8AddrFormat+
      (uint32)u8LenFormat))
    {
      /*! Store the message context */
      DspInternal_apstreMsgContext[u8Context] = pMsgContext;

      /*! Check request memory range access */
      bMemAccessReturn = bCheckMemoryAccess(u8Context,
        u8READ_MEMORY,&strMemAccess);

      u32MemLen = strMemAccess.u32MemLength;
      /*! If memory access accepted */
      if(bMemAccessReturn == TRUE)
      {
        /*! If the requested Memory length is larger than the available
        buffer size */
        if(strMemAccess.u32MemLength > pMsgContext->resMaxDataLen)
        {
#if(DCM_PAGED_BUFFER_ENABLED)              

          u32MemLen = pMsgContext->resMaxDataLen;

          /*! Set PagedMode to TRUE*/
          DspInternal_abePagedMode[u8Context] = TRUE;
#else
          /*! Set the negative respons code to DCM_E_RESPONSETOOLONG*/
          u8NegRespCode = DCM_E_RESPONSETOOLONG;
#endif

        }
        if(u8NegRespCode == 0)
        {
          Dsp_u32RdMemoryAddr = strMemAccess.u32MemAddress;
          Dsp_u32RdMemoryLen = strMemAccess.u32MemLength;


          /*! Read the requested memory */
          udtReadMemReturn = Dcm_ReadMemory(0,
            strMemAccess.u32MemAddress,
            u32MemLen,
            pMsgContext->resData);
          /*! Set the Response message length */
          pMsgContext->resDataLen = (Dcm_MsgLenType)strMemAccess.u32MemLength;

          /*! If read returns OK */
          if(udtReadMemReturn == DCM_READ_OK)
          {

#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
            if(DspInternal_abePagedMode[u8Context] == TRUE)
            {
              /*! Start paged processing */
              DsdInternal_StartPagedProcessing(
                DspInternal_apstreMsgContext[u8Context]);

              Dsp_u32RdMemoryAddr   += u32MemLen;
              Dsp_u32RdMemoryLen    -= u32MemLen;
              DspInternal_abePageUpdate[u8Context] = FALSE;
              DsdInternal_ProcessPage(u8Context,u32MemLen);

              /*! Set the dsp status */
              DspInternal_au8eStatus[u8Context] = u8MAIN_RMBA;
            }
#endif               

            bSendNegResp = FALSE;

          }
          /*! Else If read is pending */
          else if(udtReadMemReturn == DCM_READ_PENDING)
          {
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
            if(DspInternal_abePagedMode[u8Context] == TRUE)
            {
              /*! Start paged processing */
              DsdInternal_StartPagedProcessing(
                DspInternal_apstreMsgContext[u8Context]);
            }
#endif
            /*! store requested Memory Address and length */
            Dsp_u32RdMemoryAddr = strMemAccess.u32MemAddress;
            Dsp_u32RdMemoryLen = strMemAccess.u32MemLength;
            /*! Set the dsp status */
            DspInternal_au8eStatus[u8Context] = u8MAIN_RMBA;

          }
          /*! Else */
          else
          {
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
            DspInternal_abePagedMode[u8Context] = FALSE;
#endif
            /*! Set the negative response code to
            * DCM_E_GENERALPROGRAMMINGFAILURE*/
            u8NegRespCode = DCM_E_GENERALPROGRAMMINGFAILURE;

          }
        }
      }
      /*! ELSE: Memory range access not accepted */
      else
      {
        /*! Set the negative response code with the code returned by
        bCheckMemoryAccess*/
        u8NegRespCode = strMemAccess.u8NegCode;
      }
    }
  }




 
  /*! If Dsp status is DspInternal_u8IDLE */
  if(DspInternal_au8eStatus[u8Context] == DspInternal_u8IDLE)
  {
    /*! If negative response to be sent */
    if(bSendNegResp == TRUE)
    {
      /*! Call DsdInternal_SetNegResponse*/
      DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
    }
    /*! Call DsdInternal_ProcessingDone*/
    DsdInternal_ProcessingDone(pMsgContext);
  }

}
#endif

#if(DCM_bWMBA_EN == STD_ON)
/******************************************************************************/
/*! \Description Implements the UDS WriteMemoryByAddress (0x3D) service. \n
    \param[in]   pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To: CDD-0158(0),CDD-0159(0),CDD-0160(0),CDD-0161(0),CDD-0162(0),
               CDD-0222(0),CDD-0165(0),CDD-0166(0),CDD-0167(0),
               CDD-1082(0),CDD-1083(0),CDD-1084(0),CDD-1085(0)

*******************************************************************************/
FUNC(void,DCM_CODE)  DspInternal_WriteMemoryByAddress(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)

{
    boolean                       bSendNegResp = TRUE;
    Dcm_NegativeResponseCodeType  u8NegRespCode =
                                    DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    Dcm_ReturnWriteMemoryType     udtWriteMemReturn;
    uint8                         u8AddrFormat;
    uint8                         u8LenFormat;
    boolean                       bMemAccessReturn;
    uint8                         u8LoopIndex;
    tstrCheckMemAccess            strMemAccess;
    uint8                         u8Context;

    u8Context = pMsgContext->idContext;

    if(pMsgContext->reqDataLen > 0)
    {

      /*! Get the Size of memoryAddress parameter */
      /*! Get the Size of memoryLength parameter */
      u8AddrFormat = pMsgContext->reqData[0] & u8ADDR_FORMAT_MASK;
      u8LenFormat = (pMsgContext->reqData[0] & u8LEN_FORMAT_MASK)>>4;

      /*! Check for the minimum request length */
      if((uint32)pMsgContext->reqDataLen == ((uint32)1+
        (uint32)u8AddrFormat+
        (uint32)u8LenFormat))
      {

        /*! Store the message context */
        DspInternal_apstreMsgContext[u8Context] = pMsgContext;

        /*! Check the Memory Access */
        bMemAccessReturn = bCheckMemoryAccess(u8Context,u8WRITE_MEMORY,
          &strMemAccess);

        /*! check that the request length is correct */
        if((uint32)pMsgContext->reqDataLen == (uint32)1 + (uint32)u8AddrFormat +
          (uint32)u8LenFormat + strMemAccess.u32MemLength)

        {
          /*! If memory write access is accepted */
          if(bMemAccessReturn == TRUE)
          {
            /*! Call Dcm_WriteMemory */
            udtWriteMemReturn = Dcm_WriteMemory(0,
              strMemAccess.u32MemAddress,
              strMemAccess.u32MemLength,
              &pMsgContext->reqData[(uint8)1 + u8AddrFormat + u8LenFormat]);

            /*! Set the response length */
            pMsgContext->resDataLen = (Dcm_MsgLenType)1 +
              (Dcm_MsgLenType)u8AddrFormat + (Dcm_MsgLenType)u8LenFormat;

            /*! Prepare the positive response */
            for(u8LoopIndex = 0 ; u8LoopIndex < (uint8)(u8AddrFormat+u8LenFormat)
              ; u8LoopIndex++)
            {
              pMsgContext->resData[u8LoopIndex] =
                pMsgContext->reqData[u8LoopIndex];
            }

            /*! If Dcm_WriteMemory returns OK*/
            if(udtWriteMemReturn == DCM_WRITE_OK)
            {
              /*! Send negative response */
              bSendNegResp = FALSE;

            }
            /*! Else IF Dcm_WriteMemory is pending */
            else if(udtWriteMemReturn == DCM_WRITE_PENDING)
            {

              /*! store requested Memory Address and length */
              Dsp_u32RdMemoryAddr = strMemAccess.u32MemAddress;
              Dsp_u32RdMemoryLen = strMemAccess.u32MemLength;

              /*! Set the Status to u8MAIN_WMBA*/
              DspInternal_au8eStatus[u8Context] = u8MAIN_WMBA;

            }
            /*! Else*/
            else
            {
              /*! Set negative response code to DCM_E_GENERALPROGRAMMINGFAILURE*/
              u8NegRespCode = DCM_E_GENERALPROGRAMMINGFAILURE;

            }
          }
          /*! Else [Memory Write access not accepted] */
          else
          {
            /*! Set the negative response code with the code returned by
            bCheckMemoryAccess*/
            u8NegRespCode = strMemAccess.u8NegCode;

          }
        }
      }
    }
    /*! If Dsp status is DspInternal_u8IDLE */
    if(DspInternal_au8eStatus[u8Context] == DspInternal_u8IDLE)
    {
      /*! If negative response to be sent */
      if(bSendNegResp == TRUE)
      {
        /*! Call DsdInternal_SetNegResponse*/
        DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
      }
      /*! Call DsdInternal_ProcessingDone*/
      DsdInternal_ProcessingDone(pMsgContext);
    }

}
#endif



#if(DCM_bREQUEST_DOWNLOAD_EN == STD_ON)

/******************************************************************************/
/*! \Description Implements the UDS RequestDownload (0x34) service. \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-1090(0),CDD-1091(0),CDD-1092(0),CDD-0112(0),CDD-0113(0),
                CDD-0114(0),CDD-0115(0),CDD-0116(0),CDD-0117(0),CDD-0118(0),
                CDD-0119(0),CDD-0120(0),CDD-0121(0),
*******************************************************************************/
FUNC(void,DCM_CODE)  DspInternal_RequestDownload(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)

{

  Dcm_NegativeResponseCodeType     u8NegRespCode = 0;
  Dcm_MsgLenType                   u32BufferSize;
  uint8                            u8RxBufferId;
  uint8                            u8ProtocolIndex;
  boolean                          bCheckFailed = FALSE;
  boolean                          bMemAccessReturn;
  tstrCheckMemAccess               strMemAccess;
  uint8                            u8Context;

  u8Context = pMsgContext->idContext;

  DspInternal_apstreMsgContext[u8Context] = pMsgContext;

  /*! If Request Download session is Active */
  if(Dsp_bReqDownOk == TRUE)
  {
    /*! Set Check Failed flag to TRUE.*/
    bCheckFailed = TRUE;

    /*! Set u8NegRespCode to DCM_E_CONDITIONSNOTCORRECT */
    u8NegRespCode = DCM_E_CONDITIONSNOTCORRECT;

  }

  /*! If the request Length is less than 4 THEN */
  if(pMsgContext->reqDataLen < (Dcm_MsgLenType)u8RD_MIN_REQ_LEN)
  {
    /*! Set Check Failed flag to TRUE.*/
    bCheckFailed = TRUE;

    /*! Set u8NegRespCode to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT*/
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

  }

  /*! If dataFormatIdentifier (reqData[0]) not equal to Zero */
  if(pMsgContext->reqData[0] != 0)
  {
    /*! Set Check Failed flag to TRUE.*/
    bCheckFailed = TRUE;
    /*! Set u8NegRespCode to DCM_E_REQUESTOUTOFRANGE*/
    u8NegRespCode = DCM_E_REQUESTOUTOFRANGE;

  }

  /*! If check failed flag is FALSE */
  if(bCheckFailed == FALSE)
  {
    /*! Call bCheckMemoryAccess with parameter u8DOWNLOAD_MEMORY*/
    bMemAccessReturn = bCheckMemoryAccess(u8Context,
                                          u8DOWNLOAD_MEMORY,&strMemAccess);

    /*! IF bMemAccessReturn returns TRUE */
    if(bMemAccessReturn == TRUE)
    {
      /*! Set Dsp_bReqDownOk to TRUE */
      Dsp_bReqDownOk = TRUE;

      /*! Set the Block sequence counter to 1 */
      Dsp_u8BlockSeqCount = (uint8)1;
      Dsp_u32RdMemoryAddr = strMemAccess.u32MemAddress;
      Dsp_u32RdMemoryLen =  strMemAccess.u32MemLength;

      /*! Get the Receive buffer Size */
      u8ProtocolIndex = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                        pkstrDcmDslProtocolRx[pMsgContext->dcmRxPduId].
                        u8DcmDslProtocolIndex;
      u8RxBufferId     = Dcm_pkstrePbConfig->strPbDcmDslConfig.
                         pkstrDcmDslProtocolRow[u8ProtocolIndex].
                         u8DcmDslProtocolRxBufferID;


      u32BufferSize    = Dcm_kstreDslConfig.astrDcmDslBuffer[u8RxBufferId].
                         udtBufferSize;

      /*! Set Request Download First Block to TRUE */
      Dsp_bRdFirstBlock = TRUE;



      /*! Set resData[0] with LengthFormatIdentifier */
      pMsgContext->resData[0] = u8RD_LEN_FORMAT_IDENT;

      /*! Set the maxNumberOfBlockLength with the size of the RX Buffer */
      pMsgContext->resData[1] = (uint8)((u32BufferSize & (uint32)0xF000)>>24);
      pMsgContext->resData[2] = (uint8)((u32BufferSize & (uint32)0x0F00)>>16);
      pMsgContext->resData[3] = (uint8)((u32BufferSize & (uint32)0x00F0)>>8);
      pMsgContext->resData[4] = (uint8)(u32BufferSize & (uint32)0x000F);

      /*! Set resDataLen with 5 */
      pMsgContext->resDataLen = (Dcm_MsgLenType)u8RD_RES_LEN;

    }
    /*! ELSE */
    else
    {
      /*! Set Check Failed flag to TRUE.*/
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode with strMemAccess.u8NegCode */
      u8NegRespCode = strMemAccess.u8NegCode;
    }

  }

  /*! If Check Failed flag is TRUE */
  if(bCheckFailed == TRUE)
  {
    /*! Call DsdInternal_SetNegResponse*/
    DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
  }
  /*! DsdInternal_ProcessingDone*/
  DsdInternal_ProcessingDone(pMsgContext);


}
#endif




#if(DCM_bREQUEST_UPLOAD_EN == STD_ON ||DCM_bREQUEST_DOWNLOAD_EN == STD_ON )
/******************************************************************************/
/*! \Description Implements the UDS TransferData (0x36) service. \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-1096(0),CDD-1097(0),CDD-1098(0),CDD-1507(0),CDD-0134(0),
                CDD-0135(0),CDD-0136(0),CDD-0137(0),CDD-0138(0),CDD-0139(0),
                CDD-0140(0),CDD-0143(0),CDD-0144(0),CDD-0145(0),CDD-0146(0),
                CDD-0149(0),CDD-0150(0)
*******************************************************************************/
/* !Deviation : Inhibit rule [4700]: This function can't be simplified        */
/*              to more than one function for performance.                    */
/* PRQA S 4700 ++                                                             */
FUNC(void,DCM_CODE)  DspInternal_TransferData(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)

{
    Dcm_NegativeResponseCodeType     u8NegRespCode = 0;
    boolean                          bCheckFailed = FALSE;
    Dcm_ReturnWriteMemoryType        u8WriteMemReturn;
    uint8                            u8InternalMainStatus = DspInternal_u8IDLE;
    uint8                            u8Context;

    u8Context = pMsgContext->idContext;

    DspInternal_au8eStatus[u8Context] = DspInternal_u8IDLE;


    DspInternal_apstreMsgContext[u8Context] = pMsgContext;

    /*! If request download session is not active */
    if(Dsp_bReqDownOk == FALSE)
    {
      /*! Set Check failed flag to TRUE. */
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode with DCM_E_REQUESTSEQUENCEERROR*/
      u8NegRespCode = DCM_E_REQUESTSEQUENCEERROR;

    }

    /*! If check failed is False and the request length is less than 2 Then */
    if((bCheckFailed == FALSE) &&
        (pMsgContext->reqDataLen < (Dcm_MsgLenType)u8TD_MIN_REQ_LEN))
    {
      /*! Set Check failed flag to TRUE. */
      bCheckFailed = TRUE;

      /*! Set u8NegRespCode with DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT*/
      u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

    }

    /*! If check failed flag is FALSE */
    if(bCheckFailed == FALSE)
    {
      /*! If Request download first block is TRUE */
      if(Dsp_bRdFirstBlock == TRUE)
      {
        /*! If recieved blockSequenceCounter not equal to
         *  Dsp_u8BlockSeqCount */
        if(pMsgContext->reqData[0] != Dsp_u8BlockSeqCount)
        {
          /*! Set check failed to TRUE */
          bCheckFailed = TRUE;

          /*! Set u8NegRespCode with wrongBlockSequenceCounter 0x73 */
          u8NegRespCode = u8NR_WRONG_BS_COUNT;
        }

      }
      /*! ELSE */
      else
      {
        /*! If recieved blockSequenceCounter not equal to
         *  Dsp_u8BlockSeqCount && not equal to (Dsp_u8BlockSeqCount-1) */
        if((pMsgContext->reqData[0] != Dsp_u8BlockSeqCount) &&
            (pMsgContext->reqData[0] != (Dsp_u8BlockSeqCount-(uint8)1)))
        {
          /*! Set check failed to TRUE */
          bCheckFailed = TRUE;

          /*! Set u8NegRespCode with wrongBlockSequenceCounter 0x73 */
          u8NegRespCode = u8NR_WRONG_BS_COUNT;
        }
      }
    }


    /*! If check Failed is FALSE */
    if(bCheckFailed == FALSE)
    {
      /*! If received blockSequenceCounter equals to (Dsp_u8BlockSeqCount-1)*/
      if(pMsgContext->reqData[0] == (Dsp_u8BlockSeqCount-(uint8)1))
      {
        /*! Set resDataLen to 1 */
        pMsgContext->resDataLen = (Dcm_MsgLenType)u8TD_RES_LEN;

        /*! Set resData[0] with reqData[0] */
        pMsgContext->resData[0] = pMsgContext->reqData[0];

      }
      /*! ELSE */
      else
      {
        /*! If the remaining bytes to download equals Zero */
        if(Dsp_u32RdMemoryLen == 0)
        {
          /*! Set check failed flag to TRUE. */
          bCheckFailed = TRUE;
          /*! Set u8NegRespCode with DCM_E_REQUESTSEQUENCEERROR*/
          u8NegRespCode = DCM_E_REQUESTSEQUENCEERROR;

        }
        if((bCheckFailed == FALSE) &&
            ((pMsgContext->reqDataLen-1)>Dsp_u32RdMemoryLen))
        {
          /*! Set check failed flag to TRUE. */
          bCheckFailed = TRUE;

          /*! Set u8NegRespCode with transferDataSuspended 0x71*/
          u8NegRespCode = u8NR_TD_SUSPENDED;

        }

        /*! If check failed is FALSE */
        if(bCheckFailed == FALSE)
        {
          /*! Call Dcm_WriteMemory to write data to memory */
          u8WriteMemReturn = Dcm_WriteMemory(
                                             0,
                                             Dsp_u32RdMemoryAddr,
                                             (pMsgContext->reqDataLen-1),
                                              &pMsgContext->reqData[1]);

          /*! IF Dcm_WriteMemory returns DCM_WRITE_OK*/
          if(u8WriteMemReturn == DCM_WRITE_OK)
          {
            /*! Set Dsp_u32RdMemoryLen with the remaining bytes to download */
            Dsp_u32RdMemoryLen = Dsp_u32RdMemoryLen -
                                 (pMsgContext->reqDataLen-(uint32)1);

            /*! Set Dsp_u32RdMemoryAddr with the next address to write to */
            Dsp_u32RdMemoryAddr = Dsp_u32RdMemoryAddr +
                                 (pMsgContext->reqDataLen-(uint32)1);

            /*! set First Block to download flag to FALSE */
            Dsp_bRdFirstBlock = FALSE;

            /*! Set resDataLen to 1*/
            pMsgContext->resDataLen = (Dcm_MsgLenType)u8TD_RES_LEN;

            /*! Set resData[0] with reqData[0]*/
            pMsgContext->resData[0] = pMsgContext->reqData[0];

            /*! Dsp_u8BlockSeqCount equal 255 */
            if(Dsp_u8BlockSeqCount == (uint8)255)
            {
              /*! Set Dsp_u8BlockSeqCount to Zero */
              Dsp_u8BlockSeqCount = 0;

            }
            /*! ELSE */
            else
            {
              /*! Increment Dsp_u8BlockSeqCount*/
              Dsp_u8BlockSeqCount++;

            }
          }
          /*! ELSE IF Dcm_WriteMemory returns DCM_WRITE_PENDING */
          else if(u8WriteMemReturn == DCM_WRITE_PENDING)
          {

            /*! Set the Dsp status to u8MAIN_TRANS_DATA_PEND*/
            u8InternalMainStatus = u8MAIN_TRANS_DATA_PEND;



          }
          /*! ELSE */
          else
          {
            /*! Set check failed to TRUE */
            bCheckFailed = TRUE;

            /*! Set u8NegRespCode to DCM_E_GENERALPROGRAMMINGFAILURE*/
            u8NegRespCode = DCM_E_GENERALPROGRAMMINGFAILURE;

          }
        }
      }
    }

    if(u8InternalMainStatus == DspInternal_u8IDLE)
    {

      /*! If check Failed Flag is TRUE */
      if(bCheckFailed == TRUE)
      {
        /*! Call DsdInternal_SetNegResponse*/
        DsdInternal_SetNegResponse(pMsgContext,u8NegRespCode);
      }

      /*! Call DsdInternal_ProcessingDone*/
      DsdInternal_ProcessingDone(pMsgContext);

    }
    else
    {
      DspInternal_au8eStatus[u8Context] = u8InternalMainStatus;

    }

}
/* PRQA S 4700 --                                                             */
#endif

#if(DCM_bREQUEST_UPLOAD_EN == STD_ON ||DCM_bREQUEST_DOWNLOAD_EN == STD_ON )


/******************************************************************************/
/*! \Description Implements the UDS RequestTransferExit (0x37) service. \n
    \param[in] pMsgContext   Pointer to the MsgContext structure. \n
    \Range       NOT NULL  \n
    \return      void.
    \Trace_To : CDD-1099(0),CDD-0153(0),CDD-0154(0),CDD-0155(0),CDD-0156(0),
                CDD-0157(0)
*******************************************************************************/
FUNC(void,DCM_CODE)  DspInternal_RequestTransferExit(
    P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext)

{
  Dcm_NegativeResponseCodeType     u8NegRespCode = 0;
  boolean                          bCheckFailed = FALSE;


  /*! IF request Data Len not equal to 0 THEN */
  if(pMsgContext->reqDataLen != (Dcm_MsgLenType)u8RTE_REQ_LEN)
  {
    /*! Set Check Failed to TRUE */
    bCheckFailed = TRUE;

    /*! Set u8NegRespCode to DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT*/
    u8NegRespCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;

  }


  /*! If check failed is FALSE and request download is not active*/
  if((bCheckFailed == FALSE) && (Dsp_bReqDownOk == FALSE))
  {
    /*! Set Check Failed to TRUE */
    bCheckFailed = TRUE;

    /*! Set u8NegRespCode to DCM_E_REQUESTSEQUENCEERROR*/
    u8NegRespCode = DCM_E_REQUESTSEQUENCEERROR;

  }

  /*! If check failed is FALSE and not all bytes have been downloaded */
  if((bCheckFailed == FALSE) && (Dsp_u32RdMemoryLen != 0))
  {

    /*! Set request download session flag to FALSE */
    Dsp_bReqDownOk = FALSE;

    /*! Set Check Failed to TRUE */
    bCheckFailed = TRUE;

    /*! Set u8NegRespCode to DCM_E_REQUESTSEQUENCEERROR*/
    u8NegRespCode = DCM_E_REQUESTSEQUENCEERROR;

  }

  /*! IF Check Failed is FALSE */
  if(bCheckFailed == FALSE)
  {
    /*! Set request download session flag to FALSE */
    Dsp_bReqDownOk = FALSE;

    /*! Set resDataLen to 0 */
    pMsgContext->resDataLen = (Dcm_MsgLenType)u8RTE_RES_LEN;

  }

  /*! IF Check Failed is TRUE */
  if(bCheckFailed == TRUE)
  {
    /*! Call DsdInternal_SetNegResponse */
    DsdInternal_SetNegResponse(pMsgContext,
                               u8NegRespCode);

  }
  /*! Call DsdInternal_ProcessingDone */
  DsdInternal_ProcessingDone(pMsgContext);

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
