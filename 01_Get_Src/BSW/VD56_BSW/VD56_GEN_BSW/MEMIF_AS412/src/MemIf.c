/******************************************************************************/
/*                                                                            */
/* !Layer           : ECU Abstraction Layer                                   */
/*                                                                            */
/* !Component       : MemIf                                                   */
/* !Description     : AutOSAR Memory Abstraction Interface component          */
/*                                                                            */
/* !Module          : MemIf                                                   */
/* !Description     : Memory Abstraction Interface main module                */
/*                                                                            */
/* !File            : MemIf.c                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO - All Rights Reserved                                 */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/* $Header:   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/13_MemIf/02_Development/02_Source_Code/02_Source_Files/MemIf.c-arc   1.18   Jun 24 2014 09:59:26   AABDELSALAM  $
******************************************************************************/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.9            R1.1.0   AR4.1                                 */
/* Done by    : M.Taymour                                     Date : 17/02/14 */
/* Description: Update SW versions check                                      */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.8            R1.1.0   AR4.0                                 */
/* Done by    : M.El-Ashmawy                                  Date : 18/09/12 */
/* Description: - Fixed MISRA warnings                                        */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.7            R1.1.0   AR4.0                                 */
/* Done by    : M.El-Ashmawy                                  Date : 27/08/12 */
/* Description: - Fixed Team Track Tickets #02760,#02884 and #03130           */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.6            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/10/11 */
/* Description: - Updated to take into account the return of Det_ReportError. */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.5            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 29/09/11 */
/* Description: - Updated after solving some QAC warnings and testing bugs.    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.4            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 20/09/11 */
/* Description: - Updated in the inter module version checking part.    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.3            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 14/09/11 */
/* Description: - Updated after applying the "Coding Guidelines" docuemt.    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.2.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/09/11 */
/* Description: - Updated after running VNR.                    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.1.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/09/11 */
/* Description: - Updated after solving peer review bugs.                    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.0.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 10/05/11 */
/* Description: - Initial version for AUTOSAR Release 4.0.                    */
/******************************************************************************/
/*-- Include component internals --*/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0002                                        */
#include "MemIf.h"
/*! \Trace_To  GSCSW-MemIf-SDD-001-0002                                     */
/*-- Include component externals --*/

/* Development Error Tracer Module Definition File                            */
/*! \Trace_To   GSCSW-MemIf-SDD-001-0003                                  */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif


/******************************************************************************/
/* Inter Module Checking                   */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0200                                  */

#if (MEMIF_bINTER_MOD_VER_CHECK == STD_ON)

#if (MEMIF_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)
    #error "Compiler AR RELEASE MAJOR VERSION is not compatible with MEMIF AR RELEASE MAJOR VERSION"
#endif
#if (MEMIF_AR_RELEASE_MINOR_VERSION < COMPILER_AR_RELEASE_MINOR_VERSION)
    #error "Compiler AR RELEASE MINOR VERSION is not compatible with MEMIF AR RELEASE MINOR VERSION"
#endif

#if (MEMIF_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)
    #error "Platform Types AR RELEASE MAJOR VERSION is not compatible with MEMIF AR RELEASE MAJOR VERSION"
#endif
#if (MEMIF_AR_RELEASE_MINOR_VERSION < PLATFORM_AR_RELEASE_MINOR_VERSION)
    #error "Platform Types AR RELEASE MINOR VERSION is not compatible with MEMIF AR RELEASE MINOR VERSION"
#endif

#if (MEMIF_AR_RELEASE_MAJOR_VERSION != MEM_AR_RELEASE_MAJOR_VERSION)
    #error "MemMap AR RELEASE MAJOR VERSION is not compatible with MEMIF AR RELEASE MAJOR VERSION"
#endif
#if (MEMIF_AR_RELEASE_MINOR_VERSION < MEM_AR_RELEASE_MINOR_VERSION)
    #error "MemMap AR RELEASE MINOR VERSION is not compatible with MEMIF AR RELEASE MINOR VERSION"
#endif

