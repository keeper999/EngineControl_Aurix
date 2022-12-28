/******************************************************************************/
/*                                                                            */
/* !Layer           : ECU Abstraction Layer                                   */
/*                                                                            */
/* !Component       : MemIf                                                   */
/* !Description     : AutOSAR Memory Abstraction Interface component    */
/*                                                                            */
/* !Module          : MemIf                                                   */
/* !Description     : Memory Abstraction Interface main module                */
/*                                                                            */
/* !File            : MemIf.h                                                 */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2008 VALEO - All Rights Reserved                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/* $Header:   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/13_MemIf/02_Development/02_Source_Code/03_Header_Files/MemIf.h-arc   1.13   Jun 10 2014 11:23:04   AELSOHBY  $
*******************************************************************************/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.12            R1.1.0   AR4.1                                */
/* Done by    : M.Taymour                                     Date : 17/02/14 */
/* Description: - Update SW version to 2.0 and AR Release versoin to 4.1.2    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.11            R1.1.0   AR4.0                                */
/* Done by    : M.Wadid                                       Date : 21/03/13 */
/* Description: - Modified MEMIF_SW_PATCH_VERSION                             */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.10            R1.1.0   AR4.0                                */
/* Done by    : M.Amroussy                                     Date : 18/09/12 */
/* Description: - Modified MEMIF_SW_PATCH_VERSION                             */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.9            R1.1.0   AR4.0                                 */
/* Done by    : M.El-Ashmawy                                  Date : 18/09/12 */
/* Description: - Modified MEMIF_SW_PATCH_VERSION                             */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.8            R1.1.0   AR4.0                                 */
/* Done by    : M.El-Ashmawy                                  Date : 28/08/12 */
/* Description: - Fixed history of previous release                           */
/*                (Added inclusion of Std_Types.h (related to TTT #03053)     */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.7            R1.1.0   AR4.0                                 */
/* Done by    : M.El-Ashmawy                                  Date : 28/08/12 */
/* Description: - Added inclusion of Std_Types.h (related to TTT #03053)      */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.6            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 22/09/11 */
/* Description: - Updated in "Private Component Defines" part of the file.*/
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.5            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 19/09/11 */
/* Description: - Removed the "Inter Module Version Checking"; done in c file.*/
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.4            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 14/09/11 */
/* Description: - Updated after applying the "Coding Guidelines" docuemt.    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.3            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/09/11 */
/* Description: - Updated after running VNR.                    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.2              R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/09/11     */
/* Description: - Updated after solving peer review bugs.                     */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.1          R1.0.0   AR4.0                                   */
/* Done by    : A.Farid                                       Date : 25/07/11 */
/* Description: - Updated after migrating to the new folder structure         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.0.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 10/05/11 */
/* Description: - Initial version for AUTOSAR Release 4.0.                    */
/******************************************************************************/
#ifndef MEMIF_H
#define MEMIF_H

#include "Std_Types.h"
/*-- Include component internals --*/
#include "MemIf_Cfg.h"


/*============================================================================*/
/*=== Published Information ==================================================*/
/*============================================================================*/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0036, GSCSW-MemIf-SDD-001-0006              */

/*!  Module ID of the 'MemIf' module from Module List                */
#define MEMIF_MODULE_ID                       (22U)

/*!  Vendor ID of the dedicated implementation of this module
              according to the AUTOSAR vendor list                            */
#define MEMIF_VENDOR_ID                       (38U)

/*!  Major version number of AUTOSAR specification on which the      
              appropriate implementation is based on.                         */
#define MEMIF_AR_RELEASE_MAJOR_VERSION        (4U)

/*!  Minor version number of AUTOSAR specification on which the   
              appropriate implementation is based on.                         */
#define MEMIF_AR_RELEASE_MINOR_VERSION        (1U)

/*!  Release revision number of AUTOSAR specification on which     
              the appropriate implementation is based on.                     */
#define MEMIF_AR_RELEASE_REVISION_VERSION     (2U)

/*!  Major version number of the vendor specific implementation of   
              the module. The numbering is vendor specific.                   */
#define MEMIF_SW_MAJOR_VERSION                (2U)

/*!  Minor version number of the vendor specific implementation of   
              the module. The numbering is vendor specific.                   */
#define MEMIF_SW_MINOR_VERSION                (0U)

/*!  Patch level version number of the vendor specific   
              implementation of the module. The numbering is vendor specific. */
#define MEMIF_SW_PATCH_VERSION                (0U)

