/******************************************************************************/
/*! \file LinSM.h
*
* \brief
*   This file containing the APIs declaration, symbols, and data exported     */
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : LinSM                                                   */
/* !Description     : LinSM is a part of the Communication service layer,     */
/*                    and it's responsible for:                               */  
/*                    -Switching Schedule tables when requested by Upper layer*/
/*                    - GotoSleep and Wakeup Handling.                        */
/*                    - Notification to the upper layer when new state entered*/
/*                                                                            */
/* !File            : LinSM.h                                                 */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/DEI Team room/archives/E95110014/02_Modules/21_Lin$*/
/* $Revision::   1.8      $$Author::   MTAYMOUR        $$Date::   Feb 17 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINSM_H
#define LINSM_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinSM_Cfg.h"
#include "LinIf.h"
#include "ComM.h"

/* PRQA S 0850 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Memclass is defined as an empty    */
/*              macro                                                         */
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define LINSM_MODULE_ID                     (141U)
#define LINSM_INSTANCE_ID                   (0U)
#define LINSM_VENDOR_ID                     (38U)

#define LINSM_SW_MAJOR_VERSION              (2U)
#define LINSM_SW_MINOR_VERSION              (0U)
#define LINSM_SW_PATCH_VERSION              (0U)

#define LINSM_AR_RELEASE_MAJOR_VERSION      (4U)
#define LINSM_AR_RELEASE_MINOR_VERSION      (1U)
#define LINSM_AR_RELEASE_REVISION_VERSION   (2U)

/******************************************************************************/
/* Intra-Module Checking - Module Header Files and Module Configuration Files */
/******************************************************************************/
/* Check this component version information toward configured one */
#ifdef LINSM_CFG_MAJOR_VERSION 
  #ifdef LINSM_CFG_MINOR_VERSION
     /* Major version of the vendor specific implementation of LINIF module */
    #if (LINSM_SW_MAJOR_VERSION != LINSM_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif
     /* Minor version of the vendor specific implementation of LINIF module */
    #if (LINSM_SW_MINOR_VERSION > LINSM_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif 
  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* LINSM_CFG_MINOR_VERSION */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif  /* LINSM_CFG_MAJOR_VERSION */

/******************************************************************************/
/*! \Description    The Lin Channel SubState for the No Communication mode.   \n
    \Range          0x00                                                      \n
*******************************************************************************/
#define LINSM_NO_COM     0x02 
/******************************************************************************/
/*! \Description    The Lin Channel SubState for the FULL Communication mode. \n
    \Range          0x01                                                      \n
*******************************************************************************/
#define LINSM_FULL_COM   0x01
/******************************************************************************/
/*! \Description    The LinSM State is Uninitialized.                         \n
    \Range          0x00                                                      \n
*******************************************************************************/
#define LinSM_u8UNINIT    0x00
/******************************************************************************/
/*! \Description    The LinSM State is Initialized.                           \n
    \Range          0x01                                                      \n
*******************************************************************************/
#define LinSM_u8INIT   0x01

/******************************************************************************/
/* Services IDs                                                               */
/******************************************************************************/
/******************************************************************************/
/*! \Description    LinSM_GetVersionInfo() Service ID                         \n
    \Range          0x02                                                      \n
*******************************************************************************/
#define LinSM_u8VERSION_INFO_ID    0x02
/******************************************************************************/
/*! \Description    LinSM_ScheduleRequest() Service ID                        \n
    \Range          0x10                                                      \n
*******************************************************************************/
#define LinSM_u8SCHEDULEREQUEST_ID    0x10
/******************************************************************************/
/*! \Description    LinSM_GetCurrentComMode() Service ID                      \n
    \Range          0x11                                                      \n
*******************************************************************************/
#define LinSM_u8GETCURRENTMODE_ID    0x11
/******************************************************************************/
/*! \Description    LinSM_RequestComMode() Service ID                         \n
    \Range          0x12                                                      \n
*******************************************************************************/
#define LinSM_u8REQUESTCOMMODE_ID    0x12
/******************************************************************************/
/*! \Description    LinSM_MainFunction() Service ID                           \n
    \Range          0x30                                                      \n
*******************************************************************************/
#define LinSM_u8MAINFUNCTION_ID    0x30
/******************************************************************************/
/*! \Description    LinSM_ScheduleRequestConfirmation() Service ID            \n
    \Range          0x20                                                      \n
*******************************************************************************/
#define LinSM_u8SCHEDULEREQCNF_ID    0x20
/******************************************************************************/
/*! \Description    LinSM_GotoSleepConfirmation() Service ID                  \n
    \Range          0x22                                                      \n
*******************************************************************************/
#define LinSM_u8GOTOSLEEPCNF_ID            0x22
/******************************************************************************/
/*! \Description    LinSM_WakeupConfirmation() Service ID                     \n
    \Range          0x21                                                      \n
*******************************************************************************/
#define LinSM_u8WAKEUPCNF_ID            0x21