#if (MEMIF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
    #error "StdTypes AR RELEASE MAJOR VERSION is not compatible with MEMIF AR RELEASE MAJOR VERSION"
#endif
#if (MEMIF_AR_RELEASE_MINOR_VERSION < STD_AR_RELEASE_MINOR_VERSION)
    #error "StdTypes AR RELEASE MINOR VERSION is not compatible with MEMIF AR RELEASE MINOR VERSION"
#endif

#if (MEMIF_bUSE_EA == STD_ON)
/* Major AR version of the MemIf and Ea modules      */
#if (MEMIF_AR_RELEASE_MAJOR_VERSION != EA_AR_RELEASE_MAJOR_VERSION)
    #error "EA AR RELEASE MAJOR VERSION is not compatible with MEMIF AR RELEASE MAJOR VERSION"
#endif
/* Minor AR version of the MemIf and Ea modules      */
#if (MEMIF_AR_RELEASE_MINOR_VERSION != EA_AR_RELEASE_MINOR_VERSION)
    #error "EA AR RELEASE MINOR VERSION is not compatible with MEMIF AR RELEASE MINOR VERSION"
#endif
#endif /* (MEMIF_bUSE_EA == STD_ON) */

#if (MEMIF_bUSE_FEE == STD_ON)
/* Major AR version of the MemIf and Fee modules      */
#if (MEMIF_AR_RELEASE_MAJOR_VERSION != FEE_AR_RELEASE_MAJOR_VERSION)
    #error "FEE AR RELEASE MAJOR VERSION is not compatible with MEMIF AR RELEASE MAJOR VERSION"
#endif
/* Minor AR version of the MemIf and Fee modules      */
#if (MEMIF_AR_RELEASE_MINOR_VERSION < FEE_AR_RELEASE_MINOR_VERSION)
    #error "FEE AR RELEASE MINOR VERSION is not compatible with MEMIF AR RELEASE MINOR VERSION"
#endif
#endif /* (MEMIF_bUSE_FEE == STD_ON) */

#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
/* Check the compatibility between MemIf and included modules             */
    /* Major AR version of the MemIf and Det modules      */
#if (MEMIF_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
  #error "DET AR RELEASE MAJOR VERSION is not compatible with MEMIF AR RELEASE MAJOR VERSION"
#endif
    /* Minor AR version of the MemIf and Det modules      */
#if (MEMIF_AR_RELEASE_MINOR_VERSION < DET_AR_RELEASE_MINOR_VERSION)
  #error "DET AR RELEASE MINOR VERSION is not compatible with MEMIF AR RELEASE MINOR VERSION"
#endif
#endif /* MEMIF_DEV_ERROR_DETECT == STD_ON */

#endif /* #if (MEMIF_bINTER_MOD_VER_CHECK == STD_ON) */

/* !Deviation :                                                               */
/*  Inhibit message number 750. Local macro used on MemMap not referenced     */
/*  Inhibit message number 760. Redundant macro used on MemMap                */
/*  Inhibit message number 961. Multiple use of #define for MemMap            */
/*  Inhibit message number 537. Repeated include for MemMap                   */
/*  Inhibit message number 960. Use of '#undef' is discouraged                */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
#define MEMIF_START_SEC_CODE /*## Open Code Section ##                        */
#include "MemMap.h"
/*lint -restore                                                               */

/*============================================================================*/
/*=== Synchronous API Bodies =================================================*/
/*============================================================================*/

#if (MEMIF_NUMBER_OF_DEVICES > 1U)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, MEMIF_CODE) MemIf_SetMode

(
  /*!  Expected drivers speed mode.       */
  VAR(MemIf_ModeType, AUTOMATIC) Mode
)

