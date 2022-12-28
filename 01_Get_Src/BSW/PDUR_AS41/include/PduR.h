
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !File            : PduR.h                                                  */
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
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.41     $$Author::   ametwelly      $$Date::   Aug 25 2014 $*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/

#ifndef PDUR_H
#define PDUR_H

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include "Std_Types.h"
#include "PduR_Types.h"
#include "PduR_PBCfg.h"
#include "PduR_Cfg.h"

#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/******************************************************************************/
/* EXTERNED DATA                                                              */
/******************************************************************************/


/******************************************************************************/
/* SYMBOLIC DEFINES                                                           */
/******************************************************************************/
#define     PDUR_VENDOR_ID                              0x38
#define     PDUR_MODULE_ID                              0x33

#define     PDUR_AR_RELEASE_MAJOR_VERSION               0x04
#define     PDUR_AR_RELEASE_MINOR_VERSION               0x01
#define     PDUR_AR_RELEASE_REVISION_VERSION            0x02
#define     PDUR_SW_MAJOR_VERSION                       0x02
#define     PDUR_SW_MINOR_VERSION                       0x00
#define     PDUR_SW_PATCH_VERSION                       0x01

#define     PDUR_E_CONFIG_PTR_INVALID                   0x00
#define     PDUR_E_INVALID_REQUEST                      0x01
#define     PDUR_E_PDU_ID_INVALID                       0x02
#define     PDUR_E_TP_TX_REQ_REJECTED                   0x03
#define     PDUR_E_DUPLICATED_IPDU_ID                   0x06
#define     PDUR_E_ROUTING_TABLE_ID_INVALID             0x08
#define     PDUR_E_NULL_POINTER                         0x09
/*R4.0.3    PDUR_E_PDU_INSTANCES_LOST                   0x0A*/
/*R4.0.3    PDUR_E_INIT_FAILED                          0x0B*/
#define     PDUR_E_TP_TX_GW_LENGTH                      0x0C
#define     PDUR_E_API_STILL_RUNNING                    0x0D

/*------------------------------- Services Ids -------------------------------*/
#define     PduR_u8INIT_API_ID                          0xF0
#define     PduR_u8GETVRSNINFO_API_ID                   0xF1
#define     PduR_u8GET_CFG_ID_API_ID                    0xF2
#define     PduR_u8ENABLE_RTNG_API_ID                   0xF3
#define     PduR_u8DISBLE_RTNG_API_ID                   0xF4

/******************************************************************************/
/*------------------ Configuration vs Module Version Check -------------------*/
/******************************************************************************/

/* Check this component version information toward configured one             */
#ifdef PDUR_CFG_MAJOR_VERSION 
  #ifdef PDUR_CFG_MINOR_VERSION
     /* Major version of the vendor specific implementation of PDUR module    */
    #if (PDUR_SW_MAJOR_VERSION != PDUR_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif
     /* Minor version of the vendor specific implementation of PDUR module    */
    #if (PDUR_SW_MINOR_VERSION != PDUR_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif 
  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* PDUR_CFG_MINOR_VERSION                                            */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif  /* PDUR_CFG_MAJOR_VERSION                                             */


/******************************************************************************/
/*----------------------- Inter-modules Version Check ------------------------*/
/******************************************************************************/

#if (PduR_bINTER_MOD_VER_CHECK == STD_ON)

/* ------------------------------- Std Types -------------------------------- */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
    #error Std AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < STD_AR_RELEASE_MINOR_VERSION)
    #error Std AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif

/* --------------------------------- MemMap --------------------------------- */
#define PDUR_START_SEC_VAR_8
#include "Memmap.h"

#if (PDUR_AR_RELEASE_MAJOR_VERSION != MEM_AR_RELEASE_MAJOR_VERSION)
    #error MemMap AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < MEM_AR_RELEASE_MINOR_VERSION)
    #error MemMap AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif

#define PDUR_STOP_SEC_VAR_8
#include "Memmap.h"

/* -------------------------------- Compiler -------------------------------- */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)
    #error Compiler AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < COMPILER_AR_RELEASE_MINOR_VERSION)
    #error Compiler AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif

/* -------------------------------- Platform -------------------------------- */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)
    #error Platform AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < PLATFORM_AR_RELEASE_MINOR_VERSION)
    #error Platform AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif

/* ----------------------------- ComStack Types ----------------------------- */
#if (PDUR_AR_RELEASE_MAJOR_VERSION != COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION)
    #error ComStackType AR RELEASE MAJOR VERSION is not compatible with PduR \
           AR RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < COMSTACKTYPE_AR_RELEASE_MINOR_VERSION)
    #error ComStackType AR RELEASE MINOR VERSION is not compatible with PduR \
           AR RELEASE MINOR VERSION.
#endif