/*!  Identifier that shall be used by upper layers to adress all 
              meory devices in the call of MemIf_GetStatus (broadcast index). */
#define MEMIF_BROADCAST_ID                    ((uint8)0xFF)

/*!  Instance ID of MemIf module, set to 0 since not other possible */
#define u8MEMIF_INSTANCE_ID            ((uint8)0x00)


/*============================================================================*/
/*=== Private Component Defines ==============================================*/
/*============================================================================*/

#if (MEMIF_DEV_ERROR_DETECT == STD_ON) 

/*!  GetVersionInfo API ID.                    */
#define MEMIF_u8SID_GET_VERSION_INFO         ((uint8)0x0A)

#if (MEMIF_NUMBER_OF_DEVICES > 1U)

/*--- Service IDs defines ----------------------------------------------------*/

/* !MComment : EA module service IDs                                          */
#define MEMIF_u8SID_READ                     ((uint8)0x02)
#define MEMIF_u8SID_WRITE                    ((uint8)0x03)
#define MEMIF_u8SID_CANCEL                   ((uint8)0x04)
#define MEMIF_u8SID_GET_STATUS               ((uint8)0x05)
#define MEMIF_u8SID_GET_JOB_RESULT           ((uint8)0x06)


/* !Deviation : Inhibit MISRA rule [97] because configuration calsses and     */
/*              types are defined in MemIf_Types.h which is included through  */
/*                  the abstarction modules according to the modified file        */
/*                  architecture specified by CEE requirements                    */

/* !Deviation : Inhibit MISRA rule [3332] because configuration calsses and   */
/*              types are defined in MemIf_Types.h which is included through  */
/*                  the abstarction modules according to the modified file        */
/*                  architecture specified by CEE requirements                    */

/* PRQA S 3332 ++                                                             */
/*lint -save -vo -e553 -v                                                     */
#if (MEMIF_u8API_CONFIG_CLASS == MEMIF_u8API_CONFIG_CLASS_2)
  #define MEMIF_u8SID_INVALIDATE_BLOCK       ((uint8)0x07)
  #define MEMIF_u8SID_ERASE_IMDT_BLOCK       ((uint8)0x09)
#endif /* MEMIF_u8API_CONFIG_CLASS */
/* PRQA S 3332 --                                                             */
/*lint -restore                                                               */

/*--- DET Error Codes Defines ------------------------------------------------*/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0003                                       */

/*!  API service called with invalid device index                   */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0106                                       */
#define MEMIF_E_PARAM_DEVICE           ((uint8)0x01)

#endif /* MEMIF_NUMBER_OF_DEVICES */

/*!  API service called with NULL pointer argument                 */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0107                                       */
#define MEMIF_E_PARAM_POINTER          ((uint8)0x02)

#endif /* MEMIF_DEV_ERROR_DETECT */

/*============================================================================*/
/*=== Implementation Version Checking ========================================*/
/*============================================================================*/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0101                                       */

/* Check this component version information toward configured one             */
#ifdef MEMIF_CFG_MAJOR_VERSION 
  #ifdef MEMIF_CFG_MINOR_VERSION
    
    /* Major version of the vendor specific implementation of MemIf module    */
    #if (MEMIF_SW_MAJOR_VERSION != MEMIF_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif
 
    /* Minor version of the vendor specific implementation of MemIf module    */
    #if (MEMIF_SW_MINOR_VERSION > MEMIF_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif

  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* MEMIF_CFG_MINOR_VERSION */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif /* MEMIF_CFG_MAJOR_VERSION */


/*============================================================================*/
/*=== Public Component API Prototypes ========================================*/
/*============================================================================*/

/* !Deviation :                                                               */
/*  Inhibit message number 750. Local macro used on MemMap not referenced     */
/*  Inhibit message number 760. Redundant macro used on MemMap                */
/*  Inhibit message number 961. Multiple use of #define for MemMap            */
/*  Inhibit message number 537. Repeated include for MemMap                   */
/*  Inhibit message number 960. Use of '#undef' is discouraged                */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
#define MEMIF_START_SEC_CODE /*## Open code section ##                        */
#include "MemMap.h"
/*lint -restore                                                               */

/*--- Synchronous APIs -------------------------------------------------------*/

#if (MEMIF_NUMBER_OF_DEVICES > 1U) 
/******************************************************************************/
/*! \Description  API to change the operation speed mode of the underlying    
                memory device drivers. Note: broadcasted to all devices.    */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0013                                      */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, MEMIF_CODE) MemIf_SetMode

