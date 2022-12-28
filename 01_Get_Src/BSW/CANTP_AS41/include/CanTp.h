/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CanTp is the component between the PDU Router and the   */
/*                    CAN Interface module. The main purpose of the CanTp     */
/*                    component is to segment and reassemble CAN I-PDUs longer*/
/*                    than 8 bytes                                            */
/*                                                                            */
/* !File            : CanTp.h                                                 */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/19_CanTp/0$*/
/* $Revision::   1.14     $$Author::   mamroussy      $$Date::   Aug 24 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/*! \file CanTp.h
*
* \par
*   This file contains the APIs, symbols, and data exported by the CanTp      
    Component to the upper layer                                              */
/******************************************************************************/
#ifndef CANTP_H
#define CANTP_H


#include "CanTp_Types.h"
#include "ComStack_Types.h"
#include "CanTp_Cfg.h"
#include "CanTp_PBCfg.h"
#include "Det.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/*! \Description    CanTp Module ID according to AutoSAR Basic Software       
                    Modules List                                              \n
    \Range          35                                                        \n
*******************************************************************************/
#define CANTP_MODULE_ID                     0x23

/******************************************************************************/
/*! \Description    CanTp Instance ID                                         \n
    \Range          0                                                         \n
*******************************************************************************/
#define CANTP_INSTANCE_ID                   0x00

/******************************************************************************/
/*! \Description    Valeo ID according to AutoSAR vendors list                \n
    \Range          38                                                        \n
*******************************************************************************/
#define CANTP_VENDOR_ID                     0x26

/******************************************************************************/
/*! \Description    Autosar Release Major Version                             \n
    \Range          4                                                         \n
*******************************************************************************/
#define CANTP_AR_RELEASE_MAJOR_VERSION      (4)

/******************************************************************************/
/*! \Description    Autosar Release Minor Version                             \n
    \Range          1                                                         \n
*******************************************************************************/
#define CANTP_AR_RELEASE_MINOR_VERSION      (1)

/******************************************************************************/
/*! \Description    Autosar Release Revision Version                          \n
    \Range          2                                                         \n
*******************************************************************************/
#define CANTP_AR_RELEASE_REVISION_VERSION   (2)

/******************************************************************************/
/*! \Description    Software Major Version                                    \n
    \Range          2                                                         \n
*******************************************************************************/
#define CANTP_SW_MAJOR_VERSION              (2)

/******************************************************************************/
/*! \Description    Software Minor Version                                    \n
    \Range          0                                                         \n
*******************************************************************************/
#define CANTP_SW_MINOR_VERSION              (0)

/******************************************************************************/
/*! \Description    Software Patch Version                                    \n
    \Range          0                                                         \n
*******************************************************************************/
#define CANTP_SW_PATCH_VERSION              (1)


/******************************************************************************/
/*! \Description    CanTp_Init() Service ID                                   \n
    \Range          0x01                                                      \n
*******************************************************************************/
#define CanTp_u8INIT_ID                     0x01

/******************************************************************************/
/*! \Description    CanTp_Shutdown() Service ID                               \n
    \Range          0x02                                                      \n
*******************************************************************************/
#define CanTp_u8SHUTDOWN_ID                 0x02

/******************************************************************************/
/*! \Description    CanTp_Transmit() Service ID                               \n
    \Range          0x03                                                      \n
*******************************************************************************/
#define CanTp_u8TRANSMIT_ID                 0x03

/******************************************************************************/
/*! \Description    CanTp_MainFunction() Service ID                           \n
    \Range          0x06                                                      \n
*******************************************************************************/
#define CanTp_u8MAIN_FUNCTION_ID            0x06

/******************************************************************************/
/*! \Description    CanTp_GetVersionInfo() Service ID                         \n
    \Range          0x07                                                      \n
*******************************************************************************/
#define CanTp_u8VERSION_INFO_ID             0x07

/******************************************************************************/
/*! \Description    CanTp_CancelTransmit() Service ID                         \n
    \Range          0x08                                                      \n
*******************************************************************************/
#define CanTp_u8CANCEL_TANSMIT_ID           0x08

/******************************************************************************/
/*! \Description    CanTp_CancelReceive() Service ID                          \n
    \Range          0x09                                                      \n
*******************************************************************************/
#define CanTp_u8CANCEL_RECEIVE_ID           0x09

