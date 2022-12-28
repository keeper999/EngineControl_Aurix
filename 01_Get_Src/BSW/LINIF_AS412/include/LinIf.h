/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                      */
/*                                                                            */
/*!Component       : LinIf                                                    */
/*!Description     : The Lin Interface AutoSAR component                      */
/*                                                                            */
/*!Module          : LinIf                                                    */
/*!Description     : The Main Header file of the Component                    */
/*                                                                            */
/*!\File             LinIf.h                                                  */
/* \par              The Main Header file of the LinIf Component              */
/*!Scope           : Public                                                   */
/*                                                                            */
/*!Target          : All                                                      */
/*                                                                            */
/*!Vendor          : VIAS                                                     */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-   */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.28     $$Author::   MTAYMOUR       $$Date::   Apr 30 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_H
#define LINIF_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf_Cfg.h"
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "LinIf_Types.h"
#include "LinIf_PBcfg.h"
#include "LinIf_DetErrors.h"
#include "EcuM_Types.h"

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#include "Dem.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


#define LINIF_MODULE_ID                     (62U)
#define LINIF_INSTANCE_ID                   (0U)
#define LINIF_VENDOR_ID                     (38U)

#define LINIF_SW_MAJOR_VERSION              (2U)
#define LINIF_SW_MINOR_VERSION              (0U)
#define LINIF_SW_PATCH_VERSION              (0U)

#define LINIF_AR_RELEASE_MAJOR_VERSION      (4U)
#define LINIF_AR_RELEASE_MINOR_VERSION      (1U)
#define LINIF_AR_RELEASE_REVISION_VERSION   (2U)

/* Check this component version information toward configured one */
#ifdef LINIF_CFG_MAJOR_VERSION
  #ifdef LINIF_CFG_MINOR_VERSION
     /* Major version of the vendor specific implementation of LINIF module */
    #if (LINIF_SW_MAJOR_VERSION != LINIF_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif
     /* Minor version of the vendor specific implementation of LINIF module */
    #if (LINIF_SW_MINOR_VERSION != LINIF_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif
  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* LINIF_CFG_MINOR_VERSION */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif  /* LINIF_CFG_MAJOR_VERSION */

#if(LinIf_bINTER_MOD_VER_CHECK == STD_ON)
/******************************************************************************/
/*----------------------- Inter-modules Version Check ------------------------*/
/******************************************************************************/

/* ------------------------------- Std Types -------------------------------- */
#if (LINIF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
    #error Std AR RELEASE MAJOR VERSION is not compatible with LinIf AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINIF_AR_RELEASE_MINOR_VERSION < STD_AR_RELEASE_MINOR_VERSION)
    #error Std AR RELEASE MINOR VERSION is not compatible with LinIf AR \
           RELEASE MINOR VERSION.
#endif

/* -------------------------------- Memmap ---------------------------------- */
#if (LINIF_AR_RELEASE_MAJOR_VERSION != MEM_AR_RELEASE_MAJOR_VERSION)
    #error Memmap AR RELEASE MAJOR VERSION is not compatible with LinIf AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINIF_AR_RELEASE_MINOR_VERSION < MEM_AR_RELEASE_MINOR_VERSION)
    #error Memmap AR RELEASE MINOR VERSION is not compatible with LinIf AR \
           RELEASE MINOR VERSION.
#endif

/* ---------------------------- Platform Types ------------------------------ */
#if (LINIF_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)
    #error Platform AR RELEASE MAJOR VERSION is not compatible with LinIf AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINIF_AR_RELEASE_MINOR_VERSION < PLATFORM_AR_RELEASE_MINOR_VERSION)
    #error Platform AR RELEASE MINOR VERSION is not compatible with LinIf AR \
           RELEASE MINOR VERSION.
#endif

/* ------------------------------- Compiler --------------------------------- */
#if (LINIF_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)
    #error Compiler AR RELEASE MAJOR VERSION is not compatible with LinIf AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINIF_AR_RELEASE_MINOR_VERSION < COMPILER_AR_RELEASE_MINOR_VERSION)
    #error Compiler AR RELEASE MINOR VERSION is not compatible with LinIf AR \
           RELEASE MINOR VERSION.