{
    /* !Deviation : Inhibit MISRA rule [3197] as the variable is initialized    */
    /*              then modified before being used in the for loop             */
    /* PRQA S 3197 ++                                                           */
    /*!  Device index for browsing wrapping table  */
    VAR(uint8_least, AUTOMATIC) u8DeviceIdx = (uint8) 0;
  /* PRQA S 3197 --                                                           */

/* PRQA S 0850 --                                                             */

  /*!  Browse all configured devices and call respective SetMode APIs */
    for (u8DeviceIdx = (uint8) 0;
       u8DeviceIdx < ((uint8)MEMIF_NUMBER_OF_DEVICES);
       u8DeviceIdx++)
    {
    /* !Deviation : Inhibit MISRA rule [20] because configuration calsses and   */
    /*              types are defined in MemIf_Types.h which is included through*/
    /*                  the abstarction modules according to the modified file      */
    /*                  architecture specified by CEE requirements                  */

    /* !Deviation : Inhibit MISRA rule [3332] because configuration calsses and */
    /*              types are defined in MemIf_Types.h which is included through*/
    /*                  the abstarction modules according to the modified file      */
    /*                  architecture specified by CEE requirements                  */

    /*lint -save -vo -e409 -e10 -e40 -e808 -e522 -v                             */
    /* PRQA S 3332 ++                                                           */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
        MemIf_kapfudteSetModeApiCfg[u8DeviceIdx](Mode);
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
    }
}

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex
)
{
    /* !Deviation : Inhibit MISRA rule [3197] as the variable enuDeviceStatus   */
    /*              is initialized then modified by the function call before    */
    /*              using the modified value                                    */
    /* PRQA S 3197 ++                                                           */
    /*!  Device index for browsing wrapping table  */
    VAR(uint8_least, AUTOMATIC)            u8DeviceIdx = (uint8) 0;

    /*!  Resulting status      */
    VAR(MemIf_StatusType, AUTOMATIC)       enuCompiledStatus = MEMIF_UNINIT;

    /*!  Unitary device status */
    VAR(MemIf_StatusType, AUTOMATIC)       enuDeviceStatus   = MEMIF_UNINIT;
  /* PRQA S 3197 ++                                                           */

/* PRQA S 0850 --                                                             */

/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  IF [Device index is out of range] and                          
             [Device index different from broadcast index] THEN             */
    if ((DeviceIndex >= ((uint8)MEMIF_NUMBER_OF_DEVICES)) &&
      (DeviceIndex != MEMIF_BROADCAST_ID))
    {
    /*!  Report "parameter device" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030, GSCSW-MemIf-SDD-001-0011          */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_GET_STATUS, MEMIF_E_PARAM_DEVICE);
    }
  /*!  ELSE [No other error to detect] THEN                           */
    else
