
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : Dcm_Cfg.h                                               */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VALEO                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.22     R1.0.0     AR4.0.2                                   */
/* Done by    : A.Farid                                       Date : 12/01/11 */
/* Description: - Fixed Misra Issues.                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.21     R1.0.0     AR4.0.2                                   */
/* Done by    : mmoneim                                       Date : 03/01/11 */
/* Description: - update 2 types of routine Dcm_DspRoutineInfoType and
 *                Dcm_DspRoutineType.                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.20     R1.0.0     AR4.0.2                                   */
/* Done by    : A.Farid                                       Date : 31/12/10 */
/* Description: - STD_ON/STD_OFF instead of TRUE/FALSE
                - Configured off the ROE & Periodic                           */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.19     R1.0.0     AR4.0.2                                   */
/* Done by    : A.Zakaria                                     Date : 29/12/10 */
/* Description: - Added Configuration Parameters:
                  DCM_bCOMM_CONTROL_EN,
                  DCM_bCDTCI_EN,
                  DCM_bCDTCS_EN,
                  DCM_bLINK_CONTROL_EN,
                  DCM_bECU_RESET_EN,
                  DCM_bTESTER_PRESENT_EN,
                  DCM_bSEC_ACCESS_EN,
                  DCM_bSES_CONTROL_EN,
                  DCM_bRMBA_EN,
                  DCM_bWMBA_EN,
                  DCM_bREQUEST_UPLOAD_EN,
                  DCM_bREQUEST_DOWNLOAD_EN,
                  DCM_bJUMP_TO_BOOT_EN                                        */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.12     R1.0.0     AR4.0.2                                   */
/* Done by    : A.Zakaria                                     Date : 23/12/10 */
/* Description: - Removed DCM_u8PERIODIC_REQ_MAX_DATA_LEN                     */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.11     R1.0.0     AR4.0.2                                   */
/* Done by    : A.Zakaria                                     Date : 23/12/10 */
/* Description: - Changed  Dcm_DspUploadMemoryRangeInfoType,              
                           Dcm_DspDownloadMemoryRangeInfoType,               
                           Dcm_DspReadMemoryRangeInfoType,                    
                           Dcm_DspWriteMemoryRangeInfoType to                 
                   a common type Dcm_DspMemoryRangeInfoType                   */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.10     R1.0.0     AR4.0.2                                   */
/* Done by    : A.Zakaria                                     Date : 12/12/10 */
/* Description: - Added Comments to the Code                                  */
/*              - Fixed Peer Review Bugs                                      */
/******************************************************************************/
  
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/DCM_CONFIG/DCM_GEN/Dcm_Cfg.h_v  $*/
/* $Revision::   1.24     $$Author::   pbakabad        $$Date::   May 27 2013 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/



#ifndef DCM_CFG_H
#define DCM_CFG_H


#define DCM_bNVM_USED     STD_OFF
  
#if(DCM_bNVM_USED == STD_ON)
#include "Nvm.h"
#endif



/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/*!  \Description  OBDServiceEnabled - To Enable disable OBD handling in Dcm
*******************************************************************************/
#define DCM_bOBD_SERVICES_ENABLED    STD_ON
  
/******************************************************************************/
/*!  \Description  DcmDspRoeTimerInterruptScalling :This configuration parameter 
                   is used with ResponseOnEvent service when the sub-function
                   equals onTimerInterrupt  to scale the Timer value which is 
                   present in the eventTypeRecord (in ms) parameter  in the
                   request. i.e eventTypeRecord(in ms) is multiplied by 
                   DcmDspRoeTimerInterruptScalling to get the actual timer value
*******************************************************************************/
#define DCM_u16DSP_ROE_TIMER_INTERRUPT_SCALING     (uint16)0
/******************************************************************************/
/*!  \Description  DcmDspRoeEventWindowScaling:This configuration parameter is 
                   used with ResponseOnEvent service to scale eventWindowTime 
                   (in seconds) to get the actual eventWindowTime. 
                   i.e. the eventWindowTime in the request in multiplied by 
                   DcmDspRoeEventWindowScaling to get the actual eventWindowTime
*******************************************************************************/
#define DCM_u8DSP_ROE_EVENT_WINDOW_SCALING          (uint8)0

/******************************************************************************/
/*!  \Description  DcmDevErrorDetect 
*******************************************************************************/
#define DCM_DEV_ERROR_DETECT      STD_ON

/******************************************************************************/
/*!  \Description  DcmRespondAllRequest .
*******************************************************************************/
#define DCM_RESPOND_ALL_REQUEST      STD_ON

/******************************************************************************/
/*!  \Description  DcmRequestManufacturerIndicationEnabled .
*******************************************************************************/
#define DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED     STD_ON

/******************************************************************************/
/*!  \Description  DcmRequestSupplierIndicationEnabled .
*******************************************************************************/
#define DCM_REQUEST_SUPPLIER_INDICATION_ENABLED     STD_ON

/******************************************************************************/
/*!  \Description  DcmRequestManufactureSupplierIndicationEnabled.
*******************************************************************************/
#define DCM_REQUEST_MANUF_SUPPL_INDIC_EN     STD_ON
  

/******************************************************************************/
/*!  \Description  DcmTaskTime .
*******************************************************************************/
#define DCM_TASK_TIME_IN_MS    (uint16)5

/******************************************************************************/
/*!  \Description  DcmVersionInfoApi .
*******************************************************************************/
#define DCM_VERSION_INFO_API     STD_ON
  

/******************************************************************************/
/*!  \Description  DcmPagedBufferEnabled .
*******************************************************************************/
#define DCM_PAGED_BUFFER_ENABLED      STD_OFF
  


/******************************************************************************/
/*!  \Description  Protocol Preemption Enable/Disable.
*******************************************************************************/
#define DCM_bPROT_PREEMPT_ENABLED         STD_ON

/******************************************************************************/
/*!  \Description  Periodic Transmission Enable/Disable.
*******************************************************************************/
#define DCM_bPERIODIC_TRANS_ENABLED       STD_OFF
  

/******************************************************************************/
/*!  \Description  Maximum TX buffer size
*******************************************************************************/
#define DCM_udtMAX_TX_BUFFER_SIZE         (Dcm_MsgLenType)255

/******************************************************************************/
/*! \Description  Max number of concurrent Periodic Transmission.
*******************************************************************************/
#define DCM_u8MAX_NUM_PERIODIC_TX             1

  
/******************************************************************************/
/*! \Description  Max number of periodic responses for each DID
*******************************************************************************/
#define DCM_u32PERIODIC_MAX_RESPONSES         
/******************************************************************************/
/*! \Description  The number of MainFunction calls for specifing the rate of  \n
                  reading the periodic identifiers with transmissionMode      \n
                  equals "sendAtSlowRate".
*******************************************************************************/
#define DCM_u16PERIODIC_SLOW_RATE             
/******************************************************************************/
/*! \Description  The number of MainFunction calls for specifing the rate of  \n
                  reading the periodic identifiers with transmissionMode      \n
                  equals "sendAtMediumRate".
*******************************************************************************/
#define DCM_u16PERIODIC_MEDIUM_RATE           
/******************************************************************************/
/*! \Description  The number of MainFunction calls for specifing the rate of  \n
                  reading the periodic identifiers with transmissionMode      \n
                  equals "sendAtFastRate".
*******************************************************************************/
#define DCM_u16PERIODIC_FAST_RATE             


/******************************************************************************/
/*!  \Description  Roe Enable/Disable.
*******************************************************************************/

#define DCM_bROE_ENABLED      STD_OFF
  

/******************************************************************************/
/*! \Description  Session Control Type in which a higher priority protocol is
 *                allowed to preempt a lower priority one while the later is
 *                processing a request.
*******************************************************************************/
#define DCM_udtPROT_PREEMPT_SESSION       255


/******************************************************************************/
/*! \Description  Switched on/off the inter-module version checks between DCM 
 *                and the interfaced modules.
*******************************************************************************/
#define DCM_bINTER_MOD_VER_CHECK          STD_OFF
  

#if(DCM_bROE_ENABLED == STD_ON)

#define DCM_u16DSP_ROE_MAX_QUEUE_LENGTH     0
#define DCM_u16DSP_ROE_MAX_EVENT_LENGTH     0
/* (DcmDspRoeMaxEventLength * DcmDspRoeMaxQueueLength) */
#define DCM_u16ROE_QUE_MAX_DATA_LEN         (uint16)(DCM_u16DSP_ROE_MAX_QUEUE_LENGTH * DCM_u16DSP_ROE_MAX_EVENT_LENGTH)

#endif

/******************************************************************************/
/*!  \Description  DcmPagedBufferTimeout.
*******************************************************************************/
#define DCM_PAGED_BUFFER_TIMEOUT     (uint16)(1000/DCM_TASK_TIME_IN_MS)

/*! /Description  Number of DTCs to be read synchronously per cycle.      /n */ 
/*                Used for Read DTC subfunctions of ReadDTCInformation    /n */ 
#define DCM_u16RDTC_DTC_PER_CYC         0

/*! /Description  Number of snapshot records to be read synchronously per /n */ 
/*                cycle.                                                  /n */ 
/*                Used for Read Freeze frames subfunctions of             /n */ 
/*                ReadDTCInformation                                      /n */ 
#define DCM_u8RDTC_SNAPSHOTS_PER_CYC    0

/******************************************************************************/
/*!  \Description  This Parameter enables/diables implementing a diagnostic
                    service completly using callouts [Dcm_<DiagnosticService>,
                    Dcm_Confirmation ]. This parameter has nothing to do with
                    services implemented partially using callouts like
                    ReadMemoryByAddress,WriteMemoryByAddress.
                    This parameter is set to STD_ON if configuration 
                    parameter DcmDsdServiceIsCallout is set to TRUE for any
                    service,Otherwise this parameter is set to STD_OFF.                    
*******************************************************************************/
#if (DCM_bOBD_SERVICES_ENABLED == STD_ON)

#define DCM_bOBD_SVC01_ENABLED STD_ON
  


#define DCM_bOBD_SVC02_ENABLED STD_ON
  


#define DCM_bOBD_SVC03_ENABLED STD_ON
  


#define DCM_bOBD_SVC04_ENABLED STD_ON
  


#define DCM_bOBD_SVC06_ENABLED STD_ON
  


#define DCM_bOBD_SVC07_ENABLED STD_ON
  


#define DCM_bOBD_SVC08_ENABLED STD_OFF
  


#define DCM_bOBD_SVC09_ENABLED STD_ON
  


#define DCM_bOBD_SVC0A_ENABLED STD_OFF
  


#endif

#define DCM_bDIAG_SERV_IS_CALLOUT                     STD_OFF
  
#define DCM_bPSA_SPECIFIC_CONF                        STD_ON
  


#define DCM_bROUTINE_CONTROL_ENABLED                  STD_ON
  

#define DCM_bREQUEST_CONTROL_ENABLED                  STD_OFF
  