#endif

/* ---------------------------- ComStack Types ------------------------------ */
#if (LINIF_AR_RELEASE_MAJOR_VERSION != COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION)
    #error ComStack Types AR RELEASE MAJOR VERSION is not compatible with LinIf\
           AR RELEASE MAJOR VERSION.
#endif
#if (LINIF_AR_RELEASE_MINOR_VERSION < COMSTACKTYPE_AR_RELEASE_MINOR_VERSION)
    #error ComStack Types AR RELEASE MINOR VERSION is not compatible with LinIf\
           AR RELEASE MINOR VERSION.
#endif

/* --------------------------------- Dem ------------------------------------ */
#if (LINIF_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION)
    #error Dem AR RELEASE MAJOR VERSION is not compatible with LinIf AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINIF_AR_RELEASE_MINOR_VERSION < DEM_AR_RELEASE_MINOR_VERSION)
    #error Dem AR RELEASE MINOR VERSION is not compatible with LinIf AR \
           RELEASE MINOR VERSION.
#endif

/* --------------------------------- Det ------------------------------------ */
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
#if (LINIF_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
    #error Det AR RELEASE MAJOR VERSION is not compatible with LinIf AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINIF_AR_RELEASE_MINOR_VERSION < DET_AR_RELEASE_MINOR_VERSION)
    #error Det AR RELEASE MINOR VERSION is not compatible with LinIf AR \
           RELEASE MINOR VERSION.
#endif
#endif
#endif /* LinIf_bINTER_MOD_VER_CHECK == STD_ON */



#if (LinIf_bIF_VERSION_INFO_API == STD_ON)
/******************************************************************************/
/*!\Description    LinIf_GetVersionInfo Returns the version information of    \n
this  module.
    \param[out]   Pointer to where to store the version information of this
                  module. \n
            \Range   NOT NULL  \n                                             */
/*\Trace_To    : LinIf-CDD-0175(0), LinIf-CDD-0178(0), LinIf-CDD-0176(0)      */
/******************************************************************************/

/*!Deviation : inhibit MISRA rule [3459]: because the memmap file is used     */
/*!              for memory allocation and should be included several times.  */
/* PRQA S 3459 L1                                                             */

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
#define LinIf_GetVersionInfo(VersionInfo)\
do{\
    if(NULL_PTR == (VersionInfo))\
    {\
        (void)Det_ReportError(LINIF_MODULE_ID, \
                              LINIF_INSTANCE_ID,\
                              LinIf_u8LINIF_GET_VERSION_ID,\
                              LINIF_E_PARAMETER_POINTER);\
    }\
    else\
    {\
        (VersionInfo)->moduleID         = LINIF_MODULE_ID;\
        (VersionInfo)->vendorID         = LINIF_VENDOR_ID;\
        (VersionInfo)->sw_major_version = LINIF_SW_MAJOR_VERSION;\
        (VersionInfo)->sw_minor_version = LINIF_SW_MINOR_VERSION;\
        (VersionInfo)->sw_patch_version = LINIF_SW_PATCH_VERSION;\
    }\
}while(0)
#endif

#if (LinIf_u8DEV_ERROR_DETECT == STD_OFF)
#define LinIf_GetVersionInfo(VersionInfo)\
do{\
    if(NULL_PTR != (VersionInfo))\
    {\
        (VersionInfo)->moduleID         = LINIF_MODULE_ID;\
        (VersionInfo)->vendorID         = LINIF_VENDOR_ID;\
        (VersionInfo)->sw_major_version = LINIF_SW_MAJOR_VERSION;\
        (VersionInfo)->sw_minor_version = LINIF_SW_MINOR_VERSION;\
        (VersionInfo)->sw_patch_version = LINIF_SW_PATCH_VERSION;\
    }\
}while(0)
#endif
/* PRQA L:L1                                                                  */
#endif

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define LINIF_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/*                                  LinIf                                     */
/******************************************************************************/

/******************************************************************************/
/* Description : Initializes the LIN Interface.                               */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinIf_Init(
    P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_DATA) pkstrLinIfConf);


/******************************************************************************/
/* Description : Indicates a transmit request.                                */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_Transmit(
   VAR(PduIdType, AUTOMATIC) udtLinTxPduId,
   P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) pkstrPduInfoPtr);