(
  /*!  Expected drivers speed mode.       */
  VAR(MemIf_ModeType, AUTOMATIC) Mode         
);
/* PRQA S 0850 --                                                             */

/******************************************************************************/
/*! \Description  API to get the current availability status of a particular  
                memory device abstraction. Note: use MEMIF_BROADCAST_ID to  
                address all devices at the same time and get a compiled     
                global status of Memory Abstraction layer.                  */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0017, GSCSW-MemIf-SDD-001-0012          */
/*!  Status of the selected memory device(s) abstraction(s).     */
/*! \Range  [MEMIF_UNINIT, MEMIF_IDLE, MEMIF_BUSY, MEMIF_BUSY_INTERNAL] */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex
);
/* PRQA S 0850 --                                                             */

/******************************************************************************/
/*! \Description  API to get the result of the last job requested in a        
                particular memory device abstraction.                       */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0018                                    */
/*!  Last job result of the selected memory device abstraction.  */
/*! \Range  [MEMIF_JOB_OK, MEMIF_JOB_PENDING, MEMIF_JOB_CANCEL,
                   MEMIF_JOB_FAILED, MEMIF_BLOCK_INCONSISTENT,
                   MEMIF_BLOCK_INVALID]                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex
);
/* PRQA S 0850 --                                                             */
#endif /* MEMIF_NUMBER_OF_DEVICES */

#if (MEMIF_VERSION_INFO_API == STD_ON)
/*! \Trace_To  GSCSW-MemIf-SDD-001-0037                                      */
/******************************************************************************/
/*! \Description  API to get the version information of the MemIf module.     */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0020                                      */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, MEMIF_CODE) MemIf_GetVersionInfo
(
  /*!  Pointer to version structure.     */
  P2VAR(Std_VersionInfoType, AUTOMATIC, MEMIF_APPL_DATA) VersionInfoPtr  
                              
/* PRQA S 0850 --                                                             */
                              
);
#endif /* MEMIF_VERSION_INFO_API */


/*--- Asynchronous APIs -----------------------------------------------------*/

#if (MEMIF_NUMBER_OF_DEVICES > 1U)
/******************************************************************************/
/*! \Description  API to read a (part of) logical block from a memory device. */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0014                                      */
/*!  Request accepted or not.                                    */
/*! \Range  [E_OK, E_NOT_OK]                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read
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
);
/*PRQA S 0850--                            */

/******************************************************************************/
/*! \Description  API to write a full logical block to a memory device.       */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0015                                      */
/*!  Request accepted or not.                                    */
/*! \Range  [E_OK, E_NOT_OK]                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex,
  
  /*!  Number of the logical block.      */
  VAR(uint16, AUTOMATIC)  BlockNumber,
  
  /*!  Pointer to source RAM block.      */
  P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr  
                              
);
/*PRQA S 0850--                            */
#endif /* MEMIF_NUMBER_OF_DEVICES */

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
#if ((MEMIF_u8API_CONFIG_CLASS == MEMIF_u8API_CONFIG_CLASS_2) &&              \
     (MEMIF_NUMBER_OF_DEVICES > 1U))
/* PRQA S 3332 --                                                     */
/*lint -restore                                                               */
/******************************************************************************/
/*! \Description  API to mark data of a logical block as invalid in a memory  
                device.                                                     */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0019                                    */
/*!  Request accepted or not.                                    */
/*! \Range  [E_OK, E_NOT_OK]                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex,  

  /*!  Number of the logical block.      */
  VAR(uint16, AUTOMATIC)  BlockNumber         
);
/*PRQA S 0850--                            */
        
/******************************************************************************/
/*! \Description  API to pre-erase data of a logical block for further write. */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0021                                    */
/*!  Request accepted or not.                                    */
/*! \Range  [E_OK, E_NOT_OK]                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex,
  
  /*!  Number of the logical block.      */
  VAR(uint16, AUTOMATIC)  BlockNumber         
);
/*PRQA S 0850--                            */
        
/******************************************************************************/
/*! \Description  API to cancel the current job of a device abstraction.      */
/******************************************************************************/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0016                                      */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, MEMIF_CODE) MemIf_Cancel
(
  /*!  Index of the concerned device.    */
  /*! \Range  [0..MEMIF_NUMBER_OF_DEVICES-1]    */
  VAR(uint8, AUTOMATIC)   DeviceIndex         
);
/*PRQA S 0850--                            */
#endif /* MEMIF_u8API_CONFIG_CLASS and MEMIF_NUMBER_OF_DEVICES */

          
/* inhibit message number 750 because local macro used on MemMap not         */
/* referenced                                                                */
/* inhibit message number 760 because Redundant macro used on MemMap         */
/* inhibit message number 961 because multiple use of #define for MemMap     */
/* inhibit message number 537 because Repeated include for MemMap            */
/* inhibit message number 960 because use of '#undef' is discouraged         */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                            */
#define MEMIF_STOP_SEC_CODE /*## Close code section ##                       */
#include "MemMap.h"
/*lint -restore                                                              */