/*!  ### ENDIF [Development mode] ###                                 */
#endif

  /*!  IF [Input device index corresponds to broadcast index] THEN    */
    if (DeviceIndex == MEMIF_BROADCAST_ID)
    {
    /*!  Compilation of all statuses : initialize result to the       
               lowest priority status, i.e. IDLE                            */
        enuCompiledStatus = MEMIF_IDLE;

    /*!  Browse all devices and call respective GetStatus APIs,       
               exit loop if an UNINIT status has been found                 */
        while ((u8DeviceIdx < ((uint8)MEMIF_NUMBER_OF_DEVICES)) &&
           (enuCompiledStatus != MEMIF_UNINIT))
        {
      /* !Deviation : Inhibit MISRA rule [20] because configuration calsses and */
      /*              types are defined in MemIf_Types.h which is included      */
      /*                  through the abstarction modules according to the modified */
      /*                  file architecture specified by CEE requirements           */

      /* !Deviation : Inhibit MISRA rule [3332] because configuration calsses   */
      /*              and types are defined in MemIf_Types.h which is included  */
      /*                  through the abstarction modules according to the modified */
      /*                  file architecture specified by CEE requirements           */

      /*lint -save -vo -e409 -e10 -e40 -e808 -e522 -v                           */
      /* PRQA S 3332 ++                                                         */
    /*!  Call the currently selected device's GetStatus API           */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
            enuDeviceStatus = MemIf_kapfudteGetStatusApiCfg[u8DeviceIdx]();
    /* PRQA S 3332 --                                                         */
      /*lint -restore                                                           */
    /*!  IF [Returned device status priority > current result] THEN   */
            if (enuDeviceStatus > enuCompiledStatus)
            {
        /*!  High priority status => store this device status as the  
                   final compiled status                                    */
                enuCompiledStatus = enuDeviceStatus;
            }
      /*!  ELSE [Returned status priority <= current result] THEN     */
            else
            {
                 /*!  Do nothing                          */
            }
      /*!  ENDIF [Returned device status priority]                    */

      /*!  Move to next device to be browsed                          */
            u8DeviceIdx++;
        }

    }
  /*!  ELSE [Input device index different from broadcast index] THEN  */
    else
    {
    /* !Deviation : Inhibit MISRA rule [20] because configuration calsses and   */
    /*              types are defined in MemIf_Types.h which is included through*/
    /*                  the abstarction modules according to the modified file      */
    /*                  architecture specified by CEE requirements                  */

    /* !Deviation : Inhibit MISRA rule [3332] because configuration calsses and */
    /*              types are defined in MemIf_Types.h which is included through*/
    /*                  the abstarction modules according to the modified file      */
    /*                  architecture specified by CEE requirements                  */

    /*lint -save -vo -e409 -e10 -e40 -e808 -e522 -v                             */
    /* PRQA S 3332 ++                                                           */
  /*!  Call the selected device's GetStatus API and return result     */
  /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
        enuCompiledStatus = MemIf_kapfudteGetStatusApiCfg[DeviceIndex]();
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
    }

    return(enuCompiledStatus);

}

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex
)
{

    /*!  Returned job result */
    VAR(MemIf_JobResultType, AUTOMATIC) enuJobResult = MEMIF_JOB_FAILED;

/* PRQA S 0850 --                                                             */

/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  IF [Device index is out of range]                           */
    if (DeviceIndex >= ((uint8)MEMIF_NUMBER_OF_DEVICES))
    {
    /*!  Report "parameter device" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030, GSCSW-MemIf-SDD-001-0011          */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_GET_JOB_RESULT, MEMIF_E_PARAM_DEVICE);
    }
  /*!  ELSE [No other error to detect] THEN                           */
    else
    {
/*!  ### ENDIF [Development mode] ###                                 */
#endif
    /* !Deviation:  Inhibit MISRA rule [20] because   configuration calsses     */
    /*               and types  are defined in MemIf_Types.h which is included  */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /*lint -save -vo -e409 -e10 -e40 -e808  -v                                  */
    /* !Deviation:  Inhibit MISRA rule [3332] because   configuration calsses   */
    /*              and types  are defined in MemIf_Types.h which is included   */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /* PRQA S 3332 ++                                                           */
    /*!  Call selected device's GetJobResult API and return result    */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
    /* PRQA S 2215 ++                                                           */
        enuJobResult = MemIf_kapfudteGetJobResuApiCfg[DeviceIndex]();
    /* PRQA S 2215 --                                                           */
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
    /*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    }
    /*!  ### ENDIF [Development mode] ###                                 */
#endif

    return(enuJobResult);
}
#endif /* MEMIF_NUMBER_OF_DEVICES */

#if (MEMIF_VERSION_INFO_API == STD_ON)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, MEMIF_CODE) MemIf_GetVersionInfo
(
  /*!  Pointer to version structure. */
  P2VAR(Std_VersionInfoType, AUTOMATIC, MEMIF_APPL_DATA) VersionInfoPtr
  /* PRQA S 0850 --                                                           */
)
{
/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  Check that the passed pointer is not NULL                      */
    if(VersionInfoPtr == NULL_PTR)
    {
    /*!  Report "parameter device" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030                              */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_GET_VERSION_INFO, MEMIF_E_PARAM_POINTER);
    }
  /*!  ELSE [No other error to detect] THEN                           */
    else
    {
 /*!  ### ENDIF [Development mode] ###                                 */
#endif
    /*!   Set version info container with configured Module ID, Vendor
                ID and configured component version numbering               */
        VersionInfoPtr->vendorID = (uint16)MEMIF_VENDOR_ID;
        VersionInfoPtr->moduleID = (uint16)MEMIF_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)MEMIF_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)MEMIF_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)MEMIF_SW_PATCH_VERSION;