#define DCM_bDSP_DID_ENABLED                          STD_ON
  

#define DCM_bREAD_DTC_INFO_ENABLED   STD_ON
  


#define DCM_u8NUM_OF_MANUF_INDIC                      1U

#define DCM_u8NUM_OF_SUPPL_INDIC                      1U

#define DCM_u8NUM_OF_MANUF_SUPPL_INDIC                1U

#define DCM_u8NUM_OF_CALLBACK_REQ_SERV                (uint8)1

#define DCM_u8NUM_OF_PROTOCOLS                        (uint8)2

#define DCM_u8NUMBER_OF_BUFFERS                       (uint8)2

#define DCM_u8NUM_SECURITY_LEVELS                     (uint8)1

#define DCM_u8NUM_OF_SERV_TABLE                       (uint8)2

#define DCM_u16NUM_OF_DIDS                            (uint16)282

#define DCM_u16NUM_OF_DID_INFO                        (uint16)282

#define DCM_u16NUM_OF_DATA                            (uint16)282

#define DCM_u16NUM_OF_DATA_INFO                       (uint16)282

#define DCM_u8NUM_OF_SESS_TABLE                       (uint8)1

/*! /Description  Number of DcmDspPid container */
#define DCM_u8NUM_OF_PIDS                             36U

#define DCM_u8NUM_OF_ROUTINES                         (uint8)49

#define DCM_u8NUM_OF_ROUTINES_INFO                    (uint8)49

/*! /Description  Number of DcmDspVehInfo container */ 
#define DCM_u8NUM_OF_VEHICLE_INFO                     3U

/*! /Description  Number of DcmDspTestResultObdmidTid container */ 
#define DCM_u8NUM_OBDMID                              9U

/*! /Description  Number of DcmDspRequestControl container */
#define DCM_u8NUM_RC_TIDS                             0U

#define DCM_u16DSP_ROE_BUF_SIZE                       (uint16)1

#define DCM_bDSP_ROE_INIT_ON_DSC                      STD_OFF
  

#define DCM_u16DSP_ROE_INTER_MESSAGE_TIME             (uint16)0

#define DCM_u8DSP_ROE_MAX_NUMBER_OF_RETRY             (uint8)0

#define DCM_bDSP_ROE_QUEUE_ENABLED                    STD_OFF
  


/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    CommunicationControl UDS service (0x28).
*******************************************************************************/
#define DCM_bCOMM_CONTROL_EN      STD_OFF
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    ClearDiagnosticInformation UDS service (0x14).
*******************************************************************************/
#define DCM_bCDTCI_EN             STD_ON
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    ControlDTCSetting UDS service (0x85).
*******************************************************************************/
#define DCM_bCDTCS_EN             STD_ON
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    LinkControl UDS service (0x87).
*******************************************************************************/
#define DCM_bLINK_CONTROL_EN      STD_OFF
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    EcuReset UDS service (0x11).
*******************************************************************************/
#define DCM_bECU_RESET_EN         STD_ON
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    TesterPresent UDS service (0x3E).
*******************************************************************************/
#define DCM_bTESTER_PRESENT_EN    STD_ON
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    SecurityAccess UDS service (0x27).
*******************************************************************************/
#define DCM_bSEC_ACCESS_EN        STD_ON
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    DiagnosticSessionControl UDS service (0x10).
*******************************************************************************/
#define DCM_bSES_CONTROL_EN       STD_ON
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    ReadMemoryByAddress UDS service (0x23).
*******************************************************************************/
#define DCM_bRMBA_EN              STD_OFF
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    WriteMemoryByAddress UDS service (0x3D).
*******************************************************************************/
#define DCM_bWMBA_EN              STD_OFF
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    RequestUpload UDS service (0x35).
*******************************************************************************/
#define DCM_bREQUEST_UPLOAD_EN    STD_OFF
  

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    RequestDownload UDS service (0x34).
*******************************************************************************/
#define DCM_bREQUEST_DOWNLOAD_EN  STD_OFF
  
/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    ReadDataByIdentifier UDS service (0x22).
*******************************************************************************/
#define DCM_bRDBI_EN              STD_ON
      

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    WriteDataByIdentifier UDS service (0x2E).
*******************************************************************************/
#define DCM_bWDBI_EN              STD_ON
      

/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    InputOutputControlByIdentifier UDS service (0x2F).
*******************************************************************************/
#define DCM_bIO_CONTROL_EN              STD_OFF
      
/******************************************************************************/
/*!  \Description  Enables\Disables the implementation of
                    ReadDataByPeriodicIdentifier UDS service (0x2A).
*******************************************************************************/
#define DCM_bREAD_SCALING_DATA_EN       STD_OFF
      


/******************************************************************************/
/*!  \Description  Indicates whether container DcmDspMemory 
                    is present or not.
*******************************************************************************/
#define DCM_bDSP_MEMORY_ENABLED           STD_OFF
  

#if(DCM_bDSP_MEMORY_ENABLED == STD_ON)
/******************************************************************************/
/*!  \Description  Indicates whether container DcmDspDownloadMemoryRangeInfo
                    is present or not.
*******************************************************************************/
#define DCM_bDOWNLOAD_MEMORY_RANGE_EN     STD_OFF
      

/******************************************************************************/
/*!  \Description  Indicates whether container DcmDspReadMemoryRangeInfo
                    is present or not.
*******************************************************************************/
#define DCM_bREAD_MEMORY_RANGE            STD_OFF
  

/******************************************************************************/
/*!  \Description  Indicates whether container DcmDspUploadMemoryRangeInfo
                    is present or not.
*******************************************************************************/
#define DCM_bUPLOAD_MEMORY_RANGE_EN       STD_OFF
  

/******************************************************************************/
/*!  \Description  Indicates whether container DcmDspWriteMemoryRangeInfo
                    is present or not.
*******************************************************************************/
#define DCM_bWRITE_MEMORY_RANGE_EN        STD_OFF
  

#if(DCM_bDOWNLOAD_MEMORY_RANGE_EN == STD_ON)
/******************************************************************************/
/*!  \Description  Indicates the multiplicity of container 
                    DcmDspDownloadMemoryRangeInfo.
*******************************************************************************/
#define DCM_u8NUM_DOWNLOAD_MEM_RANGE      (uint8)0

#endif


#if(DCM_bREAD_MEMORY_RANGE == STD_ON)
/******************************************************************************/
/*!  \Description  Indicates the multiplicity of container 
                    DcmDspReadMemoryRangeInfo.
*******************************************************************************/
#define DCM_u8NUM_READ_MEM_RANGE          (uint8)0
#endif

#if(DCM_bUPLOAD_MEMORY_RANGE_EN == STD_ON)
/******************************************************************************/
/*!  \Description  Indicates the multiplicity of container 
                    DcmDspUploadMemoryRangeInfo.
*******************************************************************************/
#define DCM_u8NUM_UPLOAD_MEM_RANGE        (uint8)0

#endif

#if(DCM_bWRITE_MEMORY_RANGE_EN == STD_ON)
/******************************************************************************/
/*!  \Description  Indicates the multiplicity of container 
                    DcmDspWriteMemoryRangeInfo.
*******************************************************************************/
#define DCM_u8NUM_WRITE_MEM_RANGE         (uint8)0

#endif

#endif



/******************************************************************************/
/*!  \Description  Enables\Disables the ability of the DCM to Jump to the
 Bootloader Through Services LinkControl or DiagnosticSessionControl. 
 DCM_bJUMP_TO_BOOT_EN is set to STD_ON if  DCM_bLINK_CONTROL_EN is STD_ON or
 DcmDspSessionForBoot  configuration parameters equals to DCM_OEM_BOOT
 or DCM_SYS_BOOT for any DcmDspSessionRow.
                 
*******************************************************************************/ 
#define DCM_bJUMP_TO_BOOT_EN              STD_ON
  
/*! \Description  DcmDspMaxDidToRead    */
#define DCM_u16DSP_MAX_DID_TO_READ        0U
  


#if(DCM_bRDBI_EN == STD_ON)
/*! \Description  DID defined by PSA for Max no. of DIDs in one request */
#define DCM_u16MAX_NUM_DIDS_1REQ_DID      ((uint16)0xF020)
#endif



/*! \Description  Maximum size (in bytes) for a signal inside a DID   */
#define DCM_u16DSP_MAX_DID_SIGNAL_SIZE   24U
        
/*! \Description  Number of DID signals to be read synchrously in the DSP
                  service callback before postponing the rest to the perioidic
                  task, zero value means all                                  */

#define DCM_u16DSP_SIGNALS_TO_READ_SYNC           (uint16)1

/*! \Description  Number of DID signals to be read asynchrously in the DSP
                  periodic main function every period, zero value means all   */

#define DCM_u16DSP_SIGNALS_TO_READ_IN_TASK        (uint16)2
/*! \Description  Number of DID signals to be written synchrously in the DSP
                  service callback before postponing the rest to the perioidic
                  task, zero value means all                                  */

#define DCM_u16DSP_SIGNALS_TO_WRITE_SYNC          (uint16)3

/*! \Description  Number of DID signals to be written asynchrously in the DSP
                  periodic main function every period, zero value means all   */

#define DCM_u16DSP_SIGNALS_TO_WRITE_IN_TASK       (uint16)4
/*! \Description  Number of DID signals to be controlled synchrously in the DSP
                  service callback before postponing the rest to the perioidic
                  task, zero value means all                                  */

#define DCM_u16DSP_SIGNALS_TO_CONTROL_SYNC        (uint16)5

/*! \Description  Number of DID signals to be controlled asynchrously in the DSP
                  periodic main function every period, zero value means all   */

#define DCM_u16DSP_SIGNALS_TO_CONTROL_IN_TASK     (uint16)6
/*! \Description  Number of DID signals to be returned to ECU control
                  synchrously once the S3Timeout, default session transition or
                  protocol preemption occured, before postponing the rest to the
                  perioidic task, zero value means all                        */

#define DCM_u16DSP_SIGNALS_TO_RET_CONTROL_SYNC    (uint16)7

/*! \Description  Number of DID signals to be returned to ECU control
                  asynchrously in the periodic main function every period,
                  zero value means all                                        */

#define DCM_u16DSP_SIGNALS_TO_RET_CONTROL_IN_TASK     (uint16)7
/******************************************************************************/
/* PDUID's SYMBOLS                                                            */
/******************************************************************************/


#define DCM_RX_PDUID_0     (PduIdType)0

#define DCM_RX_PDUID_1     (PduIdType)1

#define DCM_RX_PDUID_2     (PduIdType)2

#define DCM_RX_PDUID_3     (PduIdType)3

#define DCM_TX_CONF_PDUID_0     (PduIdType)0

#define DCM_TX_CONF_PDUID_1     (PduIdType)1

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/



/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef P2FUNC(void, DCM_APPL_CODE, Dcm_tpfvidFunction) (void);