/*===========================================================================*/
/*=== PublicComponent constants exports =====================================*/
/*===========================================================================*/

#if (MEMIF_NUMBER_OF_DEVICES > 1U)

/* inhibit message number 750 because local macro used on MemMap not         */
/* referenced                                                                */
/* inhibit message number 760 because Redundant macro used on MemMap         */
/* inhibit message number 961 because multiple use of #define for MemMap     */
/* inhibit message number 537 because Repeated include for MemMap            */
/* inhibit message number 960 because use of '#undef' is discouraged         */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                            */
#define MEMIF_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h" /*## Open unknown size constant section ##               */
/*lint -restore                                                              */



/* !Deviation:  Inhibit MISRA rule [97],[20] because   configuration calsses */
/*                  and types  are defined in MemIf_Types.h which is included */
/*         through  the abstarction modules according to the modified file   */
/*         architecturespecified by CEE requirements */
/*lint -save -vo -e553 -e10 -e19 -e808  -v                                    */
/* !Deviation:  Inhibit MISRA rule [3332] because   configuration calsses and */
/*                  types  are defined in MemIf_Types.h which is included */
/*         through  the abstarction modules according to the modified file   */
/*         architecturespecified by CEE requirements */
/* PRQA S 3332 ++                                                             */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/* !MComment : Exports wrapping tables of MemIf APIs to corresponding memory
               abstraction modules APIs (used for multi devices wrapping).   */

extern CONST(MemIf_tpfvidSetModeApi, MEMIF_CFG_CONST) 
             MemIf_kapfudteSetModeApiCfg[MEMIF_NUMBER_OF_DEVICES];
extern CONST(MemIf_tpfenuGetStatusApi, MEMIF_CFG_CONST) 
             MemIf_kapfudteGetStatusApiCfg[MEMIF_NUMBER_OF_DEVICES];
extern CONST(MemIf_tpfenuGetJobResultApi, MEMIF_CFG_CONST) 
             MemIf_kapfudteGetJobResuApiCfg[MEMIF_NUMBER_OF_DEVICES];
extern CONST(MemIf_tpfudtReadApi, MEMIF_CFG_CONST) 
             MemIf_kapfudteReadApiCfg[MEMIF_NUMBER_OF_DEVICES];
extern CONST(MemIf_tpfudtWriteApi, MEMIF_CFG_CONST) 
             MemIf_kapfudteWriteApiCfg[MEMIF_NUMBER_OF_DEVICES];
#if (MEMIF_u8API_CONFIG_CLASS == MEMIF_u8API_CONFIG_CLASS_2)
extern CONST(MemIf_tpfudtEraseImdtBlockApi, MEMIF_CFG_CONST) 
             MemIf_kapfudteErsImdtBlckApiCfg[MEMIF_NUMBER_OF_DEVICES];
extern CONST(MemIf_tpfudtInvalidateBlockApi, MEMIF_CFG_CONST) 
             MemIf_kapfudteInvalidBlckApiCfg[MEMIF_NUMBER_OF_DEVICES];
extern CONST(MemIf_tpfvidCancelApi, MEMIF_CFG_CONST) 
            MemIf_kapfudteCancelApiCfg[MEMIF_NUMBER_OF_DEVICES];
#endif /* MEMIF_u8API_CONFIG_CLASS */
/*PRQA S 0850 --                    */
/* PRQA S 3332 --                                                     */
/*lint -restore                                                               */

/* inhibit message number 750 because local macro used on MemMap not         */
/* referenced                                                                */
/* inhibit message number 760 because Redundant macro used on MemMap         */
/* inhibit message number 961 because multiple use of #define for MemMap     */
/* inhibit message number 537 because Repeated include for MemMap            */
/* inhibit message number 960 because use of '#undef' is discouraged         */
/* inhibit message number 766 because include of MemMap at end of file       */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -e766 -v                      */
#define MEMIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h" /*## Close unknown size constant section ##              */

#endif /* MEMIF_NUMBER_OF_DEVICES */




#endif /* MEMIF_H */

/*==== End of file ==========================================================*/