/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    }
 /*!  ### ENDIF [Development mode] ###                                 */
#endif
}
#endif /* MEMIF_VERSION_INFO_API */


/*===========================================================================*/
/*=== Asynchronous API prototypes ===========================================*/
/*===========================================================================*/

#if (MEMIF_NUMBER_OF_DEVICES > 1U)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex,

  /*!  Number of the logical block.      */
  VAR(uint16, AUTOMATIC)  BlockNumber,

  /*!  Address offset inside the block.  */
  VAR(uint16, AUTOMATIC)  BlockOffset,

  /*!  Pointer to destination RAM block. */
  P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr,

  /*!  Number of bytes to be read.       */
  VAR(uint16, AUTOMATIC)  Length
)
{

    /*!  Device's API returned value   */
    VAR(Std_ReturnType, AUTOMATIC) udtDeviceReturn = E_NOT_OK;
/*PRQA S 0850--                            */

/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  Check that the passed pointer is not NULL                      */
    if(DataBufferPtr != NULL_PTR)
    {
    /*!  IF [Device index is out of range]                           */
        if (DeviceIndex < ((uint8)MEMIF_NUMBER_OF_DEVICES))
        {
#endif
    /* !Deviation:  Inhibit MISRA rule [20] because   configuration calsses     */
    /*                and types  are defined in MemIf_Types.h which is included */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /*lint -save -vo -e409 -e10 -e40 -e808  -v                                  */
    /* !Deviation:  Inhibit MISRA rule [3332] because   configuration calsses   */
    /*               and types  are defined in MemIf_Types.h which is included  */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /* PRQA S 3332 ++                                                           */
    /*!  Call selected device's Read API and return error code        */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
            udtDeviceReturn = MemIf_kapfudteReadApiCfg[DeviceIndex](
                                                    BlockNumber, BlockOffset,
                                                    DataBufferPtr, Length);
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
        /*!  Report "parameter device" error to DET                 */
        /*! \Trace_To  GSCSW-MemIf-SDD-001-0030, GSCSW-MemIf-SDD-001-0011     */
            (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                        MEMIF_u8SID_READ, MEMIF_E_PARAM_DEVICE);
        }

    }
  /*!  ELSE [No other error to detect] THEN                       */
    else
    {
    /*!  Report "parameter pointer" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030                              */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_READ, MEMIF_E_PARAM_POINTER);
    }
/*!  ### ENDIF [Development mode] ###                                 */
#endif

    return(udtDeviceReturn);
}



/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex,

  /*!  Number of the logical block.      */
  VAR(uint16, AUTOMATIC)  BlockNumber,

  /*!  Pointer to source RAM block.      */
  P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr

)
{
    /*!  Device's API returned value   */
    VAR(Std_ReturnType, AUTOMATIC) udtDeviceReturn = E_NOT_OK;
/*PRQA S 0850--                            */

/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  Check that the passed pointer is not NULL                      */
    if(DataBufferPtr != NULL_PTR)
    {
    /*!  IF [Device index is out of range]                           */
        if (DeviceIndex < ((uint8)MEMIF_NUMBER_OF_DEVICES))
        {
#endif
    /* !Deviation:  Inhibit MISRA rule [20] because   configuration calsses     */
    /*              and types  are defined in MemIf_Types.h which is included   */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /*lint -save -vo -e409 -e10 -e40 -e808  -v                                  */
    /* !Deviation:  Inhibit MISRA rule [3332] because   configuration calsses   */
    /*              and types  are defined in MemIf_Types.h which is included   */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /* PRQA S 3332 ++                                                           */
    /*!  Call selected device's Write API and return error code       */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
            udtDeviceReturn = MemIf_kapfudteWriteApiCfg[DeviceIndex](
                                                   BlockNumber, DataBufferPtr);
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
        /*!  Report "parameter device" error to DET                 */
        /*! \Trace_To  GSCSW-MemIf-SDD-001-0030, GSCSW-MemIf-SDD-001-0011     */
            (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                        MEMIF_u8SID_WRITE, MEMIF_E_PARAM_DEVICE);
        }

    }
  /*!  ELSE [No other error to detect] THEN                       */
    else
    {
    /*!  Report "parameter pointer" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030                              */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_WRITE, MEMIF_E_PARAM_POINTER);
    }