#if (LinSM_bDEV_ERROR_DETECT == STD_ON)
/******************************************************************************/
/* Errors IDs                                                                 */
/******************************************************************************/
/******************************************************************************/
/*! \Description    DET error reported when API called without initialization 
                    of LinSM                                                  \n
    \Range          0x00                                                      \n
*******************************************************************************/
#define LINSM_E_UNINIT                0x00
/******************************************************************************/
/*! \Description    DET Error reported when Referenced network does not exist \n
    \Range          0x20                                                      \n
*******************************************************************************/
#define LINSM_E_NONEXISTENT_NETWORK  0x20 
/******************************************************************************/
/*! \Description    DET Error reported when API service called with wrong 
                    parameter                                                 \n
    \Range          0x30                                                      \n
*******************************************************************************/
#define LINSM_E_PARAMETER  0x30 
/******************************************************************************/
/*! \Description    DET Error reported when API service called with invalid 
                    pointer                                                   \n
    \Range          0x40                                                      \n
*******************************************************************************/
#define LINSM_E_PARAMETER_POINTER  0x40
/******************************************************************************/
/*! \Description    DET Error reported when Timeout occured of LinIF callbacks\n
    \Range          0x50                                                      \n
*******************************************************************************/
#define LINSM_E_CONFIRMATION_TIMEOUT 0x50
/******************************************************************************/
#endif  /* LINSM_bDEV_ERROR_DETECT == STD_ON */

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/* !Deviation: [3453] The function like macro is used to ease the function 
                      implementation                                          */
/* PRQA S 3453 ++ */
#define LinSM_vidREPORT_DET_ERROR(u8ApiId, u8ErrorId)                          \
   ((void)Det_ReportError(                                                     \
                    LINSM_MODULE_ID, LINSM_INSTANCE_ID, (u8ApiId), (u8ErrorId)))
/* PRQA S 3453 -- */
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/*! \Description  Type used to report the current mode to the BswM and it is 
                  the Sub-State machine for each network.                     */
/*! \Range   LINSM_FULL_COM,LINSM_NO_COM                                      */
typedef uint8 LinSM_ModeType;

/*! \Description  Typeused to report the state of the LinSM module.           */
/*! \Range   LINSM_INIT,LINSM_UNINIT                                          */
typedef uint8 LinSM_tu8StateType;
                    
/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define LINSM_START_SEC_VAR_8
#include "Memmap.h"
/*! \Description  Parameter used to report the communication mode (Sub-State 
                  machine) for each LIN Channel                               */
/*! \Range    LINSM_FULL_COM,LINSM_NO_COM                                     */
extern VAR(LinSM_ModeType, LINSM_VAR) LinSM_au8eChannelMode[LinSM_u16MAX_CHANNEL_NUM];

/*! \Description  Parameter used to report the State of LinSM state machine.  */
/*! \Range    LINSM_UNINIT,LINSM_INIT                                         */
/*! \Trace_To LinSM-CDD-0027(0)                                                */
extern VAR(LinSM_tu8StateType, LINSM_VAR) LinSM_u8eState;

#define LINSM_STOP_SEC_VAR_8
#include "Memmap.h"                    
/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define LINSM_START_SEC_CODE
#include "MemMap.h"
                    
#if (LinSM_bVERSION_INFO_API == STD_ON)
/******************************************************************************/
/*! \Description    This function returns the version information of the LinSM
                    Component                                                 \n
    \param[out]     versioninfo     A pointer to the structure where the      
                                    version information will be stored        \n
*******************************************************************************/
/* !Deviation: [3456] Requirement States that this function should be
    implemented as a macro if source code of caller is available and this is a
    minor rule */