/* /Description  Standard subfunctions (start/Stop) type for lookup tables */ 
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8RoutineSubfunction)(
  VAR(boolean,AUTOMATIC)                 bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)        u8OpStatus,
  P2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) pku8DataIn,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA)   pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA)   pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/* /Description  Standard subfunction (requestResult) type for lookup tables */ 
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ResultSubfunction)(
  VAR(boolean,AUTOMATIC)               bEndianConv,
  VAR(Dcm_OpStatusType,AUTOMATIC)      u8OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) pu8DataOut,
  P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) pu16DataLength,
  P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to GetSeed operation member of
                    SecurityAccess_<LEVEL> interface  \n     
*******************************************************************************/
typedef  P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8GetSeed)(
        P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) SecurityAccessDataRecord,
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Seed,
        P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to CompareKey operation member of
                    SecurityAccess_<LEVEL> interface  \n     
*******************************************************************************/
typedef  P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8CompareKey)(
            P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Key,
            Dcm_OpStatusType OpStatus);
            
/******************************************************************************/
/*!  \Description  Pointer to the Internal diagnostic service 
       DspInternal_<DiagnosticService> or callout Dcm_<DiagnosticService>. \n
*******************************************************************************/
typedef  P2FUNC(void, DCM_APPL_CODE, Dcm_tpfvidDiagServType)(
            P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_VAR) pMsgContext);

/******************************************************************************/
/*!  \Description  Pointer to Manufacturer Indication function. \n                            
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ManufIndicType)(
    uint8 SID, P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) RequestData,uint16 DataSize,
    uint8 ReqType, uint8 DcmRxPduId, 
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode );
    
/******************************************************************************/
/*!  \Description  Pointer to supplier Indication function. \n                            
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8SupplIndicType)(
    uint8 SID,
    P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) RequestData,
    uint16 DataSize,
    uint8 ReqType, uint8 DcmRxPduId, 
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode );

/******************************************************************************/
/*!  \Description  Pointer to sub-function Manufacturer supplier Indication 
                      check function. \n                            
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ManufSupplIndicType)(
    uint8 SID,
    P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) RequestData,
    uint16 DataSize,
    uint8 ReqType, uint8 DcmRxPduId, 
    P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode );

#if(DCM_bOBD_SVC08_ENABLED == STD_ON)
/******************************************************************************/
/*!  \Description  Pointer to the RequestControl operation member of the 
                      RequestControlServices_<TID> interface.  \n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8RequestControlType)(
    P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) OutBuffer,
    P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) InBuffer );
#endif

/******************************************************************************/
/*!  \Description  Pointer to the application ReadData function. \n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ReadDataFncType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data);

/******************************************************************************/
/*!  \Description  Pointer to the synchronous client server ReadData. \n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ReadDataSyncCsType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data);
   
/******************************************************************************/
/*!  \Description  Pointer to the Asynchronous client server ReadData. \n
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8ReadDataAsyncCsType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data);

/******************************************************************************/
/*!  \Description  Pointer to the Sender Receiver ReadData operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ReadDataSrType)(
   P2VAR(void,AUTOMATIC,DCM_APPL_DATA) Data);

/******************************************************************************/
/*!  \Description  Pointer to the ReadDataLength function. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ReadDataLengthFncType)(
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) DataLength);

/******************************************************************************/
/*!  \Description  Pointer to the ReadDataLength Sync operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType,
               DCM_APPL_CODE,
               Dcm_tpfu8ReadDataLengthSyncCsType)(
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) DataLength);

/******************************************************************************/
/*!  \Description  Pointer to the ReadDataLength Async operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType,
               DCM_APPL_CODE,
               Dcm_tpfu8ReadDataLengthAsyncCsType)(
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) DataLength);

/******************************************************************************/
/*!  \Description  Pointer to the ConditionCheckRead function. \n 
*******************************************************************************/   
typedef P2FUNC(Std_ReturnType,
               DCM_APPL_CODE,
               Dcm_tpfu8ConditionCheckReadFncType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the ConditionCheckRead Sync operation. \n 
*******************************************************************************/   
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8ConditionCheckReadSyncCsType)(
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the ConditionCheckRead Async function. \n 
*******************************************************************************/   
typedef P2FUNC(Std_ReturnType,
               DCM_APPL_CODE,
               Dcm_tpfu8ConditionCheckReadAsyncCsType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the fixed length WriteData function. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8WriteDataFixedFncType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data,
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Non fixed length WriteData function. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8WriteDataNotFixedFncType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the fixed length WriteData Sync operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8WriteDataFixedSyncCsType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Non fixed length WriteData Sync operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8WriteDataNotFixedSyncCsType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data,
   uint16 DataLength,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the fixed length WriteData Async operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8WriteDataFixedAsyncCsType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data,
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Non fixed length WriteData Async operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8WriteDataNotFixedAsyncCsType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the fixed length SR WriteData operation.\n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8WriteDataFixedSrType)(
    P2VAR(void,AUTOMATIC,DCM_APPL_DATA) Data);

/******************************************************************************/
/*!  \Description  Pointer to the non fixed length SR WriteData operation.\n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8WriteDataNotFixedSrType)(
uint16 DataLength,
P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Data);

/******************************************************************************/
/*!  \Description  Pointer to the GetScalingInformation operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfDspDataGetScalingInfoFncType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) ScalingInfo,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Asynch CS ReturnControlToECU operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataReturnCtrlToEcuAsyncCsType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Synch CS ReturnControlToECU operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataReturnCtrlToEcuSyncCsType)(
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the application ReturnControlToECU function. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
                                       Dcm_tpfDspDataReturnControlToEcuFncType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Async CS ResetToDefault operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataResetToDefaultAsyncCsType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Sync CS ResetToDefault operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataResetToDefaultSyncCsType)(
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the application ResetToDefault function. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataResetToDefaultFncType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Async FreezeCurrentState operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataFreezeCurrStateAsyncCsType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);
   
/******************************************************************************/
/*!  \Description  Pointer to the Sync FreezeCurrentState operation. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataFreezeCurrStateSyncCsType)(
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the application FreezeCurrentState function. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataFreezeCurrentStateFncType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Async ShortTermAdjustment operation.\n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataShortTermAdjustAsyncCsType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) ControlOptionRecord,
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Sync ShortTermAdjustment operation.\n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataShortTermAdjustSyncCsType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) ControlOptionRecord,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the application ShortTermAdjustment function.\n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfDspDataShortTermAdjustmentFncType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) ControlOptionRecord,
   Dcm_OpStatusType OpStatus,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

#if ((DCM_bOBD_SERVICES_ENABLED == STD_ON) || (DCM_bRDBI_EN == STD_ON))
   
/******************************************************************************/
/*!  \Description  Pointer to the GetInfotypeValueData operation memeber 
                  of InfotypeServices_<VEHINFODATA> interface.\n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_tpfu8ReadVehInfoType)(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) DataValueBuffer);

#endif

/******************************************************************************/
/*!  \Description  Pointer to the Start operation member of 
           RoutineServices_<ROUTINENAME> if DcmDspRoutineFixedLength is TRUE. \n 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8StartRoutineFixedType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataIn,
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataOut,  
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Start operation member of 
           RoutineServices_<ROUTINENAME> if DcmDspRoutineFixedLength is FALSE.\n                                                  
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8StartRoutineNotFixedType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataIn,
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataOut,
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) currentDataLength,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Stop operation member of 
           RoutineServices_<ROUTINENAME> if DcmDspRoutineFixedLength is TRUE. \n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8StopRoutineFixedType)(
  P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataIn,
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataOut,  
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the Stop operation member of 
           RoutineServices_<ROUTINENAME> if DcmDspRoutineFixedLength is FALSE.\n
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8StopRoutineNotFixedType)(
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataIn,
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataOut,
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) currentDataLength,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the RequestResults operation member of 
           RoutineServices_<ROUTINENAME> if DcmDspRoutineFixedLength is FALSE.\n
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,
               Dcm_tpfu8RequestResultsNotFixedType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataOut,
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) currentDataLength,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the RequestResults operation member of 
           RoutineServices_<ROUTINENAME> if DcmDspRoutineFixedLength is TRUE. \n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8RequestResultsFixedType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) dataOut,
   P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_APPL_DATA) ErrorCode);

/******************************************************************************/
/*!  \Description  Pointer to the ActivateEvent operation member of 
                      ROEServices interface. \n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfDspDidRoeActivateFncType)(
   uint8 RoeEventId,
   Dcm_RoeStateType RoeState);

#if ((DCM_bOBD_SERVICES_ENABLED == STD_ON) || (DCM_bRDBI_EN == STD_ON))
/******************************************************************************/
/*!  \Description  Pointer to the GetDTRValue operation used for 
                      OBD service $06. \n 
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfGetDTRValueType)(
   Dcm_OpStatusType OpStatus,
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) Testval,
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) Minlimit,
   P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) Maxlimit,
   P2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) Status);

#endif

/******************************************************************************/
/*!  \Description  Pointer to the IoHwAb_Dcm_<EcuSignalName> function \n 
                                                 
*******************************************************************************/
typedef P2FUNC(void, DCM_APPL_CODE, Dcm_tpfvidIoHwAbDcmType)(
   uint8 action,
   P2VAR(void,AUTOMATIC,DCM_APPL_DATA) signal);

/******************************************************************************/
/*!  \Description  Pointer to the IoHwAb_Dcm_Read<EcuSignalName> function \n 
                                                 
*******************************************************************************/
typedef P2FUNC(void, DCM_APPL_CODE, Dcm_tpfvidIoHwAbDcmReadType)(
   P2VAR(void,AUTOMATIC,DCM_APPL_DATA) signal);

/******************************************************************************/
/*!  \Description  Pointer to the StartProtocol operation member of 
                      CallbackDCMRequestServices interface. \n                       
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8StartProtocol)(
   Dcm_ProtocolType ProtocolID);

/******************************************************************************/
/*!  \Description  Pointer to the StopProtocol operation member of 
                      CallbackDCMRequestServices interface. \n                       
                                                 
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE,Dcm_tpfu8StopProtocol)(
   Dcm_ProtocolType ProtocolID);


/******************************************************************************/
/******************************************************************************/
/*******                       DSP TYPES                                *******/
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/*!  \Description Dcm_DspDataTypeType  \n
*******************************************************************************/
typedef uint8 Dcm_DspDataTypeType;
#define BOOLEAN   0
#define SINT16    1
#define SINT32    2
#define SINT8     3
#define UINT16    4
#define UINT32    5
#define UINT8     6


/******************************************************************************/
/*!  \Description Dcm_PortUsedType  \n
*******************************************************************************/
typedef uint8 Dcm_PortUsedType;
#define USE_BLOCK_ID                    0
#define USE_DATA_ASYNCH_CLIENT_SERVER   1 
#define USE_DATA_SENDER_RECEIVER        2
#define USE_DATA_SYNCH_CLIENT_SERVER    3
#define USE_ECU_SIGNAL                  4
#define USE_FNC                         5

/******************************************************************************/
/*!  \Description DcmDspSecurityRow \n
*******************************************************************************/

typedef struct
{
    /*! \Description  DcmDspSecurityLevel    \n
      \Range         1..63        \n
      \Unit          Dcm_SecLevelType   */
    
  Dcm_SecLevelType u8DcmDspSecurityLevel;
  
    /*! \Description  DcmDspSecurityADRSize    \n
      \Range         1..4294967295       \n
      \Unit          uint32   */
    
  uint32 u32DcmDspSecurityADRSize;

      /*! \Description  DcmDspSecurityDelayTime    \n
      \Range         0 .. 20000/DCM_TASK_TIME_IN_MS        \n
      \Unit          uint16   */
  uint16 u16DcmDspSecurityDelayTime;
      
    /*! \Description  DcmDspSecurityDelayTimeOnBoot    \n
      \Range         0 .. 20000/DCM_TASK_TIME_IN_MS       \n
      \Unit          uint16   */
  
  uint16 u16DcmDspSecurityDelayTimeOnBoot;
  
  /*! \Description  DcmDspSecurityKeySize    \n
      \Range          1..4294967295         \n
      \Unit          uint32   */
    
  uint32 u32DcmDspSecurityKeySize;
  
      /*! \Description  DcmDspSecurityNumAttDelay    \n
      \Range         1..255        \n
      \Unit          uint8   */
  
  uint8 u8DcmDspSecurityNumAttDelay;
  
      /*! \Description  DcmDspSecuritySeedSize    \n
      \Range         1..4294967295         \n
      \Unit          uint32   */
  
  uint32 u32DcmDspSecuritySeedSize;
 
      /*! \Description  Pointer to GetSeed operation    \n
      \Range         Not NULL         \n
      \Unit          Pointer to function   */ 
  Dcm_tpfu8GetSeed pfu8GetSeed;
 
      /*! \Description  Pointer to CompareKey operation    \n
      \Range         Not NULL         \n
      \Unit          Pointer to function   */  
  Dcm_tpfu8CompareKey pfu8CompareKey;

}Dcm_DspSecurityRowType;



/******************************************************************************/
/*!  \Description DcmDspSessionRow \n
*******************************************************************************/


typedef struct
{
   /*! \Description  DcmDspSessionForBoot    \n
      \Range         {DCM_NO_BOOT, DCM_OEM_BOOT, DCM_SYS_BOOT}   \n
      \Unit          Dcm_SessionBootType   */
    
  Dcm_SessionBootType u8DcmDspSessionForBoot;
  
   /*! \Description  DcmDspSessionLevel    \n
      \Range         {DCM_DEFAULT_SESSION,  DCM_PROGRAMMING_SESSION, 
                       DCM_EXTENDED_DIAGNOSTIC_SESSION , 
                       DCM_SAFTEY_SYSTEM_DIAGNOSTIC_SESSION, 
                       DCM_ALL_SESSION_LEVEL}      \n
      \Unit          Dcm_SesCtrlType   */
    
  Dcm_SesCtrlType      u8DcmDspSessionLevel;
  
   /*! \Description  DcmDspSessionP2ServerMax    \n
      \Range         1..1000/DCM_TASK_TIME_IN_MS         \n
      \Unit          uint16   */
    
  uint16              u16DcmDspSessionP2ServerMax;
  
   /*! \Description  DcmDspSessionP2StarServerMax    \n
      \Range         0..100000/DCM_TASK_TIME_IN_MS         \n
      \Unit          uint16   */  
    
  uint16              u16DcmDspSessionP2StarServerMax;

}Dcm_DspSessionRowType;


/******************************************************************************/
/*!  \Description Define pointer to Dcm_DspSessionRowType \n\n
  \Range       Not Null \n\n
  \Unit        Pointer to Dcm_DspSessionRowType
*******************************************************************************/

typedef P2CONST(Dcm_DspSessionRowType,TYPEDEF,DCM_APPL_CONST)
        Dcm_tpkstrDspSessionRowType;


/******************************************************************************/
/*!  \Description Define pointer to Dcm_DspSecurityRowType \n\n
  \Range       Not Null \n\n
  \Unit        Pointer to Dcm_DspSecurityRowType
*******************************************************************************/

typedef P2CONST(Dcm_DspSecurityRowType,TYPEDEF,DCM_APPL_CONST) 
        Dcm_tpkstrDspSecurityRowType;



/******************************************************************************/
/*!  \Description DcmDspSession container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  u8NumOfSessRows to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumOfSessRows;
  
   /*! \Description  Pointer to SessionRow    \n
      \Range         Not Null \n
      \Unit          Pointer to   Dcm_tpkstrDspSessionRowType */
    
  P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_APPL_CONST)
    ppkstrDcmDspSessionRowType;
}Dcm_DspSessionType;