/******************************************************************************/
/*! \Description    CanTp_ChangeParameter() Service ID                        \n
    \Range          0x09                                                      \n
*******************************************************************************/
#define CanTp_u8CHANGE_PARAM_ID             0x0A

/******************************************************************************/
/*! \Description    CanTp_TxConfirmation() Service ID                         \n
    \Range          0x40                                                      \n
*******************************************************************************/
#define CanTp_u8TX_CONFIRMATION_ID          0x40

/******************************************************************************/
/*! \Description    CanTp_RxIndication() Service ID                           \n
    \Range          0x42                                                      \n
*******************************************************************************/
#define CanTp_u8RX_INDICATION_ID            0x42


#if (CanTp_bDEV_ERROR_DETECT == STD_ON)
/******************************************************************************/
/*! \Description    DET error code that is reported when an API is called     
                    with invalid parameters                                   \n
    \Range          0x02                                                      \n
*******************************************************************************/
#define CANTP_E_PARAM_ID                    0x02

/******************************************************************************/
/*! \Description    DET error code that is reported when an API is called     
                    with a NULL pointer                                       \n
    \Range          0x03                                                      \n
*******************************************************************************/
#define CANTP_E_PARAM_POINTER               0x03

/******************************************************************************/
/*! \Description    DET error code that is reported when an API is called     
                    while the Component is not initialized                    \n
    \Range          0x20                                                      \n
*******************************************************************************/
#define CANTP_E_UNINIT                      0x20

/******************************************************************************/
/*! \Description    DET error code that is reported when an API is called     
                    with a TxPduId that does not exist                        \n
    \Range          0x30                                                      \n
*******************************************************************************/
#define CANTP_E_INVALID_TX_ID               0x30

/******************************************************************************/
/*! \Description    DET error code that is reported when an API is called     
                    with an RxPduId that does not exist                       \n
    \Range          0x40                                                      \n
*******************************************************************************/
#define CANTP_E_INVALID_RX_ID               0x40

/******************************************************************************/
/*! \Description    DET error code that is reported when CanTp_Transmit() is  
                    called with invalid TxNSdu length                         \n
    \Range          0x70                                                      \n
*******************************************************************************/
#define CANTP_E_INVALID_TX_LENGTH           0x70

/******************************************************************************/
/*! \Description    DET error code that is reported when CanTp_RxIndication() 
                    is called with invalid RxNPdu length                      \n
    \Range          0x80                                                      \n
*******************************************************************************/
#define CANTP_E_INVALID_RX_LENGTH           0x80

/******************************************************************************/
/*! \Description    DET error code that is reported when multiple frame       
                    transmission/reception operation is requested for an NSdu 
                    that is configured for functional addressing              \n
    \Range          0x90                                                      \n
*******************************************************************************/
#define CANTP_E_INVALID_TATYPE              0x90

/******************************************************************************/
/*! \Description    DET error code that is reported when Requested operation  
                    is not supported (Cancel transmission/reception is        
                    requested for an N-SDU that it is not on                  
                    transmission/reception process                            
    \Range          0xA0                                                      \n
*******************************************************************************/
#define CANTP_E_OPER_NOT_SUPPORTED          0xA0

/******************************************************************************/
/*! \Description    DET error code that is reported when a transmission/      
                    reception operation is aborted due to any protocol error  
                    other than timeouts                                       \n
    \Range          0xB0                                                      \n
*******************************************************************************/
#define CANTP_E_COM                         0xB0

/******************************************************************************/
/*! \Description    DET error code that is reported when a reception operation
                    is aborted due to Ar, Br, or Cr timeouts                  \n
    \Range          0xC0                                                      \n
*******************************************************************************/
#define CANTP_E_RX_COM                      0xC0

/******************************************************************************/
/*! \Description    DET error code that is reported when a transmission       
                    operation is aborted due to As, Bs, or Cs timeouts        \n
    \Range          0xD0                                                      \n
*******************************************************************************/
#define CANTP_E_TX_COM                      0xD0
#endif  /* CanTp_bDEV_ERROR_DETECT == STD_ON */


/******************************************************************************/
/*! \Description    Value of CanTp_u8eCanTpGlobalState that indicates that the
                    CanTp Component is not initialized                        \n
    \Range          0                                                         \n
*******************************************************************************/
#define CANTP_OFF                           0x00

/******************************************************************************/
/*! \Description    Value of CanTp_u8eCanTpGlobalState that indicates that the
                    CanTp Component is initialized                            \n
    \Range          1                                                         \n
*******************************************************************************/
#define CANTP_ON                            0x01





