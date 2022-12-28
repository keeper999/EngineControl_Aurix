/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : Dcm.h                                                   */
/*                                                                            */
/* !Scope           : Public                                                  */
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
/* $Archive::   I:/PROJETS/LIBEMB/LOG/COM/DCM/LOG/Dcm.h_v                    $*/
/* $Revision::   1.6      $$Author::   lvoilmy         $$Date::   22 Nov 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef DCM_H
#define DCM_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "ComStack_Types.h"
#include "Dcm_Types.h"
#include "Rte_Dcm_Type.h"
#include "Dcm_Cfg.h"
#include "Dcm_PBcfg.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/*! \Description DCM Module Id      \n
    \Range       0x35               \n
*******************************************************************************/
#define DCM_MODULE_ID         (uint16)0x35
/******************************************************************************/
/*! \Description DCM Vendor Id      \n
    \Range       38                 \n
*******************************************************************************/
#define DCM_VENDOR_ID         (uint16)38
/******************************************************************************/
/*! \Description DCM Instance Id      \n
    \Range       0x00                 \n
*******************************************************************************/
#define Dcm_u8INSTANCE_ID     (uint8)0x00


/******************************************************************************/
/*! \Description Autosar Release Major Version      \n
    \Range       4                                  \n
*******************************************************************************/
#define DCM_AR_RELEASE_MAJOR_VERSION     (4U)
/******************************************************************************/
/*! \Description Autosar Release Minor Version      \n
    \Range       0                                  \n
*******************************************************************************/
#define DCM_AR_RELEASE_MINOR_VERSION     (0U)
/******************************************************************************/
/*! \Description Autosar Release Revision Version      \n
    \Range       2                                     \n
*******************************************************************************/
#define DCM_AR_RELEASE_REVISION_VERSION  (2U)


/******************************************************************************/
/*! \Description Software Major Version      \n
    \Range       1                           \n
*******************************************************************************/
#define DCM_SW_MAJOR_VERSION     (1U)
/******************************************************************************/
/*! \Description Software Minor Version      \n
    \Range       0                           \n
*******************************************************************************/
#define DCM_SW_MINOR_VERSION     (1U)
/******************************************************************************/
/*! \Description Software Patch Version      \n
    \Range       1                           \n
*******************************************************************************/
#define DCM_SW_PATCH_VERSION     (5U)


/******************************************************************************/
/*! \Description DET Error: Timeout      \n
    \Range       0x01                    \n
*******************************************************************************/
#define DCM_E_INTERFACE_TIMEOUT            (uint8)0x01
/******************************************************************************/
/*! \Description DET Error: Out Of Range      \n
    \Range       0x02                         \n
*******************************************************************************/
#define DCM_E_INTERFACE_VALUE_OUT_OF_RANGE (uint8)0x02
/******************************************************************************/
/*! \Description DET Error: Buffer Overflow      \n
    \Range       0x03                            \n
*******************************************************************************/
#define DCM_E_INTERFACE_BUFFER_OVERFLOW    (uint8)0x03
/******************************************************************************/
/*! \Description DET Error: Protocol Mismatch      \n
    \Range       0x04                              \n
*******************************************************************************/
#define DCM_E_INTERFACE_PROTOCOL_MISMATCH  (uint8)0x04
/******************************************************************************/
/*! \Description DET Error: Module Not Initialized      \n
    \Range       0x05      \n
*******************************************************************************/
#define DCM_E_UNINIT                       (uint8)0x05
/******************************************************************************/
/*! \Description DET Error: Invalid Input Parameter      \n
    \Range       0x06      \n
*******************************************************************************/
#define DCM_E_PARAM                        (uint8)0x06
/******************************************************************************/
/*! \Description DET Error: Null Input Pointer      \n
    \Range       0x07      \n
*******************************************************************************/
#define DCM_E_NULL_POINTER                 (uint8)0x07
/******************************************************************************/
/*! \Description DET Error: Invalid OBD Request Message      \n
    \Range       0x08      \n
*******************************************************************************/
#define DCM_u8E_OBD_INVALID_REQUEST                 (uint8)0x08