#if(DCM_bSEC_ACCESS_EN == STD_ON)

/******************************************************************************/
/*!  \Description DcmDspSecurity container \n
*******************************************************************************/

typedef struct
{

   /*! \Description  Pointer to SecurityRow with size DCM_NUM_SECURITY_LEVELS \n
      \Range         Not Null \n
      \Unit          Pointer to   Dcm_DspSecurityRowType */
    
    
  Dcm_DspSecurityRowType akstrDcmDspSecurityRow[DCM_u8NUM_SECURITY_LEVELS];
}Dcm_DspSecurityType;

#endif

/******************************************************************************/
/*!  \Description DcmDspDataInfo container \n
*******************************************************************************/

typedef struct 
{
   /*! \Description  DcmDspDataFixedLength    \n
      \Range         0..1         \n
      \Unit          boolean   */  
    
  boolean bDcmDspDataFixedLength;
  
     /*! \Description  DcmDspDataScalingInfoSize    \n
      \Range         0..4294967295         \n
      \Unit          uint32   */  
    
  uint32 u32DcmDspDataScalingInfoSize;
} Dcm_DspDataInfoType;


/******************************************************************************/
/*!  \Description DcmDspDidRead container \n
*******************************************************************************/

typedef struct
{

   /*! \Description  u8NumofSecRef to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumofSecRef; 

   /*! \Description  u8NumOfSessRows to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumofSessRef; 
  
   /*! \Description  DcmDspDidReadSecurityLevelRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   DcmDspSecurityRowType*/    
  
  P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST) 
  ppkstrDcmDspDidReadSecurityLevelRef; 
  
   /*! \Description  DcmDspDidReadSessionRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   DcmDspSessionRowType*/    
  
  
  P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_APPL_CONST)  
  ppkstrDcmDspDidReadSessionRef; 
}Dcm_DspDidReadType;


/******************************************************************************/
/*!  \Description DcmDspDidRead container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  u8NumofSecRef to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumofSecRef;  
  
   /*! \Description  u8NumOfSessRows to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumofSessRef; 
  
   /*! \Description  DcmDspDidWriteSecurityLevelRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   DcmDspSecurityRowType*/    
    
  P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST)
    ppkstrDcmDspDidWriteSecurityLevelRef; 
  
   /*! \Description  DcmDspDidWriteSessionRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   DcmDspSessionRowType*/    
    
  P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_APPL_CONST)
    ppkstrDcmDspDidWriteSessionRef; 
}Dcm_DspDidWriteType;


/******************************************************************************/
/*!  \Description DcmDspDidControl container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspDidFreezeCurrentState    \n
      \Range         0..1         \n
      \Unit          boolean   */  
    
  boolean bDcmDspDidFreezeCurrentState;
  
   /*! \Description  DcmDspDidResetToDefault    \n
      \Range         0..1         \n
      \Unit          boolean   */  
    
  boolean bDcmDspDidResetToDefault;
   
   /*! \Description  DcmDspDidReturnControlToEcu    \n
      \Range         0..1         \n
      \Unit          boolean   */  

  boolean bDcmDspDidReturnControlToEcu;
  
   /*! \Description  DcmDspDidShortTermAdjustment    \n
      \Range         0..1         \n
      \Unit          boolean   */  

    
  boolean bDcmDspDidShortTermAdjustment;

   /*! \Description  u8NumofSecRef  to determine the number of security levels\n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumofSecRef;
  
     /*! \Description  u8NumOfSessRows to determine the number of sessions   \n
      \Range         0..31         \n
      \Unit          uint8   */  
  
  uint8 u8NumofSessRef;
  
   /*! \Description  DcmDspDidControlSecurityLevelRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSecurityRowType*/    
    
  
  P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST)
    ppkstrDcmDspDidControlSecurityLevelRef;
  
   /*! \Description  DcmDspDidControlSessionRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSessionRowType*/    
  
  P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_APPL_CONST)
    ppkstrDcmDspDidControlSessionRef;
}Dcm_DspDidControlType;


/******************************************************************************/
/*!  \Description DcmDspDidAccess container \n
*******************************************************************************/

typedef struct 
{

   /*! \Description  DcmDspDidControl   \n
      \Range         Structure        \n
      \Unit          Dcm_DspDidControlType   */  
  P2CONST(Dcm_DspDidControlType, TYPEDEF, DCM_APPL_CONST) pkstrDcmDspDidControl;

   /*! \Description  DcmDspDidRead   \n
      \Range         Structure        \n
      \Unit          Dcm_DspDidReadType   */  

  P2CONST(Dcm_DspDidReadType, TYPEDEF, DCM_APPL_CONST) pkstrDcmDspDidRead;
  
   /*! \Description  DcmDspDidWrite   \n
      \Range         Structure        \n
      \Unit          Dcm_DspDidWriteType   */   
  
  P2CONST(Dcm_DspDidWriteType, TYPEDEF, DCM_APPL_CONST) pkstrDcmDspDidWrite; 

}Dcm_DspDidAccessType;


/******************************************************************************/
/*!  \Description DcmDspDidInfo container \n
*******************************************************************************/

typedef struct 
{
   /*! \Description  DcmDspDidDynamicallyDefined    \n
      \Range         0..1         \n
      \Unit          boolean   */  
  boolean              bDcmDspDidDynamicallyDefined;
  
   /*! \Description  DcmDspDidAccess   \n
      \Range         Structure        \n
      \Unit          Dcm_DspDidAccessType   */   
  Dcm_DspDidAccessType strDcmDspDidAccess;
  
}Dcm_DspDidInfoType;


/******************************************************************************/
/*!  \Description DcmDspData container \n
*******************************************************************************/