/* ------------------------------- Det Module ------------------------------- */
#if (PduR_bDEV_ERROR_DETECT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
    #error Det AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)
    #error Det AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ CanIf Module ------------------------------ */
#if (PduR_bCANIF_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION)
    #error CanIf AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION)
    #error CanIf AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ LinIf Module ------------------------------ */
#if ((PduR_bLINIF_PRESENT == STD_ON) || (PduR_bLINTP_PRESENT == STD_ON))
#if (PDUR_AR_RELEASE_MAJOR_VERSION != LINIF_AR_RELEASE_MAJOR_VERSION)
    #error LinIf AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION != LINIF_AR_RELEASE_MINOR_VERSION)
    #error LinIf AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ FrIf  Module ------------------------------ */
#if (PduR_bFRIF_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != FRIF_AR_RELEASE_MAJOR_VERSION)
    #error FlexRayIf AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < FRIF_AR_RELEASE_MINOR_VERSION)
    #error FlexRayIf AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ CanNm  Module ----------------------------- */
#if (PduR_bCANNM_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != CANNM_AR_RELEASE_MAJOR_VERSION)
    #error CanNm AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < CANNM_AR_RELEASE_MINOR_VERSION)
    #error CanNm AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ FrNm  Module ------------------------------ */
#if (PduR_bFRNM_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != FRNM_AR_RELEASE_MAJOR_VERSION)
    #error FlexRayNm AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < FRNM_AR_RELEASE_MINOR_VERSION)
    #error FlexRayNm AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ CanTp Module ------------------------------ */
#if (PduR_bCANTP_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != CANTP_AR_RELEASE_MAJOR_VERSION)
    #error CanTp AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION != CANTP_AR_RELEASE_MINOR_VERSION)
    #error CanTp AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ FrTp  Module ------------------------------ */
#if (PduR_bFRTP_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != FRTP_AR_RELEASE_MAJOR_VERSION)
    #error FlexRayTp AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < FRTP_AR_RELEASE_MINOR_VERSION)
    #error FlexRayTp AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ SoAd  Module ------------------------------ */
#if (PduR_bSOAD_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != SOAD_AR_RELEASE_MAJOR_VERSION)
    #error SoAd AR RELEASE MAJOR VERSION is not compatible with PduR AR \
    RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < SOAD_AR_RELEASE_MINOR_VERSION)
    #error SoAd AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

/* ------------------------------ J1939Tp  Module --------------------------- */
#if (PduR_bJ1939TP_PRESENT == STD_ON)
#if (PDUR_AR_RELEASE_MAJOR_VERSION != J1939TP_AR_RELEASE_MAJOR_VERSION)
    #error J1939Tp AR RELEASE MAJOR VERSION is not compatible with PduR AR \
           RELEASE MAJOR VERSION.
#endif
#if (PDUR_AR_RELEASE_MINOR_VERSION < J1939TP_AR_RELEASE_MINOR_VERSION)
    #error J1939Tp AR RELEASE MINOR VERSION is not compatible with PduR AR \
           RELEASE MINOR VERSION.
#endif
#endif

#endif /* #if (PduR_bINTER_MOD_VER_CHECK == STD_ON) */

#if (PduR_bZERO_COST_OPERATION == STD_OFF)

/******************************************************************************/
/* FUNCTIONS DECLARATIONS                                                     */
/******************************************************************************/
#define PDUR_START_SEC_CODE
#include "Memmap.h"

extern FUNC(void, PDUR_CODE) PduR_Init(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_APPL_CONST)  ConfigPtr);

#if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
extern FUNC(void, PDUR_CODE) PduR_EnableRouting(
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             id);

extern FUNC(void, PDUR_CODE) PduR_DisableRouting(
    VAR(PduR_RoutingPathGroupIdType, AUTOMATIC)             id);
#endif

extern FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId(void);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if (PduR_bZERO_COST_OPERATION == STD_OFF) */