/******************************************************************************/
/* Description : Requests a schedule table to be executed.                    */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE)  LinIf_ScheduleRequest(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
    VAR(LinIf_SchHandleType, AUTOMATIC) udtSchedule);

/******************************************************************************/
/* Description : The main processing function of the LIN Interface.           */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinIf_MainFunction(void);


#if (LinIf_bCANCEL_TX_SUPPORT == STD_ON)
/******************************************************************************/
/* Description : Indicates a Cancel Transmit request. This is a dummy method
                 introduced for interface compatibility.                      */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_CancelTransmit(
   VAR(PduIdType, AUTOMATIC) udtLinTxPduId);

#endif

/******************************************************************************/
/* Description : Initiates a transition into the Sleep Mode on the selected
                channel.                                                      */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_GotoSleep(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel);

/******************************************************************************/
/* Description : Initiates the wake up process.                               */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel);

/******************************************************************************/
/* Description : Will be called when the EcuM has been notified about a wakeup
                 on a specific LIN channel.                                   */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);

/******************************************************************************/
/* Description : Set the given LIN transceiver to the given mode.             */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvMode(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
    VAR(LinTrcv_TrcvModeType, AUTOMATIC) enuTransceiverMode);

/******************************************************************************/
/* Description : Returns the actual state of a LIN Transceiver Driver.        */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvMode(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
    P2VAR(LinTrcv_TrcvModeType, AUTOMATIC, LINIF_APPL_DATA)
                                                           penuTransceiverMode);

/******************************************************************************/
/* Description : This API enables, disables and clears the notification for
                 wakeup events on the addressed network                       */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_SetTrcvWakeupMode(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
    VAR(LinIf_TrcvWakeupModeType, AUTOMATIC) enuLinTrcvWakeupMode);

/******************************************************************************/
/* Description : Returns the reason for the wake up that has been detecteted by
                 the LIN Transceiver Driver.                                  */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinIf_GetTrcvWakeupReason(
    VAR(NetworkHandleType, AUTOMATIC) udtChannel,
    P2VAR(LinIf_TrcvWakeupReasonType, AUTOMATIC, LINIF_APPL_DATA)
                                                           penuTrcvWuReasonPtr);

/******************************************************************************/
/*                                  LinTp                                     */
/******************************************************************************/


#if (LinIf_u8TP_SUPPORTED == STD_ON)
/******************************************************************************/
/* Description : Cancels the request to receive a LIN Tp Message.             */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelReceive(
    VAR(PduIdType, AUTOMATIC) udtLinTpRxSduId);

/******************************************************************************/
/* Description : Cancels the request to transmit a LIN Tp Message.            */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_CancelTransmit(
    VAR(PduIdType, AUTOMATIC) udtLinTpTxSduId);


/******************************************************************************/
/* Description : Changes parameter request.                                   */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_ChangeParameter(
    VAR(PduIdType, AUTOMATIC) udtPduId,
    VAR(TPParameterType, AUTOMATIC) enuParameter,
    VAR(uint16, AUTOMATIC) u16Value);


/******************************************************************************/
/* Description : Initializes the LIN Transport Layer.                         */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinTp_Init(
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_DATA) pkstrTpConfigPtr);

/******************************************************************************/
/* Description : Shutdowns the LIN TP.                                        */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinTp_Shutdown(void);


/******************************************************************************/
/* Description : Requests the transfer of segmented data.                     */
/******************************************************************************/
extern FUNC(Std_ReturnType, LINIF_CODE) LinTp_Transmit(
    VAR(PduIdType, AUTOMATIC) udtLinTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) pkstrLinTpTxInfoPtr);


/******************************************************************************/
/* Description : Returns the version information of this module.              */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinTp_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, LINIF_APPL_DATA) pudtVersionInfo);
    
/******************************************************************************/
/* Description : The LIN Driver or LIN Transceiver Driver will call this 
                 function to report the wake up source after the successful 
                 wakeup detection during CheckWakeup or after power on by bus.*/
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);

#endif

#define LINIF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* LINIF_H */


/*-------------------------------- end of file -------------------------------*/