typedef struct 
{
   /*! \Description  DcmDspDataSize    \n
      \Range         0..65535         \n
      \Unit          uint16   */  
    
  uint16                          u16DcmDspDataSize;
  
  
   /*! \Description  DcmDspDataType    \n
      \Range         {BOOLEAN, SINT16, SINT32, SINT32, SINT8,
                      UINT16, UINT32, UINT8}         \n
      \Unit          Dcm_DspDataTypeType   */    
    
  Dcm_DspDataTypeType             u8DcmDspDataType;
  
   /*! \Description  DcmDspDidDynamicallyDefined    \n
      \Range         { USE_BLOCK_ID, USE_DATA_ASYNCH_CLIENT_SERVER, 
                       USE_DATA_SENDER_RECEIVER, USE_DATA_SYNCH_CLIENT_SERVER,
                       USE_ECU_SIGNAL, USE_FNC }         \n
      \Unit          Dcm_PortUsedType   */    
  
  Dcm_PortUsedType                u8DcmDspDataUsePort;
  
   /*! \Description  DcmDspDataConditionCheckReadFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */    
  
  Dcm_tpfu8ConditionCheckReadFncType pfDcmDspDataConditionCheckReadFnc;
  
   /*! \Description  DcmDspDataConditionCheckReadSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */    
  
  Dcm_tpfu8ConditionCheckReadSyncCsType pfDcmDspDataConditionCheckReadSync;
   
  /*! \Description  DcmDspDataConditionCheckReadAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */    
  
  Dcm_tpfu8ConditionCheckReadAsyncCsType pfDcmDspDataConditionCheckReadAsync;
  
  /*! \Description  DcmDspDataFreezeCurrentStateAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataFreezeCurrStateAsyncCsType
                                            pfDcmDspDataFreezeCurrentStateAsync;
  
   /*! \Description  DcmDspDataFreezeCurrentStateSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataFreezeCurrStateSyncCsType pfDcmDspDataFreezeCurrentStateSync;
  
  /*! \Description  DcmDspDataFreezeCurrentStateFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataFreezeCurrentStateFncType pfDcmDspDataFreezeCurrentStateFnc;
  
  /*! \Description  DcmDspDataGetScalingInfoFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataGetScalingInfoFncType pfDcmDspDataGetScalingInfo;
  
   /*! \Description  DcmDspDataResetToDefaultAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfDspDataResetToDefaultAsyncCsType pfDcmDspDataResetToDefaultAsync;
  
   /*! \Description  DcmDspDataResetToDefaultSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfDspDataResetToDefaultSyncCsType pfDcmDspDataResetToDefaultSync;
  
   /*! \Description  DcmDspDataResetToDefaultFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfDspDataResetToDefaultFncType pfDcmDspDataResetToDefaultFnc;
  
   /*! \Description  DcmDspDataReturnControlToEcuAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataReturnCtrlToEcuAsyncCsType
                                            pfDcmDspDataReturnControlToEcuAsync;
  
   /*! \Description  DcmDspDataReturnControlToEcuSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataReturnCtrlToEcuSyncCsType pfDcmDspDataReturnControlToEcuSync;
  
   /*! \Description  DcmDspDataReturnControlToEcuFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataReturnControlToEcuFncType pfDcmDspDataReturnControlToEcuFnc;
  
   /*! \Description  DcmDspDataShortTermAdjustmentAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataShortTermAdjustAsyncCsType
                                           pfDcmDspDataShortTermAdjustmentAsync;
  
   /*! \Description  DcmDspDataShortTermAdjustmentSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataShortTermAdjustSyncCsType
                                            pfDcmDspDataShortTermAdjustmentSync;

  /*! \Description  DcmDspDataShortTermAdjustmentFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */       
  
  Dcm_tpfDspDataShortTermAdjustmentFncType pfDcmDspDataShortTermAdjustmentFnc;
 
  /*! \Description  DcmDspDataReadDataLengthFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8ReadDataLengthFncType     pfDcmDspDataReadDataLengthFnc;
  
  /*! \Description  DcmDspDataReadDataLengthSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8ReadDataLengthSyncCsType     pfDcmDspDataReadDataLengthSync;
  
  /*! \Description  DcmDspDataReadDataLengthAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8ReadDataLengthAsyncCsType     pfDcmDspDataReadDataLengthAsync;
  
   /*! \Description  DcmDspDataReadAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8ReadDataAsyncCsType    pfDcmDspDataReadAsync;
  
   /*! \Description  DcmDspDataReadSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8ReadDataSyncCsType     pfDcmDspDataReadSync;
  
   /*! \Description  DcmDspDataRead Sender/Receiver port    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8ReadDataSrType         pfDcmDspDataReadSr;
  
   /*! \Description  DcmDspDataReadEcuSignal    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfvidIoHwAbDcmReadType     pfDcmDspDataReadEcuSignal;

   /*! \Description  DcmDspDataReadFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8ReadDataFncType        pfDcmDspDataReadFnc;

   /*! \Description  DcmDspDataWriteFixedFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8WriteDataFixedFncType     pfDcmDspDataWriteFixedFnc;
  
   /*! \Description  DcmDspDataWriteNotFixedFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8WriteDataNotFixedFncType  pfDcmDspDataWriteNotFixedFnc;
  
   /*! \Description  DcmDspDataWriteFixedSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8WriteDataFixedSyncCsType     pfDcmDspDataWriteFixedSync;
  
   /*! \Description  DcmDspDataWriteNotFixedSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8WriteDataNotFixedSyncCsType  pfDcmDspDataWriteNotFixedSync;
  
     /*! \Description  DcmDspDataWriteFixedAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8WriteDataFixedAsyncCsType     pfDcmDspDataWriteFixedAsync;
  
   /*! \Description  DcmDspDataWriteNotFixedAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8WriteDataNotFixedAsyncCsType  pfDcmDspDataWriteNotFixedAsync;
  
  /*! \Description  DcmDspDataWriteFixed Sender/Receiver port   \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8WriteDataFixedSrType        pfDcmDspDataWriteFixedSr;
  
  /*! \Description  DcmDspDataWriteNotFixed Sender/Receiver port   \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8WriteDataNotFixedSrType        pfDcmDspDataWriteNotFixedSr;

#if(DCM_bNVM_USED == STD_ON)
   /*! \Description  DcmDspDataBlockIdRef    \n
      \Range         0..65535        \n
      \Unit          NvM_BlockIdType   */    

  NvM_BlockIdType                 udtDcmDspDataBlockIdRef; 
#endif
  
   /*! \Description  DcmDspDataInfoRef    \n
      \Range         Not Null       \n
      \Unit          Pointer to Dcm_DspDataInfoType    */    
  
  P2CONST(Dcm_DspDataInfoType,TYPEDEF,DCM_APPL_CONST) pkstrDcmDspDataInfoRef;
  
   /*! \Description  DcmDspDataEcuSignal    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */   
  
  Dcm_tpfvidIoHwAbDcmType     pfDcmDspDataEcuSignal;
} Dcm_DspDataType;


/******************************************************************************/
/*!  \Description DcmDspDidSignal container \n
*******************************************************************************/

typedef struct 
{

   /*! \Description  DcmDspDidDataPos    \n
      \Range         0..65535        \n
      \Unit          uint16   */    
    
  uint16 u16DcmDspDidDataPos;
  
   /*! \Description  DcmDspDidDataRef    \n
      \Range         0..4294967295        \n
      \Unit          uint32  */    
    
  uint32 u32DcmDspDidDataRef;
} Dcm_DspDidSignalType;


/******************************************************************************/
/*!  \Description DcmDspDidExtRoe container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspDidRoeActivateFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */   
    
  Dcm_tpfDspDidRoeActivateFncType pfDcmDspDidRoeActivateFnc;
  
   /*! \Description  DcmDspDidRoeEventId    \n
      \Range         0..255        \n
      \Unit          uint8   */    
    
  uint8 u8DcmDspDidRoeEventId;
} Dcm_DspDidExtRoeType;



/******************************************************************************/
/*!  \Description Dcm_DspDidType \n\n
  \Range       structure \n\n
  \Unit        structure
*******************************************************************************/


typedef struct Dcm_tudtDspDidType Dcm_DspDidType;

/******************************************************************************/
/*!  \Description Pointer to Dcm_DspDidType\n\n
  \Range       Not Null \n\n
  \Unit         Pointer to Dcm_DspDidType
*******************************************************************************/

typedef P2CONST(Dcm_DspDidType,TYPEDEF,DCM_APPL_CONST) Dcm_tpkstrDspDidType;


/******************************************************************************/
/*!  \Description Dcm_DspDidType container \n
*******************************************************************************/

struct Dcm_tudtDspDidType
{

   /*! \Description  DcmDspDidIdentifier    \n
      \Range         0..65535        \n
      \Unit          uint16   */   
    
  uint16 u16DcmDspDidIdentifier;
  
   /*! \Description  DcmDspDidRoeQueueEnabled    \n
      \Range         0..1        \n
      \Unit          boolean   */   

  boolean bDcmDspDidRoeQueueEnabled;
  
   /*! \Description  u8NumOfDidRef determine the number of refrenced DIDs    \n
      \Range         0..255        \n
      \Unit          uint8   */ 
    
  uint8 u8NumOfDidRef;
  

   /*! \Description  DcmDspDidRef    \n
      \Range         Not Null        \n
      \Unit          Pointer to uint16    */   
    
  P2CONST(uint16,TYPEDEF,DCM_APPL_CONST) pkstrDcmDspDidRef;
  
   /*! \Description  u8NumOfDidSignal determine the number of referenced DIDs \n
      \Range         0..255        \n
      \Unit          uint8   */ 
    
  uint8 u8NumOfDidSignal;
  
   /*! \Description  DcmDspDidSignal to refere to signals per DID    \n
      \Range         Not Null        \n
      \Unit          Pointer to Dcm_DspDidSignalType    */   
    
  P2CONST(Dcm_DspDidSignalType,TYPEDEF,DCM_APPL_CONST) pkstrDcmDspDidSignal;
  
   /*! \Description DspDidInfoRef to refere to DIDs info    \n
      \Range         Not Null        \n
      \Unit          Pointer to Dcm_DspDidInfoType    */   
    
  P2CONST(Dcm_DspDidInfoType,TYPEDEF,DCM_APPL_CONST) pkstrDspDidInfoRef;
  
   /*! \Description DcmDspDidExtRoe    \n
      \Range         Structure      \n
      \Unit          Pointer to Dcm_DspDidExtRoeType    */   
    
  Dcm_DspDidExtRoeType strDcmDspDidExtRoe;

};





/******************************************************************************/
/*!  \Description  Type of DcmDspDownloadMemoryRangeInfo,
                            DcmDspUploadedMemoryRangeInfo,
                            DcmDspReadMemoryRangeInfo,
                            DcmDspWriteMemoryRangeInfo containers \n                     
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspMemoryRangeHigh    \n
      \Range         0..4294967294        \n
      \Unit          uint32   */ 
    
  uint32 u32DcmDspMemoryRangeHigh;
  
   /*! \Description  DcmDspMemoryRangeLow    \n
      \Range         0..4294967294        \n
      \Unit          uint32   */
    
  uint32 u32DcmDspMemoryRangeLow;
  

  
   /*! \Description  u8NumOfSecRef to determine the number of security levels \n
      \Range         0..31        \n
      \Unit          uint8  */   
    
  
  uint8 u8NumOfSecRef;
  
   /*! \Description  DcmDspSecurityRow    \n
      \Range         Not Null       \n
      \Unit          Pointer to DcmDspMemoryRangeSecurityLevelRef    */  
    
  P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST)\
              ppkstrDcmDspMemoryRangeSecurityLevelRef;

} Dcm_DspMemoryRangeInfoType;