#if(PduR_bVERSION_INFO_API == STD_ON)
/******************************************************************************/
/*! \Description    Returns the version information of the PduR
    \return         void \n
    \Trace_To       PduR-CDD-0161(0), PduR-CDD-0162(0), PduR-CDD-5164(0)
    \Trace_To       PduR-CDD-5270(0)
*******************************************************************************/
/* !Deviation : Inhibit MISRA rule [3412]: The function GetVersionInfo must be*/
/*              implemented as a macro as specified and the unrecognized code */
/*              fragment is because of the while(1==0) at the end which is    */
/*              safe for the current implementation                           */
/* PRQA S 3412 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3456]: versionInfo parameter will normally*/
/*              be evaluated more than once as it this macro is a replacement */
/*              to a real service so its safe to have this                    */
/* PRQA S 3456 ++                                                             */
/******************************************************************************/
#if(PduR_bZERO_COST_OPERATION == STD_OFF)
#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#define PduR_GetVersionInfo(versionInfo) do {                                  \
    /*! Check module's initialization                                      */  \
    if(PduR_u8eState == PDUR_UNINIT)                                           \
    {                                                                          \
        /*! Report to DET                                                  */  \
        (void) Det_ReportError( PDUR_MODULE_ID, 0,                             \
                                PduR_u8GETVRSNINFO_API_ID,                     \
                                PDUR_E_INVALID_REQUEST);                       \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        /*! Check versionInfo pointer if NULL or not                       */  \
        if((versionInfo) == NULL_PTR)                                          \
        {                                                                      \
            /*! Report to DET                                              */  \
            (void) Det_ReportError( PDUR_MODULE_ID, 0,                         \
                                    PduR_u8GETVRSNINFO_API_ID,                 \
                                    PDUR_E_NULL_POINTER);                      \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /*! Copy PduR version information to the passed pointer        */  \
            (versionInfo)->moduleID           = PDUR_MODULE_ID;                \
            (versionInfo)->sw_major_version   = PDUR_SW_MAJOR_VERSION;         \
            (versionInfo)->sw_minor_version   = PDUR_SW_MINOR_VERSION;         \
            (versionInfo)->sw_patch_version   = PDUR_SW_PATCH_VERSION;         \
            (versionInfo)->vendorID           = PDUR_VENDOR_ID;                \
        }                                                                      \
    }                                                                          \
} while (1==0)
#else /*  (PduR_bDEV_ERROR_DETECT == STD_OFF) */
#define PduR_GetVersionInfo(versionInfo) do {                                  \
    /*! Check module's initialization                                      */  \
    if(PduR_u8eState == PDUR_UNINIT)                                           \
    {                                                                          \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        /*! Check versionInfo pointer if NULL or not                       */  \
        if((versionInfo) == NULL_PTR)                                          \
        {                                                                      \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /*! Copy PduR version information to the passed pointer        */  \
            (versionInfo)->moduleID           = PDUR_MODULE_ID;                \
            (versionInfo)->sw_major_version   = PDUR_SW_MAJOR_VERSION;         \
            (versionInfo)->sw_minor_version   = PDUR_SW_MINOR_VERSION;         \
            (versionInfo)->sw_patch_version   = PDUR_SW_PATCH_VERSION;         \
            (versionInfo)->vendorID           = PDUR_VENDOR_ID;                \
        }                                                                      \
    }                                                                          \
} while (1==0)
#endif /* #if(PduR_bDEV_ERROR_DETECT == STD_ON) */
#else
#if(PduR_bDEV_ERROR_DETECT == STD_ON)
#define PduR_GetVersionInfo(versionInfo) do {                                  \
    /*! Check versionInfo pointer if NULL or not                           */  \
    if((versionInfo) == NULL_PTR)                                              \
    {                                                                          \
        /*! Report to DET                                                  */  \
        (void) Det_ReportError( PDUR_MODULE_ID, 0,                             \
                                PduR_u8GETVRSNINFO_API_ID,                     \
                                PDUR_E_NULL_POINTER);                          \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        /*! Copy PduR version information to the passed pointer            */  \
        (versionInfo)->moduleID           = PDUR_MODULE_ID;                    \
        (versionInfo)->sw_major_version   = PDUR_SW_MAJOR_VERSION;             \
        (versionInfo)->sw_minor_version   = PDUR_SW_MINOR_VERSION;             \
        (versionInfo)->sw_patch_version   = PDUR_SW_PATCH_VERSION;             \
        (versionInfo)->vendorID           = PDUR_VENDOR_ID;                    \
    }                                                                          \
} while (1==0)
#else /*  (PduR_bDEV_ERROR_DETECT == STD_OFF) */
#define PduR_GetVersionInfo(versionInfo) do {                                  \
    /*! Check versionInfo pointer if NULL or not                       */      \
    if((versionInfo) == NULL_PTR)                                              \
    {                                                                          \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        /*! Copy PduR version information to the passed pointer        */      \
        (versionInfo)->moduleID           = PDUR_MODULE_ID;                    \
        (versionInfo)->sw_major_version   = PDUR_SW_MAJOR_VERSION;             \
        (versionInfo)->sw_minor_version   = PDUR_SW_MINOR_VERSION;             \
        (versionInfo)->sw_patch_version   = PDUR_SW_PATCH_VERSION;             \
        (versionInfo)->vendorID           = PDUR_VENDOR_ID;                    \
    }                                                                          \
} while (1==0)
#endif /* #if(PduR_bDEV_ERROR_DETECT == STD_ON) */
#endif /* #if(PduR_bZERO_COST_OPERATION == STD_OFF) */
#endif /* #if(PduR_bVERSION_INFO_API == STD_ON) */
/* PRQA S 3412 --                                                             */
/* PRQA S 3456 --                                                             */


#endif /* PDUR_H */

/*------------------------------- end of file --------------------------------*/