/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/*! \Description    This function initializes all global variables of the CanTp 
                    Component with the given configuration set and sets the 
                    CanTp state to CANTP_ON                                   \n
    \param[in]      CfgPtr  Pointer to post-build configuration structure     \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_Init(
                  P2CONST(CanTp_ConfigType, AUTOMATIC, CANTP_APPL_CONST)CfgPtr);


/******************************************************************************/
/*! \Description    This function is called to shutdown the CanTp Component by
                    closing all pending transport protocol connections,       
                    releasing all resources, and setting the CanTp state to   
                    CANTP_OFF                                                 \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_Shutdown(void);


/******************************************************************************/
/*! \Description    This function is used to issue a transmission request     \n
    \param[in]      CanTpTxSduId    This parameter contains the unique CanTp  
                                    module identifier of the CAN N-SDU to be  
                                    transmitted                               \n
                    \Range          0 .. CanTp_u16NUM_OF_TX_NSDUS-1           \n
    \param[in]      CanTpTxInfoPtr  A pointer to a structure that contains the
                                    data to be transmitted and its length     \n
    \return         Transmission request result                               \n
                    E_OK:           The request was accepted                  \n
                    E_NOT_OK:       The request was rejected                  \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit(
    VAR(PduIdType, AUTOMATIC)                           CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST)   CanTpTxInfoPtr);


/******************************************************************************/
/*! \Description    The main function for scheduling the CanTp                \n
*******************************************************************************/
extern FUNC(void, CANTP_CODE) CanTp_MainFunction(void);


/******************************************************************************/
/*! \Description    This function is used to cancel the transmission of an    
                    ongoing N-SDU                                             \n
    \param[in]      CanTpTxSduId    This parameter contains the unique CanTp  
                                    module identifier of the CAN N-SDU whose  
                                    transmission operation shall be cancelled \n
                    \Range          0 .. CanTp_u16NUM_OF_TX_NSDUS-1           \n
    \return         Cancellation request result                               \n
                    E_OK:           The request was accepted                  \n
                    E_NOT_OK:       The request was rejected                  \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelTransmit(
    VAR(PduIdType, AUTOMATIC) CanTpTxSduId);


/******************************************************************************/
/*! \Description    This function is used to cancel the reception of an       
                    ongoing N-SDU                                             \n
    \param[in]      CanTpRxSduId    This parameter contains the unique CanTp  
                                    module identifier of the CAN N-SDU whose  
                                    reception operation shall be cancelled    \n
                    \Range          0 .. CanTp_u16NUM_OF_RX_NSDUS-1           \n
    \return         Cancellation request result                               \n
                    E_OK:           The request was accepted                  \n
                    E_NOT_OK:       The request was rejected                  \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelReceive(
    VAR(PduIdType, AUTOMATIC) CanTpRxSduId);


#if (CanTp_bCHANGE_PARAMETER_API == STD_ON)
/******************************************************************************/
/*! \Description    This function is used to request the change of reception  
                    parameters BS and STmin for a specified N-SDU             \n
    \param[in]      id              This parameter contains the unique CanTp  
                                    module identifier of the CAN N-SDU whose  
                                    reception parameters shall be changed     \n
                    \Range          0 .. CanTp_u16NUM_OF_RX_NSDUS-1           \n
    \param[in]      parameter       Specify the parameter to which the value  
                                    has to be changed (BS or STmin)           \n
                    \Range          STMIN/BS                                  
    \param[in]      value           The new value of the reception parameter  \n
    \return         Change parameter request result                           \n
                    E_OK:           The request was accepted                  \n
                    E_NOT_OK:       The request was rejected                  \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ChangeParameter(
    VAR(PduIdType, AUTOMATIC)       id,
    VAR(TPParameterType, AUTOMATIC) parameter,
    VAR(uint16, AUTOMATIC)          value);
#endif  /* CanTp_bCHANGE_PARAMETER_API == STD_ON */



#if (CanTp_bGET_VERSION_INFO_API == STD_ON)
/******************************************************************************/
/*! \Description    This function returns the version information of the CanTp
                    Component                                                 \n
    \param[out]     versioninfo     A pointer to the structure where the      
                                    version information will be stored        \n
*******************************************************************************/
/* !Deviation: [3459] Requirement States that this function should be
    implemented as a macro if source code of caller is available and this is a
    minor rule */
/* PRQA S 3459, 3412 ++ */