/******************************************************************************/
/*!  \Description DcmDspMemory container \n
*******************************************************************************/
#if(DCM_bDSP_MEMORY_ENABLED == STD_ON)
typedef struct
{
#if(DCM_bDOWNLOAD_MEMORY_RANGE_EN == STD_ON)
   /*! \Description  DcmDspDownloadMemoryRangeInfo    \n
      \Range         Not Null       \n
      \Unit          Pointer to Dcm_DspDownloadMemoryRangeInfoType    */  
    
  Dcm_DspMemoryRangeInfoType
    astrDcmDspDownloadMemoryRangeInfo[DCM_u8NUM_DOWNLOAD_MEM_RANGE];
#endif
  
#if(DCM_bREAD_MEMORY_RANGE == STD_ON)
   /*! \Description  DcmDspReadMemoryRangeInfo    \n
      \Range         Not Null       \n
      \Unit          Pointer to Dcm_DspReadMemoryRangeInfoType    */  
    
  Dcm_DspMemoryRangeInfoType 
    astrDcmDspReadMemoryRangeInfo[DCM_u8NUM_READ_MEM_RANGE];
#endif
  
#if(DCM_bUPLOAD_MEMORY_RANGE_EN == STD_ON)  
   /*! \Description  DcmDspUploadMemoryRangeInfo    \n
      \Range         Not Null       \n
      \Unit          Pointer to Dcm_DspUploadMemoryRangeInfoType    */  
    
  Dcm_DspMemoryRangeInfoType 
    astrDcmDspUploadMemoryRangeInfo[DCM_u8NUM_UPLOAD_MEM_RANGE];
#endif
  
#if(DCM_bWRITE_MEMORY_RANGE_EN == STD_ON)
   /*! \Description  DcmDspWriteMemoryRangeInfo    \n
      \Range         Not Null       \n
      \Unit          Pointer to Dcm_DspWriteMemoryRangeInfoType    */  
    
  Dcm_DspMemoryRangeInfoType 
    astrDcmDspWriteMemoryRangeInfo[DCM_u8NUM_WRITE_MEM_RANGE];
#endif
  


} Dcm_DspMemoryType;

#endif





/******************************************************************************/
/*!  \Description DcmDspPidService01 container \n
*******************************************************************************/

typedef struct
{

   /*! \Description  DcmDspPidDataUsePort    \n
      \Range         0..1         \n
      \Unit          USE_DATA_ASYNCH_CLIENT_SERVER,
                     USE_DATA_SENDER_RECEIVE, 
                     USE_DATA_SYNCH_CLIENT_SERVER,
                     USE_FNC  */     
  Dcm_PortUsedType                u8DcmDspPidDataUsePort;


  /*! \Description  DcmDspDataReadAsync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8ReadDataAsyncCsType    pfDcmDspDataReadAsync;
  
   /*! \Description  DcmDspDataReadSync    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8ReadDataSyncCsType     pfDcmDspDataReadSync;
  
   /*! \Description  DcmDspDataRead Sender/Receiver port    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */         
  
  Dcm_tpfu8ReadDataSrType         pfDcmDspDataReadSr;


   /*! \Description  DcmDspDataReadFnc    \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */        
  
  Dcm_tpfu8ReadDataSyncCsType        pfDcmDspDataReadFnc;

} Dcm_DspPidService01Type;

/******************************************************************************/
/*!  \Description DcmDspPidSupportInfo container \n
*******************************************************************************/


typedef struct
{
  
   /*! \Description  DcmDspPidSupportInfoPos    \n
      \Range         0..255         \n
      \Unit          uint8 */   

  uint8 u8DcmDspPidSupportInfoPos;

} Dcm_DspPidSupportInfoType;


/******************************************************************************/
/*!  \Description DcmDspPidDataSupportInfo container \n
*******************************************************************************/





/******************************************************************************/
/*!  \Description Dcm_DspPidSupportedServiceType \n\n
  \Range       {DCM_SERVICE_01, DCM_SERVICE_01_02, DCM_SERVICE_02} \n\n
  \Unit        uint8
*******************************************************************************/

typedef uint8 Dcm_DspPidSupportedServiceType;
#define DCM_SERVICE_01 0x00
#define DCM_SERVICE_01_02 0x01
#define DCM_SERVICE_02 0x02


/******************************************************************************/
/*!  \Description DcmDspPidData container \n
*******************************************************************************/

typedef struct
{

   /*! \Description  DcmDspPidDataPos    \n
      \Range         0..2040          \n
      \Unit          uint16 */   
    
  uint16 u16DcmDspPidDataPos;
  
   /*! \Description  DcmDspPidDataSize    \n
      \Range         0..2040          \n
      \Unit          uint16 */   
    
  uint16 u16DcmDspPidDataSize;

  /*! \Description  DcmDspPidDataType    \n
      \Range         {BOOLEAN, SINT16, SINT32, SINT32, SINT8,
                      UINT16, UINT32, UINT8}         \n
      \Unit          Dcm_DspDataTypeType   */    
    
  Dcm_DspDataTypeType            u8DcmDspPidDataType;

  
   /*! \Description  DcmDspPidService01 container   \n
      \Range         not Null          \n
      \Unit          pointer to Dcm_DspPidService01Type */  

    
  P2CONST(Dcm_DspPidService01Type,TYPEDEF,DCM_APPL_CONST)
    pkstrDcmDspPidService01;
  
  
} Dcm_DspPidDataType;


/******************************************************************************/
/*!  \Description DcmDspPid container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspPidIdentifier    \n
      \Range         0..255          \n
      \Unit          uint8 */   
    
  uint8 u8DcmDspPidIdentifier; 
  
   /*! \Description  DcmDspPidDataSize    \n
      \Range         0..255          \n
      \Unit          uint8 */   
    
  uint8 u8DcmDspPidSize;
  
   /*! \Description  u8NumOfPidData    \n
      \Range         1..255          \n
      \Unit          uint8 */   
    
  uint8 u8NumOfPidData;
  
   /*! \Description  u16NumOfPidSupportInfo    \n
      \Range         0..255          \n
      \Unit          uint8 */   
    
  uint8 u8NumOfPidSupportInfo;

    
   /*! \Description  DcmDspPidService    \n
      \Range         {DCM_SERVICE_01, DCM_SERVICE_02, DCM_SERVICE_01_02 \n
      \Unit          uint8 */    

  Dcm_DspPidSupportedServiceType u8DcmDspPidService;
  
   /*! \Description  DcmDspPidData container   \n
      \Range         Not Null          \n
      \Unit          Pointer to  Dcm_DspPidDataType*/   
    
  P2CONST(Dcm_DspPidDataType,TYPEDEF,DCM_APPL_CONST) pkstrDcmDspPidData;
  
   /*! \Description  DcmDspPidSupportInfo container   \n
      \Range         Not Null          \n
      \Unit          Pointer to  Dcm_DspPidSupportInfoType*/   
    
  P2CONST(Dcm_DspPidSupportInfoType,TYPEDEF,DCM_APPL_CONST) 
     pkstrDcmDspPidSupportInfo;

} Dcm_DspPidType;


#if(DCM_bOBD_SVC08_ENABLED == STD_ON)
/******************************************************************************/
/*!  \Description DcmDspRequestControl container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspRequestControlInBufferSize    \n
      \Range         0..4294967295          \n
      \Unit          uint32 */   
    
  uint32 u32DcmDspRequestControlInBufferSize;
  
   /*! \Description  DcmDspRequestControlOutBufferSize    \n
      \Range         0..4294967295          \n
      \Unit          uint32 */   
    
  uint32 u32DcmDspRequestControlOutBufferSize;
  
   /*! \Description  DcmDspRequestControlTestId    \n
      \Range         0..255          \n
      \Unit          uint8 */     
  
  uint8  u8DcmDspRequestControlTestId;
  
   /*! \Description  RequestControl port  \n
      \Range         Not Null          \n
      \Unit          Pointer to  function port*/      
    
  Dcm_tpfu8RequestControlType pfu8RequestControl;

} Dcm_DspRequestControlType;

#endif

/******************************************************************************/
/*!  \Description DcmDspRoutineSignal container \n
*******************************************************************************/

typedef struct
{
  /*! \Description  DcmDspRoutineSignalLength    \n
      \Range         0..65535          \n
      \Unit          uint16 */   
    
  uint16              u16DcmDspRoutineSignalLength;
  
  /*! \Description  DcmDspRoutineSignalPos    \n
      \Range         0..65535          \n
      \Unit          uint16 */   
    
  uint16               u16DcmDspRoutineSignalPos;
  
  /*! \Description  DcmDspRoutineSignalType    \n
      \Range         {BOOLEAN, SINT16, SINT32, SINT32,
                      SINT8, UINT16, UINT32, UINT8}         \n
      \Unit          uint16 */   
    
  Dcm_DspDataTypeType u8DcmDspRoutineSignalType;

} Dcm_DspRoutineSignalType;


/******************************************************************************/
/*!  \Description Dcm_tpkstrDspRoutineSignalType \n\n
  \Range       Not Null \n\n
  \Unit        Pointer to Dcm_tpkstrDspRoutineSignalType
*******************************************************************************/


typedef P2CONST(Dcm_DspRoutineSignalType,TYPEDEF,DCM_APPL_CONST) 
              Dcm_tpkstrDspRoutineSignalType;


/******************************************************************************/
/*!  \Description DcmDspRoutineSubFunc strucnture \n
*******************************************************************************/
        
typedef struct
{
  /*! \Description  u8NumOfSignals    \n
      \Range         0..255          \n
      \Unit          uint8 */   
    
  uint8 u8NumOfSignals;

  /*! \Description  DcmDspRoutineSignal  contains the signals per sub-function\n
      \Range        Not Null          \n
      \Unit          uint32 */

  P2CONST(Dcm_DspRoutineSignalType,TYPEDEF,DCM_APPL_CONST)
    pkstrDcmDspRoutineSignal;

} Dcm_DspRoutineSubFuncType;


/******************************************************************************/
/*!  \Description DcmDspRoutineAuthorization container \n
*******************************************************************************/
        
        
typedef struct
{
   /*! \Description  u8NumOfSessRows to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumOfSessRef;
  
   /*! \Description  u8NumofSecRef  to determine the number of security levels\n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumOfSecRef;
  
   /*! \Description  DcmDspRoutineSecurityLevelRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSecurityRowType*/    
    
  P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST)\
              ppkstrDcmDspRoutineSecurityLevelRef;
        
   /*! \Description  DcmDspRoutineSessionRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSessionRowType*/   
    
  P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_APPL_CONST)\
              ppkstrDcmDspRoutineSessionLevelRef;

} Dcm_DspRoutineAuthorizationType;