/*!  ### ENDIF [Development mode] ###                                 */
#endif

    return(udtDeviceReturn);
}


/* !Deviation:  Inhibit MISRA rule [97] because   configuration calsses  are*/
/*                  defined in MemIf_Types.h which is included through  the*/
/*         abstarction modules according to the modified file  architecture */
/*         specified by CEE requirements */
/*lint -save -vo -e553 -v                                                     */
/* !Deviation:  Inhibit MISRA rule [3332] because configuration calsses  are*/
/*                  defined in MemIf_Types.h which is included through  the*/
/*         abstarction modules according to the modified file  architecture */
/*         specified by CEE requirements */
/* PRQA S 3332 ++                                                             */
#if (MEMIF_u8API_CONFIG_CLASS == MEMIF_u8API_CONFIG_CLASS_2)
/* PRQA S 3332 --                                                     */
/*lint -restore                                                               */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex,

  /*!  Number of the logical block.      */
  VAR(uint16, AUTOMATIC)  BlockNumber
)
{

    /*!  Device's API returned value   */
    VAR(Std_ReturnType, AUTOMATIC) udtDeviceReturn = E_NOT_OK;
/*PRQA S 0850--                            */

/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  IF [Device index is out of range]                           */
    if (DeviceIndex >= ((uint8)MEMIF_NUMBER_OF_DEVICES))
    {
    /*!  Report "parameter device" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030, GSCSW-MemIf-SDD-001-0011          */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_INVALIDATE_BLOCK, MEMIF_E_PARAM_DEVICE);
    }
  /*!  ELSE [No other error to detect] THEN                           */
    else
    {
/*!  ### ENDIF [Development mode] ###                                 */
#endif
    /* !Deviation:  Inhibit MISRA rule [20] because   configuration calsses     */
    /*              and types  are defined in MemIf_Types.h which is included   */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /*lint -save -vo -e409 -e10 -e40 -e808  -v                                  */
    /* !Deviation:  Inhibit MISRA rule [3332] because   configuration calsses   */
    /*              and types  are defined in MemIf_Types.h which is included   */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /* PRQA S 3332 ++                                                           */
    /*!  Call selected device's InvalidateBlock API and return
                 error code                                                   */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
        udtDeviceReturn = MemIf_kapfudteInvalidBlckApiCfg[DeviceIndex](
                                                                  BlockNumber);
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    }
/*!  ### ENDIF [Development mode] ###                                 */
#endif

    return(udtDeviceReturn);
}


/* !Deviation:  Inhibit MISRA rule [97] because   configuration calsses  are*/
/*                  defined in MemIf_Types.h which is included through  the*/
/*         abstarction modules according to the modified file  architecture */
/*         specified by CEE requirements */
/*lint -save -vo -e553 -v                                                     */
/* !Deviation:  Inhibit MISRA rule [3332] because configuration calsses  are*/
/*                  defined in MemIf_Types.h which is included through  the*/
/*         abstarction modules according to the modified file  architecture */
/*         specified by CEE requirements */
/* PRQA S 3332 ++                                                             */