/******************************************************************************/
/*! \Description Service Id of Dcm_ComM_NoComModeEntered()      \n
    \Range       0x21      \n
*******************************************************************************/
#define Dcm_u8COMM_NO_COM_ID       (uint8)0x21
/******************************************************************************/
/*! \Description Service Id of Dcm_ComM_SilentComModeEntered()      \n
    \Range       0x22      \n
*******************************************************************************/
#define Dcm_u8COMM_SILENT_COM_ID   (uint8)0x22
/******************************************************************************/
/*! \Description Service Id of Dcm_ComM_FullComModeEntered()      \n
    \Range       0x23      \n
*******************************************************************************/
#define Dcm_u8COMM_FULL_COM_ID     (uint8)0x23
/******************************************************************************/
/*! \Description Service Id of Dcm_<Session>ModeEntry()      \n
    \Range       0x2C      \n
*******************************************************************************/
#define Dcm_u8MODE_ENTRY                        (uint8)0x2C
/******************************************************************************/
/*! \Description Service Id of Dcm_MainFunction()      \n
    \Range       0x25      \n
*******************************************************************************/
#define Dcm_u8MAIN_FUNCTION_ID                  (uint8)0x25
/******************************************************************************/
/*! \Description Service Id of Dcm_Init()      \n
    \Range       0x01      \n
*******************************************************************************/
#define Dcm_u8INIT_ID                           (uint8)0x01
/******************************************************************************/
/*! \Description Service Id of Dcm_GetSecurityLevel()      \n
    \Range       0x0d      \n
*******************************************************************************/
#define Dcm_u8GET_SECURITY_LVL_ID             (uint8)0x0d
/******************************************************************************/
/*! \Description Service Id of Dcm_GetSesCtrlType()      \n
    \Range       0x06      \n
*******************************************************************************/
#define Dcm_u8GET_SES_CTRL_TYPE_ID              (uint8)0x06
/******************************************************************************/
/*! \Description Service Id of Dcm_GetActiveProtocol()      \n
    \Range       0x0f      \n
*******************************************************************************/
#define Dcm_u8GET_ACTIVE_PRTCL_ID            (uint8)0x0f
/******************************************************************************/
/*! \Description Service Id of Dcm_ResetToDefaultSession()      \n
    \Range       0x2a      \n
*******************************************************************************/
#define Dcm_u8RST_TO_DEF_SESS_ID       (uint8)0x2a
/******************************************************************************/
/*! \Description Service Id of Dcm_GetVersionInfo()      \n
    \Range       0x24      \n
*******************************************************************************/
#define Dcm_u8GET_VERSION_INFO_ID               (uint8)0x24
/******************************************************************************/
/*! \Description Service Id of Dcm_StartOfReception()      \n
    \Range       0x00      \n
*******************************************************************************/
#define Dcm_u8START_RECEPTION_ID             (uint8)0x00
/******************************************************************************/
/*! \Description Service Id of Dcm_CopyRxData()      \n
    \Range       0x02      \n
*******************************************************************************/
#define Dcm_u8COPY_RX_DATA_ID                   (uint8)0x02
/******************************************************************************/
/*! \Description Service Id of Dcm_TpRxIndication()      \n
    \Range       0x03      \n
*******************************************************************************/
#define Dcm_u8RX_INDICATION_ID                  (uint8)0x03
/******************************************************************************/
/*! \Description Service Id of Dcm_CopyTxData()      \n
    \Range       0x04      \n
*******************************************************************************/
#define Dcm_u8COPY_TX_DATA_ID                   (uint8)0x04
/******************************************************************************/
/*! \Description Service Id of Dcm_TpTxConfirmation()      \n
    \Range       0x05      \n
*******************************************************************************/
#define Dcm_u8TX_CONFIRMATION_ID                (uint8)0x05
/******************************************************************************/
/*! \Description Service Id of DspInternal_ReadDataByIdentifier()      \n
    \Range       0x62      \n
*******************************************************************************/
#define Dcm_u8UDS_RDBI_ID         (uint8)0x62
/******************************************************************************/
/*! \Description Service Id of DspInternal_ReadDTCInformation()      \n
    \Range       0x59      \n
*******************************************************************************/
#define Dcm_u8UDS_READ_DTC_INFO_ID              (uint8)0x59
/******************************************************************************/
/*! \Description Service Id of DspInternal_InputOutputControlByIdentifier()  \n
    \Range       0x6F      \n
*******************************************************************************/
#define Dcm_u8IO_CTRL_BY_IDENT_ID           (uint8)0x6F
/******************************************************************************/
/*! \Description Service Id of DspInternal_OBDService01()  \n
    \Range       0x91      \n
*******************************************************************************/
#define Dcm_u8OBD_SERVICE_01_ID           (uint8)0x91
/******************************************************************************/
/*! \Description Service Id of DspInternal_OBDService02()  \n
    \Range       0x92      \n
*******************************************************************************/
#define Dcm_u8OBD_SERVICE_02_ID           (uint8)0x92
/******************************************************************************/
/*! \Description Service Id of DspInternal_OBDService06()  \n
    \Range       0x96      \n
*******************************************************************************/
#define Dcm_u8OBD_SERVICE_06_ID           (uint8)0x96
/******************************************************************************/
/*! \Description Service Id of DspInternal_OBDService08()  \n
    \Range       0x98      \n
*******************************************************************************/
#define Dcm_u8OBD_SERVICE_08_ID           (uint8)0x98
/******************************************************************************/
/*! \Description Service Id of DspInternal_OBDService09()  \n
    \Range       0x99      \n
*******************************************************************************/
#define Dcm_u8OBD_SERVICE_09_ID           (uint8)0x99
/******************************************************************************/
/*! \Description Service Id of DspInternal_ReadScalingDataByIdentifier()      \n
    \Range       0x59      \n
*******************************************************************************/
#define Dcm_u8UDS_READ_SCALING_ID         (uint8)0x2A

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/******** Debugging Variables   **************/
#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
/*! \Trace_To: SRS-1159(0) */
extern VAR(boolean, DCM_VAR) Dcm_beDiagnosticsActive;
#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/*! \Trace_To: SRS-1160(0) */
extern VAR(Dcm_SecLevelType, DCM_VAR) Dcm_u8eCurrSecLevel;
/*! \Trace_To: SRS-1161(0) */
extern VAR(Dcm_SesCtrlType, DCM_VAR)  Dcm_u8eCurrSesCtrl;
/*! \Trace_To: SRS-1162(0) */
extern VAR(uint8,DCM_VAR) Dcm_u8eMainProtocolID;
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3456]: Macro required by AUTOSAR. */