/******************************************************************************/
/*!  \Description DcmDspRoutineInfo container \n
*******************************************************************************/


typedef struct
{
   /*! \Description  DcmDspRoutineAuthorization     \n
      \Range        Structure    \n
      \Unit          Dcm_DspRoutineAuthorizationType*/   
    
  Dcm_DspRoutineAuthorizationType strDcmDspRoutineAuthorization;
  
   /*! \Description  DcmDspRoutineRequestResOut     \n
      \Range        NULL_PTR, NOT NULL    \n
      \Unit          Dcm_DspRoutineSubFuncType*/   
    
  P2CONST(Dcm_DspRoutineSubFuncType,TYPEDEF,DCM_APPL_CONST) 
     pstrDcmDspRoutineRequestResOut;
  
   /*! \Description  DcmDspRoutineStopIn     \n
      \Range        NULL_PTR, NOT NULL    \n
      \Unit          Dcm_DspRoutineSubFuncType*/    
    
  P2CONST(Dcm_DspRoutineSubFuncType,TYPEDEF,DCM_APPL_CONST) 
     pstrDcmDspRoutineStopIn;
  
   /*! \Description  DcmDspRoutineStopOut     \n
      \Range        NULL_PTR, NOT NULL    \n
      \Unit          Dcm_DspRoutineSubFuncType*/     
    
  P2CONST(Dcm_DspRoutineSubFuncType,TYPEDEF,DCM_APPL_CONST) 
     pstrDcmDspRoutineStopOut;
  
   /*! \Description  DcmDspStartRoutineIn     \n
      \Range        NULL_PTR, NOT NULL    \n
      \Unit          Dcm_DspRoutineSubFuncType*/   
    
  P2CONST(Dcm_DspRoutineSubFuncType,TYPEDEF,DCM_APPL_CONST) 
     pstrDcmDspStartRoutineIn;
  
   /*! \Description  DcmDspStartRoutineOut     \n
      \Range        NULL_PTR, NOT NULL    \n
      \Unit          Dcm_DspRoutineSubFuncType*/   
    
  P2CONST(Dcm_DspRoutineSubFuncType,TYPEDEF,DCM_APPL_CONST)
     pstrDcmDspStartRoutineOut;

} Dcm_DspRoutineInfoType;



/******************************************************************************/
/*!  \Description DcmDspRoutine container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspRoutineIdentifier   \n
      \Range         0..65535         \n
      \Unit          uint16   */  
    
  uint16 u16DcmDspRoutineIdentifier;
  
   /*! \Description  DcmDspRoutineFixedLength   \n
      \Range         0..1         \n
      \Unit          boolean   */  
    
  boolean bDcmDspRoutineFixedLength;

  /*! \Description  DcmDspRoutineUsePort   \n
      \Range         0..1         \n
      \Unit          boolean   */  
    
  boolean bDcmDspRoutineUsePort;
  
   /*! \Description  DcmDspRoutineInfoRef container    \n
      \Range         Not Null         \n
      \Unit          Pointer to Dcm_DspRoutineInfoType  */   
    
  P2CONST(Dcm_DspRoutineInfoType,TYPEDEF,DCM_APPL_CONST)
                                                      pkstrDcmDspRoutineInfoRef;

   /*! \Description  DcmDspRequestResultsRoutine pointer to function  \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */ 
  
  Dcm_tpfvidFunction     pfDcmDspRequestResultsRoutine;
  
   /*! \Description   DcmDspStartRoutine pointer to function   \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */   
    
  Dcm_tpfvidFunction     pfDcmDspStartRoutine;
  
   /*! \Description  DcmDspStopRoutine pointer to function  \n
      \Range         Not Null         \n
      \Unit          Pointer to function  */   
    
  Dcm_tpfvidFunction     pfDcmDspStopRoutine;

   /*! \Description  DcmDspRequestResultsRoutineSupported     \n
       \Range        TRUE, FALSE   */  
  boolean                bDcmDspRequestResultsRoutineSupported;

   /*! \Description  DcmDspStopRoutineSupported     \n
       \Range        TRUE, FALSE   */  
  boolean                bDcmDspStopRoutineSupported;

} Dcm_DspRoutineType;


#if ((DCM_bOBD_SERVICES_ENABLED == STD_ON) || (DCM_bRDBI_EN == STD_ON))

/******************************************************************************/
/*!  \Description DcmDspVehInfoData container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspVehInfoDataOrder   \n
      \Range         0..255         \n
      \Unit          uint8  */  
    
  uint8 u8DcmDspVehInfoDataOrder;
  
   /*! \Description  DcmDspVehInfoDataSize   \n
      \Range         0..255         \n
      \Unit          uint8   */  
    
  uint8 u8DcmDspVehInfoDataSize;
  
   /*! \Description  DcmDspVehInfoDataReadFnc   \n
      \Range         Not Null         \n
      \Unit          Pointer to function   */  
    
  Dcm_tpfu8ReadVehInfoType pfDcmDspVehInfoDataReadFnc;
  
   /*! \Description  DcmDspVehInfoDataUsePort   \n
      \Range         0..1         \n
      \Unit        boolean   */  
    
  boolean bDcmDspVehInfoDataUsePort; 
  /*! \Description  DcmDspVehInfoDataReadPort   \n
      \Range         Not Null         \n
      \Unit          Pointer to function   */
  Dcm_tpfu8ReadVehInfoType pfDcmDspVehInfoDataReadPort;
} Dcm_DspVehInfoDataType;


/******************************************************************************/
/*!  \Description DcmDspVehInfo container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspVehInfoDataUsePort   \n
      \Range         0..255         \n
      \Unit        uint8   */  
    
  uint8 u8DcmDspVehInfoInfoType;
  
  /*! \Description  u8NumVehInfoData   \n
      \Range        1..255       \n
      \Unit        uint8          */ 
  uint8 u8NumVehInfoData;
  /*! \Description  DcmDspVehInfoData container   \n
      \Range        Not Null        \n
      \Unit        Pointer to  Dcm_DspVehInfoDataType  */  
    
  P2CONST(Dcm_DspVehInfoDataType,TYPEDEF,DCM_APPL_CONST)
    pkstrDcmDspVehInfoData;

} Dcm_DspVehInfoType;

/******************************************************************************/
/*!  \Description DcmDspTestResultObdmidTids container \n
*******************************************************************************/

typedef struct
{
     /*! \Description  DcmDspTestResultTestId   \n
      \Range         0..255         \n
      \Unit        uint8   */
    
  uint8 u8DcmDspTestResultTestId; 

    /*! \Description  DcmDspTestResultObdmidTidUaSid   \n
      \Range         0..255         \n
      \Unit        uint8   */  
    
  uint8 u8DcmDspTestResultObdmidTidUaSid; 

   /*! \Description  GetDTRValue   \n
      \Range         Not Null         \n
      \Unit        Pointer to Function    */
    
  Dcm_tpfGetDTRValueType pfGetDTRValue;

  
}Dcm_DspTestResultObdmidTidsType; 


/******************************************************************************/
/*!  \Description DcmDspTestResultObdmidTid container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDspTestResultObdmid   \n
      \Range         0..255         \n
      \Unit        uint8   */  
    
  uint8 u8DcmDspTestResultObdmid;
  
   /*! \Description  u8NumOfTids   \n
      \Range         0..255         \n
      \Unit        uint32   */  
    
  uint8 u8NumOfTids;

   /*! \Description  DcmDspTestResultObdmidTids   \n
      \Range         NOT NULL         \n
      \Unit        Pointer to Dcm_DspTestResultObdmidTidsType  */  
    
  P2CONST(Dcm_DspTestResultObdmidTidsType,TYPEDEF,DCM_APPL_CONST)\
    pku8DcmDspTestResultObdmidTids;

}Dcm_DspTestResultObdmidTidType;



#endif

/******************************************************************************/
/*!  \Description DcmDsp pre-compiled container \n
*******************************************************************************/

typedef struct 
{
   /*! \Description  DcmDspPowerDownTime   \n
      \Range         0..255         \n
      \Unit        uint8   */

  uint8   u8DcmDspPowerDownTime;

#if(DCM_bDSP_DID_ENABLED== STD_ON)

  /*! \Description  DcmDspDid container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspDidType  */  
    
  Dcm_DspDidType   astrDcmDspDid[DCM_u16NUM_OF_DIDS ];
  
    /*! \Description  DcmDspDidInfo container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspDidInfoType  */ 
    
  Dcm_DspDidInfoType  astrDcmDspDidInfo[DCM_u16NUM_OF_DID_INFO];
 
  /*! \Description  DcmDspData container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspDataType  */ 
    
  Dcm_DspDataType  astrDcmDspData[DCM_u16NUM_OF_DATA ];

    /*! \Description  DcmDspDataInfo container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspDataInfoType  */ 
    
    
  Dcm_DspDataInfoType  astrDcmDspDataInfo[DCM_u16NUM_OF_DATA_INFO ];
#endif
#if(DCM_bDSP_MEMORY_ENABLED== STD_ON)

    /*! \Description  DcmDspMemory container   \n
      \Range         Structure       \n
      \Unit        Pointer to Dcm_DspMemoryType  */ 
    
  Dcm_DspMemoryType             strDcmDspMemory;
#endif

#if (DCM_u8NUM_OF_PIDS > 0U)
    /*! \Description  DcmDspPid container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspPidType  */ 
    
  Dcm_DspPidType                astrDcmDspPid[DCM_u8NUM_OF_PIDS];
#endif
#if(DCM_u8NUM_RC_TIDS > 0U)

    /*! \Description  DcmDspRequestControl container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspRequestControlType  */ 
    
  Dcm_DspRequestControlType     astrDcmDspRequestControl[DCM_u8NUM_RC_TIDS];
#endif

#if(DCM_bROUTINE_CONTROL_ENABLED == STD_ON)

    /*! \Description  DcmDspRoutine container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspRoutineType  */ 
    
  Dcm_DspRoutineType     astrDcmDspRoutine[DCM_u8NUM_OF_ROUTINES];
  
      /*! \Description  DcmDspRoutineInfo container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspRoutineInfoType  */ 
    
  Dcm_DspRoutineInfoType astrDcmDspRoutineInfo[DCM_u8NUM_OF_ROUTINES_INFO];
#endif

#if (DCM_u8NUM_OBDMID > 0U)
/*! \Description  DcmDspTestResultObdmidTid   reference \n
      \Range        Not Null         \n
      \Unit        Pointer to Dcm_DspTestResultObdmidTidType  */  
    
  Dcm_DspTestResultObdmidTidType astrDcmDspTestResultObdmidTid[DCM_u8NUM_OBDMID];
#endif
#if (DCM_u8NUM_OF_VEHICLE_INFO > 0U)
    /*! \Description  DcmDspVehInfo container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspVehInfoType  */ 
    
  Dcm_DspVehInfoType            astrDcmDspVehInfo[DCM_u8NUM_OF_VEHICLE_INFO];
#endif

#if(DCM_bSEC_ACCESS_EN == STD_ON)
    /*! \Description  DcmDspSecurity container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspSecurityType  */ 
    
  Dcm_DspSecurityType           strDcmDspSecurity;
#endif

      /*! \Description  DcmDspSession container   \n
      \Range         Not Null       \n
      \Unit        Pointer to Dcm_DspSessionType  */ 
    
  Dcm_DspSessionType            astrDcmDspSession[DCM_u8NUM_OF_SESS_TABLE];

} Dcm_DspType;