#if (CanTp_bDEV_ERROR_DETECT == STD_ON)

	/*! If a NULL pointer is received:                                        */
	/*! Report the corresponding DET error code                               */
	/*! \Trace_Tp   CanTp-CDD-0150(0)                                         */
#define CanTp_GetVersionInfo(versioninfo) do {                                 \
    if ((versioninfo) == NULL_PTR)                                             \
    {                                                                          \
        (void)Det_ReportError(                                                 \
                   CANTP_MODULE_ID, CANTP_INSTANCE_ID,                         \
							  CanTp_u8VERSION_INFO_ID, CANTP_E_PARAM_POINTER); \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = CANTP_VENDOR_ID;                             \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = CANTP_MODULE_ID;                             \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version = CANTP_SW_MAJOR_VERSION;              \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version = CANTP_SW_MINOR_VERSION;              \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version = CANTP_SW_PATCH_VERSION;              \
    }                                                                          \
} while (1==0)
#else  /* CanTp_bDEV_ERROR_DETECT */

	/*! Store the Module's Version Info at the structure addressed by the
		passed pointer                                                        */
	/*! \Trace_To   CanTp-CDD-0146(0)                                         */

#define CanTp_GetVersionInfo(versioninfo) do {                                 \
    ((Std_VersionInfoType *)versioninfo)->vendorID = CANTP_VENDOR_ID;                                 \
    ((Std_VersionInfoType *)versioninfo)->moduleID = CANTP_MODULE_ID;                                 \
    ((Std_VersionInfoType *)versioninfo)->sw_major_version = CANTP_SW_MAJOR_VERSION;                  \
    ((Std_VersionInfoType *)versioninfo)->sw_minor_version = CANTP_SW_MINOR_VERSION;                  \
    ((Std_VersionInfoType *)versioninfo)->sw_patch_version = CANTP_SW_PATCH_VERSION;                  \
} while (1==0)
/* PRQA S 3459, 3412 -- */

#endif	/* CanTp_bGET_VERSION_INFO_API */
#endif 	/* CanTp_bDEV_ERROR_DETECT */

#if (CanTp_bREAD_PARAMETER_API == STD_ON)
/******************************************************************************/
/*! \Description    This function is used to read the current value of reception  
                    parameters BS and STmin for a specified N-SDU             \n
    \param[in]      id              This parameter contains the unique CanTp  
                                    module identifier of the CAN N-SDU whose  
                                    reception parameters shall be changed     \n
                    \Range          0 .. CanTp_u16NUM_OF_RX_NSDUS-1           \n
    \param[in]      parameter       Specify the parameter to which the value  
                                    has to be changed (BS or STmin)           \n
                    \Range          STMIN/BS                                  
    \param[in]      value           The new value of the reception parameter  \n
    \return         Change parameter request result                           \n
                    E_OK:           The request was accepted                  \n
                    E_NOT_OK:       The request was rejected                  \n
*******************************************************************************/
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ReadParameter(
    VAR(PduIdType, AUTOMATIC)       id,
    VAR(TPParameterType, AUTOMATIC) parameter,
    P2VAR(uint16, AUTOMATIC,AUTOMATIC)          value);
#endif  /* CanTp_bREAD_PARAMETER_API == STD_ON */


#define CANTP_STOP_SEC_CODE
#include "MemMap.h"





/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/*! \Description    This variable holds the CanTp Component state             \n
    \Range          CANTP_OFF\CANTP_ON                                        \n
*******************************************************************************/

#define CANTP_START_SEC_VAR_8
#include "Memmap.h"

extern VAR(uint8, CANTP_VAR) CanTp_u8eCanTpGlobalState;

#define CANTP_STOP_SEC_VAR_8
#include "Memmap.h"

/******************************************************************************/
/* Intra-Module Checking - Module Header Files and Module Configuration Files */
/******************************************************************************/

#ifdef CANTP_CFG_MAJOR_VERSION 
  #ifdef CANTP_CFG_MINOR_VERSION
     /* Major version of the vendor specific implementation of CanTp module */
    #if (CANTP_SW_MAJOR_VERSION != CANTP_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif
     /* Minor version of the vendor specific implementation of CanTp module */
    #if (CANTP_SW_MINOR_VERSION > CANTP_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif 
  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* CANTP_CFG_MINOR_VERSION */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif  /* CANTP_CFG_MAJOR_VERSION */


#endif /* CANTP_H */

/*-------------------------------- end of file -------------------------------*/