/* PRQA S 3456 ++ */
/* PRQA S 3459 ++ */

#if(DCM_VERSION_INFO_API == STD_ON)
/******************************************************************************/
/*! \Description Returns the version information of DCM module \n
    \return      void \n
*******************************************************************************/
#define Dcm_GetVersionInfo(\
    /*! \param versionInfo Pointer to version information of DCM module.*/\
    versionInfo)\
    do\
    {\
      (versionInfo)->moduleID = DCM_MODULE_ID;\
      (versionInfo)->sw_major_version = DCM_SW_MAJOR_VERSION;\
      (versionInfo)->sw_minor_version = DCM_SW_MINOR_VERSION;\
      (versionInfo)->sw_patch_version = DCM_SW_PATCH_VERSION;\
      (versionInfo)->vendorID         = DCM_VENDOR_ID;\
      (versionInfo)->instanceID       = Dcm_u8INSTANCE_ID;\
    }\
    while(0)

#endif

/* PRQA S 3456 -- */
/* PRQA S 3459 -- */

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define DCM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void,DCM_CODE) Dcm_MainFunction(void);

extern FUNC(void,DCM_CODE) Dcm_Init(
    P2CONST(Dcm_ConfigType,AUTOMATIC,DCM_APPL_CONST) ConfigPtr);

extern FUNC(Std_ReturnType,DCM_CODE) Dcm_GetActiveProtocol(
    P2VAR(Dcm_ProtocolType,AUTOMATIC,DCM_APPL_DATA) ActiveProtocol);

extern FUNC(Std_ReturnType,DCM_CODE) Dcm_GetSesCtrlType(
       P2VAR(Dcm_SesCtrlType,AUTOMATIC,DCM_APPL_DATA) SesCtrlType);

extern FUNC(Std_ReturnType,DCM_CODE) Dcm_GetSecurityLevel(
    P2VAR(Dcm_SecLevelType,AUTOMATIC,DCM_APPL_DATA) SecLevel);

extern FUNC(Std_ReturnType,DCM_CODE) Dcm_ResetToDefaultSession(void);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"




#endif /* DCM_H */

/*-------------------------------- end of file -------------------------------*/