/******************************************************************************/
/******************************************************************************/
/*******                       DSD TYPES                                *******/
/******************************************************************************/
/******************************************************************************/



/******************************************************************************/
/*!  \Description DcmDsdSubService pre-compiled container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDsdSubServiceId    \n
      \Range         0..255       \n
      \Unit        uint8  */ 
  uint8 u8DcmDsdSubServiceId;
  
   /*! \Description  u8NumofSecRef  to determine the number of security levels\n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8 u8NumOfSecurityRef;
  
   /*! \Description  u8NumOfSessRows to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
  
  uint8 u8NumOfSessionRef;
  
   /*! \Description  DcmDsdSubServiceSecurityLevelRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSecurityRowType*/    
    
  P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST) 
    ppkstrDcmDsdSubServiceSecurityLevelRef;

   /*! \Description  DcmDsdSubServiceSessionLevelRef     \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSessionRowType*/    
    
  P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_APPL_CONST)  
    ppkstrDcmDsdSubServiceSessionLevelRef;
} Dcm_DsdSubServiceType;

/******************************************************************************/
/*!  \Description Dcm_ServAddressModeType is to identify whether the service 
                   run in physical, functional or both modes. \n\n
  \Range       {DCM_FUNC_ONLY, DCM_PHYS_ONLY, DCM_FUNC_AND_PHYS}  \n\n
  \Unit        None
*******************************************************************************/

typedef uint8 Dcm_ServAddressModeType;
#define DCM_FUNC_ONLY         0x00
#define DCM_PHYS_ONLY         0x01
#define DCM_FUNC_AND_PHYS     0x02



/******************************************************************************/
/*!  \Description DcmDsdService pre-compiled container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDsdSidTabServiceId   \n
      \Range         0..255         \n
      \Unit          uint8   */  
  uint8                     u8DcmDsdSidTabServiceId;

  
   /*! \Description  DcmDsdSidTabFnc    \n
      \Range         No Null         \n
      \Unit          uint8   */    
  Dcm_tpfvidDiagServType    pfvidDcmDsdSidTabFnc;
  
   /*! \Description  DcmDsdServAddressMode \n
      \Range         {DCM_FUNC_ONLY, DCM_PHYS_ONLY, DCM_FUNC_AND_PHYS} \n
      \Unit          uint8   */    
  Dcm_ServAddressModeType   u8DcmDsdServAddrMode;
  
   /*! \Description DcmDsdSidTabSubfuncAvail  \n
      \Range         0..1        \n
      \Unit          boolean   */  
    
  boolean                   bDcmDsdSidTabSubfuncAvail;
  
   /*! \Description DcmDsdIsCallout  \n
      \Range         0..1        \n
      \Unit          boolean   */  
    
  boolean                   bDcmDsdIsCallout;

   /*! \Description  u8NumofSecRef  to determine the number of security levels\n
      \Range         0..31         \n
      \Unit          uint8   */  
  
  uint8                     u8NumOfSecurityRef;

   /*! \Description  u8NumOfSessRows to determine the number of sessions    \n
      \Range         0..31         \n
      \Unit          uint8   */  
    
  uint8                     u8NumOfSessionRef;

   /*! \Description  u8NumOfSubServices  to determine the number Sub-Functions\n
      \Range         0..255         \n
      \Unit          uint8   */    
  
  uint8                     u8NumOfSubServices;
  
   /*! \Description  DcmDsdSidTabSecurityLevelRef      \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSecurityRowType*/  
  
  P2CONST(Dcm_tpkstrDspSecurityRowType,TYPEDEF,DCM_APPL_CONST) 
  ppkstrDcmDsdSidTabSecurityLevelRef;
  
   /*! \Description  DcmDsdSidTabSessionLevelRef      \n
      \Range        Not Null     \n
      \Unit          Pointer to   Dcm_tpkstrDspSessionRowType*/  
  
  P2CONST(Dcm_tpkstrDspSessionRowType,TYPEDEF,DCM_APPL_CONST) 
  ppkstrDcmDsdSidTabSessionLevelRef;
  
   /*! \Description  DcmDsdSubService     \n
      \Range        Not Null     \n
      \Unit          Pointer to   DcmDsdSubServiceType*/   
  
  P2CONST(Dcm_DsdSubServiceType,TYPEDEF,DCM_APPL_CONST) pkstrDcmDsdSubService;
} Dcm_DsdServiceType;


/******************************************************************************/
/*!  \Description Dcm_tpkstrDsdServiceType is a pointer to service container\n\n
  \Range      Not Null \n\n
  \Unit        Pointer to Dcm_DsdServiceType
*******************************************************************************/

typedef P2CONST(Dcm_DsdServiceType,TYPEDEF,DCM_APPL_CONST)
                                                       Dcm_tpkstrDsdServiceType;


/******************************************************************************/
/*!  \Description DcmDsdService pre-compiled container \n
*******************************************************************************/

typedef struct
{
   /*! \Description  DcmDsdSidTabId \n
      \Range         0..255         \n
      \Unit          uint8   */    
  uint8 u8DcmDsdSidTabId;
  
   /*! \Description  u8NumOfServ  to determine the number of configured services
    *                per table  \n
      \Range         0..255         \n
      \Unit          uint8   */    
    
  uint8 u8NumOfServ;
  
   /*! \Description  DcmDsdService reference    \n
      \Range        Not Null     \n
      \Unit          Pointer to   DcmDsdServiceType*/ 
    
  P2CONST(Dcm_tpkstrDsdServiceType,TYPEDEF,DCM_APPL_CONST) ppkstrDcmDsdService;
} Dcm_DsdServiceTableType;

/******************************************************************************/
/*!  \Description DcmDsdService pre-compiled container \n
*******************************************************************************/

typedef struct 
{  
   /*! \Description  DcmDsdServiceTable reference    \n
      \Range        Not Null     \n
      \Unit          Pointer to   DcmDsdServiceTable*/ 
    
  Dcm_DsdServiceTableType astrDcmDsdServiceTable[DCM_u8NUM_OF_SERV_TABLE];
} Dcm_DsdType;




/******************************************************************************/
/******************************************************************************/
/*******                       DSL TYPES                                *******/
/******************************************************************************/
/******************************************************************************/




/******************************************************************************/
/*!  \Description DcmDslBuffer container \n
*******************************************************************************/ 

typedef struct
{
  /*! \Description   Container DcmDslBuffer   \n
      \Range        NotNull        \n
      \Unit          Dcm_MsgType   */
  Dcm_MsgType    pudtBuffer;
  
  /*! \Description   Container DcmDslBuffer   \n
      \Range        8..4294967294        \n
      \Unit          Dcm_MsgLenType   */
      
  Dcm_MsgLenType udtBufferSize;
}Dcm_strDslBufferType;



/******************************************************************************/
/*!  \Description Dcm_DslProtocolRow pre-compiled container \n
*******************************************************************************/   
typedef struct 
{
  /*! \Description   DcmDslProtocolEndiannessConvEnabled   \n
      \Range        0.. 1       \n
      \Unit          boolean   */
    
  boolean bDcmDslProtocolEndiannessConvEnabled; 
  /*! \Description   DcmDslProtocolIsParallelExecutab   \n
      \Range        0.. 1       \n
      \Unit          boolean   */  
  boolean bDcmDslProtocolIsParallelExecutab; 
  
    /*! \Description   DcmDslProtocolSessionRef   \n
      \Range        0.. 1       \n
      \Unit          boolean   */  
  P2CONST(Dcm_DspSessionType,TYPEDEF,DCM_APPL_CONST)
                                                  pkstrDcmDslProtocolSessionRef;
}Dcm_PcDslProtocolRowType;


/******************************************************************************/
/*!  \Description DcmDslCbkDcmRequstService ports pre-compiled  \n
*******************************************************************************/  

typedef struct 
{
  /*! \Description   StartProtocol   \n
      \Range        Not Null        \n
      \Unit          Pointer to function   */
    
  Dcm_tpfu8StartProtocol pfu8StartProtocol;

  /*! \Description   StopProtocol   \n
      \Range        Not Null        \n
      \Unit          Pointer to function   */
  Dcm_tpfu8StopProtocol pfu8StopProtocol;

}Dcm_CallbackDcmRequestServiceType;


/******************************************************************************/
/*!  \Description DSL pre-compiled container \n
*******************************************************************************/
typedef struct
{

  /*! \Description   Container DcmDslProtocol   \n
      \Range        None        \n
      \Unit          None   */
  Dcm_PcDslProtocolRowType  astrDcmDslProtocolRow[DCM_u8NUM_OF_PROTOCOLS]; 
  
  /*! \Description   Container DcmDslBuffer    \n
      \Range        None        \n
      \Unit          None   */  
  Dcm_strDslBufferType      astrDcmDslBuffer[DCM_u8NUMBER_OF_BUFFERS];  
 
  /*! \Description   Container DcmDslCallbackDCMRequestService   \n
      \Range        None        \n
      \Unit          None   */ 
  Dcm_CallbackDcmRequestServiceType 
  astrCbkDcmRequstService[DCM_u8NUM_OF_CALLBACK_REQ_SERV]; 

#if(DCM_REQUEST_MANUFACTURER_INDICATION_ENABLED == STD_ON)
  /*! \Description   Container DcmDslServiceRequestManufacturerIndication   \n
      \Range         N/A        \n
      \Unit          None   */
  Dcm_tpfu8ManufIndicType  
    apfu8ManufIndication[DCM_u8NUM_OF_MANUF_INDIC]; 
#endif
#if(DCM_REQUEST_SUPPLIER_INDICATION_ENABLED == STD_ON)
  /*! \Description   Container DcmDslServiceRequestSupplierIndication   \n
      \Range         N/A        \n
      \Unit          None   */
  Dcm_tpfu8SupplIndicType   
    apfu8SupplierIndication[DCM_u8NUM_OF_SUPPL_INDIC]; 
#endif
#if(DCM_REQUEST_MANUF_SUPPL_INDIC_EN == STD_ON)
  /*! \Description   Container DcmDslServiceRequestManufactureSupplierIndication
   *                  - PSA added    \n
      \Range         N/A        \n
      \Unit          None   */
  Dcm_tpfu8ManufSupplIndicType
                           apfu8ManufSupplIndic[DCM_u8NUM_OF_MANUF_SUPPL_INDIC];
#endif

} Dcm_DslType;



#endif /*DCM_CFG_H*/