/* PRQA S 3456, 3412 ++ */
#if (LinSM_bDEV_ERROR_DETECT == STD_ON)

    /*! If a NULL pointer is received:                                        */
    /*! Report the corresponding DET error code                               */
    /*! \Trace_To   LinSM-CDD-0103(0),LinSM-CDD-0102(0)                       */
#define LinSM_GetVersionInfo(versioninfo) do {                                 \
    if ((versioninfo) == NULL_PTR)                                             \
    {                                                                          \
        /*! \Trace_To LinSM-CDD-0103(0)*/                                      \
        (void)Det_ReportError(                                                 \
                   LINSM_MODULE_ID, LINSM_INSTANCE_ID,                         \
                              LinSM_u8VERSION_INFO_ID, LINSM_E_PARAMETER_POINTER); \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        /*! \Trace_To   LinSM-CDD-0101(0)                                   */ \
        (versioninfo)->vendorID = LINSM_VENDOR_ID;                             \
        (versioninfo)->moduleID = LINSM_MODULE_ID;                             \
        (versioninfo)->sw_major_version = LINSM_SW_MAJOR_VERSION;              \
        (versioninfo)->sw_minor_version = LINSM_SW_MINOR_VERSION;              \
        (versioninfo)->sw_patch_version = LINSM_SW_PATCH_VERSION;              \
    }                                                                          \
} while (1==0)
#else  /* LinSM_bDEV_ERROR_DETECT */

    /*! Store the Module's Version Info at the structure addressed by the
        passed pointer                                                        */
    /*! \Trace_To   LinSM-CDD-0101(0)                                         */

#define LinSM_GetVersionInfo(versioninfo) do {                                 \
    (versioninfo)->vendorID = LINSM_VENDOR_ID;                                 \
    (versioninfo)->moduleID = LINSM_MODULE_ID;                                 \
    (versioninfo)->sw_major_version = LINSM_SW_MAJOR_VERSION;                  \
    (versioninfo)->sw_minor_version = LINSM_SW_MINOR_VERSION;                  \
    (versioninfo)->sw_patch_version = LINSM_SW_PATCH_VERSION;                  \
} while (1==0)
/* PRQA S 3456, 3412 -- */
#endif    /* LinSM_bGET_VERSION_INFO_API */
#endif     /* LinSM_bDEV_ERROR_DETECT */

/******************************************************************************/
/*! \Description    This function initializes all global variables of the LinSM 
                    Component                                                 \n
*******************************************************************************/
FUNC(void, LINSM_CODE) LinSM_Init(void);

/******************************************************************************/
/*! \Description    This function used to request the Schedule table for the 
                    selected Lin Channel                                      \n
    \param[in]      udtNetwork  Identification of the LIN channel             \n
    \param[in]      udtSchedule  Schedule Table index required                \n
*******************************************************************************/
FUNC(Std_ReturnType, LINSM_CODE) LinSM_ScheduleRequest( 
    NetworkHandleType udtNetwork, 
    LinIf_SchHandleType udtSchedule );

/******************************************************************************/
/*! \Description    This function used to get the current communication mode  
                    for the selected Lin Channel                              \n
    \param[in]      udtNetwork  Identification of the LIN channel             \n
    \param[in]      udtpMode    Returns the active Communication mode         \n
*******************************************************************************/
FUNC(Std_ReturnType, LINSM_CODE) LinSM_GetCurrentComMode( 
    NetworkHandleType udtNetwork, 
    ComM_ModeType* udtpMode );
    
/******************************************************************************/
/*! \Description    This function used to request a new communication mode  
                    for the selected Lin Channel                              \n
    \param[in]      udtNetwork  Identification of the LIN channel             \n
    \param[in]      udtMode    Communication mode requested                   \n
*******************************************************************************/
FUNC(Std_ReturnType, LINSM_CODE) LinSM_RequestComMode( 
    NetworkHandleType udtNetwork, 
    ComM_ModeType udtMode );

/******************************************************************************/
/*! \Description    Periodic function that runs the timers of different request
                    timeouts                                                  \n
*******************************************************************************/
FUNC(void, LINSM_CODE) LinSM_MainFunction( void);
    
#define LINSM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* LINSM_H */

/*-------------------------------- end of file -------------------------------*/                