/* PRQA S 3332 --                                                     */
/*lint -restore                                                               */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex,

  /*!  Number of the logical block.      */
  VAR(uint16, AUTOMATIC)  BlockNumber
)
{

    /*!  Device's API returned value   */
    VAR(Std_ReturnType, AUTOMATIC) udtDeviceReturn = E_NOT_OK;

/*PRQA S 0850--                            */

/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  IF [Device index is out of range]                           */
    if (DeviceIndex >= ((uint8)MEMIF_NUMBER_OF_DEVICES))
    {
    /*!  Report "parameter device" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030, GSCSW-MemIf-SDD-001-0011          */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_ERASE_IMDT_BLOCK, MEMIF_E_PARAM_DEVICE);
    }
  /*!  ELSE [No other error to detect] THEN                           */
    else
    {
/*!  ### ENDIF [Development mode] ###                                 */
#endif
    /* !Deviation:  Inhibit MISRA rule [20] because   configuration calsses     */
    /*              and types  are defined in MemIf_Types.h which is included   */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /*lint -save -vo -e409 -e10 -e40 -e808  -v                                  */
    /* !Deviation:  Inhibit MISRA rule [3332] because   configuration calsses   */
    /*               and types  are defined in MemIf_Types.h which is included  */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /* PRQA S 3332 ++                                                           */
  /*!  Call selected device's EraseImmediateBlock API and return      
             error code                                                     */
  /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
        udtDeviceReturn = MemIf_kapfudteErsImdtBlckApiCfg[DeviceIndex](BlockNumber);
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    }
/*!  ### ENDIF [Development mode] ###                                 */
#endif

    return(udtDeviceReturn);
}


/* !Deviation:  Inhibit MISRA rule [97] because   configuration calsses  are*/
/*                  defined in MemIf_Types.h which is included through  the*/
/*         abstarction modules according to the modified file  architecture */
/*         specified by CEE requirements */
/*lint -save -vo -e553 -v                                                     */
/* !Deviation:  Inhibit MISRA rule [3332] because configuration calsses  are*/
/*                  defined in MemIf_Types.h which is included through  the*/
/*         abstarction modules according to the modified file  architecture */
/*         specified by CEE requirements */
/* PRQA S 3332 ++                                                             */


/* PRQA S 3332 --                                                     */
/*lint -restore                                                               */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, MEMIF_CODE) MemIf_Cancel
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex
)
/*PRQA S 0850--                            */
{
/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
  /*!  IF [Device index is out of range]                           */
    if (DeviceIndex >= ((uint8)MEMIF_NUMBER_OF_DEVICES))
    {
    /*!  Report "parameter device" error to DET                      */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0030, GSCSW-MemIf-SDD-001-0011          */
        (void) Det_ReportError((uint16)MEMIF_MODULE_ID, u8MEMIF_INSTANCE_ID,
                    MEMIF_u8SID_CANCEL, MEMIF_E_PARAM_DEVICE);
    }
  /*!  ELSE [No other error to detect] THEN                           */
    else
    {
/*!  ### ENDIF [Development mode] ###                                 */
#endif
    /* !Deviation:  Inhibit MISRA rule [20] because   configuration calsses     */
    /*               and types  are defined in MemIf_Types.h which is included  */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /*lint -save -vo -e409 -e10 -e40 -e808  -e522 -v                            */
    /* !Deviation:  Inhibit MISRA rule [3332] because   configuration calsses   */
    /*               and types  are defined in MemIf_Types.h which is included  */
    /*         through  the abstarction modules according to the modified file      */
    /*         architecturespecified by CEE requirements                            */
    /* PRQA S 3332 ++                                                           */
    /*!  Call selected device's Cancel API                            */
    /*! \Trace_To  GSCSW-MemIf-SDD-001-0010                                  */
        MemIf_kapfudteCancelApiCfg[DeviceIndex]();
    /* PRQA S 3332 --                                                           */
    /*lint -restore                                                             */
/*!  ### IF [Development mode activated] THEN ###                     */
#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
    }
/*!  ### ENDIF [Development mode] ###                                 */
#endif
}
#endif /* MEMIF_u8API_CONFIG_CLASS     */

#endif /* MEMIF_NUMBER_OF_DEVICES */


/* inhibit message number 750 because local macro used on MemMap not          */
/* referenced                                                                 */
/* inhibit message number 760 because Redundant macro used on MemMap          */
/* inhibit message number 961 because multiple use of #define for MemMap      */
/* inhibit message number 537 because Repeated include for MemMap             */
/* inhibit message number 960 because use of '#undef' is discouraged          */
/* inhibit message number 766 because include of MemMap at end of file        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -e766 -v                       */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */

#define MEMIF_STOP_SEC_CODE /*## Close code section ##                        */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */


/*==== End of file ==========================================================*/
